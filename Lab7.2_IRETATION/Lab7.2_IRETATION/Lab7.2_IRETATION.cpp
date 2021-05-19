#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** &a, const int n, const int k, int low, int hight) 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) 
			a[i][j] = low + rand() % (hight - low + 1);
}

void Print(int** &a, const int n, const int k) 
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
	}
	cout << endl;
}

int Sum(int** &a, const int n, const int k) 
{
	int s = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(i % 2 == 0))
		{
			int min = a[i][0];
			for (int j = 0; j < k; j++)
			{
				if (a[i][j] < min)
				{
					min = a[i][j];
				}
			}
			s += min;
			count++;
		}
	}
	return s;
}

int main() 
{
	srand(unsigned(time(NULL)));

	int Low;
	int Hight;
	
	int n;
	int k;

	cout << "Low = ";
	cin >> Low;
	cout << "Hight = ";
	cin >> Hight;
	cout << "RowCount = ";
	cin >> n;
	cout << "ColCount = ";
	cin >> k;


	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];

	Create(a, n, k, Low, Hight);
	Print(a, n, k);

	int S = Sum(a, n, k);

	cout << endl << "  " << "S = " << S << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}