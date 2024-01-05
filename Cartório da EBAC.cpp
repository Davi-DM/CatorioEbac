#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //Função responsvel por cadrastar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem 
	
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado"); //Coletando informações do usuários
	scanf("%s", cpf); //%s refere-se a strings, ele amarzena o conteúdo da string
			
	strcpy(arquivo, cpf);//Função responsavel por copiar os valores das strings
			
	FILE *file;//Cria o arquivo no Banco de dados, no caso a pasta
	file = fopen(arquivo, "w");//Cria o arquivo e o "w" significa escrever, ou seja ele cria o arquivo e escreve o conteúdo dentro do arquivo.
	fprintf(file,cpf);// Salva o valor da variável
	fclose(file);// Fecha o arquivo
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o nome de usuário a ser cadastrado: ");
	scanf("%s",nome);
			
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o sobrenome de usuário a ser cadastrado: ");
	scanf("%s",sobrenome);
			
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
			
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
			
	printf("Digite o cargo de usuário a ser cadastrado: ");
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
	
	char cpf[40];//Variável responsável por armazenar conteúdo
	char conteudo[200];//Variável responsável por armazenar conteúdo
	
	printf("Digite o CPF do usuário a ser consultado: ");//Coleta as informações respasadas pelo usuário	
	scanf("%s", cpf);//%s refere-se a strings, ele amarzena o conteúdo da string, vai armazenar o "cpf" repassado pela pessoa que irá fazer a busca
	
	FILE *file;//Entra na biblioteca responsável pela função "FILE" e dentro ela puxa os arquivos "file".
	file = fopen(cpf, "r");//"fopen" refere-se a função de abrir a pasta e dentro da pasta a função vai buscar o arquivo "cpf", por último a função vai "ler", "r" ou "read" o conteúdo dentro do arquivo "cpf"
	
	//Inicio para validar se o usuário está realmente cadastrado
	if(file == NULL)//Função responsável por testar a condição repassada
	{
		printf("Não foi possivel abrir o arquivo, não localizado\n");
	}	
	
	//Inicio da função para salvamento do arquivo acima
	while(fgets(conteudo, 200, file) != NULL)//Laço repetição; While= Enquanto; fgets = buscar o arquivo. " A função está salvando e rodando na string "conteúdo" os "200" caractetes que estão dentro do "file" enquanto o conteúdo da string for "diferente de"/"!=" Null
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);// Irá salvar os valores que estão dentro da string "conteudo" e posteriomente irá apresentar esses valores
		printf("\n\n");
	}
	//Fim da função para salvamento
	
	system("pause");//Responsavel por pausar o sistema
}
		
		
int deletar()
{
	setlocale(LC_ALL, "Portuguese");//Define a linguagem
		
	char cpf[40];
		
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string, ele armazena o conteúdo na string, ele vai amarzenar tudo o que o usuário digitar e salvar no arquivo que eu pedir.
		
	remove(cpf);//Função responsável por deletar o aquivo que irá ser repassado
	
	//Inicio da validação de usuário, responsável por validar se aquele usuário no qual eu quero deletar realmente existe
	FILE *file;//Entra na biblioteca responsável pela função "FILE" e dentro ela puxa os arquivos "file".
	file = fopen(cpf,"r");//"fopen" refere-se a função de abrir a pasta e dentro da pasta a função vai buscar o arquivo "cpf", por último a função vai "ler", "r" ou "read" o conteúdo dentro do arquivo "cpf"
	
	//Validação
	if(file == NULL)//Função responsável por testar a condição repassada
	{
		printf("Usuário deletado com sucesso!\n");
		system("pause");//Responsável por pausar o sistema
	}		
	//Final da validação	
}
	
int main()
{
//Definindo variáveis
	int opcao=0;
	int laco=1;
			
	for(laco=1;laco=1;)
	{
					
		system("cls");// Responsável por limpar a tela

		//Definindo a linguagem			
		setlocale(LC_ALL, "Portuguese");
				
//Inicio do Menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar usuários\n");
		printf("\t2 - Consultar usuários\n");
		printf("\t3 - Deletar usuários\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opcao: ");//Fim do menu
		
		scanf("%d", &opcao);// Amarzene na variável "opção" o valor que o usuário digitar
				
		system("cls");// Comando para deletar as mensagens que ficam em cima
				
		//Inicio das estruturas condicionais de seleção
		switch(opcao)
		{
			case 1:
			registrar();//Chamada de funções
			break;
					
			case 2:
			consultar();//Chamada de funções
			break;
					
			case 3:
			deletar();//Chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sitema!\n");
			return 0;
			break;
										
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
			//Fim da seleção
		}
				
	}
		
}
