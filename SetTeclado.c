#include "SetTeclado.h"

void moveUP()
{
	if((wherey()-1) > 0)
	{
		gotoxy(wherex(), wherey()-1);
	}
}

void moveDOWN(int nlin)
{
	if((wherey()+1) < nlin)
	{
		gotoxy(wherex(), wherey()+1);
	}
}

void moveLEFT()
{
	if((wherex()-1) > 0)
	{
		gotoxy(wherex()-1, wherey());
	}else if((wherey()-1) > 0)
	{
		gotoxy(wherex(), wherey()-1);
	}
}

void moveRIGHT(char *texto)
{
	if((wherex()+1) < strlen(texto))
	{
		gotoxy(wherex()+1, wherey());
	}else{
		newline();
	}
}

void backspace(char *texto)
{
	remove_char(texto, wherex());
	if((wherex()-1) > 0)
	{
		gotoxy(wherex()-1, wherey());
	}else if((wherey()-1) > 0)
	{
		gotoxy(wherex(), wherey()-1);
	}
}

void ENTER(char *texto, int nlin, int i)
{
	escreve(texto);
	strcpy(texto, "" );
	i = 0;
	nlin = nlin+1;
	newline();
}

void END_FECHAR(bool rodando)
{
	system("exit terminal");
}

void F1_ABRIR()
{

}

void F2_SALVAR()
{

}

void F3_COMPILAR(char *nomeDoArquivo)
{
	char *comando = "gcc ";
	char *str2 = ".c -o ";
	strcat(comando, nomeDoArquivo);
	strcat(comando, str2);
	strcat(comando, nomeDoArquivo);
	
	system(comando);
}

void F4_EXECUTA(char *nomeDoArquivo)
{
	char *comando = "./";
	strcat(comando, nomeDoArquivo);
	system(comando);
}