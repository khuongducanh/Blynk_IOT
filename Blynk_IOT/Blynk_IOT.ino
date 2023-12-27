#define BLYNK_TEMPLATE_ID "TMPL6NhAbNJhO"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "P7GeajmFSDryXyHLLGkfeO5uv89nBuiz"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <string.h>
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 25
DHT dht(DHTPIN,DHTTYPE);

#define LED1 13
#define LED2 12
#define LED3 14
#define LED4 27
#define BLYNK_PRINT Serial

WidgetLED LED1_ON_APP(V4);
WidgetLED LED2_ON_APP(V5);
WidgetLED LED3_ON_APP(V6);
WidgetLED LED4_ON_APP(V7);

int button1;
int button2;
int button3;
int button4;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Sir Hai T4";
char pass[] = "0987167931";

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(26,OUTPUT);
  digitalWrite(26,HIGH);
  dht.begin();
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}



BLYNK_WRITE(V0) {
  button1 = param.asInt();
    if(button1 == 1){
      digitalWrite(LED1, HIGH);
      LED1_ON_APP.on();
      delay(500);
    }else{
      digitalWrite(LED1, LOW);
      LED1_ON_APP.off();
      delay(500);
    }
}

BLYNK_WRITE(V1) {
  button2 = param.asInt();
    if(button2 == 1){
      digitalWrite(LED2, HIGH);
      LED2_ON_APP.on();
      delay(500);
    }else{
      digitalWrite(LED2, LOW);
      LED2_ON_APP.off();
      delay(500);
    }
}


BLYNK_WRITE(V2) {
  button3 = param.asInt();
    if(button3 == 1){
      digitalWrite(LED3, HIGH);
      LED3_ON_APP.on();
      delay(500);
    }else{
      digitalWrite(LED3, LOW);
      LED3_ON_APP.off();
      delay(500);
    }
}

BLYNK_WRITE(V3) {
  button4 = param.asInt();
    if(button4 == 1){
      digitalWrite(LED4, HIGH);
      LED4_ON_APP.on();
      delay(500);
    }else{
      digitalWrite(LED4, LOW);
      LED4_ON_APP.off();
      delay(500);
    }
}


void cambiennhietdodoam(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  // Check is Read 
  if (isnan(h) || isnan(t)) {
    delay(500);
    Serial.println("Failed to read from DHT sensor!\n");
    return;
  }
  Blynk.virtualWrite(V8, t);
  Blynk.virtualWrite(V9, h);
  Serial.print("\n");
  Serial.print("Do Am " + String(h) + "%");
  Serial.print("\t");
  Serial.print("Nhiet Do" + String(t) + " C");
  delay(2000);
}


void loop() {
Blynk.run();
cambiennhietdodoam();
}
