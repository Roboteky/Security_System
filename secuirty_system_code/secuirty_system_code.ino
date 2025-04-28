#include <Adafruit_LiquidCrystal.h>

// C++ code
//

int pir = 2;
int pir2 = 3;
int led = 9;

bool alarm = 0;
bool prev_alarm = 0;

bool alarm2= 0;
bool prev_alarm2 = 0;

Adafruit_LiquidCrystal lcd(0x20);



void setup()
{
  pinMode(led, OUTPUT);
  
  pinMode(pir, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(pir), getState, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pir2), getState, CHANGE);
  
  lcd.begin(16,2);
  
  Serial.begin(9600);
  
  lcd.setBacklight(1);
  
  lcd.setCursor(0,0);
  lcd.print("Security System");
  
}

void getState() {
  alarm = digitalRead(pir);
  alarm2 = digitalRead(pir2);
}

void loop()
{
  
//  alarm = digitalRead(pir);
  
//  getState();
  if (alarm != prev_alarm || alarm2 != prev_alarm2) {
    
    if (alarm || alarm2 ) {
      digitalWrite(led,HIGH);

      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      if (alarm) {
          delay(2000);
	      lcd.print("INTRUDER RM 1");
	      Serial.println("Intruder Rm 1");
      } else {
        
          delay(2000);
	      lcd.print("INTRUDER RM 2");
          Serial.println("Intruder Rm 2");
        
        
	  }

    } else {

      digitalWrite(led, LOW);

      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("ALL CLEAR");

      Serial.println("All Clear");
    }
    
    prev_alarm = alarm;
    prev_alarm2 = alarm2;
    
  }
  
//  delay(5000);
  
}
