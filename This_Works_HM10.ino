#include <SoftwareSerial.h>
SoftwareSerial BT(2,1);
byte val; //value to receieve data from the serial port this used to be char
int motor1pin1 = 4; 
int motor1pin2 = 5;

void setup() {
  pinMode(motor1pin1, OUTPUT); // set motor pins as outputs
  pinMode(motor1pin2, OUTPUT);
  BT.begin(9600); // begin serial communications at 9600 bits per second (baud)
  pinMode(3, OUTPUT);
}

void loop() {
  analogWrite(3, 150);
  if( BT.available() ) // check if there is data to read
  {
    val = BT.read(); // read the data into value variable
    BT.print("Reading new data: ");
    BT.println(val, HEX); // print this HEX value

  }
  if (val == '1') // if 1 (high) is received, need to adjust this to account for HEX
  {
  digitalWrite(motor1pin1, HIGH); //move motor
  digitalWrite(motor1pin2, LOW);
  }
  else // 1 not received
  {
  digitalWrite(motor1pin1, LOW); //move motor the other way
  digitalWrite(motor1pin2, HIGH);
  }
  delay(100);
}