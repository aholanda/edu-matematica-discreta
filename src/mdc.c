
/**
 * \brief Este programa calcula o maximo divisor
 * comum entre dois numeros inteiros positivos
 * usando o algoritmo de Euclides.
 * \author Adriano J. Holanda
 * \date 2012-10-23, 2016-11-01
 * \email ajholanda@gmail.com
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
 * \brief A funcao mdc implmementa o algoritmo de 
 * Euclides de acordo com o apresentado pela
 * especificacao logica.
 * \param M primeiro numero para achar o divisor
 * \param N segundo numero para achar o divisor 
 **/

int mdc(int M, int N) {
	int x=M, y=N;

	while (x!=y) {
		printf("x=%d, y=%d\n", x, y);
		if (x<y) {
			y = y - x;
			x = x; /* instrucao inserida por questao de clareza */
		} else {
			x = x - y;
			y = y; /* instrucao inserida por questao de clareza */
		}
	}

	return x;
}

void __como_usar(char arg[]) {
  fprintf(stderr, "Uso:\n\t %s M N\n", arg);
  fprintf(stderr, "argumentos:\n\t M e N devem ser inteiros positivos.\n");
  exit(-1);
}
