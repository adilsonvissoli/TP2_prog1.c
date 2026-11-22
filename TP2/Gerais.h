#ifndef GERAIS_H
#define GERAIS_H


int menu(void), menu1(void), menu2(void), menu3(void);
void imprimirVia(struct viatura v);
void imprimirOcr(struct ocorrencia o);
void verif_via();
void verif_ocr();
void minusculo(string palavra);
int verificacao_data(int dia, int mes, int ano);

#endif