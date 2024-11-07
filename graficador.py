# Archivo para visualizar el cierre convexo calculado por el archivo 
# "Graham.cpp"
# Por: Pedro Jesus Sotelo Arce
# Matricula: A01285371
# Fecha de ultima modificación 06/11/2024

# Libreria para graficar
import matplotlib.pyplot as plt

# Función para leer los puntos desde el archivo generado en graham.cpp
def leer_puntos(nombre_archivo):
    puntos = []
    with open(nombre_archivo, 'r') as archivo:
        for linea in archivo:
            x, y = map(float, linea.strip().split(','))
            puntos.append((x,y))
    return puntos

# leer puntos originales y del cierre convexo

puntos = leer_puntos("puntos_aleatorios.txt")
cierreConvexo = leer_puntos("cierre_convexo.txt")

# Dibujar los puntos originales
x, y = zip(*puntos)
plt.scatter(x, y, color='blue', label= "puntos originales")

# Dibujamos el cierre convexo
cx, cy = zip(*cierreConvexo)
plt.plot(cx + (cx[0],), cy + (cy[0],), color='red', marker= 'o', linestyle='-', label="Cierre Convexo")

# Configuración basica de la grafica
plt.xlabel("Eje X")
plt.ylabel("Eje Y")
plt.legend()
plt.title("Cierre convexo usando Graham Scan")
plt.savefig("cierre_convexo.png")
plt.show()