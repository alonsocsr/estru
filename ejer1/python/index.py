from collections import Counter
import re
import time

#funcion para contar la frecuencia
def count_word_frequency(filename):
    start_time = time.time()

    #abrir el archivo
    with open(filename, 'r', encoding='utf-8') as file:
        text = file.read()
    
    # Se utiliza una expresion regular (re) para encontrar
    # todas las palabras
    words = re.findall(r'\b\w+\b', text.lower())
    
    # cuenta la frecuencia de cada palabra (Counter Collections)
    word_counts = Counter(words)
    
    # Ordena las palabras por frecuencia en orden descendente
    sorted_word_counts = sorted(word_counts.items(), key=lambda item: item[1], reverse=True)

    end_time = time.time()
    execution_time_ms = (end_time - start_time) * 1000
    print(f"Execution time: {execution_time_ms:.3f} ms")
    
    return sorted_word_counts

# se lee el archivo y ejecuta la funcion
filename = '../texto.txt'
word_frequencies = count_word_frequency(filename)

# imprimir las palabras y su frecuencia
for word, frequency in word_frequencies:
    print(f"{word}: {frequency}")
