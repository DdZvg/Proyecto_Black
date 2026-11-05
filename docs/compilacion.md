# Guía de compilación

Este documento tiene dos guías para compilar y ejecutar el Proyecto_Black

## Parte 1. Compilacion con cl


## **Parte 2.Compilación con Visual Studio**

### **2.1 Requisitos**

**Requisito**                 **Detalle**
Sistema operativo:           Windows 10 u 11
Visual Studio:               La versión con la que se creó el proyecto, Visual Studio 2026. La                                   solución usa el formato *.slnx* que solo abren las versiones recientes.
Carga de trabajo:            **Desarrollo para el escritorio con C++**
Estándar de C++:             C++20, ya viene configurado en el proyecto
Git:                         Solo si se clona el repositorio en lugar de descargar ZIP

(Imagen)

Si el instalador no muestra la carga de trabajo,abra Visual Studio Installer-->Modificar y marquela.

### **2.2 Obtener el código**
#### **Opcion A:clonar con Git**
https://github.com/DdZvg/Proyecto_Black.git
cd Proyecto_Black

#### **Opcion B:descargar el ZIP**
En la  pagina del repositorio en GitHub, presione Code-->**Download ZIP** y extraiga la carpeta completa. No mueva el archivo de lugar.
(Imagen)

### **2.3 Abrir la solucion**
1. Abra Visual Studio y elija **Abrir un proyecto o una solución** , ejemplo: *Archivo*-->*Abrir*-->*Proyecto* o *solucion*.
2. Seleccione el archivo *Proyecto_Black.slnx* que esta en la carpeta raíz del repositorio.
(Imagen)

3.En el *Explorador de soluciones* debe aparecer el proyecto **Proyecto_Black** con los archivos .h y .cpp de la carpeta *src*
(Imagen)

### **2.4 Elegir la configuracion**
En la barra de herramientas superior seleccione:
-Configuracion:**Debug**
-Plataforma:**x64**
(Imagen)

### **2.5 Compilar**
1.Menu **Compilar-->Compilar solución**, tambien se puede utilizar el atajo *Ctrl+Shift+B.
2.Revise la ventana **Salida**. La compilacion fue exitosa si termina con una linea como:

====*Compilar:1 correctos, 0 erroneos, 0 actualizados, 0 omitidos*====
(Imagen)
El ejecutable queda en *x64\Debug\Proyecto_Black.exe.*

### **2.6 Ejecutar**
Presione **Ctrl+F5**:*Depurar-->Iniciar sin depurar. Se abre una ventana de consola con el juego. Con *Ctrl+F5* la consola no se cierra sola al terminar.
(Imagen)

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


