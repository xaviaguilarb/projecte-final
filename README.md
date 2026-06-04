# Projecte FInal - Pabelló escolar: Monitorització de temperatura i llum

## 📌 Descripció del projecte

Aquest projecte forma part de l'assignatura d'Informàtica industrial / Sistemes embedded. L'objectiu és desenvolupar un sistema de monitorització ambiental per a pabelló escolar utilitzant una **ESP32**.

El sistema llegeix la **temperatura** (mitjançant un sensor LM35) i el **nivell de llum** (mitjançant un LDR) i mostra les dades pel monitor sèrie. Quan les condicions surten dels rangs de confort establerts, s'activa un **LED d'alerta**.

### 🎯 Objectius

- ✅ Llegir temperatura amb sensor LM35
- ✅ Llegir nivell de llum amb LDR
- ✅ Mostrar dades estructurades pel monitor sèrie
- ✅ Detectar situacions de confort deficient
- ✅ Activar LED d'alerta visual
- ✅ Documentar el projecte completament

### 📊 Rangs de confort

| Paràmetre | Rang òptim | Alerta |
| :--- | :--- | :--- |
| 🌡️ Temperatura | 20°C - 24°C | < 20°C o > 24°C |
| ☀️ Llum | > 30% | < 30% |

---

## 🛠️ Components utilitzats

| Component | Quantitat | Descripció |
| :--- | :---: | :--- |
| ESP32 | 1 | Placa de desenvolupament |
| LM35 | 1 | Sensor de temperatura analògic |
| LDR | 1 | Fotorresistor per mesurar llum |
| LED vermell | 1 | Alerta visual |
| Resistència 220Ω | 1 | Per al LED |
| Resistència 10kΩ | 1 | Per al LDR (pull-down) |
| Cables | - | Cables de connexió |
| Protoboard | 1 | Placa de proves |

---

## 🔌 Connexions

| Component | Pin ESP32 | Descripció |
| :--- | :--- | :--- |
| LM35 (VCC) | 3.3V | Alimentació |
| LM35 (GND) | GND | Terra |
| LM35 (OUT) | GPIO34 | Sortida analògica |
| LDR | GPIO35 | Sortida analògica (amb resistència 10kΩ a GND) |
| LED (+) | GPIO27 | Sortida digital |
| LED (-) | GND | Terra (amb resistència 220Ω) |
