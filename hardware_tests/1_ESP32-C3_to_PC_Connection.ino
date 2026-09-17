void setup() {
  // Start communication at 115200 speed
  Serial.begin(115200); 
  
  // Wait a moment for the USB connection to wake up
  delay(2000); 
}

void loop() {
  // Send a message every 1 second
  Serial.println("Hello! The ESP32-C3 connection is working!");
  delay(1000); 
}