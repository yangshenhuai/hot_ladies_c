
float fire_sensor = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(fire_sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   float fire_value = analogRead(fire_sensor);
   Serial.println(fire_value);
}
