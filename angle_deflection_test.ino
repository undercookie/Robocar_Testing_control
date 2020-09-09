//defining all the pins that the motors are attached to:
#define MOTORS_LEFT_BACKWARD_PIN 6
#define MOTORS_LEFT_FORWARD_PIN 11
#define MOTORS_RIGHT_BACKWARD_PIN 3
#define MOTORS_RIGHT_FORWARD_PIN 5

//all the sensor stuff:
#include <Wire.h>
#include <VL53L1X.h>
VL53L1X sensor;

//the servo:
#include <Servo.h>
Servo myservo; 

//extra variables and such stuff:
char answer;
int pos = 0;
SFEVL53L1X distanceSensor;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C
  sensor.setTimeout(50000);
  pinMode(MOTORS_LEFT_BACKWARD_PIN, OUTPUT);
  pinMode(MOTORS_LEFT_FORWARD_PIN, OUTPUT);
  pinMode(MOTORS_RIGHT_BACKWARD_PIN, OUTPUT);
  pinMode(MOTORS_RIGHT_FORWARD_PIN, OUTPUT);
  myservo.attach(9);
}

void move_forward() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
}

void move_backward() {
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 128);
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 0);
}

void turn_slightly_left() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 0);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 80);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
}

void turn_slightly_right() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 80);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
}

void servo() {
  //for servo movement
  for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
  }

  for (pos = 60; pos == 60; pos += 0) {
    delay(500);
    
  }

  for (pos = 60; pos <= 120; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
  }
  
  for (pos = 120; pos >= 60; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
  }

  for (pos = 60; pos == 60; pos += 0) {
    delay(500);
    
  }

  for (pos = 60; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    
  }
}

void sensormeasurement() {
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  
  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  //Long: 360cm; Medium: 290cm; Short: 136cm
  sensor.setDistanceMode(VL53L1X::Long); 
  sensor.setMeasurementTimingBudget(50);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  //that's the one we need to change for timing!!!! Was set to 5 in the beginning!!!
  sensor.startContinuous(1000);

  sensor.read();
  Serial.print(sensor.ranging_data.range_mm);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensormeasurement();
  delay(1000); //needs to be adjusted to the servo speed!
}
