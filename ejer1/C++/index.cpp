// C++ program to calculate the frequency
// of each word in the given string
 
#include <bits/stdc++.h>

using namespace std;


/*ordenar*/
// funcion que compara pares para ordenar
bool cmp(pair<string, int>& a, pair<string, int>& b) 
{ 
    return a.second > b.second; 
} 
 

// funcion que ordena el map de acuerdo al valor en un para (clave-valor)
void sort(map<string, int>& M) 
{ 
 
    //se declara el vector de pares
    vector<pair<string, int> > A; 
 
    // copia la clave valor del map
    for (auto& it : M) { 
        A.push_back(it); 
    } 
 
    // ordena usando la funcion comparadora 
    sort(A.begin(), A.end(), cmp); 
 
    // imprimir los valores ordenados 
    for (auto& it : A) {
        cout << it.first << ' '
            << it.second << endl; 
    } 
} 


int main()
{

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    /*puntero al archivo*/
    ifstream file;
    //se abre el archivo en modo lectura
    file.open("../texto.txt", ios::in);
    //falla en abrir
    if(file.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    /*cadena que lee cada linea del archivo*/
    string text;

    //variable para mapear cada palabra y su contador de frecuencia
    map<string, int> M;

    /*mientras no sea el final del archivo*/
    while(!file.eof()){
        getline(file, text);

        // cadena para guardar las palabras
        string word = "";
    
        for (int i = 0; i < text.size(); i++) {
    
            // verificar si la cadena actual
            // es un espacio en blanco
            // entonces se tiene una palabra
            if (text[i] == ' ') {
    
                // Si la palabra no se encuentra entonces
                // inserta con frecuencia 1
                if (M.find(word) == M.end()) {
                    M.insert(make_pair(word, 1));
                    word = "";
                }
    
                // se actualiza la frecuencia
                else {
                    M[word]++;
                    word = "";
                }
            } //coma o punto tambien indica que te una palabra
              // dps existe un espacio por lo que se mueve el contador 
            else if (text[i] == ',' || text[i] == '.') {

                if (M.find(word) == M.end()) {
                    M.insert(make_pair(word, 1));
                    word = "";
                }
    
                // se actualiza la frecuencia
                else {
                    M[word]++;
                    word = "";
                }
                i++; //mover contador por el siguiente espacio
            }    
            else
                word += tolower(text[i]);
        }
    
        //Se guarda la ultima palabra
        if (M.find(word) == M.end())
            M.insert(make_pair(word, 1));
    
        // se aumenta la frecuencia
        else
            M[word]++;
    }

    file.close();

    sort(M);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Execution time: " << elapsed.count() << " ms" << endl;
    
    return 0;
}