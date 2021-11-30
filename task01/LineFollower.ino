void setLineFollow(char manner)
{
  forward();
  
  lastError = 0;
  integral=0;

  switch(manner)
  { 

     case 'E'://Extremly Slow
    Kp = 0.1;
    Kd = 2;
    Ki = 0.001;
    minSpeed = 0;
    baseSpeed = 50;
    maxSpeed = 50;
    break;
    
     case 'X'://Extremly  veryyyy Slow
    Kp = 0.1;
    Kd = 2;
    Ki = 0.001;
    minSpeed = 0;
    baseSpeed = 50;
    maxSpeed = 50;
    break;

    case 'S'://Slow
    Kp = 0.1;
    Kd = 1;
    Ki = 0.001;
    minSpeed = 0;
    baseSpeed = 60;
    maxSpeed = 90;
    break;

    case 'M'://Moderate
    default:
    Kp = 0.05;
    Kd = 2;
    Ki = 0.001;
    minSpeed = 0;
    baseSpeed = 100;
    maxSpeed = 120;
    break;
  }
}

//Line Following : PID Algorithm -------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lineFollow()
{
  
  uint16_t position = qtr.readLineBlack(sensorValues); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = position - 3500;
  
  integral = integral + error;
  
  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki*integral;
  
  lastError = error;
  
  byte rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed,rightMotorSpeed);
}

void lineFollow_WhiteLine()
{
  
  uint16_t position = qtr.readLineWhite(sensorValues); // get calibrated readings along with the line position, refer to the QTR Sensors Arduino Library for more details on line position.
  int error = position - 3500;
  
  integral = integral + error;
  
  int controlSpeed = Kp * error + Kd * (error - lastError) + Ki*integral;
  
  lastError = error;
  
  byte rightMotorSpeed = constrain((baseSpeed + controlSpeed), minSpeed, maxSpeed);
  byte leftMotorSpeed = constrain((baseSpeed - controlSpeed), minSpeed, maxSpeed);

  motorSpeed(leftMotorSpeed,rightMotorSpeed);
}



//=====================================================================================================================================================================================
