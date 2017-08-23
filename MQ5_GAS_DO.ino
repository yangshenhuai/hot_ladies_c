/**
 * read the MQ5 Gas Sensor module to arduino using Digital Out PIN
 * 
 */
int sensor = 7;
int gas_value;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  gas_value = digitalRead(sensor);
  Serial.println(gas_value);
}
