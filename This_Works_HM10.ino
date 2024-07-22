#include <SoftwareSerial.h>
SoftwareSerial BT(2,1);
byte val; //value to receieve data from the serial port this used to be char
int motor1pin1 = 4; 
int motor1pin2 = 5; // green LED

void setup() {
  pinMode(motor1pin1, OUTPUT); // set LED pins as outputs
  pinMode(motor1pin2, OUTPUT);
  BT.begin(9600); //begin serial communications at 9600 bits per second (baud)
  pinMode(3, OUTPUT);
}

void loop() {
  analogWrite(3, 150);
  if( BT.available() ) // check if there is data to read
  {
    val = BT.read(); // read the data into our value variable
    BT.print("Reading new data: ");
    BT.println(val, HEX); // used to not have , HEX.

  }
  if (val == '1') // if 1 (high) is received, need to adjust this to account for HEX
  {
  digitalWrite(motor1pin1, HIGH); // Turn on the green light and off the red light
  digitalWrite(motor1pin2, LOW);
  }
  else // 1 not received
  {
  digitalWrite(motor1pin1, LOW); // Turn on the red light and off the green light
  digitalWrite(motor1pin2, HIGH);
  }
  delay(100);
}