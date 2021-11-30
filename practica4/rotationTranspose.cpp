#include <bits/stdc++.h>

using namespace std;

void print(int **M, int n);
void rotation(int **M, int n);
void transpose(int** M, int n);

int main(){
    ifstream f;
    string name;
	cout << "Ingrese el nombre del archivo: ";
	cin >> name;
    string S;
    f.open(name.c_str());
    int n = 0,j = 0,i = 0,m;
    
    // Cuenta la cantidad de filas
    while( getline(f,S) ) {
		n++;
	}
	f.close();
	
	// por si existe un renglón de más, ajusta n
	n = ((int)(n/2))*2;
	
	// M es la matriz que contendrá los datos
    int** M = new int*[n];
    for(i=0;i<n;i++){
		M[i] = new int[n];
	}
	
	// A es la matriz que contendrá los datos
    int** A = new int*[n];
    for(i=0;i<n;i++){
		A[i] = new int[n];
	}
	
	// Leemos los datos, se aceptan dos formatos de texto
	// 1.- caracteres separados por espacio o coma sin espacio
	// esto es que la longitud de cada fila es aprox el doble de columnas
	// (en nuestro ejemplo el archivo tiene 16 filas y 31 columnas)
	// 2.- caracteres no separados
    f.open(name.c_str());
    while( getline(f,S) && j<n ){
		i = 0;
		m = S.length();
		while(S[i] != '\0' && S[i] != '\n' ){
			// Si el formato es un caractér separado por espacio
			if(2*n == m || 2*n == m+1){
				if(i%2==0){
					M[j][(int)(i/2)] = (int)S[i];
				}
			}else if(n==m){
				M[j][i] = (int)S[i];
			}
			i++;
		}
		cout << endl;
		j++;
	}
	cout << "\nMatriz\n";
	print(M,n);

	cout << "\nRotacion por intercambio de filas y columnas\n";
	rotation(M,n);
	print(M,n);

  return 0;
}

void print(int **M, int n) {
	int j,i;
	for(j = 0; j < n; j++){
		for(i = 0; i < n; i++){
			cout << (char)M[j][i] << " ";
		}
		cout << endl;
	}
}

void transpose(int** M, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int tmp = M[j][i];
      M[j][i] = M[i][j];
      M[i][j] = tmp;
      // swap(M[j][i], M[i][j]);
    }
  }
}

void rotation(int **M, int n) {
  transpose(M, n);
}