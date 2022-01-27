// แก้เวลา tran เสร็จ Verify ทุกครั้งก่อน Upload เพื่อตรวจสอบว่า Code ว่า error ไหม
// หลังจาก Done Uploading ไปที่ Serial Monitor ใส่เวลา้ในการถ่ายภาพไป(วินาที)
// เช่น ใส่ เลข 5 ไป แล้วกด Send มอเตอร์จะหยุด ถ่ายภาพ 5 วินาที
#include <SoftwareSerial.h>
int enA = 9;
int in1 = 10;
int in2 = 11;
String n = "0" ;
int time;
float tran;

SoftwareSerial mySerial(2, 3);
String inputString = "";
void setup() {
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 mySerial.begin(9600);
 Serial.begin(9600);
 tran = 5; //<<-----ฒใส่เวลาส่ง Source เป็นวินาที เช่น tran = 5 => 5วินาที(แก้เฉพาะตรง นี้ เท่านั้น)
}

void loop() {
  if (Serial.available() > 0) { 
      n = Serial.readString(); 
      Serial.print("Time : ");
      Serial.println(n);
      time = n.toInt();
  if (n== "0" ){
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.println("can not start!");
    }
  else{
 //Stage 1 – MAX speed
    analogWrite(enA, 255);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("Start");
    delay(tran*1000UL); 
 //Stage 2 stop !!!
    analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.println("stop");
    delay(time*1000UL);
  //Stage 3 MAX speed reversing the direction in reverse
    analogWrite(enA, 255);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("reversing");
    delay(tran*1000UL); 
    Serial.println("OK!");
    }
  }
  analogWrite(enA, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(500);
 

}
