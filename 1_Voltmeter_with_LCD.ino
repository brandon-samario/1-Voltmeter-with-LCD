/*
  The purpose of this program  is to understand how an lcd works, and use it to display voltage such as a voltmeter.
  Using a sperate power source, this program provides the ability to read the voltage value of the power source using the anolog input pin (A0).
  Thus, it uses the coversion formula for voltage, converting the analog value (analogread (A0)) into a voltage value, which is then displayed on the lcd.
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // rs, e, d4, d5, d6, d7

// voltage setup
float input_voltage = 0.0;
float temp = 0.0;

// the setup function runs once when you press reset or power the board
void setup()
{

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
  lcd.print("VOLTMETER"); // print text on lcd

}

// the loop function runs over and over again forever
void loop()
{

  int analog_value = analogRead(A0); // read value on analog pin A0
  input_voltage = (analog_value * 5.0) / 1024.0; //Conversion formula for voltage

  if (input_voltage < 0.1)
  {

    input_voltage = 0.0;

  }

  Serial.print("V = "); // print text in serial monitor
  Serial.println(input_voltage); // print value of voltage from power source in serial monitor

  lcd.setCursor(0, 1); // position of text on lcd (will show on 2nd colomn)
  lcd.print("Voltage = "); // print text on lcd
  lcd.print(input_voltage); // print value voltage on lcd
  delay(300); // wait time

}