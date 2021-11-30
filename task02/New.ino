void rightTurnAtjunction()
{
  
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ((dval[0] && dval[1]) || (dval[6] && dval[7]))
    {
      ShortDistance(900, 100);  // short distance to the junction parameters: (encoder count, speed)
      brakeActive();
      turn_Right90(); 
      break;
    }
    lineFollow();
  }
}
void leftTurnAtjunction()
{
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ((dval[0] && dval[1]) || (dval[6] && dval[7]))
    {
      ShortDistance(900,100); // short distance to the junction parameters: (encoder count, speed)
      brakeActive();
      turn_Left90();
      break;
    }
    lineFollow();
  }
}
void onToLine(){
  turn_Left90();
}

void skip(){
  setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if ((dval[0] && dval[1]) || (dval[6] && dval[7]))
    {
      ShortDistance(300,120);  // short distance to the junction parameters: (encoder count, speed)
      break;
    }
    lineFollow();
  }
}

void stopAtBar(){
   setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if (dval[1] && dval[2] && dval[3] && dval[4] && dval[5] && dval[6])
    {
      brakeActive();
      break;
    }
    lineFollow();
  }
}

void stopAtBarForWhite(){
   setLineFollow(manner);
  while (1)
  {
    qtrRead();
    if (!( dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6]))
    {
      brakeActive();
      break;
    }
    lineFollow();
  }
}

void dottedLine(){
  setLineFollow('S');
  while (1)
  {
    qtrRead();
   /* if (!(dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7]))
    {
      forward(55,28);
     
    } */
    if ( dval[2] && dval[3] && dval[4] && dval[5] && dval[6]&& dval[7])
    {
      brakeActive();
      ShortDistance(900);
  brakeActive();
  turn_Left90();
      break;
    }
    
    lineFollow();
  }
  
}

void invert_BlackToWhite() {
  setLineFollow('M');
  while (1) {
   
    qtrRead();
    if((dval[0] && dval[1] && dval[6] && dval[7]) && !(dval[3] && dval[4])) {
      ShortDistance(200);
      brakeActive();
      break;
    }
     lineFollow();
  }
}
