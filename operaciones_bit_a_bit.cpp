// 1. XOR entre I_D (img transformada, es la img final parcial) y la img I_M.bmp (es la img aleatoria)
void aplicarXor(unsigned char* imagen, unsigned char* IM, int tamaño) {
    for(int i = 0; i < tamaño; i++) {
        imagen[i] ^= IM[i];
    }
}

// 2. Rotación de 3 bits a la DERECHA (como en el Caso 1)
unsigned char rotarDerecha(unsigned char byte) {
    return (byte >> 3) | (byte << (8 - 3));
}

// 3. Rotación de 3 bits a la IZQUIERDA (para revertir)
unsigned char rotarIzquierda(unsigned char byte) {
    return (byte << 3) | (byte >> (8 - 3));
}
