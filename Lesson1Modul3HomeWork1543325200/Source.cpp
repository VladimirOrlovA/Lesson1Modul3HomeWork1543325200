#include<stdio.h>
#include<iostream>
#include<cmath>
#include<locale.h>
#include<time.h>
#define sec 60


void Task1()
{
	// int h=15, m=30, s=45, daystart=28800, secday; // Текущее время 15:30:45, начало дня 8:00
	
	int secday;
	const int daystart = 28800, dayend = 61200; // Начало дня с 8:00

start:

	int h = 0 + rand() % 24; // день длится с 8 до 17 часов
	int m = 0 + rand() % 60; // минуты в часе принимают значения от 0 до 60
	int s = 0 + rand() % 60; // секунды в минуте принимают значения от 0 до 60
		
	secday = h * pow(sec, 2) + m * sec + s - daystart;
	
	printf("\nТекущее время %dч : %dм : %dс \n", h, m, s);

	if (secday >= 0 && secday+daystart <= dayend) {printf("С начала дня прошло : %d секунд\n\n", secday); }
	else if (secday < 0){ printf("День еще не начался\n\n"); }
	else if (secday+daystart >= dayend) { printf("День длился : %d секунд\n\n", (dayend-daystart)); goto start;  }
	
}


void Task2()
{
	int day;
	int m = 0 + rand() % 12; //  12 месяцев в году
	int d = 0 + rand() % 30; //  30 дней в месяце

	// enum motnth {Jan, Feb, Mar, May, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

	day = (m - 1) * 30 + d;

	printf("\n\nДата %d месяц %d день. С начала года прошло => %d дней\n\n", m, d, day);
	
	/*switch (m)
		{
		case 0: { day = d; printf("\n\nДата %d Января 2018 года. С начала года прошло => %d дней\n\n", d, day); }break;
		case 1: { day = 31+d; printf("\n\nДата %d Января 2018 года. С начала года прошло => %d дней\n\n", d, day); }break;
		default:
			break;
		}*/

}


void Task3()
{
	int day;
	int m = 0 + rand() % 12; //  12 месяцев в году последовательность 31, 30, 31, 30, 31 и т.д
	
start:
	
	int d = 0 + rand() % 31; //  31 день в месяце

	if (m % 2 == 0) 
	{ 
		day = (m / 2) * 31 + ((m / 2) - 1) * 30 + d; 
		printf("\n\nДата %d месяц %d день. С начала года прошло => %d дней\n\n", m, d, day);
	}
	else if (d != 31)
	{ 
		day = (m / 2)*(30 + 31) + d;
		printf("\n\nДата %d месяц %d день. С начала года прошло => %d дней\n\n", m, d, day);
	}
	else { printf("1");  goto start; } // переход на генерацию нового значения дня, т.к. выпал 31 день, а в четном месяце их 30
}


void Task4()
{
		int m1;
		int m0;
		int N=10 + rand() % 99;

		m1 = N / 10;
		m0 = N - m1*10;

		printf("\nДвузначное натуральное число %d\n", N);
		printf("\nПервое число - десятки = %d\nВторое число - единицы = %d\n", m1, m0);
}


void Task5()
{
	start:
	int m1 = 0 + rand() % 9;
	int m2 = 0 + rand() % 9;
	int m3 = 0 + rand() % 9;

	printf("\n\nСлучайные числа m1 = %d, m2 = %d, m3 = %d \n", m1, m2, m3);

	if (m1 == m2 && m1 == m3 && m2 == m3){ printf("\nВведенные числа m1, m2, m3 равны между собой. Пробуем еще раз...\n\n"); goto start; }
	else
	{
		if (m1 == m2 && m1 < m3) { printf("\nВведено два минимальных значения из трех, определить одно не возможно.\nПробуем еще раз..."); goto start; }
		if (m1 == m3 && m2 > m3) { printf("\nВведено два минимальных значения из трех, определить одно не возможно.\nПробуем еще раз..."); goto start; }
		if (m2 == m3 && m1 > m2) { printf("\nВведено два минимальных значения из трех, определить одно не возможно.\nПробуем еще раз..."); goto start; }
		
		
		if (m1 < m2 && m1 < m3) { printf("\nНаименьшее число из введенных m1 = %d \n", m1); }
		else if (m2 < m1 && m2 < m3) { printf("\nНаименьшее число из введенных m2 = %d \n", m2); }
		else if (m3 < m1 && m3 < m2) { printf("\nНаименьшее число из введенных m3 = %d \n", m3); }
	}
}


void Task6()
{
	int c = 0;
	do
	{
		c++;
		int m = 1 + rand() % 45;
		int n = 1 + rand() % 10;
		if (m%n == 0) { printf("\nЧисло n=%d кратно m=%d\n\n", n,m); }
		else { printf("\nЧисло n=%d  не кратно m=%d\n\n", n, m); }
	} while (c < 7);
}


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	int task;
	int flag;

	start:

	printf("Enter number of task from (1) to (6) : ");
	scanf_s("%d", &task);

	switch (task)
	{
	case 1: {(Task1()); } break;
	case 2: {(Task2()); } break;
	case 3: {(Task3()); } break;
	case 4: {(Task4()); } break;
	case 5: {(Task5()); } break;
	case 6: {(Task6()); } break;

	default:
		break;
	}

	{
		printf("\nDo You want to continue? set 0 or 1 =>  ");
		scanf_s("%d", &flag);
		
	if (flag == 1)
		goto start;

	system("pause");
	}
}