
# Documentación sobre Funcionalidades Modernas en C++20 utilizadas

En esta sección, se presentan y explican algunas de las funcionalidades modernas de C++20 utilizadas en los ejemplos de código proporcionados para las actividades 2, 3 y 4. Se destacarán las características clave y se darán ejemplos claros para facilitar la comprensión de estos conceptos avanzados.

## 1. `std::unique_ptr` y Manejo de Memoria Inteligente

### Descripción

En C++20, el uso de `std::unique_ptr` es fundamental para la gestión automática de la memoria, evitando fugas de memoria y simplificando el manejo de objetos dinámicamente asignados. `std::unique_ptr` es una clase plantilla que proporciona un puntero exclusivo a un objeto, asegurando que sólo haya un único `unique_ptr` que posea y administre el recurso a la vez.

### Ejemplo en Código

En los ejemplos de las actividades, `std::unique_ptr` se utiliza para almacenar objetos de clases derivadas en un contenedor polimórfico.

```cpp
#include <memory>
#include <vector>
#include <iostream>

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "El perro ladra: ¡Guau guau!" << std::endl;
    }
    void moverse() const override {
        std::cout << "El perro corre." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animales;
    animales.push_back(std::make_unique<Perro>());

    for (const auto& animal : animales) {
        animal->hacerSonido();
        animal->moverse();
    }

    return 0;
}
```

### Ventajas

- **Seguridad de la memoria:** `std::unique_ptr` automáticamente libera la memoria cuando el puntero sale de su ámbito.
- **Transferencia de propiedad:** Los objetos pueden transferir su propiedad mediante `std::move`, asegurando que no haya múltiples propietarios del mismo recurso.

## 2. Clases Abstractas y Métodos Virtuales Puros

### Descripción

Las clases abstractas en C++ se utilizan para definir interfaces comunes que pueden ser implementadas por clases derivadas. Un método virtual puro se declara con `= 0` y debe ser implementado por cualquier clase derivada concreta.

### Ejemplo en Código

En las actividades, se definen clases abstractas como `Animal` y `Dispositivo`, que tienen métodos virtuales puros.

```cpp
class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "El perro ladra: ¡Guau guau!" << std::endl;
    }
    void moverse() const override {
        std::cout << "El perro corre." << std::endl;
    }
};
```

### Ventajas

- **Polimorfismo:** Permite tratar objetos de diferentes clases derivadas de manera uniforme a través de punteros o referencias a la clase base.
- **Extensibilidad:** Facilita la adición de nuevas clases derivadas sin modificar el código existente que utiliza la clase base.


## 3. `override` y `final` para Métodos Virtuales

### Descripción

C++11 introdujo las palabras clave `override` y `final` para mejorar la claridad y la seguridad del código orientado a objetos. `override` asegura que un método está sobrescribiendo un método virtual base, mientras que `final` previene que un método o clase sea sobrescrito o derivado nuevamente.

### Ejemplo en Código

En los ejemplos, se usa `override` para indicar que un método en una clase derivada sobrescribe un método virtual de la clase base.

```cpp
class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "El perro ladra: ¡Guau guau!" << std::endl;
    }
    void moverse() const override {
        std::cout << "El perro corre." << std::endl;
    }
};
```

### Ventajas

- **Claridad:** Facilita la comprensión del código indicando explícitamente las sobrescrituras.
- **Mantenimiento:** Ayuda a evitar errores durante el mantenimiento y la extensión del código.

## 4. `std::move` y Transferencia de Recursos

### Descripción

`std::move` se utiliza para convertir un objeto en un valor rvalue, permitiendo la transferencia eficiente de recursos desde un objeto a otro sin realizar copias costosas. Es esencial para la semántica de movimiento, una característica clave en C++11 y posteriores.

### Ejemplo en Código

En los ejemplos de las actividades, `std::move` se utiliza para transferir `unique_ptr` al contenedor, asegurando que la propiedad del objeto se transfiera correctamente.

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual void moverse() const = 0;
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "El perro ladra: ¡Guau guau!" << std::endl;
    }
    void moverse() const override {
        std::cout << "El perro corre." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animales;
    auto perro = std::make_unique<Perro>();
    animales.push_back(std::move(perro)); // Transferencia de propiedad

    for (const auto& animal : animales) {
        animal->hacerSonido();
        animal->moverse();
    }

    return 0;
}
```

### Ventajas

- **Eficiencia:** Permite la transferencia de recursos sin necesidad de copias, mejorando el rendimiento.
- **Control de recursos:** Facilita la gestión de recursos complejos y la optimización de la memoria.

---

## Conclusión

Estas características modernas de C++20 no solo mejoran la eficiencia y la claridad del código, sino que también facilitan la implementación de conceptos avanzados de programación orientada a objetos. Al incorporar estas funcionalidades en nuestros ejemplos, hemos mejorado la robustez, la seguridad y el rendimiento del código, permitiendo una mayor comprensión y aplicación en proyectos reales.
