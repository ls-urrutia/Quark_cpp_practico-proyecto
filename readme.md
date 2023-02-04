Ejecución

El programa fue desarrollado en visual studio code, por lo que debe ejecutarse por consola. 
Nunca habia usado vs code para c++ por lo que tuve que buscar como instalar un compilador llamado mingw,
y seguir los pasos. Después de ya instalado en windows se puede abrir un cmd en la carpeta del programa.


Si es en windows hay que instalar el compilador mingw, y ejecutar la siguiente linea:

g++ -o main.exe main.cpp menu.cpp entidades/cotizacion.cpp entidades/prenda.cpp entidades/tienda.cpp entidades/vendedor.cpp

y despues lo siguiente: main.exe

Con esto, se generará la app en la misma consola, y de hecho quedara guardado el ejecutable en la carpeta.

La razon de usar vs code es porque es el programa que uso por defecto para PHP y me era más comodo organizarme ahi, etc