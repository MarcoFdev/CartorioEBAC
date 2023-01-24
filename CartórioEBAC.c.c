#include <stdio.h> //biblioteca de comunica��o de usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
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
        return 0; ///se o CPF tiver todos os n�meros iguais ele � inv�lido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os n�meros de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 n�o for o mesmo que o da valida��o CPF � inv�lido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os n�meros de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 n�o for o mesmo que o da valida��o CPF � inv�lido
        }
    }
    return 1;

int Registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis
	char Arquivo[40];
	char CPF[40];
	char Nome[40];
	char Sobrenome[40];
	char Cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", CPF); //%s salva a informa��o/string
	
	strcpy(Arquivo, CPF); //responsavel por os valores das strings
	
	FILE *file;// cria o arquivo
	file = fopen(Arquivo, "w"); //cria o arquivo e o "w" significa escrever	
	fprintf(file, CPF); //salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(Arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ", ");
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", Nome);//salvando a informa��o/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Nome);//salvo o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	file = fopen(Arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", Sobrenome);//Salvando a informa��o/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Sobrenome);//salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(Arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", Cargo);//salvando a informa��o/string
	
	file = fopen(Arquivo, "a");//abrindo o arquivo
	fprintf(file, Cargo);//salvando o valor da vari�vel
	fclose(file);//fechando o arquivo
	
	system("pause");
}

int Consultar() 
{
	setlocale(LC_ALL, "Portuguese");
	
	//definindo vari�veis
	char Conteudo[200];
	char CPF[40];
	
	printf("Digite o CPF a ser consultado: \n");//coletando informa��es do usu�rio
	scanf("%s", CPF);//salvando a informa��o/string com "%s"
	
	system("cls");
	
	FILE *file;//criando o arquivo
	file = fopen(CPF, "r");//abrindo o arquivo, "r" significa ler
	
	if(file == NULL) //caso o arquivo n�o exista ou tenha sido deletado
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(Conteudo, 200, file) != NULL)//Mostra as informa��es solicitadas
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", Conteudo);
		printf("\n\n");
		
	}
	
	system("pause"); 
	
	fclose(file);
	
}

int Deletar()
{
	//coletando vari�veis
	char CPF[40];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF do usu�rio a ser deletado!\n");//coletando informa��es do usu�rio
	scanf("%s", CPF);//salvando as informa��es/string com "%s"
	
	remove(CPF);//fun��o de deletar a informa��o

	FILE *file;//criando o arquivo
	file = fopen(CPF, "r");//abrinfo o arquivo e "r" significa ler
	
	if(file == CPF)
	{ 
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{ 
		printf("O usu�rio n�o se encontra mais no sistema!\n");
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
		
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
		printf("Escolha a op��o desejadado menu:\n\n");
		printf("\t1- Registrar nomes:\n");
		printf("\t2- Consultar nomes:\n");
		printf("\t3- Deletar nomes:\n\n");	
		printf("\t4- Validar CPF:\n\n");	
		printf("Op��o:"); //fim do menu
		
		scanf("%d", &opcao); //armazenando escolha do usu�rio
		
		system("cls");//respons�vel por limpar as telas
				
		switch(opcao) //inicio da sele��o
		{
			case 1:
				Registro();//chamada de fun��es
			break;
			
			case 2:
				Consultar();//chamada de fun��es
			break;
			
			case 3:
				Deletar();//chamada de fun��es
			break;
			
			case 4:
				validarCPF();//chamada de fun��es
			break;
			
			default:
				printf("Est� op��o n�o est� dispon�vel\n");
				system("pause");
			break;
		}  //fim da sele��o	
		
	}	
}
