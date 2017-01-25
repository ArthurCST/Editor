#include <stdlib.h>

#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


//	<SETA>
	void moveUP(); //sobe
	void moveDOWN(int nlin); //desce
	void moveLEFT(); //mover para a esquerda
	void moveRIGHT(int *linha); //mover para a direita
//	</SETA>

	void END_FECHAR(); //tecla END para finalizar o programa 
