#include <iostream>
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using namespace std;
int n, i, j, k;
double d, s;
int main()
{
	auto t1 = high_resolution_clock::now();
	n = 3; // головна змінна
	cout << "Poryadok: " << n << endl;
	double** a = new double* [n];
	for (i = 0; i <= n; i++)
		a[i] = new double[n];
	double** a1 = new double* [n];
	for (i = 0; i <= n; i++)
		a1[i] = new double[n];
	double* b = new double[n];
	double* x = new double[n];
	for (i = 1; i <= n; i++) // заповнення
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = rand() % 10;
			cout << "a[" << i << "," << j << "] = " << a[i][j] << endl;
			a1[i][j] = a[i][j];
		}
		b[i] = rand() % 10;
		cout << "b[" << i << "] = " << b[i] << endl;
	}

	for (k = 1; k <= n; k++) // прямий хід
	{
		for (j = k + 1; j <= n; j++)
		{
			d = a[j][k] / a[k][k];
			for (i = k; i <= n; i++)
			{
				a[j][i] = a[j][i] - d * a[k][i];
			}
			b[j] = b[j] - d * b[k];
		}
	}

	for (k = n; k >= 1; k--) // зворотній хід
	{
		d = 0;
		for (j = k + 1; j <= n; j++)
		{
			s = a[k][j] * x[j];
			d = d + s;
		}
		x[k] = (b[k] - d) / a[k][k];
	}
	cout << "Korni sistemy: " << endl;
	for (i = 1; i <= n; i++)
		cout << "x[" << i << "] = " << x[i] << " " << endl;
	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	std::cout << ms_double.count() << "ms\n";
	return 0;
}
