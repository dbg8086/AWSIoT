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

> Input only pins   

GPIO 34   
GPIO 35   
GPIO 36   
GPIO 39   

> SPI 내부 플래시 메모리   

GPIO 6 ~ GPIO 11 까지 핀은 내부 SPI 플래시 메모리에 연결되어 있다. 이 핀들은 사용하지 않도록 한다.   

GPIO 6 (SCK/CLK)   
GPIO 7 (SDO/SD0)   
GPIO 8 (SDI/SD1)   
GPIO 9 (SHD/SD2)   
GPIO 10 (SWP/SD3)   
GPIO 11 (CSC/CMD)   

> 시리얼 통신   

[source](../src/02_SERIAL/SERIAL.ino)   

> ADC   

ADC2 핀은 Wi-Fi가 사용될 때 사용될 수 없다.    

ADC1_CH0 (GPIO 36)   
ADC1_CH1 (GPIO 37)   
ADC1_CH2 (GPIO 38)   
ADC1_CH3 (GPIO 39)   
ADC1_CH4 (GPIO 32)   
ADC1_CH5 (GPIO 33)   
ADC1_CH6 (GPIO 34)   
ADC1_CH7 (GPIO 35)   
ADC2_CH0 (GPIO 4)   
ADC2_CH1 (GPIO 0)   
ADC2_CH2 (GPIO 2)   
ADC2_CH3 (GPIO 15)   
ADC2_CH4 (GPIO 13)   
ADC2_CH5 (GPIO 12)   
ADC2_CH6 (GPIO 14)   
ADC2_CH7 (GPIO 27)   
ADC2_CH8 (GPIO 25)   
ADC2_CH9 (GPIO 26)   

[source](../src/03_ANALOG/ANALOG.ino)   

> PWM   

ESP32 LED PWM 컨트롤러는 16개의 독립적인 채널이 있다. 이 16개의 채널은 PWM 신호를 생성하기 위해 다른 속성으로 설정할 수 있다. GPIO 34 ~ 39를 제외하고 모든 핀은 PWM 핀으로 사용될 수 있다.   

[source](../src/04_PWM/PWM.ino)   

> I2C   

ESP32는 두 개의 I2C 채널이 있고 어떤 핀이든 SDA 혹은 SCL 으로 설정할 수 있다. 디폴트 I2C 핀은 다음과 같다.   

GPIO 21 (SDA)   
GPIO 22 (SCL)   


[source](../src/05_I2C/SCAN/SCAN.ino)   

> VSPI   

GPIO 23   
GPIO 19   
GPIO 18   
GPIO 5   

[source](../src/06_SPI/SPI.ino)   

> INTERRUPT   

모든 GPIO는 인터럽트로 설정될 수 있다. 아두이노에서는 다음 함수로 인터럽트를 설정한다.   

```
attachInterrupt(digitalPinToInterrupt(GPIO), function, mode);
- digitalPinToInterrupt(GPIO) : 해당 GPIO 핀을 인터럽트 핀으로 설정한다.
- function : 인러럽트 처리 함수
- mode : LOW, HIGH, CHANGE, FALLING, RISING
```
[source](../src/07_INTERRUPT/INTERRUPT.ino)   
