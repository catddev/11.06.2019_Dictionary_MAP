#include<map>
#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

//1.	Используя контейнер map реализовать программу – словарь.
//Основные возможности :
//-поиск слова;
//-добавление, удаление, редактирование слов;
//-чтение и запись словаря в файл.

int main() {
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dict;
	ifstream in("Dictionary.txt");

	string key, value;
	while (!in.eof()) {
		getline(in, key, '#');
		getline(in, value, '#');
		in.ignore();
		dict[key] = value;
	}

	cout << "Enter 1 to find a word" << endl;
	cout << "Enter 2 to remove a word" << endl;
	cout << "Enter 3 to add a word" << endl;
	cout << "Enter 4 to edit a word" << endl;
	int choice;
	cin >> choice;
	string word;

	switch (choice) {
	case 1:
	{
		cin >> word;
		auto it = dict.find(word);
		if (it != dict.end())
			cout << it->first << " " << it->second << endl;
	}
		break;
	case 2:
	{
		cin >> word;
		auto it = dict.find(word);
		if (it != dict.end())
			dict.erase(it);
	}
		break;
	case 3:
	{
		cin >> key;
		getline(cin, value, '#');
		dict[key] = value;
	}
		break;
	case 4:
	{
		cin >> word;
		auto it = dict.find(word);

		if (it != dict.end())
		{
			cout << it->second << endl;
			getline(cin, value, '#');
			dict[word] = value;
		}
		break;
	}
	}

	cout << "DICTIONARY" << endl;
	for (auto it = dict.begin(); it != dict.end(); it++)
		cout << it->first << " " << it->second << endl;



	system("pause");
	return 0;
}