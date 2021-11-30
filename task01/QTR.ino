//**************************************************LOAD************************************************************
void qtrLoad()
{
  qtr.calibrate();
  for (int i = 0; i < SensorCount; i++)
  {
    qtr.calibrationOn.minimum[i] = EEPROM.read(i);
    qtr.calibrationOn.maximum[i] = 5 * (EEPROM.read(i+10));
  }
  
}


//***********************************************************SAVE**************************************************
//Saving Calibration Values ---------------------------------------------------------------------

void qtrSave()
{
  lcd.clear();
  lcd.print("Calibrating...");
  
  
  leftCount=0;
  rightCount=0;
  byte percentage = 0;
  lcd.setCursor(0,1);
  
  for(int i=0;i<3;i++)
  {
    leftTurn(100,100);
    while(leftCount <= 300 && rightCount <=300) qtr.calibrate();

    brakeActive();
    percentage += 10;
    refresh(percentage);
    leftCount=0;
    rightCount=0;
    delay(100);
    
    rightTurn(100,100);
    while(leftCount <= 600 && rightCount <=600) qtr.calibrate();

    brakeActive();
    percentage += 10;
    refresh(percentage);
    leftCount=0;
    rightCount=0;
    delay(100);
    
    leftTurn(100,100);
    while(leftCount <= 300 && rightCount <=300) qtr.calibrate();
    
    brakeActive();
    percentage += 10;
    refresh(percentage);
    leftCount=0;
    rightCount=0;
    delay(100);
  }
 
  //--------------------Saving to EEPROM------------------------------
  
  for (int i = 0; i < SensorCount; i++)
  {
    EEPROM.write(i,qtr.calibrationOn.minimum[i]);
    EEPROM.write(i+10,(qtr.calibrationOn.maximum[i]/5));
  }

  refresh(100);
  delay(500);

  cal:
  lcd.clear();
  lcd.print("Calib. Completed");
  displayQTRVal();
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(" MAIN  |  Recal.");
  checkButtonPress();
  if(leftButton) qtrSave();
  else if(rightButton) menu(); //main code

  lcd.clear();
 


}

void qtrRead()
{
  uint16_t position=qtr.readLineBlack(sensorValues);

  for(int i=0; i < SensorCount ; i++ )
  {
    if(sensorValues[i] > 500) dval[i] = 1;
    else dval[i] = 0;
  }
}

void qtrRead_WhiteLine()
{
  uint16_t position=qtr.readLineWhite(sensorValues);

  for(int i=0; i < SensorCount ; i++ )
  {
    if(sensorValues[i] < 500) dval[i] = 1;
    else dval[i] = 0;
  }
}
void displayQTRVal(){
  lcd.clear();
  
  for (int i = 0; i < 4; i++)
  {
    lcd.print(qtr.calibrationOn.minimum[i]);
    lcd.print(" ");
  }

  lcd.setCursor(0,1);
  for (int i = 4; i < 8; i++)
  {
    lcd.print(qtr.calibrationOn.minimum[i]);
    lcd.print(" ");
  }

  delay(5000);
  lcd.clear();

  for (int i = 0; i < 3; i++)
  {
    lcd.print(qtr.calibrationOn.maximum[i]);
    lcd.print(" ");
  }
  
  lcd.setCursor(0,1);
  for (int i = 3; i < 6; i++)
  {
    lcd.print(qtr.calibrationOn.maximum[i]);
    lcd.print(" ");
  }

  delay(3000);
  lcd.clear();

  for (int i = 6; i < 8; i++)
  {
    lcd.print(qtr.calibrationOn.maximum[i]);
    lcd.print(" ");
  }

  delay(3000);
}
