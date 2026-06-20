#include <iostream>
#include <string>
using namespace std;

// Variables globales básicas
string nombreCliente;
int edadCliente;
int totalVerduras;
int totalCarnes;
int totalLicores;
int tipoCliente;
int diaSemana;
int opcion;

// Inventario inicial
int cantidadTomates = 350, cantidadRepollo = 300, cantidadPapas = 250;
int cantidadMolida = 140, cantidadCerdo = 150, cantidadAsar = 180;
int cantidadNacional = 110, cantidadExtranjera = 100, cantidadVino = 200, cantidadVodka = 200;

// Totales
float totalVenta = 0;

// Prototipos
void registrarCliente();
void menuVerduras();
void menuCarnes();
void menuLicores();
void menuInventario();
void mostrarFactura();

int main() {
    registrarCliente();

    do {
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
             << "             Bienvenido a Puma Market\n"
             << "+++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "1. Area de Verduras \n";
        cout << "2. Area de Carnes\n";
        if (edadCliente >= 18){
            cout << "3. Area de Licores\n";
        }else{
            cout << "3. El area no esta disponible para menores de edad. \n";
        }
        cout << "4. Inventario\n";
        cout << "5. Factura\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuVerduras(); break;
            case 2: menuCarnes(); break;
            case 3: menuLicores(); break;
            case 4: menuInventario(); break;
            case 5: mostrarFactura(); break;
            case 6: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    } while (opcion != 6);

    return 0;
}

// Módulos iniciales temporales
void registrarCliente() {
     cout << "\n===== REGISTRO DEL CLIENTE =====\n";

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombreCliente);

    do {
        cout << "Ingrese la edad del cliente: ";
        cin >> edadCliente;
        if (edadCliente < 6 || edadCliente > 105){
            cout << "ERROR: La edad que ingreso es invalida. \n";
        }
    } while (edadCliente < 6 || edadCliente > 105);
    
    do {
        cout << "Ingrese el tipo de cliente: ";
        cin >> tipoCliente;

        if (tipoCliente < 1 || tipoCliente > 3) {
            cout << "ERROR:El tipo de cliente que ingreso es Invalido.\n";
        }
    } while (tipoCliente < 1 || tipoCliente > 3);

     cout << "\nCliente registrado correctamente.\n";
}

void menuVerduras() {
     int opcionVL, cantidad;

    cout << "\n===== BIENVENIDOS AL AREA DE VERDURAS =====\n";
    cout << "1. Tomates - L.10 - Disponible: " << cantidadTomates << endl;
    cout << "2. Repollo     - L.15 - Disponible: " << cantidadRepollo << endl;
    cout << "3. Papas  - L.17 - Disponible: " << cantidadPapas << endl;
    cout << "Seleccione producto: ";
    cin >> opcionVL;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "ERROR: Cantidad no valida.\n";
        return;
    }

    switch (opcionVL) {
        case 1:
            if (cantidad <= cantidadTomates) {
                cantidadTomates -= cantidad;
                totalVerduras += cantidad * 10;
                cout << "Tomates agregados correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 2:
            if (cantidad <= cantidadRepollo) {
                cantidadRepollo -= cantidad;
                totalVerduras += cantidad * 17;
                cout << "Repollo agregado correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 3:
            if (cantidad <= cantidadPapas) {
                cantidadPapas -= cantidad;
                totalVerduras += cantidad * 17;
                cout << "Papas agregadas correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        default:
            cout << "Opcion no valida.\n";
    }
}

void menuCarnes() {
     int opcionVL, cantidad;

    cout << "\n===== BIENVENIDO AL AREA DE CARNES =====\n";
    cout << "1. Carne Molida - L.50 - Disponible: " << cantidadMolida << endl;
    cout << "2. Carne de Cerdo     - L.70 - Disponible: " << cantidadCerdo << endl;
    cout << "3. Carne para Asar  - L.75 - Disponible: " << cantidadAsar << endl;
    cout << "Seleccione producto: ";
    cin >> opcionVL;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "ERROR: Cantidad no valida.\n";
        return;
    }

    switch (opcionVL) {
        case 1:
            if (cantidad <= cantidadMolida) {
                cantidadMolida -= cantidad;
                totalCarnes += cantidad * 50;
                cout << "Carne Molida agregada correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 2:
            if (cantidad <= cantidadCerdo) {
                cantidadCerdo -= cantidad;
                totalVerduras += cantidad * 70;
                cout << "Carne de Cerdo agregada correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 3:
            if (cantidad <= cantidadAsar) {
                cantidadAsar -= cantidad;
                totalVerduras += cantidad * 75;
                cout << "Carne para Asar agregada correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        default:
            cout << "Opcion no valida.\n";
    }
}

void menuLicores(){
    if(edadCliente < 18 ){
        cout << "El area 3 no esta disponible para menores de edad. \n";
    }else {
    int opcionVL, cantidad;
     cout << "\n===== BIENVENIDO AL AREA DE LICORES =====\n";
    cout << "1. Cerveza Nacional - L.50 - Disponible: " << cantidadNacional << endl;
    cout << "2. Cerveza Extranjera    - L.80 - Disponible: " << cantidadExtranjera << endl;
    cout << "3. Vino  - L.200 - Disponible: " << cantidadVino << endl;
    cout << "4. Vodka  - L.100 - Disponible: " << cantidadVodka << endl;
    cout << "Seleccione producto: ";
    cin >> opcionVL;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "ERROR: Cantidad no valida.\n";
        return;
    }

    switch (opcionVL) {
        case 1:
            if (cantidad <= cantidadNacional) {
                cantidadNacional -= cantidad;
                totalLicores += cantidad * 50;
                cout << "Cerveza Nacional agregada correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 2:
            if (cantidad <= cantidadExtranjera) {
                cantidadExtranjera -= cantidad;
                totalLicores += cantidad * 80;
                cout << "Cerveza Extranjera agregada correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 3:
            if (cantidad <= cantidadVino) {
                cantidadVino -= cantidad;
                totalLicores += cantidad * 200;
                cout << "Vinos agregados correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;
            
         case 4:
            if (cantidad <= cantidadVodka) {
                cantidadVodka -= cantidad;
                totalLicores += cantidad * 100;
                cout << "Vodka agregado correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        default:
            cout << "Opcion no valida.\n";
    }        
}
   
}

void menuInventario() {
   int opcionInv, cantidad;

    cout << "\n===== INVENTARIO ACTUAL =====\n";
    cout << "1. Tomates:     " << cantidadTomates << endl;
    cout << "2. Repollo:         " << cantidadRepollo << endl;
    cout << "3. Papas:      " << cantidadPapas << endl;
    cout << "4. Carne Molida:       " << cantidadMolida << endl;
    cout << "5. Carne de Cerdo:  " << cantidadCerdo << endl;
    cout << "6. Carne para Asar:   " << cantidadAsar << endl;
    cout << "7. Cerveza Nacional:   " << cantidadNacional << endl;
    cout << "8. Cerveza Extranjera:   " << cantidadExtranjera << endl;
    cout << "9. Vino:   " << cantidadVino << endl;
    cout << "10. Vodka:   " << cantidadVodka << endl;

    cout << "\nSeleccione producto para ingresar inventario: ";
    cin >> opcionInv;

    cout << "Cantidad a ingresar: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "ERROR: Cantidad no valida.\n";
        return;
    }

    switch (opcionInv) {
        case 1: cantidadTomates+= cantidad; break;
        case 2: cantidadRepollo += cantidad; break;
        case 3: cantidadPapas += cantidad; break;
        case 4: cantidadMolida += cantidad; break;
        case 5: cantidadCerdo += cantidad; break;
        case 6: cantidadAsar += cantidad; break;
        case 7: cantidadNacional += cantidad; break;
        case 8: cantidadExtranjera += cantidad; break;
        case 9: cantidadVino += cantidad; break;
        case 10: cantidadVodka += cantidad; break;
        default:
            cout << "Opcion no valida.\n";
            return;
    }

    cout << "Inventario actualizado correctamente.\n";
}

void descuentos(){
    cout << "Descuentos \n";
}
void impuestos(){
    cout << "Impuestos \n";
}
void mostrarFactura() {
    cout << "Modulo factura pendiente de desarrollo.\n";
}
