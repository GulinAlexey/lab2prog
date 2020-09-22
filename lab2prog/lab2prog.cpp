// lab2prog.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	printf("Первый запуск!\n");
	_getch();
	return 0;
}

