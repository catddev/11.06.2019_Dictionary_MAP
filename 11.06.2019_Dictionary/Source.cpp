#include<map>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//1.	Используя контейнер map реализовать программу – словарь.
//Основные возможности :
//-поиск слова;
//-добавление, удаление, редактирование слов;
//-чтение и запись словаря в файл.

int main() {
	map<string, string> dic;
	ifstream in("Dictionary.txt");

	string key, value;
	while (!in.eof()) {
		getline(in, key, '#');
		getline(in, value, '#');
		in.ignore();
		cout << key << " " << value << endl;
	}




	system("pause");
	return 0;
}