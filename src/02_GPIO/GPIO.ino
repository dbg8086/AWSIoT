void setup(void)
{
	pinMode(23, OUTPUT);
	pinMode(22, OUTPUT);
	pinMode(21, OUTPUT);
	
	digitalWrite(23, LOW);
	digitalWrite(22, LOW);
	digitalWrite(21, LOW);
}



void loop(void)
{
	digitalWrite(23, LOW);
	delay(1000);
	digitalWrite(23, HIGH);
	delay(1000);

	digitalWrite(22, LOW);
	delay(1000);
	digitalWrite(22, HIGH);
	delay(1000);
	
	digitalWrite(21, LOW);
	delay(1000);
	digitalWrite(21, HIGH);
	delay(1000);
}
