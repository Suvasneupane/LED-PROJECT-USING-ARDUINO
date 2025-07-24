const int ledCount = 12;
const int ledPins[ledCount] = {2,3,4,5,6,7,8,9,10,11,12,13};

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  patternKnightRider();
  patternChase();
  patternBlinkAll();
  patternWave();
  patternAlternate();
  patternPingPong();
  patternRandomTwinkle();
  patternRaining();
  patternAdvanceGlow();
}

/* ----------- Patterns ----------- */

// 1. Knight Rider
void patternKnightRider() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(80);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCount-2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(80);
    digitalWrite(ledPins[i], LOW);
  }
}

// 2. Chase
void patternChase() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

// 3. Blink All
void patternBlinkAll() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], HIGH);
    delay(300);
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
    delay(300);
  }
}

// 4. Wave
void patternWave() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }
}

// 5. Alternate
void patternAlternate() {
  for (int j = 0; j < 6; j++) {
    // Even ON, Odd OFF
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], (i%2==0)?HIGH:LOW);
    delay(300);
    // Odd ON, Even OFF
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], (i%2!=0)?HIGH:LOW);
    delay(300);
  }
}

// 6. Ping-Pong
void patternPingPong() {
  int mid = ledCount / 2;
  for (int step = 0; step < mid; step++) {
    digitalWrite(ledPins[step], HIGH);
    digitalWrite(ledPins[ledCount - 1 - step], HIGH);
    delay(120);
  }
  for (int step = mid - 1; step >= 0; step--) {
    digitalWrite(ledPins[step], LOW);
    digitalWrite(ledPins[ledCount - 1 - step], LOW);
    delay(120);
  }
}

// 7. Random Twinkle
void patternRandomTwinkle() {
  for (int i = 0; i < 25; i++) {
    int randLed = random(ledCount);
    digitalWrite(ledPins[randLed], HIGH);
    delay(80);
    digitalWrite(ledPins[randLed], LOW);
  }
}

// 8. Raining Effect (Top to Bottom)
void patternRaining() {
  for (int drop = 0; drop < 3; drop++) {
    for (int i = ledCount-1; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
      digitalWrite(ledPins[i], LOW);
    }
  }
}

// 9. Advance Glow (2→13, 2→12, 2→11...)
void patternAdvanceGlow() {
  // Turn OFF all first
  for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);

  for (int end = ledCount-1; end >= 0; end--) {
    for (int i = 0; i <= end; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(80);
    }
    delay(200);
    // Leave previous LEDs ON
  }

  // Finally clear all
  delay(500);
  for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
}
