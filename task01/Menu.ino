
void(* resetFunc)(void) = 00;

void reset()//ISR for reset
{
  Start(); //turning off all the functions
  resetFunc();
}

void menu()
{
  //menu:
  lcd.clear();
  delay(50);
  lcd.print("** TECHBLOCKS **");
  lcd.setCursor(0,1);
  lcd.print("Main  Set.  Cal.");

  checkButtonPress();
  
  if(leftButton) loop(); //run main code
  
  else if(centerButton) qtrSave(); //run calibration
  
  
}

void refresh(float var)
{
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(var); lcd.print("%");
}

void checkButtonPress()
{
  leftButton=0, centerButton=0, rightButton=0;

  
  while(1)
  {
    char key = userin.getKey();
      Serial.println(key);
    if(key=='1') 
    {
      leftButton = 1;
      break;
    }
    else if(key=='2') 
    {
      centerButton = 1;
      break;
    }
    else if(key=='3')
    {
      rightButton = 1;
      break;
    }
  }
  delay(250);
}
