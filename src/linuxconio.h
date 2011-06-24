//============================================================================
// Name        : linuxconio.h
// Author      : Ankgi Sukarmana (soekarmana@gmail.com)
// Version     : 0.0.1
// License     : GPL
// Description : Pengganti fungsi2 conio.h yang sering digunakan
//============================================================================

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

void clrscr(){
	system("clear");
}

//fungsi getch() di linux
//sumber : http://www.dreamincode.net/code/snippet5395.htm
//unknown bug : function must be called 2x

int lingetch(void) {
  struct termios oldt, newt;
  int ch;

  /* We can't necessarily trust POSIX's STDIN_FILENO */
  int stdin_fd = fileno(stdin);

  /* Get and save the current terminal flags */
  tcgetattr(stdin_fd, &oldt);

  /* Copy the old settings and turn off echo/canonical mode */
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);

  /* Apply the new settings */
  tcsetattr(stdin_fd, TCSANOW, &newt);

  /* Call the standard getchar() function */
  ch = getchar();

  /* Restore the original settings */
  tcsetattr(stdin_fd, TCSANOW, &oldt);

  return ch;
}

void getch(){
	lingetch();
	lingetch();
}

//fungsi gotoxy di linux
//sumber :

int gotoxy(int x, int y) {
	char essq[100];		// String variable to hold the escape sequence
	char xstr[100];		// Strings to hold the x and y coordinates
	char ystr[100];		// Escape sequences must be built with characters

	/*
	** Convert the screen coordinates to strings
	*/
	sprintf(xstr, "%d", x);
	sprintf(ystr, "%d", y);

	/*
	** Build the escape sequence (vertical move)
	*/
	essq[0] = '\0';
	strcat(essq, "\033[");
	strcat(essq, ystr);

	/*
	** Described in man terminfo as vpa=\E[%p1%dd
	** Vertical position absolute
	*/
	strcat(essq, "d");

	/*
	** Horizontal move
	** Horizontal position absolute
	*/
	strcat(essq, "\033[");
	strcat(essq, xstr);
	// Described in man terminfo as hpa=\E[%p1%dG
	strcat(essq, "G");

	/*
	** Execute the escape sequence
	** This will move the cursor to x, y
	*/
	printf("%s", essq);

	return 0;
}

