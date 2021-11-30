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

#define TAM 1000

using namespace std;

void generateArray(int *arr, int tam);
void printArray(int *arr, int tam);
void binaryToDecimal(int *arrA, int *arrB, int tam, int *count);

int main()
{
  init();
  return 0;
}

/**
 * Funcion que se encarga de iniciar el algoritmos
 **/
void init() {
  FILE *f = fopen("binaryToDecimal.cvs", "at");
  int count = 0; // contador de pasos a ejecutar
  int points = 20; // hacemos la prueba para 20 puntos
  int tam = 10; // iniciamos con una longitud en el arreglo de 10
  int A[TAM], B[TAM];

  for (int i = 0; i < points; i++)
  {
    count = 0;
    
    generateArray(A, tam);
    generateArray(B, tam);
    
    printArray(A, tam);
    
    printf("\n");
    printArray(B, tam);
    
    printf("\n");
    binaryToDecimal(A, B, tam, &count);
    
    printf("Num de pasaos: %d", count);
    
    fprintf(f,"%d, %d\n", tam, count);
    
    tam += 10;
  }
  fclose(f);
}

/**
 * Funcion para generar un arreglo con numeros entre 0 y 1
 * @param arr
 * @param tam -> longitud del arreglo
 **/
void generateArray(int *arr, int tam)
{
  srand(time(NULL));
  for (int i = 0; i < tam; i++)
  {
    arr[i] = rand() % 2;
  }
}

/**
 * Funcion para mostrar por consola un arreglo
 * @param  arr
 * @param tam -> longitud del arreglo
 **/ 
void printArray(int *arr, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("[ %d ]", arr[i]);
  }
}

/**
 * Funcion que realiza la operacion and entre dos arreglos con numeros binarios y posteriormente calcula el numero en decimal
 * @param arrA
 * @param arrB
 * @param tam -> longitud del arreglo
 * @param count -> cuenta el numero de pasos que ejecuta el algoritmo
 **/ 
void binaryToDecimal(int* arrA, int* arrB, int tam, int *count)
{
  unsigned long long numDecimal = 0; (*count)++;
  int m = 1; (*count)++;
  int current_c; (*count)++; // caracter actual del arreglo c
  int arrC[tam]; (*count)++; // arreglo para almacenar el numero binario despues de aplicar la operacion AND
  
  // OPERACION AND
  (*count)++;
  for (int k = 0; k < tam; k++)
  {
    (*count)++;
    if (arrA[k] == 1 && arrB[k] == 1)
    {
      (*count)++;
      arrC[k] = 1; (*count)++;
    }
    else
    {
      (*count)++;
      arrC[k] = 0; (*count)++;
    }
    (*count)++;
    printf("%d ", arrC[k]); (*count)++;
  }
  (*count)++;

  // pasar de binario a decimal
  (*count)++;
  for (int x = tam - 1; x >= 0; x--)
  {
    (*count)++;
    current_c = arrC[x]; (*count)++;
    if (current_c == 1) {
      (*count)++;
      numDecimal += m; (*count)++;
    }
    m *= 2; (*count)++;
    (*count)++;
  }
  (*count)++;
  printf("\nNumero Decimal: %llu\n", numDecimal); (*count)++;
}