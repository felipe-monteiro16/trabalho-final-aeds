#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define maxpessoas 50

/*PROFESSORES: 
Código (001, 029, ...), 
nome professor, 
Titulação (ESP, MST, DOU, POS), 
sexo (M,F); 
salário, 
Departamento (DCC, DEX, DCA, DLT, DEC, ...)
*/
struct pessoa{
    char codigo[50];
    char nome[50];
    char titulacao[50];
    char sexo[50];
    //int salario;
    char departamento[50];
};


int cont = 0;
struct pessoa pg[maxpessoas];


void pausa() {
    printf("\n\n===================================\n");
    printf("Send any input to continue...");
    char a;
    scanf("%s", &a); // Aguarda a entrada do usuário
}


void adicionapessoa(){
    cont++;
    char nome1;
    system("clear");
    printf("===================================\n");
    printf("ADICIONANDO PROFESSOR...\n");
    printf("===================================\n");
    printf("Código: ");
    scanf("%s", pg[cont].codigo);
    printf("Nome: ");
    scanf("%s", pg[cont].nome);
    // strcpy(nome1, pg[cont].nome);
    printf("Titulação: ");
    scanf("%s", pg[cont].titulacao);
    printf("Sexo: ");
    scanf("%s", pg[cont].sexo);
    //printf("Salário: ");
    //scanf("%d", &pg.salario);
    printf("Departamento: ");
    scanf("%s", pg[cont].departamento);
    pausa();
    return;
}


void listagemgeral(){
    int c;
    system("clear");
    printf("===================================\n");
    printf("LISTAGEM GERAL\n");
    printf("===================================\n");
    for(c=0; c<=cont; c++){
        printf("\n-------------------------\n");
        printf("Professor %d\n", c+1);
        printf("-------------------------");
        printf("\nCódigo: %s", pg[c].codigo);
        printf("\nNome: %s", pg[c].nome);
        printf("\nTitulação: %s", pg[c].titulacao);
        printf("\nSexo: %s", pg[c].sexo);
        //printf("\nSalário:  %d", &pg.salario);
        printf("\nDepartamento: %s", pg[c].departamento);  
        printf("\n");
    }
    pausa();
    return;
}


void listagemparcial(){
    int op, bk = 0;
    while(bk == 0){     // OPÇÕES LISTAGEM PARCIAL
        system("clear");
        printf("===================================\n");
        printf("LISTAGEM PARCIAL\n");
        printf("===================================\n");
        printf("TIPO DE LISTAGEM: \n");
        printf("\n[0] - Filtrar por Categoria\n");
        printf("[1] - Filtrar por Pessoa\n");
        printf("[2] - Cancelar\n");
        printf("\nSua Opção: ");
        scanf("%d", &op);
        switch(op){
            case 0:     // FILTRAR POR CATEGORIA
                int cat, c;
                system("clear");
                printf("===================================\n");
                printf("LISTAGEM PARCIAL\n");
                printf("===================================\n");
                printf("Selecionar Categoria:\n\n");
                printf("[0] - Código\n");
                printf("[1] - Nome\n");
                printf("[2] - Titulação\n");
                printf("[3] - Sexo\n");
                printf("[4] - Departamento\n");
                printf("\n Sua Opção:");
                scanf("%d", &cat);
                switch(cat){
                    case 0:     // CÓDIGO
                        for(c=0; c<=cont; ++c){
                            printf("\nProfessor %d\n", c+1);
                            printf("Código: %s\n", pg[c].codigo);
                            
                        }
                        break;
                    case 1:     // NOME
                    
                        break;
                    case 2:     // TITULAÇÃO
                    
                        break;
                    case 3:     // SEXO
                    
                        break;
                    case 4:     // DEPARTAMENTO
                    
                        break;
                    default:
                        printf("\nOpção Inválida!");
                        pausa();
                }
                bk = 1;
                break;
            case 1:
                int p;
                system("clear");
                printf("===================================\n");
                printf("LISTAGEM PARCIAL\n");
                printf("===================================\n");
                printf("Selecionar Pessoa:\n");
                for(c=0; c<=cont; ++c){
                    printf("[%d] - %s %d\n", c, pg[c].nome, c+1);
                }
                while(1 == 1){
                    printf("Sua Opção: ");
                    scanf("%d", &p);
                    if(p > cont || p < 0)
                        printf("Opção Inválida\n");
                    else{
                        printf("\n-------------------------\n");
                        printf("Professor %d\n", p+1);
                        printf("-------------------------");
                        printf("\nCódigo: %s", pg[p].codigo);
                        printf("\nNome: %s", pg[p].nome);
                        printf("\nTitulação: %s", pg[p].titulacao);
                        printf("\nSexo: %s", pg[p].sexo);
                        //printf("\nSalário:  %d", &pg.salario);
                        printf("\nDepartamento: %s", pg[p].departamento);  
                        printf("\n");
                        break;
                    }
                }
                bk = 1;
                break;
            case 2:
                bk = 1;
                break;
            default:
                printf("\nOpção Inválida");
                break;
        }
        pausa();
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");
    int num = 0;
    strcpy(pg->codigo, "001");
    strcpy(pg->nome, "João Batista");
    strcpy(pg->titulacao, "DOU");
    strcpy(pg->departamento, "DCC");
    strcpy(pg->sexo, "M");
    //{"001", "JoãoBatista", "DOU", "M", "DCC"};
    //pg[1] = {"029", "AntônioWilson", "DOU", "M", "DCE"};
    while (num != 99)
    {
        system("clear");
        printf(
        "===================================\n"
        "          SELECIONAR OPÇÃO\n"
        "===================================\n"
        " 1 - INCLUSÃO DE DADOS\n"
        " 2 - LISTAGEM GERAL DE DADOS\n"
        " 3 - LISTAGEM PARCIAL DE DADOS\n"
        " 4 - MODIFICAÇÃO TOTAL DE DADOS\n"
        " 5 - MODIFICAÇÃO PARCIAL DE DADOS\n"
        "99 - ENCERRAR PROGRAMA\n"
        "===================================\n");
        printf("Sua Opção: ");
        scanf("%d", &num);
        switch(num){
            case 1:
                adicionapessoa();
                break;
            case 2:
                listagemgeral();
                break;
            case 3:
                listagemparcial();
                break;
            case 99:
                printf("===================================\n");
                printf("        PROGRAMA ENCERRADO\n");
                printf("===================================\n");
                break;
            default:
                printf("Opção Inválida.");
                pausa();
                break;
        }
    }
    return 0;
}


