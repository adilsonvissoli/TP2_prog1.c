#include <stdio.h>
#include <string.h>
#include "Gerais.h"
#include "Viatura.h"
#include "Ocorrência.h"
#include "Atendimento.h"

#define T 100

//tipo inteiro estritamente positivo
typedef unsigned int u_int;

//criação do tipo string
typedef char string[T];

//ESTRUTURA --> primeiro switch case para 1. 2. ou 3. --> segundo switch case para as funcoes de cada necessidade. (do while para rodar tudo pelo menos uma vez(em cada menu))
int opcao, opcao1, opcao2, opcao3;

int main()
{
    do {
        opcao = menu();
            switch (opcao) {
                
                case 1:
                do{
                opcao1 = menu1();
                    switch (opcao1) {
                        case 0:
                        break;
                        case 1: if (qtd_via >= T) {
                                    printf("O limite de viaturas foi atingido!\n");
                                } else {
                                    via[qtd_via] = cadastrarVia();
                                    qtd_via++;
                                }
                                break;
                        case 2: listarVia();
                                break;              
                        case 3: ativas();
                                break;
                        case 4: modelo();
                                break;
                        case 5: baixa();
                                break;
                        case 6: verif();
                                break;
                        default: printf("Opção não existente!");
                        break;
                    }
                } while(opcao1 != 0);
                break;
                case 2:
                do{
                opcao2 = menu2();
                    switch (opcao2) {
                        case 0:
                        break;
                        case 1: if(qtd_ocr >= T){
                                    printf("O limite de ocorrências foi atingido!\n");
                                } else {
                                    ocr[qtd_ocr] = cadastrarOcr();
                                    qtd_ocr++;
                                }   
                                break;
                        case 2: listarOcr();
                                break;
                        case 3: atendidas();
                                break;
                        case 4: pendentes();
                                break;
                        case 5: por_codigo();       
                                break;
                        case 6: por_tipo();
                                break;
                        default: printf("Opção não existente!");
                        break;
                    }
                } while (opcao2 != 0);
                break;
                case 3:
                do{
                opcao3 = menu3();
                    switch (opcao3) {
                        case 0:
                        break;
                        case 1: atendimento();
                                break;
                        case 2: PorVia();
                                break;
                        case 3: PorTipo();
                                break;
                        case 4: PorInter();
                                break; 
                        default: printf("Opção não existente!");
                        break;           
                    }
                } while (opcao3 != 0);
                break;
            }
    } while(opcao != 0);   
    return 0;
}