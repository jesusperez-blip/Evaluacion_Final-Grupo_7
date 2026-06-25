# 1. IMAGEN BASE: Descargamos un entorno Linux que ya incluye el compilador de C/C++
FROM gcc:latest

# 2. DIRETORIO DE TRABAJO: Creamos una carpeta llamada /app dentro del contenedor 
WORKDIR /app

# 3. COPIA DE ARCHIVOS: Copiamos nuestro main.cpp (y todo lo demas) a la capeta /app del contenedor 
COPY . .

# 4. COMPILACION: Copilamos los archivos .cppy generamos un ejecutable llamado "programa_grupo"
RUN g++ -o programa_grupo *.cpp

# 5. EJECUTAR: Definimos el comando por defecto para ejecutar el programa
CMD ["./programa_grupo"]