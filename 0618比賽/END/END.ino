#include <Ping.h>
#include <Servo.h>
Servo servoPin1;
Servo servoPin2;

int whiskerPin1=5;
int whiskerPin2=7;
int x;
int y;

Ping ping1 = Ping(11);   //宣告左方超音波
Ping ping2 = Ping(4);   //宣告右方超音波
void setup() {
  pinMode(5,INPUT);
  pinMode(7,INPUT);
  servoPin1.attach(12);/*右邊*/
  servoPin2.attach(13);/*左邊*/
  Serial.begin(9600);
}

void loop(){
  int centimeters;
  float a=0,b=0;

  x=digitalRead(5);
  y=digitalRead(7);


  
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


  
  a=ping1.centimeters();    //宣告左方超音波
  b=ping2.centimeters();    //宣告右方超音波
  forward();

  if((x==1) && (y==1) && (10<a<30) && (0<b<20)) {
    backward();
    turn_left();
    forward();
    }

   if((x==1) && (y==1) && (0<a<20) && (100<b<30)) {
    backward();
    turn_right();
    forward();
    }
  
  if((10<a<30) && (0<b<20)){  //右轉
      turn_right();
      forward();
    }

    if((10<a<30) && (0<b<20)){   //左轉
      turn_left();
      forward();
    }
}  

/*副程式專區*/
  int forward(){                //前進的副程式
    for(int i = 0;i<8;i++){
    servoPin1.write(1300);
    servoPin2.write(1700);
    delay(500);
    }
   }
   int backward(){               //後退的副程式
    for(int i = 0;i<4;i++){
    servoPin1.write(1700);
    servoPin2.write(1300);
    delay(500);
    }
   }
   
  int turn_left(){            //左轉的副程式  
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(500);
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(500);
   }
  int turn_right(){           //右轉的副程式
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(500);
    servoPin1.write(1300);
    servoPin2.write(550);
    delay(500);
   }
