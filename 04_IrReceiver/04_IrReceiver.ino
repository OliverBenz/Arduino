// Need Arduino-IRremote-master library
// https://github.com/z3t0/Arduino-IRremote

#include <IRremote.h>
#include <IRremoteInt.h>

int irPin = 13;
IRrecv receiver(irPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
}

void loop() {
  if(receiver.decode(&results)){
    if(results.value !=  4294967295){
      Serial.println(results.value, HEX);
    }
    receiver.resume();
  }
}
