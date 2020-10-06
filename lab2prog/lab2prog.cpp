// ГУЛИН А. ПИ-92 Лаб. 3 Классы и объекты С++

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#define LEN 35 // макс. длина строки

//ОПИСАНИЕ ФУНКЦИЙ
int init(struct worker *wrk); //1 инициализация структуры
int read(struct worker *wrk); //2 ввод структуры
int display(struct worker *wrk); //3 вывод структуры
struct worker add(struct worker *wr1, struct worker *wr2); //4 сложение структур
int obnul(struct worker *wrk); //5 обнуление прогулов (прикладная функция)
int izm_zarpl(struct worker *wrk); //6 Изменение зарплаты (прикладная функция)

class Worker //класс работника заповедника
{
private: //закрытые методы
	int num_tr; //номер трудовой книжки
	char name_surname[LEN]; //имя и фамилия
	char dolzh[LEN]; //должность
	int hours; //кол-во рабочих часов
	int zarpl; //зарплата в месяц в рублях
	int progools; //кол-во прогулов (в днях)
	
public: //открытые методы
	Worker() //конструктор без параметров
	{
	}

	~Worker() //деструктор
	{
	}

	//инициализация
	void Init(int num_trud, const char* name_sur, const char* dolzhno, int hourss, int zarplat, int progoo)
	{
		strcpy(this->name_surname, name_sur);
		strcpy(this->dolzh, dolzhno);
		this->num_tr=num_trud;
		this->hours=hourss;
		this->zarpl=zarplat;
		this->progools=progoo;
	}

	void Display() //вывод
	{
		printf("\nВывод информации о работнике\n");
		printf("Номер трудовой книжки: ");
		printf("%d\n", this->num_tr);
		fflush(stdin); //очистка потока
		printf("Имя и фамилия: ");
		puts(this->name_surname);
		fflush(stdin); //очистка потока
		printf("Должность: ");
		puts(this->dolzh);
		printf("Кол-во рабочих часов: ");
		printf("%d\n", this->hours);
		printf("Зарплата (в руб.): ");
		printf("%d\n", this->zarpl);
		printf("Кол-во прогулов: ");
		printf("%d\n", this->progools);
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток ввода)
	SetConsoleOutputCP(1251); // для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток вывода)

	printf("Программа для работы с информацией о работниках заповедника.\n");
	struct worker wrk1; //объявление тестовой структуры для демонстрации работы функций
	printf("\nПЕРВАЯ СТРУКТУРА\n");
	init(&wrk1); //инициализация
	read(&wrk1); //ввод
	display(&wrk1); //вывод

	struct worker wrk2; //объявление тестовой структуры для демонстрации работы функций
	printf("\nВТОРАЯ СТРУКТУРА\n");
	init(&wrk2); //инициализация
	read(&wrk2); //ввод
	display(&wrk2); //вывод

	printf("\nСЛОЖЕНИЕ ПЕРВОЙ И ВТОРОЙ СТРУКТУР.\nРезультат: третья структура, сохраняющая номер трудовой, имя и фамилию, должность первого работника\nи добавляющая к остальным полям числовые значения второго работника.\nТаким образом, второй работник сокращается и его обязанности и привилегии возлагаются на первого работника.\n");
	struct worker wrk3; //объявление тестовой структуры для демонстрации работы функций
	wrk3=add(&wrk1, &wrk2); //сложение первой и второй структуры (порядок важен!)
	printf("\nРЕЗУЛЬТАТ СЛОЖЕНИЯ - ТРЕТЬЯ СТРУКТУРА:\n");
	display(&wrk3); //вывод получившейся третьей структуры
	printf("\nОБНУЛЕНИЕ ПРОГУЛОВ ПЕРВОГО РАБОТНИКА (ПО ПЕРВОЙ СТРУКТУРЕ)\nРаботник отработал их или уплатил неустойку\n");
	obnul(&wrk1); //обнуление прогулов
	printf("\nРЕЗУЛЬТАТ ОБНУЛЕНИЯ:\n");
	display(&wrk1); //вывод
	printf("\nИЗМЕНЕНИЕ ЗАРПЛАТЫ ВТОРОГО РАБОТНИКА\n");
	izm_zarpl(&wrk2); //изменение зарплаты
	printf("\nРЕЗУЛЬТАТ ИЗМЕНЕНИЯ:\n");
	display(&wrk2); //вывод

	struct worker *tmp=(struct worker*) malloc(sizeof(struct worker)); //создание нового узла
	printf("\nДИНАМИЧЕСКАЯ СТРУКТУРА\n");
	read(tmp); //получить данные в динамическую структуру
	display(tmp); //вывести динамическую структуру
	printf("\nОБНУЛЕНИЕ ПРОГУЛОВ РАБОТНИКА С ДИНАМИЧЕСКОЙ СТРУКТУРОЙ\n");
	obnul(tmp); //обнуление прогулов
	printf("\nРЕЗУЛЬТАТ ОБНУЛЕНИЯ:\n");
	display(tmp); //вывод
	free(tmp); //очистить память от динамической структуры

	printf("\nНажмите любую клавишу для выхода из программы...\n");
	_getch();
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


//функция сложения
struct worker add(struct worker *wr1, struct worker *wr2)
{
	struct worker wrsum; //структура - результат суммы
	wrsum=*wr1; //переписать первую структуру в суммарную структуру
	wrsum.hours+=wr2->hours; //прибавить к имеющимся числовым переменным суммарной структуры значения из второй структуры (кроме номера трудовой)
	wrsum.zarpl+=wr2->zarpl;
	wrsum.progools+=wr2->progools;
	return wrsum; //вернуть итоговую структуру как результат
}

//функция обнуления прогулов
int obnul(struct worker *wrk)
{
	wrk->progools=0; //обнулить прогулы
	return 0;
}

//функция изменения зарплаты
int izm_zarpl(struct worker *wrk)
{
	printf("Изменение зарплаты работника\n");
	printf("Введите изменение зарплаты в рублях (отрицательное число для уменьшения зарплаты,\nположительное для прибавки): ");
	int izm; //переменная с прибавкой или убавкой зарплаты
	scanf("%d", &izm);
	wrk->zarpl+=izm; //добавить изменение к текущей зарплате
	return 0;
}