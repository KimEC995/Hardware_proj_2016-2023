/*
 * PETE Project
 * 아두이노 나노 + NEMA17 + A4988 + LCD_I2C_1602 + 10K 가변저항 + 히터 + 온도계
*/

#include <thermistor.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <MsTimer2.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

thermistor therm1(A1,0);
int Heater = 8;

int dirPin = 5;  
int stepPin = 4;  
int stepdelay;
int MotorLoop = 1;

void setup() 
{
  lcd.init();
  lcd.backlight();

  pinMode(Heater, OUTPUT);

  pinMode(stepPin, OUTPUT);  
  pinMode(dirPin, OUTPUT);  
  MsTimer2::set(10,MotorT);
  MsTimer2::start();

  Serial.begin(9600);
}

void loop() 
{
  double temp1 = therm1.analog2temp();
  
  digitalWrite(Heater,HIGH);
 
  if(temp1 >= 40)
  {
    digitalWrite(Heater,LOW);
  }
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp1);
  lcd.setCursor(0,1);
  lcd.print("Step: ");
  lcd.print(stepdelay);
  delay(500);
  lcd.clear();

  //Serial.println(temp1);

}

void MotorT()
{
  digitalWrite ( dirPin, HIGH ) ;
  int val = analogRead(A0);
  stepdelay = map(val,0,1023,6000,200);
  
    digitalWrite ( stepPin, HIGH ) ;
    delayMicroseconds (stepdelay) ;
    digitalWrite ( stepPin, LOW ) ;
    delayMicroseconds (stepdelay) ;
    Serial.println(val);

//  Serial.println(stepdelay);
  
}
