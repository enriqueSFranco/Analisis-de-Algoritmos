#include <bits/stdc++.h>

using namespace std;

int division1(int n, int div, int res, int* cont);
int division2(int n, int div, int res, int* cont);
int division3(int n, int div, int* cont);

int main() {
    // FILE *f = fopen("division1.cvs", "at");
    int cont = 0; // contador de pasos a ejecutar
    int points = 60; // hacemos la prueba para 20 puntos

    // int d1 = division1(0, 1, 0, &cont);
    // int d2 = division1(15, 2, 1, &cont);
    // int d3 = division1(15, 2, 1, &cont);

    // int d2 = division2(10, 2, 0, &cont);
    // int d3 = division3(10, 2, &cont);
    // printf("d1=%d\n",d1);
    // printf("d1: %d\nd2: %d\nd3: %d\n",d1,d2,d3);


    for (int i = 1; i <= points; i++) {
        cont = 0;
        int d1 = division1(i, 1, 1, &cont);
        printf("d1: %d\n",d1);
        printf("Num de pasos de div1: %d\n", cont);
        
        cont = 0;
        int d2 = division2(i, 1, 1, &cont);
        printf("d2: %d\n",d2);
        printf("Num de pasos de div2: %d\n", cont);

        cont = 0;
        int d3 = division3(i, 1, &cont);
        printf("d3: %d\n",d3);
        printf("Num de pasos de div3: %d\n", cont);
        
        // fprintf(f,"%d, %d\n", i, cont);
    }

    // fclose(f);

    return 0;
}

/**
 * Complejidad O(n)
 * @param n es el valor que se le asigna al dividendo
 * @param div es el valor que se le asigna al divisor
 * @param r es el valor que se le asigna al residuo
 * @param cont contabiliza los pasos ejecutados por el algoritmo
 **/ 
int division1(int n, int div, int r, int* cont) {
    int q = 0; (*cont)++; // O(1)

    while (n >= div) { // O(n)
        (*cont)++;
        n = n - div; (*cont)++; // O(1)
        q = q + 1; (*cont)++; // O(1)
    }
    (*cont)++;

    r = n; (*cont)++; // O(1)
    (*cont)++;
    return q; // O(1)
}

/**
 * Complejidad O(log(n))
 * @param n es el valor que se le asigna al dividendo
 * @param div es el valor que se le asigna al divisor
 * @param res es el valor que se le asigna al residuo
 * @param cont contabiliza los pasos ejecutados por el algoritmo
 **/ 
int division2(int n, int div, int res, int* cont) {
    int dd = div; (*cont)++;
    int q = 0; (*cont)++;
    int r = n; (*cont)++;

    while (dd <= n) { // logn
        (*cont)++;
        dd = 2 * dd; (*cont)++;
    }
    (*cont)++;
    
    while (dd > div) { // logn
        (*cont)++;
        dd = dd/2; (*cont)++;
        q = 2 * q; (*cont)++;
        (*cont)++;
        if (dd <= r) {
            r = r - dd; (*cont)++;
            q = q + 1; (*cont)++;
        }
    }
    (*cont)++;
    (*cont)++;
    return q; (*cont)++;
}

/**
 * Complejidad O(log(n))
 * @param n es el valor que se le asigna al dividendo
 * @param div es el valor que se le asigna al divisor
 * @param cont contabiliza los pasos ejecutados por el algoritmo
 **/ 
int division3(int n, int div, int* cont) {
    (*cont)++;
    if (div > n) {
        return 0; (*cont)++;
    }
    else {
        (*cont)++;
        return 1 + division3(n-div, div, cont);
    }
}
