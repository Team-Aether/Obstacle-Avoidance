int trigPin1 = 8;
int trigPin2 = 9;
int trigPin3 = 10;

int echo1 = 11;
int echo2 = 12;
int echo3 = 13;

int revLeft  = 4;
int fwdLeft  = 5;
int revRight = 6;
int fwdRight = 7;

long duration1,duration2,duration3, distance1, distance2, distance3 ;

void setup(){
  delay (random(500,2000)); //delay for a random time
  Serial.begin(9600);
  pinMode(revLeft, OUTPUT);
  pinMode(fwdLeft, OUTPUT);
  pinMode(revRight, OUTPUT);
  pinMode(fwdRight, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
}

void pause(){
    digitalWrite(revLeft,  LOW);  
    digitalWrite(fwdLeft,  LOW);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, LOW);
    delay(100);
  }
void moveForward(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, HIGH);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, HIGH);
    delay(500);
  }  
void moveRight(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, LOW);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, HIGH);
    delay(500);
 }

void moveLeft(){
    digitalWrite(revLeft, LOW);
    digitalWrite(fwdLeft, HIGH);
    digitalWrite(revRight, LOW);
    digitalWrite(fwdRight, LOW);
    delay(500);
  }
void reverse(){
    digitalWrite(revLeft, HIGH);
    digitalWrite(fwdLeft, LOW);
    digitalWrite(revRight, HIGH);
    digitalWrite(fwdRight, LOW);
    delay(500);
  }


void loop(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);

  duration1 = pulseIn(echoPin1, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
  duration3 = pulseIn(echoPin3, HIGH);

  distance1 = duration1 / 58.2 ; // convert to distance
  distance2 = duration2 / 58.2;
  distance3 = duration3 / 58.2;
  
  if (distance1 > 20 and distance2 > 20 and distance3 > 20){ //if no obstacles move forward
    moveForward();
  }
  if (distance 2 < 20){
    pause();
    moveRight();
    pause();
    moveForward();    
  }
  if (distance3 < 20){
    pause();
    moveLeft();
    pause();
    moveForward();  
  }
  if(distance1 < 20){
    pause();
    moveRight();
    pause();
    moveForward();  
  }

  //for stop and resume
  /*if (distance1 < 10 ){
    pause();
    reverse();
  } */ 
}
