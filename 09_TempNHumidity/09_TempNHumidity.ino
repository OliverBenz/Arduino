#include "dht.h"

dht DHT;

#define DHT11_PIN 10
#define MOI_PIN 0

int map_low = 616;
int map_high = 301;

void setup(){
  Serial.begin(9600);
}

void loop()
{
  int moisturePer = map(analogRead(MOI_PIN), map_low, map_high, 0, 100);

  Serial.print("Moisture = ");
  Serial.print(moisturePer);
  Serial.println(" %");

  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);

  Serial.println("");
  Serial.println("----------------------");
  Serial.println("");

  if (moisturePer > 60){
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
  }

  delay(2000);
}
