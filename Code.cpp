#include <iostream>
using namespace std;
int main()
{
	int n; //описание переменных
	cout << "N=";
	cin >> n;
	int* A = new int[n];
	cout << "P.S. enter the numbers separated by a space\n";
	for (int i = 0; i < n; i++)
		{
		cin >> A[i];
		}
	for (int i = 0; i < n - 1; i++) // Максимальное число просмотров массива
	{
		bool zamena = false; // Флаг показывает, что был выполнен обмен элементов 
		for (int j = 0; j<n - 1 - i; j++) // Просматриваем массив (последние элементы могут быть отсортированы на предыдущих шагах)
			if (A[j]>A[j + 1]) // Элементы меняем местами
			{
			int buf = A[j];
			A[j] = A[j + 1];
			A[j + 1] = buf;
			zamena = true;
			}
		if (!zamena) // Замен не было массив уже отсортирован
			break;
	}
		for (int i = 0; i < n; i++)
		{
			cout << A[i];
			cout << " ";
		}
	
	system("pause");
	return 0;
}
