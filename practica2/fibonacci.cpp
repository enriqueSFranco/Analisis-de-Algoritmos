/**
 * INSTITUTO POLITECNICO NACIONAL
 * ESCUELA SUPERIOR DE COMPUTO
 * 
 * Materia: Analisis de Algoritmos
 * Profesor: Luna Benoso Benjamin
 * Grupo: 3CV12
 * Algoritmo: Susecion de Fibonacci
 * Alumnos:
 *    Mora Flores Einar Antonio
 *    Salinas Franco Carlos Enrique
 **/

#include <bits/stdc++.h>

using namespace std;

int fibonacciIterativo(int n, int* cont);
int fibonacciRecursivo(int n, int* cont);

int main() {
	FILE *f = fopen("fibonacci.cvs", "at");
  int cont = 0; // contador de pasos a ejecutar
  int points = 20; // hacemos la prueba para 20 puntos

  for (int i = 1; i <= points; i++)
  {
    cont = 0;
    int fibo = fibonacciIterativo(i, &cont);
    printf("%d -> %d, %d\n",i,fibo,cont);
    fprintf(f,"%d, %d\n", i, cont);

  }
  fclose(f);
  
  return 0;
}
// a b 
// 0,1,1,2,3,5,8,13
int fibonacciIterativo(int n, int* cont) { // O(n)
  int a = 0; (*cont)++;
  int b = 1; (*cont)++;
  int fibonacci = 0; (*cont)++;

  if (n==1) {
    (*cont)++;
    return a;
  }
  else if (n==2) {
    (*cont)++;
    return b;
  }
  else {
    (*cont)++;
    for (int i=3; i<=n; i++) {
      (*cont)++;
      fibonacci=a+b; (*cont)++;
      a=b; (*cont)++;
      b=fibonacci; (*cont)++;
    }
    (*cont)++;
  }
  (*cont)++;
  return fibonacci; (*cont)++;
}

// O(2^n)
int fibonacciRecursivo(int n, int *cont) {
	(*cont)++;
  if (n == 1) {
    return 0;(*cont)++;
  }
  (*cont)++;
  if (n == 2) {
    return 1;(*cont)++;
  }
  (*cont)++;
  return fibonacciRecursivo(n-1, cont)+fibonacciRecursivo(n-2, cont);
}
