// lab2prog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	printf("Второй запуск!\n"); //Это запуск!
	_getch();
	return 0;
}

