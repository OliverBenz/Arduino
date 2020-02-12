#define SHIFT_DATA 2
#define SHIFT_DATA_A 14 // Begin of 3 analog data pins

#define SHIFT_CLK 3
#define SHIFT_LATCH 4

void setAddress(int address){
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, address);


  for(int i = 0; i < 3; i++){
    digitalWrite(SHIFT_DATA_A+i, (address >> (8+i)));  
  }
  
  digitalWrite(SHIFT_DATA_A, (address>>8) & 0x4 > 0);
  digitalWrite(SHIFT_DATA_A+1, (address>>9) & 0x2 > 0);
  digitalWrite(SHIFT_DATA_A+2, (address>>10) & 0x1 > 0);

  digitalWrite(SHIFT_LATCH, LOW);
  digitalWrite(SHIFT_LATCH, HIGH);
  digitalWrite(SHIFT_LATCH, LOW);
}


void setup() {
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  for(int i =0; i < 3; i++) pinMode(SHIFT_DATA_A+i, OUTPUT);

  setAddress(0b00000000000);
}

void loop() {
}
