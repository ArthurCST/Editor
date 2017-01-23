#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>

#include "conioreal.h"
#include "SetLinhas.h"

//	<SETA>
	void moveUP();
	void moveDOWN(int nlin);
	void moveLEFT();
	void moveRIGHT(char *texto);
//	</SETA>

	void backspace(char *texto);


	void ENTER(char *texto, int nlin, int i);
	
	
	void END_FECHAR();
	

	void F1_ABRIR();
	void F2_SALVAR(char *texto);
	void F3_COMPILAR(char *nomeDoArquivo);
	void F4_EXECUTA(char *nomeDoArquivo);