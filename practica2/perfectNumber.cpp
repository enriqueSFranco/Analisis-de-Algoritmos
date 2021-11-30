/**
 * INSTITUTO POLITECNICO NACIONAL
 * ESCUELA SUPERIOR DE COMPUTO
 * 
 * Materia: Analisis de Algoritmos
 * Profesor: Luna Benoso Benjamin
 * Grupo: 3CV12
 * Algoritmo: Numero Perfecto
 * Alumnos:
 *    Mora Flores Einar Antonio
 *    Salinas Franco Carlos Enrique
 **/


#include <bits/stdc++.h>

using namespace std;

int LIMIT = 1e5;

// prototipos de funciones
bool isPerfectNumber(int n, int* cont);
void printPerfectNumber(int n);

int main() {

	//int n;
	//printf("Ingresa la cantidad de numeros perfectso a conocer\n");
	//scanf(" %d",&n);
	//printf("\n");
  //printPerfectNumber(n);
  
  int cont = 0;
  int pts = 200;
  FILE *f = fopen("perfectNumber.cvs", "at");
  for (int i = 1; i <= pts; i++) {
  	cont = 0;
  	isPerfectNumber(i, &cont);
  	printf("Num de pasos: %d", cont);
  	fprintf(f,"%d, %d\n", i, cont);  	
  }
  fclose(f);

  return 0;
}
/**
 * @param n es el numero entero a verificar si es perfecto
 * @param cont contador de pasos ejecutados
 * @return si n es un numero perfecto devolvemos true, de lo contrario false
 **/
bool isPerfectNumber(int n, int* cont) {
  int sum = 0; (*cont)++;
  (*cont)++;
  for (int i=1; i<n; i++) {
    (*cont)++;
    if (n%i == 0) {
      (*cont)++;
      sum += i;
    }
    (*cont)++;
    (*cont)++;
  }
  (*cont)++;
  if (n == sum) {
    (*cont)++;
    return true;
  }
  return false;(*cont)++;
}


/**
 * Imprime los primeros n numeros perfectos
 @param n cantidad de numeros perfectos que se mostraran
 **/
void printPerfectNumber(int n) {
  FILE *f = fopen("numero_perfecto_impresion.cvs", "at");
  int cont = 0;
  int total_numbers = 1;
  for (int i=1;i<=LIMIT;i++) {
  	cont = 0;
  	cont++;
  	cont++;
    if (isPerfectNumber(i, &cont)) {
      printf("%d\n",i); cont++;
      fprintf(f,"%d, %d\n", i, cont);
      cont++;
	  if(total_numbers==n){
		  break;
	  }
	  cont++;
	  total_numbers++;
    }
    cont++;
  }
  fclose(f);
}
