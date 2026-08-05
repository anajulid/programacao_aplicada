#include <iostream>

using namespace std;

class DataHora {
private:
	string data_;
	float hora_;
	
public:
	DataHora(string data, float hora);
	DataHora(string data);
	DataHora(float hora);
	
	void exibir_info();
};

int main() {
	setlocale(LC_ALL, "portuguese");
	
	DataHora data1("12-10-2005", 20.10);
	DataHora data2("12-10-2024");
	DataHora data3(20.00);
	
	data1.exibir_info();
	data2.exibir_info();
	data3.exibir_info();
	
	return 0;
}

DataHora::DataHora(string data, float hora):
	data_(data), hora_(hora){}
	
DataHora::DataHora(string data):
	data_(data), hora_(00.00){}

DataHora::DataHora(float hora):
	data_("01-01-2000"), hora_(hora){}
	
void DataHora::exibir_info() {
	cout << "Data: " << data_ << endl;
	cout << "Hora: " << hora_ << endl;
}
