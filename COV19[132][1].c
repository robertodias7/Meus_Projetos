#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define MAX_SENHA 6
#define MAX_LOGIN 50
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)


char email[40];
int mes;
int dia;
int ano;
int data = 2022;
int *idade;
FILE *CAD;
FILE *COM;


struct cadastro {
	char nome[40];//OK
	char CPF[12];//OK
	char telefone[12];//OK
	char rua[20];//OK
	char endereco[20];//OK
	int numero;//OK
	char CEP[9]; //OK
	char complemento[30];//OK
	char bairro[20];//OK
	char cidade[30];//OK
	char estado[20];//OK
	char sexo[2];//OK

}; struct cadastro paciente;

void cadastro(void);//OK
void menu(void);//OK
void tela(void);//OK

int Usuario( FILE* file, char* user, char* senha ) //VALIDA O USUÁRIO
{
	char tmpLogin[MAX_LOGIN];
	char tmpSenha[MAX_SENHA];

	fscanf(file, "%s", tmpLogin);

	while( !feof(file) )
	{
		if( !strcmp(tmpLogin, user))
		{
			fscanf(file, "%s", tmpSenha);

			if( !strcmp(tmpSenha, senha))
				return 1;
		}
		else
		{
			fscanf(file, "%*s");
		}

		fscanf(file, "%s", tmpLogin);
	}

	return 0;
}

char* CriaSenha() //INICIA A CRIAÇÃO DE SENHA
{
    register int i;
	char* senha = (char*)malloc(sizeof *senha * MAX_SENHA);

    for(i = 0; i < MAX_SENHA; i++)
	{
        senha[i] = getch();
        if(senha[i] == '\r')
            break;
        else
            printf("*");
    }
	senha[i] = '\0';

	return senha;
}

void tela(void)// TELA DE INÍCIO
{
	printf("\n\n");
	printf("\t\t\t\t\t\t  SEJA BEM-VINDO\n");
	printf("\t\t\t\t  INSIRA USUÁRIO E SENHA PARA LOGAR NO SISTEMA ");
	printf("\n\t\t\t\t ______________________________________________\n");
	printf("\n\n\n");
	return;
}

int main(void){
	system("color 1F");
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	tela();
	int main();

	FILE* fpIN;
	int option = 0;

	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha, *confirmaSenha;

	do
	{   //TELA DE CADASTRO
		printf("\n\t\t\t\t1- LOGIN\n");
		printf("\t\t\t\t2- CADASTRAR\n");
		printf("\t\t\t\t3- SAIR\n\n");
		printf("\t\t\t\tDIGITE A OPÇÃO DESEJADA: ");
		scanf("%d", &option);
		CLEAN_BUFF;

		switch( option )
		{
			case 1:	/*VALIDAÇÃO DE SENHA*/
				printf("\n\t\t\t\tUSUÁRIO......: ");
				gets(user);
				printf("\t\t\t\tSENHA........: ");
				senha = CriaSenha();

				fpIN = fopen("usuarios1.txt", "a+");
				if(Usuario(fpIN, user, senha)){
                        printf("\n\t\t\t\tUSUÁRIO REGISTRADO.");

					cadastro();
                }

                else
				printf("\n\t\t\t\tUSUÁRIO NÃO REGISTRADO\n");
				fclose(fpIN);
				free(senha);
                exit(0);

			case 2:
				do
				{   //CONFIRMAÇÃO DE SENHA
					printf("\n\t\t\t\tUSUÁRIO......: ");
					gets(user);
					printf("\t\t\t\tSENHA........: ");
					senha = CriaSenha();
					printf("\n\t\t\t\tCONFIRMAÇÃO DE SENHA: ");
					confirmaSenha = CriaSenha();
					printf("\n");

					if( !strcmp(senha, confirmaSenha) )
						break;
                    else    //CASO AS SENHAS NÃO SEJAM IGUAIS, MENSAGEM
				  		printf("\n\t\t\t\tAS SENHAS NÃO SÃO IGUAIS. TENTE NOVAMENTE\n\n");
                } while(1);

				system("cls");
				tela();// TELA DE APRESENTAÇÃO
				printf("\n\n");
				fpIN = fopen("usuarios1.txt", "a+");
				fprintf(fpIN, "%s %s\n", user, senha);
				fclose(fpIN);

				free(senha);
				free(confirmaSenha);
				break;

			case 3:

			default: break; //PARA SAIR DA TELA
		}
	}while( 1 );
}

void cadastro(void)// FUNÇÃO DE CADASTRO DE PACIENTES
{
	system("cls");
	int idade;
	int dia= 0;
	int mes = 0;
	int ano = 0;
	char comorbidade[40];
	FILE *COM;
	FILE *CAD;
	CAD = fopen("c19.txt", "a");

	printf("\n\t\t\t\t    INSIRA OS DADOS DO(A) PACIENTE\n");
	printf("\t\t\t_____________________________________________________\n\n");
	printf("\n\t\t\tNOME COMPLETO: ");fflush(stdin);fgets(paciente.nome, 40, stdin);
	fprintf(CAD, "NOME COMPLETO: %s", paciente.nome);
	printf("\t\t\tCPF: ");fflush(stdin);scanf("%s", paciente.CPF);
	fprintf(CAD,"\nCPF: %s",paciente.CPF);
	printf("\t\t\tSEXO [M / F]: "); fflush(stdin); scanf("%s", paciente.sexo);
	fprintf(CAD, "\nSEXO [M / F]: %s", paciente.sexo);

	printf("\n\t\t\t_____________________________________________________\n");

	printf("\t\t\tDATA DE NASCIMENTO\n");
	printf("\t\t\tDIA(DD): ");fflush(stdin);scanf("%d",&dia);
	printf("\t\t\tMÊS(MM): ");fflush(stdin);scanf("%d", &mes);
	printf("\t\t\tANO(AAAA): ");fflush(stdin);scanf("%d", &ano);
	printf("\n\t\t\tDATA DE NASCIMENTO: %d/%d/%d", dia, mes, ano);
	fprintf(CAD, "\nDATA DE NASCIMENTO: %d/%d/%d", dia, mes, ano);
	fclose(CAD);
	idade = data - ano;
	printf("\n\t\t\t%d anos", idade);
    // PACIENTES COM IDADE ACIMA OU IGUAL A 65 ANOS, GRUPO DE RISCO
    if(idade >= 65)
    {
        printf("\n\t\t\t_____________________________________________________\n");
        printf("\n\t\t\tO PACIENTE FAZ  PARTE DO GRUPO DE RISCO");
        COM = fopen("com19.txt", "a");
        fprintf(CAD,"\nIDADE: %d anos\n",idade);
        printf("\n\t\t\tCEP: ");fflush(stdin); scanf("%8[^\n]s", paciente.CEP);
        fprintf(COM, "\nCEP: %s", paciente.CEP);
        fclose(COM);
    }

    printf("\t\t\tCOMORBIDADE: "); fflush(stdin); scanf("%s", comorbidade);
    CAD = fopen("c19.txt", "a");
    fprintf(CAD,"\nCOMORBIDADE: %s\n", comorbidade);
    printf("\t\t\t_____________________________________________________\n");
	printf("\t\t\tINSIRA A DATA DO DIAGNÓSTICO\n");
	printf("\t\t\tDIA: ");fflush(stdin);scanf("%d", &dia);
	printf("\t\t\tMÊS: ");fflush(stdin);scanf("%d", &mes);
	printf("\t\t\tANO: ");fflush(stdin);scanf("%d", &ano);
	printf("\n\t\t\tDATA DO DIAGNÓSTICO: %d/%d/%d", dia, mes, ano);
	fprintf(CAD,"\nDATA DO DIAGNÓSTICO: %d/%d/%d", dia, mes, ano);

	printf("\n\t\t\t_____________________________________________________\n");
        //CONTATO DO PACIENTE
	printf("\t\t\tCONTATO DO(A) PACIENTE\n\n");
	printf("\t\t\tTELEFONE(DDD): ");fflush(stdin);scanf("%s", paciente.telefone);
	fprintf(CAD, "\nTELEFONE(DDD): %s",paciente.telefone);
	printf("\t\t\tE-MAIL: ");fflush(stdin);fgets(email, 40, stdin);
	fprintf(CAD, "\nE-MAIL: %s", email);
	printf("\n\t\t\t_____________________________________________________\n");
        //ENDEREÇO DO PACIENTE
	printf("\t\t\tENDEREÇO DO(A) PACIENTE\n\n");
	printf("\t\t\tENDEREÇO: ");fflush(stdin);scanf("%20[^\n]s", paciente.endereco);
	fprintf(CAD, "\nENDEREÇO: %s", paciente.endereco);
	printf("\t\t\tNÚMERO (OPCIONAL): ");fflush(stdin);scanf("%d", &paciente.numero);
	fprintf(CAD,"\nNÚMERO (OPCIONAL): %d", paciente.numero);
	printf("\t\t\tRUA (OPCIONAL): ");fflush(stdin);scanf("%[^\n]s", paciente.rua);
	fprintf(CAD,"\nRUA (OPCIONAL): %s", paciente.rua);
	printf("\t\t\tCEP: ");fflush(stdin);scanf("%s", paciente.CEP);
	fprintf(CAD,"\nCEP: %s", paciente.CEP);
	printf("\t\t\tBAIRRO: ");fflush(stdin);scanf("%30[^\n]s", paciente.bairro);
	fprintf(CAD, "\nBAIRRO: %s", paciente.bairro);
	printf("\t\t\tCOMPLEMENTO (OPCIONAL): ");fflush(stdin); scanf("%30[^\n]s", paciente.complemento);
	fprintf(CAD,"\nCOMPLEMENTO (OPCIONAL): %s", paciente.complemento);
	printf("\t\t\tCIDADE: ");fflush(stdin);scanf("%30[^\n]s", paciente.cidade);
	fprintf(CAD, "\nCIDADE: %s", paciente.cidade);
	printf("\t\t\tESTADO: ");fflush(stdin);scanf("%20[^\n]s", paciente.estado);
	fprintf(CAD,"\nESTADO: %s\n\n", paciente.estado);
	printf("\n\n\t\t\tPACIENTE CADASTRADO!\n\n");
	fclose(CAD);
	return ;
}
