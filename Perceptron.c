#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

float treinamento[30][5];
float pesos[4];
float amostra[4];

void carregarDadosDoTreinamento();
void randomizarPesos();
void treinamentoDaRede();
void operacaoPerceptron();

int main(int argc, char** argv){
	
	int i, j=1, escolha;
	
	printf(" ---------------------------------------\n");
	printf("|Redes Neurais Artificiais - Percepetron|\n");
	printf(" ---------------------------------------\n\n");
	printf("-> Voce deseja treinar a rede ou digitar seus pesos particulares? 1 - Treinamento | 2 - Operacao | 0 - Sair\n");
	printf("-> ");
	scanf("%d", &escolha);
	printf("\n\n");
	
	while(escolha==1||escolha==2){
		switch(escolha){
		case 1:{
			do{
			printf("-> Pressione enter para dar inicio ao carregamento do conjunto de treinamento\n\n");
			system("pause");
			carregarDadosDoTreinamento();
			randomizarPesos();
			treinamentoDaRede();
			printf("\n-> Voce executou %d treinamento(s)\n", j);
			printf("-> Voce deseja fazer outro treinamento da rede? 1 - Sim | 0 - nao\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			j++;
		    }while(i==1);
		    printf("-> Voce deseja ir para a operacao do Perceptron? 1 - Sim | 0 - Nao\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			if(i==1){
				operacaoPerceptron(1);
			    break;
			}else{
				 break;
			}
		}
		case 2:{
			do{
			operacaoPerceptron(2);
			printf("-> Voce deseja apresentar outro conjunto de pesos e amostras pessoais?? 1 - Sim | 0 - Nao\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
			}while(i==1);
			break;
		}
		}
		printf("-> Voce tem o valor dos pesos ou deseja treinar a rede? 1 - Treinamento | 2 - Operacao | 0 - Sair\n");
		printf("-> ");
		scanf("%d", &escolha);
		printf("\n\n");
	}
	
	printf("-> Esperamos que tenha gostado da nossa implementacao do Perceptron. Obrigado!\n");
	
	return 0;
}

void operacaoPerceptron(int escolha){
	
	int j, i;
	float saida;
	
	if(escolha!=1){
		for(j = 0; j < 4; j++){
			if(j==0){
				printf("-> Digite o valor do limiar de ativacao\n");
				printf("-> ");
				scanf("%f", &pesos[j]);
			}else{
				printf("-> Digite o valor do peso x%d\n", j);
				printf("-> ");
				scanf("%f", &pesos[j]);
			}
			
		}
		printf("\n");
	}
	
	printf("-> Vamos iniciar a digitacao das entradas. ");
	system("pause");
	printf("\n\n");
	do{	
		float somatorio = 0;
			
		for(j=0; j<4; j++){
		
		   	if(j==0){
  			amostra[j] = -1.0000;
		}else{
			printf("->Digite o valor da entrada x%d\n", j);
			printf("-> ");
			scanf("%f", &amostra[j]);
		}
	   	somatorio += pesos[j]*amostra[j];
	    }
	    
  		
		printf("\n");
		printf("-> Somatorio = %.4f\n\n", somatorio);	
			
			
		if(somatorio>=0){
			saida = 1.0000;
			printf("-> Somatorio maior ou igual a 0, saida = %.4f\n\n", saida);
			system("pause");
		}else{
			saida = -1.0000;
			printf("-> Somatorio menor que 0, saida = %.4f\n\n", saida);
			system("pause");
		}
		
		printf("\n-> Voce deseja apresentar outro conjunto de amostras?? 1 - Sim | 0 - nao\n");
			printf("-> ");
			scanf("%d", &i);
			printf("\n\n");
	}while(i==1);
	
}

void treinamentoDaRede(){
	
	float tDA = 0.01, somatorio, saida;
	int nE = 0, i = 0, j;
	int erro;
	
	do{
		
		erro = 0;
		
		for(i = 0; i<30; i++){
			
			somatorio = 0;
			
			for(j=0; j<4; j++){
				somatorio += pesos[j]*treinamento[i][j];
			}
			
			if(somatorio>=0){
				saida = 1.0000;
			}else{
				saida = -1.0000;
			}
			
			if(saida != treinamento[i][4]){
				
				for(j = 0 ; j<4; j++){
					pesos[j] = pesos[j] + (tDA * (treinamento[i][4] - saida) * treinamento[i][j]);
				}
				
				erro = 1;
				
			}
			
		}
		
		nE = nE+1;			
		
	}while(erro != 0);
	
	printf("\n      Pesos atualizados      \n");
	
	printf(" ----------------------------\n");
	for(i=0; i<4; i++){
		if(i==0){
			printf("|Limiar de ativacao = %.4f|\n", pesos[i]);
		}else{
			if(pesos[i]<0){
				printf("|Peso da entrada x%d = %.4f|\n", i, pesos[i]);
			}else{
				printf("|Peso da entrada x%d = %.4f |\n", i, pesos[i]);
			}
		}
	}
	
	printf(" ----------------------------\n\n");
	
	printf("\n-> Treinamento finalizado com sucesso!\n");
	printf("-> Numero de epocas de treinamento contabilizadas = %d\n\n", nE);
	
	system("pause");
	
}


void randomizarPesos(){
	
	int i=0;
	
	srand((unsigned)time(NULL));
	
	printf("\n");
	
	printf("                Randomizacao dos pesos               \n");
	
	printf(" ----------------------------------------------------\n");
	
	do{
		
		pesos[i] = rand()%100001;
		
		pesos[i] = pesos[i]/100000;
		
		if(i == 0){
			printf("|Limiar de ativacao randomicamente escolhido = %.4f|\n", pesos[i]);
		}else{
			printf("|Peso da entrada x%d randomicamente escolhido = %.4f|\n", i, pesos[i]);
		}
		
		i++;
		
	}while(i<4);
	
	printf(" ----------------------------------------------------\n\n");
	
	printf("-> Pesos randomizados com sucesso!\n");
	printf("-> Pressione enter para dar inicio ao treinamento da rede\n\n");
	
	system("pause");
	
	return;
	
}

void carregarDadosDoTreinamento(){
	
	char url[]="Nome do arquivo para carregar o conjunto de treinamento.txt";
	
	int i = 0;
	
	FILE *arq;
	
	arq = fopen(url, "r");
	if(arq == NULL)
		printf("NAO FOI POSSIVEL ABRIR O ARQUIVO");
	else{
			printf("\n-- Conjunto de treinamento carregado do arquivo --\n\n");
			printf("Obs: Entrada x0 corresponde ao peso w0 (limiar de ativacao), logo, por convencao, sempre sera -1\n\n");
			while(((fscanf(arq,"%f %f %f %f\n", &treinamento[i][1], &treinamento[i][2], &treinamento[i][3], &treinamento[i][4]))!=EOF)&&i<31){
				treinamento[i][0] = -1.0000;
				printf("x0 = %.4f, x1 = %.4f, x2 = %.4f, x3 = %.4f, d = %.4f\n", treinamento[i][0], treinamento[i][1], treinamento[i][2], treinamento[i][3], treinamento[i][4]);
				i++;	
	  	    }
			printf("\n\n");	
	}
	
	fclose(arq);
	
	printf("-> Dados carregados do arquivo com sucesso!\n");
	printf("-> Pressione enter para dar inicio a randomizacao dos pesos\n\n");
	
	system("pause");
	
	return;
	
}