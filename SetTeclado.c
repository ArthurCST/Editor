#include "SetTeclado.h"
#include "SetLinhas.h"
#include "conioreal.h"

void moveUP()
{
	if((wherey()-1) > 0) //caso a posicao y não seja a inical
	{
		gotoxy(wherex(), wherey()-1); //recupera as pocisoes de xy e decrementa o y
	}
}

void moveDOWN(int nlin)
{
	if((wherey()+1) < nlin) //caso haja linha digitada pra baixo
	{
		gotoxy(wherex(), wherey()+1);//recupera as pocisoes de xy e incrementa o y
	}
}

void moveLEFT()
{
	if((wherex()-1) > 0) //caso a posicao x não seja a inical
	{
		gotoxy(wherex()-1, wherey()); //recupera as pocisoes de xy e incrementa o x
	}
}

void moveRIGHT(int *linha)
{	
	if((wherex()+1)<=linha[wherey()]) //caso haja texto digitado a direita
	{
		gotoxy(wherex()+1, wherey()); ////recupera as pocisoes de xy e incrementa o x
	
	}
	
}

void END_FECHAR()
{
	endconio();//elimina a janela
	exit(0); //fecha o programa
}

