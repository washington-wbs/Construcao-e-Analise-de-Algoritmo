#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int **m;
int **s;
 
void MatrixChainOrder(int *arr, int n){
  int tam, i, j, k, aux1, aux2;
  n--;
  m = (int **)malloc(n * sizeof(int *));
  for(i = 0; i < n; i++){
    m[i] = (int *)calloc(n, sizeof(int));
  }
  s = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; ++i) {
    s[i] = (int *)calloc(n, sizeof(int));
  }
  for (tam = 1; tam < n; ++tam) {
    for (i = 0; i < n - tam; ++i) {
      j = i + tam;
      m[i][j] = INT_MAX;
      for (k = i; k < j; ++k) {
        aux1 = arr[i] * arr[k + 1] * arr[j + 1];
        aux2 = m[i][k] + m[k + 1][j] + aux1;
        if (aux2 < m[i][j]) {
          m[i][j] = aux2;
          s[i][j] = k;
        }
      }
    }
  }
}

void SequenciaOtima(int i, int j) {
  if(i == j){
    printf("%c", i + 65);
  } else {
    printf("(");
    SequenciaOtima(i, s[i][j]);
    SequenciaOtima(s[i][j] + 1, j);
    printf(")");
  }
}

int main(){
  int i, j, n;
  int arr1[4]  = {5, 6, 3, 1};
  int arr2[13] = {1, 5, 25, 30, 100, 70, 2, 1, 100, 250, 1, 1000, 2};
  int arr3[12] = {1000, 1, 500, 12, 1, 700, 2500, 3, 2, 5, 14, 10};
  int *matriz[3] = {arr1, arr2, arr3};
  int sizes[3] = {4, 13, 12};
  for (i = 0; i < 3; ++i) {
    printf("Matriz  : [");
    n = sizes[i];
    for (j = 0; j < n; ++j) {
      printf("%d", matriz[i][j]);
        if (j < n - 1) printf(", "); else printf("]\n");
    }        
    MatrixChainOrder(matriz[i], n);
    printf("Sequencia : ");
    SequenciaOtima(0, n - 2);
    printf("\nCusto  : %d\n\n", m[0][n - 2]);
    for (j = 0; j <= n - 2; ++j) free(m[j]);
      free(m);
      for (j = 0; j <= n - 2; ++j) free(s[j]);
        free(s);
  }
  return 0;
}
