/*
	Следующая программа производит быстрый поиск заданного числа из последовательности Фибоначчи.
	В алгоритме используется метод поиска чисел Фибоначчи через свойства матриц,
	а также реализована фунция бинарного возведения в степень для матриц.
	Этот алгоритм по большей части "Proof of concept", так как ряд растет с экспоненциальной скоростью
	и для нормального хранения чисел Фибоначчи необходимо реализовывать длинную арифметику.
*/

#include "stdafx.h"
#include <locale>
#include <stdio.h>

using namespace std;

unsigned long long fib(int n);
unsigned long long** powm(unsigned long long** a, int n, int p);
unsigned long long** gen(unsigned long long** a, unsigned long long** b, int m, int n, int k);

int main()
{
	_wsetlocale(LC_ALL, L"Russian");
 	int n(0), res(0);
	printf("Введите номер числа Фибоначчи: ");
	scanf("%d", &n);
	printf("Fn = %llu\n", fib(n));
	system("pause");
	return 0;
}

unsigned long long fib(int n)						// Сама фунция нахождения числа Фибоначчи
{
	unsigned long long** p = new unsigned long long*[2];
	p[0] = new unsigned long long[2];
	p[1] = new unsigned long long[2];
	p[0][0] = 0;
	p[0][1] = 1;
	p[1][0] = 1;
	p[1][1] = 1;
	unsigned long long** f = new unsigned long long*[1];
	f[0] = new unsigned long long[2];
	f[0][0] = 0;
	f[0][1] = 1;
	p = powm(p, 2, n);
	f = gen(f, p, 1, 2, 2);
	return f[0][0];
}

unsigned long long** powm(unsigned long long** a, int n, int p)		// Функция возведения в степень квадратных матриц
{
	unsigned long long** b = new unsigned long long*[n];		// Инициализация единичной матрицы
	for (int i(0); i < n; ++i) {
		b[i] = new unsigned long long[n];
		for (int j(0); j < n; ++j)
			b[i][j] = 0;
	}
	for (int i(0); i < n; ++i)
		b[i][i] = 1;
	while (p)							// Бинарное возведение в степень
	{
		if (p & 1)
			b = gen(b, a, n, n, n);
		a = gen(a, a, n, n, n);
		p >>= 1;
	}
	return b;
}

unsigned long long** gen(unsigned long long** a, unsigned long long** b, int m, int n, int k)
{
	unsigned long long** c = new unsigned long long*[m];		// Функция умножения матриц
	for (int i(0); i < m; ++i)	c[i] = new unsigned long long[k];
	for (int i(0); i < m; ++i) {
		for (int j(0); j < k; ++j) {
			c[i][j] = 0;
			for (int g(0); g < n; ++g)
				c[i][j] += a[i][g] * b[g][j];
		}
	}
	return c;
}
