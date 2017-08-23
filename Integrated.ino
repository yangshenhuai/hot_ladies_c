
/**
 * will try to read from several sensors
 * 
 */

float gas_sensor = A0;
int i = 0; // use the i as the indicator to determin read from which digil output or analogue out

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

 
  Serial.print("gs");
  Serial.print(readGasSensor());
  Serial.println("ge");


  i++;
}

float readGasSensor() {
  float gas_value=analogRead(gas_sensor);
  return gas_value;
}

