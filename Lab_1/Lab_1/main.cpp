#include <iostream>
#include <chrono>
#include "file.h"

const char* INPUT_FILENAME = "input.txt";
const char* RESULT_FILENAME = "result.txt";
const char* STAT_FILENAME = "statistics.txt";

using namespace std;

int** mul_matrix(int** arr_1, int** arr_2, size_t size)
{
    int** result = allocate(size);
    for (int i = 0; i < size; ++i)
    {
        result[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) 
            {
                result[i][j] += arr_1[i][k] * arr_2[k][j];
            }
        }
    }

    return result;
}

int main()
{
    srand(time(0));
    size_t* arr_sizes = new size_t[8] {500, 600, 800, 1000, 1200, 1500, 1800, 2000};
    double* durations_arr = new double[10](0);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            write_input_file(INPUT_FILENAME, arr_sizes[i]);
            pair<int**, int**> pair_arr = read_file(INPUT_FILENAME);
            int** res = allocate(arr_sizes[i]);

            auto start = chrono::steady_clock::now();
            res = mul_matrix(pair_arr.first, pair_arr.second, arr_sizes[i]);
            auto end = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            durations_arr[j] = duration.count();

            write_file(RESULT_FILENAME, res, arr_sizes[i]);
            clear(res, arr_sizes[i]);
            clear(pair_arr.first, arr_sizes[i]);
            clear(pair_arr.second, arr_sizes[i]);
        }
        write_stat(STAT_FILENAME, arr_sizes[i], durations_arr);
        cout << "Mul matrix " << arr_sizes[i] << "x" << arr_sizes[i] << " is done" << endl;
        for (int i = 0; i < 10; ++i)
        {
            cout << durations_arr[i] << " ";
        }
        cout << endl;
    }

    delete[] arr_sizes;
    delete[] durations_arr;

	return 0;
}