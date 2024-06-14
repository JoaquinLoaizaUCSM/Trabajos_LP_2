# Sistema de Gestión de Recursos Humanos

## Descripción del Proyecto

El Sistema de Gestión de Recursos Humanos es una aplicación desarrollada en C++, diseñada para gestionar empleados de diferentes tipos dentro de un departamento. El sistema permite la creación de una jerarquía de clases para representar diversos roles (como gerentes, desarrolladores, diseñadores, etc.), cada uno con su propio cálculo de salario y funcionalidades específicas. Además, el sistema utiliza plantillas de clase para la gestión genérica de departamentos y hace uso de archivos para almacenar y cargar datos de empleados y evaluaciones.

El sistema se desarrolló en varias etapas, cada una centrada en un aspecto específico de la programación, como el polimorfismo, las plantillas de clase y de función, la manipulación de archivos y excepciones, y el uso de la biblioteca de plantillas estándar (STL). A través de estas etapas, el sistema se ha convertido en una herramienta completa y robusta para la gestión de recursos humanos.

### Bibliotecas Utilizadas

- `iostream`: Para entrada y salida estándar.
- `fstream`: Para operaciones de lectura y escritura de archivos.
- `stdexcept`: Para lanzar y manejar excepciones estándar.
- `vector`: Para utilizar contenedores dinámicos de la STL en la gestión de empleados y evaluaciones.
- `string`: Para el manejo de cadenas de texto.

### Estructura del Proyecto

El proyecto está organizado en diferentes archivos y directorios para mantener la modularidad y la claridad del código:

- **`clases/`**: Directorio que contiene los archivos de cabecera (`*.h`) para las clases y funciones.
- **`main.cpp`**: Archivo principal donde se encuentra la función `main`, responsable de inicializar y probar el sistema.

### Clases Creadas

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
## Desarrollo del Proyecto

- [Semana 1: Polimorfismo](Semana1.md)
- [Semana 2: Plantillas de Clase y de Función](Semana2.md)
- [Semana 3: Archivos y Excepciones](Semana3.md)
- [Semana 4: STL](Semana4.md)

## Diagramas

En esta sección, se presentarán los diagramas que representan la estructura y el flujo del sistema. Estos diagramas ayudarán a entender mejor cómo se organizan las diferentes partes del sistema y cómo interactúan entre sí.

(Puedes insertar tus diagramas aquí utilizando la sintaxis de imagen de Markdown: `![Descripción del diagrama](ruta/al/diagrama.png)`)

## Conclusiones

El Sistema de Gestión de Recursos Humanos desarrollado en C++ es una aplicación modular y eficiente que utiliza principios de programación orientada a objetos, plantillas de clase y manejo de archivos para gestionar empleados de diferentes tipos dentro de un departamento. Ofrece funcionalidades para calcular salarios específicos, manipular evaluaciones de desempeño y almacenar datos de empleados en archivos. La estructura del proyecto está diseñada para ser clara y escalable, facilitando el mantenimiento y la expansión del sistema en el futuro.