#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "toolsv2.h"
#include "matriz.h"
#include "matriz-operacoes.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main(int argc, char *argv[]) {

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// DECLARAÇÃO de VARIÁVEIS
	int **mat_a = NULL;
	int **mat_b = NULL;
	int **mat_multIJK = NULL;
	int **mat_multIKJ = NULL;
	int **mat_multKIJ = NULL;
	int **mat_multJIK = NULL;
	int **mat_multJKI = NULL;
	int **mat_multKJI = NULL;
	int **mat_somaIJ = NULL;
	int **mat_somaJI = NULL;
	FILE *fmat_a, *fmat_b, *fmat_c;
	int nr_line;
	int *vet_line = NULL;
	int N, M, La, Lb;
	double start_time, end_time;
	//int option;

	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	if (argc != 3){
		printf ("ERRO: Numero de parametros %s <matriz_a> <matriz_b>\n", argv[0]);
		exit (1);
	}

  // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	fmat_a = fopen(argv[1],"r");
	fmat_b = fopen(argv[2],"r");
  if ((fmat_a == NULL) || (fmat_b == NULL)) {
		printf("Error: Na abertura dos arquivos.");
		exit(1);
  }

  // matriz_a N (linha) x La (coluna)
	extrai_parametros_matriz(fmat_a, &N, &La, &vet_line, &nr_line);
	mat_a = alocar_matriz(N, La);
	filein_matriz (mat_a, N, La, fmat_a, vet_line, nr_line);

	// matriz_b Lb (linha) x M (coluna)
	extrai_parametros_matriz(fmat_b, &Lb, &M, &vet_line, &nr_line);
	mat_b = alocar_matriz(Lb, M);
	filein_matriz (mat_b, Lb, M, fmat_b, vet_line, nr_line);

	if ((mat_b == NULL) || (mat_a == NULL)) {
		printf("ERROR: Out of memory\n");
	}
	if(La != Lb){
		printf("\nMatrizes imcompativeis!\n");
		printf("Encerrando execucao\n\n");
		exit(1);
	}
    //if (La == Lb && N == M && La == M){
    //    printf("\n\nMatrizes compativeis para soma\n\n");
    //	mat_somaJI = alocar_matriz(N, M);
	//	zerar_matriz(mat_somaJI, N, M);
	//	if (mat_somaJI == NULL) {
	//		printf("ERROR: Out of memory\n");
	//	}

		start_time = wtime();
		somarJI(mat_a,mat_a,mat_somaJI, N, N, N);
		end_time = wtime();
		printf("\n ##### somarJI de Matrizes (JI) #####\n");
		printf("\tRuntime: %f\n", end_time - start_time);
		fmat_c= fopen("somarJI.map-result","w");
		fileout_matriz(mat_somaJI, N, M, fmat_c);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  // somarIJ
		mat_somaIJ = alocar_matriz(N, M);
		zerar_matriz(mat_somaIJ, N, M);
		if (mat_somaIJ == NULL) {
			printf("ERROR: Out of memory\n");
		}

		start_time = wtime();
		somarIJ(mat_a,mat_a,mat_somaIJ, N, N, N);
		end_time = wtime();
		printf("\n ##### somarIJ de Matrizes (IJ) #####\n");
		printf("\tRuntime: %f\n", end_time - start_time);
		fmat_c= fopen("somarIJ.map-result","w");
		fileout_matriz(mat_somaIJ, N, M, fmat_c);

		comparar_matriz (mat_somaIJ, mat_somaJI, N, M);

		liberar_matriz(mat_somaJI,N,M);
		liberar_matriz(mat_somaIJ,N,M);

    }
    //    printf ("matrizes incompativeis para soma.\n");
    //    exit (1);
    

	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
	// somarJI
	

	if(La == Lb){
        if(N != M && La != M){
        printf("\n\nMatrizes imcompativeis para soma!\n\n");        
        }
    printf("\n\nMatrizes compativeis para multiplicacao\n\n");
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	// // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação IJK
	 mat_multIJK = alocar_matriz(N, M);
	 zerar_matriz(mat_multIJK, N, M);
	 if (mat_multIJK == NULL) {
	 	printf("ERROR: Out of memory\n");
	 }
	
	 zerar_matriz(mat_multIJK, N, M);
	 start_time = wtime();
	 multiplicarIJK(mat_a,mat_b,mat_multIJK, N, La, M);
	 end_time = wtime();
	 printf("\n ##### Multiplicação de Matrizes (IJK) #####\n");
	 printf("\tRuntime: %f\n", end_time - start_time);
	 fmat_c= fopen("multiIJK.map-result","w");
	 fileout_matriz(mat_multIJK, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%OK

	 // // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação IKJ
	mat_multIKJ = alocar_matriz(N, M);
	zerar_matriz(mat_multIKJ, N, M);
	if (mat_multIKJ == NULL) {
	 	printf("ERROR: Out of memory\n");
	}
	
	zerar_matriz(mat_multIKJ, N, M);
	start_time = wtime();
	multiplicarIKJ(mat_a,mat_b,mat_multIKJ, N, La, M);
	end_time = wtime();
	printf("\n ##### Multiplicação de Matrizes (IKJ) #####\n");
	printf("\tRuntime: %f\n", end_time - start_time);
	fmat_c= fopen("multiIKJ.map-result","w");
	fileout_matriz(mat_multIKJ, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%OK
	 // // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação KIJ
	mat_multKIJ = alocar_matriz(N, M);
	 zerar_matriz(mat_multKIJ, N, M);
	 if (mat_multKIJ == NULL) {
	 	printf("ERROR: Out of memory\n");
	 }
	
	 zerar_matriz(mat_multKIJ, N, M);
	 start_time = wtime();
	 multiplicarKIJ(mat_a,mat_b,mat_multKIJ, N, La, M);
	 end_time = wtime();
	 printf("\n ##### Multiplicação de Matrizes (KIJ) #####\n");
	 printf("\tRuntime: %f\n", end_time - start_time);
	 fmat_c= fopen("multiKIJ.map-result","w");
	 fileout_matriz(mat_multKIJ, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%OK
	//

	 // // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação JIK
	mat_multJIK = alocar_matriz(N, M);
	 zerar_matriz(mat_multJIK, N, M);
	 if (mat_multJIK == NULL) {
	 	printf("ERROR: Out of memory\n");
	 }
	
	 zerar_matriz(mat_multJIK, N, M);
	 start_time = wtime();
	 multiplicarJIK(mat_a,mat_b,mat_multJIK, N, La, M);
	 end_time = wtime();
	 printf("\n ##### Multiplicação de Matrizes (JIK) #####\n");
	 printf("\tRuntime: %f\n", end_time - start_time);
	 fmat_c= fopen("multiJIK.map-result","w");
	 fileout_matriz(mat_multJIK, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%OK

	 // // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação JKI
	mat_multJKI = alocar_matriz(N, M);
	 zerar_matriz(mat_multJKI, N, M);
	 if (mat_multJKI == NULL) {
	 	printf("ERROR: Out of memory\n");
	 }
	
	 zerar_matriz(mat_multJKI, N, M);
	 start_time = wtime();
	 multiplicarJKI(mat_a,mat_b,mat_multJKI, N, La, M);
	 end_time = wtime();
	 printf("\n ##### Multiplicação de Matrizes (JKI) #####\n");
	 printf("\tRuntime: %f\n", end_time - start_time);
	 fmat_c= fopen("multiJKI.map-result","w");
	 fileout_matriz(mat_multJKI, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%OK

	 // // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// // Multiplicação KJI
	//mat_multKJI = alocar_matriz(N, M);
	// zerar_matriz(mat_multKJI, N, M);
	// if (mat_multKJI == NULL) {
	// 	printf("ERROR: Out of memory\n");
	// }
	//
	// zerar_matriz(mat_multKJI, N, M);
	 //start_time = wtime();
	// multiplicarKJI(mat_a,mat_b,mat_multKJI, N, La, M);
	// end_time = wtime();
	// printf("\n ##### Multiplicação de Matrizes (KJI) #####\n");
	// printf("\tRuntime: %f\n", end_time - start_time);
	// fmat_c= fopen("multiKJI.map-result","w");
	// fileout_matriz(mat_multKJI, N, M, fmat_c);
	// // %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	
	// // %%%%%%%%%%%%%%%%%%%%%%%% BEGIN %%%%%%%%%%%%%%%%%%%%%%%%
  	// Multiplicação KJI
	 mat_multKJI = alocar_matriz(N, M);
	 zerar_matriz(mat_multKJI, N, M);
	 if (mat_multKJI == NULL) {
	 	printf("ERROR: Out of memory\n");
	 }
	
	 zerar_matriz(mat_multKJI, N, M);
	 start_time = wtime();
	 multiplicarKJI(mat_a,mat_b,mat_multKJI, N, La, M);
	 end_time = wtime();
	 printf("\n ##### Multiplicação de Matrizes (KJI) #####\n");
	 printf("\tRuntime: %f\n", end_time - start_time);
	 fmat_c= fopen("multiKIJ.map-result","w");
	 fileout_matriz(mat_multKJI, N, M, fmat_c);
	
	 comparar_matriz (mat_multIJK, mat_multKJI, N, M);
	 liberar_matriz(mat_multIJK,N,M);
	 liberar_matriz(mat_multIKJ,N,M);
	 liberar_matriz(mat_multKIJ,N,M);
	 liberar_matriz(mat_multJIK,N,M);
	 liberar_matriz(mat_multJKI,N,M);	 
	 liberar_matriz(mat_multKJI,N,M);
	 
	}
	
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%
	
	liberar_matriz(mat_a,N,La);
	liberar_matriz(mat_b,Lb,M);
	fclose(fmat_a);
	fclose(fmat_b);
	// %%%%%%%%%%%%%%%%%%%%%%%% END %%%%%%%%%%%%%%%%%%%%%%%%

	return 0;
}

