#include <stdafx.h>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int number_rows,
		number_columns; 
	cout << "Введите количество строк матрицы: ";
	cin >> number_rows;
	cout << "Введите количество столбцов матрицы: ";
	cin >> number_columns;

	// динамическое создание двумерного массива
	float **ptrarray = new float*[number_rows];
	for (int count = 0; count < number_rows; count++)
		ptrarray[count] = new float[number_columns];

	for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
	{
		for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
		{
			ptrarray[counter_rows][counter_columns] = rand() % 100; // заполнение массива случайными числами
			cout << setw(2) << ptrarray[counter_rows][counter_columns] << "  "; // вывод на экран двумерного массива
		}
		cout << endl;
	}
	cout << endl;

	int trace = 0; // след матрицы
	for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
		for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
			if (counter_rows == counter_columns)
				trace += ptrarray[counter_rows][counter_columns]; // считаем след матрицы

	// удаление двумерного динамического массива
	for (int count = 0; count < number_rows; count++)
		delete[]ptrarray[count];

	cout << "След матрицы: " << trace << endl;
	system("pause");
	return 0;
}