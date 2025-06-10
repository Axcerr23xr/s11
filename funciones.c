#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibro(Libro libros[], int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("No se pueden registrar más libros.\n");
        return;
    }

    Libro nuevoLibro;
    int idValido = 0;
    
    // Validación para evitar IDs duplicados
    do {
        printf("Ingrese ID del libro: ");
        fflush(stdin);
        scanf("%d", &nuevoLibro.id);
        
        idValido = 1; // Asumimos que el ID es válido inicialmente
        
        // Comprobar si el ID ya existe
        for (int i = 0; i < *contador; i++) {
            if (libros[i].id == nuevoLibro.id) {
                printf("Error: El ID %d ya existe. Intente con otro ID.\n", nuevoLibro.id);
                idValido = 0;
                break;
            }
        }
    } while (!idValido);
    
    // Validación para el título
    do {
        printf("Ingrese título del libro: ");
        fflush(stdin);
        fgets(nuevoLibro.titulo, MAX_TITULO, stdin);
        nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0'; // Eliminar salto de línea
        
        if (strlen(nuevoLibro.titulo) == 0) {
            printf("Error: El título no puede estar vacío. Intente nuevamente.\n");
        }
    } while (strlen(nuevoLibro.titulo) == 0);
    
    // Validación para el autor
    do {
        printf("Ingrese autor del libro: ");
        fflush(stdin);
        fgets(nuevoLibro.autor, MAX_AUTOR, stdin);
        nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0'; // Eliminar salto de línea
        
        if (strlen(nuevoLibro.autor) == 0) {
            printf("Error: El autor no puede estar vacío. Intente nuevamente.\n");
        }
    } while (strlen(nuevoLibro.autor) == 0);
    
    // Validación para el año
    int anioValido = 0;
    do {
        printf("Ingrese año de publicación: ");
        fflush(stdin);
        if (scanf("%d", &nuevoLibro.anio) != 1) {
            printf("Error: Debe ingresar un número válido para el año. Intente nuevamente.\n");
            while (getchar() != '\n'); // Limpiar buffer si la entrada fue inválida
        } else if (nuevoLibro.anio <= 0) {
            printf("Error: El año debe ser un número positivo. Intente nuevamente.\n");
        } else {
            anioValido = 1;
        }
    } while (!anioValido);
    
    strcpy(nuevoLibro.estado, "Disponible");

    libros[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado exitosamente.\n");
}

void mostrarLibros(const Libro libros[], int contador) {
    printf("ID\tTítulo\t\tAutor\t\tAño\tEstado\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibro(const Libro libros[], int contador) {
    int opcion;
    int opcionValida = 0;
    
    do {
        printf("Buscar por: 1. ID, 2. Título\n");
        fflush(stdin);
        if (scanf("%d", &opcion) != 1) {
            printf("Error: Debe ingresar un número (1 o 2). Intente nuevamente.\n");
            fflush(stdin); // Usar fflush en vez de getchar
        } else if (opcion != 1 && opcion != 2) {
            printf("Error: Opción inválida. Ingrese 1 para ID o 2 para Título.\n");
        } else {
            opcionValida = 1;
        }
    } while (!opcionValida);

    if (opcion == 1) {
        int id;
        int idValido = 0;
        
        do {
            printf("Ingrese ID del libro: ");
            fflush(stdin);
            if (scanf("%d", &id) != 1) {
                printf("Error: Debe ingresar un número válido para el ID. Intente nuevamente.\n");
                fflush(stdin); // Usar fflush en vez de getchar
            } else {
                idValido = 1;
            }
        } while (!idValido);
        
        for (int i = 0; i < contador; i++) {
            if (libros[i].id == id) {
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
    } else if (opcion == 2) {
        char titulo[MAX_TITULO];
        do {
            printf("Ingrese título del libro: ");
            fflush(stdin);
            fgets(titulo, MAX_TITULO, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
            
            if (strlen(titulo) == 0) {
                printf("Error: El título no puede estar vacío. Intente nuevamente.\n");
            }
        } while (strlen(titulo) == 0);
        
        for (int i = 0; i < contador; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
    }
    printf("Libro no encontrado.\n");
}

void actualizarEstado(Libro libros[], int contador) {
    int id;
    int idValido = 0;
    
    do {
        printf("Ingrese ID del libro para actualizar estado: ");
        fflush(stdin);
        if (scanf("%d", &id) != 1) {
            printf("Error: Debe ingresar un número válido para el ID. Intente nuevamente.\n");
            fflush(stdin); // Usar fflush en vez de getchar
        } else {
            idValido = 1;
        }
    } while (!idValido);
    
    for (int i = 0; i < contador; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }
            printf("Estado actualizado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void eliminarLibro(Libro libros[], int *contador) {
    int id;
    int idValido = 0;
    
    do {
        printf("Ingrese ID del libro para eliminar: ");
        fflush(stdin);
        if (scanf("%d", &id) != 1) {
            printf("Error: Debe ingresar un número válido para el ID. Intente nuevamente.\n");
            fflush(stdin); // Usar fflush en vez de getchar
        } else {
            idValido = 1;
        }
    } while (!idValido);
    
    for (int i = 0; i < *contador; i++) {
        if (libros[i].id == id) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado exitosamente.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
