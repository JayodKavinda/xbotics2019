void shortestPath(){

    turn_Right90();
    lcd.print(turns);
     for (int z = 0; z < Ucount; z++) 
      fixedArray();
    
  //lcd.print(turns);
}


void fixedArray() {

  String temp = "";
  index = turns.length();
  index--;
  for (int i = index; i >= 0; i--) {
    if (turns.charAt(i) == 'U') {
      if ( i < index - 1) {
        for (int j = i; j + 2  <= index; j++) {
          temp = temp + turns.charAt(j + 2);
        }
      }
      if ((turns.charAt(i - 1) == 'L' && turns.charAt(i + 1) == 'A') || (turns.charAt(i - 1) == 'L' && turns.charAt(i + 1) == 'A')) {
        for (int j = i; j - 1 <= index; j++) {
          turns.remove(j - 1);
        }
        turns = turns + 'R';
        turns = turns + temp;

      }
      if (turns.charAt(i - 1) == 'L' && turns.charAt(i + 1) == 'L') {
        for (int j = i; j - 1 <= index; j++) {
          turns.remove(j - 1);
        }
        turns = turns + 'A';
        turns = turns + temp;
      }
      break;
    }
  }
}
