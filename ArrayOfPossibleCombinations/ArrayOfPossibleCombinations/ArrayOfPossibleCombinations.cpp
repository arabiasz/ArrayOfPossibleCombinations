// ArrayOfPossibleCombinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

size_t Factory(size_t n)
{
	size_t result = 1;

	while (n > 0)
	{
		result *= n;
		n--;
	}
	return result;
}

size_t CombinationsWithoutRepetitionCount(size_t k, size_t n)
{
	return Factory(n) / ((Factory(k)) * (Factory(n - k)));
}


size_t ** MakeCombinationTable(size_t k, size_t n, size_t combinationCount)
{
	size_t ** tab = new size_t*[combinationCount];

	for (size_t i = 0; i < combinationCount; i++)
	{
		tab[i] = new size_t[k];
	}

	for (size_t i = 0; i < k; i++)
	{
		tab[0][i] = i;
	}

	for (size_t i = 1; i < combinationCount; i++)
	{
		if (tab[i - 1][k - 1] < n - 1)
		{
			size_t x;
			for (x = 0; x < k - 1; x++)
				tab[i][x] = tab[i - 1][x];

			tab[i][x] = tab[i - 1][x] + 1;
		}
		else
		{
			for (size_t j = 0; j < k - 2; j++)
			{
				tab[i][j] = tab[i - 1][j];
			}

			for (size_t l = k - 2; l >= 0; l--)
			{
				size_t start = tab[i - 1][l];
				size_t m;
				for (m = l; m < k; m++)
				{
					tab[i][m] = ++start;
				}

				if (tab[i][m - 1] <= n - 1)
					break;
			}
		}
	}

	return tab;
}

int main()
{
	ofstream resultFile;
	resultFile.open("result.txt");

	int k, n;
	cout << "Enter k and n: ";
	cin >> k >> n;

	size_t combinationCount = CombinationsWithoutRepetitionCount(k, n);

	size_t ** table = MakeCombinationTable(k, n, combinationCount);

	resultFile << "The number of combinations: " << combinationCount << endl;

	for (size_t i = 0; i < combinationCount; i++)
	{
		for (size_t j = 0; j < k; j++)
		{
			cout << table[i][j];
			resultFile << table[i][j];
		}
		cout << endl;
		resultFile << endl;
	}
	resultFile.close();

	for (int i = 0; i < combinationCount; i++)
		delete table[i];
	delete table;

	return 0;
}
