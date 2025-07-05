//reference: https://dienthongminhesmart.com/lap-trinh-esp8266/giao-tiep-uart-esp8266/

#include <SoftwareSerial.h>
// Khai báo các chân RX và TX cho espsoftwareserial
#define RX_PIN 4 // D2
#define TX_PIN 5 // D1

// Tạo một đối tượng espsoftwareserial với tốc độ baud là 9600
SoftwareSerial mySerial(RX_PIN, TX_PIN);

void setup() {
  // Khởi tạo cổng nối tiếp phần cứng với tốc độ baud là 115200
  Serial.begin(115200);

  // Khởi tạo cổng nối tiếp phần mềm với tốc độ baud là 9600
  mySerial.begin(9600);

  // In ra thông báo khởi động
  //Serial.println("ESP8266 UART Communication Example");

  pinMode(LED_BUILTIN, OUTPUT); // Đặt chân kết nối với led là chân đầu ra
}

void loop() {
  /*
  // Nếu có dữ liệu từ cổng nối tiếp cứng, gửi nó sang cổng nối tiếp mềm
  if (Serial.available()) {
    char c = Serial.read();
    mySerial.write(c);
  }

  // Nếu có dữ liệu từ cổng nối tiếp mềm, gửi nó sang cổng nối tiếp cứng
  if (mySerial.available()) {
    char c = mySerial.read();
    Serial.write(c);
  }
  */
  if (mySerial.available()) { // Nếu có dữ liệu từ cổng nối tiếp mềm
    char c = mySerial.read(); // Đọc ký tự điều khiển
    mySerial.println(c); // In ra ký tự điều khiển qua cổng nối tiếp mềm
    Serial.println(c); // In ra ký tự điều khiển qua cổng nối tiếp cứng
    if (c == '1') { // Nếu ký tự là '0'
      // Bật led
      digitalWrite(LED_BUILTIN, LOW); //ve mass ~ pull down
      Serial.println("LED is on"); // In trạng thái led qua cổng nối tiếp cứng
    }
    else if (c == '0') { // Nếu ký tự là 'f'
      // Tắt led
      digitalWrite(LED_BUILTIN, HIGH); //ngung ve mass ~ pull up
      Serial.println("LED is off "); // In trạng thái led qua cổng nối tiếp cứng
    }
    else { // Nếu ký tự khác
      // Không làm gì
      Serial.println("Invalid command"); // In báo lỗi qua cổng nối tiếp cứng
    }
  }
}
