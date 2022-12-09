#include <SPI.h>

// VSPI_MOSI 23
// VSPI_MISO 19
// VSPI_CLK 18
// VSPI_CS0 5
#define SPICS_PIN 5

#define RDSR 5
#define WRSR 1
#define READ 3
#define WRITE 2

SPIClass *g_spi = NULL;



uint8_t SpiRAMRead8(uint16_t address)
{
	uint8_t read_byte;

	g_spi->beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
	digitalWrite(SPICS_PIN, LOW);
	
	g_spi->transfer(READ);	
	g_spi->transfer((char)(address >> 8));
	g_spi->transfer((char)address);
	read_byte = g_spi->transfer(0xFF);
	
	digitalWrite(SPICS_PIN, HIGH);
	g_spi->endTransaction();
	
	return read_byte;
	
}



void SpiRAMWrite8(uint16_t address, uint8_t data_byte)
{
	g_spi->beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
	digitalWrite(SPICS_PIN, LOW);
	
	g_spi->transfer(WRITE); 
	g_spi->transfer((char)(address >> 8));
	g_spi->transfer((char)address);
	g_spi->transfer(data_byte);
	
	digitalWrite(SPICS_PIN, HIGH);
	g_spi->endTransaction();
}

void setup(void)
{
	g_spi = new SPIClass(VSPI);
	g_spi->begin();

	pinMode(SPICS_PIN, OUTPUT);

	Serial.begin(38400);
}

void loop()
{
	uint16_t addr;
	uint8_t i;
	
	
	
	for (addr = 0; addr <= 255; addr++)
	{
		SpiRAMWrite8(addr, (uint8_t)addr);
		Serial.print("Addr: ");
		Serial.println((uint16_t)addr);
	}
	
	for (addr = 0; addr <= 255; addr++)
	{
		i = SpiRAMRead8(addr);
		Serial.print("Read: ");
		Serial.println((uint16_t)i);
	}
	delay(5000);
}
