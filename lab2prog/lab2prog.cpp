// ГУЛИН А. ПИ-92 Лаб. 9 Конструкторы

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include <Windows.h>

#define LEN 35 // макс. длина строки
#define NALOGG 0.13 //процент налоговых отчислений (изначально) (для лаб. 8)

using namespace std;

class Worker //класс работника заповедника (будет вызван классом заповедника Reserve)
{
private: //закрытые поля
	int num_tr; //номер трудовой книжки
	string name_surname; //имя и фамилия
	string dolzh; //должность
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
	void Init(int num_trud, string name_sur, string dolzhno, int hourss, int zarplat, int progoo)
	{
		this->name_surname=name_sur;
		this->dolzh=dolzhno;
		this->num_tr=num_trud;
		this->hours=hourss;
		this->zarpl=zarplat;
		this->progools=progoo;
	}

	void Display() //вывод
	{
		printf("\nВывод информации о работнике\n");
		printf("Номер трудовой книжки: ");
		cout << num_tr << endl;
		printf("Имя и фамилия: ");
		cout << name_surname << endl;
		printf("Должность: ");
		cout << dolzh << endl;
		printf("Кол-во рабочих часов: ");
		cout << hours << endl;
		printf("Зарплата (в руб.): ");
		cout << zarpl << endl;
		printf("Кол-во прогулов: ");
		cout << progools << endl;
	}

	void Read() //ввод
	{
		printf("\nВвод информации о работнике\n");
		printf("Введите номер трудовой книжки: ");
		cin >> num_tr;
		printf("Введите имя и фамилию: ");
		cin.clear();
		fflush(stdin);
		getline(std::cin, name_surname);
		printf("Введите должность: ");
		cin.clear();
		fflush(stdin);
		getline(std::cin, dolzh);
		printf("Введите кол-во рабочих часов: ");
		cin >> hours;
		printf("Введите зарплату (в руб.): ");
		cin >> zarpl;
		printf("Введите кол-во прогулов: ");
		cin >> progools;
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
		cin >> izm;
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

	void set_name(string nam)
	{
		this->name_surname=nam;
	}

	string get_name()
	{
		return this->name_surname;
	}

	void set_dol(string dol)
	{
		this->dolzh=dol;
	}

	string get_dol()
	{
		return this->dolzh;
	}
};


class Reserve //класс заповедника
{
private: //закрытые поля
	string title;     //название заповедника
	int budget;          //бюджет заповедника
	int expens;          //расходы
	int kolvow;         //кол-во работников в заповеднике
	Worker workers[LEN]; //работники заповедника
	static double nalog; //процент налоговых отчислений //для лаб. 8

public: //открытые методы
	Reserve() //конструктор без параметров
	{
	}

	~Reserve() //деструктор
	{
	}

	//Инициализация
	void Init(string titl, int budg, int exp, int kolv, Worker works[LEN])
	{
		this->title=titl;
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
		cout << title << endl;
		printf("Бюджет заповедника (в руб.): ");
		cout << budget << endl;
		printf("Расходы заповедника (в руб.): ");
		cout << expens << endl;
		printf("Кол-во работников в заповеднике: ");
		cout << kolvow << endl;
		int n = this->kolvow; //получить кол-во работников
		for(int i=0; i<n; i++)
		{
			printf("\nРаботник %d\n", i+1);
			printf("Номер трудовой книжки: ");
			cout <<  workers[i].get_num() << endl;
			fflush(stdin); //очистка потока
			printf("Имя и фамилия: ");
			cout << workers[i].get_name() << endl;
			fflush(stdin); //очистка потока
			printf("Должность: ");
			cout << workers[i].get_dol() << endl;
			printf("Кол-во рабочих часов: ");
			cout << workers[i].get_h() << endl;
			printf("Зарплата (в руб.): ");
			cout <<  workers[i].get_z() << endl;
			printf("Кол-во прогулов: ");
			cout << workers[i].get_prog() << endl;
		}
	}

	void Read() //ввод
	{
		printf("\nВвод информации о заповеднике\n");
		printf("Введите название: ");
		cin.clear();
		fflush(stdin);
		getline(std::cin, title);
		printf("Введите бюджет заповедника (в руб.): ");
		cin >> budget;
		printf("Введите расходы заповедника (в руб.): ");
		cin >> expens;
		printf("Введите кол-во работников в заповеднике: ");
		cin >> kolvow;
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
		this->Init(rsum.title, rsum.budget, rsum.expens, rsum.kolvow, rsum.workers); //вернуть итоговый объект как результат
	}

	void ZarplChange() //изменение бюджета (прикладное)
	{
		printf("Изменение зарплаты всех работников\n");
		printf("Введите изменение зарплаты в рублях (отрицательное число для уменьшения,\nположительное для прибавки): ");
		int izm; //переменная с прибавкой или убавкой
		cin >> izm;
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
		cin >> izm;
		this->budget+=izm; //добавить изменение к текущему
	}

	static double get_nalog() //получение значения процента налоговых отчислений (для лаб. 8)
	{
		return nalog;
	}

	static void set_nalog(double nalogi) //установление значения процента налоговых отчислений (для лаб. 8)
	{
		nalog=nalogi;
	}

	int get_kolvo() //получение значения кол-ва работников
	{
		return kolvow;
	}

	void set_budg(int budg) //установление значения бюджета
	{
		this->budget=budg;
	}

	void set_exp(int exp) //установление значения расходов
	{
		this->expens=exp;
	}

	void nal_otchisl(double &otchisl) //налоговые отчисления
	{
		otchisl = expens * nalog;
		printf("Налоговые отчисления заповедника (в руб.): ");
		cout << otchisl << endl;
	}

	void this_sohr(int *sohr) // сохранённая (неиспользованная) часть бюджета
	{
		*sohr = budget - expens;
		printf("Неиспользованная часть бюджета: ");
		cout << *sohr << endl;
	}

	static void sravn_kolvow(Reserve r1, Reserve r2) //сравнить два заповедника по кол-ву работников (статический метод) (для лаб. 8)
	{
		if(r1.get_kolvo()>r2.get_kolvo())
		{
			printf("В первом заповеднике больше работников, чем во втором.\n");
		}
		else if (r1.get_kolvo()==r2.get_kolvo())
		{
			printf("Кол-во работников в первом и втором заповедниках одинаково.\n");
		}
		else
		{
			printf("Во втором заповеднике больше работников, чем в первом.\n");
		}
	}

	friend Reserve operator+(Reserve r1, Reserve r2); //дружественная функция

	Reserve& operator++() //увеличение бюджета, первая перегрузка
    {
        this->budget++;
        return *this;
    }
    Reserve operator++(int) //увеличение бюджета, вторая перегрузка
    {
        Reserve re = *this;
        ++*this;
        return re;

    }



};

double Reserve::nalog=NALOGG; //начальное значение налога

Reserve operator+(Reserve r1, Reserve r2) //сложение (отдельная от класса функция)
{
	Reserve rsum;
	rsum=r1; //переписать первую структуру в суммарную структуру
	rsum.set_budg(r1.budget + r2.budget);
	rsum.set_exp(r1.expens + r2.expens);
	return rsum;
}

int main()
{
	double nalogii = 0; //налоговые отчисления
	int sohran = 0; //сохранённая часть бюджета

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);// для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток ввода)
	SetConsoleOutputCP(1251); // для корректной работы с русскими буквами (установка кодовой страницы win-cp 1251 в поток вывода)


	Worker wrkk[2]; //массив работников для инициализации заповедника
	wrkk[0].Init(12345, "Иванов Иван", "Егерь", 200, 15000, 2);
	wrkk[1].Init(54321, "Сидоров Семён", "Зоолог", 150, 19000, 1);


	printf("Программа для работы с информацией о работниках заповедника и самих\nзаповедниках.\n");
	printf("\nРАБОТА СО СТАТИЧЕСКИМ ОБЪЕКТОМ.\n");
	Reserve res1;
	res1.Read();
	res1.Display();
	res1.ZarplChange();
	res1.Display();
	res1.BudgChange();
	res1.Display();

	res1.nal_otchisl(nalogii); //возврат значения через ссылку
	res1.this_sohr(&sohran); //возврат значения через указатель


	printf("\nРАБОТА С ДИНАМИЧЕСКИМ МАССИВОМ ОБЪЕКТОВ ИЗ ДВУХ ЗАПОВЕДНИКОВ.\n");
	Reserve* reses = new Reserve [2];
	for(int dd=0; dd<2; dd++)
	{
		printf("\nЗАПОВЕДНИК %d\n", dd+1);
		reses[dd].Read();
		reses[dd].Display();
	}

	//ДЛЯ ЛАБ. 8
	printf("\nСравнение этих двух заповедников.\n");
	Reserve::sravn_kolvow(reses[0], reses[1]); //исп. статический метод
	Reserve::set_nalog(0.05); //работа со статическим полем
	printf("\nНовое значение подоходного налога: ");
	cout << Reserve::get_nalog() << endl;

	delete[] reses;


	printf("\nНажмите любую клавишу для выхода из программы...\n");
	_getch();
	return 0;
}
