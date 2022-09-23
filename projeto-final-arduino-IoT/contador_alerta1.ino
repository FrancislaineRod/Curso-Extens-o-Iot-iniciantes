// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);

  lcd_1.print("Contando 1 a 10!!!");
}

void loop()
{
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  delay(1); // Wait for 1 millisecond(s)
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  lcd_1.setCursor(0, 1);
  lcd_1.print(constrain(seconds, 1, 10));
  lcd_1.setBacklight(1);
  delay(500); // Wait for 500 millisecond(s)
  seconds += 1;
  if (seconds == 10) {
    tone(5, 29, 10000); // play tone 10 (A#0 = 29 Hz)
    delay(1000); // Wait for 1000 millisecond(s)
    lcd_1.clear();
    lcd_1.print("FIM!");
  }
}