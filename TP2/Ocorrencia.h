#ifndef OCORRÊNCIA_H
#define OCORRÊNCIA_H

#include <stdio.h>

struct data {
    int dia;
    int mes;
    int ano;
};

//tipos de dados de uma ocorrência
typedef struct ocorrencia {
    int codigo;
    string tipo; //assalto, latrocínio, roubo, furto, acidente de trânsito, estupro, estorção.
    struct data data; //struct de 3 ints
    string nome;
    int status; //1 atendida, 0 pendente
    int codigo_via;
} ocr_t;

struct ocorrencia cadastrarOcr(void);
void listarOcr(void);
void atendidas(void);
void pendentes(void);
void por_codigo(void);
void por_tipo(void);

#endif