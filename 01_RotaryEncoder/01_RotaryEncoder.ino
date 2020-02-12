// https://www.youtube.com/watch?v=v4BbSzJ-hz4

/*
PINS
------
Rot. Encoder  -     Arduino

GND           -     Power GND
+             -     Power 5V
DT            -     Digital 6
CLK           -     Digital 7

*/


int outputA = 6;
int outputB = 7;

int counter = 0;
int aState;
int aLastState;

void setup() {
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);

  Serial.begin(9600);

  aLastState = digitalRead(outputA);
}

void loop() {
  aState = digitalRead(outputA);

  if(aState != aLastState){
    if(digitalRead(outputB) != aState){
      counter++;
    }
    else{
      counter--;
    }

    Serial.print("Position: ");
    Serial.print(counter);
  }
  aLastState = aState;
}
