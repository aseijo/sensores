#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define SENSORTEMP A0
#define SENSORLUZ A1

float dhtHum;
float dhtTemp;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  dhtTemp = dht.readTemperature();
  dhtHum = dht.readHumidity();
  
  int valorTemp = analogRead(SENSORTEMP);
  int valorLuz = analogRead(SENSORLUZ);
  float grados = ((valorTemp / 1023.0) * 5000) / 10;
  
  Serial.print("DHTTemp:");
  Serial.println(dhtTemp);  
  Serial.print("DHTHum:");
  Serial.println(dhtHum);
  Serial.print("Luz:");
  Serial.println(valorLuz);
  
  delay(2000);
  
}
