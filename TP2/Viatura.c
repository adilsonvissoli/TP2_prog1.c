#include <stdio.h>
#include "Viatura.h"

u_int qtd_via = 0;

struct viatura cadastrarVia(void)
{
    struct viatura aux;
    int verif_tipo=0, verif_producao=0, verif_valor=0, verif_situacao=0;

    do{
        //---------cadastro
        verif_tipo=0, verif_producao=0, verif_valor=0, verif_situacao=0;
        aux.codigo = qtd_via;
        printf("\nCódigo..............:%02i\n", qtd_via);
        
        printf("Tipo................:");
        fgets(aux.tipo, T, stdin);
        aux.tipo[strlen(aux.tipo)-1] = '\0';
        minusculo(aux.tipo);

        printf("Fabricante..........:");
        fgets(aux.fabricante, T, stdin);
        aux.fabricante[strlen(aux.fabricante)-1] = '\0';
        minusculo(aux.fabricante);

        printf("Modelo..............:");
        fgets(aux.modelo, T, stdin);
        aux.modelo[strlen(aux.modelo)-1] = '\0';
        minusculo(aux.modelo);

        printf("Ano de produção.....:");
        scanf("%i", &aux.producao);
        getchar();
        printf("valor...............:");
        scanf("%f", &aux.valor);
        getchar();

        printf("Ativa --> 1 // Parada --> 0\n");
        printf("Situação............:");
        scanf("%i", &aux.situacao);
        getchar();

        //----------------VERIFICAÇÕES
        //se nn for moto nem carro
        if(!strcmp(aux.tipo, "carro") || !strcmp(aux.tipo, "moto")){
            verif_tipo = 1;
        } if(!verif_tipo){
            printf("Erro no tipo. Digite novamente!\n");
        }
        //muito extremo
        if(aux.producao > 1800 && aux.producao <= 2027){
            verif_producao = 1;
        } if(!verif_producao){
            printf("Erro no ano de produção. Tente novamente!\n");
        }
        //entre cem milhoes e 1
        if(aux.valor > 0 && aux.valor <= 100000000){
            verif_valor = 1;
        } if(!verif_valor){
            printf("Erro no valor. Tente novamente!\n");
        }
        // 0 ou 1
        if(aux.situacao == 0 || aux.situacao == 1){
            verif_situacao = 1;
        } if(!verif_situacao){
            printf("Erro na situação. Tente novamente!\n");
        } while (!verif_tipo || !verif_producao || !verif_valor || !verif_situacao);
    }

    return aux; 
}

void listarVia(void)
{
    for(int i=0; i < qtd_via; i++){
        imprimirVia(via[i]);
    }
}

void ativas(void)
{
    int encontrou =0;
    for(int i=0; i < qtd_via; i++){
        if(via[i].situacao){
            imprimirVia(via[i]);
            encontrou = 1;
        }
    } if(!encontrou){
        printf("Não há nenhuma viatura ativa!\n");
    }
}

void modelo(void)
{
    string teste;
    int encontrou =0;
    printf("Qual é o modelo que você deseja consultar?\n");
    printf("-->");
    fgets(teste, T, stdin);
    teste[strlen(teste)-1]='\0';

    for(int i=0; i < qtd_via; i++){
        if(!strcmp(via[i].modelo, teste)){
            imprimirVia(via[i]);
            encontrou =1;
        }
    } if(!encontrou){
        printf("Não há nenhuma viatura desse modelo cadastrada!\n");
    }
}

void baixa(void)
{
    int baixa;
    int encontrou_via=0,encontrou_codigo=0;
    for(int i=0; i < qtd_via; i++){
        if(via[i].situacao){
            imprimirVia(via[i]);
            encontrou_via=1;
        }
    } if(!encontrou_via){
        printf("Não há nenhuma viatura ativa!\n");
    }
    printf("\nPara dar baixa em uma viatura, veja as opções de baixa e indique-a pelo seu código\n");
    printf("-->");
    scanf("%i", &baixa);

    for(int i=0; i < qtd_via; i++){
        if(via[i].codigo == baixa){
            if(via[i].situacao == 0){
                printf("Essa viatura já está parada!");
            } else {
                via[i].situacao = 0;
                encontrou_codigo=1;
            }
        }
    }
    if(!encontrou_codigo){
        printf("Não há nehuma viatura de código %i cadastrada\n", baixa);
    }
}

void verif(void)
{
    int verificacao=0;
    int flag=0;
    printf("\nQual viatura você está buscando (por código)?\n");
    printf("-->");
    scanf("%i", &verificacao);

    for(int i=0; i< qtd_via; i++){
        if(via[i].codigo == verificacao){
            imprimirVia(via[i]);
            flag =1;
            break;
        } 
    }
    if (!flag){
            printf("Viatura não existente!\n");
    }
}