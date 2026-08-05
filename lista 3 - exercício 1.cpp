#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	int codigo;
	
	cout << "Digite o código para saber o tipo do produto: " << endl;
	cin >> codigo;
	
	switch (codigo) {
		case 1:
			cout << "Alimento não-perecível" << endl;
			break;
		case 2 ... 4:
			cout << "Alimento perecível" << endl;
			break;
		case 5 ... 6:
			cout << "Vestuário" << endl;
			break;
		case 7:
			cout << "Higiene pessoal" << endl;
			break;
		case 8 ... 15:
			cout << "Limpeza e Utensílios Domésticos" << endl;
			break;
		default:
			cout << "Código inválido! por favor, digite um número entre 1 a 15" << endl;
			break;
	}
	
	return 0;
}
