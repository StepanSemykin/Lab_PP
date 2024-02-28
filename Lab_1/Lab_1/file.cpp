#include <iostream>
#include <fstream>
#include <iomanip>
#include <utility>

using namespace std;

int** allocate(size_t size)
{
	int** arr = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = new int[size];
	}

	return arr;
}

void clear(int** arr, size_t size)
{
	for (int i = 0; i < size; ++i)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

int** generate_random_matrix(size_t size)
{
	int** arr = allocate(size);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			arr[i][j] = rand() % 1000;
		}
	}

	return arr;
}

void write_input_file(const char* filename, size_t size)
{
	ofstream fout(filename);
	fout << size << endl;
	for (int k = 0; k < 2; ++k)
	{
		int** input_arr = generate_random_matrix(size);
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				fout << setw(4) << input_arr[i][j] << " ";
			}
			fout << endl;
		}
		fout << endl;
		clear(input_arr, size);
	}
	fout.close();
}

pair<int**, int**> read_file(const char* filename)
{
	size_t size;
	ifstream fin(filename);
	fin >> size;

	int** arr_1 = allocate(size);
	int** arr_2 = allocate(size);

	for (int k = 0; k < 2; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (k == 0) fin >> arr_1[i][j];
				else fin >> arr_2[i][j];
			}
		}
	}
	fin.close();

	return pair<int**, int**>(arr_1, arr_2);
}

void write_file(const char* filename, int** arr, size_t size)
{
	ofstream fout(filename);
	fout << size << endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			fout << setw(4) << arr[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

void write_stat(const char* filename, size_t size, double* durations)
{
	ofstream fout(filename, ios::app);
	fout << size << endl;
	for (int i = 0; i < 10; ++i)
	{
		fout << durations[i] << " ";
	}
	fout << endl;
	fout.close();
}
