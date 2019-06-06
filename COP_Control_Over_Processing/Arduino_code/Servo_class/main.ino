
#define GMIN 85
#define GMAX 160
#define GPIN 6
#define HMAX 130
#define HMIN 50
#define HPIN 11
#define VMAX 130
#define VMIN 40
#define VPIN 10
#define RMAX 170
#define RMIN 10
#define RPIN 9

#define MANUAL
//#define AUTO
port port1 ;
servo rServo(RPIN, RMAX, RMIN), hServo(HPIN, HMAX, HMIN), vServo(VPIN, VMAX, VMIN), gServo(GPIN, GMAX, GMIN);

void manualMod();
void autoMod();
void park();
void prnlocation();
void sequence();


void setup()
{
  port1.bridge();
  rServo.start();
  hServo.start();
  vServo.start();
  gServo.start();
}

void loop()
{
#ifdef MANUAL
  manualMod();
#endif

#ifdef AUTO
  autoMod();
#endif
}

void manualMod()
{

  switch (port1.recieve())
  {
    case '4' : rServo.moveto(rServo.getPos() + 1) ; break;
    case '6' : rServo.moveto(rServo.getPos() - 1) ; break;
    case '8' : hServo.moveto(hServo.getPos() + 1) ; break;
    case '2' : hServo.moveto(hServo.getPos() - 1) ; break;
    case '7' : vServo.moveto(vServo.getPos() + 1) ; break;
    case '1' : vServo.moveto(vServo.getPos() - 1) ; break;
    case '9' : gServo.moveto(gServo.getPos() - 1) ; break;
    case '3' : gServo.moveto(gServo.getPos() + 1) ; break;
    case '0' : park() ; break;
    case 'p' : prnlocation() ; break;
  }
}

void park()
{
  gServo.moveto(90, 25);
  vServo.moveto(90, 25);
  hServo.moveto(90, 25);
  rServo.moveto(90, 25);

}

void prnlocation()
{

 Serial.print("GRIPPER SERVO : "); Serial.print(gServo.getPos());
 Serial.print("\tVERTICAL : "); Serial.print(vServo.getPos());
 Serial.print("\tHORIZONTAL SERVO : "); Serial.print(hServo.getPos());
 Serial.print("\tROTATION SERVO : "); Serial.println(rServo.getPos());

}

void autoMod()
{
  //currently empty
}

