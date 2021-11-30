#include <bits/stdc++.h>

using namespace std;

void rotation( int **A, int x, int y, int m);
void print(int **M, int n);

int main(){
  ifstream f;
  string name;
	cout << "Ingrese el nombre del archivo: ";
	cin >> name;
  string S;
  f.open(name.c_str());
  int n = 0,j = 0,i = 0,m;
    
  // Cuenta la cantidad de filas
  while( getline(f,S) )
		n++;
	f.close();
	
	// por si existe un renglón de más, ajusta n
	n = ((int)(n/2))*2;
	
	// M es la matriz que contendrá los datos
  int** M = new int*[n];
  for(i = 0; i < n; i++)
		M[i] = new int[n];
	
	// A es la matriz que contendrá los datos
  int** A = new int*[n];
  for(i = 0; i < n; i++)
		A[i] = new int[n];
	
	// Leemos los datos, se aceptan dos formatos de texto
	// 1.- caracteres separados por espacio o coma sin espacio
	// esto es que la longitud de cada fila es aprox el doble de columnas
	// (en nuestro ejemplo el archivo tiene 16 filas y 31 columnas)
	// 2.- caracteres no separados
  f.open(name.c_str());
  while( getline(f,S) && j<n ) {
		i = 0;
		m = S.length();
		while(S[i] != '\0' && S[i] != '\n'){
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


	cout << "\nRotacion con divide y venceras\n";
	rotation(M, 0, 0, n);
	print(M,n);
	
  return 0;
}

void rotation(int **A, int x, int y, int m) {
  if(m < 2) { return ; } // caso base

	// caso general
  rotation(A,x,y,m/2);
  rotation(A,x+m/2,y,m/2);
  rotation(A,x,y+m/2,m/2);
  rotation(A,x+m/2,y+m/2,m/2);

  for(int i = x; i < m/2+x; i++){
    for(int j = y; j < m/2+y; j++){
			int z = A[i][j];
			A[i][j] = A[i][j+m/2];
			A[i][j+m/2] = A[i+m/2][j+m/2];
			A[i+m/2][j+m/2] = A[i+m/2][j];
			A[i+m/2][j] = z;
		} 
  }
}

void print(int** M, int n) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << (char)M[i][j] << " ";
		}
		cout << endl;
	}
}
