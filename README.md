# CrossTheRoad

**Cross The Road** es un juego 2D inspirado en el clásico "Frogger". El objetivo es simple: ¡cruza la calle esquivando coches sin morir en el intento!

## Características

- Gráficos con [Raylib](https://www.raylib.com/)
- Jugabilidad basada en movimiento por grilla
- Entorno modular para personajes, enemigos y lógica de juego
- Tests automatizados con [Google Test](https://github.com/google/googletest)
- Sistema de compilación multiplataforma con CMake

## Instalación

Clona el repositorio

```sh
git clone https://github.com/macasteglione/CrossTheRoad
cd CrossTheRoad
```

Crea un archivo llamado `is` con el siguiente contenido:

```sh
#!/bin/bash
set -e

BUILD_DIR="build"
EXECUTABLE="CrossTheRoad"

function build() {
  echo "🛠️ Configurando proyecto con CMake..."
  cmake -S . -B "$BUILD_DIR" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
  echo "🔨 Compilando proyecto..."
  cmake --build "$BUILD_DIR" -- -j
}

function clear() {
  echo "🧹 Limpiando y creando directorio de build..."
  rm -rf "$BUILD_DIR"
}

function tests() {
  echo "🧪 Compilando tests y ejecutando..."
  cmake --build "$BUILD_DIR" --target testing -j
  ctest --test-dir "$BUILD_DIR" --output-on-failure
}

function run() {
  echo "▶️ Ejecutando programa..."
  "$BUILD_DIR/$EXECUTABLE"
}

if [ $# -eq 0 ]; then
  echo "Uso: $0 {build|clear|tests|run}"
  exit 1
fi

case "$1" in
  clear)
    clear
    ;;
  build)
    build
    ;;
  tests)
    tests
    ;;
  run)
    run
    ;;
  *)
    echo "Opción inválida: $1"
    echo "Uso: $0 {build|clear|tests|run}"
    exit 1
    ;;
esac
```

Dale permisos de ejecución:

```sh
chmod +x is
```

## Compilación, Ejecución y Tests

Compilar el proyecto:

```sh
./is build
```

Ejecutar el juego:

```sh
./is run
```

Ejecutar los tests:

```sh
./is tests
```

Limpiar el directorio de compilación:

```sh
./is clear
```

## Estructura del Proyecto

```py
CrossTheRoad/
├── cmake/         # Archivos auxiliares de compilación
├── external/      # Módulos externos (raylib, gtest, etc.)
├── src/           # Código fuente del juego
├── include/       # Archivos de cabecera
├── testing/       # Tests de las funcionalidades
├── assets/        # Recursos gráficos y de sonido (organizados por tipo)
├── build/         # Directorio de compilación (generado automáticamente)
├── CMakeLists.txt
└── README.md
```
