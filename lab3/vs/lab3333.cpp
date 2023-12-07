#include <stdio.h>
#include <locale.h>
#include <Windows.h>
int main(void)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");
	char str[300], p;
	int i, k = 0;

	//printf("Введите строку: ");
	gets_s(str);
	//printf("Вот Ваша строка: %s", str);

	for (i = 0; i <= 300; i++) {
		if ((str[i] == ' ') || (str[i] == 0)) {
			p = str[i - 1];

			str[i - 1] = str[i - k];
			str[i - k] = p;
			k = 0;
		}
		else {
			k++;
		}
	}
	printf("%s", str);
	return 0;

}