// ГУЛИН А. ПИ-92 Лаб. 2 Структуры языка Си

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#define LEN 35 // макс. длина строки

int init(struct worker wrk); //описание функции инициализации

struct worker //структура для работника заповедника
{
	int num_tr; //номер трудовой книжки
	char name_surname[LEN]; //имя и фамилия
	char dolzh[LEN]; //должность
	int hours; //кол-во рабочих часов
	int zarpl; //зарплата в месяц в рублях
	int progools; //кол-во прогулов (в днях)
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток ввода)
	SetConsoleOutputCP(1251); // для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток вывода)

	printf("Программа для работы с информацией о работниках заповедника.\n");
	struct worker wrk1;
	init(wrk1);
	_getch();
	return 0;
}

//Функция инициализации структуры
int init(struct worker wrk)
{
	wrk.num_tr=0; //Инициализация соответствующих числовых переменных и строк структуры
	wrk.name_surname[0]='\0';
	wrk.dolzh[0]='\0';
	wrk.hours=0;
	wrk.zarpl=0;
	wrk.progools=0;
	return 0;
}
