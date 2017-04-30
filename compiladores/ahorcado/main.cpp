#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void welcome();
void caracter();
void intentos();
void mostrar_cabeza();
void mostrar_tronco();
void mostrar_brazos();
void mostrar_piernas();
void menu_help();
void help();

int main() {
	char frase[60],rep[100],temporal[100];
	char pal;
	int longitud,i,j,inicial,acertado=0,temp=0,oportunidades = 6;
	int repetido=0,gano=0, ayuda, optionhelp;

	welcome();
	caracter();
	scanf("%s", frase);
	system("cls");
	
	longitud = 0;
	inicial = 0;
	j = 0;
	
	rep[0] = ' ';
	rep[1] = '\0';
	
	
	do {
		system("cls");
		temp=0;
		
		if(inicial == 0) {
			for(i=0;i<strlen(frase);i++) {
				if(frase[i] == ' ') {
					temporal[i] = ' ';
					longitud++;
				}
				else {
					temporal[i] = '_';       
					longitud++;
				}
			}
		}
		
		inicial = 1;
		
		temporal[longitud] = '\0';
		
		for(i=0;i<strlen(rep);i++) {
			if(rep[i] == pal) {
				repetido = 1;
				break;
			}
			else {
				repetido = 0;
			}
		}
		
		if(repetido == 0) {
			for(i=0;i<strlen(frase);i++) {
				if(frase[i] == pal) {
					temporal[i] = pal;
					acertado++;
					temp=1;
				}
			}
		}
		
		if(repetido == 0) {
			if(temp == 0) {
				oportunidades = oportunidades - 1;
				// printf("%d \n", oportunidades);
			}
		}
		else {
			printf("Ya se ha introducido este caracter");
			printf("\n\n");
		}
		
		printf("\n");
		
		for(i=0;i<strlen(temporal);i++) {
			printf(" %c ",temporal[i]);
		}
		
		printf("\n");
		
		if(strcmp(frase,temporal) == 0) {
			gano = 1;
			break;
		}
		
		printf("\n");
		printf("Letras Acertadas: %d",acertado);
		printf("\n");
		printf("Oportunidades Restantes: %d",oportunidades);
		printf("\n");
		/*switch(oportunidades) {
			case 4: viewError1();
				break;
			default:
				cout << "No tiene mas oportunidades";
				break;
		}*/

		switch (oportunidades) {
			case 4: mostrar_cabeza();
				break;
			case 3: mostrar_tronco();
				break;
			case 2: mostrar_brazos();
				break;
			case 1: mostrar_piernas();
				break;
		}
		
		rep[j] = pal;
		j++;
		
		if (oportunidades==0)
		{
			break;
		}
		
		printf("Introduzca una letra:");
		scanf("\n%c",&pal);
		
	}while(oportunidades != 0);
	
	
	if(gano) {
		printf("\n\n");
		printf("Felicitaciones!! Adivinaste la palabra.");
	}
	else {
		printf("\n\n");
		printf("Perdiste :(, pero puedes volver a intentarlo");
	}
	
	printf("\n\n");
	system("PAUSE");
	return 0;
	
}

void welcome () {
	cout << "-------------------------------------------------------------- \n" << endl;
	cout << "\t \t Bienvenido (a) al juego del arhocado" << endl;
	cout << "-------------------------------------------------------------- \n" << endl;
}

void caracter ()
{
	cout << "Ingrese palabra o frase a divinar" << endl; 
}

void help()
{
	cout << "Desea utilizar una ayuda" << endl;
	cout << "1. Si " << endl;
	cout << "2. No" << endl;
}

void mostrar_cabeza()
{
	cout << "   \n  " << endl;
	cout << "\t ||||||| \n"
			"\t | . . | \n"
			"\t |__-__|" << endl;
			cout << "   \n  " << endl;
	/*cout << "        _______" << endl;
	cout << "       |       |" << endl;
	cout << "       |       O" << endl;
	cout << "       |      " << endl;
	cout << "       |      " << endl;
	cout << " ______|" << endl;
	cout << "|" << endl;
	cout << "Desea Una Ayuda, SI:1 NO: 0" << endl;*/
}

void mostrar_tronco ()
{
	cout << "   \n  " << endl;
	cout << "\t	||||||| \n"
			"\t | . . | \n"
			"\t |  -  | \n"
			"\t |_____| \n"
			"\t ____||___ \n"
			"\t |        | \n"
			"\t |        | \n"
			"\t |        | \n"
			"\t |________| \n"
			"\t |        | \n"
			"\t |   |    | \n"
			"\t |___|____| \n" << endl;
			cout << "   \n  " << endl;
}

void mostrar_brazos ()
{
	cout << "   \n  " << endl;
	cout << 	  "\t ||||||| \n"
				  "\t | . . | \n"
				  "\t |__-__| \n"
		"\t ________ ____||____________ \n"
		"\t |_______|        |________| \n"
				"\t |        | \n"
				"\t |        | \n"
				"\t |________| \n"
				"\t |        | \n"
				"\t |   |    | \n"
				"\t |___|____| \n" << endl;
				cout << "   \n  " << endl;
}

void mostrar_piernas ()
{
	cout << "   \n  " << endl;
	cout << 	  "\t ||||||| \n"
				  "\t | . . | \n"
				  "\t |__-__| \n"
		"\t ________ ____||____________ \n"
		"\t |_______|        |________| \n"
				"\t |        | \n"
				"\t |        | \n"
				"\t |________| \n"
				"\t |        | \n"
				"\t |   |    | \n"
			"\t ____|___|____| \n"
		   "\t |_____________| \n" << endl;
		   cout << "   \n  " << endl;
}

void menu_help()
{
	cout << "Opcion de ayudas" << endl;
	cout << "Opcion 1: Las Primeras 2 Letras " << endl;
	cout << "Opcion 2: Las Ultimas 2 Letras " << endl;
	cout << "Opcion 3: Mostrar Las Vocales" << endl;
}

