const int seg7[] = {22, 23, 24, 25, 26, 27, 28, 29};
const int scan[] = {30, 31, 32, 33};
int delaytime = 5;
char TAB[] { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x18};
int ii, jj;
void setup() {
  for (ii = 0; ii < 7; ii++) {
    pinMode(seg7[ii], OUTPUT);
  }
  for (ii = 0; ii < 4; ii++) {
    pinMode(scan[ii], OUTPUT);
    digitalWrite(scan[ii], LOW);
  }
  Serial.begin(9600);
}
void loop () {
  if (Serial.available()) {
    delaytime = Serial.readStringUntil('\n').toInt();
    Serial.print(delaytime);
    Serial.println(" ms");
  }
  OutPort(TAB[5]);
  digitalWrite(scan[0], LOW);
  delay(delaytime);
  digitalWrite(scan[0], HIGH);

  OutPort(TAB[2]);
  digitalWrite(scan[1], LOW);
  delay(delaytime);
  digitalWrite(scan[1], HIGH);

  OutPort(TAB[4]);
  digitalWrite(scan[2], LOW);
  delay(delaytime);
  digitalWrite(scan[2], HIGH);

  OutPort(TAB[0]);
  digitalWrite(scan[3], LOW);
  delay(delaytime);
  digitalWrite(scan[3], HIGH);
}
void OutPort(byte dat) {
  for (jj = 0; jj < 7; jj++) {
    digitalWrite(seg7[jj], dat % 2);
    dat = dat / 2;
  }
}
