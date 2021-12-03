#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list> 
#include <algorithm>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "quadratic.h"

using namespace std;

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}

int main (){

    int opcion;
    string start;
    string target;
    int num;
    string name;
    string strNum;
    int length;
    string city;
    string linea;
    string texto;

    Graph taxi;
    taxi.loadGraphMat( "taxis.txt", 10 , 10);

    Quadratic <string, int> quad_hash(10, string("empty"), myHash);

    ifstream file("base de datos.txt");

    while (true) {

        cout<<"\n----------- QuereTaxi ------------"<<endl;
        cout<<"\n1 ..... Ver Rutas Disponibles"<<endl;
        cout<<"2 ..... Llamar a un taxi"<<endl;
        cout<<"3 ..... Registrar datos de contacto"<<endl;
        cout<<"4 ..... PhoneApp de conductor"<<endl;
        cout<<"5 ..... Salir"<<endl;
        cout<<" "<<endl;
        cout<<"Opcion: ";
        cin>> opcion;

        switch (opcion)
        {
        case 1:
            cout<< taxi.printAdjMat_clean();
            break;

        case 2:   

            taxi.loadGraphList("taxis.txt", 10 , 10);

            cout<<"\nLista de lugares: ALAMEDA - ARCOS - ANTEA - REFUGIO - JURIQUILLA"<<endl;
            cout<<"Lista de lugares: TECMTY - ANAHUAC - MILENIO - PASEO - BOULEVARES"<<endl;
            cout<<"\nPorfavor escriba el lugar de su eleccion en MAYUSCULAS y tal como esta escrito, gracias."<<endl;
            cout<<"\nEscribe tu origen: ";
            cin>>start;
            cout<<"\nEscribe tu destino: ";
            cin>>target;
            cout<<"\nLa ruta mas rapida es: ";

            cout<<taxi.BFS(citytonumber(start), citytonumber(target));

            
            break;
        
        case 3:

            cout<<"\nIntroduce tu nombre: ";
            cin>>name;
            cout<<"\nIntroduce un numero (SIN LADA) para que el conductor te llame cuando llegue: ";
            cin>>num;
            cout<<" "<<endl;
            strNum = to_string(num); 
            length = strNum.length(); 

            if (length!=7) {
                cout<<"\nEl numero introducido no contiene 7 numeros, intentelo de nuevo."<<endl;
                break;
            }
            write(name, num);
            quad_hash.put(string(name), num);

            break;

        case 4:

            cout<<"\nBienvenido Conductor!"<<endl;
            cout<<" "<<endl;
            cout<<"Para obtener el numero de tu pasajero mediante PhoneApp, porfavor introduce su"<<endl;
            cout<<"nombre el cual esta disponible unicamente en tu app de conductor cuando abres el viaje: ";
            cin>>name;
            cout<<" "<<endl;
            cout<<"EL numero de "<<name<<" es: ";
            cout<<quad_hash.get(string(name));
            cout<<" "<<endl;

            break;

        case 5:

            cout<<"\nHasta la vista benji!"<<endl;
            cout<<" "<<endl;
            exit(EXIT_SUCCESS);

            break;

        default:
            cout<<"Opcion no valida en el menu, intente de nuevo"<<endl;
            cout<<" "<<endl;
            break;
        }

    }

}

