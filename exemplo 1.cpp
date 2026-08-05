#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	float num1, num2;
	
	cout << "digite o primeiro número: " << endl;
	cin >> num1;
	
	cout << "digite o segundo numero: " << endl;
	cin >> num2;
	
	if (num1 > num2) {
		cout << "o maior numero e: " << num1 << endl;
	}
	else if (num2 > num1) {
		cout << "o maior numero e: " << num2 << endl;
	}
	else {
		cout << "os dois numeros sao iguais." << endl;
	}
	
	return 0;
}
