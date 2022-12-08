const int LED_PIN = 2;

const int g_nLedChannel = 0;
 
void setup()
{
	int nFreq = 5000;
	int nResolution = 8;
	
	ledcSetup(g_nLedChannel, nFreq, nResolution);
  
	ledcAttachPin(LED_PIN, g_nLedChannel);
}



void loop(void)
{
	int nDutyCycle = 0;
	
	for(nDutyCycle = 0; nDutyCycle <= 255; nDutyCycle++)
	{   
		ledcWrite(g_nLedChannel, nDutyCycle);
		delay(15);
	}

	for(nDutyCycle = 255; nDutyCycle >= 0; nDutyCycle--)
	{
		ledcWrite(g_nLedChannel, nDutyCycle);   
		delay(15);
	}
}