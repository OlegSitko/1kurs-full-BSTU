#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>// ввод выод 
using namespace std;
int _stateMenu;  //переменная для работы с меню


void Menu() {
	
	cout << "Выберите действие:" << endl
		<< "(1)lb2 Ввод данных" << endl
		<< "(2)lb2 Вывод" << endl
		<< "(3)lb5 Сохранение" << endl
		<< "(4)lb4 Поиск по индексу" << endl
		<< "(5)lb5 Чтение из файла" << endl
		<< "(6)lb6 Удаление клиента" << endl
		<< "(7)lb6 Удаление полное" << endl
		<< "(8)lb6 изменение клмента" << endl
		<< "(9)lb8 поиск подстрок" << endl
		<< "(10)lb7 сортировка по телефону(вставками)" << endl
		<< "(11)lb7 сортировка по фамилии (пузырьковая)" << endl
		<< "(12)lb3 удаление файла" << endl
		<< "(13)lb3 удаление содержимого файла" << endl
		<< "(14)lb9 Бинарный поиск по номеру " << endl
		<< "(0) выход" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}
struct Credit
{
	int interest_rate{}; // процентная ставка
	int time{}; // срок
	string credit_name; // название кредита
};
struct Client
{
	string type_of_property; // собственность
	string addres; // адврес 
	int telephone_number{}; // номер телефона
	string fio; // фио
	Credit credit[9];
};

void remove_file(char filename[])//lb3       удаление содежримого файла
{

	ofstream fout(filename, ios_base::trunc); // открываем файл для удаления содержимого
	fout.close();//закрываем
}
void print_all_struct(Client* t, int kol, int kolvo) //4 lb
													   //выводит на экран базу клиентов и кредитов и тд.
{
	for (int i = 0; i < kol; i++)
	{
		cout << "\n----------------Индекс " << i << " ----------------";
		cout << "\nФИО: " << t[i].fio << "\nТелефон: " << t[i].telephone_number << "\nАдрес: " << t[i].addres << "\n Собственность: " << t[i].type_of_property;
		for (int k = 0; k < kolvo; k++)
		{
			cout << "\n Название кредита: " << t[i].credit[k].credit_name << "\n Срок: " << t[i].credit[k].time << "\nПроцентная ставка: " << t[i].credit[k].interest_rate;
		}
	}
}
void findin(Client* t, int index, int kolvo)
{
	for (int i = 0; i <= index; i++)//линейный поиск по индексу, берем индекс нашего клиента и тупо сравниваем со всеми другими
	{
		if (i == index) {
			cout << "\n----------------Индекс " << i << " ----------------";
			cout << "\nФИО: " << t[i].fio << "\nТелефон: " << t[i].telephone_number << "\nАдрес: " << t[i].addres << "\n Собственность: " << t[i].type_of_property;
			for (int k = 0; k < kolvo; k++)
			{
			cout << "\n Название кредита: " << t[i].credit[k].credit_name << "\n Срок: " << t[i].credit[k].time << "\nПроцентная ставка: " << t[i].credit[k].interest_rate;
			}
		}
	}
}
void savin(Client* d, int n, string fileName, int l)//5lb сохранение и чтение
{
	// создается поток для записи--------------
	// открывает fileName и делает так, чтобы он был пустой
	ofstream record(fileName, ios::out);


	if (record) { //если файл открыт тогда ...
		record << n << endl;//размерность сутруктуры 

		for (int i = 0; i < n; i++) {
			record << d[i].type_of_property << endl;
			record << d[i].addres << endl;
			record << d[i].telephone_number << endl;
			record << d[i].fio << endl;
			for (int k = 0; k < l; k++)
			{
				record << d[i].credit[k].interest_rate << endl;
				record << d[i].credit[k].time << endl;
				record << d[i].credit[k].credit_name << endl;
			}
		}
		cout << "Данные записаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	record.close();
}
void read(Client* (&d), int& n, string fileName, int l)//5lb
{
	//создаём поток для чтения
	ifstream record(fileName);

	// условие: если файл открылся
	if (record) {
		record >> n;

		d = new Client[n];//динамический массив структур читобы можно было настраивать размер массива 

		for (int i = 0; i < n; i++) {
			record >> d[i].type_of_property;
			record >> d[i].addres;
			record >> d[i].telephone_number;
			record >> d[i].fio;

			for (int k = 0; k < l; k++)
			{
				record >> d[i].credit[k].interest_rate;
				record >> d[i].credit[k].time;
				record >> d[i].credit[k].credit_name;
			}
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	record.close();
}
void Copy(Client* (&d_n), Client* (&d_o), int n)//new massive and old massive данные со старого файла загоняем в новый ФАЙЛ 
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void del(Client* (&d), int& n)//LB6 изменение удаление 
{
	int _n;
	cout << "Введите номер элемента (от 0 до " << n << "): ";
	cin >> _n;
	system("cls");

	if (_n >= 0 && _n < n) {
		// временный массив
		Client* buf = new Client[n];

		Copy(buf, d, n);

		// выделяем новую память
		
		d = new Client[n];
		int q = 0;//новый  ммассив опять индекс

		// заполняем неудаленные данные
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;//был 3 но его место занял 4 
			}
		}

		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введён неверно!" << endl;
}
void Change(Client* (&t), int n, int l)//разименнованный указатель  структуры

{
	int i;
	cout << "Введите номер элемента (от 0 до " << n << "): ";
	cin >> i;
	system("cls");

	// проверка, что ввели правильное значение
	if (i >= 0 && i < n) {
		cout << "\nФамилия: "; cin >> t[i].fio;
		cout << "\nТелефон: "; cin >> t[i].telephone_number;
		cout << "\nАдрес: "; cin >> t[i].addres;
		cout << "\nСобственность: "; cin >> t[i].type_of_property;
		for (int k = 0; k < l; k++)
		{
			cout << "\n Процентная ставка: "; cin >> t[i].credit[k].interest_rate; 
			cout << "\n Срок: "; cin >> t[i].credit[k].time;
			cout << "\n Название кредита: "; cin >> t[i].credit[k].credit_name;
		}

		system("cls");

		cout << "Данные изменены!" << endl;
	}

}
void FindStr(Client* (&a), int n)//lb8
{
	string fio; //переменная нашей подстроки
	cout << "Поиск подстроки в имени: ";
	cin >> fio;
	system("cls");

	for (int i = 0; i < n; i++)
	{
		int l = a->fio.size();//берем размер оригинальной структуры
		int l2 = fio.size();//размер новой стуктуры
		int fg = 0;//переменая отвечающая за индекс
		string x = a[i].fio;//переменна на случай, если ввели в функцию имя препода

		for (int j = 0; j < l; j++) {
			if (j + l2 > l + fg)break;//если сумма больше чем размер слова, идем к следующему слову
			if (fio[fg] != x[j]) //если не совпало, переходим к следующей итерации
			{
				fg = 0;
				continue;
			}
			fg++;//если ничего выше не сработало увеличиваем .... если все попало выводим 
			if (fg == l2)
			{

				cout << "\n----------------Индекс " << i << " ----------------";
				cout << "\nФИО: " << a[i].fio << "\nТелефон: " << a[i].telephone_number << "\nАдрес: " << a[i].addres << "\n Собственность:" << a[i].type_of_property;

				break;

			}
		}
	}
}
void InsertSort(Client* (&t), int n)//lb7 вставочная сортировка
{
	//При сортировке вставками массив разбивается на две области: упорядоченную и и неупорядоченную. 
	//Изначально весь массив является неупорядоченной областью. При первом проходе первый элемент из неупорядоченной
	//области изымается и помещается в правильном положении в упорядоченной области.
	Client key;//запасная структура 
	int i = 0;

	for (int j = 1; j < n; j++) {
		key = t[j];//запасная ровняется ориг
		i = j - 1;//уменьшаем область            отходим на единицу .предыдущий больше того что взяли  ( i-отсортированная . j-предствоит отсортировать).
		while (i >= 0 && t[i].telephone_number > key.telephone_number)//если оригинальный-1, больше копии, цікл выполнятся
		{
			t[i + 1] = t[i];//поменялись 
			i--;// индекс был 2 стал 1
			t[i + 1] = key;// 2 ровняется копии
		}
	}

}
void BubbleSort(Client* (&t), int n)//lb7 пузырьковая 
{
	for (int i = 0; i < n; i++) // принцип сортировки 
		//При пузырьковой сортировке сравниваются соседние элементы и меняются местами, если следующий элемент больше предыдущего.
		//Требуется несколько проходов по данным.Во время первого прохода сравниваются первые два элемента в массиве.
		//Если они не в порядке, они меняются местами и затем сравнивается элементы в следующей паре.При том же условии они так же меняются местами.
		//Таким образом сортировка происходит в каждом цикле пока не будет достигнут конец массива
	{
		for (int j = i + 1; j < n; j++) {
			if (t[i].fio > t[j].fio) {
				//меняем местами элементы
				swap(t[i], t[j]);// меняем 

			}
		}
	}
}

// Бинарный поиск по номеру lb9
int binarSearch(struct Client t[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (t[i].telephone_number > t[j].telephone_number)
			{
				//меняем местами элементы
				swap(t[i], t[j]);
			}
		}
	}

	int left, right, middle, index;
	left = 0; right = n;//границы поиска
	middle = 0;
	cout << "Введите номер, который нужно найти: ";
	cin >> index;
	while (1) {
		middle = (left + right) / 2;
		if (index < t[middle].telephone_number) {
			right = middle - 1;
		}
		else if (index > t[middle].telephone_number) {
			left = middle + 1;
		}
		else {
			cout << "Элемент с таким номером найден в ячейке с номером " << ++middle << endl;
			system("pause");
			break;
		}
		if (left > right) {
			cout << "Такого элемента нету" << endl;
			return -1;
			Menu();
		}
	
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int in, size, size2, x{};
	cout << "Введите количество клиентов:\n";
	cin >> size;
	Client* t = new Client[size];//динамический массив
	cout << "Введите количество кредитов:\n";
	cin >> size2;
	int* p = new int[size2];
	char filename[80];
	Menu();
	while (_stateMenu != 0) {

		switch (_stateMenu)
		{
		case 1: // добавление клиента
			system("cls"); // очистка консоли

			for (int i = 0; i < size; i++)
			{
				cout << "\nФИО: "; cin >> t[i].fio;			
				cout << "\nАдрес: "; cin >> t[i].addres;
				cout << "\nНомер телефона: "; cin >> t[i].telephone_number;
				cout << "\nСобственность: "; cin >> t[i].type_of_property;
				for (int k = 0; k < size2; k++)
				{
					cout << "\nПроцентная ставка по кедиту: "; cin >> t[i].credit[k].interest_rate;
					cout << "\nСрок по ркедиту: "; cin >> t[i].credit[k].time;
					cout << "\nНазвание кредита: "; cin >> t[i].credit[k].credit_name;
				}
			}
			system("pause"); // задержка консоли
			system("cls");
			Menu();
			break;
		case 2://вывод
			system("cls");

			print_all_struct(t, size, size2);
			cout << "\nДанные выведены!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 3://сохранение 
			system("cls");
			cout << "Введите название файла: ";
			cin >> filename;
			savin(t, size, filename, size2);
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:// поиск по индексу 
			system("cls");
			cout << "Какой индекс вывести? ";
			cin >> in;
			findin(t, in, size2);
			system("pause");
			system("cls");
			Menu();
			break;
		case 5: //чтение из файла 
			system("cls");
			read(t, size, filename, size2);
			system("pause");
			system("cls");
			Menu();
			break;
		case 6://удаление преподователя 
			system("cls");
			if (size != 0) {
				del(t, size);
			}
			else
				cout << "Данные пусты!" << endl;
			
			system("pause");
			system("cls");
			Menu();
			break;
		case 7: //полное удаление
			size = 0;
			delete[]t;//удаляем всю память выделенную под t(структруу) 
			t = new Client[size];
			system("pause");
			system("cls");

			Menu();
			break;
		case 8://изменение
			if (size != 0) {//не пишем  индекс потому что в самой функции есть поиск по индексу
				Change(t, size, size2);
				system("pause");
				system("cls");
				Menu();
				break;
			}
			else
			{
				cout << "Данные пусты!" << endl;
				break;
			}

		case 9:
			FindStr(t, size);
			system("pause");
			system("cls");
			Menu();
			break;
		case 10:
			BubbleSort(t, size);
			system("pause");
			system("cls");
			print_all_struct(t, size, size2);
			cout << "\nДанные выведены!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 11:
			InsertSort(t, size);
			system("pause");
			system("cls");
			print_all_struct(t, size, size2);
			cout << "\nДанные выведены!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		case 12:
			cout << "Введите название файла: ";
			cin >> filename;
			remove(filename);
			system("pause");
			system("cls");
			Menu();
			break;
		case 13:
			remove_file(filename);
			system("pause");
			system("cls");
			Menu();
			break;
		case 14:
			binarSearch(t, size);
			system("pause");
			system("cls");
			Menu();
			break;
		
			
		default:
			system("cls");
			cout << "Неверно введен номер действия!" << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}
}
