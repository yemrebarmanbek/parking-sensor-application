#include <Wire.h>
#include <FaBoLCD_PCF8574.h>   // ARDUİNO LCD BU ŞEKİLDE ÇALIŞIR

FaBoLCD_PCF8574 lcd;

int trig_pin=9,echo_pin=10,buzzer=11,led=12;

void setup() {
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin(16,2);
  

}

void loop() {

   
   long sure,mesafe;
   
   digitalWrite(trig_pin,LOW);  
   delayMicroseconds(2);
   digitalWrite(trig_pin,HIGH);
   delayMicroseconds(10); 
   digitalWrite(trig_pin,LOW);  
   
   sure=pulseIn(echo_pin,HIGH);  
   mesafe=(sure/2)*0.0343;       


   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("MESAFE");
   lcd.setCursor(7,0);
   lcd.print(mesafe);


   if(mesafe<=5)
   {
      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);
      delay(20);
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(20);
    }
    
   else if(mesafe<=10)
    {
      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(50);
      
      }

    else  if(mesafe<=15)
      {
      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(100);
        
        }
      else
      {
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
        
        }  
     delay(10);


}
