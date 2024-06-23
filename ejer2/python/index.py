import random
import csv
import time

def generate_matrix(rows, cols):
    return [[random.randint(1, 10) for _ in range(cols)] for _ in range(rows)]

def multiply_matrices(mat1, mat2):
    rows1, cols1 = len(mat1), len(mat1[0])
    cols2 = len(mat2[0])

    result = [[0 for _ in range(cols2)] for _ in range(rows1)]
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += mat1[i][k] * mat2[k][j]
    return result

def write_matrix_to_csv(file, matrix):
    with open(file, 'a', newline='') as f:
        writer = csv.writer(f)
        for row in matrix:
            writer.writerow(row)

def main():
    rows1, cols1 = 200, 250
    rows2, cols2 = 250, 210

    start_time = time.time()

    mat1 = generate_matrix(rows1, cols1)
    mat2 = generate_matrix(rows2, cols2)
    result = multiply_matrices(mat1, mat2)

    with open('matrices_result.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerow(['Matriz 1:'])
    write_matrix_to_csv('matrices_result.csv', mat1)
    
    with open('matrices_result.csv', 'a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow([])
        writer.writerow(['Matriz 2:'])
    write_matrix_to_csv('matrices_result.csv', mat2)
    
    with open('matrices_result.csv', 'a', newline='') as f:
        writer = csv.writer(f)
        writer.writerow([])
        writer.writerow(['Resultado Multiplicación:'])
    write_matrix_to_csv('matrices_result.csv', result)

    print("Las Matrices y el resultado fueron escritas en matrices_result.csv")

    end_time = time.time()
    execution_time_ms = (end_time - start_time) * 1000
    print(f"Execution time: {execution_time_ms:.3f} ms")

if __name__ == "__main__":
    main()
