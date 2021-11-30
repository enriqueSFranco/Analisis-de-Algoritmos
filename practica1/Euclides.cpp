/**
 * INSTITUTO POLITECNICO NACIONAL
 * ESCUELA SUPERIOR DE COMPUTO
 * 
 * Materia: Analisis de Algoritmos
 * Profesor: Luna Benoso Benjamin
 * Grupo: 3CV12
 * Alumnos:
 *    Mora Flores Einar Antonio
 *    Salinas Franco Carlos Enrique
 **/

#include <bits/stdc++.h>

using namespace std;

int euclides(int m, int n);
void fibonacci();

int main() {

  fibonacci();
  return 0;
}

/**
 * Algoritmos de euclides, calcula el mcd de dos numeros
 * @param m
 * @param n
 * @return numero de pasos ejecutados del algoritmos
 **/ 
int euclides(int m, int n) {
  int count = 0; // contador de pasos ejecutados
  int r; count++;
  int num_mayor;

  if (m<n) {
    num_mayor = m;
    r = n;
  } else {
    num_mayor = n;
    r = m;
  }

  int auxiliar;
  while(r != 0) {
      auxiliar = r; count++;
      r = num_mayor%auxiliar; count++;
      num_mayor = auxiliar; count++;
    }
    count++;
    return count;
  return 0;
}

/**
 * Fucion para probar el algoritmo de euclides con el peor caso
 * que son con los numeros de la sucesión de fibonacci
 **/
void fibonacci() {
  int points = 20; // graficar 20 puntos
  int a = 0;
  int b = 1;
  int suma = 0;
  FILE *f = fopen("peorCaso.cvs", "at");

  printf("a b count\n");
  for(int i = 1; i <= points; i++) {
    printf("%d %d %d\n", a, b, euclides(a, b));
    suma = a + b;
    a = b;
    b = suma;
    fprintf(f,"%d, %d\n", a, euclides(a,b));
  }
  fclose(f);
}