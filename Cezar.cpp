#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	setlocale(0, "");
	system("chcp 1251");
	int n, y, x;
	string s;
	char mas[33] = {
		'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
		'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
	cout << "\nСтрока: ";
	getline(cin, s);
	cout << "\nСдвиг: ";
	cin >> n;
	cout << "\nЗашифровать - 1, расшифровать - 0: ";
	cin >> x;
	if (x == 1) {
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 33; j++) {
				if (s[i] == mas[j]) {
					y = (j + n) % 33;
					if (y < 0) {
						s[i] = mas[33 + y];
						break;
					}
					else {
						s[i] = mas[y];
						break;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 33; j++) {
				if (s[i] == mas[j]) {
					y = (j - n) % 33;
					if (y < 0) {
						s[i] = mas[33 + y];
						break;
					}
					else {
						s[i] = mas[y];
						break;
					}
				}
			}
		}
	}
	cout << endl << s << " \n\n";
	return 0;
}

