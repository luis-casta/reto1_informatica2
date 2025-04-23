# RETO 1,  ANÁLISIS Y POSIBLE SOLUCIÓN
**Descripción Breve**:
Este es el primer análisis y la posible solución del reto 1 de informatica 2.

## Datos e información que nos proporcionan
- imagen ID (imagen final), de m filas por n columas * 3 canales (RGB), cada uno con 8 bits → 24 bits.
- imagen IM (imagen aleatoria, de igual dimensiones y canales que la imagen final).
- M (mascara), imagen pequeña usada para el enmascaramiento depúes de cada transformación. Esta mascara se suma con la imagen transformada y el resultado se guradan en archivos .txt)
- Archivos de enmascaramiento(M1.txt, M2.txt), los cuales contienen la semilla (valor entero que me indica de que punto empiezo a hacer la mascara) y los resultados de las sumas ID(k+s) + M(k) → contienen la suma de los RGB píxel a píxel 
- K. índice que recorre la mascara valor por valor.
- Dos conjuntos de archivos que representan dos posibles entradas y salidas del sistema.(los archivos del caso 1 muestran los resultados despues de aplicar en primer lugar XOR entre la imagen origial (I_O,bmp) y la imagen aleatoria (I_M.bmp), al resultado de esa imagen se le aplicó una rotación de 3 bits a la derecha, y al resultado de esa imagen se le aplico un XOR, y ese resultado es lo que tenemos en el archivo p3.bmp)

## lo que entiendo que hay que hacer 
La imagen original fué modificada mediante una serie de transformaciones a nivel de bits, que incluyen desplazamientos, rotaciones y XOR, en un orden desconocido, con una imagen de distorción generada automaticamente (IM.bmp).
Despues de cada tranformación se aplicó una mascara sobre una porción de la imagen, a partir de una semilla aleatoria, esta operación se hizo sumando valor por valor de color RGB usando la siguiente formula:
s(k) = ID(k + s) + M(k)
donde sk(es el resultado que se guarda en el .txt), ID(es la imagen tranformada parcial), k(es el índice que recorre la mascara), s(es la semilla), M(es la mascara).

Mi objetivo es recontruir la imagen original, teniendo en cuenta que no conozco el orden de los pasos que se aplicaron, y tampoco tengo el algoritmo completo de como se hizo. Pero tengo dos archivos.txt, los cuales tienen la semilla, la cual me sirve para saber desde donde empieza a hacer la mascara, y los resultados de las sumas, que me permiten comparar esos resultados con mi suma al momento de aplicar una operación de bit a bit.

## posible solución.
pasos:
1. tengo que cargar las imágenes usando el codigo que se me entregó.
2. probar combinaciones de operaciones (XOR, rotaciones,desplazamientos) para la transformación sobre ID(imagen final parcial) e IM(imagen aleatoria).
3. aplicar la suma del enmascaramiento s(k) = ID(k + s ) + M(k)
4. comparar el resultado de esa suma con los que están guardados en los archivos .txt (la verdad no estoy muy seguro de que sea asi la comparación) si coinciden quiere decir que la transformación fue correcta.
5. repetir el proceso para encontrar el orden correcto de transformaciones.
6. Una vez que tenga el orden y cuales fueron las transformaciones que se le aplicarón a la imagen, revertir esas transformaciones (si se le aplico una rotacion de 2 bits a la izquierda, yo la roto 2 bits a la derecha) para obtener la imagen original.

## lo que entiendo hasta el momento
- lo que representa cada imagen (ID,IM, M).
- que significa cada dato en la suma.

## dudas que tengo 
- la semilla es un numero aleatorio y me dice desde donde empezar, pero si empieza en la ultima posición de la imagen que pasa ?, se desborda ? en clase le hicierón una pregunta similar al profesor y creo haber escuchado que no, pero todavia no entiendo por qué no.
- Estoy  confundido con los archivos .txt, me sirven para comparar mi suma con la suma que estos guardan ?, por eso puse en el punto 4 de la posible solución que no estoy seguro de que sea así como lo planteo.

## Notas personales 
La verdad en estos momenetos creo tener más dudas que certezas, quizás no esté teniendo en cuenta algunos aspectos o simplemente me falte comprender de mejor manera lo que se me pide en el reto, pero lo que si tengo claro es que trabaré en ello para poder cumplir con este objetivo.

## avances 
Entendí que la semilla no se deborda porque el valor se s está limitado de forma que la operación ID(k + s) siempre acceda a una posición válida dentro de la imagen, es decir 
que si la imagen tiene 900 píxeles y la máscara tiene 2o elementos, la semilla puede ser como máximo 880.

Entedí que los archivos .txt me sirven para verificar si las transformaciones que estoy haciendo son correctas, son como una pista que van diciendo si voy bien o no.
Estos archivos los uso de la sigueinte forma:
cuando aplico una transformación sobre la imagen, a esa transformación la sumo con las máscara usando la simsma semilla del .txt y comparo los resultados con los valores que están el .txt

## problema presentado.
En este punto comparé todas las transformaciones posibles y ninguna me coinidió con la máscara, quizás la esté comparando mal. Lo que estoy haciendo es cargar la imagen transformada I_D, aplicarle una transformación y a esa imagen que me da despues de la tranfomación la exporto como (rotar_derecha.bmp, desplazar_izquierda.bmp, operacion_xor.bmp etc) dependiendo de la transformación que le esté haciendo, la guardo con el nombre ( esa seria la segunda transformación equivalente a la p2.bmp del caso 1), a esa imagen tranformada le estoy sumando la maáscara (M.bmp) a partir de la semilla y ese resultado lo comparo con M2.txt.
La duda que tengo en estos moentos es si habia que sumar esa máscara o tendria que restarla, voy a intentar restar la máscara y ver el resultado.
