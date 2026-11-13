# Guía de compilación

Este documento tiene dos guías para compilar y ejecutar el Proyecto_Black

## Parte 1. Compilacion con cl

### **1.1 Requisitos**

Para compilar el proyecto desde la consola se necesitan los siguientes requisitos:

| **Requisito** | **Detalle** |
|---|---|
| Sistema operativo | Windows 10 u 11 |
| Visual Studio | Visual Studio 2026 con las herramientas de compilación de C++ instaladas. |
| Carga de trabajo | **Desarrollo para el escritorio con C++** |
| Consola | **x64 Native Tools Command Prompt for VS 2026** |
| Estándar de C++ | C++17 para esta compilación. El proyecto de Visual Studio está configurado con C++20. |
| Código fuente | Tener descargado o clonado el repositorio completo de **Proyecto_Black**. |

### **1.2 Abrir la consola de compilación**

1. Abra el menú de **Inicio** de Windows.
2. Busque **x64 Native Tools Command Prompt for VS 2026** y abra la consola.
3. Para verificar que el compilador funciona correctamente, escriba el siguiente comando:

```cmd
cl
```

Si el compilador está instalado correctamente, aparecerá información sobre la versión de Microsoft C/C++.

Es normal que aparezca el mensaje `uso: cl [...]`, ya que todavía no se ha indicado ningún archivo para compilar.

<img width="1277" height="688" alt="cl-01-verificar-y-archivos" src="https://github.com/user-attachments/assets/effa295c-f526-4b9b-9da8-18c624f49c1a" />


### **1.3 Ubicar los archivos del proyecto**

1. Desde la consola, ingrese a la carpeta principal del proyecto utilizando el siguiente comando:

```cmd
cd /d C:\Users\yoyce\source\repos\Proyecto_Black
```

La ruta anterior corresponde a la ubicación utilizada para esta guía. En otra computadora debe cambiarse por la ubicación donde se descargó o clonó el repositorio.

2. Para encontrar los archivos de código fuente, escriba:

```cmd
dir /s /b *.cpp
```

3. En la consola aparecerán los archivos `.cpp` del proyecto, como `main.cpp`, `Carta.cpp`, `Mazo.cpp`, `Mano.cpp` y las demás clases utilizadas para el funcionamiento del juego.

Estos archivos se encuentran dentro de la carpeta `src`.

### **1.4 Compilar el proyecto**

1. Desde la carpeta principal de **Proyecto_Black**, escriba el siguiente comando:

```cmd
cl /EHsc /std:c++17 /Fe:Blackjack.exe src\*.cpp
```

2. El compilador comenzará a procesar todos los archivos `.cpp` del proyecto. Cada parte del comando cumple una función:

| **Comando** | **Función** |
|---|---|
| `cl` | Ejecuta el compilador de Microsoft C/C++. |
| `/EHsc` | Activa el manejo de excepciones de C++. |
| `/std:c++17` | Utiliza el estándar C++17 para compilar. |
| `/Fe:Blackjack.exe` | Establece el nombre del archivo ejecutable. |
| `src\*.cpp` | Compila los archivos `.cpp` que se encuentran en la carpeta `src`. |

3. Revise la información de la consola. Si no aparecen errores que impidan la compilación, se generará el archivo `Blackjack.exe` en la carpeta principal del proyecto.

<img width="1920" height="1080" alt="cl-02-compilacion" src="https://github.com/user-attachments/assets/dc565cad-b9fb-48d7-be8e-3338d000b736" />


**Nota:** Durante la compilación pueden aparecer advertencias `C4566` relacionadas con los caracteres de las cartas y la página de códigos de Windows. Estas advertencias no impidieron generar el ejecutable.

Para utilizar el estándar C++20, configurado en la solución de Visual Studio, puede sustituirse `/std:c++17` por `/std:c++20`.

### **1.5 Ejecutar**

1. Cuando termine la compilación, escriba el siguiente comando en la misma consola:

```cmd
Blackjack.exe
```

2. Presione **Enter**. Si el programa se compiló correctamente, aparecerá la pantalla de bienvenida del juego **Blackjack**.

3. Presione nuevamente **Enter** para ingresar al menú principal y comenzar a jugar.

<img width="862" height="521" alt="cl-03-ejecucion" src="https://github.com/user-attachments/assets/857b634e-ede6-4108-9d9b-cf5104d1dc3a" />


### **1.6 Problemas comunes**

| **Problema** | **Causa** | **Solución** |
|---|---|---|
| `'cl' no se reconoce como un comando` | La consola no tiene configuradas las herramientas de C++. | Abra **x64 Native Tools Command Prompt for VS 2026** y verifique que las herramientas de C++ estén instaladas. |
| `fatal error C1083: no se puede abrir '*.cpp'` | Se intentó compilar desde una carpeta que no contiene los archivos `.cpp`. | Desde la carpeta principal del proyecto, utilice `src\*.cpp` en lugar de `*.cpp`. |
| Aparecen advertencias `C4566` | Algunos caracteres no pueden representarse en la página de códigos actual. | Estas advertencias no impiden compilar. Puede probar agregando `/utf-8` al comando de compilación. |
| El archivo `Blackjack.exe` no aparece | Hubo errores durante la compilación o se utilizó una ruta incorrecta. | Revise los errores mostrados en la consola y verifique que los archivos estén dentro de la carpeta `src`. |
| Las cartas muestran símbolos incorrectos | La consola puede utilizar una codificación incompatible con los caracteres del juego. | Si el programa utiliza UTF-8, pruebe el comando `chcp 65001` antes de ejecutar el juego. |



## **Parte 2.Compilación con Visual Studio**

### **2.1 Requisitos**

**Requisito**                 **Detalle**
Sistema operativo:           Windows 10 u 11
Visual Studio:               La versión con la que se creó el proyecto, Visual Studio 2026. La                                   solución usa el formato *.slnx* que solo abren las versiones recientes.
Carga de trabajo:            **Desarrollo para el escritorio con C++**
Estándar de C++:             C++20, ya viene configurado en el proyecto
Git:                         Solo si se clona el repositorio en lugar de descargar ZIP

<img width="1426" height="746" alt="vs-01-instalador" src="https://github.com/user-attachments/assets/0035119b-28d1-4e41-9bba-7ca050397940" />


Si el instalador no muestra la carga de trabajo,abra Visual Studio Installer-->Modificar y marquela.

### **2.2 Obtener el código**
#### **Opcion A:clonar con Git**
https://github.com/DdZvg/Proyecto_Black.git
cd Proyecto_Black

#### **Opcion B:descargar el ZIP**
En la  pagina del repositorio en GitHub, presione Code-->**Download ZIP** y extraiga la carpeta completa. No mueva el archivo de lugar.

<img width="1327" height="906" alt="vs-02-descargar" src="https://github.com/user-attachments/assets/c76c48dc-b018-427f-85a8-03fc5b37861a" />


### **2.3 Abrir la solucion**
1. Abra Visual Studio y elija **Abrir un proyecto o una solución** , ejemplo: *Archivo*-->*Abrir*-->*Proyecto* o *solucion*.
2. Seleccione el archivo *Proyecto_Black.slnx* que esta en la carpeta raíz del repositorio.

<img width="1912" height="600" alt="vs-03-abrir-solucion" src="https://github.com/user-attachments/assets/c134c7f7-b137-4f55-9aa5-0212357fe10a" />


3.En el *Explorador de soluciones* debe aparecer el proyecto **Proyecto_Black** con los archivos .h y .cpp de la carpeta *src*}

<img width="1917" height="1021" alt="vs-04-explorador" src="https://github.com/user-attachments/assets/7169f7b6-01d7-496c-aff1-ea0f482540c6" />


### **2.4 Elegir la configuracion**
En la barra de herramientas superior seleccione:
-Configuracion:**Debug**
-Plataforma:**x64**

<img width="1917" height="82" alt="vs-05-configuracion" src="https://github.com/user-attachments/assets/cc550a4e-719e-41f2-9b52-b5f5b7c449c3" />



### **2.5 Compilar**
1.Menu **Compilar-->Compilar solución**, tambien se puede utilizar el atajo *Ctrl+Shift+B.
2.Revise la ventana **Salida**. La compilacion fue exitosa si termina con una linea como:

====*Compilar:1 correctos, 0 erroneos, 0 actualizados, 0 omitidos*====

<img width="1067" height="192" alt="vs-06-compilacion-ok" src="https://github.com/user-attachments/assets/26cf0c0c-61db-4c44-a79a-378319697612" />

El ejecutable queda en *x64\Debug\Proyecto_Black.exe.*

### **2.6 Ejecutar**
Presione **Ctrl+F5**:*Depurar-->Iniciar sin depurar. Se abre una ventana de consola con el juego. Con *Ctrl+F5* la consola no se cierra sola al terminar.

<img width="745" height="574" alt="vs-07-ejecucion png" src="https://github.com/user-attachments/assets/4647eb85-e708-4deb-b1dc-9262098d2542" />

Con F5 (con depuracion) la consola puede cerrarse apenas termina el programa.

### **2.7 Problemas comunes**
|  Problema      |   Causa   |  Solución |
|---             |---|---|
| Visual Studio no abre el *.slnx* | Su versión es antigua | Instale la versión indicada en 2.1 |
| *Error: no se encuentra el SDK de Windows*/windows.h *no encontrado  | Falta el SDK | En el Installer *Modificar-->Componentes individuales* y marque el **SDK de Windows 10/11** |
| *No se encuentra el conjunto de herramientas v145* | Su virtual Studio es más antigua | Clic derecho en el proyecto-->**Propiedades-->General-->Conjunto de herramienta de plataforma** y elija el que tenga instalado.    |
| Los caracteres de las cartas se ven como ? o simbolos raros | La consola no usa UTF-8 | Ejecute el juego desde **Windows Terminal** o use *Ctrl+ F5, que abre la consola de Windows. |
| *error C2039/ identificador no encontrado*| Falta algun archivo del proyecto | Verifique que descargo el repositorio completo y que todos los .cpp estan en *Archivos de codigo fuente*. |
| El *.exe* no aparece|  | Revise que la plataforma sea **x64** y busque en *x64\Debug*. Si cambio a *Release*, estara en *x64\Release*. |


