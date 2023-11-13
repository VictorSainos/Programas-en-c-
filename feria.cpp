#include <iostream>
#define Max 1000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct
{
	int a[Max];
} P;

P moneda3 ();
P moneda4 ();

int main(int argc, char** argv) 
{
	int x;
	P p;
	
	p = moneda4();	
	
	for(x=3; x<24; x++)
	{
		cout << p.a[x] << " ";
	}
	
	return 0;
}


P moneda3 ()
{
	int r,x,y,z;
	P p;
	for (x=1; x<7; x++)
		for (y=1; y<7; y++)
			for (z=1; z<7; z++)
				p.a[x+y+z-1] = 0;

	for (x=1; x<7; x++)
		for (y=1; y<7; y++)
			for (z=1; z<7; z++)
				p.a[x+y+z-1]++;
				
	return p;
}


P moneda4 ()
{
	int r,x,y,z,w;
	P p;
	
	for (x=1; x<7; x++)
		for (y=1; y<7; y++)
			for (z=1; z<7; z++)
				for (w=1; w<7; w++)
					p.a[x+y+z+w-1]=0;
					
	for (x=1; x<7; x++)
		for (y=1; y<7; y++)
			for (z=1; z<7; z++)
				for (w=1; w<7; w++)
					p.a[x+y+z+w-1]++;
					
	return p;
}
//<<>>
