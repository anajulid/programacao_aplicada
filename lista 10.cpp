#include <iostream>

using namespace std;

class Complexo {
private:
	int real_;
	int imag_;
	
public:
	Complexo (int real_, int imag_);
	Complexo();
	
	Complexo operator+(Complexo p);
	void exibir_info();
};

int main () {
	setlocale(LC_ALL, "portuguese");
	
	Complexo num1(1, 2);
	Complexo num2(2, 3);
	Complexo num3 = num1 + num2;
	
	num3.exibir_info();
	
	return 0;
}

Complexo Complexo::operator+(Complexo num) {
	real_ = real_ + num.real_;
	imag_ = imag_ + num.imag_;

	return Complexo(real_, imag_);
}

Complexo::Complexo(int real, int imag) : real_(real), imag_(imag) {}

Complexo::Complexo(){}

void Complexo::exibir_info() {
    cout << "(" << real_ << "+" << imag_ << "i)" << endl;
}
