#include <iostream>

using namespace std;

int main() {
	
	setlocale (LC_ALL, "portuguese");
	
	cout << "Os números ímpares de 1 a 50 são: " << endl;
	
	for (int i = 0; i < 50; ++i) {
		if (i % 2 != 0) {
			cout << i << endl;
		}
	}
	
	return 0;
}
