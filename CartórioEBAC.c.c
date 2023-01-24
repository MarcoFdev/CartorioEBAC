#include <stdio.h> //biblioteca de comunicação de usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings



int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;

int Registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis
	char Arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", CPF); //%s salva a informação/string
	
	strcpy(Arquivo, CPF); //responsavel por os valores das strings
	
	FILE *file;// cria o arquivo
	file = fopen(Arquivo, "w"); //cria o arquivo e o "w" significa escrever	
	fprintf(file, CPF); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(Arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ", ");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", Nome);//salvando a informação/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Nome);//salvo o valor da variável
	fclose(file);//fechando o arquivo
	
	file = fopen(Arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", Sobrenome);//Salvando a informação/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Sobrenome);//salvo o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(Arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", Cargo);//salvando a informação/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Cargo);//salvando o valor da variável
	fclose(file);//fechando o arquivo
	
	system("pause");
}

int Consultar() 
{
	setlocale(LC_ALL, "Portuguese");
	
	//definindo variáveis
	char Conteudo[200];
	char CPF[40];
	
	printf("Digite o CPF a ser consultado: \n");//coletando informações do usuário
	scanf("%s", CPF);//salvando a informação/string com "%s"
	
	system("cls");
	
	FILE *file;//criando o arquivo
	file = fopen(CPF, "r");//abrindo o arquivo, "r" significa ler
	
	if(file == NULL) //caso o arquivo não exista ou tenha sido deletado
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(Conteudo, 200, file) != NULL)//Mostra as informações solicitadas
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", Conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); 
	
	fclose(file);
	
}

int Deletar()
{
	//coletando variáveis
	char CPF[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usuário a ser deletado!\n");//coletando informações do usuário
	scanf("%s", CPF);//salvando as informações/string com "%s"
	
	remove(CPF);//função de deletar a informação

	FILE *file;//criando o arquivo
	file = fopen(CPF, "r");//abrinfo o arquivo e "r" significa ler
	
	if(file == CPF)
	{ 
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{ 
		printf("O usuário não se encontra mais no sistema!\n");
		system("pause");
	}
	
	fclose(file);//fecha o arquivo


}

int main() 
{
	
	int opcao = 0; // definindo variaveis
	int laco=1;
	
	
	for (laco=1;laco=1;) 
	{
		
		system("cls");
			
		setlocale(LC_ALL, "Portuguese"); //definincdo linguagem
		
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejadado menu:\n\n");
		printf("\t1- Registrar nomes:\n");
		printf("\t2- Consultar nomes:\n");
		printf("\t3- Deletar nomes:\n\n");	
		printf("\t4- Validar CPF:\n\n");	
		printf("Opção:"); //fim do menu
		
		scanf("%d", &opcao); //armazenando escolha do usuário
		
		system("cls");//responsável por limpar as telas
				
		switch(opcao) //inicio da seleção
		{
			case 1:
				Registro();//chamada de funções
			break;
			
			case 2:
				Consultar();//chamada de funções
			break;
			
			case 3:
				Deletar();//chamada de funções
			break;
			
			case 4:
				validarCPF();//chamada de funções
			break;
			
			default:
				printf("Está opção não está disponível\n");
				system("pause");
			break;
		}  //fim da seleção	
		
	}	
}
