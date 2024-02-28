import numpy as np

INPUT_FILE_PATH = 'Lab_1\\Lab_1\\input.txt'
RESULT_FILE_PATH = 'Lab_1\\Lab_1\\result.txt'

def read_file(filename: str) -> str:
    with open(filename, "r", encoding="utf-8") as f:
        res = f.readlines()[1:]
    return res


def to_int(data: str) -> list:
    matrix = []
    for string in data:
        if string == '\n':
            continue
        row = [int(x) for x in string.split()]
        matrix.append(row)
    return matrix


def mul_is_correct(matrix_1: list, matrix_2: list, matrix_res: list) -> None:
    mul = np.matmul(matrix_1, matrix_2)
    matrix_res = np.array(matrix_res)
    if np.array_equal(mul, np.array(matrix_res)): print('Mul is correct')
    else: print('Mul is wrong')


if __name__ == "__main__":
    input_matrix = read_file(INPUT_FILE_PATH)
    input_matrix = to_int(input_matrix)
    size = len(input_matrix)
    matrix_1 = input_matrix[:int((size/2))]
    matrix_2 = input_matrix[int(size/2):]

    res = read_file(RESULT_FILE_PATH)
    res = to_int(res)
    mul_is_correct(matrix_1, matrix_2, res)
    