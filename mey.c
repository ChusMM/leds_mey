

#define POS_ROJO 0
#define POS_VERDE 1
#define POS_AMA 2
#define POS_AZUL 3

#define LEDS_SIZE 4

int si = D2; // pulsador si rojo
int no = D7; // pulsador no rojo

int leds[LEDS_SIZE];
int ledActive = 0;

void setup() {
  leds[POS_ROJO] = D5;
  leds[POS_VERDE] = D6;
  leds[POS_AMA] = D4;
  leds[POS_AZUL] = D8;

  // put your setup code here, to run once:
  pinMode (leds[POS_ROJO], OUTPUT); // led Rojo salida
  pinMode (leds[POS_VERDE], OUTPUT); // led Verde salida
  pinMode (leds[POS_AMA], OUTPUT); // led Amarillo salida
  pinMode (leds[POS_AZUL], OUTPUT); // led Azul salida
  pinMode (si, INPUT); // pulsador si rojo entrada
  pinMode (no, INPUT); //pulsador no rojo entrada
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  for (i = 0; i < LEDS_SIZE; i++) {
    blinkAndEvaluate(leds[i]);
  }
  
}

void blinkAndEvaluate(int currentLed) {
  while (digitalRead (si) == LOW && digitalRead (no) == LOW) {
    digitalWrite (currentLed, HIGH);
    delay (250);
    digitalWrite (currentLed, LOW);
    delay (250); 
  }

  if (digitalRead (si) == HIGH && digitalRead (no) == LOW) {
    digitalWrite (currentLed, HIGH);
  } else {
    if (digitalRead (si) == LOW && digitalRead (no) == HIGH) {
      digitalWrite (currentLed, LOW); 
    }
  }
}
