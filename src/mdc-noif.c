
/**
 * Este programa calcula o maximo divisor
 * comum entre dois numeros inteiros positivos
 * usando o algoritmo de Euclides.
 * Autor: Adriano J. Holanda
 * Data: 2012-10-23
 */

#include <stdio.h>
#include <stdlib.h>

int mdc(int M, int N);
void __como_usar(char arg[]);

int main(int argc, char **argv) {
	int M, N;

	if (argc!=3)
		__como_usar(argv[0]);

	M = atoi(argv[1]);
	N = atoi(argv[2]);
    
	if (M<=0 || N<=0)
		__como_usar(argv[0]);
  
	printf("MDC(%d,%d)=%d\n", M, N, mdc(M,N));
  
	return 0;
}

/**
 * Na versao sem loop do calculo do mdc as afirmacoes logicas sao
 * implementadas de forma mais fidedigna.  Em C, quando uma afirmacao
 * eh falsa, o valor zero eh retornado, e no caso do conectivo
 * logico && (AND), o restante da expressao nao sera avaliada 
 * pois a avaliacao das expressoes em C eh feita da esquerda para 
 * a direita. Ignorar o aviso do compilador para este fato que eh
 * desejado.
 */

int mdc(int M, int N) {
	int x, y;
	/* 
	   Os rotulos Init: e Next: sao usados somente para ficar parecido 
	   com a especificacao. Ignorar o aviso do compilador para a falta
	   de uso.
	*/
Init:
	x=M, y=N;
  
Next:
	do { /* este do-while seria bug na versão usando if */
		printf("x=%d, y=%d\n", x, y);
		((x<y) && (y = y - x)) || ((x>y) && (x = x - y));
	} while (x!=y);

	return x;
}

void __como_usar(char arg[]) {
  fprintf(stderr, "Uso:\n\t %s M N\n", arg);
  fprintf(stderr, "argumentos:\n\t M e N devem ser inteiros positivos.\n");
  exit(-1);
}

/*
  Changelog:
  2016-11-01: Comentarios do rotulos e loop.
 */
