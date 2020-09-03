#define MOTORS_LEFT_BACKWARD_PIN 6
#define MOTORS_LEFT_FORWARD_PIN 11
#define MOTORS_RIGHT_BACKWARD_PIN 3
#define MOTORS_RIGHT_FORWARD_PIN 5
char answer;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(MOTORS_LEFT_BACKWARD_PIN, OUTPUT);
pinMode(MOTORS_LEFT_FORWARD_PIN, OUTPUT);
pinMode(MOTORS_RIGHT_BACKWARD_PIN, OUTPUT);
pinMode(MOTORS_RIGHT_FORWARD_PIN, OUTPUT);
}

//turn left (L), turn slightly left (E), turn right (R), turn slightly right (I), 
//move forward (F), Move backward (B), halt the car (H), start the car(S)

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)

{
  answer = Serial.read();

  switch (answer)
  {
    case 'F':
    //move forward
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 255);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 255);
    break;

    case 'B':
    //move backward
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 255);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 255);
    break;

    case 'L':
    //turn left
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 128);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 255);
    break;

    case 'R':
    //turn right
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 255);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 128);
    break;

    case 'E':
    //turn slightly left
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 200);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 255);
    break;

    case 'I':
    //turn slightly right
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 255);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 200);
    break;

    case 'H':
    //stop the car
    analogWrite(MOTORS_LEFT_FORWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_FORWARD_PIN, 0);
    analogWrite(MOTORS_LEFT_BACKWARD_PIN, 0);
    analogWrite(MOTORS_RIGHT_BACKWARD_PIN, 0);
    break;

    default:
    break;
  }
}
}
