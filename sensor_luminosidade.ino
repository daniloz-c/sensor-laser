
int ldr_pin = A0;
int piezo_pin = 6;
int valorldr = 0;

int limite = 950; // Sensibilidade do sensor

void setup() {
  pinMode(ldr_pin, INPUT);
  pinMode(piezo_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valorldr = analogRead(ldr_pin);

  Serial.print("Valor lido pelo LDR = ");
  Serial.println(valorldr);

  // Se o laser for interrompido
  if (valorldr < limite) {
    tone(piezo_pin, 10000); // Apita a 1000 Hz
    Serial.println("ALERTA: Objeto detectado!");
  }
  else {
    noTone(piezo_pin); // Desliga o Piezo
  }

  delay(100);
}
