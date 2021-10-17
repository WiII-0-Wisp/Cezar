#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char mas[33] = {
		'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т',
		'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' }; // алфавит
		string s, ns;
		bool f = 1, g = 1;
		int n, y;
		char x;
		cout << "Введите строку, состоящую из русских букв нижнего регистра: ";
		getline(cin, s);
		cout << "Введите сдвиг - целое число: ";
		getline(cin, ns);

		if (ns[0] == '-') { // если сдвиг отрицательный
			g = 0;
			ns.erase(0, 1);
		}
		for (int i = 0; i < ns.size(); i++) { // посимвольная проверка сдвига
			if ((ns[i] < 48) || (ns[i] > 57)) {
				f = 0;
			}
		}
		cout << "Зашифровать строку - 1, расшифровать - 0: ";
		cin >> x;
		if ((x != '1') && (x != '0')) { // посимвольная проверка 
			f = 0;
		}
		if (f) { // если данные корректны
			n = stoi(ns); // строка в число
			if (!g) { // если сдвиг отрицателен
				n = -n;
			}
			if (x == '1') { // если зашифровать
				for (int i = 0; i < s.length(); i++) { // пробег по строке
					for (int j = 0; j < 33; j++) { // пробег по алфавиту
						if (s[i] == mas[j]) { // если символ в строке и в алфавите совпали
							y = (j + n) % 33; // здесь плюс
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
				for (int i = 0; i < s.length(); i++) { // если расшифровать
					for (int j = 0; j < 33; j++) { // то же самое, но с минусом
						if (s[i] == mas[j]) {
							y = (j - n) % 33; // а тут минус
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
			cout << endl << s << endl;
		} else {
			cout << "Некорректные данные, попробуйте снова." << endl;
		}
	return 0;
}

