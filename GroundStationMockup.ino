int32_t altitude = 0;
uint32_t lattitude = 542277318;
uint32_t longtitude = 183639024;
int16_t meanTemp = 3600;
uint8_t tempInfo0 = 0x00;
uint8_t tempInfo1 = 0x00;
uint8_t tempInfo2 = 0x00;
uint16_t lastFrame = 0x0001;
uint16_t status = 0x0000;
uint16_t statusKom = 0x0000;


uint8_t komRise = 0;
uint8_t i=0;

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
  altitude +=10;
  lattitude +=100;
  longtitude+=100;
  if (meanTemp >= 3750) {
    komRise = 0;
  } else if (meanTemp <= 3550) {
    komRise = 1;
  }
  if (komRise == 0) {
    meanTemp-=10;
  }
  else {
    meanTemp+=10;
  }
  tempInfo0 = 0;
  tempInfo1 = 0;
  tempInfo2 = 0;
  for (uint8_t j=0; j<=8; j+=2) {
    tempInfo0 |= ((i & 0x03) << j);
  }
  for (uint8_t j=0; j<=8; j+=2) {
    tempInfo1 |= ((i & 0x03) << j);
  }
  for (uint8_t j=0; j<=8; j+=2) {
    tempInfo2 |= ((i & 0x03) << j);
  }

  if (status == 0) {
    status = 1;
  }
  else {
    status <<= 1;
  }
  if (statusKom == 0) {
    statusKom = 1;
  }
  else {
    statusKom <<= 1;
  }
  i++;
  if (i > 3) i=0;

  printHex(((altitude >> 16) & 0xFFFF), 4);
  printHex(((altitude ) & 0xFFFF), 4);
  printHex(((lattitude >> 16) & 0xFFFF), 4);
  printHex(((lattitude ) & 0xFFFF), 4);
  printHex(((longtitude >> 16) & 0xFFFF), 4);
  printHex(((longtitude ) & 0xFFFF), 4);
  printHex(meanTemp, 4);
  printHex(tempInfo2, 2);
  printHex(tempInfo1, 2);
  printHex(tempInfo0, 2);
  printHex(lastFrame, 4);
  printHex(status, 4);
  printHex(statusKom, 4);

  Serial.println();
  delay(1000);        // delay in between reads for stability
}
