#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>  

#define TAM_LINHA 200

typedef struct _LINE_LIST_ LINHA;

struct _LINE_LIST_ 
{
	char *linha;
	struct _LINE_LIST_ *prox;		
};
struct _LINE_LIST_ *inicio;
struct _LINE_LIST_ *fim;

void gera_lista();

void escreve(char *texto);

void remove_char(char *texto, int posicao_x);

