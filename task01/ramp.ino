void ramp() {
  stopAtBar();
  encoderCountAhead(2800);

  setLineFollow('M');
    for(int k=0;k<20;k++)
    lineFollow();
}

void encoderCountAhead(int val) {
  setEncoderPID('S');
  while (1) {
    forward();
    encoderPID();
    if (leftCount > val && rightCount > val)
    {
      brakeActive();
      break;
      delay(500);
    }
  }
}
