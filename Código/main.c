#include <stdio.h>

// Funcoes principais
void access(int *, int *, int *, int *);
void actions(float *balance);

// Validacoes
int verifyAgency(int agency); // Verificar se agencia existe
int validateCredentials(int account, int password); // Validar Credenciais

// Acoes do usuario
int deposit(float **balance);
int transfers();
int withdraw();
int extract();
int savings();
int payments();
int others();
void leave();


void main()
{
    int agency, account, password, logged = 0;
    float balance;

    while (logged != 1)
    {
        access(&agency, &account, &password, &logged);
    }

    if (logged == 1)
    {
        actions(&balance);
    }

    system("pause");
}

void access(int *agency, int *account, int *password, int *logged)
{
    printf("  ------------------------------------------------------------\n");
    printf("  |                    ... FATEC BANK ...                    |\n");
    printf("  |                    ..................                    |\n");
    printf("  |                                                          |\n");
    printf("  |                DIGITE O NUMERO DA AGENCIA                |\n");
    printf("  |                                                          |\n");
    printf("  ------------------------------------------------------------\n");
    scanf("%i", agency);
    if (verifyAgency(*agency) == 1)
    {
        printf("  ------------------------------------------------------------\n");
        printf("  |                                                          |\n");
        printf("  |                 DIGITE O NUMERO DA CONTA                 |\n");
        printf("  |                                                          |\n");
        printf("  ------------------------------------------------------------\n");
        scanf("%i", account);
        printf("  ------------------------------------------------------------\n");
        printf("  |                                                          |\n");
        printf("  |                      DIGITE SUA SENHA                    |\n");
        printf("  |                         6 DIGITOS                        |\n");
        printf("  |                                                          |\n");
        printf("  ------------------------------------------------------------\n");
        scanf("%i", password);
        if (validateCredentials(*account, *password) == 1)
        {
            *logged = 1;
            printf("Parabens voce esta logado!!!\n"); // Temporario
        }
        else
        {
            printf("Conta e/ou senha nao coincidem, tente novamente\n");
        }
    }
    else
    {
        printf("Agencia invalida\n");
    }
    
}

void actions(float *balance)
{
    int operation;

    printf("  ------------------------------------------------------------\n");
    printf("  |                    ... FATEC BANK ...                    |\n");
    printf("  |                    ..................                    |\n");
    printf("  |                                                          |\n");
    printf("  |     <- DEPOSITO (1)                      (2) SAQUE ->    |\n");
    printf("  |                                                          |\n");
    printf("  |     <- TRANSFERENCIAS (3)              (4) EXTRATO ->    |\n");
    printf("  |                                                          |\n");
    printf("  |     <- POUPANCA (5)                 (6) PAGAMENTOS ->    |\n");
    printf("  |                                                          |\n");
    printf("  |     <- SAIR (7)                         (8) OUTROS ->    |\n");
    printf("  |                                                          |\n");
    printf("  |                      DIGITE A OPCAO                      |\n");
    printf("  |                                                          |\n");
    printf("  ------------------------------------------------------------\n");
    scanf("%i", &operation);

    switch (operation)
    {
        case 1:
            if (deposit(&balance) == 1)
            {
                printf("Deposito feito com sucesso, saldo atual: %f", balance);
            }

            actions(balance);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            actions(balance);
            break;
    }
}

int verifyAgency(int agency)
{
    int agencies[7] = {12, 15, 18, 20, 30, 50, 60}; // Simulando requesicao ao servidor sobre as agencias ativas

    for (int i = 0; i < 6; i++)
    {
        if (agencies[i] == agency)
        {
            return 1;
        }
    }

    return 0;
}

int validateCredentials(int account, int password)
{
    int accounts[2][2] = {{3001, 123456}, {3000, 1234567}}; // [Conta, Senha]

    for (int i = 0; i < 2; i++)
    {
        if (account == accounts[i][0] && password == accounts[i][1])
        {
            return 1;
        }

    }

    return 0;
}

int deposit(float **balance)
{
    **balance += 1000;
    printf("%.2f", **balance);
    return 1;
}