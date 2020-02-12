const int hm = A0;
int value;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(hm);
  value = constrain(value, 400, 1023);
  // value = map(value, 400, 1023, 100, 0);

  Serial.print(value);
  Serial.print('\n');

  delay(1000);
}
