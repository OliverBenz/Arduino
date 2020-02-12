#include <IRremote.h>

IRsend irSend;

void setup() {
}

void loop() {
  irSend.sendSony(0xB4B8F, 20);
  delay(100);
}
