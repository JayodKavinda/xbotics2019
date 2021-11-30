/////////////////////////////////////////////////////////////////////////////////////////////////
///                            Xbotics 2019 - Full Code 11.25pm                              ////
/////////////////////////////////////////////////////////////////////////////////////////////////


#include <EEPROM.h>
#include <QTRSensors.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>
#include <Servo.h>
#include <Adafruit_TCS34725.h>
#include<TCS34725_Color_Sensor.h>


//==================================================color sensor==============================================
char tempColor;
int ArenaC_count;  // sorting color count in arena C
bool isarenaB = false;
char color_of_4_sensor[4];
char color; //soting color of box
unsigned int redCount=0;
unsigned int greenCount=0;
unsigned int blueCount=0;
/* Initialise with specific int time and gain values */
//Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
//const int interruptPin = 18;
int led01 = 53;
int led02 = 51;
int led03 = 49;
int led04 = 18;
//--------------------------------------Metel detection--------------------------------------
int switchpin = 45;
bool switchread = 0;

#define TCAADDR 0x70
#define CSLAddr 1 //7
#define CSRAddr 2 //2
#define CSFAddr 5 //4
#define CSBAddr 3 //6
//===variable for containing colours of four sides(R-1,G-2,B-3)
int CRV;
int CLV;
int CFV;
int CBV;
int roun = 2;
TCS34725_I2C_ColorSensor colorSensorL;
TCS34725_I2C_ColorSensor colorSensorR;
TCS34725_I2C_ColorSensor colorSensorF;
TCS34725_I2C_ColorSensor colorSensorB;

//================================================keypad=======================================================
byte collum[4] = {32, 26, 24, 22};
byte row[1] = {30};

char key[1][4] =
{ {'1', '2', '3', '4'}
};
int tonel = 34;
Keypad userin = Keypad(makeKeymap(key), row, collum, 1, 4);

//=============================================================================================================
//////Shortest path var.//////////////////////
int index;
String turns = "";
//=============================================Servo=========================================================


int Gripinitial = 0;
Servo Baservo;
Servo Armservo;
Servo Gripservo;

int initialBase = 160; // top position of base
int initialArm = 60;  //60 for fall down position <60 position is falling up

int Basend = 70; // bottom position of base
int Armend = 35;
int Gripend = 70;

//PID Coefficients and Variables --------------------------------------------------------------------------------
float Kp;
float Kd;
float Ki;

byte maxSpeed;
byte minSpeed;
byte baseSpeed;

int lastError = 0;
int integral = 0;
//===============================================================================================================

int buzzer = 31;

////algorithem variables-----------------------------------------------------------------------------------------//
int detect;
int left;
int right;
int Ahead;
int dead;
int End;
int turnCount;
int Ucount = 0;
unsigned int state = 0;

#define junctionCount 550

//================================================================================================================

//Mototrs -------------------------------------------------------------------------------------------------------
#define leftMotorForward 7  //motor directions
#define leftMotorBackward 8
#define rightMotorForward 5
#define rightMotorBackward 6

#define rightMotorPWM 9 //PWM controls
#define leftMotorPWM 10
//===============================================================================================================


//Encoders ------------------------------------------------------------------------------------------------------
volatile unsigned long leftCount = 0, rightCount = 0;

void leftISR() //ISR for left motor count
{
  leftCount++;
}

void rightISR() //ISR for right motor count
{
  rightCount++;
}


//LCD Menu ------------------------------------------------------------------------------------------------------
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

//#define leftPin 25
//#define centerPin 24
//#define rightPin 18

bool leftButton = 0, centerButton = 0, rightButton = 0;
//===============================================================================================================

//======================================Color====================================================================
int red = 38;
int green = 40;
int blue = 42;

//QTR Sensor ----------------------------------------------------------------------------------------------------
QTRSensors qtr;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
bool dval[SensorCount];

char manner = 'M';
//===============================================================================================================


void setup() {

  Serial.begin(9600);
  //interrupts();

  //  pinMode(interruptPin, INPUT_PULLUP); //TCS interrupt output is Active-LOW and Open-Drain
  //  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);

  /* if (tcs.begin())
     Serial.println("Found sensor"); */
  // Set persistence filter to generate an interrupt for every RGB Cycle, regardless of the integration limits
  //tcs.write8(TCS34725_PERS, TCS34725_PERS_NONE);
  //tcs.setInterrupt(true);
  //==============================================color Sensors===============================================
  Serial.println("Setting Left Sensor to 125ms integration time and 4x gain");
  tcaSelect(CSLAddr);
  colorSensorL.Setup(TCS34725_IntegrationTime::INTEGRATION_TIME_125_MS, TCS34725_RGBCGain::GAIN_4_X);    //Set up color sensor
  Serial.print("Integration Time: "); Serial.println((uint8_t)colorSensorL.GetIntegrationTime(), HEX);

  Serial.println("Setting Right Sensor to 125ms integration time and 4x gain");
  tcaSelect(CSRAddr);
  colorSensorR.Setup(TCS34725_IntegrationTime::INTEGRATION_TIME_125_MS, TCS34725_RGBCGain::GAIN_4_X);    //Set up color sensor

  Serial.println("Setting Right Sensor to 125ms integration time and 4x gain");
  tcaSelect(CSFAddr);
  colorSensorF.Setup(TCS34725_IntegrationTime::INTEGRATION_TIME_125_MS, TCS34725_RGBCGain::GAIN_4_X);    //Set up color sensor

  Serial.println("Setting Right Sensor to 125ms integration time and 4x gain");
  tcaSelect(CSBAddr);
  colorSensorB.Setup(TCS34725_IntegrationTime::INTEGRATION_TIME_125_MS, TCS34725_RGBCGain::GAIN_4_X);    //Set up color sensor

  //-----------------------------------------------------------------------------------------------------------

  qtr.setTypeAnalog();                    // configure the QTR sensors
  qtr.setSensorPins((const uint8_t[]) {
    A8, A9, A10, A11, A12, A13, A14, A15
  }, SensorCount);

  // pinMode(leftPin, INPUT_PULLUP);         //button for menu
  // pinMode(centerPin, INPUT_PULLUP);
  // pinMode(rightPin, INPUT_PULLUP);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(leftMotorForward, OUTPUT);      //motor controlling pins
  pinMode(leftMotorBackward, OUTPUT);    //
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);

  pinMode(led01, OUTPUT);  // tcs34750 color led pinmode
  pinMode(led02, OUTPUT);
  pinMode(led03, OUTPUT);
  pinMode(led04, OUTPUT);

  pinMode(switchpin, INPUT);
  
  pinMode(buzzer, OUTPUT); //keypad
  Baservo.attach(15);  //armmm
  Armservo.attach(14);
  Gripservo.attach(16);
  //Grip.attach();
  Baservo.write(initialBase);
  Armservo.write(initialArm);
  Gripservo.write(Gripinitial);

  pinMode(2, INPUT_PULLUP);              //Interrupts assigning for Encoders
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), leftISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), rightISR, CHANGE);

  lcd.init();                             // initialize the lcd display
  lcd.init();
  lcd.backlight();
  lcd.clear();

  ColorLedOff();

  menu();

  // setLineFollow('E');
  //setEncoderPID('E');
  qtrLoad();
  lcd.clear();  //Loading qtr values----

}

void loop() {

  //interface for main code
 lcd.print("**   RUN!!   **");

 //arenaA();
  //arenaB();
  //arenaC();
// arenaD();
 // arenaE();
  //arenaF();
  // arenaG();
  //arenaH();
  //arenaI();
  //arenaJ_part1();
  //arenaJ_part2();
 
  // solveMesh();
  // shortestPath();
  //while (1);
}
