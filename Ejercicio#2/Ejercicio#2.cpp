/*Ejercicio # 2: Ciclos y Arreglos
Una empresa tiene diez almacenes y necesita crear un programa que lea las ventas mensuales de los diez almacenes,
 calcular la media de ventas y obtener un  listado de los almacenes cuyas ventas mensuales son superiores a la media.*/
 
 #include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct datos{
	int cod;
	int mes;
	float ventas;
};

void pedirdatos();
int main(){
	pedirdatos();
	system("pause");
}

void pedirdatos(){
	int i, sumatotal=0;
	float media;
	datos vec[2];
	
	for(i=0;i<2;i++){
		system("cls");
		cout<<"\t\t\t\t-----VENTAS DE ALMACENES-----"<<endl;
		cout<<"\t\t\t\t-----------------------------"<<endl;
		cout<<"\t\t\t\t** Ingrese el codigo del almacen "<<i+1<<": ";
		cin>>vec[i].cod;
		do{
			cout<<"\t\t\t\t** ingrese el mes del de la realizacion de la venta "<<i+1<<": ";
			cin>>vec[i].mes;
		}while(vec[i].mes>12);
		cout<<"\t\t\t\t** Ingrese la cantidad vendida ";
		cin>>vec[i].ventas;
		sumatotal +=vec[i].ventas;
	}
	media = sumatotal/2;
	
	for(i=0;i<2;i++){
		system("cls");
		if(vec[i].ventas > media){
			cout<<"El almacen "<<vec[i].cod<<" con ventas de "<<vec[i].ventas<<" en el mes de "<<vec[i].mes<<" es superior a la media"<<endl;
		}else{
			cout<<"Ningun almacen supero las ventas superior a la media establecida"<<endl<<endl;
		}
		cout<<"La media de las ventas de todos los almacenes es: "<<media<<"\n\n";
	}
}
