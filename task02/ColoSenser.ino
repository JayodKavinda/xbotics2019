
int ColorCount() {
  redCount=0;
  greenCount=0;
  blueCount=0;
  if (color == 'R'){
    for(int j=0;j<4;j++){
      if(color_of_4_sensor[j]=='R') redCount++;
    }
    return redCount;
    }
    
  else if (color == 'G'){
    for(int j=0;j<4;j++){
      if(color_of_4_sensor[j]=='G') greenCount++;
    }
    return greenCount;
    }
  else{
    for(int j=0;j<4;j++){
      if(color_of_4_sensor[j]=='B') 
      blueCount++;
    }
    return blueCount;
    }

}
void displayColor(int val) {
  if (color == 'R') {
    if (val == 1) {
      digitalWrite(red, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(red, LOW);
     digitalWrite(buzzer, LOW);
       delay(500);
    }
    else if ( val == 3) {
      for (int j = 0; j < 3; j++) {
        digitalWrite(red, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        delay(500);
      }

    }
    else {
      for (int j = 0; j < 2; j++) {
        digitalWrite(red, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        digitalWrite(buzzer, LOW);
        delay(500);
      }

    }
  }
  else if (color == 'G') {
    if (val == 1) {
      digitalWrite(green, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      digitalWrite(buzzer, LOW);
    }
    else if ( val == 3) {
       for (int j = 0; j < 3; j++) {
      digitalWrite(green, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
       }
    }
    else {
       for (int j = 0; j < 2; j++) {
      digitalWrite(green, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(green, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
       }

    }
  }
  else {
    if (val == 1) {
      digitalWrite(blue, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
      digitalWrite(buzzer, LOW);
    }
    else if ( val == 3) {
       for (int j = 0; j < 3; j++) {
      digitalWrite(blue, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
     
       }
    }
    else {
        for (int j = 0; j < 2; j++) {
      digitalWrite(blue, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(blue, LOW);
      digitalWrite(buzzer, LOW);
      delay(500);
     
       }
    }
  }
}




void get4Color() {
  isarenaB = true;
  for (int i = 0; i < 3; i++) {
    //Serial.println("Testing Left Sensor");
    tcaSelect(CSLAddr);
    //delay(1);
    color_of_4_sensor[0]=ReadColorSensor("COLORR", colorSensorL);

    //Serial.println("Testing Right Sensor");
    tcaSelect(CSRAddr);
    //delay(1);
    color_of_4_sensor[1]=ReadColorSensor("COLORR", colorSensorR);

    //Serial.println("Testing Right Sensor");
    tcaSelect(CSFAddr);
    //delay(1);
    color_of_4_sensor[2]=ReadColorSensor("COLORR", colorSensorF);

    //Serial.println("Testing Right Sensor");
    tcaSelect(CSBAddr);
    //delay(1);
    color_of_4_sensor[3]=ReadColorSensor("COLORR", colorSensorB);
    delay(600);
    Serial.println("____________________");
  }


}

void get1Color() {

  for (int i = 0; i < 3; i++) {
    //Serial.println("Testing Left Sensor");
    tcaSelect(CSFAddr);
    //delay(1);
    ReadColorSensor("COLORR", colorSensorF);


    delay(600);
    Serial.println("____________________");
  }
  if (tempColor == 'G') {
    color = 'G';
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
  }
  else if (tempColor == 'B') {
    color = 'B';
    digitalWrite(blue, HIGH);
    delay(500);
    digitalWrite(blue, LOW);
  }
  else {
    color = 'R';
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
  }



}

void tcaSelect(uint8_t addr)
{
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << addr);
  Wire.endTransmission();
}

//*******************************************
//Color Sensor code
//*******************************************
char ReadColorSensor(String tag, TCS34725_I2C_ColorSensor& colorSensor)
{
  uint16_t r, g, b, c;

  colorSensor.Read();
  r = colorSensor.GetRed();
  g = colorSensor.GetGreen();
  b = colorSensor.GetBlue();
  //Serial.print(tag + " ");Serial.print(r); Serial.print(" "); Serial.print(g); Serial.print(" "); Serial.print(b); Serial.print(" "); Serial.println(c);
  if (r > g) {
    Serial.print("RED\n");
    tempColor = 'R';
    return 'R';
  } else if (g > b) {
    Serial.print("GREEN\n");
    tempColor = 'G';
    return 'G';
  } else {
    Serial.print("BLUE\n");
    tempColor = 'B';
    return 'B';
  }

}


void ColorLedOn() {
  digitalWrite(led01, HIGH);
  digitalWrite(led02, HIGH);
  digitalWrite(led03, HIGH);
  digitalWrite(led04, HIGH);
}

void ColorLedOff() {
  digitalWrite(led01, LOW);
  digitalWrite(led02, LOW);
  digitalWrite(led03, LOW);
  digitalWrite(led04, LOW);
}
