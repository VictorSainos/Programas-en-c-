#include <iostream>
#include <string.h>
#define Max 1000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

typedef struct
{
	int p[Max];
} P;

P par (int ,int, int []);
int potencia (int);
int verificar(int, int[]);

int main(int argc, char** argv) 
{
	int n,m, p=0, i=0,x,y, z=0, w=1;
	char cad[Max], cad2[Max]; 
	int a[Max],aux[Max], d[] = {1,2,4,8,16,32,64,128};
	P h,j;
	
	cout << "Ingrese el mensaje: ";   cin >> cad;
	n = strlen(cad);
	m = n*8; x=m; //obtengo la cantidad de bit del mensaje
	
	//calcula cuatos bit se agragaran al mensaje
	do
	{
		x=x/2;    p++;
	} while(0<x);
	
	for (x=0; x<p; x++)  a[potencia(x)-1] = 3; //reserva el espacio para los bit de codificacion
	
	for (x=n-1; x>=0; x--)
	{
		y=cad[x];
		
		//pasa de decimal a binario
		while(y!=0)
		{
			aux[i] = y%2;
			y=y/2;   i++;
		}
		
		//Va agregando cada bit a mi nueva cadena de bits, se agrega de derecha a izquierda segun la cadena de caracteres
		while (z<=i)
		{
			if(a[w]!=3) 
			{
				a[w]=aux[z]; z++;
			}
			w++;    
		}
		z=0;
		i=0;
	}
		
	h = par(m,p,a);
	cout << "El codigo hamming es: ";
	
	for (x=0; x<p;x++)
	{
		cout << h.p[x];
	}
	cout << endl;
	
	cout << "Ingrese la posicion del bit que cambiara: ";   x = verificar(p+m, a);
	
	//cambia el bit seleccionado
	if (a[x]==1) a[x]=0;
	else a[x]=1;
	
	int r=0,pos=7;    char b;
	y=0;
	
	cout <<"El mensaje resivido es: ";
	for (x=p+m-1; x>=0; x--)
	{
		if (a[x]!=3) 
		{
			if (a[x]==1)
			{
				r += d[pos];
			}
			y++; pos--;
		}
		
		if (y==8)
		{
			b = r;
			cout << b;
			y=0; pos = 7; r=0;
		}
	}
	
	cout << endl;
		
	j = par(m,p,a);
	
	r=0; y=0;
	
	cout << "El error esta en el bit: ";
	for (x=0; x<p; x++)
	{
		if(h.p[x] != j.p[x])
		{
			cout << "2^" <<x << " ";
			r+=d[y];
		}
		y++;
	}	
	
	cout << "= " << r << endl;
	
	return 0;
}


//verifica que el bit ingresado pueda cambiarse
int verificar(int p, int a[])
{
	int n;
	
	cin >> n;
	
		if(a[n-1]==3) 
		{
			cout << "La posicion esta reservada para el bit de paridad, escoja otra: "; 
			n = verificar(p,a);
		}
		
		if ( n-1>=p)
		{
			cout << "La posicion revasa el rango " << p << " escoja otra vez: "; 
			n = verificar(p,a);
		}
		
	return n-1;
}


//calcula las potencias de 2
int potencia (int x)
{
	int y,r=1;
	
	for(y=0; y<x; y++)  r=r*2;
	
	return r;
}


//genera el codigo hamming
P par (int m, int p, int q[])  // m es la cantidad de bits del mensaje, p es la cantidad de bits ques e agregaran
{
	int a,x,y,z;
	P c;	
	
	for (x=0; x<p; x++)
	{
		c.p[x]=0;
		y = potencia(x)-1;
		a=y;
		
		while (a<p+m)
		{
			for (z=0; z<y+1; z++)
			{
				if (a<p+m)
				{
					if (q[a]==1) 
					{
						c.p[x]+=1;
					}
				}
				a++;
			}
			a+=y+1;
		}
		c.p[x] %=2;
	}
	
	return c;
}
//<<>>
