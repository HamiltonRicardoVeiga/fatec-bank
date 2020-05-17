#include <stdio.h>

// Funcoes principais
void access(int *, int *, int *, int *, float *, float *);
void actions(float *balance, float *balanceSavings);

// Validacoes
int verifyAccount(int);
int verifyAccountSavings(int);
int verifyAgency(int);             // Verificar se agencia existe
int validateCredentials(int, int); // Validar Credenciais
int consultBarCode(int);

// Acoes do usuario
int deposit(float *, float);
int transfers();
int withdraw(float, float);
int extract();
void leave();

void main()
{
    int agency, account, password, logged = 0;
    float balance, balanceSavings;

    while (logged != 1)
    {
        access(&agency, &account, &password, &logged, &balance, &balanceSavings);
    }

    if (logged == 1)
    {
        actions(&balance, &balanceSavings);
    }

    system("pause");
}

void access(int *agency, int *account, int *password, int *logged, float *balance, float *balanceSavings)
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
            *balanceSavings = 3000;
            *balance = 1000;
            *logged = 1;
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

void actions(float *balance, float *balanceSavings)
{
    int operation, subOperation, barCode, valueBarCode, cc_account;
    float newAction, value;
    while (operation != 7)
    {
        newAction = 0;
        value = 0;
        valueBarCode = 0;
        subOperation = 0;

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
        printf("  |     <- SAIR (7)                                          |\n");
        printf("  |                                                          |\n");
        printf("  |                      DIGITE A OPCAO                      |\n");
        printf("  |                                                          |\n");
        printf("  ------------------------------------------------------------\n");
        printf("                                                              \n");
        printf("        Saldo: %.2f                                           \n", *balance);
        printf("                                                              \n");
        printf("  ------------------------------------------------------------\n");
        scanf("%i", &operation);

        switch (operation)
        {
        case 1:
            printf("  ------------------------------------------------------------\n");
            printf("  |                    ... FATEC BANK ...                    |\n");
            printf("  |                    ..................                    |\n");
            printf("  |                                                          |\n");
            printf("  |                         DEPOSITO                         |\n");
            printf("  |                                                          |\n");
            printf("  |              DIGITE O VALOR A SER DEPOSITADO             |\n");
            printf("  |                                                          |\n");
            printf("  ------------------------------------------------------------\n");
            scanf("%f", &value);

            if (deposit(&newAction, value) == 1)
            {
                *balance += newAction;
            }
            break;
        case 2:
            while (subOperation != 2 && subOperation != 3)
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                         SAQUES                           |\n");
                printf("  |                                                          |\n");
                printf("  |               DIGITE O VALOR A SER SACADO                |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                scanf("%f", &value);
                if (value > 1000)
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         SAQUES                           |\n");
                    printf("  |                                                          |\n");
                    printf("  |             O VALOR A SER SACADO E MAIOR QUE             |\n");
                    printf("  |            QUE O PERMITIDO NO CAIXA ELETRONICO           |\n");
                    printf("  |          FAVOR DIRIJA-SE AO GERENTE PARA EFETUAR         |\n");
                    printf("  |                         O SAQUE                          |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                                                          |\n");
                    printf("  |                                                          |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         SAQUES                           |\n");
                    printf("  |                                                          |\n");
                    printf("  |            DESEJA REALIZAR O SAQUE MENOR QUE             |\n");
                    printf("  |                       R$ 1000.00                         |\n");
                    printf("  |                                                          |\n");
                    printf("  |        <- SIM (1)                      (2) NAO->         |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                    scanf("%i", &subOperation);
                }
                else
                {
                    subOperation = 3;
                }
            }

            if (subOperation == 3)
            {
                if (withdraw(*balance, value) == 1)
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         SAQUES                           |\n");
                    printf("  |                                                          |\n");
                    printf("  |                RETIRE O VALOR SOLICITADO                 |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");

                    *balance -= value;
                }
                else
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         SAQUES                           |\n");
                    printf("  |                                                          |\n");
                    printf("  |             VOCE NAO POSSUI SALDO SUFICIENTE             |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
            }
            else
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                         SAQUES                           |\n");
                printf("  |                                                          |\n");
                printf("  |               ACAO CANCELADA PELO USUARIO                |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
            }
            break;
        case 3:
            printf("  ------------------------------------------------------------\n");
            printf("  |                    ... FATEC BANK ...                    |\n");
            printf("  |                    ..................                    |\n");
            printf("  |                                                          |\n");
            printf("  |                      TRANSFERENCIAS                      |\n");
            printf("  |                                                          |\n");
            printf("  |     <- CONTA CORRENTE (1)       (2) CONTA POUPANCA ->    |\n");
            printf("  |                                                          |\n");
            printf("  |     <- VOLTAR (3)                                        |\n");
            printf("  |                                                          |\n");
            printf("  ------------------------------------------------------------\n");
            scanf("%i", &subOperation);
            switch (subOperation)
            {
            case 1:
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                      CONTA CORRENTE                      |\n");
                printf("  |                                                          |\n");
                printf("  |                 DIGITE O NUMERO DA CONTA                 |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                scanf("%i", &cc_account);

                if (verifyAccount(cc_account) == 1)
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |              DIGITE O VALOR A SER TRANSFERIDO            |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                    scanf("%f", &value);

                    if (value <= *balance)
                    {
                        *balance -= value;
                    }
                    else
                    {
                        printf("  ------------------------------------------------------------\n");
                        printf("  |                    ... FATEC BANK ...                    |\n");
                        printf("  |                    ..................                    |\n");
                        printf("  |                                                          |\n");
                        printf("  |                       CONTA CORRENTE                     |\n");
                        printf("  |                                                          |\n");
                        printf("  |              VOCE NAO POSSUI SALDO SUFICIENTE            |\n");
                        printf("  |                                                          |\n");
                        printf("  ------------------------------------------------------------\n");
                    }
                }
                else
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                       CONTA INVALIDA                     |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
                break;
            case 2:
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                      CONTA POUPANCA                      |\n");
                printf("  |                                                          |\n");
                printf("  |                 DIGITE O NUMERO DA CONTA                 |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                scanf("%d", &cc_account);

                if (verifyAccountSavings(cc_account) == 1)
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |              DIGITE O VALOR A SER TRANSFERIDO            |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                    scanf("%f", &value);

                    if (value <= *balance)
                    {
                        *balance -= value;
                    }
                    else
                    {
                        printf("  ------------------------------------------------------------\n");
                        printf("  |                    ... FATEC BANK ...                    |\n");
                        printf("  |                    ..................                    |\n");
                        printf("  |                                                          |\n");
                        printf("  |                      CONTA POUPANCA                      |\n");
                        printf("  |                                                          |\n");
                        printf("  |              VOCE NAO POSSUI SALDO SUFICIENTE            |\n");
                        printf("  |                                                          |\n");
                        printf("  ------------------------------------------------------------\n");
                    }
                }
                else
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                       CONTA INVALIDA                     |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
                break;
            default:
                break;
            }
            break;
        case 4:
            break;
        case 5:
            printf("  ------------------------------------------------------------\n");
            printf("  |                    ... FATEC BANK ...                    |\n");
            printf("  |                    ..................                    |\n");
            printf("  |                                                          |\n");
            printf("  |                         POUPANCA                         |\n");
            printf("  |                                                          |\n");
            printf("  |     <- APLICAR (1)                    (2) RETIRAR ->     |\n");
            printf("  |                                                          |\n");
            printf("  |     <- VOLTAR (3)                                        |\n");
            printf("  |                                                          |\n");
            printf("  ------------------------------------------------------------\n");
            printf("                                                              \n");
            printf("        Saldo: %.2f                                           \n", *balanceSavings);
            printf("                                                              \n");
            printf("  ------------------------------------------------------------\n");
            scanf("%i", &subOperation);

            if (subOperation == 1)
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                         POUPANCA                         |\n");
                printf("  |                                                          |\n");
                printf("  |               DIGITE O VALOR A SER APLICADO              |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                scanf("%f", &value);

                if (value <= *balance)
                {
                    *balanceSavings += value;
                    *balance -= value;
                }
                else 
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         POUPANCA                         |\n");
                    printf("  |                                                          |\n");
                    printf("  |              VOCE NAO POSSUI SALDO SUFICIENTE            |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
            }
            else if (subOperation == 2)
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                         POUPANCA                         |\n");
                printf("  |                                                          |\n");
                printf("  |               DIGITE O VALOR A SER RETIRADO              |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                scanf("%f", &value);

                if (value <= *balanceSavings)
                {
                    *balanceSavings -= value;
                    *balance += value;
                }
                else
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                         POUPANCA                         |\n");
                    printf("  |                                                          |\n");
                    printf("  |              VOCE NAO POSSUI SALDO SUFICIENTE            |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
                
            }
            break;
        case 6:
            printf("  ------------------------------------------------------------\n");
            printf("  |                    ... FATEC BANK ...                    |\n");
            printf("  |                    ..................                    |\n");
            printf("  |                                                          |\n");
            printf("  |                        PAGAMENTOS                        |\n");
            printf("  |                                                          |\n");
            printf("  |                  DIGITE CODIGO DE BARRAS                 |\n");
            printf("  |                                                          |\n");
            printf("  ------------------------------------------------------------\n");
            scanf("%i", &barCode);

            valueBarCode = consultBarCode(barCode);

            if (valueBarCode != 0)
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                        PAGAMENTOS                        |\n");              
                printf("  |                                                          |\n");
                printf("  |                 DESEJA EFETUAR O PAGAMENTO?              |\n");
                printf("  |                                                          |\n");
                printf("  |      <- SIM (1)                          (2) NAO ->      |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
                printf("                                                              \n");
                printf("        Valor: %i                                             \n", valueBarCode);
                printf("                                                              \n");
                printf("  ------------------------------------------------------------\n");
                scanf("%i", &subOperation);

                if (subOperation == 1)
                {
                    if (valueBarCode <= *balance)
                    {
                        *balance -= valueBarCode;

                        printf("  ------------------------------------------------------------\n");
                        printf("  |                    ... FATEC BANK ...                    |\n");
                        printf("  |                    ..................                    |\n");
                        printf("  |                                                          |\n");
                        printf("  |                        PAGAMENTOS                        |\n");
                        printf("  |                                                          |\n");
                        printf("  |              PAGAMENTO EFETUADO COM SUCESSO!             |\n");
                        printf("  |                                                          |\n");
                        printf("  ------------------------------------------------------------\n");
                    }
                    else
                    {
                        printf("  ------------------------------------------------------------\n");
                        printf("  |                    ... FATEC BANK ...                    |\n");
                        printf("  |                    ..................                    |\n");
                        printf("  |                                                          |\n");
                        printf("  |                         PAGAMENTOS                       |\n");
                        printf("  |                                                          |\n");
                        printf("  |              VOCE NAO POSSUI SALDO SUFICIENTE            |\n");
                        printf("  |                                                          |\n");
                        printf("  ------------------------------------------------------------\n");
                    }
                    
                }
                else
                {
                    printf("  ------------------------------------------------------------\n");
                    printf("  |                    ... FATEC BANK ...                    |\n");
                    printf("  |                    ..................                    |\n");
                    printf("  |                                                          |\n");
                    printf("  |                        PAGAMENTOS                        |\n");
                    printf("  |                                                          |\n");
                    printf("  |              OPERACAO CANCELADA PELO USUARIO             |\n");
                    printf("  |                                                          |\n");
                    printf("  ------------------------------------------------------------\n");
                }
            }
            else
            {
                printf("  ------------------------------------------------------------\n");
                printf("  |                    ... FATEC BANK ...                    |\n");
                printf("  |                    ..................                    |\n");
                printf("  |                                                          |\n");
                printf("  |                        PAGAMENTOS                        |\n");
                printf("  |                                                          |\n");
                printf("  |                      BOLETO INVALIDO                     |\n");
                printf("  |                                                          |\n");
                printf("  ------------------------------------------------------------\n");
            }
            break;
        case 7:
            leave();
            break;
        default:
            printf("Continuar operacoes.\n");
            break;
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

int verifyAccount(int account)
{
    int accounts[2] = {3001, 3000};

    for (int i = 0; i < 2; i++)
    {
        if (account == accounts[i])
        {
            return 1;
        }
    }

    return 0;
}

int verifyAccountSavings(int account)
{
    int accounts[2] = {4005, 5006};

    for (int i = 0; i < 2; i++)
    {
        if (account == accounts[i])
        {
            return 1;
        }
    }

    return 0;
}

int validateCredentials(int account, int password)
{
    int accounts[2][2] = {{3001, 123456}, {3000, 123457}}; // [Conta, Senha]

    for (int i = 0; i < 2; i++)
    {
        if (account == accounts[i][0] && password == accounts[i][1])
        {
            return 1;
        }
    }

    return 0;
}

int consultBarCode(int barCode)
{
    int data[4][2] = {{123456789, 3000}, {987654321, 1500}, {123345678, 500}, {998736452, 30}};

    for (int i = 0; i < 4; i++)
    {
        if (barCode == data[i][0])
        {
            return data[i][1];
        }
    }

    return 0;
}

int deposit(float *newAction, float value)
{
    *newAction = value;
    return 1;
}

int withdraw(float balance, float value)
{
    if (balance >= value)
    {
        return 1;
    }

    return 0;
}

void leave() 
{
    printf("Obrigado pela preferencia.\n");
}