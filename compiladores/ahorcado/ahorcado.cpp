#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string palabra_original;
string palabra_mostrar;
string nombre_jugador;
int vidas;
int optHelp;

void mostrar();
void ingresar(char x);
void inicializar();
void intento1();
void intento2();
void intento3();
void intento4();
void intento5();
void intento6();
void intento7();
void intento8();
void intento9();
void dibujar_muneco();
int obtener_numero_aleatorio(int b);
int menuHelp();
string obtener_palabra_aleatoria();
vector <string> obtener_colleccion_de_palabras();

int main()
{
	inicializar();
	mostrar();
	while(vidas > 0 && palabra_mostrar != palabra_original) {
		char x;
		cin >> x;
		ingresar(x);
		mostrar();
		optHelp = menuHelp();
	}
	
	
	if (vidas > 0) {
		cout << "ganaste " << endl;
	} else { 
		cout << "perdiste, la palabra era:" << palabra_original << endl;
	}
}

void mostrar()
{
	cout << "Vidas: " << vidas << endl;
	cout << palabra_mostrar << endl;
	dibujar_muneco();
}

void inicializar()
{
	vidas = 10;
	palabra_original = obtener_palabra_aleatoria();
	
	// convertimos la palabra original en miniscula
	for (int i = 0; i < palabra_original.length(); i++)
	{
		if (palabra_original[i] >= 'A' && palabra_original[i] <= 'Z') 
		{
			palabra_original[i]+=32;
		}
	}
	
	for (int i = 0; i < palabra_original.length(); i++)
	{
		if (palabra_original[i] >= 'a' && palabra_original[i] <= 'z') 
		{
			palabra_mostrar+='\n -';
		} else {
			palabra_mostrar+= palabra_original[i];
		}
	}
}

void ingresar(char x)
{
	bool perdiVidas = true;
	for (int i = 0; i < palabra_original.length(); ++i)
	{
		if (x == palabra_original[i])
		{
			perdiVidas = false;
			palabra_mostrar[i] = x;
		}
	}
	
	if (perdiVidas)
	{
		vidas--;
	}
}

string obtener_palabra_aleatoria()
{
	vector <string> palabras = obtener_colleccion_de_palabras();
	int numero_aleatorio = obtener_numero_aleatorio(palabras.size());
	return palabras[3];
}

vector <string> obtener_colleccion_de_palabras()
{
	vector<string> palabras;
	ifstream file_input_stream("palabras.txt");

	string palabra;
	while (file_input_stream >> palabra) {
		palabras.push_back(palabra);
	}
	file_input_stream.close();
	/*palabras.push_back("palabra");
	palabras.push_back("cama");
	palabras.push_back("computador");
	palabras.push_back("bateria");
	palabras.push_back("carro rojo");
	*/
	return palabras;
}

int obtener_numero_aleatorio(int b)
{
	srand(time(0));
	int numero_aleatorio = rand();
	return numero_aleatorio % b;
}

void dibujar_muneco()
{
	switch(vidas) {
		case 1:
			intento1();
			break;
		case 2:
			intento2();
			break;
		case 3:
			intento3();
			break;
		case 4:
			intento4();
			break;
		case 5:
			intento5();
			break;
		case 6:
			intento6();
			break;
		case 7:
			intento7();
			break;
		case 8:
			intento8();
			break;
		case 9:
			intento9();
			break;
	}
}

void intento9()
{
	cout<<"____________" <<endl;
}

void intento8()
{
	cout<<"____________"<<endl;
	cout<<"|         "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|           "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
}

void intento7()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|           "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
}

void intento6()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|           "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|--------------"<<endl;
}

void intento5()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|        \\"<<endl;
	cout<<"|         \\"<<endl;
	cout<<"|          \\"<<endl;
	cout<<"|--------------"<<endl;
}

void intento4()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|           "<<endl;
	cout<<"|      / \\"<<endl;
	cout<<"|     /   \\"<<endl;
	cout<<"|    /     \\"<<endl;
	cout<<"|--------------"<<endl;
}

void intento3()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|       |  "<<endl;
	cout<<"|       |  "<<endl;
	cout<<"|       |   "<<endl;
	cout<<"|      / \\"<<endl;
	cout<<"|     /   \\"<<endl;
	cout<<"|    /     \\"<<endl;
	cout<<"|--------------"<<endl;
}

void intento2()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|          "<<endl;
	cout<<"|          "<<endl;
	cout<<"|      /|\\ "<<endl;
	cout<<"|     / | \\"<<endl;
	cout<<"|    /  |  \\"<<endl;
	cout<<"|      / \\"<<endl;
	cout<<"|     /   \\"<<endl;
	cout<<"|    /     \\"<<endl;
	cout<<"|--------------"<<endl;
}

void intento1()
{
	cout<<"____________"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|       |"<<endl;
	cout<<"|      ___  "<<endl;
	cout<<"|     (^_^)    "<<endl;
	cout<<"|      /|\\ "<<endl;
	cout<<"|     / | \\"<<endl;
	cout<<"|    /  |  \\"<<endl;
	cout<<"|      / \\"<<endl;
	cout<<"|     /   \\"<<endl;
	cout<<"|    /     \\"<<endl;
	cout<<"|--------------"<<endl;
}

int menuHelp()
{
	int opt;
	cout << "SELECCIONE EL NIVEL DE DIFICULTAD" << endl;
	cout << "1.NOBATO" << endl;
	cout << "2.PRINCIPIANTE" << endl;
	cout << "3.INTERMEDIO" << endl;
	cout << "4.PRO" << endl;
	cout << "5.LEGENDARIO" << endl;
	cin >> opt;
	return opt;
}