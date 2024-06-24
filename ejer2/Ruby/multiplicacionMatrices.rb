require 'csv'
require 'benchmark'

# Función para generar una matriz aleatoriamente
def generar_matriz_aleatoria(filas, columnas)
  Array.new(filas) { Array.new(columnas) { rand(10) } }
end

# Función para escribir varias matrices en un archivo CSV
def escribir_varias_matrices_en_archivo(matrices, nombres, nombre_archivo)
  CSV.open(nombre_archivo, "w") do |csv|
    matrices.each_with_index do |matriz, index|
      csv << [nombres[index]]
      matriz.each { |fila| csv << fila }
      csv << [] # Para dejar una línea en blanco entre cada matriz
    end
  end
end

# Función para multiplicar dos matrices y medir el tiempo de ejecución
def multiplicar_matrices(filas_a, columnas_a, filas_b, columnas_b)
  matriz_a = generar_matriz_aleatoria(filas_a, columnas_a)
  matriz_b = generar_matriz_aleatoria(filas_b, columnas_b)

  resultado = Array.new(filas_a) { Array.new(columnas_b, 0) }

  tiempo = Benchmark.realtime do
    filas_a.times do |i|
      columnas_b.times do |j|
        columnas_a.times do |k|
          resultado[i][j] += matriz_a[i][k] * matriz_b[k][j]
        end
      end
    end
  end

  # Escribir todas las matrices en un solo archivo CSV
  matrices_para_escribir = [matriz_a, matriz_b, resultado]
  nombres_matrices = ["Matriz A (#{filas_a}x#{columnas_a}):", "Matriz B (#{filas_b}x#{columnas_b}):", "Resultado de la multiplicación:"]
  escribir_varias_matrices_en_archivo(matrices_para_escribir, nombres_matrices, 'matrices_result.csv')

  tiempo_ms = (tiempo * 1000).round(4)
  puts "\nTiempo de ejecución para multiplicar matrices de tamaño #{filas_a}x#{columnas_a} y #{filas_b}x#{columnas_b}: #{tiempo_ms} milisegundos"
end

puts "Ingrese el número de filas de la matriz A: "
filas_a = gets.chomp.to_i
puts "Ingrese el número de columnas de la matriz A: "
columnas_a = gets.chomp.to_i
puts "Ingrese el número de filas de la matriz B: "
filas_b = gets.chomp.to_i
puts "Ingrese el número de columnas de la matriz B: "
columnas_b = gets.chomp.to_i

if columnas_a != filas_b
  puts "No se pueden multiplicar las matrices. Las columnas de A deben ser igual a las filas de B."
  exit
end

multiplicar_matrices(filas_a, columnas_a, filas_b, columnas_b)
