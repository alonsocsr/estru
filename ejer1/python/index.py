from collections import Counter
import re

#funcion para contar la frecuencia
def count_word_frequency(filename):
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
    
    return sorted_word_counts

# se lee el archivo y ejecuta la funcion
filename = '../texto.txt'
word_frequencies = count_word_frequency(filename)

# imprimir las palabras y su frecuencia
for word, frequency in word_frequencies:
    print(f"{word}: {frequency}")
