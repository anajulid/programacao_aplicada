#include <iostream>

using namespace std;

class ContaBancaria {
private:
	double saldo_;
	double limite_;
	string senha_;
	string titular_;

public:
	ContaBancaria (string titular, double saldo, double limite, string senha);
	
	void depositar(double valor);
	
	void sacar(double valor, string sen);
	
	void transferir(double valor, string sen);
	
	double getSaldo();
};

int main (){
	setlocale(LC_ALL, "portuguese");
    
    ContaBancaria minhaConta1 ("Ana", 0, 1000, "1234");
	minhaConta1.depositar(100);
	cout << "Depósito bem sucedido. Saldo atual: R$ " << minhaConta1.getSaldo() << endl;
	minhaConta1.sacar (50,"1234");
	cout << "Saque bem sucedido. Saldo atual: R$ " << minhaConta1.getSaldo() << endl;
	
	ContaBancaria minhaConta2 ("Lara", 100, 1000, "2468");
	minhaConta2.sacar (2000,"2468");
	minhaConta2.transferir (2000, "2468");
	
	return 0;
}


ContaBancaria::ContaBancaria(string titular, double saldo, double limite, string senha):
	titular_(titular), saldo_(saldo), limite_(limite), senha_(senha){}

	void ContaBancaria::depositar(double valor) {
		saldo_ += valor;
	}
	
	void ContaBancaria::sacar(double valor, string senha){
		if ((saldo_ + limite_ >= valor) && (senha_ == senha)){
			saldo_ -= valor;
		}
		else{
			cout << "Senha ou valor incompatível.";
		}
	}
	
	void ContaBancaria::transferir(double valor, string senha){
		if ((saldo_ + limite_ >= valor) && (senha_ == senha)){
			saldo_ -= valor;
		}
		else{
			cout << "Senha ou valor incompatível.";
		}
	}
	
	double ContaBancaria::getSaldo() {
		return saldo_;
	}
