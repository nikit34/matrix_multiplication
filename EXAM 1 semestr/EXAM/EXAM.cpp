
#include "pch.h"
#include <iostream>
#include <windows.h>
#include "getmtx.h"


using namespace std;



void printMatrix(int**matrix_for_print,int n)
//процедура печати матрицы (матрица,размерность)

{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			cout << matrix_for_print[i][j] << " ";
		cout << "\n"; 
	}
	cout << "\n";
}



int main()
{	
	setlocale(LC_ALL, "");
	while (true) {
		// n - размерность
		int n;
		cout << "Введите размерность n: ";
		cin >> n;

		//высвобождаем память под матрицу
		int** matrix;
		matrix = new int*[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new int[n];


		//заполняем матрицу
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << "Введите элемент [" << i << "] [" << j << "]: ";
				cin >> matrix[i][j];
			}
			cout << endl;
		}

		//печатаем матрицу (матрица, размерность)
		printMatrix(matrix, n);

		// det(матрица, размерность) - функция счета определителя

		cout << "Определитель: " << det(matrix, n) << endl;
		getchar();
		for (int g = 0; g < n; g++)
			delete[g]matrix;
		delete[] * matrix;
	}
	return 0;
}
