/*
Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador para un número dado de horas trabajadas y un salario hora.
Las horas que superen las 40 horas semanales se pagarán como extras con un salario hora 1,5 veces el salario ordinario. Así mismo se deberá calcular 
el monto a pagar de IGSS por cada trabajador.

El programa debera contener un menu para:
1) Invocar dicha funcion y grabar datos a un archivo,
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria. 
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;

struct datos{
	int codem;
	char nombre[25];
	float salario;
	int horas;
	float iggs;
	float total;
	float costohora;
	float costohextra;
	int horaextra;
}est;

void menu();
void pedirdatos();
void aniadir();
void leer();

int main(){
		 menu();
	system("pause");
}

void menu(){
		int menu;
	do{
		system("cls");
		cout<<"\t\t\t\t------Funciones salariales------"<<endl;
		cout<<"\t\t\t\t--------------------------------"<<endl;
		cout<<"\t\t\t\t1.Ingresar Datos"<<endl;
		cout<<"\t\t\t\t2.Leer Archivo"<<endl;
		cout<<"\t\t\t\t3.Salir"<<endl;
		cout<<"\t\t\t\t  Elija una opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
				system("cls");
				pedirdatos();
				aniadir();
				break;
			case 2:
				system("cls");
				leer();
				break;
			case 3:
				menu = 3;
				break;
	
		}
	}while(menu!=3);
}

void pedirdatos(){
	cout<<"Ingrese el Codigo del Empleado: "<<endl;
	cin>>est.codem; 
	fflush(stdin);
	cout<<"Ingrese Nombre de Empleado: "<<endl;
	cin.getline(est.nombre,25,'\n');
	cout<<"Ingrese Salario Ordinario: "<<endl;
	cin>>est.salario;
	cout<<"Ingrese Horas Trabajadas: "<<endl;
	cin>>est.horas;
	
	est.costohora = est.salario/30/8;
	if(est.horas>40){
		est.horaextra = est.horas - 40;
	}
	est.iggs = ((est.horas - est.horaextra)*est.costohora)*0.0483;
	est.costohextra = (est.horaextra*est.costohora)*1.5;
	
	est.total = ((est.horas-est.horaextra)*est.costohora + est.costohextra)-est.iggs;
}

void aniadir(){
		ofstream archivo;
				
		try {
		archivo.open("archivo.txt",ios::app);
		archivo<<est.codem<<"\t"<<est.nombre<<"\t"<<est.horas<<"\t"<<est.salario<<"\t"<<est.total<<"\t"<<est.iggs<<endl;
		archivo.close();
		cout<<"Datos grabados en el archivo"<<endl<<endl;
		}
		catch(exception X){
			cout<<"Error al grabar en el archivo"<<endl<<endl;
		} //fin try/catch
		system("PAUSE");
		archivo.close();
}

void leer(){
	system("cls");
	ifstream leer;
	string salario;
	int lineas=0,i;

			
		leer.open("archivo.txt",ios::in); 
				
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
				
		while(getline(leer,salario)){
			lineas++;
		}	
	leer.close(); 	
					
	datos v[lineas];
			
		leer.open("archivo.txt",ios::in);
		if(leer.fail()){
			cout<<"No se pudo abrir el archivo!!!";
			exit(1);
		}
		
		for(i=0;i<lineas;i++){    
  			leer>>v[i].codem>>v[i].nombre>>v[i].horas>>v[i].salario>>v[i].total>>v[i].iggs;
		}
		
			cout<<"\t\t\tCodigo empleado | Nombre Empleado | Horas  |  Salario  |     Total a pagar  |    IGGS   "<<endl;
		for(i=0;i<lineas;i++){
			cout<<"\t\t\t\t "<<v[i].codem<<"\t\t"<<v[i].nombre<<"\t\t"<<v[i].horas<<"\t"<<v[i].salario<<"\t\t"<<v[i].total<<"\t\t"<<v[i].iggs<<endl;
		}
		cout<<endl<<endl;
		system("pause");
		leer.close();
}
