

#include <Servo.h>
#define HALTTIME 1

class servo
{
    Servo S ;
    int maxValue , minValue ;
    int curPos ;
    int pin ;

  public:
    void start() ;
    int getPos() ;
    void moveto(int,int) ;
    servo(int,int,int) ;
    
};

servo::servo(int p,int maxVal ,int minVal):pin(p),maxValue(maxVal),minValue(minVal),curPos(90)
{}
void servo::start()
{
  S.attach(pin);
}

int servo::getPos()
{
  return curPos ;
}

void servo::moveto(int p, int intervel = 15)
{
  p = p > maxValue ? maxValue : p ;
  p = p < minValue ? minValue : p ;
  while (curPos != p)
  {
    curPos = curPos < p ? ++curPos : --curPos ;
    S.write(curPos);
    delay(intervel);
  }
  delay(HALTTIME);
}
