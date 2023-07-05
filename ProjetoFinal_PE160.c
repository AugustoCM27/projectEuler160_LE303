#include<stdio.h>
#include<stdlib.h>
int main(void) /*declarando a função principal para obter o resultado do problema*/
{
	int resp; /*variável que vai receber o valor da função f(N) (declarada depois do código main)*/
	resp = f(1000000000000);
	
	puts("********** Project Euler **********");
	puts("Problema 160: Factorial Trailing Zeros");
	puts("\n********** Resposta: **********\n");
	printf("f(1000000000000) = %d \n\n", resp);
	
	system("pause");
    return 0;
}
/*definindo a função f(N) que depende de um 
parâmetro N (N = 10^12), do tipo long long.*/
int f(long long N) 
{
	while (N > 1000000) 
	{
		N = N/5; //enquanto N for maior do que 1 milhão, divida N por 5
	}
    N = N*5; // multiplique o “N” resultante por 5 para obtermos N > 10^6 (N = 2560000)
/*Determina-se res do tipo long long, devido a extensividade dos dados do problema.*/
	long long res = 1;
/*A variável res retornará o resultado do problema, após serem atribuídas funções à mesma.*/
	int i; //contador i
	/*loop relacionado ao cálculo do fatorial de N: começar em 1 ou 2 não faz diferença para o cálculo do fatorial*/ 
	for (i = 2; i <= N; i++) // para  2  <= i <= 2560000 , realize o loop com  i = i +1
	{
		int n = i; 
		while (n % 5 == 0) // enquanto n for divisível por 5 - eliminação dos 0’s
		{
			n  = n/5; 
			res  = res/2; //divida n por 5 e res por 2
		}
/*apresentação da fórmula resultante dentro do loop : */
		res = (res*(n % 100000))% 100000000; 
/*
	Vale ressaltar que que a expressão acima possui o mesmo significado que :
    res = [res*(n mod 10^5)] mod 10^8
*/
	}
/*
	Realizando a operação res mod 10^5 para obter apenas os últimos 5 dígitos do 
	(anda-se com a vírgula 5 vezes para a esquerda, o resto da divisão inteira será
	a resposta de nosso interesse), 
	já com os zeros removidos pela operação anterior: 
*/
	return res % 100000; //determina-se o retorno da função f(N)
}; /* ponto e vírgula por que a função está declarada depois de sua utilização */
