

#include <iostream>
#include <string>
using namespace std;





    /*
Nombre del estudiante: Josue Alvear
Fecha: 09/09/2026
Tema: registro de notas finales de un grupo de estudiantes yconsultar información básica del curso
Entrada: notas, opción del menú y nombre a buscar
Proceso: validar, almacenar, recorrer, calcular y buscar
Salida: reporte general y resultado de búsqueda
*/
int MostrarMenu();
void registrarEstudiantes(string Estudiante[], double Nota[], int &contador);

int main (){

    string Estudiante[20];
    double Nota[20];

    int contador = 0;

    int Opcion; 



    do{
        Opcion =  MostrarMenu();

        switch (Opcion) {
            case 1:

                registrarEstudiantes(Estudiante, Nota, contador);
                break;
            case 2:
                
                break;
            case 3:
              
                break;
            case 4:
                
                break;
            default:
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
        }
    }while (Opcion != 4);

    return 0;
}


int MostrarMenu(){

    int Opcion; 

    do{

        cout << "==============  BIENVENIDO AL MENU DEL SISTEMA =============" << endl;
        cout << "1. Ingresar notas de los estudiantes" << endl;
        cout << "2. Mostrar reporte general" << endl;
        cout << "3. Buscar estudiante por nombre" << endl;
        cout << "4. Salir" << endl;
        cin >> Opcion;

        if (Opcion < 1 ||    Opcion > 4) {
            
            cout << "Opción inválida Por favor, intente nuevamente." << endl;
        }



    } while (Opcion < 1 || Opcion > 4);
      

    return Opcion;

}


void registrarEstudiantes(string Estudiante[], double Nota[], int &contador) {

    int cantidad;

    do{
        cout << "Ingrese la cantidad de estudiantes a registrar (1-20): ";
        cin >> cantidad;

        if (cantidad < 1 || cantidad > 20) {
            cout << "Cantidad inválida. Intente nuevamente." << endl;
        }
    } while (cantidad < 1 || cantidad > 20);

    contador = cantidad; 

    for (int i = 0; i < cantidad; i++) {

        cout << "Ingrese el nombre del estudiante " << (i + 1) << ": ";
        cin >> Estudiante[i];

        double notaIngresada;

        
        do {
            cout << "Ingrese la nota de " << Estudiante[i] << " (0-20): ";
            cin >> notaIngresada;

            if (notaIngresada < 0 || notaIngresada > 20) {
                cout << "Nota inválida. Intente nuevamente." << endl;
            }
        } while (notaIngresada < 0 || notaIngresada > 20);

        Nota[i] = notaIngresada;
    }

    cout << "Estudiantes registrados con éxito." << endl;
}// tiene un error en consola.. ingresando 5 o mas estudiantes la consola se vuelve loca

void mostrarReporte(string Estudiante[], double Nota[], int contador) {

    
    cout << "\n===== REPORTE GENERAL =====" << endl;
    for (int i = 0; i < contador; i++) {
        cout << (i + 1) << ". " << Estudiante[i] << " - Nota: " << Nota[i];
        if (Nota[i] >= 14) {
            cout << " - APROBADO" << endl;
        } else {
            cout << " - REPROBADO" << endl;
        }
    }

   
    double sumaNotas = Nota[0];
    int indiceMayor = 0;
    int indiceMenor = 0;
    int aprobados = (Nota[0] >= 14) ? 1 : 0;
    int reprobados = (Nota[0] >= 14) ? 0 : 1;

   
    for (int i = 1; i < contador; i++) {
        sumaNotas += Nota[i];

        if (Nota[i] > Nota[indiceMayor]) {
            indiceMayor = i;
        }
        if (Nota[i] < Nota[indiceMenor]) {
            indiceMenor = i;
        }

        if (Nota[i] >= 14) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    double promedio = sumaNotas / contador;

   
    cout << "\nPromedio general: " << promedio << endl;
    cout << "Estudiante con nota mayor: " << Estudiante[indiceMayor] << " (" << Nota[indiceMayor] << ")" << endl;
    cout << "Estudiante con nota menor: " << Estudiante[indiceMenor] << " (" << Nota[indiceMenor] << ")" << endl;
    cout << "Cantidad de aprobados: " << aprobados << endl;
    cout << "Cantidad de reprobados: " << reprobados << endl;
}

void buscarEstudiante(string Estudiante[], double Nota[], int contador) {

    string nombreBuscado;
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscado;

    int indiceEncontrado = -1; 

    for (int i = 0; i < contador; i++) {
        if (Estudiante[i] == nombreBuscado) {
            indiceEncontrado = i;
            break; 
        }
    }

    if (indiceEncontrado != -1) {
        cout << "\nEstudiante encontrado:" << endl;
        cout << "Nombre: " << Estudiante[indiceEncontrado] << endl;
        cout << "Nota: " << Nota[indiceEncontrado] << endl;
        if (Nota[indiceEncontrado] >= 14) {
            cout << "Estado: APROBADO" << endl;
        } else {
            cout << "Estado: REPROBADO" << endl;
        }
    } else {
        cout << "No se encontró ningún estudiante con ese nombre." << endl;
    }
}


