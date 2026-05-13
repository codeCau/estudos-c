#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define P_Max 5
    typedef struct {

        char nm[50];
        int id;
        float alt;
        float ps;
        float im;

    } pessoa;

            pessoa cofre[P_Max];

            int pT = 0;
            int p = 0;
            int o = 0;

            int verificacao(char n[]);
            void cadastrar();
            void listar();
            void menu(int i);
            void imcc(int i);
            void idade(int i);
            void ldentro(int i);
            int mainMenu();

            int main() {
                do {
                    
                    system("cls");
                    mainMenu();
                    
                switch(o) {
                 
                    case 1:

                        system("cls");
                        cadastrar ();
                        getchar();

                        break;

                    case 2:

                        system("cls");
                        listar();
                        
                        break;
                        
                    case 0:
                    
                    break;
                    
                    default:

                        system("cls");
                        printf("\nSelecione uma opcao valida\n");
                        
                        break;
                }
        }while(o != 0);
        
        system("cls");  
        printf("encerrando programa\n");
        printf("pressione entrer para sair\n");
        getchar();
        getchar();
        
        return 0;
        
    }

    int mainMenu(){
            printf("Escolha uma opcao: \n");
            printf("--Total de cadastros: %d--", p);
            printf("\n1 - Cadastrar uma pessoa: \n");
            printf("2 - Liste as pessoas cadastradas: \n");
            printf("0 - Para sair do sistema\n");
            scanf("%d", &o);
        
            return o;
    }

    int verificacao(char n[]) { 

        if(strlen (n) == 0 ){

            printf("\nNome invalido\n");
            printf("pressione enter para tentar novamente");
            getchar();
            getchar();

            return 0;
        }

        if(strpbrk(n, "0123456789") != NULL ) {

            printf("\nNome invalido\n");
            printf("pressione enter para tentar novamente");
            getchar();
            getchar();

            return 0;

        }
        return 1;
    }

    void cadastrar () {
        if(pT >= P_Max){

            system("cls");
            printf("\nMaximo de pessoas cadastradas!\n");;

            return;
        }

        printf("Escreva seu nome:\n");        
                                            //! fgets subistitui o scanf e faz com uqe o strlen == 0 funcione corretamente
        while(getchar() != '\n');          //! while (getchar() != '\n'); faz o fgets consumir o '\n' que sobrou
        
        fgets(cofre[p].nm, 50, stdin);  
        cofre[p].nm [strcspn (cofre[p].nm, "\n") ] = '\0';
        if(verificacao (cofre[p].nm) == 0) return;

        printf("Escreva sua idade:\n");
        scanf("%4d", &cofre[p].id);    
        printf("Escreva sua altura:\n");
        scanf("%f", &cofre[p].alt);
        printf("Escreva seu peso:\n");
        scanf("%f", &cofre[p].ps);
        
        pT++;
        p++;

        return;
        
    }

    void ldentro(int i) {

        printf("Nome da Pessoa: ");                    
        printf("%s\n", cofre[i].nm);
        printf("Idade: ");
        printf("%d\n", cofre[i].id);
        printf("Altura: ");
        printf("%.2f\n", cofre[i].alt);

    }

    void idade(int i) {
        if(cofre[i].id < 18){

            printf("Menor de idade\n");
        
    }

        else {
        
            printf("Maior de idade\n");
        
        }
    }

    void imcc(int i) {

        cofre[i].im = cofre[i].ps / (cofre[i].alt * cofre[i].alt);
        printf("seu imc e: %.1f ", cofre[i].im);

    }

    void menu(int i) {

            printf("Nome da Pessoa: ");                    
            printf("%s\n", cofre[i].nm);
            printf("Idade: ");
            printf("%d\n", cofre[i].id);
            printf("Altura: ");
            printf("%.2f\n", cofre[i].alt);
            printf("Peso: ");
            printf("%.2f\n", cofre[i].ps);
    }
    
    void listar() {
        if(pT == 0) {

            printf("Nao consta nenhum cadastro no sistema\n");
            printf("pressione enter para voltar ao menu");
            getchar();
            getchar();

        return;
        }
        for (int i = 0; i < pT; i++){

            printf("\n------------------------\n");
            menu(i);
            idade(i);
            imcc(i);
            printf("\n------------------------\n");
            getchar();
        }
    }