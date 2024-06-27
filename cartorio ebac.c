#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o (Idioma)
#include <string.h> //Biblioteca respons�vel pelas strings

//Vari�veis globais
int opcao=0; 
int repeticao=0;
int menu=0;
int sair=0;
int escolha=0;
int erro=0;


int loop() //Fun��o para retorno ao menu ou fechamento de qualquer local do programa
{
	scanf("%i", &opcao);
		
	switch (opcao)
	{
		case 1:
		repeticao=1; //Repete a �ltima a��o realizada
		break;
				
		case 2:
		menu=1; //Retorna ao menu principal
		break;
				
		case 3:
		sair=1; //Encerra o programa
		break;
				
		default: //Mensagem de erro caso outro caractere seja digitado al�m dos descritos acima
		system("cls");
		printf("\n\tOp��o escolhida n�o existente!!!\n");
		printf("\n\tPor favor, escolha uma op��o dispon�vel no menu!!!\n\n");
		system("pause");
		erro=1;
		break;	
	}
}

int registro()  //Fun��o registrar novos usu�rios
{
	
	do 
	{
		repeticao=0;
	
		system("cls");
	
		printf("\n\tInclus�o de usu�rios\n\n");
	
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
			printf("\n\tUsu�rio j� cadastrado!\n\n");
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
			fprintf(file, " - "); //, Para separar as informa��es
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
			
			printf("\n\tRegistro conclu�do com sucesso!\n\n");
			
			system("pause");
		}
		do
		{
			erro=0;
	
			system("cls");
			printf("\n\tO que deseja?\n\n");	
			printf("\t1 - Registrar outro CPF\n");
			printf("\t2 - Retornar ao Menu\n");
			printf("\t3 - Fechar aplica��o\n");
			printf("\n\n Op��o: ");
			
			loop();
	
		}
		while (erro==1);
		
	}
	while (repeticao==1);

}
	


int consultar() // Consultar CPF de usu�rios
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		repeticao=0;
		system("cls");
		printf("\n\tConsulta de usu�rios\n");
		
		char cpf[50];
		char conteudo[200];
		
		printf("\n Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); //Ler o arquivo CPF
		
		if(file == NULL)
		{
			system("cls");
			printf("\n\tUsu�rio n�o localizado!\n\n");		
		}
		
		while(fgets(conteudo, 200, file) != NULL) //Enquanto busca no arquivo, busca as informa��es
		{
			system("cls");
			printf("\n\tInforma��es de usu�rio localizadas:\n\n");
			printf("%s", conteudo);
			printf("\n");
			printf("\n\tConsulta conclu�da com sucesso!\n\n");
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
				printf("\t3 - Fechar aplica��o\n");
				printf("\n\nOp��o: ");
				
				loop();
		
			}
		while (erro==1);
	}			
	while (repeticao==1);
}

int deletar() //Deletar usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		repeticao=0;
		system("cls");
		
		char cpf[50];
	
		printf("\n\tDeletar usu�rio\n");
		printf("\n Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("\n\tUsu�rio n�o localizado\n\n");
			system("pause");
	
			do
			{
				erro=0;
		
				system("cls");
				printf("\n\tO que deseja?\n\n");	
				printf("\t1 - Deletar outro CPF\n");
				printf("\t2 - Retornar ao Menu\n");
				printf("\t3 - Fechar aplica��o\n");
				printf("\n\nOp��o: ");
			
				loop();
		
			}
	
			while (erro==1);
		}
	
		fclose(file);
	
		if(file != NULL)
		{
			system("cls");
			printf("\n\tVoc� est� prestes a deletar o seguinte usu�rio: ");
			printf(cpf);
			printf("\n\n\tDeseja prosseguir?\n\n");
			printf("\t1 - SIM");
			printf("\t\t2 - N�O\n\n");
			printf("\tConfirma��o: ");
			scanf("%i", &escolha);
			
			switch (escolha)
				{
					case 1:
					remove(cpf);
					system("cls");
					printf("\n\tUsu�rio deletado com sucesso!\n\n");
					system("pause");
			
					do
					{
						erro=0;	
				
						system("cls");
						printf("\n\tO que deseja?\n\n");	
						printf("\t1 - Deletar outro CPF\n");
						printf("\t2 - Retornar ao Menu\n");
						printf("\t3 - Fechar aplica��o\n");
						printf("\n\nOp��o: ");
						
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
					printf("\t3 - Fechar aplica��o\n");
					printf("\n\nOp��o: ");
					
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
			printf("\n\t\tCart�rio da EBAC \n\n"); //In�cio d emenu
			printf("\tEscolha a op��o desejada do menu\n\n");
			printf("\t1 - Registro de usu�rios\n");
			printf("\t2 - Consultar usu�rios\n");
			printf("\t3 - Deletar usu�rios\n");
			printf("\t4 - Sair\n\n");
			printf("Op��o: "); //Fim de menu
		
			scanf("%i", &opcao);//Armazenamento de escolha
			scanf("%c", &LetraDigitada); //Registra digita��o de algum caractere que n�o n�mero para gerar erro
		
			system("cls");
	
			switch (opcao) //SwitchCase de op��es de escolhas
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
				printf("\n\tOp��o escolhida n�o existente!!!\n");
				printf("\n\tPor favor, escolha uma op��o dispon�vel no menu!!!\n\n");
				menu=1;
				system("pause");		
			}
			
		}	
	while (menu==1);
		
	if (sair==1)
		{	
		system("cls");
		printf("\n\tEsse Software � de cria��o de Denner Filipi Ribeiro");
		}
}
