
float sensor = A0;
float gas_value;
void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  gas_value=analogRead(sensor);
  Serial.println(gas_value);
}
