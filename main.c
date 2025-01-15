#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
char nome[100];
char sexo;
int idade;
};
typedef struct cliente cliente;
struct venda{
int itens;
int sabores;
float valor;
cliente cliente;
};
typedef struct venda venda;

void arquivar(FILE *arq, venda vendasalva);
int vendasArquivadas(venda **vendas, int *total);

int main(void) {
  
  int a = 0;
  int qtd = 0;
  venda *vendas = NULL;
  int total = 0;
  int g = 0;
  int resposta = 0;
  FILE *arq;

  vendasArquivadas(&vendas, &total);

  printf("            SORVETERIA ICEBOX\n");
  do{
    do{ 
    printf("\n            ----- MENU -----\n\n");
    printf("1 - Cadastrar novas vendas\n");
    printf("2 - Ver informações da venda baseada no nome do cliente\n");
    printf("3 - Ver informações de todas vendas\n");
    printf("4 - Encerrar o programa\n");
    printf("\nQual opção deseja: ");
    scanf("%d", &a);
      if(a != 1 && a != 2 && a != 3 && a != 4){
        printf("\nOpção inválida\n");
      }
    }while(a != 1 && a != 2 && a != 3 && a != 4);

    if(a == 1){
      arq = fopen("registros.txt", "a");
      if(arq == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
      }
      do{
        do{
          printf("Quantas vendas deseja cadastrar: ");
          scanf("%d", &qtd);
          if(qtd < 0){
            printf("Inválido. Insira um valor positivo\n");
          }
        }while(qtd < 0);
        if(vendas == NULL){
          vendas = (venda *)malloc(qtd * sizeof(venda));
          g = qtd;
        }else if(total + qtd > g){
          g = total + qtd;
          vendas = (venda *)realloc(vendas, g * sizeof(venda));
        }
        if(vendas == NULL){
          printf("Erro ao alocar memória");
          return 1;
        }
        for(int i = 0; i < qtd; i++){
          printf("\n[Cadastro do cliente]\n\n");
          getchar();
          do{
            printf("Cadastro %02d\n", total + i + 1);
            printf("Nome: ");
            fgets(vendas[total + i].cliente.nome, 100, stdin);
            vendas[total + i].cliente.nome[strcspn(vendas[total + i].cliente.nome, "\n")] = '\0';
            if(strlen(vendas[total + i].cliente.nome) < 3){
              printf("Inválido. Por favor insira um nome com 3 ou mais letras.\n");
            }
          }while(strlen(vendas[total + i].cliente.nome) < 3);
          do{
            printf("Sexo(m/f/n): ");
            scanf(" %c", &vendas[total + i].cliente.sexo);
            if(vendas[total + i].cliente.sexo != 'm' && vendas[total + i].cliente.sexo != 'f' && vendas[total + i].cliente.sexo != 'n' && vendas[total + i].cliente.sexo!= 'M' && vendas[total + i].cliente.sexo != 'F' && vendas[total + i].cliente.sexo != 'N'){
                printf("Sexo inválido. Por favor insira m/f/n\n");
              }
            }while(vendas[total + i].cliente.sexo != 'm' && vendas[total + i].cliente.sexo != 'f' && vendas[total + i].cliente.sexo != 'n' && vendas[total + i].cliente.sexo!= 'M' && vendas[total + i].cliente.sexo != 'F' && vendas[total + i].cliente.sexo != 'N');
          do{
            printf("Idade: ");
            scanf("%d", &vendas[total + i].cliente.idade);
            if(vendas[total + i].cliente.idade <= 0){
              printf("Idade inválida. Por favor insira uma idade maior que 0.\n");
            }
          }while(vendas[total + i].cliente.idade <= 0);
          do{
            printf("Quantidade de itens comprados: ");
            scanf("%d", &vendas[total + i].itens);
            if(vendas[total + i].itens <= 0){
              printf("Quantidade inválida. Por favor informe uma quantidade positiva.\n");
            }
          }while(vendas[total + i].itens <= 0);
          do{
            printf("Quantidade de sabores: ");
            scanf("%d", &vendas[total + i].sabores);
            if(vendas[total + i].sabores <= 0){
              printf("Quantidade inválida. Por favor informe uma quantidade positiva.\n");
            }
          }while(vendas[total + i].sabores <= 0);
          do{
            printf("Valor total: R$");
            scanf("%f", &vendas[total + i].valor);
            if(vendas[total + i].valor < 0){
              printf("Valor inválido. Por favor informe um valor positivo.\n");
            }
          }while(vendas[total + i].valor < 0);
          arquivar(arq, vendas[total + i]);
        }
        total += qtd;
        printf("\nCadastro realizado com sucesso!\n\n");
        printf("Digite 1 para cadastrar mais vendas.\nDigite 2 para retornar ao menu.\n:");
        scanf("%d", &resposta);
      }while(resposta == 1);
    }else if(a == 2){
      char nomecliente[100];
      int resposta2 = 0;

      do{
        int c = 0;
        float b = 0;
        float soma = 0;
        float media = 0;
        printf("Digite o nome do cliente que deseja procurar: ");
        getchar();
        fgets(nomecliente, 100, stdin);
        nomecliente[strcspn(nomecliente, "\n")] = '\0';
        for(int i = 0; i < total; i++){
          if(strcmp(nomecliente, vendas[i].cliente.nome) == 0){
            printf("\nCliente: %s", nomecliente);
            printf("\nQuantidade de itens: %d", vendas[i].itens);
            printf("\nQuantidade de sabores: %d", vendas[i].sabores);
            printf("\nValor total: R$%.2f\n", vendas[i].valor);
            soma += vendas[i].valor;
            b++;
            c = 1;
          }
        }
        if(c == 0){
          printf("\nNão há compras realizadas nesse nome.\n");
        }
        if(c == 1){
          media = soma / b;
          printf("\nMédia de valor das compras: R$%.2f\n", media);
        }
        printf("\nDigite 1 para pesquisar novamente.\nDigite 2 para retornar ao menu.\n:");
        scanf("%d", &resposta2);
      }while(resposta2 == 1);
    }else if(a == 3){
      arq = fopen("registros.txt", "r");
      float abaixo = 0;
      int qtdabaixo = 0;
      int umitem = 0;
      int saborpar = 0;
      int qtdmulher = 0;
      float valorhomem = 0;
      int totalitem = 0;
      int totalsabores = 0;
      float valortotal = 0;
      float valormedio = 0;
      char maiornome[100];

      printf("\nDigite um valor para exibir a quantidade de vendas abaixo deste valor: R$");
      scanf("%f", &abaixo);

      for(int i = 0; i < total; i++){
        if(vendas[i].valor < abaixo){
          qtdabaixo++;
        }
        if(vendas[i].itens == 1){
          umitem++;
        }
        if(vendas[i].sabores %2 == 0){
          saborpar++;
         }
        if(vendas[i].cliente.sexo == 'f'){
          qtdmulher++;
        }
        if(vendas[i].cliente.sexo == 'm'){
          valorhomem += vendas[i].valor;
        }
        totalitem += vendas[i].itens;
        totalsabores += vendas[i].sabores;
        valortotal += vendas[i].valor;
      }
      valormedio = valortotal / total;

      printf("\nQuantidade de vendas abaixo do valor R$%.2f = %d", abaixo, qtdabaixo);
      printf("\nQuantidade de vendas com 1 item vendido = %d", umitem);
      printf("\nQuantidade de vendas com número par de sabores = %d", saborpar);
      printf("\nQuantidade de clientes mulheres = %d", qtdmulher);
      printf("\nValor total comprado pelos homens = R$%.2f", valorhomem);
      printf("\nQuantidade total de itens vendidos = %d", totalitem);
      printf("\nQuantidade total de sabores vendidos = %d", totalsabores);
      printf("\nValor total da compra = R$%.2f", valortotal);
      printf("\nValor médio da compra = R$%.2f\n", valormedio);

      int maior = 0;
      for(int i = 0; i < total; i++){
        if(strlen(vendas[i].cliente.nome) > maior){
          maior = strlen(vendas[i].cliente.nome);
          strcpy(maiornome, vendas[i].cliente.nome);
        }
      }
      for(int i = 0; i < total; i++){
        if(strcmp(vendas[i].cliente.nome, maiornome) == 0){
          printf("\nInformações do cliente com maior nome:\n");
          printf("\nVenda 0%d %s\n", i+1, maiornome);
          printf("Quantidade de itens: %d\n", vendas[i].itens);
          printf("Quantidade de sabores: %d\n", vendas[i].sabores);
          printf("Valor total: R$%.2f\n", vendas[i].valor);
        }
      }
      char novonome[100];
      int menor = 0;
      for(int i = 0; i < total; i++){
        if(vendas[i].cliente.idade < menor || menor == 0){
          menor = vendas[i].cliente.idade;
          strcpy(novonome, vendas[i].cliente.nome);
        }
      }
      for(int i = 0; i < total; i++){
        if(strcmp(vendas[i].cliente.nome, novonome) == 0){
          printf("\nInformações do cliente mais novo:\n");
          printf("\nVenda 0%d %s\n", i+1, novonome);
          printf("Quantidade de itens: %d\n", vendas[i].itens);
          printf("Quantidade de sabores: %d\n", vendas[i].sabores);
          printf("Valor total: R$%.2f\n", vendas[i].valor);
        }
      }
      char opcao;
      printf("\n\nDeseja retornar para o menu principal(s/n): ");
      scanf(" %c", &opcao);
      switch(opcao){
        case 'n':
        printf("\n*** Programa Encerrado ***\n");
        exit(0);
      }
    }
  }while(a != 4);
  free(vendas);
  return 0;
}

void arquivar(FILE *arq, venda vendasalva){
  fprintf(arq, "%s\n %c\n %d\n %d\n %d\n %.2f\n", vendasalva.cliente.nome, vendasalva.cliente.sexo, vendasalva.cliente.idade, vendasalva.itens, vendasalva.sabores, vendasalva.valor);
}

int vendasArquivadas(venda **vendas, int *total){
  int qtd = 0;
  FILE *arq = fopen("registros.txt", "r");
  if(arq == NULL){
    return 0;
  }
  while(!feof(arq)){
    venda vendas0;
    if(fscanf(arq, " %[^\n]\n %c\n %d\n %d\n %d\n %f\n", vendas0.cliente.nome, &vendas0.cliente.sexo, &vendas0.cliente.idade, &vendas0.itens, &vendas0.sabores, &vendas0.valor) == 6){
      (*vendas) = realloc(*vendas, (qtd + 1) * sizeof(venda));
      (*vendas)[qtd] = vendas0;
      qtd++;
    }
  }
  fclose(arq);
  *total = qtd;
  return qtd;
}
