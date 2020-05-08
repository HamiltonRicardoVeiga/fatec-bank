#include <stdio.h>

void access(int *, int *, int *);
int verifyAgency(int agency);                       // Verificar se agencia existe
int validateCredentials(int account, int password); // Validar Credenciais

void main()
{
    int agency, account, password;
    access(&agency, &account, &password);
    printf("%i %i", agency, account);
    system("pause");
}

void access(int *agency, int *account, int *password)
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
            printf("Parabens voce esta logado!!!");
        }
        else
        {
            printf("Erro no login tente novamente");
        }
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
    return 1;
}