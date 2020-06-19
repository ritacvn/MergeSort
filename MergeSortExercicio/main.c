//
//  main.c
//  MergeSortExercicio
//
//  Created by Rita de Cassia Vasconcelos do Nascimento on 19/06/20.
//  Copyright © 2020 Rita de Cassia Vasconcelos do Nascimento. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {
  int cpf, idade;
  char telefone, nome, sexo;
}funcionario;

funcionario funcionarios[5];

void exibeLista(void);
void insereDados(void);
void merge(funcionario *funcionarios, int inicio, int meio, int fim);
void mergeSort(funcionario funcionarios[], int inicio, int fim);
int i;

int main() {
  int opcao;
 do {
  printf("Insira o código que deseja: \n");
  printf(" 1- Inserir dados; \n 2- Exibir dados; \n 3- Merge Sort; \n 4- Finalizar o programa; \n ");
  scanf("%d",&opcao);
  switch (opcao) {
    case 1:
      insereDados();
      break;
    case 2:
      exibeLista();
      break;
    case 3:
      printf("Funcionários ordenados por usas respectivas idades com merge sort: \n");
      mergeSort(funcionarios, 0, 4);
      for(i=0;i<=4;i++) {
           printf("\n");
           printf("Cpf: %d \n", funcionarios[i].cpf);
           printf("Nome: %c \n", funcionarios[i].nome);
           printf("Telefone: %c \n", funcionarios[i].telefone);
           printf("Sexo: %c \n", funcionarios[i].sexo);
           printf("Idade: %d \n", funcionarios[i].idade);
          printf("\n");
         }
      break;
    case 4:
      printf("Programa finalizado!");
    default:
      break;
  }
 } while (opcao != 4);
  return 0;
}

void insereDados() {
  for(i=0; i<=4; i++) {
    printf("Cpf: \n");
    scanf("%d", &funcionarios[i].cpf);
    printf("Nome: \n");
    scanf("%s", &funcionarios[i].nome);
    printf("Telefone: \n");
    scanf("%s", &funcionarios[i].telefone);
    printf("Sexo: M para masculino e F para feminino: \n");
    scanf("%s", &funcionarios[i].sexo);
    printf("Idade: \n");
    scanf("%d", &funcionarios[i].idade);
  }
}

void exibeLista() {
  for (i=0; i<=4; i++) {
    printf("\n");
    printf("Cpf: %d \n", funcionarios[i].cpf);
    printf("Nome: %c \n", funcionarios[i].nome);
    printf("Telefone: %c \n", funcionarios[i].telefone);
    printf("Sexo: %c \n", funcionarios[i].sexo);
    printf("Idade: %d \n", funcionarios[i].idade);
    printf("\n");
  }
}

void merge(funcionario *funcionarios, int inicio, int meio, int fim) {
    int ini1 = inicio, ini2 = meio+1, comAux = 0, tam = fim-inicio+1;
     int *vetAux;
     vetAux = (int*)malloc(tam * sizeof(int));
   
     while(ini1 <= meio && ini2 <= fim) {
       if(funcionarios[ini1].idade < funcionarios[ini2].idade) {
         vetAux[comAux] = funcionarios[ini1].idade;
         ini1++;
       } else {
         vetAux[comAux] = funcionarios[ini2].idade;
         ini2++;
       }
       comAux++;
     }
   
     while(ini1 <= meio) {
       vetAux[comAux] = funcionarios[ini1].idade;
       comAux++;
       ini1++;
     }
   
     while(ini2 <= fim) {
       vetAux[comAux] = funcionarios[ini2].idade;
       comAux++;
       ini2++;
     }
   
     for(comAux = inicio; comAux <= fim; comAux++) {
       funcionarios[comAux].idade = vetAux[comAux-inicio];
     }
   
     free(vetAux);
}

void mergeSort(funcionario funcionarios[], int inicio, int fim) {
  if (inicio < fim) {
    int meio = (fim+inicio)/2;

    mergeSort(funcionarios, inicio, meio);
    mergeSort(funcionarios, meio+1, fim);
    merge(funcionarios, inicio, meio, fim);
    
  }
}

