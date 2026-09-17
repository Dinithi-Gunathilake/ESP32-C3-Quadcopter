/**
Make sure it is connected to your ESP32-C3 exactly like this:
VCC -> ESP32 3.3V 
GND -> ESP32 GND
SDA -> ESP32 GPIO 8
SCL -> ESP32 GPIO 9

Ensure you have installed the Adafruit MPU6050 library via the Library Manager.**/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10); // Wait for Serial Monitor to open

  Serial.println("Starting MPU6050 Test...");

  // Crucial for ESP32-C3: Set custom I2C pins (SDA = 8, SCL = 9)
  Wire.begin(8, 9); 

  // Attempt to connect to the sensor
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip.");
    Serial.println("Please check your wiring to pins 8 and 9!");
    while (1) { delay(10); } // Stop here if failed
  }
  
  Serial.println("MPU6050 Found successfully!");
  
  // Set basic flight ranges
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  
  Serial.println("Tilt the sensor to see values change...");
  delay(2000);
}

void loop() {
  // Get new sensor readings
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Print Gyroscope (rotation) values
  Serial.print("Rotation X: "); Serial.print(g.gyro.x);
  Serial.print(" | Y: "); Serial.print(g.gyro.y);
  Serial.print(" | Z: "); Serial.println(g.gyro.z);

  delay(300); // Wait slightly before reading again
}