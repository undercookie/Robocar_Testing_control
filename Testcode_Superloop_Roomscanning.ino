int angle_to_wall = 0;
int old_angle = 0;
int distance_wall = 0; //the sensor will read the value in here
int countdown_meters = 10; //will be used instead of actual measurements of the distance to the next wall

//LEDs to simulate the motors actions in the code:
#define LED_1_PIN 9 //stands for the wheels on the left side
#define LED_2_PIN 10 //stands for the wheels on the right side
#define LED_3_PIN 11 //stands for forward movement (all wheels on same speed)
#define LED_4_PIN 12 //stands for backwards movement (all wheels on same speed, motors spin in other direction)
#define LED_5_PIN 8 //stands for halting the vehicle; all motors stand still
#define LED_6_PIN 7 //stands for starting the vehicle

//global constants for the input, will later be replaced by the inputs from the sensor:
#define INPUT_ANGLE_WALL 45


void powerOffLEDs()
{
//function to make sure all LEDs are off when we begin
digitalWrite(LED_1_PIN, LOW);
digitalWrite(LED_2_PIN, LOW);
digitalWrite(LED_3_PIN, LOW);
digitalWrite(LED_4_PIN, LOW);
digitalWrite(LED_5_PIN, LOW);
digitalWrite(LED_6_PIN, LOW);
}

void setup() {
  // put your setup code here, to run once:
//Start serial with the chosen Baudrate. We need the serial monitor to controll the outputs:
Serial.begin(9600);
//set the LEDs as outputs:
pinMode(LED_1_PIN, OUTPUT);
pinMode(LED_2_PIN, OUTPUT);
pinMode(LED_3_PIN, OUTPUT);
pinMode(LED_4_PIN, OUTPUT);
pinMode(LED_5_PIN, OUTPUT);
pinMode(LED_6_PIN, OUTPUT);
powerOffLEDs();
}

void calculate_deflection_angle()
{
  angle_to_wall = INPUT_ANGLE_WALL;

  
}

void read_sensor_input()
{
  /*
   * in here the programm will continuously check for new sensoric input.
   * Since we don't have the sensor yet and don't know how to operate it, we can't really guess how the code will
   * look.
   * However, we researched on the internet and found code that used a loop to continuously check on the sensor.
   * it looked a bit like this:
   * 
   * distance = readPing();
   * delay(100);
   * distance = readPing();
   * delay(100);
   * distance = readPing();
   * delay(100);
   * 
   * we decided to keep this part in the code for later reference, in case it becomes useful.
   */
   angle_to_wall = INPUT_ANGLE_WALL;
   return angle_to_wall;
}

void Countdown_distance_wall()
{
  //will be used to simulate how the car drives towards a wall
  int ix;
  for (ix = countdown_meters; ix >= 1; ix--)
  {
    Serial.print("The next wall comes in: ");
    Serial.println(ix);
    delay(1000);
  }
  Serial.println("Close to wall,initiate turning.");
  delay(1000); //delay for better observation reasons. This is a simulation to understand better.
}

void Turn_left()
{
   analogWrite(LED_1_PIN, 123);
   analogWrite(LED_2_PIN, 255);
}

void Turn_right()
{
   analogWrite(LED_2_PIN, 123);
   analogWrite(LED_1_PIN, 255);
}

void Move_forward()
{
   analogWrite(LED_2_PIN, 255);
   analogWrite(LED_1_PIN, 255);
}

void loop() {
  // this is our superloop:
  Move_forward();
  Countdown_distance_wall();
  read_sensor_input();
  Serial.print("The angle to the wall in degrees is: ");
  Serial.println(angle_to_wall);
  old_angle = angle_to_wall;
  //We are not sure if the sensor can measure the angle from the next wall to both sides. Again, this will become a lot clearer
  //with actual hardware. For this simulation we assume the sensor measures the angle to the right side of the car.
  //To show that the car needs to deflect in the right or left direction depending on the angle that it hits the wall with,
  //we included the following if-statement:
  if (angle_to_wall > 90)
  {
    Turn_right();
    Serial.println("The car turns to the right.");
    delay(2000); //delay for better observation reasons. This is a simulation to understand better.
  }
  else
  {
    Turn_left();
    Serial.println("The car turns to the left...");
    delay(2000); //delay for better observation reasons. This is a simulation to understand better.
  }
  read_sensor_input();
  Serial.println("Continuous measuring with the sensor during turning...");
  delay(2000); //delay for better observation reasons. This is a simulation to understand better.
  if (angle_to_wall == old_angle)
  {
    Move_forward();
    Serial.println("The deflection angle now equals the incoming angle.");
    delay(1000); //delay for better observation reasons. This is a simulation to understand better.
    Serial.println("Driving straight again.");
    Serial.println('\n');
  }
  delay(1000); //delay for better observation reasons. This is a simulation to understand better.
  
}
