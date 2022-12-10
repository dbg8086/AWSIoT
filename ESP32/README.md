## ESP32   

> 설치   

메뉴에서 File → Preference를 실행하고 Additional Boards Manager URLs 항목에 다음을 추가한다.   
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json   

![arduino json](../images/01_json.png)

메뉴에서 Tools → Board → Board Manager 를 실행하고 esp32 를 설치한다.   

![board manager](../images/02_boardmanager.png)    

메뉴에서 Tools → Board → ESP32 Arduino → ESP32 Dev Module 을 선택한다.   

![board](../images/03_board.png)   

메뉴에서 Tools → Port 에서 ESP32 보드의 포트를 선택한다. 그리고 다음 예제를 업로드한다.   

```   
int LED_BUILTIN = 2;

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1000);
	digitalWrite(LED_BUILTIN, LOW);
	delay(1000);
}
```   

> 핀맵   

[pinmap](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?w=750&quality=100&strip=all&ssl=1) (Link)  

> 시리얼 통신   

[source](../src/02_SERIAL/SERIAL.ino)   

> ADC   

[source](../src/03_ANALOG/ANALOG.ino)   

> PWM   

[source](../src/04_PWM/PWM.ino)   

> I2C   

[source](../src/05_I2C/SCAN/SCAN.ino)   

> SPI   

[source](../src/06_SPI/SPI.ino)   

> INTERRUPT   

[source](../src/07_INTERRUPT/INTERRUPT.ino)   
