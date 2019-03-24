typedef struct
{
  int16_t RTD[30] = {0x0000};
  int16_t mosfet = 0x0000;
  int16_t flag = 0x0000;

} frame_antares;

frame_antares Memory;

void printHex(int32_t num, int precision) {
     char tmp[16];
     char format[128];

     sprintf(format, "%%.%dX", precision);
     //Serial.println(format);
     sprintf(tmp, format, num);
     Serial.print(tmp);
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("MarcinSetValuesKom:");
  for (int i = 0; i < 30; ++i) {
    Memory.RTD[i] = random(0x1111);
    printHex(Memory.RTD[i], 2);
  }
  Memory.mosfet = random(0x1111);
  printHex(Memory.mosfet, 4);
  Memory.flag = 
  printHex(Memory.flag, 4);
  Serial.println("!");
  delay(1000);        // delay in between reads for stability
}
