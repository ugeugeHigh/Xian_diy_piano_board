#include <Wire.h>
#include <M5Stack.h>
const int i2c_addr = 0x1C;
int d=0,c=0,e=0;
int volume=3;
void setup() {

  Serial.begin(115200);
  Wire.begin();
  M5.begin();      
  M5.Power.begin();  
  M5.Lcd.setTextSize(7);
 
  delay(500);
  pinMode(26, OUTPUT);
  pinMode(36, INPUT);
  
}

int value(int a) {
  Wire.beginTransmission(i2c_addr);
  Wire.write(a);
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr,1);
 
  d = Wire.read();
  return d; 
  
}

void tone_(int c,int d, int oct) {
  M5.Speaker.setVolume(volume);

  if (oct == 0) {
        digitalWrite(26,LOW);
        if(d == 1){
            M5.Speaker.tone(262, 200);
            Serial.println("C4");
        }else if(d == 2) {
            M5.Speaker.tone(277, 200);
            Serial.println("Cs4");
        }else if(d == 4) {
            M5.Speaker.tone(294, 200);
            Serial.println("D4");
        }else if(d == 8) {
            M5.Speaker.tone(311, 200);
            Serial.println("Ds4");
        }else if(d == 16) {
            M5.Speaker.tone(330, 200);
            Serial.println("E4");
        }else if(d == 32) {
            M5.Speaker.tone(349, 200);
            Serial.println("F4");
        }else if(d == 64) {
            M5.Speaker.tone(370, 200);
            Serial.println("Fs4");
        }else if(d == 128) {
            M5.Speaker.tone(392, 200);
            Serial.println("G4");
        }else if(c == 1) {
            M5.Speaker.tone(415, 200);
            Serial.println("Gs4");
        }else if(c == 2) {
            M5.Speaker.tone(440, 200);
            Serial.println("A4");
        }else if(c == 4) {
            M5.Speaker.tone(466, 200);
            Serial.println("As4");
        }else if(c == 8) {
            M5.Speaker.tone(494, 200);
            Serial.println("B4");
        }else {
            M5.Speaker.mute();  
        }
          
  } else if(oct == 1) {
        digitalWrite(26,HIGH);
        if(d == 1){
            M5.Speaker.tone(523, 200);
        }else if(d == 2) {
    
            M5.Speaker.tone(554, 200);
        }else if(d == 4) {
            M5.Speaker.tone(587, 200);
        }else if(d == 8) {
            M5.Speaker.tone(622, 200);
        }else if(d == 16) {
            M5.Speaker.tone(659, 200);
        }else if(d == 32) {
            M5.Speaker.tone(698, 200);
        }else if(d == 64) {
            M5.Speaker.tone(740, 200);
        }else if(d == 128) {
            M5.Speaker.tone(784, 200);
        }else if(c == 1) {
            M5.Speaker.tone(831, 200);
        }else if(c == 2) {
            M5.Speaker.tone(880, 200);
        }else if(c == 4) {
            M5.Speaker.tone(932, 200);
        }else if(c == 8) {
            M5.Speaker.tone(988, 200);
        }else {
            M5.Speaker.mute();  
        }

  }
  
  
}

void loop() {
  c = value(0x03);
  d = value(0x04);
  //Wire.requestFrom(i2c_addr,1);
  //Serial.println(c);
  /*
  c = Wire.read();
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr,2);
  Serial.println(c);
  */
  e = digitalRead(36);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.printf("%4d",d); 
  tone_(d,c,e);

  delay(10);
}
