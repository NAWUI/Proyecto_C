//a. Datos para calcular la medida de superficie de: un rectángulo, un triángulo y un trapecio.
struct Rectangulo {
    float base;
    float altura;
};

struct Triangulo {
    float base;
    float altura;
};

struct Trapecio {
    float base_mayor;
    float base_menor;
    float altura;
};
//b. Un par de coordenadas cartesianas (x, y) donde x e y son dos números reales.
struct Coordenadas {
    float x;
    float y;
};

//c. Una dirección: calle y número, localidad, código postal, número de teléfono.
struct Direccion {
    char calle[50];
    int numero;
    char localidad[50];
    int codigo_postal;
    char telefono[15];
};

//d. Un alumno: nombre (30 caracteres); número de registro (entero de seis dígitos); tipo y número de documento de identidad; dirección; materias (para cada una: nombre, fecha de regularización y de aprobación).
struct Documento {
    char tipo[10];
    int numero;
};

struct Materia {
    char nombre[30];
    char fecha_regularizacion[11]; // formato: "DD/MM/AAAA"
    char fecha_aprobacion[11];     // formato: "DD/MM/AAAA"
};

struct Alumno {
    char nombre[30];
    int numero_registro;
    struct Documento documento;
    struct Direccion direccion;
    struct Materia materias[10]; // asumimos que un alumno puede tener hasta 10 materias
};

//e. Un empleado: nombre (30 caracteres); tipo y número de documento de identidad; dirección; fecha de nacimiento; estado civil; cantidad de hijos a cargo; sexo
struct Empleado {
    char nombre[30];
    struct Documento documento;
    struct Direccion direccion;
    char fecha_nacimiento[11]; // formato: "DD/MM/AAAA"
    char estado_civil[20];
    int cantidad_hijos;
    char sexo; // 'M' para masculino, 'F' para femenino, 'O' para otro
};

//f. Un aula: tipo de aula deberá incluir: Nº de identificación, ubicación (bloque) y tipo (Laboratorio, Conferencia, Teoría‐Práctica); cantidad de mesas, cantidad de sillas, cantidad de pizarras, proyector (deberá incluir: marca, color y control remoto (si o no)).
struct Proyector {
    char marca[30];
    char color[20];
    int control_remoto; // 1 para sí, 0 para no
};

struct Aula {
    int numero_identificacion;
    char ubicacion[50];
    char tipo[30]; // Laboratorio, Conferencia, Teoría‐Práctica
    int cantidad_mesas;
    int cantidad_sillas;
    int cantidad_pizarras;
    struct Proyector proyector;
};
