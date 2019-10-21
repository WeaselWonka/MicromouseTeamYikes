typedef struct{
  int motorSpeed, motorForward, motorReverse;
} motor;

motor TestMotor = {0,0,0}; //format as {motorSpeed,motorForward,motorReverse}

void setup() {
  // put your setup code here, to run once:
  pinMode(TestMotor.motorSpeed,OUTPUT);
  pinMode(TestMotor.motorForward,OUTPUT);
  pinMode(TestMotor.motorReverse,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(TestMotor.motorSpeed,150);

  // Run the motor forward for 2 seconds
  digitalWrite(TestMotor.motorForward,1);
  digitalWrite(TestMotor.motorReverse,0);
  delay(2000);

  // Run the motor backward for 2 seconds
  digitalWrite(TestMotor.motorForward,0);
  digitalWrite(TestMotor.motorReverse,1);
  delay(2000);
  
}
