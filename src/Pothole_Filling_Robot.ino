#include<Servo.h>
Servo s;

int in1=2;
int in2=3;
int in3=4;
int in4=5;
int vry=A1;
int vrx =A0;
const int trig =6;
const int echo =A2;
const int servo=7;
long duration;
int distance;

void setup()
 {
pinMode(vrx , INPUT); //vrx
pinMode(vry,INPUT);   //vry
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
 pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
 s.attach(servo,0,180);
Serial.begin(9600);

}

void loop() 
{
  s.write(180);
distance=d();
if(distance<=3)
{
int y = analogRead(vry);
int x=analogRead(vrx);



if((x==0)&&(y<1023))
{
left();
}
else if((y==0)&&(x<1023))
{

forward();
}

else if((y<1023)&&(x==1023))
{
right();
}

else if((x<1023)&&(y==1023))
{
backward();
}
else
{
stop();
}
}
else
{
  stop();
s.write(0);
   distance=d();
}


}

void stop()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}


 void forward()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}


void right()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

void left()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}

void backward()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

long int d()
{

  digitalWrite(trig, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
return distance;
}
