# 1602a_LCD_display
This repository implements some functions to operate the 1602a LCD Display.

<details open>

<summary><h3 style="display: inline;">Introduction<h3></summary>

This repository contains useful functions to make a 1602a LCD display work. The list of implemented functions can be found in the section _Implemented Functions_.  
  
Notice that the code is implemented to be used with an STM32 Nucleo-64 F411RE, as there exists some macros regarding the pins being used to control the LCD display. For that reason, this repository might be useful for that specific board and similar ones.  
  
<details open>

<summary><h3 style="display: inline;">Implemented Functions<h3></summary>

The repository includes the following principal functions:

- LCD_Init ( ): executes the initialization process that the 1602a LCD display requires.
- setPosition ( row , column ): locates the cursor in the position defined by _row_ and _column_ inputs.
- writeNumber ( number ): writes a number between '0' and '9' into the current cursor position.
- writeCharacter ( character ): writes a character from 'A' to 'Z', common symbols like ':' and '-', or a blank space in the current cursor position.
- writeWord ( word ): writes a word, which can contain the previous characters and numbers, starting in the current cursor position.
- sendCommand ( command ): if 'command' is 'CLEAR', the content of the LCD display is erased. if 'command' is 'HOME', the cursor goes to the top left cell of the display.

It also includes secondary functions that are used to make the principal functions work:

- prepareMessage ( ): puts to LOW state all the board pins that are used to communicate with the LCD display. Therefore, all pins are ready to be set in HIGH state if the next command/message requires it. This function is called before preparing a command/message that is wanted to be sent.
- sendMessage ( ): executes the sequence that tells the LCD display to read the command/message that is being sent.