// necesita tener instalado node.js para ejecutar
// command: node index.js (ejecucion)

const fs = require('fs');

//funcion para generar las matrices
function generateMatrix(rows, cols) {
    let matrix = [];
    for (let i = 0; i < rows; i++) {
        let row = [];
        for (let j = 0; j < cols; j++) {
            //valores randoms entre 1 y 10
            row.push(Math.floor(Math.random() * 10) + 1);
        }
        matrix.push(row);
    }
    return matrix;
}

//se multiplican las matrices
function multiplyMatrices(mat1, mat2) {
    let rows1 = mat1.length;
    let cols1 = mat1[0].length;
    let cols2 = mat2[0].length;

    let result = [];
    for (let i = 0; i < rows1; i++) {
        result.push([]);
        for (let j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (let k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

function writeMatrixToFile(file, matrix) {
    let data = matrix.map(row => row.join(',')).join('\n') + '\n';
    fs.appendFileSync(file, data, 'utf8');
}

function main() {
    let rows1 = 200, cols1 = 250;
    let rows2 = 250, cols2 = 210;

    let startTime = Date.now();

    let mat1 = generateMatrix(rows1, cols1);
    let mat2 = generateMatrix(rows2, cols2);
    let result = multiplyMatrices(mat1, mat2);

    let file = 'matrices_result.csv';
    fs.writeFileSync(file, 'Matrix 1:\n', 'utf8');
    writeMatrixToFile(file, mat1);
    fs.appendFileSync(file, '\nMatrix 2:\n', 'utf8');
    writeMatrixToFile(file, mat2);
    fs.appendFileSync(file, '\nResult:\n', 'utf8');
    writeMatrixToFile(file, result);

    let endTime = Date.now();
    let executionTimeMs = endTime - startTime;
    console.log('Las Matrices y el resultado fueron escritas en matrices_result.csv');
    console.log(`Execution time: ${executionTimeMs} ms`);
}

main();
