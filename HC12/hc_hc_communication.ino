#include <SoftwareSerial.h>
SoftwareSerial HC12(D4, D3); // HC-12 TX Pin, HC-12 RX Pin
char start;
String latt;
String longt;                    // using a constant String

unsigned long int pmillis;
void setup()
{
  Serial.begin(9600);             // Serial port to computer
  HC12.begin(9600);               // Serial port to HC12
  pmillis = millis();
}

void loop()
{
  while (millis() - pmillis < 1000)
    ;
  pmillis = millis();
  char init= 'I';
  char stat = 'o';
  unsigned int bat = analogRead(A0); //4.0V = 0x0333
  latt = "-16.02873";
  longt = "-48.05326";
  unsigned int weight =50;
  unsigned int cap = 80;
 char fim ='X'; 
  start = HC12.read();
  if(start == 's') { 
     delay(1000);
   HC12.print(init);
 HC12.print(bat);
 delay(1000);
  HC12.print(latt);
  HC12.print(longt);
  HC12.print(longt);
  HC12.print(weight);
  HC12.print(stat);
  HC12.print(fim);
  HC12.println();}}
