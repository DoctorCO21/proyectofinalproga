#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    bool menu=1;
    string nombre;
    double ventas;
    double mayor_venta;
    string mayor_vendedor;
    double ventas_totales; 
    double comision;
    int id;
    int i;
    double comision_total; 
    double subtotal;
    double ganancias_finales;
    string usuario; 
    string clave; 
    int num_empleados;
    cout<<"INICIO DE SESION\n";
    cout<<"Usuario:          ";
    cin>>usuario;
    cout<<"\n";
    cout<<"Clave:       ";
    cin>>clave;
    cout<<"\n";
    cout<<"Cuantos empleados tiene?\n";
    cin>>num_empleados;
    string arr[num_empleados][4]; 

    cout<<"REGISTRO DE EMPLEADOS Y COMISIONES\n";
    ventas_totales = 0;
    comision_total = 0;
    mayor_venta = 0;
    mayor_vendedor = "";

    for (i=1; i<=num_empleados; i++){
        cout<<"Escriba su nombre\n";
        cin>>nombre;
        id = i-1;
        arr[id][0] = nombre;
        arr[id][1] = to_string(id);
        cout<<"Cuanto vendio en el mes?\n";
        cin>>ventas;
        ventas_totales = ventas_totales + ventas;
        arr[id][2] = to_string(ventas);
        if (ventas > mayor_venta){
            mayor_venta = ventas;
            mayor_vendedor = nombre;
        }
        if (ventas >= 5000){
            comision = ventas * 0.10 + 100;
            comision_total = comision_total + comision;
        }
        else{
            if (ventas >= 2500){
                comision = ventas * 0.10 + 50;
                comision_total = comision_total + comision;
            }
            else{
                comision = ventas * 0.10;
                comision_total = comision_total + comision;
            }
        }
        arr[id][3] = to_string(comision);
        cout<<"La comision de " + nombre + " es de " + to_string(comision) + " pesos.\n";
    }
    cout<<"En total se han vendido " + to_string(ventas_totales) + " pesos.\n";
    cout<<"El empleado con mas ventas fue " + mayor_vendedor + ". el recibe 300 extras.\n";
        
    if(clave == "Clave"){
        if(usuario == "Admin"){
            cout<<"Acceso Permitido\n";
            cout<<"GANANCIAS FINALES\n";
            subtotal = ventas_totales - comision_total - 300;
            cout<<"Subtotal:          " + to_string(subtotal) + "\n";
            cout<<"Impuesto:          " + to_string(ventas_totales*0.3) + "\n";
            ganancias_finales = subtotal - ventas_totales*0.3;
            cout<<"TOTAL:             " + to_string(ganancias_finales) + "\n";
        }
        else{
            cout<<"Acceso denegado, información clasificada.\n";
        }
    }
    else{
        cout<<"Acceso denegado, informacion clasificada.\n";
    }
}
