#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3);

char data;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(13, OUTPUT);//led
  bt.begin(9600);
}

void loop() {
  if (bt.available()) {
    data = bt.read();

    if (data == 'w') {
      forward();
    } else if (data == 's') {
      backward();
    } else if (data == 'a') {
      left();
    } else if (data == 'd') {
      right();
    } else if (data == 'x') {
      stop();
    }
    blink();
  }
  delay(50);
}

void blink(){
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13,LOW);
}

void forward() {
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void backward() {
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
}

void left(){
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
}

void right(){
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void stop(){
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
}