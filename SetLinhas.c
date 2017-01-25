#include "SetLinhas.h"

void escreve(LISTA *lista, DATA dado, int *linha, int nlin, char caractere)
{
	//Converte coodenada (x,y) da tela em uma posicao da lista
	int i, result = 0, posicao;
	dado.letra = caractere;
	if((wherey()-1) > 1){
		for(i=0; i<=(wherey()-1); i++)
		{
			result= result+linha[i];
		}
		posicao =result+wherex()+1;
		inserir_letra(lista, dado, posicao);
	}
	else 
	{
		posicao = wherex()-1;
		inserir_letra(lista, dado, posicao);
	}
}


LISTA *gerar_lista()
{
	LISTA *lista = (LISTA*)malloc(sizeof(LISTA)); //Aloca um espaço de memoria q caiba o tipo LISTA
	lista->tam = 0; //define tamanho incial = 0
	lista->head = NULL; //proxmio nó da lista igual a NULL
	return lista;
}

void inserir_letra(LISTA *lista, DATA dado, int posicao)
{	
	if(posicao == 0){
		NODE *noh = (NODE*) malloc(sizeof(NODE)); 
		noh->dado = dado;
		noh->prox = lista->head;
		lista->head = noh;
		lista->tam++;
	}else if(posicao >= lista->tam){
		NODE *noh = (NODE*) malloc(sizeof(NODE));
		noh->dado = dado;
		noh->prox = NULL;
		NODE *ultimo = retorna_posicao(lista, 0);
		while(ultimo->prox != NULL)
		{
			ultimo = ultimo->prox;
		}
		ultimo->prox = noh;
		lista->tam++;
	}
	else
	{
		NODE *atual = retorna_posicao(lista, posicao);
		if(atual != NULL)
		{
			NODE *anterior = retorna_posicao(lista, posicao-1);
			NODE *novoNoh = (NODE*) malloc(sizeof(NODE*));
			novoNoh->dado = dado;
			anterior->prox = novoNoh;
			novoNoh->prox = atual;
		}
		lista->tam++;	
	}
	
}
void imprimir_lista(LISTA *lista)
{
	if(lista_vazia(lista) == true)// caso a lista esteja vazia a funcao acaba
	{
		return;
	}
	
	NODE *ponteiro = lista->head; //ponteiro recebe a posicao inicial da lista

	while(ponteiro != NULL) //pontonteiro percorre a lista ate o fim e imprimindo os dados armazenados
	{
		printw("%c", ponteiro->dado.letra);
		ponteiro = ponteiro->prox;
	}
}
NODE *retorna_posicao(LISTA *lista, int posicao) //retorna um dado do tipo NODE localizado em determinada posicao
{
	NODE *noh = lista->head;//percore do inicio ate a posicao informada 
		int i;
		for(i=0; i<posicao; i++)
		{
			noh = noh->prox;
		}
	return noh;
}
void remover_letra(LISTA *lista, int *linha)
{	//Converte coodenada (x,y) da tela em uma posicao da lista
	int i, result = 0, posicao;
	if(wherey()-1>0){
		for(i=0; i<=(wherey()-1); i++)
		{
			result= result+linha[i];
		}
		posicao = result+wherex()+1;
	}else {
		posicao = wherex();
	}

	NODE *atual = retorna_posicao(lista, posicao); //atual recebe o NODE referente a posicao do cursor
	if(atual != NULL)
	{
		NODE *anterior = retorna_posicao(lista, posicao-1); //anterior recebe a posicao - 1 do NODE atual
		anterior->prox = atual->prox;
		free(atual); //apaga a posicao atual da memoria
		printw(" ");
		lista->tam--;//decrementa o tamanho da lista
	}
}
bool lista_vazia(LISTA *lista)
{
	if(lista->tam == 0) //se o temanho da lista for igual a zero a lista esta vazia
	{
		return true;
	}else
	{
		return false;
	}	
}
void alterar_letra(LISTA *lista, char letra, int posicao)
{
	if(posicao >= 0 && posicao < lista->tam )
	{
		DATA dado;
		NODE *noh = lista->head;
		int i;
		for(i=0; i<posicao; i++)//percorre lista da posicao incial ate a posica a ser autreada
		{
			noh = noh->prox;
		}
		dado.letra = letra;
		noh->dado = dado;
	}
	return;	
}

