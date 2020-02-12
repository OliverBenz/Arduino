int sensor = 3;
int led = 13;

void setup() {
  // Sensor
  pinMode(sensor, INPUT);
  // LED
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  digitalWrite(led, LOW);
}

void loop() {
  if(digitalRead(sensor) == HIGH){
    digitalWrite(led, HIGH);
    
    Serial.println("Motion detected");
    delay(200);
  }
  else{
    digitalWrite(led, LOW);
    delay(200);
  }
}
