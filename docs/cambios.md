# Cambios: reorganización del proyecto en `src/`

## Resumen

Se reorganizó el código fuente del proyecto dentro de la carpeta `src/` ubicada en la raíz del repositorio y se actualizaron las referencias del proyecto de Visual Studio. También se reforzó el `.gitignore` de la raíz para excluir binarios y archivos generados por el IDE.

## Estructura resultante

```
Proyecto_Black/                  # raíz del repositorio
├── .gitignore                   # patrones de binarios e IDE
├── .vs/                         # (ignorado)
├── x64/                         # (ignorado)
├── Proyecto_Black.slnx
├── Proyecto_Black.vcxproj       # proyecto de Visual Studio en la raíz
├── Proyecto_Black.vcxproj.filters
├── docs/
│   ├── juego.md
│   └── cambios.md               # este documento
└── src/                         # código fuente en la raíz del repositorio
    ├── blackJackGame.cpp
    ├── blackJackGame.h
    ├── Carta.cpp
    ├── Carta.h
    ├── Consola.h
    ├── Dealer.cpp
    ├── Dealer.h
    ├── Jugador.cpp
    ├── Jugador.h
    ├── main.cpp
    ├── Mano.cpp
    ├── Mano.h
    ├── Mazo.cpp
    ├── Mazo.h
    ├── Participante.cpp
    └── Participante.h
```

## Cambios detallados

### 1. Reubicación del código fuente

Los 16 archivos `.cpp` y `.h` se movieron a la carpeta `src/` de la raíz del repositorio usando `git mv`, por lo que Git conserva el historial de cada archivo.

Archivos movidos:

- `blackJackGame.cpp`, `blackJackGame.h`
- `Carta.cpp`, `Carta.h`
- `Consola.h`
- `Dealer.cpp`, `Dealer.h`
- `Jugador.cpp`, `Jugador.h`
- `main.cpp`
- `Mano.cpp`, `Mano.h`
- `Mazo.cpp`, `Mazo.h`
- `Participante.cpp`, `Participante.h`

No fue necesario modificar los `#include`: todos los archivos quedaron juntos en la misma carpeta, por lo que las rutas relativas siguen siendo válidas.

### 2. Proyecto de Visual Studio

- `Proyecto_Black.vcxproj`: se movió a la raíz del repositorio y las rutas de `ClCompile` y `ClInclude` quedaron como `src\archivo.cpp` y `src\archivo.h`.
- `Proyecto_Black.vcxproj.filters`: se movió a la raíz y las rutas quedaron como `src\archivo`, conservando el filtro `src` existente.
- `Proyecto_Black.slnx`: la referencia al proyecto se actualizó a `Proyecto_Black.vcxproj`.

### 3. `.gitignore`

Se agregó una sección explícita de binarios y salidas de compilación:

```gitignore
# Binaries and compiled outputs
*.exe
*.dll
*.lib
*.exp
*.obj
*.o
*.out
*.pdb
*.ilk
*.idb
*.ipdb
*.iobj
```

El archivo ya incluía `x64/`, `.vs/`, `*.user`, `*.obj`, `*.pdb`, etc. El `.gitignore` permanece en la raíz del repositorio.

## Verificación

- `git check-ignore` confirma que se ignoran `*.exe`, `*.obj`, `*.vcxproj.user` y `.vs/`.
- La compilación `Debug|x64` con MSBuild finaliza sin errores y genera `x64\Debug\Proyecto_Black.exe`.

## Mensaje de commit sugerido

```
refactor: reorganiza el proyecto en src/ y actualiza .gitignore

- Mueve todos los .cpp y .h a src/ (git mv, conserva historial)
- Actualiza rutas en Proyecto_Black.vcxproj y .filters
- Agrega patrones de binarios y salidas de compilación al .gitignore
```
