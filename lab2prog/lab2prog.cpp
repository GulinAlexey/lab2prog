// ГУЛИН А. ПИ-92 Лаб. 2 Структуры языка Си

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#define LEN 35 // макс. длина строки

struct worker //структура для работника заповедника
{
	int num_tr; //номер трудовой книжки
	char name_surname[LEN]; //имя и фамилия
	char dolzh[LEN]; //должность
	int hours; //кол-во рабочих часов
	int zarpl; //зарплата в месяц в рублях
	int progools; //кол-во прогулов (в днях)
};

struct animal //структура для животного в заповеднике
{
	char name[LEN]; //название вида животного
	int chislen; //численность популяции
	int plotn; //плотность популяции (кол-во особей на км2)
	char status[LEN]; //охранный статус (вымирающий вид или нет)
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	printf("Запуск!\n"); //Это запуск!
	_getch();
	return 0;
}

