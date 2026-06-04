// ===== PINS =====
const int pinLM35 = 34;  // Sensor de temperatura (LM35)
const int pinLDR = 35;   // Sensor de llum (LDR)
const int LED = 25;      // LED d'alerta

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
  Serial.println("--- SISTEMA INICIALITZAT (SENSE WIFI) ---");
}

// ===== FUNCIÓ LLEGIR SENSORS =====
void llegirSensors() {
  // Neteja visual de la consola (mulltes línies en blanc)
  for (int i = 0; i < 50; i++) Serial.println();

  // Llegir temperatura (LM35)
  int valorLM35 = analogRead(pinLM35);
  // Fórmula per a ESP32 (3.3V i 12 bits)
  float tempC = (valorLM35 * 3.3 / 4095.0) * 100.0;
  
  // Llegir llum (LDR)
  int valorLDR = analogRead(pinLDR);
  int percentLlum = map(valorLDR, 0, 4095, 0, 100);
  
  // --- NOVA LÒGICA DE CONTROL ---
  // Problema si la temperatura NO està entre 16 i 19
  bool problemaTemperatura = (tempC < 16.0 || tempC > 19.0);
  bool problemaLlum = (percentLlum < 30);
  
  // Control del LED: S'encén si hi ha qualsevol problema
  if (problemaTemperatura || problemaLlum) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  // ===== SORTIDA PER CONSOLA =====
  Serial.println("================================");
  Serial.println("🏫 PABELLÓ INTEL·LIGENT - TEMP I LLUM");
  Serial.println("================================");
  
  Serial.print("🌡️ Temperatura: ");
  Serial.print(tempC, 1);
  Serial.println(" °C");
  
  Serial.print("☀️ Llum: ");
  Serial.print(percentLlum);
  Serial.println(" %");
  
  Serial.println("--- ESTAT ---");
  
  if (problemaTemperatura) {
    if (tempC < 16.0) {
      Serial.print("⚠️ ALERTA: Fa massa fred! (<16°C)");
    } else {
      Serial.print("⚠️ ALERTA: Fa massa calor! (>19°C)");
    }
    Serial.println();
  } else {
    Serial.println("✅ Temperatura correcte (16-19°C)");
  }
  
  if (problemaLlum) {
    Serial.println("⚠️ ALERTA: Poca llum natural!");
  } else {
    Serial.println("✅ Bona llum natural");
  }
  
  if (problemaTemperatura || problemaLlum) {
    Serial.println("\n🔴 LED ALERTA: ACTIVAT");
  } else {
    Serial.println("\n🟢 LED: APAGAT (Confort òptim)");
  }
  
  Serial.println("================================");
}

// ===== LOOP =====
void loop() {
  llegirSensors();
  delay(500); // Actualització ràpida cada 0.5 segons
}
