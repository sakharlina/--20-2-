#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251>nul");
	int words;
	string line;
	ifstream input("File1.txt");
	ofstream output("File2.txt");

	if (!input.is_open())
	{
		cout << "Файл для чтения не открыт." << endl;
		return 0;
	}
	else cout << "Файл для чтения успешно открыт." << endl;

	for (int i = 1; !input.eof(); i++)
	{
		getline(input, line);

		words = 1;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
			{
				words++;
			}
		}

		if (words > 2)
		{
			output << line << endl;
		}
	}
	input.close();

	ifstream instring("File2.txt");
	int num, max = 0, word, k, e, b = 0;
	char m[30]; //Строка для слова с максимальным количеством гласных
	char str[30]; //Строка для обработки каждого слова

	while (!instring.eof())
	{
		word = 1;
		e = 0;

		getline(instring, line);

		for (int j = 0; j < line.length(); j++)
			if (line[j] == ' ')
			{
				word++;
				b++;
			}

		for (int i = 0; i < word; i++)
		{
			k = 0;
			num = 0;
			while (line[e] != ' ' && e < line.length()) //Посимвольно переписывается одно слово в строку str для обработки
			{
				str[k] = line[e];
				e++;
				k++;
			}
			for (int j = 0; j < k; j++)	if ((str[j] == 'а') || (str[j] == 'о') || (str[j] == 'у') || (str[j] == 'ы') || (str[j] == 'и')
				|| (str[j] == 'э') || (str[j] == 'ю') || (str[j] == 'я') || (str[j] == 'е') || (str[j] == 'ё'))
				num++;

			if (max < num)
			{
				b = 0;
				max = num;
				for (int j = 0; j < 30; j++) m[j] = ' '; //Затирает строку от остаточных символов
				for (int j = 0; j < k; j++) m[j] = str[j]; //В случае, если в текущем слове больше гласных, чем в слове с их наибольшим количеством, сохраняет новое слово из строки str
			}
			for (int j = 0; j < 30; j++) str[j] = ' '; //Затирает строку str, чтобы новое слово вводилось в чистую строку
			e++; //Перескакивает через пробел в строке line со всеми словами
		}
	}
	cout << "Программа успешно завершила работу." << endl;

	cout << "Номер слова, которое содержит наибольшее количество гласных букв: " << b << endl;
	cout << "Содержит " << max << " гласных букв." << endl;

	instring.close();
	output.close();
}
