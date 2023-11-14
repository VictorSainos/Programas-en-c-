#include <iostream>
#include <cmath>
#include <random>

using namespace std;

random_device rd;
mt19937 genMT19937(rd());
uniform_real_distribution<double> U01{ 0.0, 1.0 };

typedef struct p
{
    int nombre;
    int es;
    int b[100];       //lista de preferencia
} p;


typedef struct
{
    p *a;
} c;

typedef struct
{
    int cambio;
    c M;
    c H;
} S;

c al(int, c);           // al genera un listado para cada persona de mayor a menor preferencia
S busqueda(int, S);

inline double Uniforme()
{
    return U01(genMT19937);
}

int main()
{
    int x, n;
    S s;     s.cambio = 0;
    cout << "Introdusca su numero de parejas: ";    cin >> n;

    //No hice la lista dinamicamnete porque empezaba a fallar despues de n=8
    s.M.a = (p*)malloc(n * sizeof(p));
    s.H.a = (p*)malloc(n * sizeof(p));
	
    //for (x = 0; x < n; x++)
    //{
      //  s.M.a[x].b = (int*)malloc(n * sizeof(int));
        //s.H.a[x].b = (int*)malloc(n * sizeof(int));
    //}

    for (x = 0; x < n; x++)                   //Doy nombres del a al n y emparejo uno a uno, 1 con 1, 2 con 2 y asi
    {
        s.M.a[x].nombre = x + 1;    s.H.a[x].nombre = x + 1;
        s.M.a[x].es = x + 1;        s.H.a[x].es = x + 1;
    }
    
	//	Opcionalmente se pueden escirbir las lista de preferencias, no se romomienda en parejas grandes
    //cout << "Lista de preferencia de las mujeres: " << endl;
    s.M = al(n, s.M);
    //cout << endl;
    //cout << "Lista de preferencia de los hombres: " << endl;
    s.H = al(n, s.M);
    //cout << endl;

    cout << "Parejas originales: " << endl;
    cout << " M    H" << endl;
    for (x = 0; x < n; x++)
        cout << " " << s.M.a[x].nombre << "    " << s.H.a[s.M.a[x].es - 1].nombre << endl;

    cout << endl;

    s = busqueda(n, s);

    //este while me asegura que se llego a la estabilidad
    while (s.cambio != 0)
        s = busqueda(n, s);

    cout << "Parejas finales: " << endl;
    cout << " M    H" << endl;
    for (x = 0; x < n; x++)
        cout << " " << s.M.a[x].nombre << "    " << s.H.a[s.M.a[x].es - 1].nombre << endl;

    return 0;
}


c al(int n, c h)
{
    int e, x, y, z, w;
    int d[100];

    // numero cada persona y la pongo en una matriz
    for (x = 0; x < n; x++)
        d[x] = x + 1;

    for (x = 0; x < n; x++)
    {
        z = n;    // z sera las caras de mi dado aleatorio
        for (y = 0; y < n; y++)
        {
            e = (int)(ceil(z * Uniforme()-1));  // numero aleatorio
            // Le asigno ese numero aleatorio a una posicion de d y me asegura que no se repitan personas
            h.a[x].b[y] = d[e]; 
            z--;
//activar para escirbir lista       //cout << h.a[x].b[y];
            //Recorro d para quitar a la persona ya elegida
            for (w = e; w < n - 1; w++)
                d[w] = d[w + 1];
        }
//activar para escirbir lista        //cout << endl;
        //Vuelvo a enumerar a las personas
        for (w = 0; w < n; w++)
            d[w] = w + 1;
    }

    return h;
}


S busqueda(int n, S s)
{
    int aux = s.cambio,x, y, z, w=0;

    //El primero for recorre a todas las mujeres
    for (x = 0; x < n; x++)
    {
        //El segundo for compara la lista de preferencias de las mujeres con su actual esposo
        for (y = 0; y < n; y++)
        {
            //Si su esposo no es el mejor candidato, busca si el nuevo acepta a la mujer
            if (s.M.a[x].es != s.M.a[x].b[y])
            {
                //Mientras que la esposa del nuevo no aparesca en su lista
                while (s.H.a[y].es != s.H.a[y].b[w])
                {
                    // Si la mujer es aceptada
                    if (s.M.a[x].nombre == s.H.a[y].b[w])
                    {
                        //Se intercambian parejas
                        s.M.a[s.H.a[y].es].es = s.M.a[x].es;       s.H.a[s.M.a[x].es].es = s.H.a[y].es;
                        s.M.a[x].es = s.H.a[y].nombre;             s.H.a[y].es = s.M.a[x].nombre;

                        s.cambio += 1;
                    }
                    w++;
                }
                w = 0;
            }
            else break;
        }
    }

    if (s.cambio == aux)
        s.cambio = 0;
    return s;
}
//<<>>
