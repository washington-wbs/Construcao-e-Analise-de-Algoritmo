#include <stdio.h>

void iniciar(){
  printf("\n");
  printf(">>> SEQUÊNCIA DE FIBONACCI <<<");
}

int valorInicial(){
  int valor;
  printf("\n\nInforme quantos termos devem aparecer: ");
  scanf("%d", &valor);
  return valor;
}

int fibonacci(int valor){
  if (valor <= 0) {
    return valor;
  } else {
    int i, resultado = 1, ultimo = 1, penultimo = 1;
    for (i = 3; i <= valor; i++) {
      resultado = ultimo + penultimo;
      penultimo = ultimo;
      ultimo = resultado;
    }
    return resultado;
  }
}

void calcularFibonacci(int valor){
  int i;
  for (i = 0; i < valor; i++) {
    printf("%d, ", fibonacci(i));
  }
}

int main(void) {
  iniciar();
  int valor = valorInicial();
  printf("\n- Sequencia -\n");
  calcularFibonacci(valor);

  printf("\n\n");
  return 0;
}
