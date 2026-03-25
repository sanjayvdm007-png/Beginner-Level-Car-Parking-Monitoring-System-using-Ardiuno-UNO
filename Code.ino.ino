#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD objects
LiquidCrystal_I2C lcd1(0x20,16,2);
LiquidCrystal_I2C lcd2(0x21,16,2);
LiquidCrystal_I2C lcd3(0x22,16,2);

// Previous states
bool prev1 = false;
bool prev2 = false;
bool prev3 = false;

void setup()
{
  // Trigger pins
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);

  // Echo pins
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  pinMode(6,INPUT);

  // Initialize LCDs
  lcd1.init();
  lcd2.init();
  lcd3.init();

  lcd1.backlight();
  lcd2.backlight();
  lcd3.backlight();

}

// Function to measure distance
int distancemeasurement(int echo,int trigger)
{
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);

  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger,LOW);

  long time = pulseIn(echo,HIGH);
  int distance = time * 0.034 / 2;

  return distance;
}

void loop()
{
  int distance1 = distancemeasurement(2,3);
  int distance2 = distancemeasurement(4,5);
  int distance3 = distancemeasurement(6,7);

  bool state1 = distance1 < 30;
  bool state2 = distance2 < 30;
  bool state3 = distance3 < 30;
 

  // Parking 1
  if(state1 != prev1)
  {
    lcd1.clear();
    lcd1.print("Parking 1");
    lcd1.setCursor(0,1);

    if(state1)
      lcd1.print("Occupied");
    else
      lcd1.print("Empty");

    prev1 = state1;
  }

  // Parking 2
  if(state2 != prev2)
  {
    lcd2.clear();
    lcd2.print("Parking 2");
    lcd2.setCursor(0,1);

    if(state2)
      lcd2.print("Occupied");
    else
      lcd2.print("Empty");

    prev2 = state2;
  }

  // Parking 3
  if(state3 != prev3)
  {
    lcd3.clear();
    lcd3.print("Parking 3");
    lcd3.setCursor(0,1);

    if(state3)
      lcd3.print("Occupied");
    else
      lcd3.print("Empty");

    prev3 = state3;
  }

  delay(200);
}