#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int distancia(int, int, int, int);
int generatriz(int,int);

int main(int argc, char** argv) 
{
	int n,m,x1,x2,y1,y2;
	
	//Lectura de la posicion del rey
	cout << "Introsdusca las cordenadas de su rey: ";    cin >> x1 >> y1;
	
	//Lectura del destino
	cout << "Introsdusca las cordenadas del destino: ";    cin >> x2 >> y2;
	
	n = distancia(x1,y1,x2,y2);          // la dsitancia seria el exponente de la generatriz (1+x+x^2)^n

	m = abs(abs(x2-x1) - abs(y2-y1));    // m es el expoente de una de las entradas de la generatriz ya multipicada
	                                     // asi si m es 1 y mi generatriz es (1+x+x^2)^2 = 1 + 2x+ 3x^2 + 2x^3 + x^4
	cout << endl;                        // la cantidad de caminos serian 2, en conclusion n me dice las veces que multiplico la genmeratriz
	generatriz(n,m);                     // y m el exponente donde esta la cantidad de caminos, el cual es el coeficiente de dicho exponente
	
	return 0;
}


//La funcion calcula la dsitancia entre punto y punto
int distancia(int x1, int y1, int x2, int y2)
{
	int a,b;
	
	a = abs(x2-x1);    b = abs(y2-y1);   //Calculo la distancia restando la cordenada x del rey menos la cordenada y del destino
	                                     // lo mismo con las y, despues tomo el mayor de los 2 y esa es la distancia entre punto y punto
	return fmax(a,b);
}



int generatriz(int n, int m)
{
	int a,i,x,y,w,z;
	int A[2*n+1], B[2*n+1];    // En A guardo el resultado de cada multiplicacion (1+x+x^2)^n * (1+x+x^2), B es quien sera multiplicado por (1+x+x^2)
	
	for(x=0; x<2*n+1; x++)     //Aqui relleno a A de ceros y a B solo pongo los coeficientes de x^0, x^1 y x^2
	{
		if(x<3)
			B[x]=1;
		A[x]=0;    
	}
	
	
	if(n > 1)                      //Si la dsitancia es uno, no tengo que hacer nada
	{
		for(x=1; x<n; x++)         //Voy a multiplicar n-1 ya que la multipicacion (1+x+x^2)*1 ya la "hice"
		{
			w = 2*x+1;             // (1+x+x^2)^n tiene 2*n+1 terminos
			for(y=0; y<w; y++)     // entonces multiplicare solo esos terminos, x=1 sera (1+x+x^2)(1+x+x^2), solo multiplico lso primeros 3 terminos
			{                      // x=2, (1+2x+3x^2+2x^3+x^4)(1+x+x^2), solo multiplico los primeros 5 terminos
				for(z=0; z<3; z++) // Este for multiplica cada entrada de (1+x+x^2)^n por (1+x+x^2)
				{
					a =  y + z;     // a es el exponente
					A[a] += B[y]*1; // uno porque los coeficientes de (1+x+x^2) son 1
				}
			}
			
			for(i=0; i<2*n+1; i++)  //aqui paso los coeficientes de la multiplicacion hecha a B y A la relleno de ceros para la siguiente multiplicacion
			{                       // esto ya que necesito los ceoficientes resultantes para multiplicarlos por (1+x+x^2)
				B[i] = A[i];
				A[i]=0;
			}
		}
	}
	
	w = 2*n+1;
	
	cout << "La distnacia es: " << n << " ,la cantidad de caminos es: " << B[m];
	
	return 0;
}
//<<>>
