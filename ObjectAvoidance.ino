int trigLeft = A5;  // TrigA2,echo a3 -sn1
int trigRight = A1; // trigA1, echo A0 - sn2
int trigFwd= A2; // trigA5, echo A4 - sn3

int echoLeft= A4;
int echoRight = A0;
int echoFwd = A3;

int ENA = 9;
int ENB = 10;

int fwdLeft  = 2;  //IN1=2,IN2=3,IN3=4,IN4=5
int revLeft  = 3;
int fwdRight = 4;
int revRight = 5;

long durationLeft,durationRight,durationFwd, distanceLeft, distanceRight, distanceFwd;

void setup(){
  delay (random(500,2000)); //delay for a random time
  Serial.begin(9600);
  pinMode(revLeft,  OUTPUT);
  pinMode(fwdLeft,  OUTPUT);
  pinMode(revRight, OUTPUT);
  pinMode(fwdRight, OUTPUT);
  pinMode(trigLeft, OUTPUT);
  pinMode(trigRight,OUTPUT);
  pinMode(trigFwd,  OUTPUT);
  pinMode(echoLeft, INPUT);
  pinMode(echoRight,INPUT);
  pinMode(echoFwd,  INPUT);
}

const int speed = 45;


void pause(){
    digitalWrite(revLeft,  LOW);  
    digitalWrite(fwdLeft,  LOW);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, LOW);
    delay(10);
  }
void moveForward(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, HIGH);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, HIGH);
    analogWrite(ENA , speed);
    analogWrite(ENB, speed);
    delay(3000);
  }  
void moveRight(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, LOW);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, HIGH);
    analogWrite(ENA , speed);
    analogWrite(ENB, speed);
    
 }

void moveLeft(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, HIGH);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, LOW);
    analogWrite(ENA , speed);
    analogWrite(ENB, speed);
    
  }
void reverse(){
    digitalWrite(revLeft, HIGH);
    digitalWrite(fwdLeft, LOW);
    digitalWrite(revRight, HIGH);
    digitalWrite(fwdRight, LOW);
    analogWrite(ENA , 30);
    analogWrite(ENB, 50);
    delay(500);
  }

void checkForward(){
  if (distanceLeft > 10 and distanceRight > 10 and distanceFwd > 10){ //if no obstacles move forward
    moveForward();
  }
  else if (distanceFwd < 10){
    pause();
    moveRight();
    moveForward();
 }
}

void checkLeft(){
  if(distanceLeft < 10){
    pause();
    moveRight();
    moveForward();
  }
}
void checkRight(){
  if(distanceRight < 10){
    pause();
    moveLeft();
    moveForward();
 }
}

void loop(){
  digitalWrite(trigLeft, LOW);
  delayMicroseconds(2);
  digitalWrite(trigRight, LOW);
  delayMicroseconds(2);
  digitalWrite(trigFwd, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigLeft, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigFwd, HIGH);
  delayMicroseconds(10);

  durationLeft = pulseIn(echoLeft, HIGH);
  durationRight = pulseIn(echoRight, HIGH);
  durationFwd = pulseIn(echoFwd, HIGH);

  distanceLeft = durationLeft / 58.2 ; // convert to distance
  distanceRight = durationRight / 58.2;
  distanceFwd = durationFwd / 58.2;
  
  checkForward();
  checkLeft();
  checkRight();

}  
