void pick_Sward(){
  armDowncom();
  gipperPick();
  delay(100);
  armUpcom();
}

void place_Sward(){
  armDowncom();
  gripperReleas();
   armUpcom();
}

void check_Sward(){
  armDowncom();
  gipperPick();
  delay(100);
  
}

void ArmDown(){
  int val = 0;
  for (int i = initialBase; i > Basend; i--)
  {
    Baservo.write(i);
    //val = map(i, initialBase, Basend, initialArm, Armend);
    //Armservo.write(val);
    delay(20);
  }

 
}
void gipperDown(){
  for (int i = initialArm; i < 80; i++)
  {
    Armservo.write(i);
    //val = map(i, initialBase, Basend, initialArm, Armend);
    //Armservo.write(val);
    delay(20);
  }
  
}
void gipperUp(){
  for (int i = 80; i > initialArm; i--)
  {
    Armservo.write(i);
    //val = map(i, initialBase, Basend, initialArm, Armend);
    //Armservo.write(val);
    delay(20);
  }
  
}

void ArmUp(){
  int val = 0;
  for (int i = Basend; i < initialBase; i++)
  {
    Baservo.write(i);
    //val = map(i, initialBase, Basend, initialArm, Armend);
    //Armservo.write(val);
    delay(10);
  }
}

void gripperReleas()
{
  for (int i = Gripend ; i > Gripinitial; i--)
  {
    Gripservo.write(i);
    delay(10);
  }
}

void gipperPick()
{
  for (int i = Gripinitial ; i < Gripend; i++)
  {
    Gripservo.write(i);
    delay(10);
  }
}
void armDowncom()
{
  armDownhaff();
  gipperDown();
  armDownwitharm();
}
void armUpcom()
{
  armUpwitharm();
  gipperUp();
  armUPhaff();
}

void armDownhaff()
{
  for (int i = initialBase; i > 80; i--)
  {
    Baservo.write(i);
    delay(10);
  }
}

void armUPhaff()
{
  for (int i = 80; i < initialBase; i++)
  {
    Baservo.write(i);
    delay(10);
  }
}

int bole;
void armDownwitharm()
{
  for (int i = 80; i > 70; i--)
  {
    Baservo.write(i);
    bole = map(i, 80, 60, 80, 80);
    Armservo.write(bole);
    delay(10);
  }
}
void armUpwitharm()
{
  for (int i = 70; i < 80; i++)
  {
    Baservo.write(i);
    bole = map(i, 80, 60, 80, 80);
    Armservo.write(bole);
    delay(10);
  }
}
