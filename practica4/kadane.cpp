/**
 *  INSTITUTO POLITECNICO NACIONAL
 *  ESCUELA SUPERIOR DE COMPUTO
 *      Materia: Analisis de Algoritmos
 *      Grupo: 3CV12
 *      Integrantes:
 *         Mora Flores Einar Antonio
 *         Salinas Franco Carlos Enrique
 **/ 

#include <bits/stdc++.h>
#define TAM 100000

using namespace std;

void kadane(int* v);


int main() {
  
  // test
  vector<int> v = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
  // vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
  // vector<int> v = {1};
  // vector<int> v = {5,4,-1,7,8};

  kadane(v);

  return 0;
}

/**
 * Algoritmo de Kadane. Muestra la suma maxima de un vector
 * @param vector
 **/
void kadane(int* v) {
  int maxSum = INT_MIN, sumAux = 0, start = 0, startTemp = 0, end = 0;

  for (int i = 0; i < v.size(); ++i) {
    sumAux += v[i];
    if (sumAux > maxSum) {
      start = startTemp;
      end = i;
      maxSum = sumAux;
    }

    if (sumAux < 0) {
      startTemp = i+1;
      sumAux = 0;
    }
  }
  printf("Maxima Suma: %d\nInicio: %d - Fin: %d\n",maxSum,start,end);
}