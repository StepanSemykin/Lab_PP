#pragma once

int** allocate(size_t size);

void clear(int** arr, size_t size);

int** generate_random_matrix(size_t size);

void write_input_file(const char* filename, size_t size); 

std::pair<int**, int**> read_file(const char* filename);

void write_file(const char* filename, int** arr, size_t size);

void write_stat(const char* filename, size_t size, double* durations);