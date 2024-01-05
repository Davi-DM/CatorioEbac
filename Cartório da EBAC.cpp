#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o responsvel por cadrastar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem 
	
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado"); //Coletando informa��es do usu�rios
	scanf("%s", cpf); //%s refere-se a strings, ele amarzena o conte�do da string
			
	strcpy(arquivo, cpf);//Fun��o responsavel por copiar os valores das strings
			
	FILE *file;//Cria o arquivo no Banco de dados, no caso a pasta
	file = fopen(arquivo, "w");//Cria o arquivo e o "w" significa escrever, ou seja ele cria o arquivo e escreve o conte�do dentro do arquivo.
	fprintf(file,cpf);// Salva o valor da vari�vel
	fclose(file);// Fecha o arquivo
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o nome de usu�rio a ser cadastrado: ");
	scanf("%s",nome);
			
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o sobrenome de usu�rio a ser cadastrado: ");
	scanf("%s",sobrenome);
			
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o cargo de usu�rio a ser cadastrado: ");
	scanf("%s",cargo);
			
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	system("pause");
}
	
int consultar()
{
	setlocale(LC_ALL, "Portuguese");//Define a linguaguem
	
	char cpf[40];//Vari�vel respons�vel por armazenar conte�do
	char conteudo[200];//Vari�vel respons�vel por armazenar conte�do
	
	printf("Digite o CPF do usu�rio a ser consultado: ");//Coleta as informa��es respasadas pelo usu�rio	
	scanf("%s", cpf);//%s refere-se a strings, ele amarzena o conte�do da string, vai armazenar o "cpf" repassado pela pessoa que ir� fazer a busca
	
	FILE *file;//Entra na biblioteca respons�vel pela fun��o "FILE" e dentro ela puxa os arquivos "file".
	file = fopen(cpf, "r");//"fopen" refere-se a fun��o de abrir a pasta e dentro da pasta a fun��o vai buscar o arquivo "cpf", por �ltimo a fun��o vai "ler", "r" ou "read" o conte�do dentro do arquivo "cpf"
	
	//Inicio para validar se o usu�rio est� realmente cadastrado
	if(file == NULL)//Fun��o respons�vel por testar a condi��o repassada
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado\n");
	}	
	
	//Inicio da fun��o para salvamento do arquivo acima
	while(fgets(conteudo, 200, file) != NULL)//La�o repeti��o; While= Enquanto; fgets = buscar o arquivo. " A fun��o est� salvando e rodando na string "conte�do" os "200" caractetes que est�o dentro do "file" enquanto o conte�do da string for "diferente de"/"!=" Null
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);// Ir� salvar os valores que est�o dentro da string "conteudo" e posteriomente ir� apresentar esses valores
		printf("\n\n");
	}
	//Fim da fun��o para salvamento
	
	system("pause");//Responsavel por pausar o sistema
}
		
		
int deletar()
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem
		
	char cpf[40];
		
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string, ele armazena o conte�do na string, ele vai amarzenar tudo o que o usu�rio digitar e salvar no arquivo que eu pedir.
		
	remove(cpf);//Fun��o respons�vel por deletar o aquivo que ir� ser repassado
	
	//Inicio da valida��o de usu�rio, respons�vel por validar se aquele usu�rio no qual eu quero deletar realmente existe
	FILE *file;//Entra na biblioteca respons�vel pela fun��o "FILE" e dentro ela puxa os arquivos "file".
	file = fopen(cpf,"r");//"fopen" refere-se a fun��o de abrir a pasta e dentro da pasta a fun��o vai buscar o arquivo "cpf", por �ltimo a fun��o vai "ler", "r" ou "read" o conte�do dentro do arquivo "cpf"
	
	//Valida��o
	if(file == NULL)//Fun��o respons�vel por testar a condi��o repassada
	{
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");//Respons�vel por pausar o sistema
	}		
	//Final da valida��o	
}
	
int main()
{
//Definindo vari�veis
	int opcao=0;
	int laco=1;
			
	for(laco=1;laco=1;)
	{
					
		system("cls");// Respons�vel por limpar a tela

		//Definindo a linguagem			
		setlocale(LC_ALL, "Portuguese");
				
//Inicio do Menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar usu�rios\n");
		printf("\t2 - Consultar usu�rios\n");
		printf("\t3 - Deletar usu�rios\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opcao: ");//Fim do menu
		
		scanf("%d", &opcao);// Amarzene na vari�vel "op��o" o valor que o usu�rio digitar
				
		system("cls");// Comando para deletar as mensagens que ficam em cima
				
		//Inicio das estruturas condicionais de sele��o
		switch(opcao)
		{
			case 1:
			registrar();//Chamada de fun��es
			break;
					
			case 2:
			consultar();//Chamada de fun��es
			break;
					
			case 3:
			deletar();//Chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sitema!\n");
			return 0;
			break;
										
			default:
			printf("Esta op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			//Fim da sele��o
		}
				
	}
		
}
