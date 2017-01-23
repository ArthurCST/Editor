#include "SetLinhas.h"

void gera_lista()
{
	struct _LINE_LIST_ *aux;
	aux = (struct _LINE_LIST_*)malloc(sizeof(struct _LINE_LIST_)); 
	inicio = aux;
	fim = inicio;
	
}

void escreve(char *texto)
{
	struct _LINE_LIST_ *aux;
	aux = (struct _LINE_LIST_*)malloc(sizeof(struct _LINE_LIST_));
	
	aux->linha = malloc(TAM_LINHA * sizeof(char));
	int i;

	for(i=0; i<strlen(texto); i++)
	{
		aux->linha[i] = texto[i];
	}

	fim->prox = aux;
	fim = fim->prox;
	aux->prox = NULL;
}


void remove_char(char *texto, int posicao_x)
{	
		int i;
		int len = strlen(texto);
		for(i = posicao_x; i < len; i++){
			if(texto[i+1] == '\0' || texto[i+1]=="")
			{
				printf(" ");
			}else
			{
				printf("%c", texto[i+1]);
			}

			texto[i] = texto[i + 1];
			
		}
} // remove_char
