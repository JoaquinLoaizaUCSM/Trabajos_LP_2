## Semana 2: Plantillas de Clase y de Función

### Descripción

Se creó una plantilla de clase `Departamento<T>` que puede almacenar cualquier tipo de empleado. Se agregaron métodos para agregar, eliminar, buscar y listar empleados en el departamento.

### Implementación

Se utilizó la plantilla para crear departamentos de diferentes tipos de empleados.


#### Bibliotecas Utilizadas

- `iostream`: Para entrada y salida estándar.
- `fstream`: Para operaciones de lectura y escritura de archivos.
- `stdexcept`: Para lanzar y manejar excepciones estándar.
- `vector`: Para utilizar contenedores dinámicos de la STL en la gestión de empleados y evaluaciones.
- `string`: Para el manejo de cadenas de texto.

#### Estructura del Proyecto

El proyecto está organizado en diferentes archivos y directorios para mantener la modularidad y la claridad del código:

- **`include/`**: Directorio que contiene los archivos de cabecera (`*.h`) para las clases y funciones.
- **`src/`**: Directorio que contiene los archivos de implementación (`*.cpp`) para las clases y funciones.
- **`main.cpp`**: Archivo principal donde se encuentra la función `main`, responsable de inicializar y probar el sistema.

#### Clases Creadas

##### Clase `Empleado`

- **Descripción**: Clase base abstracta que representa a un empleado genérico con atributos comunes como nombre, salario base y fecha de contratación. Define un método virtual puro `calcularSalario()` que debe ser implementado por las clases derivadas.

- **Métodos Principales**:
    - `calcularSalario()`: Método virtual puro para calcular el salario del empleado.
    - `mostrarInfo()`: Método para mostrar la información del empleado.
    - Otros métodos getter para acceder a los atributos del empleado.

##### Clases Derivadas (`Gerente`, `Desarrollador`, `Disenador`, etc.)

- **Descripción**: Clases que heredan de `Empleado` y sobrescriben el método `calcularSalario()` según las reglas específicas de cada tipo de empleado. Cada clase representa un tipo específico de empleado con sus propios atributos adicionales y comportamientos.

- **Métodos Principales**:
    - `calcularSalario()`: Implementación específica del cálculo de salario para cada tipo de empleado.
    - `mostrarInfo()`: Sobrecarga para mostrar la información específica de cada tipo de empleado.
    - `getInfoAdicional()`: Método para obtener información adicional específica de cada tipo de empleado.

##### Clase Plantilla `Departamento`

- **Descripción**: Clase plantilla que permite almacenar cualquier tipo de empleado (`T`). Gestiona una colección dinámica de empleados, evaluaciones y ofrece métodos para agregar, eliminar, buscar, listar empleados, así como para manipular evaluaciones y almacenar/cargar datos desde/hacia archivos.

- **Métodos Principales**:
    - Métodos para agregar, eliminar y buscar empleados.
    - Métodos para listar empleados y ordenarlos por salario.
    - Métodos para agregar evaluaciones y calcular el promedio de evaluaciones.
    - Métodos para guardar y cargar datos desde archivos.
ste documento proporciona una visión general del proyecto, incluyendo su estructura, funcionalidades principales, 
    - y diagrama de clases para una comprensión completa del sistema desarrollado.