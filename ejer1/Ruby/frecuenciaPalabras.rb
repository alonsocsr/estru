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
  def mostrar_frecuencias(frecuencias, limite=20)
    frecuencias.sort_by { |palabra, cuenta| -cuenta }[0...limite].each do |palabra, cuenta|
      puts "#{palabra}: #{cuenta}"
    end
  end
  
  # Nombre del archivo de texto
  archivo = '../texto.txt'
  
  # Contar las palabras y mostrar las más frecuentes
  frecuencias = contar_palabras(archivo)
  mostrar_frecuencias(frecuencias)