#include <iostream>
#include <string>

using namespace std;

int main() {
	string nome;
	int idade;
	
	cout << "Digite seu nome: " << endl;
	getline(cin,nome); // getline é uma configuração pra pegar o espaço quando digitar o nome, tipo em "ana julia"
	cout << "Digite sua idade: " << endl;
	cin >> idade;
	
	cout << "Ola, " << nome << "! Voce tem " << idade << " anos." << endl;
	
	return 0;
}
