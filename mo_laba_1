// МО_1-3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
void print(float matrix[5][5])
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((i == 0) && (j == 0))
			{
				printf("\t");
				continue;
			}
			if ((i == 0) && (j == 1))
			{
				printf("So\t");
				continue;
			}
			if ((i == 0) && (j >= 2))
			{
				printf("X%1.0f\t", matrix[i][j]);
				continue;
			}
			if ((j == 0) && (i >= 1) && (i!=4))
			{
				printf("X%1.0f\t", matrix[i][j]);
				continue;
			}
			if ((j == 0) && (i >= 1) && (i == 4))
			{
				printf("F\t");
				continue;
			}
			printf("%2.3f\t", matrix[i][j]);
		}
		cout << endl;
	}
}
void  jardan(float matrix[5][5],int k, int r)
{

	float **new_matrix;
	new_matrix = new float*[5];
	for (int i = 0; i < 5; i++)
	{
		new_matrix[i] = new float[5];
		for (int j = 0; j < 5; j++)
			new_matrix[i][j] = matrix[i][j];
	}

	new_matrix[k][r] = 1 / matrix[k][r];
	for (int j = 1; j < 5; j++)
		if (j != r)
			new_matrix[k][j] = matrix[k][j] / matrix[k][r];

	for (int i = 1; i < 5; i++)
		if (i != k)
			new_matrix[i][r] = -matrix[i][r] / matrix[k][r];

	for (int j = 1; j < 5; j++)
		for (int i = 1; i < 5; i++)
			if ((j != r) && (i != k))
				new_matrix[i][j] = matrix[i][j] - (matrix[i][r] * matrix[k][j]) / matrix[k][r];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			matrix[i][j] = new_matrix[i][j];

	cout << endl;
}
void transpose(float matrix[5][5]) 
{
	matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 1; matrix[0][3] = 2; matrix[0][4] = 3;
	matrix[1][0] = 4; matrix[1][1] = -1; matrix[1][2] = -1; matrix[1][3] = -1; matrix[1][4] = 0;
	matrix[2][0] = 5; matrix[2][1] = -3; matrix[2][2] = -1; matrix[2][3] = -1; matrix[2][4] = -0.5;
	matrix[3][0] = 6; matrix[3][1] = -8; matrix[3][2] = -1; matrix[3][3] = 0; matrix[3][4] = -2;
	matrix[4][0] = 0; matrix[4][1] = 0; matrix[4][2] = -7; matrix[4][3] =- 2; matrix[4][4] = -4;
}
int main()
{
	setlocale(LC_ALL, "rus");
	float q = 1;
	int a;
	float matrix[5][5];
	matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 1; matrix[0][3] = 2; matrix[0][4] = 3;
	matrix[1][0] = 4; matrix[1][1] = 7; matrix[1][2] = 1; matrix[1][3] = 1; matrix[1][4] = 1;
	matrix[2][0] = 5; matrix[2][1] = 2; matrix[2][2] = 1; matrix[2][3] = 1; matrix[2][4] = 0;
	matrix[3][0] = 6; matrix[3][1] = 4; matrix[3][2] = 0; matrix[3][3] = 0.5; matrix[3][4] = 2;
	matrix[4][0] = 0; matrix[4][1] = 0; matrix[4][2] = 1; matrix[4][3] = 3; matrix[4][4] = 8;
	cout << "ПЗ-1, ДЗ-2\n";
	cin >> a ;
	if (a == 2)
	{ 
		transpose(matrix);
	}
	print(matrix);
	while (q != 0) 
	{
		int k = 0;
		q = 0;
		//ищем максимальный по модулю отрицательный элемент в столбце свободных членов
		float max = FLT_MIN;
		for (int i = 1; i < 4; i++) 
		{
			if ((matrix[i][1] < 0) && (abs(matrix[i][1])>max)) 
			{
				max = abs(matrix[i][1]);
				q = matrix[i][1];
				k = i;
			}
		 }
		if (q<0)
		{
			int r = 0;
			float max = FLT_MIN;
			for (int j = 2; j < 5; j++) 
			{
				if ((matrix[k][j] < 0) && (abs(matrix[k][j])>max))
				{
					max = matrix[k][j];
					r = j;
				}
			 }
			 if (!r)
			 { 
				print(matrix);
				break;
			 }
			 else 
			 {  
				float min = FLT_MAX;
				swap(matrix[0][r], matrix[k][0]);
				jardan(matrix, k, r);
			 }
		  }
		}
	cout << "Опорное решение\n";
	print(matrix);
	cout << endl;

	while (1)
	{
		int r = 0, k = 0;
		float min = 0;
		for (int j = 2; j < 5; j++)
		{
			if (matrix[4][j] > 0) 
			{
				min = matrix[4][j];
				r = j;// столбик
				break;
			}
		}
		if (min != 0)
		{
			float	new_min;
			new_min = FLT_MAX;
			for (int i = 1; i < 4; i++)
			{
				if (matrix[i][r] == 0)
					continue;
				if ((matrix[i][1] / matrix[i][r] < new_min) && (matrix[i][1] / matrix[i][r]>0))
				{
					k = i;// строка
					new_min = matrix[i][1] / matrix[i][r];
				}
			}
			if (new_min == FLT_MAX)
			{
				cout << " Error";
				break;
			}
			swap(matrix[0][r], matrix[k][0]);
			jardan(matrix, k, r);

			print(matrix);
			cout << endl;
		}
		else
			break;
	}
	cout << "Оптимальное решение\n";
	print(matrix);
	cout << endl;

	system("pause");
	return 0;
}
