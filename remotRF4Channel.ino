#include <rm4.h>

static const int kData0Pin = 3;   // pin di arduino dari D0 receiver
static const int kData1Pin = 4;   // pin di arduino dari D1 receiver
static const int kData2Pin = 5;   // pin di arduino dari D2 receiver
static const int kData3Pin = 6;   // pin di arduino dari D3 receiver

const int relay1 =  8;            // pin di arduino dari relay
const int relay2 =  9;            // pin di arduino dari relay
//const int relay3 =  10;         // pin di arduino dari relay
//const int relay4 =  11;         // pin di arduino dari relay

RM4 remote(kData0Pin, kData1Pin, kData2Pin, kData3Pin);

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  //pinMode(relay3, OUTPUT);
  //pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  //digitalWrite(relay3, HIGH);
  //digitalWrite(relay4, HIGH);

}

void loop() {
  const int button_code = remote.buttonCode();
  //Tombol B
   if (button_code == 1) {
    digitalWrite(relay1, HIGH);
  }
  //Tombol A
   if (button_code == 4) {
    digitalWrite(relay1, LOW);
  }
  //Tombol C
   if (button_code == 8) {
    digitalWrite(relay2, LOW);
  }
  //Tombol D
   if (button_code == 2) {
    digitalWrite(relay2, HIGH);
  }

 Serial.println(button_code);
  
 delay(100);
}
