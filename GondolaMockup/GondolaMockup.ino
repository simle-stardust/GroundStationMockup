typedef struct
{
  int16_t RTD[30] = {0x0000};
  int16_t mosfet[12] = 0x0000;
  int16_t flag = 0x0000;

} frame_antares;

frame_antares Memory;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("MarcinSetValuesKom:");
  for (int i = 0; i < 30; ++i) {
    Memory.RTD[i] = random(0xFFFF);
    Serial.write(Memory.RTD[i] >> 8);
    Serial.write(Memory.RTD[i] & 0xFF);
    Serial.print(",");
  }
  for (int i=0; i<12; i++) {
    Memory.mosfet[i] = random(0xFFFF);
    Serial.write(Memory.mosfet[i] >> 8);
    Serial.write(Memory.mosfet[i] & 0xFF);
    Serial.print(",");
  }
  Memory.flag = random(0xFFFF);
  Serial.write(Memory.flag >> 8);
  Serial.write(Memory.flag & 0xFF);
  Serial.println("!");
  delay(1000);        // delay in between reads for stability
}
