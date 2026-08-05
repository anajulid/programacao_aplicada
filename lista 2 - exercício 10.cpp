#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	float salario;
	
	cout << "Digite o salário do colaborador: " << endl;
	cin >> salario;
	
	if (salario <= 280) {
		cout << "Seu salário atual é de R$" << salario << endl;
		cout << "Seu aumento salárial será de 20%." << endl;
		cout << "Você receberá um aumento de R$" << 0.2 * salario << endl;
		cout << "Seu novo salário é de R$" << (0.2 * salario) + salario << endl;
	}
	
	if (salario > 280 && salario <= 700) {
		cout << "Seu salário atual é de R$" << salario << endl;
		cout << "Seu aumento salárial será de 15%." << endl;
		cout << "Você receberá um aumento de R$" << 0.15 * salario << endl;
		cout << "Seu novo salário é de R$" << (0.15 * salario) + salario << endl;
	}
	
	if (salario > 700 && salario < 1500) {
		cout << "Seu salário atual é de R$" << salario << endl;
		cout << "Seu aumento salárial será de 10%." << endl;
		cout << "Você receberá um aumento de R$" << 0.1 * salario << endl;
		cout << "Seu novo salário é de R$" << (0.1 * salario) + salario << endl;
	}
	
	if (salario >= 1500) {
		cout << "Seu salário atual é de R$" << salario << endl;
		cout << "Seu aumento salárial será de 5%." << endl;
		cout << "Você receberá um aumento de R$" << 0.05 * salario << endl;
		cout << "Seu novo salário é de R$" << (0.05 * salario) + salario << endl;
	}

	return 0;
}
