#include <bits/stdc++.h>

#define TAM 1000

using namespace std;

void generateArray(int* arr, int tam);
void printArray(int* arr, int tam);

int ternarySearch1(int* arr, int l, int r, int x, int* cont);
int ternarySearch2(int* arr, int l, int r, int x, int* cont);

int main() {
    // FILE *f = fopen("ternarySearch2.cvs", "at");
    int tam = 10;
    int A[TAM];
    int cont = 0;
    int points = 60;

    for (int i = 1; i <= points; i++) {
        cont = 0;
        generateArray(A, tam);
        printf("\n");

        printArray(A, tam);
        printf("\n");
        int search = random() % tam+1;
        // int ts1 = ternarySearch1(A, 0, tam - 1, search, &cont);
        // printf("search:%d, ts1:%d\n",search, ts1);

        // cont = 0;
        int ts2 = ternarySearch2(A, 0, tam - 1, search, &cont);
        printf("search:%d, ts2:%d\n",search, ts2);
        
        // fprintf(f,"%d, %d\n", tam, cont);

        tam+=10;
    }

    // fclose(f);

    return 0;
}

/**
 * @param arr
 * @param tam
 **/
void generateArray(int* arr, int tam) {

    int n = 1;
    for (int  i = 0; i < tam; i++) {
        arr[i] = n++;
    }
}
/**
 * @param arr
 * @param tam
 **/ 
void printArray(int* arr, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("[%d]",arr[i]);
    }
}

/**
 * Complejidad: O(log(n))
 * @param arr entrada
 * @param tam longitud del array
 * @param l apunta al primer elemento del array
 * @param r apunta al ultimo elemento del array
 * @param x elemento a buscar
 * @param cont guarda el numero de pasos ejecutados por el algoritmo
 * @return si existe el elementos devolvemos la posicion en la que se encuentra, si no devolvemos -1
 **/
int ternarySearch1(int* arr, int l, int r, int x, int* cont) {

    while (l <= r) { // log(n)
        (*cont)++;
        int i = l + (r - l) / 3; (*cont)++;
        int j = r - (r - l) / 3; (*cont)++;
        // printf("i=%d j=%d\n", i,j);

        (*cont)++;
        if (x == arr[i]) {
            return i; (*cont)++;
        }

        (*cont)++;
        if (x == arr[j]) {
            return j; (*cont)++;
        }

        (*cont)++;
        if (x < arr[i]) {
            r = i - 1; (*cont)++;
        }
        
        else if (x > arr[j]) {
            (*cont)++;
            l = j + 1; (*cont)++;
        }

        else {
            (*cont)++;
            l = i + 1; (*cont)++;
            r = j - 1; (*cont)++;
        }
    }
    (*cont)++;
    return -1; (*cont)++;
}


/**
 * @param arr lista de numeros enteros
 * @param l 
 * @param r
 * @param x elemento a buscar en la lista
 * @param cont contador de pasos ejecutados del algoritmo
 **/
int ternarySearch2(int* arr, int l, int r, int x, int* cont) {
    if (l <= r) {
        int i = l + (r - l) / 3;
        int j = r - (r - l) / 3;

        if (x == arr[i])
            return i;
        if (x == arr[j])
            return j;

        if (x > arr[j])
            return ternarySearch2(arr, j + 1, r, x, cont);
        else if (x < arr[i])
            return ternarySearch2(arr, l, i - 1, x, cont);
        else
            return ternarySearch2(arr, i + 1, j - 1, x, cont);
    }
    return 0;
}
