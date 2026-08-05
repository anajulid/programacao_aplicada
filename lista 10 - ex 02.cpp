#include <iostream>

using namespace std;

class Retangulo {
private:
	double largura_, comprimento_;
	
public:
	Retangulo (double largura_, double comprimento_);
	Retangulo ();
	
	friend double calcular_area(Retangulo r);
	friend double calcular_perimetro(Retangulo r);

};

int main () {
	setlocale(LC_ALL, "portuguese");
	
	Retangulo r(10, 11);
	
	cout << "área do retângulo: " << calcular_area(r) << endl;
	cout << "perímetro do retângulo: " << calcular_perimetro(r) << endl;
	
	return 0;
}


Retangulo::Retangulo(double largura, double comprimento): 
	largura_(largura), comprimento_(comprimento) {}

Retangulo::Retangulo(){}

double calcular_area(Retangulo r) {
    return r.largura_ * r.comprimento_;
}

double calcular_perimetro(Retangulo r) {
    return (r.largura_ + r.comprimento_) * 2;
}
