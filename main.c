#include <stdio.h>
#include <stdlib.h>
#define maxpessoas 50
/*PROFESSORES: Código (001, 029, ...), nome professor, Titulação (ESP, MST,
DOU, POS), sexo (M,F); salário, Departamento (DCC, DEX, DCA, DLT, DEC, ...);*/
struct teste{
    char codigo[4];
    char nome[6];
    char titulacao[4];
    char sexo[2];
    int salario;
    char departamento[4];
};


void main(){
    printf(
        "==============================\n"
        "       SELECIONAR OPÇÃO\n"
        "==============================\n"
        "1 - ADICIONAR UM VALOR\n"
        "2 - LISTAR VALORES\n"
        "3 - REMOVER UM VALOR\n"
        "");
    
    struct teste p[maxpessoas] = {"021", "João", "MST", "M", 12500, "DCC"};
    printf("\nCódigo: %s", p[0]s1.codigo);
    printf("\nNome: %s", s1.nome);
    printf("\nTitulação: %s", s1.titulacao);
    printf("\nSexo: %s", s1.sexo);
    printf("\nSalário:  %d", s1.salario);
    printf("\nDepartamento: %s", s1.departamento);
}
