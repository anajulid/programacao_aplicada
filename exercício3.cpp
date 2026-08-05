#include <iostream>

using namespace std;

int main() {
	
	float c, f;
	
	cout << "Digite a temperatura em graus Celsius: " << endl;
	cin >> c;
	
	f = c * 9/5 + 32;
	
	cout << "Temperatura em Fahrenheit: " << f << endl;
	
	return 0;
}
