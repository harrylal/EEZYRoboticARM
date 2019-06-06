import processing.serial.*;

Serial myPort ;
String val ;


void setup() {
  size(200, 200);
  String portName = Serial.list()[0] ;
  myPort = new Serial(this, portName, 9600);
}


void draw() {
}

void keyPressed() {
  myPort.write(key);
  println(key);
  }
