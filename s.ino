#include <dht.h>
#include <math.h>
#include <Wire.h>
#define dht_dpin A2
dht DHT;
void setup()
{
Serial.begin(9600); 
Wire.onRequest(requestEvent);
Wire.begin(8); 

}

void loop()
{

delay(100);
}
void requestEvent()
{
  char aa[5];
  char bb[12];
 // char cc[10];
  DHT.read11(dht_dpin);
  float a = DHT.humidity/3;
  float b = DHT.temperature*2;
  dtostrf(a,5,2,aa);
 // Wire.write(aa);
 //Wire.write("HIHI");
  dtostrf(b,5,2,bb);

  bb[5] ='*' ;
  bb[6] ='*' ;
  bb[7] = aa[0];
  bb[8] = aa[1];
  bb[9] = aa[2];
  bb[10] = aa[3];
  bb[11] = aa[4];
  
/*  bb[5] = aa[0];
  bb[6] = aa[1];
  bb[7] = aa[2];
  bb[8] = aa[3];
  bb[9] = aa[4];*/
  
  Wire.write(bb);
  //Wire.write(bb);
  
  
 
 
}

