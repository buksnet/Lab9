#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct maxCons {
	int count = 0;
	int position = 0;
};

int countCons(string str)
{
	string cons = "ÁÂÃÄÆÇÊËÌÍÏĞÑÒÉÔÕÖ×ÚÜáâãäæçêëìíïğñòéôõö÷úü";
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < cons.length(); j++) {
			if (str[i] == cons[j])
				count++;
		}
	}
	return count;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream f1("F1.txt");
	ofstream f2("F2.txt");
	string str;
	int count = 0;
	maxCons max;

	while (!f1.eof()) {
		getline(f1, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				count++;
				if (countCons(str) > max.count) {
					max.count = countCons(str);
					max.position = i + 1;
				}
			}
		}
		if (count == 0) {
			f2 << str << endl;
		}
		count = 0;
	}

	f2 << max.position << endl;
	return 0;
}