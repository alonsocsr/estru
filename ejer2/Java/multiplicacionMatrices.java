import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class multiplicacionMatrices {

    // Función para generar una matriz aleatoria
    public static int[][] generarMatrizAleatoria(int filas, int columnas) {
        int[][] matriz = new int[filas][columnas];
        Random random = new Random();
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j] = random.nextInt(10); // Números aleatorios entre 0 y 9
            }
        }
        return matriz;
    }

    // Función para imprimir una matriz en consola
    public static void imprimirMatriz(int[][] matriz) {
        for (int[] fila : matriz) {
            for (int valor : fila) {
                System.out.print(valor + " ");
            }
            System.out.println();
        }
    }

    // Función para escribir una matriz en un archivo CSV
    public static void escribirMatrizEnCSV(int[][] matriz, String nombreArchivo, String encabezado) {
        try (FileWriter writer = new FileWriter(nombreArchivo, true)) {
            writer.append(encabezado + "\n");
            for (int[] fila : matriz) {
                for (int i = 0; i < fila.length; i++) {
                    writer.append(String.valueOf(fila[i]));
                    if (i < fila.length - 1) {
                        writer.append(",");
                    }
                }
                writer.append("\n");
            }
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Función para multiplicar dos matrices y medir el tiempo de ejecución
    public static void multiplicarMatrices(int filasA, int columnasA, int filasB, int columnasB) {
        int[][] matrizA = generarMatrizAleatoria(filasA, columnasA);
        int[][] matrizB = generarMatrizAleatoria(filasB, columnasB);

        // Imprimir las matrices A y B
        System.out.println("Matriz A (" + filasA + "x" + columnasA + "):");
        imprimirMatriz(matrizA);
        System.out.println("\nMatriz B (" + filasB + "x" + columnasB + "):");
        imprimirMatriz(matrizB);

        // Medir el tiempo de ejecución
        long startTime = System.nanoTime();

        // Multiplicar las matrices
        int[][] resultado = new int[filasA][columnasB];
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < columnasB; j++) {
                for (int k = 0; k < columnasA; k++) {
                    resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                }
            }
        }

        // Escribir todas las matrices en un archivo CSV
        escribirMatrizEnCSV(matrizA, "resul.csv", "Matriz A (" + filasA + "x" + columnasA + "):");
        escribirMatrizEnCSV(matrizB, "resul.csv", "Matriz B (" + filasB + "x" + columnasB + "):");
        escribirMatrizEnCSV(resultado, "resul.csv", "Resultado de la multiplicacion:");

        // Calcular y mostrar el tiempo de ejecución
        long endTime = System.nanoTime();
        long tiempoNano = endTime - startTime;
        double tiempoMs = tiempoNano / 1_000_000.0; // Convertir nanosegundos a milisegundos

        System.out.println("\nTiempo de ejecución para multiplicar matrices de tamaño "
                + filasA + "x" + columnasA + " y " + filasB + "x" + columnasB + ": " + tiempoMs + " milisegundos");
    }

    public static void main(String[] args) {
        int filasA = 3;
        int columnasA = 2;
        int filasB = 2;
        int columnasB = 3;

        multiplicarMatrices(filasA, columnasA, filasB, columnasB);
    }
}
