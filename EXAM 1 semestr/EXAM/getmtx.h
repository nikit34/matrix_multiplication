#pragma once
using namespace std;
 
void get_matr(int ** matrix, int n, int i, int**temp_matrix)	
//процедура вычеркивания строки и столбца (матрица, размерность, счетчик с функции det, минор)
//temp_matrix - минор
//
{
	int ki=0, kj=0, di=0, dj=0;
	

	for (ki = 0; ki < n - 1; ki++)
	{
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < n - 1; kj++)
		{
			if (kj == 0) dj = 1;
			temp_matrix[ki][kj] = matrix[ki + di][kj + dj];

			cout << temp_matrix[ki][kj] << " ";
		}
		cout << endl;
	}

}

int det(int**matrix, int n)	//функция вычисления определителя(матрица,размерность)
{
	int temp = 0;	//временная переменная для хранения определителя
	int k = 1;	//степень
	int i;

	//выделяем для доп.матрицы
	int** temp_matrix;
	temp_matrix = new int*[n];
	for (int i = 0; i < n; i++)
		temp_matrix[i] = new int[n];



	if (n < 1) {
		std::cout << "опрделитель не может быть подсчитан";
		return 0;
	}
	else if (n == 1)
		temp = matrix[0][0];
	else if (n == 2)
		temp = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	else
	{
		for (i = 0; i < n; i++)
		{
			get_matr(matrix, n, i, temp_matrix);

			temp = temp + k * matrix[i][0] * det(temp_matrix, n - 1);
			k = -k;
		}
	}
	for (int g = 0; g < n; g++)
		delete[g]temp_matrix;
	delete[]*temp_matrix;
	return temp;
}