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
bool nextLevel = false;
bool help1 = false;
bool help2 = false;
bool help3 = false;

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
void helpTwo();
void helpThree();
void getHelp( int opt);
void isHelp();
int obtener_numero_aleatorio(int b);
int menuLevel();
int menuHelp();
int getPoints(int opt);
string obtener_palabra_aleatoria(string fileName);
string getFile(string fileName);
vector <string> obtener_colleccion_de_palabras(string fileName);

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
			cout << "Escriba una palabra" << endl;
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
	cout << "\n" << endl;
	cout << "Oportunidades Restantes: " << vidas << endl;
	cout << "Letras Acertadas:" << acertadas << endl;
	cout << "Puntaje:" << points << endl;
	cout << palabra_mostrar << endl;
	cout << "\n" << endl;
	switch (ayuda) {
		case 1:
			opt = menuHelp();
			getHelp(opt);
			cout << palabra_mostrar << endl;
			cout << "\n" << endl;
			break;
		default:
			//cout << "Sin ayuda";
			break;
	}
	dibujar_muneco();
	cout << "\n" << endl;
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
			palabra_mostrar+='-';
		} else {
			palabra_mostrar+= palabra_original[i];
		}
	}
}

void getWordByLevel(int opt)
{
	switch (opt) {
		case 1:
			cout << "Nivel 1 (Novato)" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelOne.txt");
			break;
		case 2:
			cout << "Nivel 2 (Principiante)" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelTwo.txt");
			break;
		case 3:
			cout << "Nivel 3 (Intermedio) " << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelThree.txt");
			break;
		case 4:
			cout << "Nivel 4 (Pro)" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelFour.txt");
			break;
		case 5:
			cout << "Nivel 5 (Legendario)" << endl;
			points += getPoints(opt);
			palabra_original = getFile("levelFive.txt");
			break;
		default:
			cout << "opción no valida, comenzara en el nivel 1 (Novato)" << endl;
			palabra_original = getFile("levelOne.txt");
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
		isHelp();

	} else {
		acertadas++;
	}
}

string obtener_palabra_aleatoria(string fileName)
{
	vector <string> palabras = obtener_colleccion_de_palabras(fileName);
	int numero_aleatorio = obtener_numero_aleatorio(palabras.size());
	return palabras[0];
}

vector <string> obtener_colleccion_de_palabras(string fileName)
{
	vector<string> palabras;
	ifstream file_input_stream(fileName);

	string palabra;
	/*while (file_input_stream >> palabra) {
		cout << palabra << endl;
		palabras.push_back(palabra);
	}

	string line;*/
	ifstream myfile (fileName);
	if (myfile.is_open())
	{
		while ( getline (myfile,palabra) )
		{
			palabras.push_back(palabra);
			cout << palabra << '\n';
		}
		myfile.close();
	}
	//file_input_stream.close();
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
	cout << "\n" << endl;
	cout << "|------------------------------------------------------------|" << endl;
	cout << "|Seleccione el nivel de dificultad por el cual quiere empezar|" << endl;
	cout << "|------------------------------------------------------------|" << endl;
	cout << "1.Novato" << endl;
	cout << "2.Principiante" << endl;
	cout << "3.Intermedio" << endl;
	cout << "4.Pro" << endl;
	cout << "5.Legendario" << endl;
	cout << "\n" << endl;
	cin >> opt;
	return opt;
}

int menuHelp()
{
	int opt;
	cout << "\n" << endl;
	cout << "|------------------------------------------------------------|" << endl;
	cout << "|            Seleccione la ayuda que desea recibir           |"<< endl;
	cout << "|------------------------------------------------------------|" << endl;
	cout << "1. Las dos primeras letras" << endl;
	cout << "2. Las dos ultimas letra" << endl;
	cout << "3. Dos letras aleatoria" << endl;
	cin >> opt;
	return opt;
}

void getHelp(int opt)
{
	switch(opt) {
		case 1:
			if (help1)
			{
				cout << "Usted ya utilizo esta ayuda" << endl;
			} else {
				helpOne();
			}
			break;
		case 2:
			if (help1)
			{
				cout << "Usted ya utilizo esta ayuda" << endl;
			} else {
				helpTwo();
			}
			break;
		case 3:
			if (help1)
			{
				cout << "Usted ya utilizo esta ayuda" << endl;
			} else {
				helpThree();
			}
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
	}
}

void helpOne()
{
	
	palabra_mostrar[0] = palabra_original[0];
	palabra_mostrar[1] = palabra_original[1];
	ayuda = 0;
	help1 = true;
}

void helpTwo()
{
	palabra_mostrar[palabra_original.length() - 1] = palabra_original[palabra_original.length() - 1];
	palabra_mostrar[palabra_original.length() - 2] = palabra_original[palabra_original.length() - 2];
	ayuda = 0;
	help2 = true;
}

void helpThree()
{
	int cont = 0;
	int inicio = obtener_numero_aleatorio(palabra_mostrar.length());
	for (int j = 0; j < palabra_mostrar.length(); j++)
	{

		if (palabra_mostrar[j] == '-')
		{
			if (cont < 2) 
			{
				palabra_mostrar[j] = palabra_original[j];
			}
			cont++;
		}
	}
	//palabra_mostrar[obtener_numero_aleatorio(palabra_original.length())] = palabra_original[obtener_numero_aleatorio(palabra_original.length())];
	ayuda = 0;
	help3 = true;
}

void isHelp()
{
	cout << "\n" << endl;
	cout << "|------------------|" << endl;
	cout << "| Desea Una Ayuda ?|" << endl;
	cout << "|------------------|" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cout << "\n" << endl;
	cin >> ayuda;
}
