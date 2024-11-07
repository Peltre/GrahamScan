// Implementacion del algoritmo de Graham
// Por: Pedro Jesus Sotelo Arce
// Matricula: A01285371
// Fecha de ultima modificación 06/11/2024

// Librerias necesarias
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Punto {
    double x, y;
};

// Funcion para calcular el producto cruz de 3 puntos (para saber la dirección del giro)
double productoCruz(const Punto& p1, const Punto& p2, const Punto& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// Ordenamos los puntos por angulo respecto al punto de referencia
bool compare(const Punto& p1, const Punto& p2, const Punto& ref) {
    double cross = productoCruz(p1, p2, ref);
    if (cross == 0) {
        // Si estan en linea recta, comparamos la distancia
        return hypot(p1.x - ref.x, p1.y - ref.y) < hypot(p2.x - ref.x, p2.y - ref.y);
    }
    return cross > 0;
}

//Algoritmo de Graham
vector<Punto> grahamScan(vector<Punto>& puntos) {

    // Encontramos el punto mas bajo (Menor coordenada de Y)
    Punto ref = *min_element(puntos.begin(), puntos.end(), [](Punto a, Punto b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    // Ordenamos los puntos segun el angulo respecto al punto de referencia (mas bajo)
    sort(puntos.begin(), puntos.end(), [&](Punto a, Punto b) {
        return compare(a,b,ref);
    });

    // Aplicamos el graham scan para construir el cierre convexo
    vector<Punto> cierreConvexo = {puntos[0],puntos[1]};
    for (size_t i=2; i < puntos.size(); ++i) {
        while (cierreConvexo.size() > 1 && productoCruz(cierreConvexo[cierreConvexo.size() - 2], cierreConvexo.back(), puntos[i]) <= 0){
            cierreConvexo.pop_back();
        }
        cierreConvexo.push_back(puntos[i]);
    }
    return cierreConvexo;
}

int main() {
    ifstream archivoEntrada("puntos_aleatorios.txt");
    if (!archivoEntrada) {
        cerr << "Error al abrir el archivo de entrada" << endl;
        return 1;
    }

    vector<Punto> puntos;
    double x, y;
    char comma;
    
    // Leemos los puntos del archivo y asignamos 
    while (archivoEntrada >> x >> comma >> y) {
        puntos.push_back({x,y});
    }
    archivoEntrada.close();

    // Calculamos el cierre convexo
    vector<Punto> cierreConvexo = grahamScan(puntos);

    // Hacer el archivo de output para graficar los puntos
    ofstream archivoSalida("cierre_convexo.txt");
    for (auto it = cierreConvexo.rbegin(); it != cierreConvexo.rend(); ++it) {
        archivoSalida << it->x << "," << it->y << "\n";
    } 

    archivoSalida.close();
    cout << "Cierre convexo calculado efectivamente" << endl;
    return 0;
}
