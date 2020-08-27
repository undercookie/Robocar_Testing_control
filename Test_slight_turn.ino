//We will use LEDs to test the code. In the real code they represent the Motor and it's actions:
#define LED_1_PIN 9 //stands for the wheels on the left side
#define LED_2_PIN 10 //stands for the wheels on the right side
#define LED_3_PIN 11 //stands for forward movement (all wheels on same speed)
#define LED_4_PIN 12 //stands for backwards movement (all wheels on same speed, motors spin in other direction)
#define LED_5_PIN 8 //stands for halting the vehilce; all motors stand still
#define LED_6_PIN 7 //stands for starting the car
char answer;


void powerOffLEDs()
{
//function to make sure all LEDs are off when we begin
analogWrite(LED_1_PIN, 0); 
analogWrite(LED_2_PIN, 0); 
analogWrite(LED_3_PIN, 0); 
analogWrite(LED_4_PIN, 0); 
analogWrite(LED_5_PIN, 0); 
analogWrite(LED_6_PIN, 0); 
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
    analogWrite(LED_1_PIN, 128);
    analogWrite(LED_2_PIN, 255);
    break;

    case 'E':
    //Turn slightly left:
    powerOffLEDs();
    analogWrite(LED_1_PIN, 200);
    analogWrite(LED_2_PIN, 255);
    break;

    case 'I':
    //Turn slightly right:
    powerOffLEDs();
    analogWrite(LED_2_PIN, 200);
    analogWrite(LED_1_PIN, 255);
    break;

    case 'R':
    //Turn right:
    powerOffLEDs();
    analogWrite(LED_2_PIN, 128);
    analogWrite(LED_1_PIN, 255);
    break;

    case 'F':
    //Move forward:
    powerOffLEDs();
    analogWrite(LED_3_PIN, 255);
    break;

    case 'B':
    //Move backward:
    powerOffLEDs();
    analogWrite(LED_4_PIN, 255);
    break;

    case 'H':
    //Halt:
    powerOffLEDs();
    analogWrite(LED_5_PIN, 255);
    break;

    case 'S':
    //Start
    powerOffLEDs();
    analogWrite(LED_6_PIN, 255);
    break;

    default:
    break;
   }
}
}
