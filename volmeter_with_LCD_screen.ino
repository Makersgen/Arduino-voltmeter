
// include the library code:
#include <LiquidCrystal.h>


int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int SensorVolt = A0;    // Input for the sensor, Anolog input
int sensorValue = 0;    // Initilaisation of the sensor's value
float RealVoltage = 0;  // voltage expected

void setup() {

  Serial.begin(9600); // Serial communication to read the value with the terminal
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  // Print a message to the LCD.
  lcd.print("Volmeter 2.0 ;-)");  
  delay(2000);   // wait 2 seconds
  lcd.clear();   // clear lcd
}

void loop() {
  
  lcd.setCursor(0, 0); //  Set 1st line and 1st column
  lcd.print("Voltage: "); // display "voltage
  lcd.setCursor(0, 1);    // Set cursor to the 2 line
  // print the number of seconds since reset:

  sensorValue = analogRead(SensorVolt);
  Serial.print("Valeur analogue: ");
  Serial.println(sensorValue);
  RealVoltage = (0.0048*float(sensorValue));
  Serial.print("Valeur reel en volt: ");
  Serial.println(RealVoltage);
  
  lcd.print(RealVoltage);
  lcd.setCursor(6, 1);
  lcd.print("Volts");
  delay(2000); // wait 2 seconds
}
