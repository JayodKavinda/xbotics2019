//Encoder Turnings : PID Algorithm ------------------------------------------------------------------------

void setEncoderPID(char manner)
{
  leftCount=0;
  rightCount=0;
  
  lastError=0;
  integral=0;

  switch(manner)
  {
    case 'E'://Xtremely Slow
    Kp = 1;  //50, 80
    Kd = 10;
    //Ki = ;
    minSpeed = 30;
    baseSpeed = 50;
    maxSpeed = 70;
    break;

    case 'S'://Slow
    Kp = 10;
    Kd = 50;
    //Ki = ;
    minSpeed = 70;
    baseSpeed = 100;
    maxSpeed = 130;
    break;

    case 'M'://Moderate
    default:
    Kp = 10;
    Kd = 50;
    //Ki = ;
    minSpeed = 100;
    baseSpeed = 150;
    maxSpeed = 200;
    break;

    case 'F'://Fast
    Kp = 10;
    Kd = 50;
    //Ki = ;
    minSpeed = 150;
    baseSpeed = 200;
    maxSpeed = 255;
    break;

    case 'X'://Xtremely  veryyy slow
    Kp = 50;  //50, 80
    Kd = 20;
    //Ki = ;
    minSpeed = 40;
    baseSpeed = 45;
    maxSpeed = 60;
    break;
  }

}

void encoderPID()
{
  int error = leftCount - rightCount;
  
  int controlSpeed = Kp * error + Kd * (error - lastError); // + Ki*integral;
  lastError = error;
  
  int rightMotorSpeed = constrain((baseSpeed - controlSpeed),minSpeed, maxSpeed);
  int leftMotorSpeed = constrain((baseSpeed + controlSpeed),minSpeed, maxSpeed);
  
  motorSpeed(leftMotorSpeed,rightMotorSpeed);

  Serial.print(leftCount);
  Serial.print("   ");
  Serial.println(rightCount);
  
}

//============================================================================================================
