#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** &a, const int n, const int k, int low, int hight, int rowNo, int colNo)
{
	a[rowNo][colNo] = low + rand() % (hight - low + 1);
	if (colNo < k - 1) 
	{
		Create(a, n, k, low, hight, rowNo, colNo + 1);
	}
	else
	{
		if (rowNo < n - 1)
		{
			Create(a, n, k, low, hight, rowNo + 1, 0);
		}
	}
}

void Print(int** &a, const int n, const int k, int i, int j)
{
	cout <<setw(4) << a[i][j];
	if (j < k - 1) 
	{
		Print(a, n, k, i, j + 1);
	}
	else 
	{
		if (i < n - 1) 
		{
			cout << endl;
			Print(a, n, k, i+1, 0);
		}
		else 
		{
			cout << endl << "\n";
		}
	}


}

void Sum(int** &a, const int n, const int k, int i, int j, int& S, int& min)
{
	if (i < n) 
	{
		min = a[i][0];
		if (!(i % 2 == 0))
		{
			for (int j = 0; j < k; j++)
			{
				if (j < k && (a[i][j] < min))
				{
					min = a[i][j];
				}
			}
			S += min;
			Sum(a, n, k, i + 1, 0, S, min);
		}
		else
			Sum(a, n, k, i + 1, 0, S, min);
	}
	
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

	Create(a, n, k, Low, Hight, 0, 0);
	Print(a, n, k, 0, 0);

	int min = a[0][0];

	int S = 0;

	Sum(a, n, k, 0, 0, S, min);

	cout << endl << "  " << "S = " << S << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}