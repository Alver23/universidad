#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string palabra_original;
string palabra_mostrar;
string nombre_jugador;
int vidas = 10;
int optLevel;
int acertadas = 0;
int points = 0;
int ayuda = 0;

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
void getWordByLevel(int opt);
void helpOne();
void getHelp( int opt);
void isHelp();
int obtener_numero_aleatorio(int b);
int menuLevel();
int menuHelp();
int getPoints(int opt);
string obtener_palabra_aleatoria(string fileName);
string getFile(string fileName);
vector <string> obtener_colleccion_de_palabras(string fileName);
bool nextLevel = false;

int main()
{
	optLevel = menuLevel();
	do
	{
		getWordByLevel(optLevel);
		inicializar();
		mostrar();
		while(vidas > 0 && palabra_original != palabra_mostrar) {
			char x;
			cin >> x;
			ingresar(x);
			mostrar();
			nextLevel = false;
		}
		palabra_mostrar = "";
		optLevel++;
		nextLevel = true;
	} while (optLevel != 6);
	
	if (vidas > 0) {
		cout << "ganaste " << endl;
	} else { 
		cout << "perdiste, la palabra era:" << palabra_original << endl;
	}
}

void mostrar()
{
	int opt;
	cout << "Oportunidades Restantes: " << vidas << endl;
	cout << "Letras Acertadas:" << acertadas << endl;
	cout << "Puntaje:" << points << endl;
	cout << palabra_mostrar << endl;
	dibujar_muneco();
	if (ayuda == 1)
	{
		opt = menuHelp();
		printf("%d la opcion q escojio es \n", opt);
		getHelp(opt);
	}
}

void inicializar()
{	
	//palabra_original = obtener_palabra_aleatoria();
	
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

void getWordByLevel(int opt)
{
	switch (opt) {
		case 1:
			cout << "Nivel 1" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelOne.txt");
			break;
		case 2:
			cout << "Nivel 2" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelTwo.txt");
			break;
		case 3:
			cout << "Nivel 3" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelThree.txt");
			break;
		case 4:
			cout << "Nivel 4" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelFour.txt");
			break;
		case 5:
			cout << "Nivel 5" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelFive.txt");
			break;
		default:
			cout << "opción no valida" << endl;
			break;
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
		points-=optLevel;
		vidas--;

	} else {
		acertadas++;
	}
}

string obtener_palabra_aleatoria(string fileName)
{
	vector <string> palabras = obtener_colleccion_de_palabras(fileName);
	int numero_aleatorio = obtener_numero_aleatorio(palabras.size());
	return palabras[numero_aleatorio];
}

vector <string> obtener_colleccion_de_palabras(string fileName)
{
	vector<string> palabras;
	ifstream file_input_stream(fileName);

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
			isHelp();
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
			isHelp();
			break;
		case 8:
			intento8();
			isHelp();
			break;
		case 9:
			intento9();
			
			break;
	}
}

string getFile(string fileName) {
	return obtener_palabra_aleatoria(fileName);
}

int getPoints(int opt)
{
	int res = 0;
	if (nextLevel)
	{
		res = opt * 10;
	}
	return res;
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

int menuLevel()
{
	int opt;
	cout << "Seleccione el nivel de dificultad por el cual quiere empezar" << endl;
	cout << "1.NOBATO" << endl;
	cout << "2.PRINCIPIANTE" << endl;
	cout << "3.INTERMEDIO" << endl;
	cout << "4.PRO" << endl;
	cout << "5.LEGENDARIO" << endl;
	cin >> opt;
	return opt;
}

int menuHelp()
{
	int opt;
	cout << "Seleccione la ayuda que desea recibir" << endl;
	cout << "1. Primera letra" << endl;
	cout << "2. Ultima letra" << endl;
	cout << "3. Letra aleatoria" << endl;
	return opt;
}

void getHelp(int opt)
{
	switch(opt) {
		case 1:
			helpOne();
			break;
		case 2:
			helpOne();
			break;
		case 3:
			helpOne();
			break;
	}
}

void helpOne()
{
	for (int i = 0; i < palabra_original.length(); ++i)
	{
		cout << "help ne" << i << endl;
		if (i == 1)
		{
			palabra_mostrar[i] = palabra_original[i];
			//ayuda = 0;
			break;
		}
	}
}

void isHelp()
{
	cout << "Desea Una Ayuda ?" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cin >> ayuda;
}