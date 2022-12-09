const int INTERRUPT_PIN = 27;



unsigned char g_u8Data = 0;



void IRAM_ATTR InterruptFunction(void)
{
  g_u8Data = 1;
}

void setup(void)
{
	Serial.begin(38400);
	
	pinMode(INTERRUPT_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), InterruptFunction, FALLING);
}

void loop(void)
{
  if( g_u8Data )
  {
    Serial.println(".");
    g_u8Data = 0;
  }
}
