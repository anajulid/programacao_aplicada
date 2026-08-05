#include <iostream>
#include <string>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	float altura;
	string genero;
	
	cout << "Digite sua altura: " << endl;
	cin >> altura;
	cout << "Digite F - Feminino ou M - Masculino: " << endl;
	cin >> genero;

	if (genero == "M" || genero == "m") {
		cout << "Seu peso ideal é: " << (72.7 * altura) - 58 << "kg.";
	}
	if (genero == "F" || genero == "f") {
		cout << "Seu peso ideal é: " << (62.1 * altura) - 44.7 << "kg.";
	}
	
	return 0;
}
