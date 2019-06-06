class port
{
    char cmd ;

  public:
    void bridge();
    void mail(char);
    char recieve() ;

};


void port::bridge()
{
  Serial.begin(9600);
}

void port::mail(char msg)
{
  Serial.println(msg);
}

char port::recieve()
{
  if (Serial.available() >= 0)
  {
    cmd = Serial.read();
  }
  else 
      {
      cmd = '5';
      }
  return cmd;
}

