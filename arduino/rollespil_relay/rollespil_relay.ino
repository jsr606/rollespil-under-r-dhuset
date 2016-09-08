// arduino control of dial up machine

int ledPin[5] = {2,3,4,5,6};
int relayPin[5] = {8,9,10,11,12};

boolean onOff[5] = {false, false, false, false, false};

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i<5; i++) {
    pinMode(ledPin[i], OUTPUT);
    pinMode(relayPin[i], OUTPUT);
    digitalWrite(ledPin[i], HIGH);
    delay(30);
    digitalWrite(ledPin[i], LOW);
  }
}

void loop() {
  if (Serial.available() > 5) {
    byte incoming = Serial.read();
    if (incoming != 255) {
      Serial.flush();
    } else {
      Serial.print(char(255));
      for (int i = 0; i<5; i++) {
        incoming = Serial.read();
        if (incoming == 0) {
          digitalWrite(ledPin[i], LOW);
          digitalWrite(relayPin[i], LOW);
          onOff[i] = false;
          Serial.print(char(0));
        } else {
          digitalWrite(ledPin[i], HIGH);
          digitalWrite(relayPin[i], HIGH);
          onOff[i] = true;
          Serial.print(char(1));
        }
      }
    }
  }
  /*
  for (int i = 0; i<5; i++) {
    if (onOff[i] == true) {
      Serial.print(char(1));
    } else {
      Serial.print(char(0));
    }
    Serial.println();
    delay(5);
  }
  */
  delay(25);
}

