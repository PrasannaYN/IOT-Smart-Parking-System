//#include <ArduinoJson.h>
// #include <ArduinoJson.hpp>
//Code from techzeero.com

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> //https://smart-parking-4ada0-default-rtdb.firebaseio.com/
#define FIREBASE_HOST "smart-parking-4ada0-default-rtdb.firebaseio.com"  //Your Firebase Project URL goes here without "http:" , "\" and "/" https://parking-trial-default-rtdb.firebaseio.com/
#define FIREBASE_AUTH "Bmz0rUCk35867tRlYEG2F4PrmjQHhNGj85FbhdwN"   //Your Firebase Database Secret goes here  eU0NMMlRhJ54IT267pgbIZ0QsWXvI2DlDkenB2CG

#define WIFI_SSID "Hackathon"                  //your WiFi SSID(Hotspot Name) for which your NodeMCU connects 
#define WIFI_PASSWORD "12345678"           //Password of your wifi network 

#define trigPin1 D1   //D0 (We Used GPIO Pin Number)
#define echoPin1 D0    //D1
#define trigPin2 D5    //D2
#define echoPin2 D6    //D3
#define trigPin3 D3   //D4
#define echoPin3 D2   //D5
 
void setup() 
{
  Serial.begin(9600);            // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() 
{
  if (Firebase.failed())
  {
    Serial.print("setting number failed:");
    Serial.println(Firebase.error());
    firebasereconnect();
    return;
  }
  
  //Ultrasonic Sensor 1

  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  int inch1 = duration1 *0.034/2;         // In Inch
  Serial.print ("Distance1: ");
  Serial.println(inch1);
  if(inch1 <=10)
  {
    Firebase.setInt("U1",1);
    Serial.println("U1 = 1");
  }
  else
  {
     Firebase.setInt("U1",0);
     Serial.println("U1 = 0");
  }
  
  //Ultrasonic Sensor 2

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int inch2 = duration2 *0.034/2;         // In Inch
  Serial.print ("Distance2: ");
  Serial.println(inch2);
  if(inch2 <=10)
  {
    Firebase.setInt("U2",1);
    Serial.println("U2 = 1");
  }
  else
  {
     Firebase.setInt("U2",0);
     Serial.println("U2 = 0");
  }
  
  //Ultrasonic Sensor 3

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  long duration3 = pulseIn(echoPin3, HIGH);
  long inch3 = duration3 *0.034/2;         // In Inch
  Serial.print ("Distance3: ");
  Serial.println(inch3);
  
  if(inch3 <=10)
  {
    Firebase.setInt("U3",1);
    Serial.println("U3 = 1");
  }
  else
  {
     Firebase.setInt("U3",0);
     Serial.println("U3 = 0");
  }
}