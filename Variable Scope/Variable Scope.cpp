#include <iostream>

using namespace std;

int z = 5; // глобальная переменная

void functionA()
{
	int z = 10; // локальная переменная
	z += 5;
	cout << "Local variable: " << z << endl; 
}

void functionB()
{
	z += 2; // обращение происходит к глобальной переменной z
	cout << "Global variable: " << z << endl;
}

void functionC()
{
	static int z = 10; // статическая переменная создается при первом вызове функции
	z += 5;
	cout << "Static local variable: ";
	cout << z << endl;
}

int main()
{
	int z = 8; // локальная переменная
	cout << "Local variable: " << z << endl;
	{
		int z = 10, s = 2; // локальные переменные
		cout << "Local variable: " << z << endl;
		cout << "Local variable: " << s << endl;
	}
	cout << "Local variable: " << z << endl;
	// cout << "\nLocal variable: " << s; // ошибка компиляции, так как переменная s объявлена в блоке и видна только в нем.
	functionA();
	functionB();
	functionC();
	functionA();
	functionB();
	functionC();
	cout << "Global variable: " << ::z << endl; // обращение к глобальной переменной

	return 0;
}
