#include <stdio.h>
#include "Ocorrência.h"

u_int qtd_ocr=0;

struct ocorrencia cadastrarOcr(void)
{
    struct ocorrencia aux;
    int verif_tipo = 0, verif_data = 0 ;

    do{
        //-------cadastro
        verif_tipo = 0, verif_data = 0 ;

        aux.codigo = qtd_ocr;
        printf("Código..............: %02i", qtd_ocr);

        printf("\n-->Assalto, latrocínio, roubo, furto, acidente de trânsito, estupro, estorção.<--\n");
        printf("Crime cometido......:");
        fgets(aux.tipo, T, stdin);
        aux.tipo[strlen(aux.tipo)-1] = '\0';
        minusculo(aux.tipo);

        printf("dia/mês/ano.........:");
        scanf("%d/%d/%d", &aux.data.dia, &aux.data.mes, &aux.data.ano);
        getchar();

        printf("Nome completo do registrante....:");
        fgets(aux.nome, T, stdin); 
        aux.nome[strlen(aux.nome) -1] = '\0';


        //---------------VERIFICACAO
        if(!strcmp(aux.tipo, "assalto") ||
            !strcmp(aux.tipo, "latrocínio") ||
            !strcmp(aux.tipo, "roubo") ||
            !strcmp(aux.tipo, "furto") ||
            !strcmp(aux.tipo, "acidente de trânsito") ||
            !strcmp(aux.tipo, "estupro") ||
            !strcmp(aux.tipo, "estorção")){
            verif_tipo = 1;
        } if(!verif_tipo){
            printf("Erro no crime cometido. Tente novamente!\n");
        }

        verif_data = verificacao_data(aux.data.dia, aux.data.mes, aux.data.ano);

        if(!verif_data){
            printf("Erro no campus da data. Tente novamente!\n");
        }

        aux.status = 0;
        aux.codigo_via = 0;
    } while (!verif_tipo || !verif_data);

    return aux;
}

void listarOcr(void)
{
    for(int i=0; i < qtd_ocr; i++){
        imprimirOcr(ocr[i]);
    }
}

void atendidas(void)
{
    for(int i=0; i < qtd_ocr; i++){
        if(ocr[i].status){
            imprimirOcr(ocr[i]);
        }
    }
}

void pendentes(void)
{
    for(int i=0; i < qtd_ocr; i++){
        if(ocr[i].status == 0){
            imprimirOcr(ocr[i]);
        }
    }
}

void por_codigo(void)
{
    int teste = 0, encontrou = 0;

    printf("Qual ocorrência você quer verificar (Por código)?\n");
    printf("-->");
    scanf("%i", &teste);

    for(int i=0; i<qtd_ocr; i++){
        if(ocr[i].codigo == teste){
            imprimirOcr(ocr[i]);
            encontrou = 1;
        }
    } if(!encontrou){
        printf("Nenhuma ocorrência encontrada!\n");
    }
}

//Consulta ocorrência por tipo
void por_tipo(void)
{
    string teste;
    int encontrou = 0;

    printf("Qual o tipo de ocorrência você quer verificar?\n");
    printf("-->");
    fgets(teste, T, stdin);
    minusculo(teste);
    teste[strlen(teste)-1] = '\0';

    for(int i=0; i < qtd_ocr; i++){
        if(!strcmp(teste, ocr[i].tipo)){
            imprimirOcr(ocr[i]);
            encontrou = 1;
        }
    } if(!encontrou){
        printf("Nenhuma ocorrência encontrada!\n");
    }
}