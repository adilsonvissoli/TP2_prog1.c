#include <stdio.h>
#include "Gerais.h"


int menu(void){

    int opc=0;

    printf("\n\n|========================|\n");
    printf("|=====MENU PRINCIPAL=====|\n");
    printf("|========================|\n");
    printf("1. Cadastro de frota.\n");
    printf("2. Cadastro de ocorrencias.\n");
    printf("3. Atendimento a ocorrencia.\n");
    printf("0. Sair.\n");
    printf("-->");
    scanf("%i", &opc);
    getchar();

    return opc;
}

int menu1(void){

    int opc=0;

    printf("\n\n|=======================|\n");
    printf("|===Cadastro de frota===|\n");
    printf("|=======================|\n");
    printf("1. Incluir nova viatura.\n");
    printf("2. Listar todas as viaturas.\n");
    printf("3. Listar viaturas ativas.\n");
    printf("4. Listar viaturas por modelo.\n");
    printf("5. Dar baixa em uma viatura.\n");
    printf("6. Consultar viatura pelo código.\n");
    printf("0. Sair.\n");
    printf("-->");
    scanf("%i", &opc);
    getchar();

    return opc;
}

int menu2(void){

    int opc=0;

    printf("\n\n|=============================|\n");
    printf("|===Cadastro de ocorrências===|\n");
    printf("|=============================|\n");
    printf("1. Incluir nova ocorrência.\n");
    printf("2. Listar todas as ocorrências.\n");
    printf("3. Listar ocorrências atendidas.\n");
    printf("4. Listar ocorrências pendentes.\n");
    printf("5. Consultar ocorrência por código.\n");
    printf("6. Consulta ocorrência por tipo.\n");
    printf("0. Sair.\n");
    printf("-->");
    scanf("%i", &opc);
    getchar();

    return opc;
}

int menu3(void){

    int opc=0;

    printf("\n\n|===============================|\n");
    printf("|===Atendimento de ocorrência===|\n");
    printf("|===============================|\n");
    printf("1. Atender uma ocorrência pendente.\n");
    printf("2. Listar ocorrências atendidas por uma determinada viatura.\n");
    printf("3. Listar ocorrências atendidas por tipo.\n");
    printf("4. Listar ocorrências atendidas por intervalo de data.\n");
    printf("0. Sair.\n");   
    printf("-->");
    scanf("%i", &opc);
    getchar();

    return opc;
}

void imprimirVia(struct viatura v)
{
    verif_via();

    printf("\n\nCódigo..............: %02i", v.codigo);
    printf("\nTipo................: %s", v.tipo);
    printf("\nFabricante..........: %s", v.fabricante);
    printf("\nModelo..............: %s", v.modelo);
    printf("\nAno de produçaõ.....: %i", v.producao);
    printf("\nvalor...............: %.2f", v.valor);
    printf("\nSituação............: %s", v.situacao ? "Ativa" : "Parada");
}

void imprimirOcr(struct ocorrencia o)
{
    verif_ocr();

    printf("\n\nCódigo...............: %02i", o.codigo);
    printf("\nTipo.................: %s",  o.tipo);
    printf("\nData.................: %02i/%02i/%i", o.data.dia, o.data.mes, o.data.ano);
    printf("\nRegistrante..........: %s",  o.nome);
    printf("\nStatus de ocorrencia.: %s",  o.status ? "Atendida" : "Pendente");
    printf("\nViatura responsável..: %i",  o.codigo_via);
}

void verif_via()
{
    if(qtd_via == 0){
        printf("Nenhuma viatura cadastrada\n");
    }
}

void verif_ocr()
{
    if(qtd_ocr == 0){
        printf("Nenhuma ocorrência cadastrada\n");
    }
}

void minusculo(string minuscula)
{
    for (int i=0;i<T; i++){
        if(minuscula[i] >= 65 && minuscula[i] <=90){
            minuscula[i] += 32;
        }
    }
}

int verificacao_data(int dia, int mes, int ano)
{
    const u_int meses_31[] = {1, 3, 5, 7, 8, 10, 12};
    const u_int meses_30[] = {4, 6, 9, 11};

    if(ano > 1800 && ano <= 2026){
        for(int i=0; i<7; i++){
            //meses com 31 dias
            if(mes == meses_31[i]){
                if(dia >= 1 && dia <= 31){
                    return 1;
                }
            }
            //meses com 30 dias
            else if(mes == meses_30[i]){
                if(dia >= 1 && dia <= 30){
                    return 1;
                }
            }
            //mes 2
            else if(mes == 2) {
                //bissexto
                if(ano % 4 == 0 && dia >= 1 && dia <=29){
                    return 1;
                }
                //nao bissexto
                if(ano % 4 != 0 && dia >= 1 && dia <= 28){
                    return 1;
                }
            }
        } 
    }
    return 0;
}
