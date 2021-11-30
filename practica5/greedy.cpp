#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> A);
int generateR(vector<int> A);
vector<int> solution(vector<int> d, int r);

int main() {

  // vector<int> d = {0, 29, 36, 50, 52, 66, 71, 85, 100, 117, 127, 129};
  vector<int> d = {0,5,10,30};
  int r = generateR(d);

  printf("r= %d\n",r);
  printf("Entrada: ");
  printArray(d);
  printf("\nSalida: ");
  printArray(solution(d, r));
  printf("\n");

  return 0;
}

/**
 * @param A vector que contiene los dias que abre la tienda
 * @return maximo valor entre dos numeros para el valor de r
 **/ 
int generateR(vector<int> A) {
  int maxValue = 0;
  for (int i = 0; i < A.size(); ++i) {
    int nextValue = (i + 1) % A.size();
    int maxValueTemp = max(A[nextValue] - A[i], maxValue);
    if (maxValue < maxValueTemp)
      maxValue = maxValueTemp;
  }
  return maxValue;
}
/**
 * @param A
 **/ 
void printArray(vector<int> A) {
  for (int k = 0; k < A.size(); ++k)
    printf("%d ",A[k]);
}

/**
 * @param d vector que contiene los dias que abre la tienda
 * @param r duracion del fetilizante
 * @return dias que debe ir el granjero a comprar fetilizante
 **/ 
vector<int> solution(vector<int> d, int r) {
  vector<int> set = {};
  int f = d[0] + r;
  int n = d.size();
  int lastDay = n - 1;
  int nextDay = 0;

  if (f < d[nextDay +  1]) {
    set.push_back(-1);
    return set;
  }
  set.push_back(d[0]);
  for (int i = 1; i < n; ++i) {
    nextDay = i + 1;
    if (d[nextDay] > f) {
      set.push_back(d[i]);
      f = d[i] + r;
    }
    if (i == lastDay && d[i] <= f)
      set.push_back(d[lastDay]);
  }
  return set;
}
