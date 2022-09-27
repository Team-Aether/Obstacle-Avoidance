int IR1 = 8; //forward facing IR
int IR2 = 9; // left facing IR
int IR3 = 10; //right facing IR

//driving motors 
int revLeft  = 4;
int fwdLeft  = 5;
int revRight = 6;
int fwdRight = 7;


void setup(){
  Serial.begin(9600);
  pinMode(revLeft, OUTPUT);
  pinMode(fwdLeft, OUTPUT);
  pinMode(revRight, OUTPUT);
  pinMode(fwdRight, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
}

int STAT1 = digitalRead(IR1);
int STAT2 =digitalRead(IR2);
int STAT3 =digitalRead(IR3);


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

void checkLeft(){
  if (STAT2 == 1){
    pause();
    moveRight();
    moveForward();
  }
}  
void checkRight(){
  if (STAT3 == 1){
    pause();
    moveLeft();
    moveForward();
  }
}

void checkForward(){
  if(STAT1 == 1){
    pause();
    moveLeft();
    moveForward();
  }
}
void loop(){
  checkLeft();
  checkRight();
  checkForward();
}
