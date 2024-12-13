#include <stdio.h>
#include <string.h>
#include "funciones.h"
 
void inicializarBiblioteca(Libro biblioteca[], int *cantidad) {
    *cantidad = 0;
}
int idUnico(Libro biblioteca[], int cantidad, int id) {
    for (int i = 0; i < cantidad; i++) {
        if (biblioteca[i].id == id) {
            return 0;
        }}
    return 1;
}
void registrarLibro(Libro biblioteca[], int *cantidad) {
    if (*cantidad >= MAX_LIBROS) {
        printf("No se pueden registrar mas libros. Capacidad maxima alcanzada.\n");
        return;
    }
    Libro nuevoLibro;
    do {
        printf("Ingrese ID del libro: ");
        scanf("%d", &nuevoLibro.id);

        if (nuevoLibro.id < 0) {
            printf("Error: El ID no puede ser un numero negativo.\n");
        } else if (!idUnico(biblioteca, *cantidad, nuevoLibro.id)) {
            printf("Error: El ID ya existe.\n");
            nuevoLibro.id = -1;
        }
    } while (nuevoLibro.id < 0);
    printf("Ingrese titulo: ");
    getchar();
    fgets(nuevoLibro.titulo, 100, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = '\0';

    printf("Ingrese autor: ");
    fgets(nuevoLibro.autor, 50, stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = '\0';
    do {
        printf("Ingrese el year de publicacion: ");
        scanf("%d", &nuevoLibro.anio);

printf("No puede ingresar mayor de 2024: \n");
        if (nuevoLibro.anio < 0) {
            printf("No puede ingresar mayor de 2024.\n");
            printf("Error: El year no puede ser un numero negativo.\n");
        }
    } while (nuevoLibro.anio < 0 || nuevoLibro.anio >2024);
    strcpy(nuevoLibro.estado, "Disponible");

    biblioteca[*cantidad] = nuevoLibro;
    (*cantidad)++;
    printf("Libro registrado con exito.\n");
}
void mostrarLibros(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("%-5s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Year", "Estado");
    for (int i = 0; i < cantidad; i++) {
        printf("%-5d %-30s %-20s %-10d %-15s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].estado);
    }}
void buscarLibro(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
    int opcion, idBuscado;
    char tituloBuscado[100];

    printf("Buscar por:\n1. ID\n2. Título\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el ID: ");
        scanf("%d", &idBuscado);

        for (int i = 0; i < cantidad; i++) {
            if (biblioteca[i].id == idBuscado) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nYear: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio,
                       biblioteca[i].estado);
                return;
            }}
    } else if (opcion == 2) {
        printf("Ingrese el titulo: ");
        getchar();
        fgets(tituloBuscado, 100, stdin);
        tituloBuscado[strcspn(tituloBuscado, "\n")] = '\0';

        for (int i = 0; i < cantidad; i++) {
            if (strcasecmp(biblioteca[i].titulo, tituloBuscado) == 0) {
                printf("ID: %d\nTitulo: %s\nAutor: %s\nYear: %d\nEstado: %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio,
                       biblioteca[i].estado);
                return;
            }}}
    printf("Libro no encontrado.\n");
}

void actualizarEstado(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
    int idBuscado;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < cantidad; i++) {
        if (biblioteca[i].id == idBuscado) {
            if (strcmp(biblioteca[i].estado, "Disponible") == 0) {
                strcpy(biblioteca[i].estado, "Prestado");
            } else {
                strcpy(biblioteca[i].estado, "Disponible");
            }
            printf("Estado actualizado a: %s\n", biblioteca[i].estado);
            return;
        }}
    printf("Libro no encontrado.\n");
} 
void eliminarLibro(Libro biblioteca[], int *cantidad) {
    if (*cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }
    int idBuscado;
    printf("Ingrese el ID del libro a eliminar: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < *cantidad; i++) {
        if (biblioteca[i].id == idBuscado) {
            for (int j = i; j < *cantidad - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*cantidad)--;
            printf("Libro eliminado con exito.\n");
            return;
        }}
    printf("Libro no encontrado.\n");
} 