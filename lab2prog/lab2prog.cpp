// ГУЛИН А. ПИ-92 Лаб. 4 Ассоциация

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#define LEN 35 // макс. длина строки

class Worker; //объявление класса работника

class Worker //класс работника заповедника (будет вызван классом заповедника Reserve)
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

	//Инициализация
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

	void Read() //ввод
	{
		printf("\nВвод информации о работнике\n");
		printf("Введите номер трудовой книжки: ");
		scanf("%d", &this->num_tr);
		fflush(stdin); //очистка потока
		printf("Введите имя и фамилию: ");
		gets(this->name_surname);
		fflush(stdin); //очистка потока
		printf("Введите должность: ");
		gets(this->dolzh);
		printf("Введите кол-во рабочих часов: ");
		scanf("%d", &this->hours);
		printf("Введите зарплату (в руб.): ");
		scanf("%d", &this->zarpl);
		printf("Введите кол-во прогулов: ");
		scanf("%d", &this->progools);
	}

	//сложение
	void Add(Worker wr1, Worker wr2)
	{
		Worker wrsum;
		wrsum=wr1; //переписать первую структуру в суммарную структуру
		wrsum.hours+=wr2.hours; //прибавить к имеющимся числовым переменным суммарной структуры значения из второй структуры (кроме номера трудовой)
		wrsum.zarpl+=wr2.zarpl;
		wrsum.progools+=wr2.progools;
		this->Init(wrsum.num_tr, wrsum.name_surname, wrsum.dolzh, wrsum.hours, wrsum.zarpl, wrsum.progools); //вернуть итоговую структуру как результат
	}

	//обнуление прогулов (прикладное)
	void Obnul()
	{
		this->progools=0; //обнулить прогулы
	}

	void Izm_zarpl() //изменение зарплаты (прикладное)
	{
		printf("Изменение зарплаты работника\n");
		printf("Введите изменение зарплаты в рублях (отрицательное число для уменьшения зарплаты,\nположительное для прибавки): ");
		int izm; //переменная с прибавкой или убавкой зарплаты
		scanf("%d", &izm);
		this->zarpl+=izm; //добавить изменение к текущей зарплате
	}

	//Получение и установление соответствующих полей
	void set_num(int num)
	{
		this->num_tr=num;
	}
	int get_num()
	{
		return num_tr;
	}

	void set_h(int h)
	{
		this->hours=h;
	}
	int get_h()
	{
		return hours;
	}

	void set_z(int z)
	{
		this->zarpl=z;
	}
	int get_z()
	{
		return zarpl;
	}

	void set_prog(int prog)
	{
		this->progools=prog;
	}
	int get_prog()
	{
		return progools;
	}

	void set_name(char* nam)
	{
		strcpy(this->name_surname, nam);
	}

	char* get_name()
	{
		return this->name_surname;
	}

	void set_dol(char* dol)
	{
		strcpy(this->dolzh, dol);
	}

	char* get_dol()
	{
		return this->dolzh;
	}
};


class Reserve //класс заповедника
{
private: //закрытые методы
	char title[LEN];     //название заповедника
	int budget;          //бюджет заповедника
	int expens;          //расходы
	int kolvow;         //кол-во работников в заповеднике
	Worker workers[LEN]; //работники заповедника

public: //открытые методы
	Reserve() //конструктор без параметров
	{
	}

	~Reserve() //деструктор
	{
	}

	//Инициализация
	void Init(const char* titl, int budg, int exp, int kolv, Worker works[LEN])
	{
		strcpy(this->title, titl);
		this->budget=budg;
		this->expens=exp;
		this->kolvow=kolv;
		for(int i=0; i<kolv; i++)
			this->workers[i]=works[i];
	}

	void Display() //вывод
	{
		printf("\nВывод информации о заповеднике\n");
		printf("Название заповедника: ");
		fflush(stdin); //очистка потока
		puts(this->title);
		printf("Бюджет заповедника (в руб.): ");
		printf("%d\n", this->budget);
		printf("Расходы заповедника (в руб.): ");
		printf("%d\n", this->expens);
		printf("Кол-во работников в заповеднике: ");
		printf("%d\n", this->kolvow);
		int n = this->kolvow; //получить кол-во работников
		for(int i=0; i<n; i++)
		{
			printf("\nРаботник %d\n", i+1);
			printf("Номер трудовой книжки: ");
			printf("%d\n", workers[i].get_num());
			fflush(stdin); //очистка потока
			printf("Имя и фамилия: ");
			puts(workers[i].get_name());
			fflush(stdin); //очистка потока
			printf("Должность: ");
			puts(workers[i].get_dol());
			printf("Кол-во рабочих часов: ");
			printf("%d\n", workers[i].get_h());
			printf("Зарплата (в руб.): ");
			printf("%d\n", workers[i].get_z());
			printf("Кол-во прогулов: ");
			printf("%d\n", workers[i].get_prog());
		}
	}

	void Read() //ввод
	{
		printf("\nВвод информации о заповеднике\n");
		fflush(stdin); //очистка потока
		printf("Введите название: ");
		gets(this->title);
		printf("Введите бюджет заповедника (в руб.): ");
		scanf("%d", &this->budget);
		printf("Введите расходы заповедника (в руб.): ");
		scanf("%d", &this->expens);
		printf("Введите кол-во работников в заповеднике: ");
		scanf("%d", &this->kolvow);
		int n_k = this->kolvow;
		for(int i=0; i<n_k; i++)
			this->workers[i].Read();
	}

	void Add(Reserve r1, Reserve r2) //сложение
	{
		Reserve rsum;
		rsum=r1; //переписать первую структуру в суммарную структуру
		rsum.budget+=r2.budget; //прибавить к имеющимся числовым переменным суммарной структуры значения из второй структуры
		rsum.expens+=r2.expens;
		rsum.kolvow+=r2.kolvow;
		this->Init(rsum.title, rsum.budget, rsum.expens, rsum.kolvow, rsum.workers); //вернуть итоговый объект как результат
	}

	void ZarplChange() //изменение бюджета (прикладное)
	{
		printf("Изменение зарплаты всех работников\n");
		printf("Введите изменение зарплаты в рублях (отрицательное число для уменьшения,\nположительное для прибавки): ");
		int izm; //переменная с прибавкой или убавкой
		scanf("%d", &izm);
		int n = this->kolvow; //получить кол-во работников
		for(int i=0; i<n; i++)
		{
			workers[i].set_z(workers[i].get_z()+izm); //добавить изменение к текущему
		}
	}
	
	void BudgChange() //изменение бюджета (прикладное)
	{
		printf("Изменение бюджета заповедника\n");
		printf("Введите изменение бюджета в рублях (отрицательное число для уменьшения,\nположительное для прибавки): ");
		int izm; //переменная с прибавкой или убавкой
		scanf("%d", &izm);
		this->budget+=izm; //добавить изменение к текущему
	}

	int get_kolvo() //получение значения кол-ва работников
	{
		return kolvow;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток ввода)
	SetConsoleOutputCP(1251); // для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток вывода)


	printf("Программа для работы с информацией о работниках заповедника и самих заповедниках.\n");
	Reserve res1;
	res1.Read();
	res1.Display();
	res1.ZarplChange();
	res1.Display();
	res1.BudgChange();
	res1.Display();

	printf("\nРАБОТА С ДИНАМИЧЕСКИМ ОБЪЕКТОМ.\n");

	Worker wrkk[2]; //массив работников для инициализации заповедника
	wrkk[0].Init(12345, "Иванов Иван", "Егерь", 200, 15000, 2);
	wrkk[1].Init(54321, "Сидоров Семён", "Зоолог", 150, 19000, 1);

	Reserve* resd = new Reserve();
	(*resd).Init("Байкал", 3500000,400000, 2, wrkk);
	resd->Display();
	resd->ZarplChange();
	resd->Display();

	delete resd;




	/*
	Worker wrk1; //объявление тестового объекта для демонстрации работы функций
	printf("\nПЕРВЫЙ РАБОТНИК (ИНИЦИАЛИЗИРОВАННЫЙ)\n");
	wrk1.Init(12345, "Иванов Иван", "Егерь", 200, 15000, 2); //инициализация
	wrk1.Display(); //вывод

	Worker wrk2; //объявление тестового объекта для демонстрации работы функций
	printf("\nВТОРОЙ РАБОТНИК\n");
	wrk2.Read(); //ввод
	wrk2.Display(); //вывод

	printf("\nСЛОЖЕНИЕ РАБОТНИКОВ.\nРезультат: Одному работнику добавляются часы, зарплата и прогулы другого работника\n");
	Worker wrk3;
	wrk3.Add(wrk1, wrk2); //сложение первого и второго объекта в третий объект
	wrk3.Display(); //вывод

	printf("\nОБНУЛЕНИЕ ПРОГУЛОВ ПОСЛЕДНЕГО РАБОТНИКА\n");
	wrk3.Obnul(); //обнуление прогулов
	printf("\nРЕЗУЛЬТАТ ОБНУЛЕНИЯ:\n");
	wrk3.Display(); //вывод

	printf("\nИЗМЕНЕНИЕ ЗАРПЛАТЫ ЭТОГО РАБОТНИКА\n");
	wrk3.Izm_zarpl();
	printf("\nРЕЗУЛЬТАТ ИЗМЕНЕНИЯ:\n");
	wrk3.Display(); //вывод

	//работа с динамическим объектом
	printf("\nДИНАМИЧЕСКИЙ РАБОТНИК 1 (С ИНИЦИАЛИЗ. ДАННЫМИ)\n");
	Worker* wor1 = (Worker*)calloc(1, sizeof(Worker));
	(*wor1).Init(54321, "Сидоров Семён", "Зоолог", 150, 19000, 1); //инициализация
	(*wor1).Display();

	free(wor1);

	printf("\nДИНАМИЧЕСКИЙ РАБОТНИК 2\n");
	Worker* wor2 = (Worker*)malloc(sizeof(Worker));
	(*wor2).Read();
	(*wor2).Display();

	free(wor2);

	//динамический массив
	printf("\nДИНАМИЧЕСКИЙ МАССИВ ИЗ ТРЁХ РАБОТНИКОВ (С ИНИЦИАЛИЗ. ДАННЫМИ)\n");
	Worker* workers = new Worker[3];

	workers[0].Init(11111, "Алексеев Алексей", "Ботаник", 320, 23000, 0);
	workers[1].Init(22222, "Николаев Николай", "Ботаник", 330, 24000, 0);
	workers[2].Init(33333, "Вадимов Вадим", "Ботаник", 290, 19500, 2);
	int i; //счётчик
	for (i=0; i<3; i++)
	{
		printf("\nРАБОТНИК %d\n", i+1);
		workers[i].Display();
	}

	//массив динамических объектов
	printf("\nМАССИВ ДИНАМИЧЕСКИХ ОБЪЕКТОВ ИЗ ТРЁХ РАБОТНИКОВ (С ИНИЦИАЛИЗ. ДАННЫМИ)\n");
	Worker** workerss = new Worker * [3];
	int j; //счётчик
	for (j=0; j<3; j++)
	{
		workerss[j] = new Worker();
		workerss[j]->Init(99999, "Безымянный Работник", "Дворник", 400, 9000, 0);
		printf("\nРАБОТНИК\n");
		workerss[j]->Display();
		workers[j].Add(workers[j], *workerss[j]); //сложить данные этого работника и работника из предыдущего массива и присвоить последнему
		printf("\nРЕЗУЛЬТАТ ПЕРЕНОСА ОБЯЗАННОСТЕЙ ЭТОГО РАБОТНИКА\nРАБОТНИКУ ИЗ ПРЕДЫДУЩЕГО МАССИВА\n", i+1);
		workers[j].Display();
	}
	int k; //счётчик
	for(k=0; k<3; k++)
		delete workerss[k];

	delete[] workerss;
	delete[] workers;

	*/

	printf("\nНажмите любую клавишу для выхода из программы...\n");
	_getch();
	return 0;
}
