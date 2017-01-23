#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>
#include "conioreal.h"
#include "SetLinhas.h"


int main()
{
	initconio();
	keypad(stdscr, true);
		gera_lista();		
		
		char *linha, c;
		linha = (char*) malloc(TAM_LINHA * sizeof(char));
		int unsigned caractere,i=0, nlin=1;
		while (true)
		{	
			caractere = getch();
			switch(caractere)
			{
//			<SETAS>
				case KEY_DOWN:
					if((wherey()+1) < nlin){
						gotoxy(wherex(), wherey()+1);
					}
				break;
				case KEY_UP:
					if((wherey()-1) > 0){
						gotoxy(wherex(), wherey()-1);
					}
				break;
				case KEY_LEFT:
					if(((wherex()-1) > 0) ){
						gotoxy(wherex()-1, wherey());
					}else if((wherey()-1) > 0){
						gotoxy(wherex(), wherey()-1);
					}
				break;
				case KEY_RIGHT:
					if((wherex()+1) < strlen(linha)){
						gotoxy(wherex()+1, wherey());
					}else{
						newline();
					}
				break;			
//			</SETAS>
//  		<BACKSPACE>			
				case KEY_BACKSPACE:
					remove_char(linha, wherex());
					if(((wherex()-1) > 0) ){
						gotoxy(wherex()-1, wherey());
					}else if((wherey()-1) > 0){
						gotoxy(wherex(), wherey()-1);
					}
				break;
//			</BACKSPACE>

//			<TAB>
			case '\t':
				
			break;
//			</TAB>

//			<ENTER>
				case '\n':
					escreve(linha);
					strcpy(linha, "" );
					i=0;
					nlin=nlin+1;
					newline();
				break;
//			</ENTER>

//			<END>
				case KEY_END:
					exit(0);
				break;
//			</END>

/*			<F1>//ABRIR
				case KEY_F1:
					
				break;
//			</F1>

//			<F2>//SALVA
				case KEY_F2:
					
				break;
//			</F2>

//			<F3>//COMPILA
				case KEY_F3:
					
				break;
//			</F3>*/				

				default:
					c = (char) caractere;
					printw("%c", c);
					linha[i] = c;
					i++;
					
			}
	
		}




	endconio();
	return 0;
}



































/*





int main()
{
	
	initscr(); // Inicia tela
	keypad(stdscr, true); // Habilita teclado
	erase(); // Preenche a tela de espaços em branco
	refresh();

	gera_lista();

	char *linha, c;
	linha = (char*) malloc(TAM_LINHA * sizeof(char));
	int unsigned caractere,i=0, x, y;
	//char palavra_reservada[10]; 
	while (true)
	{	
		getyx(stdscr, y, x);
		caractere = getch();
		switch(caractere)
		{
//			<SETAS>
			case KEY_DOWN:

			break;
			case KEY_UP:
			
			break;
			case KEY_LEFT:
			
			break;
			case KEY_RIGHT:
			
			break;			
//			</SETAS>

			<BACKSPACE>			
			case KEY_DC:
				
			break;
//			</BACKSPACE>

//			<ENTER>
			case '\n':
				linha[i] = '\0';
				i=0;
				puts(linha);

				escreve(linha);
				move(0, x+1);
				getyx(stdscr, y, x);
				free(linha);
				linha = (char*) malloc(TAM_LINHA * sizeof(char));
			break;
//			</ENTER>

//			<TAB>
			case '\t':
				strcat(linha, "    ");
			break;
//			</TAB>

//			<ESC>
			case 27:
				exit(0);
			break;
//			</ESC>

			default:
				if(isprint(caractere))
				{	
					c = (char)caractere;
					linha[i] = c;
					i++;
				}else{
					printw("\a");
				}
		}
	
	}
	erase();
	refresh();
	endwin();
return 0;

}*/