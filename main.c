#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include "conioreal.h"
#include "SetLinhas.h"
#include "SetTeclado.h"


int main()
{
	// Inicia janela
	initconio();
	FILE *arq;
	//Habilita Teclado
	keypad(stdscr, true);

		//Gera uma lista encadeada para a gravacao das linhas
		LISTA *lista = gerar_lista();								
		
		//String da que recebe os valores digitados difererentes de comandos especiais
		int *linha; 
		
		//Variavel auxiliar para casting dos valores inteiros para caractere										
		char c, *nomeDoArquivo, che;

		int lin, tamanho_da_linha = 0;

		//Aloca string para salvar na lista 											
		linha = (int*) malloc(1000 * sizeof(int));
		for (lin = 0; lin < 1000; ++lin)
		{
			linha[lin] = 0;
		}
		
		//Valor decimal da tecla digitada	
		int unsigned caractere; 	
					
		
		//Total de linhas escritas 									 
		int unsigned nlin=1;

		while (true)
		{	
			DATA dado;
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
					moveLEFT();
					remover_letra(lista, linha);
				break;
//			</BACKSPACE>

//			<ENTER>	DESCER UMA LINHA
				case '\n':
					escreve(lista, dado, linha, nlin,'\n');
					linha[wherey()] = tamanho_da_linha;
					newline();
					nlin++;
					tamanho_da_linha = 0;
				break;
//			</ENTER>

//			<END>
				case KEY_END:
					END_FECHAR();
				break;
//			</END>

//			<F1> ABRIR
				case KEY_F(1):
					
					printw("Digite o nome do arquivo: ");
					scanw("%s", nomeDoArquivo);//lê nome do arquivo
					arq = fopen(nomeDoArquivo, "r");
					if(arq == NULL)
	    				printw("Erro, nao foi possivel abrir o arquivo\n");
					else{
						while( (che=fgetc(arq))!= EOF ){
							
							dado.letra = che;
							NODE *noh = (NODE*) malloc(sizeof(NODE));
							noh->dado = dado;
							noh->prox = NULL;
							NODE *ultimo = lista->head;
							while(ultimo->prox != NULL)
							{
								ultimo = ultimo->prox;
							}
							ultimo->prox = noh;
							lista->tam++;
						}
					}
					imprimir_lista(lista);
				break;
//			</F1>

//			<F2> SALVAR
				case KEY_F(2):
				
				arq = fopen("test.c", "w+");
				char ch;
				NODE *ponteiro = lista->head;

				while(ponteiro != NULL)
				{	
					ch = ponteiro->dado.letra;
					fprintf(arq, "%c", ch);
					ponteiro = ponteiro->prox;
				}
				fclose(arq);
					
				break;
//			</F2>

//			<F3> COMPILAR E EXECUTAR
				case KEY_F(3):
					clear();
					printw("Digite o nome do arquivo. - sem a extensao -");

					scanw("%s", nomeDoArquivo);
					char *comando = "gcc ";
					char *str2 = ".c -o ";
					char *str3 = " && ./";
					strcat(comando, nomeDoArquivo);
					strcat(comando, str2);
					strcat(comando, nomeDoArquivo);
					strcat(comando, str3);
					strcat(comando, nomeDoArquivo);
					system(comando);

				break;
//			</F3>		

				default:
					linha[wherey()] = tamanho_da_linha;
					c = (char) caractere;
					escreve(lista, dado, linha, nlin, c);
					tamanho_da_linha++;	
					printw("%c",c);
								
			}
			
	
		}
	endconio();
	return 0;
}
