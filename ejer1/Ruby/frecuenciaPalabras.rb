require 'benchmark'

# Método para leer un archivo y contar la frecuencia de cada palabra
def contar_palabras(archivo)
    frecuencias = Hash.new(0) # Hash para almacenar la frecuencia de cada palabra
  
    # Leer el archivo línea por línea
    File.foreach(archivo) do |linea|
      # Dividir cada línea en palabras, eliminar caracteres no deseados y convertir a minúsculas
      
      # Expresion regular:
      #   \b: Marca un límite de palabra (word boundary). Esto asegura que las coincidencias comiencen y terminen en los límites de las palabras, evitando que se tomen fragmentos de palabras.
      #   [\w']: Coincide con cualquier carácter de palabra (\w incluye letras, dígitos y guiones bajos) o un apóstrofe (')
      #   +: Indica que el conjunto anterior debe aparecer una o más veces, es decir, coincidir con palabras completas.

      palabras = linea.downcase.scan(/\b[\w']+\b/)
      palabras.each { |palabra| frecuencias[palabra] += 1 }
    end
  
    frecuencias
  end
  
  # Método para mostrar las palabras más frecuentes
  def mostrar_frecuencias(frecuencias)
    frecuencias.sort_by { |palabra, cuenta| -cuenta }.each do |palabra, cuenta|
      puts "#{palabra}: #{cuenta}"
    end
  end
  
  # Nombre del archivo de texto
  archivo = '../texto.txt'

  # Medir el tiempo de ejecución del conteo de palabras y mostrar las palabras más frecuentes
  tiempo = Benchmark.measure do
    frecuencias = contar_palabras(archivo)
    mostrar_frecuencias(frecuencias)
  end
  
  tiempo_ms = tiempo.real * 1000
  puts "Tiempo de ejecución: #{tiempo_ms.round(2)} milisegundos"

  