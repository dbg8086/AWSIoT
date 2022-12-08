#include <Wire.h>
 
void setup()
{
	Wire.begin();
	Serial.begin(38400);
	Serial.println("I2C Scanner");
}
 
void loop()
{
	unsigned char u8Error = 0;
	unsigned char u8Address = 0;
	int nDevices;
	
	Serial.println("Scanning...");
	
	nDevices = 0;
	
	for (u8Address = 1; u8Address < 127; u8Address++)
	{
		Wire.beginTransmission(u8Address);
		u8Error = Wire.endTransmission();
		if (u8Error == 0)
		{
			Serial.print("I2C device found at u8Address 0x");
			if( u8Address < 16 )
			{
				Serial.print("0");
			}
			Serial.println(u8Address, HEX);
			nDevices++;
		}
		else if( u8Error == 4 )
		{
			Serial.print("Unknow u8Error at u8Address 0x");
			if ( u8Address < 16 )
			{
				Serial.print("0");
			}
			Serial.println(u8Address, HEX);
		}		
	}
	if (nDevices == 0)
	{
		Serial.println("No I2C devices found\n");
	}
	else
	{
		Serial.println("done\n");
	}
	delay(5000);					
}
