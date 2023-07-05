#include<stdio.h>
#include<stdlib.h>
int main(void) /*declarando a fun��o principal para obter o resultado do problema*/
{
	int resp; /*vari�vel que vai receber o valor da fun��o f(N) (declarada depois do c�digo main)*/
	resp = f(1000000000000);
	
	puts("********** Project Euler **********");
	puts("Problema 160: Factorial Trailing Zeros");
	puts("\n********** Resposta: **********\n");
	printf("f(1000000000000) = %d \n\n", resp);
	
	system("pause");
    return 0;
}
/*definindo a fun��o f(N) que depende de um 
par�metro N (N = 10^12), do tipo long long.*/
int f(long long N) 
{
	while (N > 1000000) 
	{
		N = N/5; //enquanto N for maior do que 1 milh�o, divida N por 5
	}
    N = N*5; // multiplique o �N� resultante por 5 para obtermos N > 10^6 (N = 2560000)
/*Determina-se res do tipo long long, devido a extensividade dos dados do problema.*/
	long long res = 1;
/*A vari�vel res retornar� o resultado do problema, ap�s serem atribu�das fun��es � mesma.*/
	int i; //contador i
	/*loop relacionado ao c�lculo do fatorial de N: come�ar em 1 ou 2 n�o faz diferen�a para o c�lculo do fatorial*/ 
	for (i = 2; i <= N; i++) // para  2  <= i <= 2560000 , realize o loop com  i = i +1
	{
		int n = i; 
		while (n % 5 == 0) // enquanto n for divis�vel por 5 - elimina��o dos 0�s
		{
			n  = n/5; 
			res  = res/2; //divida n por 5 e res por 2
		}
/*apresenta��o da f�rmula resultante dentro do loop : */
		res = (res*(n % 100000))% 100000000; 
/*
	Vale ressaltar que que a express�o acima possui o mesmo significado que :
    res = [res*(n mod 10^5)] mod 10^8
*/
	}
/*
	Realizando a opera��o res mod 10^5 para obter apenas os �ltimos 5 d�gitos do 
	(anda-se com a v�rgula 5 vezes para a esquerda, o resto da divis�o inteira ser�
	a resposta de nosso interesse), 
	j� com os zeros removidos pela opera��o anterior: 
*/
	return res % 100000; //determina-se o retorno da fun��o f(N)
}; /* ponto e v�rgula por que a fun��o est� declarada depois de sua utiliza��o */
