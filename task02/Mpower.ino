//===================================================================

//==========================================================Basic Motion Functions --------------------------------------------

void Start()
{
  digitalWrite(rightMotorPWM, LOW);
  digitalWrite(leftMotorPWM, LOW);

  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);
}

void stopBot() //stop
{
  digitalWrite(rightMotorPWM, 0);
  digitalWrite(leftMotorPWM, 0);

  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, LOW);

  delay(250);
}

void brakeActive() {
  digitalWrite(rightMotorPWM, LOW);
  digitalWrite(leftMotorPWM, LOW);

  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);

  delay(250);
}
void motorSpeed(bool state)
{
  digitalWrite(leftMotorPWM, state);
  digitalWrite(rightMotorPWM, state);
}

void motorSpeed(byte leftSpeed, byte rightSpeed)
{
  analogWrite(leftMotorPWM, leftSpeed);
  analogWrite(rightMotorPWM, rightSpeed);
}

void forward()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void forward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void backward()
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);
}

void backward(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorBackward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void leftTurn()
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);
}

void leftTurn(int LSpeed, int RSpeed)
{
  digitalWrite(rightMotorBackward, LOW);
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorBackward, HIGH);
  digitalWrite(rightMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

void rightTurn()
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);
}

void rightTurn(int LSpeed, int RSpeed)
{
  digitalWrite(leftMotorBackward, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorBackward, HIGH);
  digitalWrite(leftMotorForward, HIGH);

  analogWrite(leftMotorPWM, LSpeed);
  analogWrite(rightMotorPWM, RSpeed);
}

//====================================================Turning functions==========================================================

void turn_Right90()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  rightTurn();
  encoderPID();
  while (1)
  {
    qtrRead();
    if ((dval[3] || dval[4]) && leftCount > 500 && rightCount > 500 )
    {
      brakeActive();
      break;
    }
  }
}
void turn_Right90_forwhiteLine()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  rightTurn();
  encoderPID();
  while (1)
  {
    qtrRead_WhiteLine();
    if ((dval[3] && dval[4]) && leftCount > 500 && rightCount > 500 )
    {
      brakeActive();
      break;
    }
  }
}


void turn_Left90()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  leftTurn();
  encoderPID();
  while (1)
  {
    qtrRead();
    if ((dval[3] || dval[4]) && leftCount > 500 && rightCount > 500 )
    {
      brakeActive();
      break;
    }
  }
}
void turn_Leftt90_forwhiteLine()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  leftTurn();
  encoderPID();
  while (1)
  {
    qtrRead_WhiteLine();
    if ((dval[3] && dval[4]) && leftCount > 500 && rightCount > 500 )
    {
      brakeActive();
      break;
    }
  }
}



void turn_Left180()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  leftTurn();
  encoderPID();
  while (1)
  {
    qtrRead();
    if ((dval[3] && dval[4]) && leftCount > 1400 && rightCount > 1400 )
    {
      brakeActive();
      break;
    }
  }
}

void turn_Right180()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  rightTurn();
  encoderPID();
  while (1)
  {
    qtrRead();
    if ((dval[3] || dval[4]) && leftCount > 1400 && rightCount > 1400 )
    {
      brakeActive();
      break;
    }
  }
}

void turn_Right180_whiteLine()
{
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  rightTurn();
  encoderPID();
  while (1)
  {
    qtrRead_WhiteLine();
    if ((dval[3] || dval[4]) && leftCount > 1400 && rightCount > 1400 )
    {
      brakeActive();
      break;
    }
  }
}

//=============================================Encoder turns==================================================================

void EncodercountBack(int val) {
  backward();
  setEncoderPID('S');

  while (1){
    if( leftCount >val && rightCount>val){
      brakeActive();
      break;
     
    }
    encoderPID();
  }
   
}

void encoder_Right90(int val)
{
  leftCount = 0;
  rightCount = 0;
  rightTurn(60, 60);
  while (1)
  {
    qtrRead();
    if ( leftCount > val && rightCount > val )
    {
      brakeActive();
      break;
    }
  }
}

void encoder_Left90(int val)
{
  leftCount = 0;
  rightCount = 0;
  leftTurn(60, 60);
  while (1)
  {
    qtrRead();
    if ( leftCount > val && rightCount > val )
    {
      brakeActive();
      break;
    }
  }
}

//---------------------------------------Short distance to center At the juction-----------------------------------------------------

void ShortDistance(int val) {
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) {
    forward();
    encoderPID();
  }
  leftCount = 0;
  rightCount = 0;
}
void ShortDistanceForBar() {
  setEncoderPID('E');
  leftCount = 0;
  rightCount = 0;
  while (dval[1] && dval[2] && dval[3] && dval[4] && dval[5] && dval[6]) {
    forward();
    encoderPID();
  }
  brakeActive();
  leftCount = 0;
  rightCount = 0;

}
void ShortDistance(int val, char X) {
  setEncoderPID('X');
  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) {
    forward();
    encoderPID();
  }
  leftCount = 0;
  rightCount = 0;
}

void ShortDistance(int val , int AnalogSpeed) {

  leftCount = 0;
  rightCount = 0;
  while (leftCount <= val && rightCount <= val) forward(AnalogSpeed, AnalogSpeed);
  leftCount = 0;
  rightCount = 0;
}
//===========================================
