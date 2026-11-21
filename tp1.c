#include <stdio.h>
#include <string.h>

#define T 100

typedef unsigned int u_int;

typedef char string[T];

struct viatura {
    u_int codigo; // xx
    string tipo; //carro ou moto
    string fabricante; //marca
    string modelo; // modelo
    int producao; // ano de produção
    float valor; //valor de aquisição
    int situacao; //1 ativa, 0 parada
};

struct viatura via[T];
u_int qtd_via = 0;

//toda nova ocorrencia entra como pendente
struct data {
    int dia;
    int mes;
    int ano;
};

struct ocorrencia {
    int codigo;
    string tipo; //assalto, latrocínio, roubo, furto, acidente de trânsito, estupro, estorção.
    struct data data; //struct de 3 ints
    string nome;
    int status; //1 atendida, 0 pendente
    int codigo_via;
};

struct ocorrencia ocr[T];
u_int qtd_ocr=0;

//ESTRUTURA --> primeiro switch case para 1. 2. ou 3. --> segundo switch case para as funcoes de cada necessidade. (do while para rodar tudo pelo menos uma vez)

//DECLARAÇÕES!!!
//geral
int menu(void), menu1(void), menu2(void), menu3(void);
void imprimirVia(struct viatura v);
void imprimirOcr(struct ocorrencia o);
void verif_via();
void verif_ocr();
void minusculo(string palavra);
int verificacao_data(int dia, int mes, int ano);
int opcao, opcao1, opcao2, opcao3;

//case 1
struct viatura cadastrarVia(void);
void listarVia(void);
void ativas(void);
void modelo(void);
void baixa(void);
void verif(void);

//case 2
struct ocorrencia cadastrarOcr(void);
void listarOcr(void);
void atendidas(void);
void pendentes(void);
void codigo(void);
void tipo(void);

//case 3
void atendimento(void);
void PorVia(void);
void PorTipo(void);
void PorInter(void);

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
                        case 5: codigo();       
                                break;
                        case 6: tipo();
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

//IMPLEMENTAÇÕES
//geral
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

//--------------------
//case 1
//--------------------

struct viatura cadastrarVia(void)
{
    struct viatura aux;
    int verif_tipo=0, verif_producao=0, verif_valor=0, verif_situacao=0;

    again:
    verif_tipo=0, verif_producao=0, verif_valor=0, verif_situacao=0;
    aux.codigo = qtd_via;
    printf("\nCódigo..............:%02i\n", qtd_via);
    
    printf("Tipo................:");
    fgets(aux.tipo, T, stdin);
    aux.tipo[strlen(aux.tipo)-1] = '\0';
    printf("Fabricante..........:");
    fgets(aux.fabricante, T, stdin);
    aux.fabricante[strlen(aux.fabricante)-1] = '\0';
    printf("Modelo..............:");
    fgets(aux.modelo, T, stdin);
    aux.modelo[strlen(aux.modelo)-1] = '\0';

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
    if(!strcmp(aux.tipo, "Carro") || !strcmp(aux.tipo, "Moto")){
        verif_tipo = 1;
    } if(!verif_tipo){
        printf("Erro no tipo. Digite novamente!\n");
        goto again;
    }
    //muito extremo
    if(aux.producao > 1800 && aux.producao <= 2026){
        verif_producao = 1;
    } if(!verif_producao){
        printf("Erro no ano de produção. Tente novamente!\n");
        goto again;
    }
    //entre cem milhoes e 1
    if(aux.valor > 0 && aux.valor <= 100000000){
        verif_valor = 1;
    } if(!verif_valor){
        printf("Erro no valor. Tente novamente!\n");
        goto again;
    }
    // 0 ou 1
    if(aux.situacao == 0 || aux.situacao == 1){
        verif_situacao = 1;
    } if(!verif_situacao){
        printf("Erro na situação. Tente novamente!\n");
        goto again;
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

//--------------------------
//case 2
//--------------------------

struct ocorrencia cadastrarOcr(void)
{
    struct ocorrencia aux;
    int verif_tipo = 0, verif_data = 0 ;

    remake: 
    verif_data = 0 ;

    aux.codigo = qtd_ocr;
    printf("Código..............: %02i", qtd_ocr);

    printf("\n-->Assalto, latrocínio, roubo, furto, acidente de trânsito, estupro, estorção.<--\n");
    printf("Crime cometido......:");
    fgets(aux.tipo, T, stdin);
    aux.tipo[strlen(aux.tipo)-1] = '\0';

    printf("dia/mês/ano.........:");
    scanf("%d/%d/%d", &aux.data.dia, &aux.data.mes, &aux.data.ano);
    getchar();

    printf("Nome completo do registrante....:");
    fgets(aux.nome, T, stdin); 
    aux.nome[strlen(aux.nome) -1] = '\0';

    minusculo(aux.tipo);

    //---------------VERIFICACAO
    if(!strcmp(aux.tipo, "assalto") || !strcmp(aux.tipo, "latrocínio") || !strcmp(aux.tipo, "roubo") || !strcmp(aux.tipo, "furto") || !strcmp(aux.tipo, "acidente de trânsito") || !strcmp(aux.tipo, "estupro") || !strcmp(aux.tipo, "estorção")){
        verif_tipo = 1;
    } if(!verif_tipo){
        printf("Erro no crime cometido. Tente novamente!\n");
        goto remake;
    }

    verif_data = verificacao_data(aux.data.dia, aux.data.mes, aux.data.ano);

    if(!verif_data){
        printf("Erro no campus da data. Tente novamente!\n");
        goto remake;
    }

    aux.status = 0;
    aux.codigo_via = 0;

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

void codigo(void)
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
void tipo(void)
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

//--------------------
//case 3
//-------------------- 

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

    denovo:
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
        goto denovo;
    }

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