int rangeSensor = A0;

void setup() {
  Serial.begin(9600); //defines the speed of the connection
  
}

void loop() {
  int voltage = analogRead(rangeSensor);
  Serial.println(voltage);
  delay(100);//ms
}
