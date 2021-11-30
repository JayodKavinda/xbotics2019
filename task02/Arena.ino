
//============================================Arena A===========================================================
void arenaA() {

  //Starting square
  rightTurnAtjunction();
  stopAtBar();
  ShortDistance(130, 50); //short distance ahed to the color box 430 count and 'X' Xtreamly veryy slow speed encoder PID
  brakeActive();
  //color
  digitalWrite(18, HIGH);
  get1Color();
  digitalWrite(18, LOW);
  ShortDistance(300, 'X');
  turn_Left180();
  rightTurnAtjunction();
  skip();
}


//============================================Arena B===========================================================
void arenaB() {

  skip();
  stopAtBar();
  ShortDistance(100 , 50); //short distance ahed to the color box 750 count and 'X' Xtreamly veryy slow speed encoder PID
  brakeActive();
  ArmDown();
  //color
  ColorLedOn();
  get4Color();
  ColorLedOff();
  ArmUp();

  delay(1000);
  ShortDistance(500, 'X');
  //arm code and color detection
  turn_Left180();
  skip();
}


//============================================Arena C===========================================================
void arenaC() {

  leftTurnAtjunction();
  stopAtBar();
  ShortDistance(520);
  brakeActive();
  //indication to the judges
  ArenaC_count = ColorCount();
  displayColor(ArenaC_count);
  turn_Right180();
  skip();
  rightTurnAtjunction();
}


//============================================Arena D===========================================================
void arenaD() {

  leftTurnAtjunction();
  dottedLine();
}

//============================================Arena E==========================================================
void arenaE() {
  stopAtBar();
  // EncodercountBack(100);
  brakeActive();
  encoder_Left90(1620);
  delay(500);
  EncodercountBack(1070);
  delay(1000);
}

//============================================Arena F===========================================================
void arenaF() {
  setLineFollow('M');
  for (int k = 0; k < 20; k++) {
    lineFollow();

  }
  skip();
  skip();
  rightTurnAtjunction();

}

//============================================Arena G===========================================================
void arenaG() {
  //first round***********************
  ramp();
  rightTurnAtjunction();

  //second round********************

  // blackline to whiteline color inversion
  invert_BlackToWhite();
}

//============================================Arena H===========================================================
void arenaH() {
  solveMesh();
  //while line to blackLine invert
  //invert_BlackToWhite();
}

//============================================Arena I===========================================================

void arenaI() {

  // fist round only**********************  // need to be correct//////////////////******
  Arena_I_Testing();
  //arm for pick sawd
  check_Sward();
  if (isMetal()) {
    armUpcom();
    ShortDistance(100, 50);
    turn_Left90();
    rightTurnAtjunction();
    rightTurnAtjunction();
  }
  else  {
  gripperReleas();
    ShortDistance(100, 50);
    turn_Left90();
    Arena_I_Testing();

    if (isMetal()) {
      armUpcom();
      ShortDistance(100, 50);
      turn_Left90();
      rightTurnAtjunction();
      skip();
      rightTurnAtjunction();
    }
    else{
      gripperReleas();
    ShortDistance(100, 50);
    turn_Left90();
    Arena_I_Testing();
    pick_Sward();
    ShortDistance(100, 50);
      turn_Left90();
      rightTurnAtjunction();
      skip(); skip();
      rightTurnAtjunction();
    }
  }
  



  // blackline to whiteline color inversion
  invert_BlackToWhite();

}

//============================================Arena J===========================================================

void arenaJ_part1() {
  // shotest path is requied
  solveMesh();
  //while line to blackLine invert
}

void arenaJ_part2(){
  leftTurnAtjunction();
  leftTurnAtjunction();// task 01 only
  //placing sward...
  if(ArenaC_count==1){
   skip();
    stopAtBar();
   stopAtBarForWhite();
    
     EncodercountBack(100);
    place_Sward();
    
  }
  else if(ArenaC_count==2){
     rightTurnAtjunction();
    leftTurnAtjunction();
    stopAtBar();
    stopAtBarForWhite();
    
     EncodercountBack(100);
    place_Sward();
  }
  else{
     rightTurnAtjunction();
     skip();
    leftTurnAtjunction();
    stopAtBar();
    stopAtBarForWhite();
    
     EncodercountBack(100);
    place_Sward();
  }
  
}
