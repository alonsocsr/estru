import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ContarPalabras {

    // Método para contar la frecuencia de cada palabra en un archivo
    public static Map<String, Integer> contarPalabras(String archivo) {
        Map<String, Integer> frecuencias = new HashMap<>();

        try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                // Dividir la línea en palabras utilizando expresiones regulares
                String[] palabras = linea.toLowerCase().split("\\W+");

                // Contar las palabras
                for (String palabra : palabras) {
                    if (!palabra.isEmpty()) {
                        frecuencias.put(palabra, frecuencias.getOrDefault(palabra, 0) + 1);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return frecuencias;
    }

    // Método para mostrar las palabras más frecuentes
    public static void mostrarFrecuencias(Map<String, Integer> frecuencias) {
        // Crear una lista de entradas del mapa
        List<Map.Entry<String, Integer>> lista = new ArrayList<>(frecuencias.entrySet());

        // Ordenar la lista por frecuencia (valor) en orden descendente
        Collections.sort(lista, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2) {
                return e2.getValue().compareTo(e1.getValue());
            }
        });

        // Mostrar todas las palabras con sus frecuencias
        for (Map.Entry<String, Integer> entry : lista) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }

    public static void main(String[] args) {
        String archivo = "../texto.txt";

        long startTime = System.currentTimeMillis();

        // Contar las palabras y mostrar las más frecuentes
        Map<String, Integer> frecuencias = contarPalabras(archivo);
        mostrarFrecuencias(frecuencias); 

        long endTime = System.currentTimeMillis();
        long tiempoEjecucion = endTime - startTime;

        System.out.println("Tiempo de ejecución: " + tiempoEjecucion + " milisegundos");
    }
}
