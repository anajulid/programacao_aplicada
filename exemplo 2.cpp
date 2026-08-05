#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	int dia;
	
	cout << "digite um número de 1 - 7 para descobrir o dia da semana: " << endl;
	cin >> dia;
	
	switch (dia) {
		case 1:
			cout << "domingo" << endl;
			break;
		case 2:
			cout << "segunda" << endl;
			break;
		case 3:
			cout << "terça" << endl;
			break;
		case 4:
			cout << "quarta" << endl;
			break;
		case 5:
			cout << "quinta" << endl;
			break;
		case 6:
			cout << "sexta" << endl;
			break;
		case 7:
			cout << "sábado" << endl;
			break;
		default:
			cout << "número inválido! por favor, digite um número entre 1 e 7" << endl;
			break;
	}
	
	return 0;
}
