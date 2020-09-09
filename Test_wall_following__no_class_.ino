#define MOTORS_LEFT_BACKWARD_PIN 6
#define MOTORS_LEFT_FORWARD_PIN 11
#define MOTORS_RIGHT_BACKWARD_PIN 3
#define MOTORS_RIGHT_FORWARD_PIN 5
char answer;

int IDEAL_DISTANCE_MIN = 150;
int IDEAL_DISTANCE_MAX = 155;

#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;

void setup()
{
  pinMode(MOTORS_LEFT_BACKWARD_PIN, OUTPUT);
  pinMode(MOTORS_LEFT_FORWARD_PIN, OUTPUT);
  pinMode(MOTORS_RIGHT_BACKWARD_PIN, OUTPUT);
  pinMode(MOTORS_RIGHT_FORWARD_PIN, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor.setTimeout(500);

}

void move_forward() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
}

void turn_slightly_left() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 0); //maybe 50
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
}

void turn_slightly_right() {
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 128);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 0); //maybe 50
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
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
  sensor.setDistanceMode(VL53L1X::Short); //Changed from Long, in case the program crashes tomorrow, change that!
  sensor.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  //that's the one we need to change for timing!!!! Was set to 5 in the beginning!!!
  sensor.startContinuous(50);

  sensor.read();
  
  //Serial.print("range: ");
  Serial.print(sensor.ranging_data.range_mm);
  /*Serial.print("\tstatus: ");
  Serial.print(VL53L1X::rangeStatusToString(sensor.ranging_data.range_status));
  Serial.print("\tpeak signal: ");
  Serial.print(sensor.ranging_data.peak_signal_count_rate_MCPS);
  Serial.print("\tambient: ");
  Serial.print(sensor.ranging_data.ambient_count_rate_MCPS);*/
  
  Serial.println();
}

void loop() {
  sensormeasurement();
  if (Serial.available() > 0) {
    answer = Serial.read();
    switch (answer)
    {
      case 'I':
      turn_slightly_right();
      break;

      case 'E':
      turn_slightly_left();
      break;

      case 'F':
      move_forward();
      break;

      default:
      break;
    }
  }
  /*if (sensor.ranging_data.range_mm > IDEAL_DISTANCE) {
    turn_slightly_right();
    Serial.println("Turning right");
  }
  else if (sensor.ranging_data.range_mm < IDEAL_DISTANCE) {
    turn_slightly_left();
    Serial.println("Turning left");
  }
  else {
    move_forward();
    Serial.println("Moving forward");
  }
  */
}
