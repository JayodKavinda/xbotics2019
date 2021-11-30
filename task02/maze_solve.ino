void solveMesh()
{
  while (state == 0)
  {
    setLineFollow(manner);
    if (junctionDetect())
    {
      junTurns();
    }
    else //L turns only
    {
      if (left) turn_Leftt90_forwhiteLine();
      if (right) turn_Right90_forwhiteLine();
    }
  }
}


bool junctionDetect()
{
  setLineFollow('M');
  lineFollow_WhiteLine();

  //reseting variables
  detect = 0;
  left = 0;
  right = 0;
  Ahead = 0;
  dead = 0;
  turnCount = 0;

  while (1)
  {

    qtrRead_WhiteLine();

    //================================================Checking junction==========================================
    if (dval[0] && dval[1] || dval[7] && dval[6])
    {
      if (dval[7] && dval[6]) left = 1;
      if (dval[0] && dval[1]) right = 1;

      centerAtJunction(); //Mapping the junction

      //========================================End of mesh : inverting point==================================
      
       if((dval[0] && dval[1] && dval[6] && dval[7]) && !(dval[3] && dval[4]))                           //if ( dval[0] && dval[1] && dval[2] && dval[3] && dval[4] && dval[5] && dval[6] && dval[7] )
      {
        detect = 1;
        brakeActive();
       
        End = 1;
        left = 0;
        right = 0;
        Ahead = 0;
        state = 1;
        break;
      }

      //------------------------------------------------------------------------------------------------------
      //Counting number of turns
      if (left) turnCount++;
      if (Ahead) turnCount++;
      if (right) turnCount++;

      //checking for junction
      if (turnCount > 1) detect = 1;
      else detect = 0;


      break;
    }
    //=============================================Checking dead end==============================================
    
    if (!(dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7])) //NOR (only true when all sensors off)
    {
      qtrRead_WhiteLine();
      ShortDistance(900);
      brakeActive();
      turn_Right90_forwhiteLine();
      break;
    }

    //-------------------------------------------------------------------------------------------------------------

    else lineFollow_WhiteLine();
  }

  if (detect) return 1;
  else return 0;
}

void junTurns()
{

  if (left) {
    turn_Leftt90_forwhiteLine();
  }
  else if (Ahead) {
    //lcd.print("A");
  }
}

void centerAtJunction()
{

  ShortDistance(900);
  brakeActive();
  qtrRead_WhiteLine();
  if (dval[0] || dval[1] || dval[2] || dval[3] || dval[4] || dval[5] || dval[6] || dval[7]) Ahead = 1;



}
