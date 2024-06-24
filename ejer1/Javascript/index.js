// necesita tener instalado node.js para ejecutar
// command: node index.js

//puntero al archivo
const fs = require('fs');

// Function to read the file and process its content
function countWordFrequency(filename) {
    const startTime = process.hrtime();

    try {
        const data = fs.readFileSync(filename, 'utf8');

        // Convert to lowercase and remove punctuation
        const cleanData = data.toLowerCase().replace(/[^\w\s]/g, '');
        const words = cleanData.split(/\s+/);

        // Count word frequencies
        const wordCounts = {};
        words.forEach(word => {
            if (word) {
                wordCounts[word] = (wordCounts[word] || 0) + 1;
            }
        });

        // Convert to an array of [word, frequency] pairs
        const sortedWordCounts = Object.entries(wordCounts)
            .sort((a, b) => b[1] - a[1]);

        
        // Print the word frequencies
        sortedWordCounts.forEach(([word, count]) => {
            console.log(`${word}: ${count}`);
        });

        const endTime = process.hrtime(startTime);
        const executionTime = (endTime[0] * 1000) + (endTime[1] / 1e6);
        console.log(`Execution Time: ${executionTime} milliseconds`);

    } catch (err) {
        console.error(`Error reading file: ${err}`);
    }
}

// Example usage:
const filename = '../texto.txt';
countWordFrequency(filename);

