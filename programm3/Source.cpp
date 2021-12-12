#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double v1, double v2)
{
	return -500.005 * v1 + 499.995 * v2;
}

double f2(double v1, double v2)
{
	return  499.995 * v1 - 500.005 * v2;
}

double k1(double v1, double v2,double h)
{
	double ch = 499.995 * v2 - 500.005 * v1;
	double zn = 1 - h * (3 + sqrt(3)) / 6 * 500.005 + 499.995 * h * (3 + sqrt(3)) / 6;
	return (ch / zn);
}

double k2(double v1, double v2, double h, double k1)
{
	double ch = 499.995 * v2 + 499.995 * h * (sqrt(3) / 3) * k1 - 500.005 * v1 + 500.005 * h * sqrt(3) / 3 * k1;
	double zn = 1 + 499.995 * (3 + sqrt(3)) / 6 * h - 500.005 * h * (3 + sqrt(3)) / 6;
	return (ch / zn);
}

double m1(double v1, double v2, double h)
{
	double ch = 499.995 * v1 - 500.005 * v2;
	double zn = 1 - h * (3 + sqrt(3)) / 6 * 500.005 + 499.995 * h * (3 + sqrt(3)) / 6;
	return (ch / zn);
}

double m2(double v1, double v2, double h, double m1)
{
	double ch = -500.005 * v2 + 499.995 * v1 + 500.005 * h * (sqrt(3)) / 3 * m1 - 499.995 * h * sqrt(3) / 3 * m1;
	double zn = 1 + 499.995 * (3 + sqrt(3)) / 6 * h - 500.005 * h * (3 + sqrt(3)) / 3;
	return (ch / zn);
}

void RK3(double* t, double* v1, double* v2, double h)
{
	*t += h;
	double K1 = k1(*v1, *v2, h);
	double K2 = k2(*v1, *v2, h, K1);
	double M1 = m1(*v1, *v2, h);
	double M2 = m2(*v1, *v2, h, M1);

	*v1 += h / 2 * (K1 + K2);
	*v2 += h / 2 * (M1 + M2);

}

void true_solution(double t, double* u1,double* u2)
{
	*u1 = 10 * exp(-0.01 * t) - 3 * exp(-1000 * t);
	*u2 = 10 * exp(-0.01 * t) + 3 * exp(-1000 * t);
}


int main()
{
	double h = 0.001;
	double t = 0;
	double v1 = 7;
	double v2 = 13;
	int step = 0;
	double u1 = 7;
	double u2 = 13;

	cout << setw(10) << t << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << endl;
	while(step<100)
	{
		RK3(&t, &v1, &v2, h);
		true_solution(t, &u1, &u2);
		cout << setw(10) << t << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << endl;
		step += 1;
	}

	return 0;
}