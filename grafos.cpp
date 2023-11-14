#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int cam (int, int, int [][100]);

int main(int argc, char** argv) 
{
	int x,y,n,m;
	
	cout << "Introdusca la cantidad de puntos de su grafica: ";    cin >> n;
	
	int A[n][100], B[n][100];    //Matriz de adyasencia
	
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			cout << "Hay adyacencia entre el punto " << x+1 << " y el punto " << y+1 << " (1 si hay, 0 si no): ";
			cin >> A[x][y];
		}
	}
	
	cout << "De cuantos pasos quire sus caminos: ";    cin >> m; 
	
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			cout << A[x][y] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	cam(n,m,A);
	
	return 0;
}



int cam (int n, int m, int A[][100])
{
	int i,j,x,y,z,w;
	int R[n][100], aux[n][100];
	
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			R[x][y] = 0;          //aqui se guerdara cada resultado de la multiplicacion
			aux[x][y] = A[x][y];  //aux guerdara cada A^n, empezando solo con A*1
		}
	}
	
	for(w=0; w<m-1; w++)
	{
		for(x=0; x<n; x++)
		{
			for(y=0; y<n; y++)
			{
				for(z=0; z<n; z++)
				{
					R[x][y] += aux[x][z]*A[z][y];   //Multiplicacion de la matriz A^n*A
				}
			}
		}
		
		//Le paso al aux los resultados previos de la multiplicacion para volver a multiplicar por A y R en 0 para volver a gurdar resultados
		for(i=0; i<n; i++)
		{	
			for(j=0; j<n; j++)
			{
				aux[i][j] = R[i][j];
				R[i][j] = 0;
			}
		}
	}
	
	cout << "Matriz de " << m << " caminos: " << endl;
	
	for(x=0; x<n; x++)
	{
		for(y=0; y<n; y++)
		{
			cout << aux[x][y] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
//<<>>
