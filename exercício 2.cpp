#include <iostream>

using namespace std;

class Pessoa {
private:
	string nome_;
	int idade_;
	string email_;
	string telefone_;
	
public:
	Pessoa(string nome, int idade, string email, string telefone);
	Pessoa(string nome, int idade, string email);
	Pessoa();
	
	void exibir_info();
};

int main () {
	setlocale(LC_ALL, "portuguese");
	
	Pessoa pessoa1("Ana", 18, "ana@gmail.com", "48 999999999");
	Pessoa pessoa2("Lara", 18, "lara@gmail.com");
	Pessoa pessoa3;
	
	pessoa1.exibir_info();
	pessoa2.exibir_info();
	pessoa3.exibir_info();
	
	return 0;
}

Pessoa::Pessoa(string nome, int idade, string email, string telefone):
	nome_(nome), idade_(idade), email_(email), telefone_(telefone){}
Pessoa::Pessoa(string nome, int idade, string email):
	nome_(nome), idade_(idade), email_(email), telefone_("Não definido"){}	
Pessoa::Pessoa():
	nome_("Não definido"), idade_(0), email_("Não definido"), telefone_("Não definido"){}	
	
void Pessoa::exibir_info() {
	cout << "Nome: " << nome_ << endl;
	cout << "Idade: " << idade_ << endl;
	cout << "E-mail: " << email_ << endl;
	cout << "Telefone: " << telefone_ << endl;
}
