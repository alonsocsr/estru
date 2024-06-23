// necesita tener instalado node.js para ejecutar
// command: node index.js

//puntero al archivo
const fs = require('fs');

// se lee el archivo en la funcion y se procesa
function countWordFrequency(filename) {

    const startTime = process.hrtime();

    //arrow function:
    // tercer parámetro es una funcion callback
    // extrae el dato y error y lo representa si ocurre
    fs.readFile(filename, 'utf8', (err, data) => {
        if (err) {
            console.error(`Error reading file: ${err}`);
            return;
        }

        // Remueve los signos de puntuación y convierte a minúscula
        const cleanData = data.toLowerCase().replace(/[^\w\s]/g, '');
        const words = cleanData.split(/\s+/);

        // contar la frecuencia de las palabras
        const wordCounts = {};
        words.forEach(word => {
            if (word) {
                wordCounts[word] = (wordCounts[word] || 0) + 1;
            }
        });

        // convertir a un array de pares [word, frequency]
        const sortedWordCounts = Object.entries(wordCounts)
            .sort((a, b) => b[1] - a[1]);

        // Imprimir las palabras
        sortedWordCounts.forEach(([word, count]) => {
            console.log(`${word}: ${count}`);
        });
    });
    
    
    const endTime = process.hrtime(startTime);
    const executionTime = (endTime[0] * 1000) + (endTime[1] / 1e6);
    console.log(`Execution Time: ${executionTime} milliseconds`);
    
}
// Example usage:
const filename = '../texto.txt';
countWordFrequency(filename);

