#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int mcd(int,int);

int main() {
	
	int option = 0;
	while(option != 4){
		cout<<"1.Funcion de Euler"<<endl<<"2.Triangulo de Pascal"<<endl<<"3.Juego"<<endl<<"4.Salir"<<endl<<"Ingrese la opcion a ejecutar: "<<endl;
		cin>>option;
		switch(option){
			case 1:{
				int contador = 0;
				int bandera = 1;
				int mod;
				int num;
				cout<<"Ingrese un numero: ";
				cin>>num;
				while(num<=0){
					cout<<endl<<"El Numero ingresado debe ser mayor que 0"<<endl;
					cout<<"Ingrese un numero: ";
					cin>>num;
				}//fin while de validacion.
				
				while(bandera <= num){
					
					if(mcd(num,bandera) == 1)
						contador++;
					bandera++;	
				}
				
				
				
				cout<<"El Resultado es: "<<contador<<endl;
				break;
			}
			
			case 2:{
				int num;
				cout<<"Ingrese un numero: ";
				cin>>num;
				while(num<=0){
					cout<<endl<<"El Numero ingresado debe ser mayor que 0"<<endl;
					cout<<"Ingrese un numero: ";
					cin>>num;
				}//fin while de validacion.
				break;
			}
			
			case 3:{//simalacion del juego
				int player1 = 0;
				int player2 = 0;
				int size;
				cout<<"Ingrese el tamaño del Arreglo(Debe ser Par): ";
				cin>>size;
				while(size%2 != 0){
					cout<<endl<<"El numero ingresado no es par o es menor que 0"<<endl;
					cout<<"Ingrese el tamaño del Arreglo(Debe ser Par): ";
					cin>>size;
				}
				int num_random;
				srand(time(NULL));
				int array[size] = {};
				int array2[size] = {};
				for(int i = 0; i<size; i++){
					num_random = -50 + rand() % (51-(-50));
					
					array[i] = num_random;
					array2[i]=num_random;
				}
				
				int turnos = size/2;
				int cont = 0;
				
				int posicion;
				cout<<endl<<"¡QUE EMPIECE EL JUEGO!"<<endl<<endl;
				while(cont < turnos){
					
					cout<<"J1 Escoge: ";
					cin>>posicion;
					while(array2[posicion] == -100 || posicion > size){
						cout<<"Esta casilla ya fue elegida previamente o La posicion no existe"<<endl;
						cout<<"J1 Escoge: ";
						cin>>posicion;
					}//validacion que haya escogido otra casilla
					cout<<endl<<"Obtuvo: "<<array2[posicion]<<endl;
					player1 += array2[posicion];
					array2[posicion] = -100;
					cout<<"J2 Escoge: ";
					cin>>posicion;
					while(array2[posicion] == -100 || posicion > size){
						cout<<"Esta casilla ya fue elegida previamente o La posicion no existe"<<endl;
						cout<<endl<<"J2 Escoge: ";
						cin>>posicion;
					}//validacion que haya escogido otra casilla
					cout<<endl<<"Obtuvo: "<<array2[posicion]<<endl;
					player2 += array2[posicion];
					array2[posicion] = -100;
					cout<<endl<<"Ronda "<<cont + 1<<" - "<<"[PTS J1: "<<player1<<" <-> "<<" PTS J2: "<<player2<<"]"<<endl;
					
					
					
					cont++;
				}//fin del while
				cout<<endl<<"FINAL "<<" - "<<"[PTS J1: "<<player1<<" <-> "<<" PTS J2: "<<player2<<"]"<<endl;
				if(player1 > player2)
					cout<<"GANA J1"<<endl;
				else if(player1 == player2)
					cout<<"EMPATE"<<endl;
				else
					cout<<"GANA J2"<<endl;
					
				cout<<endl<<"Arreglo usado: [";
				for(int i = 0; i < size; i++){
					cout<<array[i]<<" ";
				}
				cout<<"]"<<endl;
				break;
			}
			
			case 4:{
				break;
			}
		}//fin del switch
	}//fin del while
	return 0;
}



int mcd(int a,int b){
	int resultado;
	for(int i = 1; i <= b;i++){
		if(a % i == 0 && b % i == 0 )
			resultado = i;
	}	
	return resultado;
}
