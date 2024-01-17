#include <Ps3Controller.h>

int dirA=1, pwmA=2, dirB=3, dirC=4, pwmB=6, pwmC=7;
// CLOCKWISE high
//anticlockwise low


void setup() {
  Serial.begin(9600);
  Ps3.begin("01:02:03:04:05:06");

    if(Ps3.isConnected()){
    Serial.println("Connected");
  }

  pinMode(dirA,OUTPUT);
  pinMode(dirB,OUTPUT);
  pinMode(dirC,OUTPUT);
  pinMode(pwmA,OUTPUT);
  pinMode(pwmB,OUTPUT);
  pinMode(pwmC,OUTPUT);
  // put your setup code here, to run once:

}


void front()
{
  analogWrite(pwmA,0);
  digitalWrite(dirB,HIGH);
  analogWrite(pwmB,150);
  digitalWrite(dirC,LOW);
  analogWrite(pwmC,150);
}
void back()
{
  analogWrite(pwmA,0);
  digitalWrite(dirB,LOW);
  analogWrite(pwmB,150);
  digitalWrite(dirC,HIGH);
  analogWrite(pwmC,150);
}
void right()
{
  digitalWrite(dirA,HIGH);
  analogWrite(pwmA,100);
  digitalWrite(dirB,HIGH);
  analogWrite(pwmB,100);
  digitalWrite(dirC,HIGH);
  analogWrite(pwmC,100);

}
void left()
{
   digitalWrite(dirA,LOW);
   analogWrite(pwmA,100);
   digitalWrite(dirB,LOW);
  analogWrite(pwmB,100);
  digitalWrite(dirC,LOW);
  analogWrite(pwmC,100);

}
void fr()
{
   digitalWrite(dirA,HIGH);
   analogWrite(pwmA,150);
   digitalWrite(dirB,LOW);
   analogWrite(pwmB,150);
  
   analogWrite(pwmC,0);
}
void lb()
{
   digitalWrite(dirA,LOW);
   analogWrite(pwmA,150);
   digitalWrite(dirB,HIGH);
   analogWrite(pwmB,150);
  
   analogWrite(pwmC,0);


}
void lf()
{
   digitalWrite(dirA,LOW);
   analogWrite(pwmA,150);

   analogWrite(pwmB,0);
   digitalWrite(dirC,HIGH);
   analogWrite(pwmC,150);

}

void br()
{
   digitalWrite(dirA,HIGH);
   analogWrite(pwmA,150);

   analogWrite(pwmB,0);
   digitalWrite(dirC,LOW);
   analogWrite(pwmC,150);

}
void stop()
{
  analogWrite(pwmA,0);
  analogWrite(pwmB,0);
  analogWrite(pwmC,0);
}

void loop() {

  delay(3000);
  if( Ps3.event.button_down.cross )
        lb();
    if( Ps3.event.button_up.cross )
        stop();

    if( Ps3.event.button_down.square )
        lf();
    if( Ps3.event.button_up.square )
        stop();

    if( Ps3.event.button_down.triangle )
        fr();
    if( Ps3.event.button_up.triangle )
        stop();

    if( Ps3.event.button_down.circle )
        br();
    if( Ps3.event.button_up.circle )
        stop();

    //--------------- Digital D-pad button events --------------
    if( Ps3.event.button_down.up )
        front();
    if( Ps3.event.button_up.up )
        stop();

    if( Ps3.event.button_down.right )
        right();
    if( Ps3.event.button_up.right )
        stop();

    if( Ps3.event.button_down.down )
        back();
    if( Ps3.event.button_up.down )
        stop();

    if( Ps3.event.button_down.left )
        left();
    if( Ps3.event.button_up.left )
        stop();
}
