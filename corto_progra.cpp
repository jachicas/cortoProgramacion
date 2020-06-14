#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

// Declarando las funciones que ejecutaran cada ejercicio
void Ejercicio1();
void Ejercicio2();
void Ejercicio3();

int main()
{

    int opcion;
    do
    {
        // Eligiendo el ejercicio a desarrollar
        printf("--- Tercer corto de programacion --- \n");
        printf("1- Calculo de salarios \n2- El numero magico \n3- Anio Bisiesto \n");
        cout << "--- Eliga un numero ---" << endl;
        cin >> opcion;
        // Limpiar el buffer de teclado
        cin.ignore();
        // Aqui seleccionamos que ejercicio queremos hacer
        switch (opcion)
        {
        case 1:
            Ejercicio1();
            break;

        case 2:
            Ejercicio2();
            break;
        case 3:
            Ejercicio3();
            break;
        }
    } while (opcion > 0 || opcion < 3);
    return 0;
}

void Ejercicio1()
{
    int num_empleado;
    cout << "--- Calculo de salarios ---" << endl;
    cout << "Ingrese la cantidad de empleados que desea calcular su salario \n";
    cin >> num_empleado;
    int horas_normales[num_empleado], horas_extras[num_empleado];
    float salario_total[num_empleado], salario_real[num_empleado];
    string nombre_empleado[num_empleado];
    for (int i = 0; i < num_empleado; i++)
    {
        cout << "-- Ingrese el nombre del empleado " << i + 1 << " --" << endl;
        cin >> nombre_empleado[i];
        // SALARIOS
        cout << "-- Ingrese el horas normales del empleado " << nombre_empleado[i] << " --" << endl;
        cin >> horas_normales[i];
        cout << endl;
        // HORAS EXTRAS
        cout << "-- Ingrese las horas extras del empleado " << nombre_empleado[i] << " --" << endl;
        cin >> horas_extras[i];
        cout << endl;
        // SALARIO TOTAL
        salario_total[i] = (horas_normales[i] * 1.75) + (horas_extras[i] * 2.50);
        // SALARIO REAL
        salario_real[i] = salario_total[i] - (salario_total[i] * 0.04) - (salario_total[i] * 0.0625) - (salario_total[i] > 500 ? (salario_total[i] * 0.10) : 0);
    }
    for (int i = 0; i < num_empleado; i++)
    {
        cout << fixed;
        cout << setprecision(2);
        cout << "Salario total de " << nombre_empleado[i] << " es de $" << salario_total[i] << " y salario real es $" << salario_real[i] << endl;
    }
}

void Ejercicio2()
{
    printf("--- Bienvenido al juego 'Adivina el numero' --- \n");
    /* Se crea 4 variables 
        'numero' contendra el numero aleatorio del 1-100
        'intentos=5' sera para los intentos, como valor inicial tendra 5
        'num_ingresado' es el numero que el usuario ingresara
        'ganador=false' este sera el estadoo inicial, si logra adivinar
        el estado pasara a 'true'
     */
    int numero, intentos = 5, num_ingresado;
    string ingresado = "";
    bool ganador = false;
    int tecla;
    ;

    /* Esta es la funcion se asegura que una serie de numeros no se repita
        tomando un valor tiempo gracias a la funcion time()
     */
    srand((unsigned)time(0));

    /*
        Aqui se establece el numero maximo para buscar un numero random 
    */
    numero = rand() % 100;
    /*
        Ejecutamos un do para hacer que el programa no se cierre y 
        se pueda usar los intentos
    */
    do
    {
        // Le pedimos que ingrese un numero al usuario
        cout << "-- Elige un numero entre 1 y 100 para ganar (Si deseas salir escribe la letra 'S') --" << endl;
        // Sirve para leer la cadena que se ha ingresado
        getline(cin, ingresado);
        cout << endl;

        // Se compara si el valor ingresado es igual a 'S' para cerrar el programa
        if (ingresado == "s" || ingresado == "S")
        {
            cout << "Te quedaban: " << intentos << " intentos" << endl;
            cout << "GAME OVER" << endl;
            return;
        }
        else
        {
            // Convierte el valor ingresado del teclado a un entero
            num_ingresado = stoi(ingresado);
            if (num_ingresado < 0 || num_ingresado > 100)
            {
                cout << "Ingrese un numero entre 1-100";
                intentos = intentos - 1;
            }
            else
            {
                /*
                    Abrimos la logica con un if 
                    El primer if valida si el numero es menor se le pedira que ingrese un mayor 
                    El segundo if valida si el numero es mayor se le pedira que ingrese uno menor
                    El tercero valida si el numero es valido o no (si esta en el rango 1-100)
                    Y por ultimo vaidamos que el usuario ganor y cambiamos el estado de ganador=true
                */
                if (num_ingresado < numero)
                {
                    cout << "---- No, elige un numero MAYOR ---- \n";
                    // Restamos un intento
                    intentos = intentos - 1;
                    cout << "Te quedan: " << intentos << " intentos" << endl;
                }
                else if (num_ingresado > numero)
                {
                    cout << "---- No, elige un numero MENOR ---- \n";
                    //Restamos un intento
                    intentos = intentos - 1;
                    cout << "Te quedan: " << intentos << " intentos" << endl;
                }
                else if (num_ingresado == numero)
                {
                    cout << "FELICITACIONES GANASTE EL JUEGO!";
                    ganador = true;
                    return;
                }
            }
        }

    } while ((intentos > 0 && intentos <= 5) || ganador == true);
    /*
        Una vez pasado el while, que valida que los intentos y si el el jugador ha ganado
        Por ultimo mostramos el numero se habia elegido aleatoriamente
    */
    cout << "PERDISTE! \n";
    cout << " ---- El numero era: " << numero << " ----";
}

void Ejercicio3()
{
    // Declaramos variable para el anio
    int anio;
    // Le pedimos que ingrese un anio
    cout << "-- Ingresa un anio para verificar si es bisiesto --" << endl;
    cin >> anio;
    // Hacemos las comparaciones para ver si es bisiesto
    if (anio % 400 == 0 || anio % 4 == 0 && anio % 100 != 0)
    {
        cout << "Este anio es bisiesto" << endl << endl;
    }
    else
    {
        cout << "---- No es bisiesto ----" << endl << endl;
    }
}