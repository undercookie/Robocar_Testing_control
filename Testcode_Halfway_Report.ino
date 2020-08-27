//We will use LEDs to test the code. In the real code they represent the Motor and it's actions:
#define LED_1_PIN 9 //stands for the wheels on the left side
#define LED_2_PIN 10 //stands for the wheels on the right side
#define LED_3_PIN 11 //stands for forward movement (all wheels on same speed)
#define LED_4_PIN 12 //stands for backwards movement (all wheels on same speed, motors spin in other direction)
#define LED_5_PIN 8 //stands for halting the vehicle; all motors stand still
#define LED_6_PIN 7 //stands for starting the vehicle
char answer;
int speed = 255; //speed of the motor

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
//Start Serial with the chosen Baudrate:
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

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
{
  answer = Serial.read();

   switch (answer)
   {
    case 'L':
    //Turn left:
    powerOffLEDs();
    digitalWrite(LED_1_PIN, HIGH);
    break;

    case 'R':
    //Turn right:
    powerOffLEDs();
    digitalWrite(LED_2_PIN, HIGH);
    break;

    case 'F':
    //Move forward:
    powerOffLEDs();
    digitalWrite(LED_3_PIN, HIGH);
    break;

    case 'B':
    //Move backward:
    powerOffLEDs();
    digitalWrite(LED_4_PIN, HIGH);
    break;

    case 'H':
    //Halt:
    powerOffLEDs();
    digitalWrite(LED_5_PIN, HIGH);
    break;

    case 'S':
    //Start
    powerOffLEDs();
    digitalWrite(LED_6_PIN, HIGH);
    break;

    default:
    break;
   }
}
}
