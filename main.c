#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>

#include "conioreal.h"
#include "SetLinhas.h"
#include "SetTeclado.h"


int main()
{
	// Inicia janela
	initconio();

	//Habilita Teclado
	keypad(stdscr, true);

		//Gera uma lista encadeada para a gravacao das linhas
		gera_lista(); 										
		
		//String da que recebe os valores digitados difererentes de comandos especiais
		char *linha; 
		
		//Variavel auxiliar para casting dos valores inteiros para caractere										
		char c;

		//Aloca string para salvar na lista 											
		linha = (char*) malloc(TAM_LINHA * sizeof(char)); 
		
		//Valor decimal da tecla digitada	
		int unsigned caractere; 	

		//Indice da posicao de gravacao de caractere na string linha						
		int unsigned i=0; 
		
		//Total de linhas escritas 									 
		int unsigned nlin=1;

		//Status do programa 
		bool rodando = true;

		//provisorio
		char *nomeDoArquivo;

		while (rodando)
		{	
			// Obtem digitado sem imprimir na tela
			caractere = getch();

			switch(caractere)
			{
//			<SETAS>
				//DESCE
				case KEY_DOWN: 
					moveDOWN(nlin);
				break;
				// SOBE
				case KEY_UP: 
					moveUP();
				break;
				// ESQUERDA
				case KEY_LEFT: 
					moveLEFT();
				break; 
				// DIREITA
				case KEY_RIGHT: 
					moveRIGHT(linha);
				break;			
//			</SETAS>

//  		<BACKSPACE>	APAGAR UM CARACTERE		
				case KEY_BACKSPACE:
					backspace(linha);
				break;
//			</BACKSPACE>

//			<ENTER>	DESCER UMA LINHA
				case '\n':
					ENTER(linha, nlin, i);
				break;
//			</ENTER>

//			<END> FECHAR
				case KEY_END:
					END_FECHAR();
				break;
//			</END>

//			<F1> ABRIR
				case 112:
					F1_ABRIR();
				break;
//			</F1>
//			<F2> SALVAR
				case 113:
					F2_SALVAR();
				break;
//			</F2>
//			<F3> COMPILAR
				case 114:
					F3_COMPILAR(nomeDoArquivo);
				break;
//			</F3>

//			<F3> EXECUTA
				case 115:
					F4_EXECUTAR(nomeDoArquivo);
				break;
//			</F3>

//			<TAB>
				case '\t':
				
				break;
//			</TAB>

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