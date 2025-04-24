
#include <iostream>


using namespace std;

// 1. XOR entre I_D (img transformada, es la img final parcial) y la img I_M.bmp (es la img aleatoria)
void aplicarXor(unsigned char* imagen_ID, unsigned char* imagen_IM, int tamaño) {
    for(int i = 0; i < tamaño; i++) {
        imagen_ID[i] ^= imagen_IM[i];
    }
}



// rotar todos los bytes de imagen a la derecha
void rotarImagenDerecha(unsigned char* imagen_ID, int total_bytes){
    for (int i = 0; i < total_bytes; ++i) {
        imagen_ID[i] = (imagen_ID[i] >> 3) | (imagen_ID[i] << (8 - 3));

    }

}




// rotar imagen a la izquierda
void rotarImagenIzquierda(unsigned char* imagen_ID, int total_bytes){
    for (int i = 0; i < total_bytes; ++i) {
        imagen_ID[i] = (imagen_ID[i] << 3) | (imagen_ID[i] >> (8 - 3));

    }

}

// Desplazamiento de bits a la derecha
void DesplzarDerecha(unsigned char* imagen_ID, int total_bytes){
    for(int i = 0; i < total_bytes; i++){
        imagen_ID[i] = imagen_ID[i] >> 3;

    }

}

// Desplazamiento a la izquierda
void DesplazarIzquierda(unsigned char* imagen_ID, int total_bytes){
    for(int i = 0; i < total_bytes; i++){
        imagen_ID[i] = imagen_ID[i] << 3;
    }

}

