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

int cont=-1;
struct pessoa pg[maxpessoas];


void pausa() {
    printf("\n\n===================================\n");
    printf("Send any input to continue...");
    char a;
    scanf("%s", &a); // Aguarda a entrada do usuário
}


void adicionapessoa(){
    cont++;
    system("clear");
    printf("===================================\n");
    printf("ADICIONANDO PROFESSOR...\n");
    printf("===================================\n");
    printf("Código: ");
    scanf("%s", pg[cont].codigo);
    printf("Nome: ");
    scanf("%s", pg[cont].nome);
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


int main(){
    int num = 0;
    setlocale(LC_ALL, "Portuguese_Brasil");
    while (num != -1)
    {
        system("clear");
        printf(
        "===================================\n"
        "          SELECIONAR OPÇÃO\n"
        "===================================\n"
        "1 - INCLUSÃO DE DADOS\n"
        "2 - LISTAGEM GERAL DE DADOS\n"
        "3 - LISTAGEM PARCIAL DE DADOS\n"
        "4 - MODIFICAÇÃO TOTAL DE DADOS\n"
        "5 - MODIFICAÇÃO PARCIAL DE DADOS\n"
        "===================================\n");
        printf("Sua Opção: ");
        scanf("%d", &num);
        if(num == 1)
            adicionapessoa();
        if(num == 2)
            listagemgeral();
    }
    return 0;
}


