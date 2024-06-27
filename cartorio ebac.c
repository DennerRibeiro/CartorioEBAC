#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região (Idioma)
#include <string.h> //Biblioteca responsável pelas strings

//Variáveis globais
int opcao=0; 
int repeticao=0;
int menu=0;
int sair=0;
int escolha=0;
int erro=0;


int loop() //Função para retorno ao menu ou fechamento de qualquer local do programa
{
	scanf("%i", &opcao);
		
	switch (opcao)
	{
		case 1:
		repeticao=1; //Repete a última ação realizada
		break;
				
		case 2:
		menu=1; //Retorna ao menu principal
		break;
				
		case 3:
		sair=1; //Encerra o programa
		break;
				
		default: //Mensagem de erro caso outro caractere seja digitado além dos descritos acima
		system("cls");
		printf("\n\tOpção escolhida não existente!!!\n");
		printf("\n\tPor favor, escolha uma opção disponível no menu!!!\n\n");
		system("pause");
		erro=1;
		break;	
	}
}

int registro()  //Função registrar novos usuários
{
	
	do 
	{
		repeticao=0;
	
		system("cls");
	
		printf("\n\tInclusão de usuários\n\n");
	
		char arquivo[50];
		char cpf[50];
		char nome[50];
		char sobrenome[50];
		char cargo[50];
	
		printf(" Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
	
		strcpy(arquivo, cpf); //Copia valor das strings
	

		FILE *file; //Comando existente da biblioteca para criar um arquivo
		file = fopen(arquivo, "W"); //Define o que fazer com o arquivo, no caso criar um novo
		fclose(file); //Fecha o arquivo
	
		file = fopen(arquivo, "r");
		fscanf(file, cpf);
		
		if (file != NULL)
		{
			printf("\n\tUsuário já cadastrado!\n\n");
			system("pause");
		}
		
		if (file == NULL)
		{
			file = fopen(arquivo, "a");
			fprintf(file, "CPF: ");
			fclose(file);
		
			file = fopen(arquivo, "a");
			fprintf(file, cpf);
			fclose(file);
		
			file = fopen(arquivo, "a"); //Atualizar arquivo criado
			fprintf(file, " - "); //, Para separar as informações
			fclose(file);
			
			printf(" Digite o nome a ser cadastrado: ");
			scanf("%s", nome);
			
			file = fopen(arquivo, "a");
			fprintf(file, "Nome: ");
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, nome);
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, " ");
			fclose(file);
			
			printf(" Digite o sobrenome: ");
			scanf("%s", sobrenome);
			
			file = fopen(arquivo, "a");
			fprintf(file, sobrenome);
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, " - ");
			fclose(file);
			
			printf(" Digite o cargo: ");
			scanf("%s", cargo);
			
			file = fopen(arquivo, "a");
			fprintf(file, "Cargo: ");
			fclose(file);
			
			file = fopen(arquivo, "a");
			fprintf(file, cargo);
			fclose(file);
			
			printf("\n\tRegistro concluído com sucesso!\n\n");
			
			system("pause");
		}
		do
		{
			erro=0;
	
			system("cls");
			printf("\n\tO que deseja?\n\n");	
			printf("\t1 - Registrar outro CPF\n");
			printf("\t2 - Retornar ao Menu\n");
			printf("\t3 - Fechar aplicação\n");
			printf("\n\n Opção: ");
			
			loop();
	
		}
		while (erro==1);
		
	}
	while (repeticao==1);

}
	


int consultar() // Consultar CPF de usuários
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		repeticao=0;
		system("cls");
		printf("\n\tConsulta de usuários\n");
		
		char cpf[50];
		char conteudo[200];
		
		printf("\n Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); //Ler o arquivo CPF
		
		if(file == NULL)
		{
			system("cls");
			printf("\n\tUsuário não localizado!\n\n");		
		}
		
		while(fgets(conteudo, 200, file) != NULL) //Enquanto busca no arquivo, busca as informações
		{
			system("cls");
			printf("\n\tInformações de usuário localizadas:\n\n");
			printf("%s", conteudo);
			printf("\n");
			printf("\n\tConsulta concluída com sucesso!\n\n");
		}
		
		fclose(file);
		
		system("pause");
		
		do
			{
				erro=0;
				
				system("cls");
				printf("\n\tO que deseja?\n\n");	
				printf("\t1 - Consultar outro CPF\n");
				printf("\t2 - Retornar ao Menu\n");
				printf("\t3 - Fechar aplicação\n");
				printf("\n\nOpção: ");
				
				loop();
		
			}
		while (erro==1);
	}			
	while (repeticao==1);
}

int deletar() //Deletar usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		repeticao=0;
		system("cls");
		
		char cpf[50];
	
		printf("\n\tDeletar usuário\n");
		printf("\n Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("\n\tUsuário não localizado\n\n");
			system("pause");
	
			do
			{
				erro=0;
		
				system("cls");
				printf("\n\tO que deseja?\n\n");	
				printf("\t1 - Deletar outro CPF\n");
				printf("\t2 - Retornar ao Menu\n");
				printf("\t3 - Fechar aplicação\n");
				printf("\n\nOpção: ");
			
				loop();
		
			}
	
			while (erro==1);
		}
	
		fclose(file);
	
		if(file != NULL)
		{
			system("cls");
			printf("\n\tVocê está prestes a deletar o seguinte usuário: ");
			printf(cpf);
			printf("\n\n\tDeseja prosseguir?\n\n");
			printf("\t1 - SIM");
			printf("\t\t2 - NÃO\n\n");
			printf("\tConfirmação: ");
			scanf("%i", &escolha);
			
			switch (escolha)
				{
					case 1:
					remove(cpf);
					system("cls");
					printf("\n\tUsuário deletado com sucesso!\n\n");
					system("pause");
			
					do
					{
						erro=0;	
				
						system("cls");
						printf("\n\tO que deseja?\n\n");	
						printf("\t1 - Deletar outro CPF\n");
						printf("\t2 - Retornar ao Menu\n");
						printf("\t3 - Fechar aplicação\n");
						printf("\n\nOpção: ");
						
						loop();
			
					}
				while (erro==1);
		
				break;
				
				do
				{
					erro=0;
				
					case 2:
					system("cls");
					printf("\n\tO que deseja?\n\n");	
					printf("\t1 - Deletar outro CPF\n");
					printf("\t2 - Retornar ao Menu\n");
					printf("\t3 - Fechar aplicação\n");
					printf("\n\nOpção: ");
					
					loop();
		
				}
				while (erro==1);
	
				break;	
				}
			while (erro==1);
		
		}
		
	}
	
	while (repeticao==1);
}


int main () 
	{	
	char LetraDigitada;
		
	setlocale(LC_ALL, "Portuguese");
	
		do 
		{
			menu=0;
			system("cls");
			printf("\n\t\tCartório da EBAC \n\n"); //Início d emenu
			printf("\tEscolha a opção desejada do menu\n\n");
			printf("\t1 - Registro de usuários\n");
			printf("\t2 - Consultar usuários\n");
			printf("\t3 - Deletar usuários\n");
			printf("\t4 - Sair\n\n");
			printf("Opção: "); //Fim de menu
		
			scanf("%i", &opcao);//Armazenamento de escolha
			scanf("%c", &LetraDigitada); //Registra digitação de algum caractere que não número para gerar erro
		
			system("cls");
	
			switch (opcao) //SwitchCase de opções de escolhas
			{
				case 1:
				registro();
				break;
			
				case 2:
				consultar();
				break;
			
				case 3:
				deletar();
				break;
						
				case 4:
				sair=1;
				break;
						
				default:
				printf("\n\tOpção escolhida não existente!!!\n");
				printf("\n\tPor favor, escolha uma opção disponível no menu!!!\n\n");
				menu=1;
				system("pause");		
			}
			
		}	
	while (menu==1);
		
	if (sair==1)
		{	
		system("cls");
		printf("\n\tEsse Software é de criação de Denner Filipi Ribeiro");
		}
}
