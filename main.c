#include <stdio.h>
#include "funciones.h"

int main()
{
    Libro libros[MAX_LIBROS];
    int contador = 0;
    int opcion, len;

    do
    {
        printf("\nBiblioteca - Menú\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        
        // Validar que sea un número válido entre 1 y 6
        do
        {
            printf("Seleccione una opción (1-6): ");
            fflush(stdin);
            len = scanf("%d", &opcion);
            
            if (len == 0 || opcion < 1 || opcion > 6)
            {
                printf("Ingrese una opción válida (1-6)\n");
                fflush(stdin); // Limpiar el buffer en caso de error
            }
        } while (len != 1 || opcion < 1 || opcion > 6);

        switch (opcion)
        {
        case 1:
            registrarLibro(libros, &contador);
            break;
        case 2:
            mostrarLibros(libros, contador);
            break;
        case 3:
            buscarLibro(libros, contador);
            break;
        case 4:
            actualizarEstado(libros, contador);
            break;
        case 5:
            eliminarLibro(libros, &contador);
            break;
        case 6:
            printf("Saliendo del programa.\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}
