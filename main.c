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


void limpartela(){
    //system("cls"); // Se estiver em ambiente Windows
    system("clear"); // Se estiver em ambiente Linux
}


void adicionapessoa(){ // FUNÇÃO PARA ADICIONAR PROFESSOR
    cont++;
    char nome1[50], sexo[50], titulacao[10];
    limpartela();
    printf("===================================\n");
    printf("ADICIONANDO PROFESSOR...\n");
    printf("===================================\n");
    printf("Código: ");
    scanf("%s", pg[cont].codigo);
    while (getchar() != '\n'); 
    printf("Nome: ");
    fgets(nome1, sizeof(nome1), stdin); 
    nome1[strcspn(nome1, "\n")] = '\0';
    strcpy(pg[cont].nome, nome1);
    // printf("Titulação: ");
    // scanf("%s", pg[cont].titulacao);
    while(1){               // VALIDAÇÃO DO Titulação//(GRD, MST, DOU, POS, OUT)
        printf("Lista de Titulações: [GRD, MST, DOU, POS, OUT]\nTitulação: ");
        scanf("%s", titulacao);

        if (strcmp(titulacao, "GRD") == 0|| strcmp(titulacao, "grd") == 0){
            strcpy(pg[cont].titulacao, "GRD");
            break;
        } else if(strcmp(titulacao, "MST") == 0 || strcmp(titulacao, "mst") == 0){
            strcpy(pg[cont].titulacao, "MST");
            break;
        } 
        else if(strcmp(titulacao, "DOU") == 0 || strcmp(titulacao, "dou") == 0){
            strcpy(pg[cont].titulacao, "DOU");
            break;
        } 
        else if(strcmp(titulacao, "POS") == 0 || strcmp(titulacao, "pos") == 0){
            strcpy(pg[cont].titulacao, "POS");
            break;
        } 
        else if(strcmp(titulacao, "OUT") == 0 || strcmp(titulacao, "out") == 0){
            strcpy(pg[cont].titulacao, "OUT");
            break;
        } else
            printf("\nPor favor, digite uma titlação válida \n");

    }
    
    
    
    while(1){               // VALIDAÇÃO DO SEXO
        printf("Sexo: ");
        scanf("%s", sexo);
        if (strcmp(sexo, "m") == 0|| strcmp(sexo, "M") == 0){
            strcpy(pg[cont].sexo, "M");
            // pg[cont].sexo = sexo;
            break;
        } else if(strcmp(sexo, "f") == 0 || strcmp(sexo, "F") == 0){
            strcpy(pg[cont].sexo, "F");
            break;
        } else
            printf("\nPor favor, digite um valor entre [M, F]\n");

    }
    
    //printf("Salário: ");
    //scanf("%d", &pg.salario);
    printf("Departamento: ");
    scanf("%s", pg[cont].departamento);
    pausa();
    return;
}


void listagemgeral(){ // FUNÇÃO PARA LISTAGEM DE TODOS OS PROFESSORES
    int c;
    limpartela();
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


void filtrarporcategoria(){ // FUNÇÃO PARA LISTAGEM POR CATEGORIA
    int cat, c;
    limpartela();
    printf("===================================\n");
    printf("LISTAGEM PARCIAL\n");
    printf("===================================\n");
    printf("Selecionar Categoria:\n\n");
    printf("[0] - Código\n");
    printf("[1] - Nome\n");
    printf("[2] - Titulação\n");
    printf("[3] - Sexo\n");
    printf("[4] - Departamento\n");
    printf("\nSua Opção: ");
    scanf("%d", &cat);
    if (cat < 0 || cat > 4) printf("\nOpção Iválida! \n");
    else {
        limpartela();
        printf("===================================\n");
        printf("LISTAGEM PARCIAL\n");
        printf("===================================\n");
        for(c=0; c<=cont; ++c){
            printf("\n---------------------\n");
            printf("Professor %d\n", c+1);
            printf("---------------------\n");
            switch(cat){
            case 0:     // CÓDIGO
                printf("Código: %s\n", pg[c].codigo);
                break;
            case 1:     // NOME
                printf("Nome: %s\n", pg[c].nome);
                break;
            case 2:     // TITULAÇÃO
                printf("Titulação: %s\n", pg[c].titulacao);
                break;
            case 3:     // SEXO
                printf("Sexo: %s\n", pg[c].sexo);
                break;
            case 4:     // DEPARTAMENTO
                printf("Departamento: %s\n", pg[c].departamento);
                break;
            default:
                printf("\nOpção Inválida!");
        
                break;
            }
        } 
    }
}


void filtrarporpessoa(){ // FUNÇÃO PARA LISTAGEM POR PROFESSOR
    int p, c;
    while(1){
        limpartela(); 
        printf("===================================\n");
        printf("LISTAGEM PARCIAL\n");
        printf("===================================\n");
        printf("Selecionar Pessoa:\n");
        for(c=0; c<=cont; ++c)  // LISTAGEM DE PROFESSORES PARA SELEÇÃO
            printf("\n[%d] - %s", c, pg[c].nome);
        printf("\n\nSua Opção: ");
        scanf("%d", &p);
        if(p > cont || p < 0){      // VERIFICAÇÃO DE INPUT INVÁLIDO
            printf("\nOpção Inválida\n");
            pausa();
            continue;
        } else{         // LISTAGEM PARCIAL DO PROFESSOR SELECIONADO
            system("clear");
            printf("===================================\n");
            printf("LISTAGEM PARCIAL\n");
            printf("===================================\n");
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
}




void listagemparcial(){ //FUNÇÃO PARA SELECIONAR TIPO DE LISTAGEM PARCIAL
    int op, bk = 0;
    while(bk == 0){     // OPÇÕES LISTAGEM PARCIAL
        limpartela();
        printf("===================================\n");
        printf("LISTAGEM PARCIAL\n");
        printf("===================================\n");
        printf("TIPO DE LISTAGEM: \n");
        printf("\n[0] - Filtrar por Categoria\n");
        printf("[1] - Filtrar por Professor\n");
        printf("[2] - Cancelar\n");
        printf("\nSua Opção: ");
        scanf("%d", &op);
        switch(op){
            case 0:     // FILTRAR POR CATEGORIA
                filtrarporcategoria();
                bk = 1;
                break;
            case 1:     // FILTRAR POR PROFESSOR
                filtrarporpessoa();
                bk = 1;
                break;
            case 2:     // VOLTA PARA MENU PRINCIPAL
                bk = 1;
                break;
            default:    // MENSAGEM DE ERRO
                printf("\nOpção Inválida");
                break;
        }
        pausa();
    }
}


void modificacaototal(){ // MODIFICAÇÃO TOTAL DOS DADOS DO PROFESSOR SELECIONADO
    int p, c;
    char nome1[50], sexo[50], titulacao[10];
    while(1){
        limpartela(); 
        printf("===================================\n");
        printf("MODIFICAÇÃO TOTAL\n");
        printf("===================================\n");
        printf("Selecionar Pessoa:\n");
        for(c=0; c<=cont; ++c)  // LISTAGEM DE PROFESSORES PARA SELEÇÃO
            printf("\n[%d] - %s", c, pg[c].nome);
        printf("\n\nSua Opção: ");
        scanf("%d", &p);
        if(p > cont || p < 0){      // VERIFICAÇÃO DE INPUT INVÁLIDO
            printf("\nOpção Inválida\n");
            pausa();
            continue;
        }
        else {      // MODIFICAÇÃO DOS DADOS DO PROFESSOR SELECIONADO
            limpartela();
            printf("=======================================\n");
            printf("MODIFICAÇÃO TOTAL - %s\n", pg[p].nome);
            printf("=======================================\n");
            printf("\nCódigo: ");
            scanf("%s", pg[p].codigo);
            while (getchar() != '\n'); 
            printf("Nome: ");
            fgets(nome1, sizeof(nome1), stdin); 
            nome1[strcspn(nome1, "\n")] = '\0';
            strcpy(pg[p].nome, nome1);
            
            
            while(1){               // VALIDAÇÃO DO Titulação//(GRD, MST, DOU, POS, OUT)
                printf("Lista de Titulações: [GRD, MST, DOU, POS, OUT]\nTitulação: ");
                scanf("%s", titulacao);
        
                if (strcmp(titulacao, "GRD") == 0|| strcmp(titulacao, "grd") == 0){
                    strcpy(pg[cont].titulacao, "GRD");
                    break;
                } else if(strcmp(titulacao, "MST") == 0 || strcmp(titulacao, "mst") == 0){
                    strcpy(pg[cont].titulacao, "MST");
                    break;
                } 
                else if(strcmp(titulacao, "DOU") == 0 || strcmp(titulacao, "dou") == 0){
                    strcpy(pg[cont].titulacao, "DOU");
                    break;
                } 
                else if(strcmp(titulacao, "POS") == 0 || strcmp(titulacao, "pos") == 0){
                    strcpy(pg[cont].titulacao, "POS");
                    break;
                } 
                else if(strcmp(titulacao, "OUT") == 0 || strcmp(titulacao, "out") == 0){
                    strcpy(pg[cont].titulacao, "OUT");
                    break;
                } else
                    printf("\nPor favor, digite uma titlação válida \n");
        
            }
    
            while(1){
                printf("Sexo: ");
                scanf("%s", sexo);
                if (strcmp(sexo, "m") == 0|| strcmp(sexo, "M") == 0){
                    strcpy(pg[cont].sexo, "M");
                    // pg[cont].sexo = sexo;
                    break;
                } else if(strcmp(sexo, "f") == 0 || strcmp(sexo, "F") == 0){
                    strcpy(pg[cont].sexo, "F");
                    break;
                } else
                    printf("\nPor favor, digite um valor entre [M, F]\n");
        
            }
            //printf("Salário: ");
            //scanf("%d", &pg.salario);
            printf("Departamento: ");
            scanf("%s", pg[p].departamento);
            pausa();
            break;
        }
    }
}


void modificacaoparcial(){
    int p, c, bk =0;
    char nome1[50], sexo[50], titulacao[10];
    while(bk == 0){
        limpartela(); 
        printf("===================================\n");
        printf("MODIFICAÇÃO TOTAL\n");
        printf("===================================\n");
        printf("Selecionar Pessoa:\n");
        for(c=0; c<=cont; ++c)  // LISTAGEM DE PROFESSORES PARA SELEÇÃO
            printf("\n[%d] - %s", c, pg[c].nome);
        printf("\n\nSua Opção: ");
        scanf("%d", &p);
        if(p > cont || p < 0){      // VERIFICAÇÃO DE INPUT INVÁLIDO
            printf("\nOpção Inválida\n");
            pausa();
            continue;
        }
        else {      // MODIFICAÇÃO DOS DADOS DO PROFESSOR SELECIONADO
            int cat;
            limpartela();
            printf("===================================\n");
            printf("MODIFICAÇÃO PARCIAL\n");
            printf("===================================\n");
            printf("Selecionar Categoria:\n\n");
            printf("[0] - Código\n");
            printf("[1] - Nome\n");
            printf("[2] - Titulação\n");
            printf("[3] - Sexo\n");
            printf("[4] - Departamento\n");
            printf("\nSua Opção: ");
            scanf("%d", &cat);
            if (cat < 0 || cat > 4) printf("\nOpção Iválida! \n");
            else {
                bk = 1;
                limpartela();
                printf("=======================================\n");
                printf("MODIFICAÇÃO PARCIAL - %s\n", pg[p].nome);
                printf("=======================================\n");
                switch(cat){
                case 0:
                    printf("\nCódigo: ");
                    scanf("%s", pg[p].codigo);
                    break;
                case 1:
                    char nome1[50];
                    while (getchar() != '\n');
                    printf("Nome: ");
                    fgets(nome1, sizeof(nome1), stdin); 
                    nome1[strcspn(nome1, "\n")] = '\0';
                    strcpy(pg[p].nome, nome1);
                    break;
                case 2:
                    while(1){               // VALIDAÇÃO DO Titulação//(GRD, MST, DOU, POS, OUT)
                        printf("Lista de Titulações: [GRD, MST, DOU, POS, OUT]\nTitulação: ");
                        scanf("%s", titulacao);
                
                        if (strcmp(titulacao, "GRD") == 0|| strcmp(titulacao, "grd") == 0){
                            strcpy(pg[cont].titulacao, "GRD");
                            break;
                        } else if(strcmp(titulacao, "MST") == 0 || strcmp(titulacao, "mst") == 0){
                            strcpy(pg[cont].titulacao, "MST");
                            break;
                        } 
                        else if(strcmp(titulacao, "DOU") == 0 || strcmp(titulacao, "dou") == 0){
                            strcpy(pg[cont].titulacao, "DOU");
                            break;
                        } 
                        else if(strcmp(titulacao, "POS") == 0 || strcmp(titulacao, "pos") == 0){
                            strcpy(pg[cont].titulacao, "POS");
                            break;
                        } 
                        else if(strcmp(titulacao, "OUT") == 0 || strcmp(titulacao, "out") == 0){
                            strcpy(pg[cont].titulacao, "OUT");
                            break;
                        } else
                            printf("\nPor favor, digite uma titlação válida \n");
                
                    }
                    break;
                case 3:
                    while(1){
                        printf("Sexo: ");
                        scanf("%s", sexo);
                        if (strcmp(sexo, "m") == 0|| strcmp(sexo, "M") == 0){
                            strcpy(pg[cont].sexo, "M");
                            // pg[cont].sexo = sexo;
                            break;
                        } else if(strcmp(sexo, "f") == 0 || strcmp(sexo, "F") == 0){
                            strcpy(pg[cont].sexo, "F");
                            break;
                        } else
                            printf("\nPor favor, digite um valor entre [M, F]\n");
                    }
                    break;
                case 4:
                    printf("Departamento: ");
                    scanf("%s", pg[p].departamento);
                    break;
                //printf("Salário: ");
                //scanf("%d", &pg.salario);
                }
            pausa();
            }
        }
    }
}


mostralistafinal(){
    int c;
    int m_mst = 0, m_dou = 0, f_mst = 0, f_dou = 0;
    limpartela(); 
    printf("===================================\n");
    printf("            LISTA FINAL\n");
    printf("===================================\n");
    
    for(c=0; c<=cont; ++c){
        if(strcmp(pg[c].sexo, "M") == 0){
            if(strcmp(pg[c].titulacao, "MST") == 0)
                m_mst++;
            if(strcmp(pg[c].titulacao, "DOU") == 0)
                m_dou++;
        }else if(strcmp(pg[c].sexo, "F") == 0){
            if(strcmp(pg[c].titulacao, "MST") == 0)
                f_mst++;
            if(strcmp(pg[c].titulacao, "DOU") == 0)
                f_dou++;
        }
    }
    
    printf("\nTITU\tMAS\tFEM\n");
    printf("DOU\t%d\t%d\n", m_dou, f_dou);
    printf("MST\t%d\t%d\n", m_mst, f_mst);
    
    // TITU    MAS     FEM
    // DOU     12      5
    // MEST    10      2
    // TOTAL   22      7
    pausa();
}



int main(){     // FUNÇÃO PRINCIPAL - MOSTRA O MENU 
    
    setlocale(LC_ALL, "Portuguese_Brasil");
    int num = 0;
    strcpy(pg[0].codigo, "001");
    strcpy(pg[0].nome, "João Batista");
    strcpy(pg[0].titulacao, "DOU");
    strcpy(pg[0].departamento, "DCC");
    strcpy(pg[0].sexo, "M");
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
        " 6 - MOSTRAR LISTA FINAL\n"
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
            case 4:
                modificacaototal();
                break;
            case 5:
                modificacaoparcial();
                break;
            case 6:
                mostralistafinal();
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


