#define MAX_LIBROS 10
#define MAX_TITULO 100
#define MAX_AUTOR 50
#define MAX_ESTADO 15

typedef struct {
    int id;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anio;
    char estado[MAX_ESTADO];
} Libro;

void registrarLibro(Libro libros[], int *contador);
void mostrarLibros(const Libro libros[], int contador);
void buscarLibro(const Libro libros[], int contador);
void actualizarEstado(Libro libros[], int contador);
void eliminarLibro(Libro libros[], int *contador);
