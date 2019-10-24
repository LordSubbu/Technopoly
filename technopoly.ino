/*
  Smart Communication System for Deaf and Mute People using Hand Gestures 

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/



#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  //We give Ground and VCC to the ADXL module using the Analog pins 
  pinMode(groundpin, OUTPUT); //pin A4 for Ground
  pinMode(powerpin, OUTPUT); //pin A5 for Vcc
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH); 
  lcd.begin(16, 2);
}

void loop() {
  // Print the sensor values:
    int  x=analogRead(xpin);
    //Serial.print(x); //print value if x
    //Serial.print("\t");  // print a tab between values:
 
    int y=analogRead(ypin);
    //Serial.print(y); //print value if y
    //Serial.print("\t");  // print a tab between values:
    
    int z=analogRead(zpin);
    //Serial.print(z); //print value if z
    //Serial.println();  // skip to next line
    
    //  delay(100); // delay before next reading:


  
  if (x <300 && x > 100 ) //If the module is tilted Backwards, Hi will be printed in the LCD Screen
    {
      Serial.println("HI");
      lcd.print("HI"); // Print a message to the LCD.
      delay(1000);
      lcd.clear(); //Clears after Display
    }

  else if (x >400) //If the module is tilted Front, Hello will be printed in the LCD Screen
    {
      Serial.println("Hello");
      lcd.print("Hello"); // Print a message to the LCD.
      delay(1000);
      lcd.clear(); //Clears after Display
    }
  
  else if (y >390) //If the module is tilted  Left, Thank You will be printed in the LCD Screen
    {
      Serial.println("Thank You");
      lcd.print("Thank You"); // Print a message to the LCD.
      delay(1000);
      lcd.clear();//Clears after Display
    }

   else if ( y<300 && y > 100) //If the module is tilted Right, Welcome will be printed in the LCD Screen
    {
      Serial.println("welcome");
      lcd.print("Welcome"); // Print a message to the LCD.
      delay(1000);
      lcd.clear();//Clears after Display
    }

   else if (z < 300 && z > 100) //If the module is tilted Upside down, No will be printed in the LCD Screen
    {
      Serial.println("NO");
      lcd.print("NO"); // Print a message to the LCD.
      delay(1000);
      lcd.clear();//Clears after Display
    }
  
  else if (x>=335 &&  x<=342 &&y >=328 && y<=336 && z >= 405&& z<=415) //Normal state, no msg is printed
    {
      Serial.println("normal");
      lcd.clear();  //Clears after Display
      delay(1000);
    }
}
