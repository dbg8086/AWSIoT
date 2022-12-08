const int ANALOG_PIN = 34;



void setup()
{
	Serial.begin(38400);
	delay(1000);
}

void loop()
{
	int nAnalog = 0;
	
	
	
	nAnalog = analogRead(ANALOG_PIN);
	
	Serial.println(nAnalog);
	
	delay(500);
}
