#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_Intentos 3 //Numero maximo de intentos para el Login

//Funciones para el empleado
void agendar_consultar_citas(){
	
#define MAX_CITAS 10 // Máximo de citas que se pueden guardar
    // Variables para almacenar la información de las citas
    char nombres[MAX_CITAS][100];
    char servicios[MAX_CITAS][100];
    char dias[MAX_CITAS][20];
    int horas[MAX_CITAS];
    
    int cantidadCitas = 0;
    int opcion;

    while (1) {
        // Mostrar el menú
        printf("\nMenu de opciones:\n");
        printf("1. Agendar una nueva cita\n");
        printf("2. Consultar citas guardadas\n");
        printf("3. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            if (cantidadCitas < MAX_CITAS) {
                // Agendar una nueva cita
                printf("Ingrese el nombre de la clienta: ");
                fgets(nombres[cantidadCitas], sizeof(nombres[cantidadCitas]), stdin);
                nombres[cantidadCitas][strcspn(nombres[cantidadCitas], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el dia de la cita (por ejemplo, Lunes): ");
                fgets(dias[cantidadCitas], sizeof(dias[cantidadCitas]), stdin);
                dias[cantidadCitas][strcspn(dias[cantidadCitas], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese la hora de la cita (en formato 24 horas, por ejemplo, 14 para 2 PM): ");
                scanf("%d", &horas[cantidadCitas]);
                getchar(); // Limpiar el buffer de entrada

                printf("Ingrese el servicio que desea realizar (por ejemplo, Corte de Cabello, Manicura): ");
                fgets(servicios[cantidadCitas], sizeof(servicios[cantidadCitas]), stdin);
                servicios[cantidadCitas][strcspn(servicios[cantidadCitas], "\n")] = '\0'; // Eliminar salto de línea

                cantidadCitas++; // Incrementar la cantidad de citas guardadas
                printf("Cita agendada exitosamente!\n");
            } else {
                printf("No se pueden guardar mas citas. El sistema está lleno.\n");
            }
        } else if (opcion == 2) {
            // Consultar las citas guardadas
            if (cantidadCitas == 0) {
                printf("No hay citas agendadas.\n");
            } else {
                printf("\nCitas agendadas:\n");
                for (int i = 0; i < cantidadCitas; i++) {
                    printf("\nCita %d:\n", i + 1);
                    printf("Nombre: %s\n", nombres[i]);
                    printf("Dia: %s\n", dias[i]);
                    printf("Hora: %d:00 horas\n", horas[i]);
                    printf("Servicio: %s\n", servicios[i]);
                }
            }
        } else if (opcion == 3) {
            // Salir del programa
            printf("Hasta luego\n");
            break;
        } else {
            printf("Opción no valida. Intente de nuevo.\n");
        }
        getchar();
        system("cls");
    }
}
void reportarServicio(){
	printf("===== Reportar Servicio =====\n");

#define MAX_SERVICIOS 10 // Máximo de servicios que se pueden reportar
    // Variables para almacenar la información de los servicios
    char empleados[MAX_SERVICIOS][100];
    char nombres_servicios[MAX_SERVICIOS][100];
    float precios[MAX_SERVICIOS];
    
    int cantidadServicios = 0;
    int opcion;

    while (1) {
        // Mostrar el menú
        printf("\nMenu de opciones:\n");
        printf("1. Reportar un nuevo servicio\n");
        printf("2. Consultar servicios reportados\n");
        printf("3. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            if (cantidadServicios < MAX_SERVICIOS) {
                // Reportar un nuevo servicio
                printf("Ingrese el nombre del empleado: ");
                fgets(empleados[cantidadServicios], sizeof(empleados[cantidadServicios]), stdin);
                empleados[cantidadServicios][strcspn(empleados[cantidadServicios], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el nombre del servicio realizado: ");
                fgets(nombres_servicios[cantidadServicios], sizeof(nombres_servicios[cantidadServicios]), stdin);
                nombres_servicios[cantidadServicios][strcspn(nombres_servicios[cantidadServicios], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el precio del servicio: ");
                scanf("%f", &precios[cantidadServicios]);
                getchar(); // Limpiar el buffer de entrada

                cantidadServicios++; // Incrementar la cantidad de servicios reportados
                printf("Servicio reportado exitosamente\n");
            } else {
                printf("No se pueden reportar mas servicios. El sistema esta lleno.\n");
            }
        } else if (opcion == 2) {
            // Consultar los servicios reportados
            if (cantidadServicios == 0) {
                printf("No hay servicios reportados.\n");
            } else {
                printf("\nServicios reportados:\n");
                for (int i = 0; i < cantidadServicios; i++) {
                    printf("\nServicio %d:\n", i + 1);
                    printf("Empleado: %s\n", empleados[i]);
                    printf("Servicio: %s\n", nombres_servicios[i]);
                    printf("Precio: %.2f\n", precios[i]);
                }
            }
        } else if (opcion == 3) {
            // Salir del programa
            printf("Hasta luego\n");
            break;
        } else {
            printf("Opción no válida. Intente de nuevo.\n");
        }
        getchar();
        system("cls");
    }
	printf("Rporte de servicio completado.\n");
}
int MenuEmpleado(){
	int opcion=0;
	
	do{
		//Limpiar pantalla
		system("cls");
		
		printf("1. Agendar/Consultar citas\n");
		printf("2. Reportar Servicio\n");
		printf("3. Salir.\n");
		printf("Seleccione una opcion: ");
		if(scanf("%d", &opcion)!=1){
			printf("Entrada no valida. Intente de nuevo.\n");
			while(getchar()!='\n'); //Limpiar el bufer de entrada
			continue; //Reintenta la entrada
		}
		
		switch(opcion){
			case 1:
				agendar_consultar_citas();
			case 2:
				reportarServicio();
				break;
			case 3:
				printf("Saliendo del sistema...\n");
				break;
			default:
				printf("Opcion no valida. Intente de nuevo.\n");
		}
		if(opcion!=3){
			printf("Presione Enter para regresar al menu...");
			getchar();
			getchar();
		}
	}while(opcion!=3);
}

//Funciones para el administrador
void registroPago(){
	printf("===== Registro de pago =====\n");
	
	#define MAX_PAGOS 10 // Máximo de pagos que se pueden registrar
	// Variables para almacenar la información de los pagos
    char empleados[MAX_PAGOS][100];
    char nombres_servicios[MAX_PAGOS][100];
    float precios[MAX_PAGOS];
    float pagos[MAX_PAGOS];
    
    int cantidadPagos = 0;
    int opcion;

    while (1) {
        // Mostrar el menú
        printf("\nMenu de opciones:\n");
        printf("1. Registrar un pago de servicio\n");
        printf("2. Consultar pagos registrados\n");
        printf("3. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            if (cantidadPagos < MAX_PAGOS) {
                // Registrar un pago de servicio
                printf("Ingrese el nombre del empleado: ");
                fgets(empleados[cantidadPagos], sizeof(empleados[cantidadPagos]), stdin);
                empleados[cantidadPagos][strcspn(empleados[cantidadPagos], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el nombre del servicio realizado: ");
                fgets(nombres_servicios[cantidadPagos], sizeof(nombres_servicios[cantidadPagos]), stdin);
                nombres_servicios[cantidadPagos][strcspn(nombres_servicios[cantidadPagos], "\n")] = '\0'; // Eliminar salto de línea

                printf("Ingrese el precio del servicio: ");
                scanf("%f", &precios[cantidadPagos]);
                getchar(); // Limpiar el buffer de entrada

                printf("Ingrese el pago realizado por el cliente: ");
                scanf("%f", &pagos[cantidadPagos]);
                getchar(); // Limpiar el buffer de entrada

                cantidadPagos++; // Incrementar la cantidad de pagos registrados
                printf("Pago registrado exitosamente!\n");
            } else {
                printf("No se pueden registrar más pagos. El sistema está lleno.\n");
            }
        } else if (opcion == 2) {
            // Consultar los pagos registrados
            if (cantidadPagos == 0) {
                printf("No hay pagos registrados.\n");
            } else {
                printf("\nPagos registrados:\n");
                for (int i = 0; i < cantidadPagos; i++) {
                    printf("\nPago %d:\n", i + 1);
                    printf("Empleado: %s\n", empleados[i]);
                    printf("Servicio: %s\n", nombres_servicios[i]);
                    printf("Precio: %.2f\n", precios[i]);
                    printf("Pago recibido: %.2f\n", pagos[i]);
                    printf("Cambio: %.2f\n", pagos[i] - precios[i]);
                }
            }
        } else if (opcion == 3) {
            // Salir del programa
            printf("Hasta luego\n");
            break;
        } else {
            printf("Opción no valida. Intente de nuevo.\n");
        }
        getchar();
        system("cls");
    }
}
void Servicios(){
	#define MAX_SERVICIOS 10
	#define MAX_NOMBRE 50
	printf("===== Servicios =====\n");
	
	    char nombres[MAX_SERVICIOS][MAX_NOMBRE] = {
        "Corte de cabello",
        "Manicure",
        "Pedicure",
        "Tinte de cabello",
        "Masaje relajante"
    };
    float precios[MAX_SERVICIOS] = {150.0, 200.0, 250.0, 500.0, 600.0};
    int cantidad = 5; // Numero de servicios registrados
    int opcion;

    do {
        printf("1. Consultar servicios\n");
        printf("2. Modificar un servicio\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            // Mostrar servicios
            printf("\n--- Servicios Registrados ---\n");
            for (int i = 0; i < cantidad; i++) {
                printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
            }
        } else if (opcion == 2) {
            // Modificar servicio
            int indice;
            float nuevoPrecio;

            printf("\n--- Servicios Registrados ---\n");
            for (int i = 0; i < cantidad; i++) {
                printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
            }

            printf("\nIngrese el numero del servicio que desea modificar: ");
            scanf("%d", &indice);

            if (indice < 1 || indice > cantidad) {
                printf("Numero de servicio invalido.\n");
                continue;
            }

            indice--; // Ajustar indice para el arreglo
            printf("Servicio seleccionado: %s - $%.2f\n", nombres[indice], precios[indice]);

            printf("Ingrese el nuevo precio: ");
            scanf("%f", &nuevoPrecio);

            if (nuevoPrecio <= 0) {
                printf("El precio debe ser mayor a 0.\n");
                continue;
            }

            precios[indice] = nuevoPrecio;
            printf("Precio actualizado correctamente.\n");
        } else if (opcion == 3) {
            printf("Saliendo del sistema...\n");
        } else {
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 3);
	//CODIGO PARA CONSULTAR LOS SERVICIOS REALIZADOS Y MODIFICARLOS SI ES NECESARIO

}
void Inventario(){
	#define MAX_PRODUCTOS 10 // Máximo de productos en el inventario
// Definimos la estructura de los productos
typedef struct {
    char nombre[100];    // Nombre del producto
    int cantidad;        // Cantidad en inventario
    float precio;        // Precio del producto
} Producto;

	printf("===== Inventario =====\n");
	Producto inventario[MAX_PRODUCTOS];  // Inventario de productos
    int cantidadProductos = 0;           // Número de productos registrados
    int opcion;
    
    while (1) {
        // Mostrar el menú de opciones
        printf("1. Agregar un nuevo producto\n");
        printf("2. Consultar inventario\n");
        printf("3. Actualizar cantidad de un producto\n");
        printf("4. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            if (cantidadProductos < MAX_PRODUCTOS) {
                // Agregar un nuevo producto
                printf("Ingrese el nombre del producto: ");
                fgets(inventario[cantidadProductos].nombre, sizeof(inventario[cantidadProductos].nombre), stdin);
                inventario[cantidadProductos].nombre[strcspn(inventario[cantidadProductos].nombre, "\n")] = '\0';  // Eliminar salto de línea

                printf("Ingrese la cantidad disponible: ");
                scanf("%d", &inventario[cantidadProductos].cantidad);

                printf("Ingrese el precio del producto: ");
                scanf("%f", &inventario[cantidadProductos].precio);
                getchar(); // Limpiar el buffer de entrada

                cantidadProductos++;  // Incrementar la cantidad de productos registrados
                printf("Producto agregado exitosamente!\n");
            } else {
                printf("El inventario está lleno. No se pueden agregar mas productos.\n");
            }
        } else if (opcion == 2) {
            // Consultar inventario
            if (cantidadProductos == 0) {
                printf("El inventario esta vacío.\n");
            } else {
                printf("\nInventario de productos:\n");
                for (int i = 0; i < cantidadProductos; i++) {
                    printf("\nProducto %d:\n", i + 1);
                    printf("Nombre: %s\n", inventario[i].nombre);
                    printf("Cantidad disponible: %d\n", inventario[i].cantidad);
                    printf("Precio: %.2f\n", inventario[i].precio);
                    printf("----------------------------\n");
                }
            }
        } else if (opcion == 3) {
            // Actualizar cantidad de un producto
            if (cantidadProductos == 0) {
                printf("El inventario esta vacio. No hay productos para actualizar.\n");
            } else {
                printf("Ingrese el nombre del producto a actualizar: ");
                char nombreProducto[100];
                fgets(nombreProducto, sizeof(nombreProducto), stdin);
                nombreProducto[strcspn(nombreProducto, "\n")] = '\0'; // Eliminar salto de línea

                int encontrado = 0;
                for (int i = 0; i < cantidadProductos; i++) {
                    if (strcmp(inventario[i].nombre, nombreProducto) == 0) {
                        printf("Producto encontrado: %s\n", inventario[i].nombre);
                        printf("Cantidad actual: %d\n", inventario[i].cantidad);
                        printf("Ingrese la nueva cantidad: ");
                        scanf("%d", &inventario[i].cantidad);
                        getchar(); // Limpiar el buffer de entrada
                        printf("Cantidad actualizada exitosamente!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("El producto no se encuentra en el inventario.\n");
                }
            }
        } else if (opcion == 4) {
            // Salir del programa
            printf("Hasta luego\n");
            break;
        } else {
            printf("Opcion no valida. Intente de nuevo.\n");
        }
        getchar();
        system("cls");
    }
}
void reportesFinancieros(){
	#define NUM_SERVICIOS 5
	printf("===== Reportes Financieros =====\n");
const char* empleados[NUM_SERVICIOS] = {"Juan Perez", "Ana Gomez", "Carlos Lopez", "Maria Diaz", "Luisa Torres"};
const char* servicios[NUM_SERVICIOS] = {"Corte de Cabello", "Manicura", "Pedicura", "Maquillaje", "Corte y Color"};
const float precios[NUM_SERVICIOS] = {20.5, 15.0, 18.0, 25.0, 35.0};
const float pagos[NUM_SERVICIOS] = {25.0, 15.0, 20.0, 30.0, 40.0};

	float totalIngresos = 0.0;
    float totalPagos = 0.0;
    float totalCambio = 0.0;


    for (int i = 0; i < NUM_SERVICIOS; i++) {
        float cambio = pagos[i] - precios[i];  // Calculamos el cambio que se entrega al cliente

        // Acumulamos los totales
        totalIngresos += precios[i];  // Ingreso por el servicio
        totalPagos += pagos[i];       // Monto pagado por el cliente
        totalCambio += cambio;        // Cambio entregado al cliente

        // Mostramos los detalles de cada servicio
        printf("Servicio %d:\n", i + 1);
        printf("Empleado: %s\n", empleados[i]);
        printf("Servicio: %s\n", servicios[i]);
        printf("Precio: %.2f\n", precios[i]);
        printf("Pago recibido: %.2f\n", pagos[i]);
        printf("Cambio: %.2f\n", cambio);
        printf("--------------------------\n");
    }

    // Mostramos los totales
    printf("\nTotales Financieros:\n");
    printf("Total de ingresos: %.2f\n", totalIngresos);
    printf("Total de pagos recibidos: %.2f\n", totalPagos);
    printf("Total de cambios entregados: %.2f\n", totalCambio);
    printf("=====================\n");
	//CODIGO PARA PODER CONSULTAR LOS REPORTES FINANCIEROS DE LA BASE DE DATOS
}
int MenuAdmin(){
	int opcion=0;
	
	do{
		//Limpiar pantalla
		system("cls");
		
		printf("1. Reportes Financieros\n");
		printf("2. Inventario\n");
		printf("3. Servicios\n");
		printf("4. Registrar Pago\n");
		printf("5. Agendar/Consultar Citas\n");
		printf("6. Salir.\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				reportesFinancieros();
				break;
			case 2:
				Inventario();
				break;
			case 3:
				Servicios();
				break;
			case 4:
				registroPago();
				break;
			case 5:
				agendar_consultar_citas();
				break;
			case 6:
				printf("Saliendo del sistema...\n");
				break;
			default:
				printf("Opcion no valida. Intente de nuevo.\n");
		}
		if(opcion!=6){
			printf("Presione Enter para regresar al menu...");
			getchar();
			getchar();
		}
	}while(opcion!=6);
}

//Funcion para el ingresar al sistema
int login(){
	//Credenciales de administrador y empleado
	char adminUsername[]="admin";
	char adminPassword[]="adminpass";
	
	char empleadoUsername[]="empleado";
	char empleadoPassword[]="empleadopass";
	
	char Username[30];
	char Password[30];
	int intentos=0;
	
	printf("-----LOGIN------\n");
	
	//Bucle para intentos de login
	while (intentos<MAX_Intentos){
		printf("Usuario: ");
		scanf("%29s", Username); //Limita a 29 caracteres para evitar desbordamiento
		printf("\nContrasena: ");
		scanf("%29s", Password);
		
		//Verificacion para administrador
		if(strcmp(adminUsername, Username)==0 && strcmp(adminPassword, Password)==0){
			printf("Bienvenido Administrador\n");
			return 1;
		}
		//Verificacion para empleado
		else if(strcmp(empleadoUsername, Username)==0 && strcmp(empleadoPassword, Password)==0){
			printf("Bienvenido Compañero\n");
			return 2;
		}
		else{
			printf("Usuario o contrasena incorrectos. Intentos restantes: %d\n", MAX_Intentos-intentos-1);
			intentos++;
		}
	}
	//Execede intentos
	printf("Demasiados intentos fallidos. Acceso denegado.\n");
	return 0;
}

void limpiarPantalla(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
//FUNCION PRINCIPAL
int main(){
	printf("******************* SISTEMA DE GESTION DE SERVICIOS********************\n");
	int loginRes=login();
	limpiarPantalla();
	
	//Menu para el Administrador
	if(loginRes==1){
		printf("Acceso al panel de administrador...\n");
		MenuAdmin();
	}
	//Menu para el empleado
	else if(loginRes==2){
		printf("Acceso al panel de empleado...\n");
		MenuEmpleado();
	}
	else{
		printf("Saliendo del sistema.\n");
	}
	return 0;
}