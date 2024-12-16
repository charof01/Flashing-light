// กำหนดขา LED และปุ่ม
int led1 = 12;
int led2 = 13;
int led3 = 14;
int led4 = 15;
int buttonPin = 4;  // ปุ่มกดต่อที่ GPIO4

int buttonState = 0;         // ตัวแปรเก็บสถานะปัจจุบันของปุ่ม  
int lastButtonState = HIGH;  // ตัวแปรเก็บสถานะก่อนหน้าของปุ่ม (เริ่มต้นเป็น HIGH เพราะใช้ INPUT_PULLUP)
bool ledState = false;       // สถานะของ LED (เริ่มต้นปิด)
bool isBlinking = false;     // ตรวจสอบสถานะการกระพริบของ LED

void setup() {
  // กำหนดขา LED เป็น Output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  // กำหนดขาปุ่มเป็น INPUT_PULLUP
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // อ่านสถานะปุ่ม
  buttonState = digitalRead(buttonPin);

  // ตรวจสอบการเปลี่ยนแปลงสถานะปุ่ม (จาก HIGH -> LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    // สลับสถานะการกระพริบ LED
    if (isBlinking) {
      // ถ้า LED กระพริบอยู่, หยุดการกระพริบ
      ledState = false;
      isBlinking = false;
    } else {
      // ถ้า LED ไม่กระพริบ, ให้เริ่มกระพริบ
      ledState = true;
      isBlinking = true;
    }

    // ดีเลย์เล็กน้อยเพื่อให้สามารถกดปุ่มใหม่ได้
    delay(200);
  }

  // อัพเดตสถานะของปุ่ม
  lastButtonState = buttonState;

  // ถ้า LED ต้องการกระพริบ, ทำการกระพริบ LED
  if (isBlinking) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    delay(500);  // LED กระพริบ (เปิด 500ms)
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(500);  // LED ปิด (500ms)
  } else {
    // ถ้า LED ไม่กระพริบ, ให้ปิด LED ทั้งหมด
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}
