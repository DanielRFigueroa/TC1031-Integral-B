# TC1031 Integral B 🖥️ ✅

## Daniel Rodriguez Figueroa   A01612889

### Correcciones:

Se añade la Integral B por completo, es decir el archivo main.cpp, change.h, graph.h, quadratic.h, base de datos.txt, taxis.txt y el archivo README.md.

### QuereTaxi - Rutas de taxi 🖥️ ✅

Este proyecto representa un sistema que hace uso de grafos para poder mapear los destinos y que asi el usuario pueda ver una tabla con la disponibilidad de rutas, con esto el usuario puede buscar una ruta elegiendo un origen y un destino para que con un BFS le de la ruta mas corta para llegar a su destino, mencionandole por que lugares pasa para llegar hasta el destino deseado.

El usuario puede registrar sus datos de contacto para que el conductor que le sea asignado le llame cuando llegue a recoger al usuario al punto de origen del viaje, esto se guarda en un archivo .txt (base de datos.txt), siendo nuestra base de datos de pasajeros para poder lleva run registro de quien hace uso de nuestros servicios, estos datos introducidos por el usuario son guardados en un hash con un put, siendo el nombre del usuario la llave (key) y el numero el valor (value).

Asi mismo, el conductor tiene la opcion de PhoneApp en la cual el conductor introduce el nombre de su pasajero (key) para asi haciendo uso de un get, poder obtener el numero del pasajero (value) y marcarle para avisar que su taxi ha llegado.


