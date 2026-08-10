#include "../Inc/1602a.h"

void LCD_Init()
{
	HAL_Delay(50); // 15ms is the minimum required
	prepareMessage();
	GPIOA->BSRR = (1 << D5)|(1 << D4);
	sendMessage();
	HAL_Delay(5); // 4,1ms is the minimum required

	prepareMessage();
	GPIOA->BSRR = (1 << D5)|(1 << D4);
	sendMessage();
	HAL_Delay(1); // 100us is the minimum required

	prepareMessage();
	GPIOA->BSRR = (1 << D5)|(1 << D4);
	sendMessage();

	prepareMessage();
	GPIOA->BSRR = (1 << D5)|(1 << D4)|(1 << D3);
	sendMessage();

	prepareMessage();
	GPIOA->BSRR = (1 << D3);
	sendMessage();

	prepareMessage();
	GPIOA->BSRR = (1 << D0);
	sendMessage();

	prepareMessage();
	GPIOA->BSRR = (1 << D3)|(1 << D2)|(1 << D1)|(1 << D0);
	sendMessage();
	HAL_Delay(1000);

	prepareMessage();
	GPIOA->BSRR = (1 << D2);
	sendMessage();

	prepareMessage();
	GPIOA->BSRR = (1 << D0);
	sendMessage();
}

void setPosition(uint8_t row, uint8_t column)
{
	prepareMessage();
	GPIOA->BSRR = (1 << D7);
	if (row == 1)
	{
		GPIOA->BSRR = (1 << D6);
	}
	if (column == 2 || column == 4 || column == 6 || column == 8 || column == 10 || column == 12 || column == 14 || column == 16)
	{
		GPIOA->BSRR = (1 << D0);
	}
	if (column == 3 || column == 4 || column == 7 || column == 8 || column == 11 || column == 12 || column == 15 || column == 16)
	{
		GPIOA->BSRR = (1 << D1);
	}
	if (column == 5 || column == 6 || column == 7 || column == 8 || column == 13 || column == 14 || column == 15 || column == 16)
	{
		GPIOA->BSRR = (1 << D2);
	}
	if (column == 9 || column == 10 || column == 11 || column == 12 || column == 13 || column == 14 || column == 15 || column == 16)
	{
		GPIOA->BSRR = (1 << D3);
	}
	sendMessage();
}

void prepareMessage()
{
	GPIOA->BSRR = (1 << (PIN_RS + 16))|(1 << (PIN_RW + 16))|(1 << (D7 + 16))
				 |(1 << (D6 + 16))|(1 << (D5 + 16))|(1 << (D4 + 16))
				 |(1 << (D3 + 16))|(1 << (D2 + 16))|(1 << (D1+ 16))
				 |(1 << (D0 + 16));
}

void sendMessage()
{
	HAL_Delay(1);
	GPIOA->BSRR = (1 << PIN_E);
	HAL_Delay(1);
	GPIOA->BSRR = (1 << (PIN_E + 16));
	HAL_Delay(1);
}

void writeNumber(uint8_t number)
{
	prepareMessage();
	GPIOA->BSRR = (1 << PIN_RS)|(1 << D5)|(1 << D4);
	if (number == 1 || number == 3 || number == 5 || number == 7 || number == 9)
	{
		GPIOA->BSRR = (1 << D0);
	}
	if (number == 2 || number == 3 || number == 6 || number == 7)
	{
		GPIOA->BSRR = (1 << D1);
	}
	if (number == 4 || number == 5 || number == 6 || number == 7)
	{
		GPIOA->BSRR = (1 << D2);
	}
	if (number == 8 || number == 9)
	{
		GPIOA->BSRR = (1 << D3);
	}
	sendMessage();
}

void writeCharacter (char character)
{
	prepareMessage();
	GPIOA->BSRR = (1 << PIN_RS);
	if (character == 'A' || character == 'B' || character == 'C' || character == 'D' || character == 'E' || character == 'F' || character == 'G'
	 || character == 'H' || character == 'I' || character == 'J' || character == 'K' || character == 'L' || character == 'M' || character == 'N' || character == 'O')
	{
		GPIOA->BSRR = (1 << D6);
	}
	if (character == 'P' || character == 'Q' || character == 'R' || character == 'S' || character == 'T' || character == 'U' || character == 'V'
		 || character == 'W' || character == 'X' || character == 'Y' || character == 'Z')
	{
		GPIOA->BSRR = (1 << D6)|(1 << D4);
	}
	if (character == ':')
	{
		GPIOA->BSRR = (1 << D5)|(1 << D4);
	}
	if (character == '-')
	{
		GPIOA->BSRR = (1 << D5);
	}
	if (character == ' ')
	{
		GPIOA->BSRR = (1 << D5);
	}
	if (character == 'A' || character == 'C' || character == 'E' || character == 'G' || character == 'I' || character == 'K' || character == 'M'
	 || character == 'O' || character == 'Q' || character == 'S' || character == 'U' || character == 'W' || character == 'Y' || character == '-')
	{
		GPIOA->BSRR = (1 << D0);
	}
	if (character == 'B' || character == 'C' || character == 'F' || character == 'G' || character == 'J' || character == 'K' || character == 'N'
	 || character == 'O' || character == 'R' || character == 'S' || character == 'V' || character == 'W' || character == 'Z' || character == ':')
	{
		GPIOA->BSRR = (1 << D1);
	}
	if (character == 'D' || character == 'E' || character == 'F' || character == 'G' || character == 'L' || character == 'M' || character == 'N'
	 || character == 'O' || character == 'T' || character == 'U' || character == 'V' || character == 'W' || character == '-')
	{
		GPIOA->BSRR = (1 << D2);
	}
	if (character == 'H' || character == 'I' || character == 'J' || character == 'K' || character == 'L' || character == 'M' || character == 'N'
	 || character == 'O' || character == 'X' || character == 'Y' || character == 'Z' || character == ':' || character == '-')
	{
		GPIOA->BSRR = (1 << D3);
	}
	sendMessage();
}

void writeWord(char word[])
{
	int i;
	for (i = 0; i < strlen(word); i++)
	{
		writeCharacter(word[i]);
	}
}

void sendCommand(char command)
{
	prepareMessage();
	if (command == CLEAR)
	{
		GPIOA->BSRR = (1 << D0);
	}
	else if (command == HOME)
	{
		GPIOA->BSRR = (1 << D1);
	}
	sendMessage();
}
