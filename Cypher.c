#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
//IMPORTANTE: Revisar tabla assci
//se puede usar la libreria string.h
/*
A: 65
Z: 90

a: 97
z: 122
*/

void cifrar(char mensaje[], int llave);
void leerMensaje(char mensaje[]);
void mostrarMensaje(char mensaje[]);
void leerArgumento(char mensaje[], char argv[]);

int main(int argc, char **argv){
	char mensaje[MAX];
	int llave;
	if (argc == 3){
		llave = atoi(argv[2]);
		if (llave==0 || llave>=26 || llave<=-26){
			printf("No puede ingresar ese valor de llave\n\n");
		}
		else{
			leerArgumento(mensaje,argv[1]);
			cifrar(mensaje,llave);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(mensaje);
		}
	}
	else if (argc == 1){
		printf("Cifrado ciclico\n");
		printf("Ingrese el mensaje a cifrar: ");
		leerMensaje(mensaje);
		printf("Ingrese la llave numerica: ");
		if (scanf("%d", &llave)==0){
			printf("Solo puede ingresar numeros\n\n");
		}else{
			while (llave>=26 || llave<=-26){
				printf("Valor de llave no valido, por favor ingrese nuevamente: "); //validar rango entre -25 y 25
				scanf("%d", &llave);
			}
			cifrar(mensaje,llave);
			printf("\nMensaje cifrado: ");
			mostrarMensaje(mensaje);
		}
	}
	else{
		printf("No puede llamar al programa con esos parametros...\n\n");
	}
	return 0;
}

void leerMensaje(char mensaje[]){
	int i=0;
	char c;
	while ((c=getchar())!='\n'){
			mensaje[i]=c;
			i++;
	}
	mensaje[i]='\0';
}

void leerArgumento(char mensaje[], char argv[]){
	int i=0;
	while (argv[i]!='\0'){
		mensaje[i]=argv[i];
		i++;
	}
	mensaje[i]='\0';
}

void mostrarMensaje(char mensaje[]){
	int i=0;
	while (mensaje[i]!='\0'){
		printf("%c", mensaje[i]);
		i++;
	}
	printf("\n\n");
}

void cifrar(char mensaje[],int llave){
	for (int i=0; i<MAX-1; i++){ //recorre el arreglo de caracteres
		int caracter = (int)mensaje[i];
		if (caracter!='\0'){ //verifica que no sea el ultimo caracter
			if ((caracter>=65 && caracter<=90) || (caracter>=97 && caracter<=122)){
				int suma = caracter + llave;
				if (llave>0){ //para llaves positivas
					if (caracter>=65 && caracter<=90){ //verifica rango de mayusculas
							if (suma > 90)
								caracter = 64 + (suma-90);
							else
								caracter += llave;
					}else{ //rango de minusculas
							if (suma > 122)
								caracter = 96 + (suma-122);
							else
								caracter += llave;
					}
				}else{ //para llaves negativas
					if (caracter>=65 && caracter<=90){ //rango de mayusculas
							if (suma < 65)
								caracter = 91 + (suma-65);
							else
								caracter += llave;
					}else{ //rango de minusculas
							if (suma < 97)
								caracter = 123 + (suma-97);
							else
								caracter += llave;
					}
				}
				mensaje[i]=caracter;
			}
		}else
			break;
	} //cierre for
}
