#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Funcion que genera una matriz con valores aleatorios
vector<vector<int>> generateMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 10 + 1; // valores random entre 1 y 10
        }
    }
    return matrix;
}

// funcion que multiplica las dos matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size(); //rows2 too
    int cols2 = mat2[0].size();

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// funcion para escribir una matriz en un archivo
void writeMatrixToFile(ofstream& file, const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // semilla para generar lod numeros randoms

    int rows1 = 200, cols1 = 250; // dimensiones de la primera matriz
    int rows2 = 250, cols2 = 210; // dimensiones de la segunda matriz

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // genera las matrices con valores randoms
    vector<vector<int>> mat1 = generateMatrix(rows1, cols1);
    vector<vector<int>> mat2 = generateMatrix(rows2, cols2);

    // multiplicar matrices
    vector<vector<int>> result = multiplyMatrices(mat1, mat2);

    // escribir en el archivo
    ofstream file("matrices_result.csv");
    if (file.is_open()) {
        file << "Matriz 1:\n";
        writeMatrixToFile(file, mat1);
        file << "\nMatriz 2:\n";
        writeMatrixToFile(file, mat2);
        file << "\nResultado:\n";
        writeMatrixToFile(file, result);
        file.close();
        cout << "Las matrices y el resultado se escribieron en matrices_result.csv" << endl;
    } else {
        cerr << "No se pudo abrir el archivo" << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Execution time: " << elapsed.count() << " ms" << endl;

    return 0;
}
