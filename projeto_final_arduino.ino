#define BLYNK_TEMPLATE_ID "TMPLj-Iqazsf"
#define BLYNK_DEVICE_NAME "sensor"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>   //Biblioteca do Esp-8266

char auth[] = "teW1HXJWSRziAE4N1Fi40OCNjvVKf7QJ";    //Codigo de autenticação do blink
char ssid[] = "get's Galaxy A12";                    // Nome da rede
char pass[] = "ndmm8288";                            // Senha da rede



const int echoPin = D1;         // Variáveis do Sensor ultrasônico, echo e trig
const int trigPin = D2;

long duration;                  // Variáveis para calculo de duração e distancia
int distance; 


void setup()
{ Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
    
  Blynk.begin(auth, ssid, pass);
}

void loop()
{ digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.017; 


  Blynk.virtualWrite(V2, distance);
  Blynk.run();
  delay(500);
  }
