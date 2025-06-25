#include <stdio.h>
#include <string.h>
int main(){
//variaveis 
//parte 1 
float valoresVenda[4];
char nomesCli[4][30];
char sexosCli[4];
char codsPed[4];
//parte 2 
int escolha = 0;
char continuar;
//parte 3 
int comparacao = 0;
char nomeCli[30];
float somaCompras = 0;
//parte 4 
float valorAbaixo = 0;
int qtdPedidosAbaixo = 0;
int qtdEntre20E40 = 0;
int qtdSexoN = 0;
float somaCompraHomens = 0;
float valorMedio = 0;
float pedidoMaisBarato = 0;
int qtdCodCOuD = 0;
int qtdCodA = 0;
int qtdCodB = 0;
int qtdCodC = 0;
int qtdCodD = 0;
int qtdCodE = 0;
char codMaisPedido;
//---------------------
//logica em si 
/*-------------Parte 1-----------------------------------*/
    printf("\n\n-----------------Cadastro de compras----------------\n\n");
    for (int i = 0; i < 4; i++){
        printf("Pedido %d: \n",i+1);
        printf("\nValor da venda : ");
        scanf("%f",&valoresVenda[i]);
            if (valoresVenda[i] < 0){
                printf("Valor invalido inserido (Numero negativo).\n\nInsira novamente o ");
i--; /*volta pro 1 pedido atrás pra poder colocar de novo*/
                continue; /*termina essa iteração do for e vai pra próxima, que é com o i--, retornando 
ao pedido que foi digitado errado*/
            }
                printf("\nNome do cliente : ");
                scanf("%s",nomesCli[i]);
                printf("\nSexo do cliente (F, M ou N): ");
                scanf(" %c",&sexosCli[i]);
                switch(sexosCli[i]){
                    case 'F':
                    case 'M': /*caso seja F M ou N, tudo segue normal,*/
                    case 'N': /*caso contrario o default faz voltar pro inicio do pedido que tá sendo 
                    cadastrado*/
                        break;
                    default:
                        printf("Sexo invalido inserido (diferente de F, M ou N).\n\nInsira novamente o ");
                        i--;
                    continue;
                }
        printf("\nCodigo do pedido (A, B, C, D ou E): ");
        scanf(" %c",&codsPed[i]);
        switch(codsPed[i]){
            case 'A': /*Registrando o Código do pedido no vetor.*/
                qtdCodA++;break; /*Adicionando a variável de Quantidade para poder ter a 
                informação de quem foi o mais pedido.*/
            case 'B':
                qtdCodB++;break;
            case 'C':
                qtdCodC++;break;
            case 'D':
                qtdCodD++;break;
            case 'E':
                qtdCodE++;break;
            default:
                printf("Codigo invalido inserido (diferente de A, B, C, D ou E).\n\nInsira novamente o ");
                i--;
            continue;
    }
        printf("\n");
    }
    printf("\n\n-----------------Cadastro realizado com sucesso!----------------\n\n");
/*-------------Parte 2-----------------------------------*/
    do{
        printf("\n\n----------------Menu----------------\n\n");
        printf("Escolha:");
        printf("\n1 - Ver informacoes de compra especifica");
        printf("\n2 - Ver informacoes de todas as compras\nR:");
        scanf("%d", &escolha);
        switch (escolha){
/*-------------Parte 3-----------------------------------*/
            case 1:
                printf("\n\n-----------------Ver informacoes de compra especifica----------------\n\n");
                printf("Nome do Cliente: ");
                scanf("%s", nomeCli);
                    for (int i = 0; i < 4; i++){
                        comparacao = strcmp(nomesCli[i], nomeCli); /*comparando dentro do for pra toda 
                        vez que o for mudar o i,*/
                        /*a comparaçao mudar pra ser de acordo com o nome que 
                        quero comparar*/
                        if(comparacao == 0){
                            somaCompras += valoresVenda[i];
                            printf("\n\nPedido %d", i+1);
                            printf("\n\nNome: %s", nomesCli[i]);
                            printf("\nValor da compra: %.2f", valoresVenda[i]);
                            printf("\nCodigo da compra: %c", codsPed[i]);
                            printf("\n\n----------------------------------------");
                        }
                    }
            if (somaCompras > 0) /*se tiver compras a soma nunca vai ser 0 entao a gente pode 
            mostrar a soma*/
            {
                printf("\n\nValor somado das compras de %s: %.2f",nomeCli, somaCompras);
                somaCompras = 0;
            }
            else{ /*se a soma continuar 0 igual quando foi declarada significa que o cliente não 
            teve compras*/
                printf("\n\nNao ha compras para o cliente de nome %s",nomeCli);
            }
                printf("\n\nvoltar pro menu?(S ou N)\nR: ");
                scanf(" %c",&continuar);
            break;
/*-------------Parte 4-----------------------------------*/
            case 2:
                printf("\n\n-----------------Ver informacoes de todas as compras----------------\n\n");
                printf("\nValor: ");
                scanf("%f", &valorAbaixo);
                    for (int i = 0; i < 4; i++) /*Iterando pelo vetor e aplicando cada condição para ser 
                    exibida posteriormente.*/
                    {
                        if (valoresVenda[i] < valorAbaixo){
                            qtdPedidosAbaixo++;
                        }
                        if(valoresVenda[i] >= 20 && valoresVenda[i] <= 40){
                            qtdEntre20E40++;
                        }
                        if (sexosCli[i] == 'N')
                        {
                            qtdSexoN++;
                        }
                        if(sexosCli[i] == 'M'){
                            somaCompraHomens = somaCompraHomens + valoresVenda[i];
                        }
                            somaCompras = somaCompras + valoresVenda[i];
                        if(valoresVenda[i] < pedidoMaisBarato || i == 0){
                            pedidoMaisBarato = valoresVenda[i];
                        }
                        if (codsPed[i] == 'C' || codsPed[i] == 'D'){
                            qtdCodCOuD++;
                        }
                        /*Algorítimo para saber qual o codigo mais pedido*/
                        if(qtdCodA >= qtdCodB && qtdCodA >= qtdCodC && qtdCodA >= qtdCodD &&
                            qtdCodA >= qtdCodE)
                        {
                            codMaisPedido = 'A';
                        }else if(qtdCodB >= qtdCodA && qtdCodB >= qtdCodC && qtdCodB >= qtdCodD
                        && qtdCodB >= qtdCodE)
                        {
                            codMaisPedido = 'B';
                        }else if(qtdCodC >= qtdCodA && qtdCodC >= qtdCodB && qtdCodC >= qtdCodD &&
                        qtdCodC >= qtdCodE)
                        {
                            codMaisPedido = 'C';
                        }else if(qtdCodD >= qtdCodA && qtdCodD >= qtdCodB && qtdCodD >= qtdCodC &&
                        qtdCodD >= qtdCodE)
                        {
                            codMaisPedido = 'D';
                        }else if(qtdCodE >= qtdCodA && qtdCodE >= qtdCodB && qtdCodE >= qtdCodC &&
                        qtdCodE >= qtdCodD)
                        {
                            codMaisPedido = 'E';
                        }
                    }
            valorMedio = somaCompras / 4;
            printf("\n\n-------------Quantidade de Pedidos Abaixo deste Valor-------------");
            printf("\nQuantidade: %i", qtdPedidosAbaixo);
            printf("\n\n-------------Quantidade de Pedidos entre 20 e 40------------------");
            printf("\nQuantidade: %i", qtdEntre20E40);
            printf("\n\n-------------Quantidade de Cliente do Sexo N----------------------");
            printf("\nQuantidade: %i", qtdSexoN);
            printf("\n\n-------------Valor total comprado pelos homens--------------------");
            printf("\nValor: R$%.2f", somaCompraHomens);
            printf("\n\n-------------Valor medio entre os Pedidos-------------------------");
            printf("\nValor: R$%.2f", valorMedio);
            printf("\n\n-------------Valor do pedido mais Barato--------------------------");
            printf("\nValor: R$%.2f", pedidoMaisBarato);
            printf("\n\n-------------Quantidade de vendas com o codigo C ou D---------");
            printf("\nQuantidade: %i", qtdCodCOuD);
            printf("\n\n-------------Codigo mais vendido--------------------------");
            printf("\ncodigo: %c", codMaisPedido);
                somaCompras = 0;
            printf("\n\nvoltar pro menu?(S ou N)\nR: ");
            scanf(" %c",&continuar);
        }
    }while (continuar == 'S');
    printf("\n-----------------Programa finalizado!-----------------");
return 0;
}