#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cctype>

using namespace std;

// Funcion que compara pares para ordenar
bool cmp(pair<string, int>& a, pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 

// Funcion que ordena el map de acuerdo al valor en un para (clave-valor)
void sort(map<string, int>& M) 
{ 
    // Se declara el vector de pares
    vector<pair<string, int>> A; 
    
    // Copia la clave valor del map al vector
    for (auto& it : M) { 
        A.push_back(it); 
    } 
    
    // Ordena usando la funcion comparadora 
    sort(A.begin(), A.end(), cmp); 
    
    // Construye el resultado como una cadena separada por newline
    string result;
    for (auto& it : A) {
        result += it.first + ' ' + to_string(it.second) + '\n';
    }
    
    // Imprime el resultado
    cout << result;
} 

int main()
{
    // Mide el tiempo de ejecucion
    auto start = chrono::high_resolution_clock::now();

    /* Puntero al archivo */
    ifstream file;
    // Se abre el archivo en modo lectura
    file.open("../texto.txt", ios::in);
    // Falla en abrir
    if(file.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    /* Cadena que lee cada linea del archivo */
    string text;

    // Variable para mapear cada palabra y su contador de frecuencia
    map<string, int> M;

    /* Mientras no sea el final del archivo */
    while(!file.eof()){
        getline(file, text);

        // Cadena para guardar las palabras
        string word = "";
    
        for (int i = 0; i < text.size(); i++) {
    
            // Verificar si la cadena actual es un espacio en blanco
            // Entonces se tiene una palabra
            if (text[i] == ' ') {
    
                // Si la palabra no se encuentra entonces inserta con frecuencia 1
                if (M.find(word) == M.end()) {
                    M.insert(make_pair(word, 1));
                    word = "";
                }
    
                // Se actualiza la frecuencia
                else {
                    M[word]++;
                    word = "";
                }
            } // Coma o punto tambien indica que te una palabra
              // Despues existe un espacio por lo que se mueve el contador 
            else if (text[i] == ',' || text[i] == '.') {

                if (M.find(word) == M.end()) {
                    M.insert(make_pair(word, 1));
                    word = "";
                }
    
                // Se actualiza la frecuencia
                else {
                    M[word]++;
                    word = "";
                }
                i++; // Mover contador por el siguiente espacio
            }    
            else
                word += tolower(text[i]);
        }
    
        // Se guarda la ultima palabra
        if (M.find(word) == M.end())
            M.insert(make_pair(word, 1));
    
        // Se aumenta la frecuencia
        else
            M[word]++;
    }

    file.close();

    // Ordena y genera la salida como una cadena separada por newline
    sort(M);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Execution time: " << elapsed.count() << " ms" << endl;
    
    return 0;
}
