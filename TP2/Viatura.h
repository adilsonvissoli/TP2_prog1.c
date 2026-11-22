#ifndef VIATURA_H
#define VIATURA_H

#include <stdio.h>

typedef struct viatura {
    u_int codigo; // xx
    string tipo; //carro ou moto
    string fabricante; //marca
    string modelo; // modelo
    int producao; // ano de produção
    float valor; //valor de aquisição
    int situacao; //1 ativa, 0 parada
} via_t;
//toda nova ocorrencia entra como pendente

struct viatura cadastrarVia(void);
void listarVia(void);
void ativas(void);
void modelo(void);
void baixa(void);
void verif(void);

#endif