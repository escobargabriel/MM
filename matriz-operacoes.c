       #include "matriz-operacoes.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MATRIZ %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }	
    /*testar*/
    if(N != M || N != L || M !=L){
        printf("\nMatrizes imcompativeis!\n");
        exit(1);
    }
	for(int i = 0; i < N; i++)
		for(int j=0; j < M; j++)
		mat_c[i][j] = mat_a[i][j] + mat_b[i][j];
		
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int somarJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }	
    /*testar*/
    if(N != M || N != L || M !=L){
        printf("\nMatrizes imcompativeis!\n");
        exit(1);
    }
	for(int j = 0; j < M; j++){
		for(int i = 0; i < N; i++){
		mat_c[j][i] = mat_a[j][i] + mat_b[j][i];		
		}	
	}
  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIJK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }	
    /*testar*/

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			mat_c[i][j] = 0;
			for(int k = 0; k < L; k++)
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			}
	
        return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarIKJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }
	/*testar*/		
		for(int i = 0; i < N; i++)
			for(int k = 0; k < L; k++){
				//mat_c[i][j] = 0;
				for(int j = 0; j < M; j++)			
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			
			}
	
        return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKIJ (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }    
  /*testar*/	
	for(int k = 0; k < L; k++){	
		for(int i = 0; i < N; i++){
			//mat_c[i][j] = 0;
			for(int j = 0; j < M; j++){				
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			}   
		}
	}
  return 0;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarJIK (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }
	/*testar*/	
	for(int j = 0; j < M; j++){	
			for(int i = 0; i < N; i++){
				for(int k = 0; k < L; k++){	
					mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			}
		}
	}
  return 0;
}



int multiplicarJKI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }
	/*testar*/	
	for(int j = 0; j < M; j++){	
		for(int k = 0; k < L; k++){
			for(int i = 0; i < N; i++){	
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			}
		}
	}
  return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int multiplicarKJI (int **mat_a, int **mat_b, int **mat_c, int N, int L, int M) {
    if(mat_a == NULL || mat_b == NULL || mat_c == NULL ){
        printf("\nMatriz nao alocada!!!\n");
        exit(1);    
    }
	/*testar*/
	for(int k = 0; k < L; k++){	
		for(int j = 0; j < M; j++){	
			for(int i = 0; i < N; i++){
				mat_c[i][j] += mat_a[i][k] * mat_b[k][j];			
			}
		}
	}
  return 0;
}



// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//int multiplicar_submatriz (matriz_bloco_t *mat_suba, matriz_bloco_t *mat_subb, matriz_bloco_t *mat_subc) {
/*implementar*/
//        return 0;
//}

