#include <esp_sleep.h>

#define LED_G 26
#define LED_B 27

void tareaActiva() {

  Serial.println("Sistema ACTIVO");

  digitalWrite(LED_G, HIGH);

  for (int i = 10; i > 0; i--) {
    Serial.printf("Entrando en Light Sleep en %d segundos\n", i);
    delay(1000);
  }

  digitalWrite(LED_G, LOW);
}

void entrarLightSleep() {

  Serial.println("Entrando en Light Sleep");

  digitalWrite(LED_B, HIGH);

  // Despertar después de 5 segundos
  esp_sleep_enable_timer_wakeup(5000000);

  delay(100);
  Serial.flush();

  esp_light_sleep_start();

  digitalWrite(LED_B, LOW);

  Serial.println("Despertado del Light Sleep");
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.println("Sistema iniciado");
}

void loop() {

  tareaActiva();

  entrarLightSleep();

  delay(1000);
}
