#include "LiquidCrystal_I2C.h";
#include "Wire.h";
#include "math.h";
int trigger_pin = 10;
int echo_pin = 9;
int bzr_pin = 8;
bool bzr_state;
float duration, distance;

LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(trigger_pin, OUTPUT);
  pinMode(bzr_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance : ");
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("Distance : ");
  lcd.setCursor(0,1);
  lcd.print(round(distance));
  lcd.print(" cm");
  if (distance < 5) {
    digitalWrite(bzr_pin, HIGH);
  }
  else {
    digitalWrite(bzr_pin, LOW);
  }
  delay(100);
}


