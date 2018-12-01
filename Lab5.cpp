/**

\mainpage Главная страница

 Данный проект является программой, которая может посчитать
максимальное количество подряд идущих букв в любомом тексте.

*/

/**
*\file
*\brief Обработка входящего текста.
*\author Gevorg
*\version 1.0
*\example Вычисление максимального количества подряд
идущих букв в словах
*
*Различные методы обработки текста.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

/**
*\brief Функция выводит на экран меню возвращает номер
выбранного пользователем пункта
* Используется в функции main()
*\return Номер пункта меню
*/
int printMenu();
///Функция считывает введенную с клавиатуры строку, ведяет под нее память и возвращает указатель.
char* setString();
/**
*\brief Функция сортирует введенную строку и возвращает
максимальное количество подряд идущих букв.
* Используется в функции main()
*\param[in] s Указатель на введенную строку
*\param[in] len Длина введенной строки
*\return Максимальное количество подряд идущих одинаковых букв.
*/
int sortString(char*, int);
/**
*\brief Функция осуществляет вывод результата на экран.
* Используется в функции main()
*\param[in] MaxL Максимальное количество подряд идущих букв.
*/
void printResult(int);
///Функция осуществляет проверку введенных пользователем данных и возвращает введенное число
int Check();

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	char *s = NULL;
	char *s1 = NULL;// указатель на массив
	int sum = 1;
	int maxL = 1;
	int i = 0;
	int len = 0;;
	char c = '\0';
	int menu = 0;

	bool arrEntered = false;
	bool arrEntered1 = false;

	
	while (menu != 4)
	{
		menu = printMenu();
		switch (menu) {
		case 1:
			system("cls");
			arrEntered1 = false;
			arrEntered = true;
			delete[] s;
			s = setString();
			len = strlen(s);
			system("cls");
			break;
		case 2:
			arrEntered1 = true;
			if (!arrEntered)
			{
				printf("Введите строку!\n");
				break;
			}
			if (menu == 2)
			{
				system("cls");
			}

			maxL = sortString(s, len);
			break;
		case 3:
			if (!arrEntered)
			{
				printf("Введите строку!\n");
				break;
			}
			if (!arrEntered1)
			{
				printf("Для начала обработайте строку!\n");
				break;
			}
			if (menu == 3)
			{
				system("cls");
			}
			printResult(maxL);
			
			break;
		}
	}

	delete[] s;
	_CrtDumpMemoryLeaks();
	return 0;
}

int printMenu()
{
	int m = 0;
	char c = '\0';
	printf("--------------------------------------------------------------------------\n");
	printf("| 1-Ввод строки                                                          |\n");
	printf("| 2-Обработка строки                                                     |\n");
	printf("| 3-Найти наибольшее количество идущих подряд букв                       |\n");
	printf("| 4-Выход                                                                |\n");
	printf("--------------------------------------------------------------------------\n");
	m = Check();

	return m;
}

char* setString()
{
	char *s = NULL;
	int i = 0;
	int len;
	char *s1 = NULL;
	char c = '\0';
	delete[] s;
	s = new char[1]; // Выделение памяти
	s[0] = '\0';

	while (true)
	{
		c = _getch();
		if (c == 13)
		{
			break;
		}
		if (c != '\0')
		{
			printf("%c", c);
			if (c == '\b') //Если пользователь нажал Backspace
			{
				printf("%c%c", ' ', '\b');
				len = strlen(s);
				if (len != 0) 
				{
					s1 = new char[len]; 
					for (int i = 0; i < len; i++) 
					{
						s1[i] = s[i];
					}
					s1[len - 1] = '\0'; 
					delete[] s;
					s = s1;
				}
			}

			else //Если пользователь ввел символ
			{
				int len = strlen(s);
				s1 = new char[len + 2];
				strcpy(s1, s);
				s1[len] = c;
				s1[len + 1] = '\0';
				delete[] s;
				s = s1;
			}
		}
		
	}
	return s;
}

int sortString(char* s, int len)
{
	int sumD = 0;
	int sum = 1;
	int maxL = 1;

	printf("Ваша строка: %s\n", s);
	for (int i = 0; i < len; i++)
	{
		if ((s[i] >= '!' && s[i] <= '@') || (s[i] >= '[' && s[i] <= '`') || (s[i] >= '{' && s[i] <= '~') || s[i] == ' ')
		{
			sumD = sumD + 1;
			continue;
		}
		if (s[i] != ' ')
		{
			if (s[i] == s[i + 1])
			{
				sum = sum + 1;
			}
			else
			{
				sum = 1;
			}
		}
		if (sum > maxL)
		{
			maxL = sum;
		}
		if (s[i] == ' ')
		{
			sum = 1;
		}
	}
	if (sumD == len)
	{
		maxL = 0;
	}
	printf("Обработка прошла успешно!\n");
	
	return maxL;
}

void printResult(int maxL)
{
	printf("Максимальное количество подряд идущих букв: %d \n", maxL);
}

int Check()
{
	int a = 0;
	char c = '\0';
	while (scanf_s("%d", &a) != 1 || a < 0)
	{
		while (scanf_s("%c", &c) != 0 && c != '\n');
		printf("Введено не верное значение! Попробуйте снова!\n");
	}
	return a;
}
