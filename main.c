/*
 * main.c
 *
 *  Created on: Nov 25, 2011
 *      Author: Doug
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "tests/simm_electrical_test.h"
#include "usb_serial/usb_serial.h"

int main(void)
{
	cli();

	DDRD |= (1 << 7);
	PORTD &= ~(1 << 7);

	USBSerial_Init();
	sei();

	while (1)
	{
		USBSerial_Check();
	}

	/*int result = SIMMElectricalTest_Run();

	if (result == 0)
	{
		while (1)
		{
			_delay_ms(200);
			PIND = (1 << 7);
		}
	}
	else
	{
		while (1)
		{
			int tmpResult = result;

			while (tmpResult)
			{
				int thisDigit = (tmpResult % 10) + 1;

				while (thisDigit--)
				{
					PIND = (1 << 7);
					_delay_ms(500);
					PIND = (1 << 7);
					_delay_ms(500);
				}

				_delay_ms(2000);

				tmpResult /= 10;
			}

			_delay_ms(5000);
		}
	}*/

	return 0;
}
