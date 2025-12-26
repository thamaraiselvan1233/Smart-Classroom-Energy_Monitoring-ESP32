int pirPin   = 13;
int ldrPin   = 34;
int greenLED = 2;
int redLED   = 4;
int buzzer   = 15;

int lightThreshold = 500;

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT_PULLDOWN);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.println("Smart Classroom Energy Monitor Started");
}

void loop() {
  int motion = digitalRead(pirPin);
  int lightValue = analogRead(ldrPin);

  Serial.print("Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.println(lightValue);

  if (motion == HIGH) {
    digitalWrite(greenLED, HIGH);

    if (lightValue > lightThreshold) {
      digitalWrite(redLED, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("ALERT: Unnecessary lights ON");
    } else {
      digitalWrite(redLED, LOW);
      digitalWrite(buzzer, LOW);
      Serial.println("Status: Classroom Normal");
    }

  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    Serial.println("Status: Classroom Empty");
  }

  delay(1000);
}
