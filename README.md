# Trabalho Final - AEDs 1

Este repositório contém o código do trabalho final da disciplina **Algoritmos e Estruturas de Dados 1**, do primeiro período do curso de Engenharia de Sistemas. O programa desenvolvido realiza o cadastro de professores, solicitando as seguintes informações:

- **Código** (ex.: 001, 002, 024)
- **Nome do professor**
- **Titulação** (ESP, MST, DOU, POS)
- **Sexo** (M, F)
- **Salário**
- **Departamento** (DCC, DEX, DCA, DLT, DEC, ...)

## Funcionalidades

Ao executar o programa, o seguinte menu é apresentado, com validação de entrada para cada opção:

1. **Inclusão de Dados**  
2. **Listagem Geral de Dados**  
3. **Listagem Parcial de Dados**  
4. **Modificação Total de Dados**  
5. **Modificação Parcial de Dados**  
6. **Mostrar Lista Final**  
99. **Encerrar Programa**  

O usuário seleciona a opção desejada e é encaminhado para a função correspondente.

## Como Executar

### Executando Online
Você pode copiar e colar o código no compilador online, como o [OnlineGDB](https://www.onlinegdb.com/online_c_compiler). Nesse ambiente, nenhuma alteração no código é necessária para execução.

### Executando Localmente
Caso prefira compilar e executar o programa em um dispositivo local:

#### Ambiente Windows
É necessário modificar a função `limpartela` para usar o comando `system("cls");`. Localize o trecho de código correspondente (por padrão, na linha 37) e ajuste da seguinte forma:

```c
void limpartela() {
    system("cls"); // Se estiver em ambiente Windows
    //system("clear"); // Se estiver em ambiente Linux
}
```
#### Ambiente Linux
Se estiver utilizando Linux, mantenha a configuração padrão:

```c
void limpartela() {
    //system("cls"); // Se estiver em ambiente Windows
    system("clear"); // Se estiver em ambiente Linux
}
```
## Demonstração Menu
```c
===================================
          SELECIONAR OPÇÃO
===================================
 1 - INCLUSÃO DE DADOS
 2 - LISTAGEM GERAL DE DADOS
 3 - LISTAGEM PARCIAL DE DADOS
 4 - MODIFICAÇÃO TOTAL DE DADOS
 5 - MODIFICAÇÃO PARCIAL DE DADOS
 6 - MOSTRAR LISTA FINAL
99 - ENCERRAR PROGRAMA
===================================
Sua Opção:
```

## Contribuição
Se encontrar algum problema ou tiver sugestões de melhoria, fique à vontade para abrir uma issue ou enviar um pull request.
