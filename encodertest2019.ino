
int motor1_speed = 6;
int motor1_forward = 3;
int motor1_backward = 2;

int motor2_speed = 7;
int motor2_forward = 4;
int motor2_backward = 5;

int encoder_pin_1A = 10;  //17
int encoder_pin_1B = 11;  //18
int encoder_pin_2A = 8;  //19
int encoder_pin_2B = 9;

volatile int encOne = 0;
volatile int encTwo = 0;
int a1_last;
int a1_current;
int a2_last;
int a2_current;

void setupEncoder(){
  pinMode(encoder_pin_1A,INPUT);
  pinMode(encoder_pin_1B,INPUT);
  pinMode(encoder_pin_2A,INPUT);
  pinMode(encoder_pin_2B,INPUT);
}

void encoderOne(){
  //Serial.println("EncoderOne call");
  
  a1_current = digitalRead(encoder_pin_1A);
  //Serial.println(a1_last);
  //Serial.println(a1_current);
  if (a1_last != a1_current){
   
    if (a1_current != digitalRead(encoder_pin_1B)){
      encOne++; //clockwise
    }
    else{
      encOne--; //counter-clockwise
    }
  }
  //Serial.println(encOne);
  //Serial.println("  ");
  a1_last = a1_current;
}

void encoderTwo(){
  //Serial.println("EncoderTwo call");
 
  a2_current = digitalRead(encoder_pin_2A);
  //Serial.println(a2_last);
  //Serial.println(a2_current);
  if (a2_last != a2_current){
   
    if (a2_current != digitalRead(encoder_pin_2B)){
      encTwo++; //clockwise
    }
    else{
      encTwo--; //counter-clockwise
    }
  }
  //Serial.println(encTwo);
  //Serial.println("  ");
  a2_last = a2_current;
}

void setupInterrupt(){
  //Serial.println(digitalPinToInterrupt(encoder_pin_A));
  attachInterrupt(encoder_pin_1A, encoderOne,CHANGE);
  attachInterrupt(encoder_pin_1B, encoderOne,CHANGE);
  attachInterrupt(encoder_pin_2A, encoderTwo, CHANGE);
  attachInterrupt(encoder_pin_2B, encoderTwo, CHANGE);
  }

  void motorSetup(){
  pinMode(motor1_speed,INPUT);
  pinMode(motor1_forward,INPUT);
  pinMode(motor1_backward,INPUT);

  pinMode(motor2_speed,INPUT);
  pinMode(motor2_forward,INPUT);
  pinMode(motor2_backward,INPUT);
}


void motorMovement(int speed,int f, int r){
  digitalWrite(motor1_speed, speed);
  analogWrite(motor1_forward, f);
  analogWrite(motor1_backward, r);
}
void setup() {
  // put your setup code here, to run once:
  setupEncoder();
  setupInterrupt();
  motorSetup();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  motorMovement(100, 1, 0);
  delay(2000);
  motorMovement(0, 0, 0);
  delay(2000);
  motorMovement(100, 0, 1);
  delay(2000);
  motorMovement(0, 0 ,0);
  delay(2000);
}
