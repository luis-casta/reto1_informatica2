
#include <iostream>


using namespace std;

// 1. XOR entre I_D (img transformada, es la img final parcial) y la img I_M.bmp (es la img aleatoria)
void aplicarXor(unsigned char* imagen_ID, unsigned char* imagen_IM, int tamaño) {
    for(int i = 0; i < tamaño; i++) {
        imagen_ID[i] ^= imagen_IM[i];
    }
}

// 2. Rotación de 3 bits a la DERECHA (como en el Caso 1)
unsigned char rotarDerecha(unsigned char byte) {
    return (byte >> 3) | (byte << (8 - 3));
}

// 3. Rotación de 3 bits a la IZQUIERDA
unsigned char rotarIzquierda(unsigned char byte) {
    return (byte << 3) | (byte >> (8 - 3));
}

// aplicar  enmascaramiento entre operacion_xor.bmp y mascara M.bmp
void enmascaramiento(unsigned char* imagen, unsigned char* mascara, unsigned char* resultado, int ancho, int alto, int semilla, int ancho_mascara, int alto_mascara) {
    int total_mascara = ancho_mascara * alto_mascara * 3;
    int total_imagen = ancho * alto * 3;

    for (int k = 0; k < total_mascara; ++k) {
        int indice_imagen = (k + semilla * 3) % total_imagen;
        resultado[k] = imagen[indice_imagen] + mascara[k];
    }
}


// comparar el emascaramiento con los archivos.txt
bool compararEnmascaramiento(unsigned char* enmascarado, unsigned int* datos_txt, int n_pixeles) {
    for (int i = 0; i < n_pixeles * 3; ++i) {
        if (enmascarado[i] != datos_txt[i]) {
            cout << "El enmascaramiento no coincide" << endl;
            return false;
        }
    }
    cout << "El enmascaramiento coincide :)" << endl;
    return true;
}






