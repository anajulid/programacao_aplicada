#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	int numeros[5];
	int soma = 0;
	
	//entrada de valores
	cout << "digite 5 números: " << endl; //pode colocar dentro do for que roda também
	for (int i = 0; i < 5; i++) {
		cin >> numeros[i];
	}
	
	//cálculo da soma dos elementos do vetor
	for (int i = 0; i < 5; i++) {
		soma = soma + numeros[i];
	}
	
	cout << "a soma dos elementos do vetor é: " << soma << endl;
	
	return 0;
}
