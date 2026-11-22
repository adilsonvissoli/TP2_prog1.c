#include <stdio.h>
#include "Atendimento.h"

void atendimento(void)
{
    int testeOcr = 0, testeVia = 0, encontrouOcr=0, encontrouVia=0;

    printf("\n|=====================|\n");
    printf("|=====ATENDIMENTO=====|\n");
    printf("|=====================|\n");
    printf("Qual é o código da ocorrência?\n");
    printf("-->");
    scanf("%i", &testeOcr);
    printf("Qual é o código da viatura responsável pelo atendimento?\n");
    printf("-->");
    scanf("%i", &testeVia);

    for(int i=0; i<qtd_ocr; i++){
        //procura ocr
        if(testeOcr == ocr[i].codigo){
            encontrouOcr = 1;
            //verif ocr
            if(ocr[i].status){
                printf("Ocorrência já atendida!");
                return ;
            } 
            for(int j=0; j<qtd_via; j++){
                //procura via
                if(testeVia == via[j].codigo){
                    encontrouVia =1;
                    //verif via
                    if(!via[j].situacao){
                        printf("Está viatura está parada!\n");
                        return;
                    } 
                    //função principal
                    else{
                        ocr[i].status = 1;
                        ocr[i].codigo_via = testeVia;

                        printf("Atendimento concluído com sucesso!\n");
                        return;
                    }
                }
            } if(!encontrouVia){
                printf("Viatura não encontrada!\n");
            }
        }
    }if (!encontrouOcr){
        printf("Ocorrência não encontrada!\n");
    }
}

void PorVia(void)
{
    int teste=0, encontrou=0;
    printf("Qual o código da viatura que você quer ver seus atendimentos?\n");
    printf("-->");
    scanf("%i", &teste);
    for(int i=0; i<qtd_ocr; i++){
        if(ocr[i].codigo_via == teste && ocr[i].status){
            imprimirOcr(ocr[i]);

            encontrou = 1;
        } else if(ocr[i].codigo_via == teste && !ocr[i].status){
            printf("Ocorrência pendente!\n");
        }
    }
    if(!encontrou){
        printf("Nenhuma ocorrência encontrada\n");
    }
}

//Vou fazer o aux se tornar minusculo e aceitar uma letra de diferença (para passar com diferenças de acentuação)
void PorTipo(void)
{
    string aux;
    int encontrou=0;
    printf("Qual tipo de crime você deseja consultar por?\n");
    printf("-->");
    fgets(aux, T, stdin);
    aux[strlen(aux)-1] = '\0';
    for(int i=0; i < qtd_ocr; i++){
        if(strcmp(aux, ocr[i].tipo) == 0 && ocr[i].status == 1){
            imprimirOcr(ocr[i]);
            encontrou = 1;
        }
    } if(!encontrou){
        printf("Nenhuma ocorrência atendida do tipo %s\n", aux);
    }
}

void PorInter(void)
{
    int teste_ano1, teste_mes1, teste_dia1, teste_ano2, teste_mes2, teste_dia2;
    int inf, sup, data, encontrou = 0;
    int troca;

    do{
        int verif_data1 =0, verif_data2 =0;
        printf("Digite as datas no formato: dd/mm/aaaa, primeiro a menor e depois a maior!\n");
        printf("-->");
        scanf("%d/%d/%d", &teste_dia1, &teste_mes1, &teste_ano1);
        printf("-->");
        scanf("%d/%d/%d", &teste_dia2, &teste_mes2, &teste_ano2);

        verif_data1 = verificacao_data(teste_dia1,teste_mes1,teste_ano1);
        verif_data2 = verificacao_data(teste_dia2,teste_mes2,teste_ano2);

        if(!(verif_data1 && verif_data2)){
            printf("Alguma(s) data está forá do intervalor disponivel. Tente novamente!\n");
        }
    } while (!verif_data1 || !verif_data2);

    /*
    IMPORTANTE, o modelo aaaa/mm/dd é o correto, substituir por dd/mm/aaaa.
    Pode parecer é intuitivo, mas inverte a prioridade de "pesos" da data. 
    */

    inf = teste_ano1 * 10000 + teste_mes1 * 100 + teste_dia1; //aaaa/mm/dd
    sup = teste_ano2 * 10000 + teste_mes2 * 100 + teste_dia2; //aaaa/mm/dd

    if(inf > sup){
        printf("A ordem das datas está invertida, entretanto o erro já foi resolvido!");
        troca = inf;
        inf = sup;
        sup = troca;
    }

    for(int i=0; i<qtd_ocr; i++){

    data = ocr[i].data.ano * 10000 + ocr[i].data.mes *100 + ocr[i].data.dia; // aaaa/mm/dd 
        if(data <= sup && data >= inf && ocr[i].status){
                imprimirOcr(ocr[i]);
                encontrou = 1;
            } else if(data <= sup && data >= inf && !ocr[i].status){
                printf("Ocorrência não atendida\n");
            }     
        } if(!encontrou){
            printf("Não há ocorrências nese intervalo de datas!\n");
        } 
}