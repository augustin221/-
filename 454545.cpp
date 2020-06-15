#include <stdafx.h>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int number_rows,// ������
		number_columns; // �������
	cout << "������� ���������� ����� �������: ";
	cin >> number_rows;
	cout << "������� ���������� �������� �������: ";
	cin >> number_columns;

	// ������������ �������� ���������� �������
	float **ptrarray = new float*[number_rows];
	for (int count = 0; count < number_rows; count++)
		ptrarray[count] = new float[number_columns];

	for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
	{
		for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
		{
			ptrarray[counter_rows][counter_columns] = rand() % 100; // ���������� ������� ���������� �������
			cout << setw(2) << ptrarray[counter_rows][counter_columns] << "  "; // ����� �� ����� ���������� �������
		}
		cout << endl;
	}
	cout << endl;

	int trace = 0; // ���� �������
	for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
		for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
			if (counter_rows == counter_columns)
				trace += ptrarray[counter_rows][counter_columns]; // ������� ���� �������

	// �������� ���������� ������������� �������
	for (int count = 0; count < number_rows; count++)
		delete[]ptrarray[count];

	cout << "���� �������: " << trace << endl;
	system("pause");
	return 0;
}
}