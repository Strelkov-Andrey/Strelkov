#include <iostream>
#include <cmath>
#include <iomanip>

//using namespace std;

inline double f1(double v1, double v2)
{
	return -500.005 * v1 + 499.995 * v2;
}

inline double f2(double v1, double v2)
{
	return  499.995 * v1 - 500.005 * v2;
}

inline void RK3(double* t, double* v1, double* v2, double h, double k1, double k2, double m1, double m2)
{
	*t += h;
	//gauss(h, v1, v2, &k1, &k2, &m1, &m2);
	*v1 += h / 2 * (k1 + k2);
	*v2 += h / 2 * (m1 + m2);

}

inline void true_solution(double t, double* u1, double* u2)
{
	*u1 = 10 * exp(-0.01 * t) - 3 * exp(-1000 * t);
	*u2 = 10 * exp(-0.01 * t) + 3 * exp(-1000 * t);
}

inline void gauss(double h, double v1, double v2, double* k1, double* k2, double* m1, double* m2)
{

	int i, j, n, m;
	n = 4;
	m = 5;
	//создаем массив
	float** matrix = new float* [4];
	for (i = 0; i < n; i++)
		matrix[i] = new float[5];

	//инициализируем

	matrix[0][0] = (1 + 500.005 * (3 + sqrt(3)) / 6 * h);
	matrix[0][1] = 0;
	matrix[0][2] = (-499.995 * (3 + sqrt(3)) / 6 * h);
	matrix[0][3] = 0;
	matrix[0][4] = -500.005 * v1 + 499.995 * v2;

	matrix[1][0] = (-500.005 * (sqrt(3)) / 3 * h);
	matrix[1][1] = 1 + 500.005 * h * (3 + sqrt(3)) / 6;
	matrix[1][2] = (499.995 * (sqrt(3)) / 3 * h);
	matrix[1][3] = -499.995 * h * (3 + sqrt(3)) / 6;
	matrix[1][4] = -500.005 * v1 + 499.995 * v2;

	matrix[2][0] = (-499.995 * (3 + sqrt(3)) / 6 * h);
	matrix[2][1] = 0;
	matrix[2][2] = (1 + 500.005 * (3 + sqrt(3)) / 6 * h);
	matrix[2][3] = 0;
	matrix[2][4] = -500.005 * v2 + 499.995 * v1;

	matrix[3][0] = (499.995 * (sqrt(3)) / 3 * h);
	matrix[3][1] = -499.995 * (3 + sqrt(3)) / 6 * h;
	matrix[3][2] = (-500.005 * (sqrt(3)) / 3 * h);
	matrix[3][3] = 1 + 500.005 * h * (3 + sqrt(3)) / 6;
	matrix[3][4] = -500.005 * v2 + 499.995 * v1;

	//выводим массив

		//Метод Гаусса
		//Прямой ход, приведение к верхнетреугольному виду
	float  tmp;
	int k;
	float* xx = new float[m];
	for (i = 0; i < n; i++)
	{
		tmp = matrix[i][i];
		for (j = n; j >= i; j--)
			matrix[i][j] /= tmp;
		for (j = i + 1; j < n; j++)
		{
			tmp = matrix[j][i];
			for (k = n; k >= i; k--)
				matrix[j][k] -= tmp * matrix[i][k];
		}
	}
	/*обратный ход*/
	xx[n - 1] = matrix[n - 1][n];
	for (i = n - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][n];
		for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
	}

	//Выводим решения
	*k1 = xx[0];
	*k2 = xx[1];
	*m1 = xx[2];
	*m2 = xx[3];
	delete[] matrix;
	delete[] xx;


}