#include <Ping.h>
#include <Servo.h>
Servo servoPin1;
Servo servoPin2;

int light=5;/*光敏*/
int value1;
int value2;
int ps1 = A4;
int ps2 = A5;

int x,y;

Ping ping1 = Ping(11);   /*宣告左方超音波*/
Ping ping2 = Ping(4);   /*宣告右方超音波*/
void setup() {
  pinMode(5,INPUT);/*左邊觸鬚*/
  pinMode(7,INPUT);/*右邊觸鬚*/
  servoPin1.attach(12);/*右邊*/
  servoPin2.attach(13);/*左邊*/
  pinMode(ps1,INPUT);
  pinMode(ps2,INPUT);
  Serial.begin(9600);
}

void loop(){
  int centimeters;
  float a=0,b=0;

  x=digitalRead(5);/*左邊觸鬚*/
  y=digitalRead(7);/*右邊觸鬚*/

  value1 = analogRead(ps1);
  value2 = analogRead(ps2);


  ping1.fire();
  Serial.print("Microseconds1: ");
  Serial.print(ping1.microseconds());
  Serial.print(" | Centimeters1: ");
  Serial.print(ping1.centimeters());
  Serial.println();

  ping2.fire();
  Serial.print("Microseconds2: ");
  Serial.print(ping2.microseconds());
  Serial.print(" | Centimeters2: ");
  Serial.print(ping2.centimeters());
  Serial.println();

  Serial.println(value1);/*把光敏數值轉類比*/
  delay(2000);
  Serial.println(value2);/*把光敏數值轉類比*/
  delay(2000);
  
  a=ping1.centimeters();    /*宣告左方超音波*/
  b=ping2.centimeters();    /*宣告右方超音波*/

  while((value1>150) && (value2>100))
  {
    forward(100);
    forward(100);

    if((x==1) && (y==1) && (25<a<125) && (0<b<20)) {/*第一二個彎*/
      backward(100);
      turn_left(100);
      forward(100);
      }

    if((x==1) && (y==1) && (37<a<50) && (15<b<120)) {/*第三個彎*/
      backward(100);
      turn_right(100);
      forward(100);
      }
  
   if((37<a<50) && (15<b<120)) {/*第四個彎*/
      turn_right(100);
      forward(100);
      }
  }
  
}  

/*副程式專區*/
  void forward(int time){                /*前進的副程式*/
    for(int i = 0;i<8;i++){
    servoPin1.write(1300);
    servoPin2.write(1700);
    delay(time);
    }
   }
   void backward(int time){               /*後退的副程式*/
    for(int i = 0;i<2;i++){
    servoPin1.write(1700);
    servoPin2.write(1300);
    delay(time);
    }
   }
  void turn_left(int time){            /*左轉的副程式*/
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(time);
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(time);
   }
  void turn_right(int time){           /*右轉的副程式*/
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(time);
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(time);
   }
