int ledPin = 6;
int sensorPin = 7;
int leitura = 0;
int ldr = A1;
int valorldr = 0;
bool estadoSensor = false;

void setup() {
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  valorldr = analogRead(ldr);
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(valorldr);

  if (valorldr > 100) {
    Serial.println("LDR maior que 100. Ignorando sensorPin.");
  } else {
    leitura = digitalRead(sensorPin);
    if (leitura == HIGH) {
      digitalWrite(ledPin, HIGH);
  
      if (estadoSensor == false) {
        Serial.println("Movimento detectado");
        estadoSensor = true;
         delay(4000);
      }
      delay(100);
    } else {
      digitalWrite(ledPin, LOW);
      if (estadoSensor == true) {
        Serial.println("Sem movimento");
        estadoSensor = false;
      }
    }
  }
  delay(600);
}