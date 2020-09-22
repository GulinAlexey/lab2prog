// ГУЛИН А. ПИ-92 Лаб. 2 Структуры языка Си

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#define LEN 35 // макс. длина строки

//ОПИСАНИЕ ФУНКЦИЙ
int init(struct worker *wrk); //инициализация структуры
int read(struct worker *wrk); //ввод структуры
int display(struct worker *wrk); //вывод структуры

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
	struct worker wrk1; //объявление тестовой структуры для демонстрации работы функций
	init(&wrk1); //инициализация
	read(&wrk1); //ввод
	display(&wrk1); //вывод

	printf("\nНажмите любую клавишу для выхода из программы...\n");
	_getch();
	return 0;
}

//Функция инициализации структуры
int init(struct worker *wrk)
{
	wrk->num_tr=0; //Инициализация соответствующих числовых переменных и строк структуры
	wrk->name_surname[0]='\0';
	wrk->dolzh[0]='\0';
	wrk->hours=0;
	wrk->zarpl=0;
	wrk->progools=0;
	return 0;
}

//Функция ввода структуры
int read(struct worker *wrk)
{
	printf("\nВвод информации о работнике\n");
	printf("Введите номер трудовой книжки: ");
	scanf("%d", &wrk->num_tr);
	fflush(stdin); //очистка потока
	printf("Введите имя и фамилию: ");
	gets(wrk->name_surname);
	fflush(stdin); //очистка потока
	printf("Введите должность: ");
	gets(wrk->dolzh);
	printf("Введите кол-во рабочих часов: ");
	scanf("%d", &wrk->hours);
	printf("Введите зарплату (в руб.): ");
	scanf("%d", &wrk->zarpl);
	printf("Введите кол-во прогулов: ");
	scanf("%d", &wrk->progools);

	return 0;
}

//Функция вывода структуры
int display(struct worker *wrk)
{
	printf("\nВывод информации о работнике\n");
	printf("Номер трудовой книжки: ");
	printf("%d\n", wrk->num_tr);
	fflush(stdin); //очистка потока
	printf("Имя и фамилия: ");
	puts(wrk->name_surname);
	fflush(stdin); //очистка потока
	printf("Должность: ");
	puts(wrk->dolzh);
	printf("Кол-во рабочих часов: ");
	printf("%d\n", wrk->hours);
	printf("Зарплата (в руб.): ");
	printf("%d\n", wrk->zarpl);
	printf("Кол-во прогулов: ");
	printf("%d\n", wrk->progools);
	return 0;
}