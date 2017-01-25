#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "conioreal.h" 

typedef struct _NODE_DATA_		//Estrutura q armazena o tipo de dado
{								  
	char letra; //tipo de dado
} DATA;

typedef struct _NODE_LIST_     //Estrutura armazenada nas posicoes da lista 
{
	DATA dado; // estrutura q armazena o dado da lista 
	struct _NODE_LIST_ *prox;  // proximo nó da lista		
} NODE;

typedef struct _LIST_           //lista encadaeada simples para armazenar caracteres digitados
{
	int tam; //tamanho da lista
	NODE* head; //posicao inicial
} LISTA;

LISTA *gerar_lista();   // funcao retona uma lista gerada

void gerar_noh(LISTA *lista, DATA dado); //Insere elemento do tipo DATA na primeira ṕosicao

void imprimir_lista(LISTA *lista);  //Mosta Lista na tela

void remover_letra(LISTA *lista, int *linha); //Remove caractere de determinada posicao de lista

bool lista_vazia(LISTA *lista); //Verifica se a lista esta vazia

void alterar_letra(LISTA *lista, char letra,int posicao); //Substitui caractere de determinada posicao

void inserir_letra(LISTA *lista, DATA dado, int posicao);  //Insere dado do tipo DATA em determinada posicao da lista

void escreve(LISTA *lista, DATA dado, int *linha, int nlin, char caractere); //escreve caractere na lista

NODE *retorna_posicao(LISTA *lista, int posicao); //Retorna um dado do tipo NODE(nó da lista) de determinada posicao da lista


