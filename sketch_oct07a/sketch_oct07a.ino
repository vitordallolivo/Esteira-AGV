#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2,3);

char c=' ';
bool ent4,ent5;
void setup() 
{
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(9600);
}

void loop() 
{
  if(Bluetooth.available())
  {
    c=Bluetooth.read();
    Serial.write(c);
  }
  ent4 = digitalRead(4);
  ent5 = digitalRead(5);
  if(ent4 == HIGH)
  {
    Bluetooth.write('a');
  }  
   if(ent5 == HIGH)
  {
    Bluetooth.write('b');
  }  
}
