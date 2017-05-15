#include <LiquidCrystal.h>
#include <Wire.h>
const int SLAVE_ADDRESS = 1;
char incomingByte = 0;
LiquidCrystal lcd(12, 7, 5, 4, 3, 2);

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(20, 2);
  lcd.cursor();
Serial.println("Humidity and temperature\n\n");
}

void loop() 
{     
  char c;
  Wire.requestFrom(8,12); 
   while (Wire.available())
   {    
        lcd.clear();
         while(Wire.available())
        {
         delay(100);
            
            c = Wire.read(); 
            lcd.write(c); 
        }
        
   }
        delay(100);
   Serial.println("");
 }

