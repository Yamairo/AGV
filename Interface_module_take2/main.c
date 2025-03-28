#ifndef F_CPU
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <util/delay.h>

// Aansluitingen:
// 8: SDI	-> PH5
// 7: SFTCLK	-> PH4
// 4: LCHCLK	-> PG5
#define SDI_BIT		PH5
#define DDR_SDI		DDRH
#define PORT_SDI	PORTH

#define SFTCLK_BIT	PH4
#define DDR_SFTCLK	DDRH
#define PORT_SFTCLK	PORTH

#define LCHCLK_BIT	PG5
#define DDR_LCHCLK	DDRG
#define PORT_LCHCLK	PORTG

static unsigned int segmentcodes[] = {
 0x03,    0x9F,     0x25,     0x0D,         //4
 0x99,    0x49,     0x41,     0x1F,         //8
 0x01,    0x09,     0x11,     0x01,         //TOT 10 GETELD VANAF 11 LETTERS OP ALFABET // A, B//12
 0x63,    0x03,     0x61,     0x71,         //16 //C,D,E,F
 0x91,    0x9F,     0xE3,     0xC5,         //20 //H,I,L,O
 0x31,    0x49,     0xE1,     0x83,         //24 //P,S,t,U
 0x25,    0xFD,     0x1D,     0x10,         //28 -,=,_
};

void init (void)
{
	// Initialiseer de pinnen voor datain, shiftclk en latchclk als output
	DDR_SDI    |= (1 << SDI_BIT);
	DDR_SFTCLK |= (1 << SFTCLK_BIT);
	DDR_LCHCLK |= (1 << LCHCLK_BIT);

	// Maak shiftclk en latchclk laag
	PORT_SFTCLK &= ~(1 << SFTCLK_BIT);
	PORT_LCHCLK &= ~(1 << LCHCLK_BIT);
}

void send_data(char data)
{
	for (unsigned i = 0; i < 8; i++)
	// Herhaal voor alle bits in een char
	{
		// Bepaal de waarde van de bit die je naar het schuifregister
		// wil sturen
		int bit = data & 1;
		data >>= 1;

		// Maak de juiste pin hoog of laag op basis van de bepaalde waarde
		// van het bit
		if (bit)
		{
			PORT_SDI |= (1 << SDI_BIT);
		}
		else
		{
			PORT_SDI &= ~(1 << SDI_BIT);
		}

		// Toggle shiftclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
		// Puls moet minimaal 13 ns hoog zijn. Een clk cycle op de Arduino duurt
		// 62 ns, dus signaal kan hoog en de volgende cycle weer omlaag
		PORT_SFTCLK |= (1 << SFTCLK_BIT);
		PORT_SFTCLK &= ~(1 << SFTCLK_BIT);
	}
}

void send_enable(int display_nummer)
{
	send_data(0x10 << display_nummer);
}

void display(char data, int display_nummer)
{
	send_data(data);
	send_enable(display_nummer);

	// Toggle latchclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
	// Puls moet minimaal 13 ns hoog zijn. Een clk cycle op de Arduino duurt
	// 62 ns, dus signaal kan hoog en de volgende cycle weer omlaag
	PORT_LCHCLK |= (1 << LCHCLK_BIT);
	PORT_LCHCLK &= ~(1 << LCHCLK_BIT);
}

void display_getal(unsigned int getal)
{
	for (int i = 0; i < 4; i++)
	{
		display(segmentcodes[getal%10], i);
		getal /= 10;
		_delay_ms(1);   // 1 kHz
	}
	display(0xFF,0);
}

int main(void)
{
    init();
    int getal=99;
    int buttonpin=0;
    int teller=0;
    while(1)
    {
        display_getal(getal+teller*100);

        if((PINF &(1<<PF1))==0)
        {
            _delay_ms(20);
             if((PINF &(1<<PF1))==0)
                {
                    if(!buttonpin)
                {

                    teller++;
                    buttonpin=1;
                    _delay_ms(20);
                }
                }

        }
        else
        {_delay_ms(20);
        if((PINF &(1<<PF1))!=0)
           {
             buttonpin=0;
           }
    }
    }
}

/*int main(void)
{
	init();
    int cijfer0=9;
    int cijfer1=9;
    int cijfer2=0;
	int cijfer3=18;

	while (1)
	{
		display(segmentcodes[cijfer0], 0);
		_delay_ms(1);
		display(segmentcodes[cijfer1], 1);
		_delay_ms(1);
		display(segmentcodes[cijfer2], 2);
		_delay_ms(1);
		display(segmentcodes[cijfer3], 3);
        _delay_ms(1);



	}

}
*/
