# GrahamScan
Calculo de cierrre convexo utilizando grahamScan

Guía de uso
Poner los tres archivos en la misma carpeta

Compilamos el archivo cpp
g++ graham.cpp -o graham

Hacemos un archivo de prueba usando el generator.py
py generator.py 15 (Para 15 numeros)
Esto generará un archivo .txt con el numero de puntos introducidos
"puntos_aleatorios.txt"

Calculamos el cierre convexo usando nuestro grahamScan
./graham puntos_aleatorios.txt

la consola emitirá un mensaje de "Se calculo el cierre convexo con exito"
y generará el archivo
"cierre_convexo.txt"

Se necesita que esten generados ambos archivos, es decir;
"puntos_aleatorios.txt"
"cierre_convexo.txt"

Para visualizar el cierre convexo usaremos el archivo de graficador.py
y haremos
py graficador.py

Esto nos mostrará una gráfica en donde podemos ver el cierre convexo
asi como los puntos originales

GRACIAS !
