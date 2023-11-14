#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) 
{
	int a=0,i,n,x,y=1,z;
	
	cout << "Introdusca c y n para x^n: ";    cin >> x;   cin >> n;
	
	//calcula cuntos bits tiene el decimal n
	while(y<=n)
	{
		y*=2;   a++;
	}
	
	int bit[a];
	
	i=a-1; z=n;
	
	//pasa de decimal a binario
	while(z!=0)
	{
		bit[i] = z%2;
		z=z/2;    i--;
	}
	
	n=a;
	//si a que es la longuitud de bit es uno eso quiere decir que la potencia es 1, si la potencia fuera cero enotnces a es cero
	if (a==1)
	{
		n=0; //igualo a=0 para que no entre en el siguiente for y bit[0]=0 ya que el primer bit se cuenta como primero y ultimo y solo puedo realizar una accion
	}
	
	y=1;
	for(i=0; i<n-1; i++)
	{
		if(i==0)            // la primera accion es multiplicar por x
		{
			y *= x;
		}
		
		if (i!=0)
		{
			if(bit[i]==1)    //si el bit es 1 se multiplica por la constante x
			{
				y*=x;   z++;
			}
		}
		y*=y;   z++;        //despues de cada recorrimiento del bits se eleva al cuedrado
	} 
	
	if(bit[a-1]==1)
	{
		y*=x;   z++;    // si el ultimo bit es uno se multiplica por x y ya no se eleva al cuadrado
	}
	
	cout << x << "^" << n << ": " << y <<endl;
	cout <<"Numero de multiplicaciones: " << z;
	
	return 0;
}
//>><<
