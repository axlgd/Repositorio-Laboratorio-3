/*****************************************************
 // FileName:        Lab3_ADC_19060718.cpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     LABORATORIO 3 ADC.
 // Authors:         AXEL GAY DIAZ
 // Updated:         10/2022
 //Nota: 
****************************************************/
 
#include <iostream>
#include <stdlib.h>
#include <clocale>

using namespace std;

/******************************
 DECLARACION DE LA CLASE
******************************/
class ADC{
//Atributos 	
	private:
		static int res;   
	    static float frec;  
	    float  volt;           
        double  res2;     
        string canal;       
//Métodos
	public:
		ADC(){
			canal = "";
		}
		void canales();
        void lec();
		static void capturar();
		void mostrar();
};

/*Se leen los voltajes*/
void ADC :: lec(){
/*Ciclo while para leer los voltajes*/
	do{
    cout<<"Ingrese un voltaje de 0v a 3.3v para el canal " <<canal<<endl;
    cin>>volt;
/*Se valida que el voltaje este en el rango correcto*/
    if(volt<0 || volt>3.3){
      cout<<"ERROR: Voltaje incorrecto"<<endl;
    }
  }while (volt<0 || volt>3.3);
  
/*Calculo del dato para cada resolucion
  8 bits*/
  if(res == 8){
    res2 = (volt*255)/3.3;
  }
//10 bits
  if(res == 10){
  	res2 = (volt*1023)/3.3;
  }
//12 bits
   if(res == 12){
  	res2 = (volt*4095)/3.3;
  }
}

/*Se muestran los datos*/
void ADC :: mostrar(){
	cout<<"\nCanal: "<<canal<<"  Dato convertido: "<<res2<<endl;
}

/*Se capturan los datos*/
void ADC::capturar(){
/*Ciclo while para capturar la resolución*/
	while(res!= 8 && res!= 10 && res!= 12){
	cout<<"Eliga la resolucion en bits (8, 10, 12): ";
	cin>> res;
/*Se valida que el tipo de resolución sea correcto*/
    	if(res!= 8 && res!= 10 && res!= 12){
     	 cout<< "ERROR: Resolución no válida"<<endl;
		}
	}
	cout<<"Ingrese la frecuencia de muestreo: ";
	cin>> frec;
    cout<< "\n";
}

/*Se piden los canales a leer*/
void ADC :: canales(){
  cout<< "Ingrese los canales que se van a leer (AN1 - AN32): "<<endl;
  cin>> canal;
}

/*Se inicializan las variables*/
int ADC :: res=0;  
float ADC :: frec=0;

/*****************
 FUNCION MAIN
*****************/
int main() {

/*Funcion para poder usar el teclado local (acentos, etc.)*/
	setlocale(LC_ALL, "");

/*DATOS PARA LA PORTADA*/
	cout<<"                                 TecNM Campus Chihuahua"<<endl;
	cout<<"                            	  Laboratorio 3 - ADC"<<endl;
	cout<<"                                     Axel Gay Díaz"<<endl;
	cout<<"                                       19060718"<<endl;
	cout<<"                   Arquitectura de Programación para Control de Hardware"<<endl;
	cout<<"                             Docente: Alfredo Chacón Aldama\n"<<endl;
	
	int i, numcan;
	
/*Se capturan la cantidad de canales a leer*/	
	ADC :: capturar();
	cout<<"Ingrese el número de canales a leer: ";
	cin>>numcan;

	ADC lec[numcan];

/*Ciclos for para el uso de métodos*/
	for(int i=0; i<numcan; i++){
			lec[i].canales();
	}

	for(int i=0; i<numcan; i++){
		lec[i].lec();
	}

	for (int i =0; i<numcan; i++){
	    lec[i].mostrar();
	}
	
return 0;
}
