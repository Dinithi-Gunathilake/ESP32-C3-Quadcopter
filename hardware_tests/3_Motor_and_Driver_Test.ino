/**
--------------ESP32-C3 Single Motor Test--------------

Make sure that the connetions are exactly like this:

IN1 (Driver) ->  GPIO 0 (ESP C3)
IN2 (Driver) -> GND (Driver) ->  GND (ESP C3)
Vcc (Driver) -> + (3.7 V)
GND (Driver) -> - (0 V)
OUT1 (Driver) -> Motor's one terminal
OUT2 (Driver) -> Motor's other terminal

**/

const int testMotorPin = 0; // Connected to IN1

void setup() {
  Serial.begin(115200);
  pinMode(testMotorPin, OUTPUT);
  Serial.println("Single motor test starting...");
  delay(2000);
}

void loop() {
  Serial.println("Motor ON (Medium Speed)");
  analogWrite(testMotorPin, 150); // Speed from 0 to 255
  delay(2000); // Run for 2 seconds
  
  Serial.println("Motor OFF");
  analogWrite(testMotorPin, 0);
  delay(2000); // Stop for 2 seconds
}