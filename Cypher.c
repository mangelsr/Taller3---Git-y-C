#include<stdio.h>
#define MAX 10000
//IMPORTANTE: Revisar tabla assci
//se puede usar la libreria string.h
/*
A: 65
Z: 90

a: 97
z: 122
*/

int cifrar(int mensaje, int llave);

int main(int argc, char **argv){
	char mensaje[MAX];
	int llave;

	printf("Cifrado ciclico\n");

	printf("Ingrese el mensaje a cifrar: ");
	scanf("%s",mensaje);

	printf("\nIngrese la llave numerica: ");
	scanf("%d", &llave);

	printf("\n\n[1]: %c\n", mensaje[0]);

	printf("\nMensaje cifrado: \n\n");
	return 0;
}

int cifrar(int mensaje,int llave){
	return (putchar(mensaje+llave));
}
