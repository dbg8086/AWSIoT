void setup(void)
{
	Serial.begin(38400);
}



void loop(void)
{
	static unsigned char u8Count = 0;
	
	
	
	Serial.println(u8Count);
	
	u8Count = u8Count + 1;
	
	delay(100);
}
