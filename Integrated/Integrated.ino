#include <Adafruit_Sensor.h>
#include <DHT.h>


#define DHTPIN 3
#define DHTTYPE DHT22

DHT dht(DHTPIN,DHTTYPE);
/**
 * will try to read from several sensors
 * 
 */

float gas_sensor = A0;
float flame_sensor = A1;
float temp ;
float hum ;
int i = 0 ; // use the i as the indicator to determin read from which digil output or analogue out
const int flameSensorMin = 0;
const int flameSensorMax = 1024;

void setup() {
  // put your setup code here, to run once:
  pinMode(gas_sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i >= 10000) {
    i = 0 ;// avoid overflow 
  }

  if(i % 3==0) {
    Serial.print("gs");
    Serial.print(readGasSensor());
    Serial.println("ge");
  } else if(i%3==1)  {
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    Serial.print("hts");
    Serial.print(hum);
    Serial.print("-");
    Serial.print(temp);
    Serial.println("hte");
  } else {
    int range = detectFire();
    if(range == 0 || range ==1) {
      Serial.println("Fire");
    } else {
      Serial.println("No F");
    }
  }
  i++;
}

float readGasSensor() {
  float gas_value=analogRead(gas_sensor);
  return gas_value;
}

int detectFire(){
  int flameSensorReading = analogRead(flame_sensor);
  int range = map(flameSensorReading,flameSensorMin,flameSensorMax,0,3);
  return range; 
}


