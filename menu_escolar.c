    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <windows.h>

        #define Max_Aluno 5
        #define Max_Disciplina 5
        #define Max_Notas 5
    
            typedef struct {
                    char disciplina[20];
                    double notas[Max_Notas];
                    float mediaNotas[Max_Disciplina];
            } disc;
                disc cofre1[Max_Disciplina];
                typedef struct {
                    char aluno[100];
                    char aprovado[100];
                disc disciplinas[Max_Aluno];
            } aluno;
                aluno cofre[Max_Aluno];
                
                float somaNotas = 0;
                int opAlunos = 0, alnTotais = 0, p = 0, opmain = 0, opaln =0, opdisc = 0, opnotas = 0, n = 0, disciplinasTotais = 0, ttnotas;
                char prof;
                
                
                void calcularmedias(int opAlunos, int opdisc){
                    float soma = 0;
                    for(int n = 0; n < Max_Notas; n++){
                        soma += cofre[opAlunos].disciplinas[opdisc].notas[n];
                }

                    cofre[opAlunos].disciplinas[opdisc].mediaNotas[opdisc] = soma / Max_Notas;
                }
                
                    void cadastroMateria(){
                            strcpy(cofre1[0].disciplina, "Matematica");
                            strcpy(cofre1[1].disciplina, "Historia");
                            strcpy(cofre1[2].disciplina, "Ciencias");
                            strcpy(cofre1[3].disciplina, "E.Fisica");
                            strcpy(cofre1[4].disciplina, "Portugues");
                            printf("Suas disciplinas sao: ");
                            printf("\n------------------------------------\n");
                        for (int i= 0; i < Max_Disciplina  ; i++ ){
                            printf("%d - %s\n", i+1, cofre1[i].disciplina);
                            disciplinasTotais++;
                            }
                            printf("------------------------------------\n");
                            while(getchar() != '\n');
                            printf("\ndisciplinas salvas\n");
                            printf("\npressione enter para entrar no menu de administrador");
                            getchar();
                
                    }
                    
                    
                    int verificacao (char n[]) { 

                        if(strlen (n) == 0){

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
                        if(alnTotais >= Max_Aluno){

                            system("cls");
                            printf("\nMaximo de alunos cadastradas!\n");;

                            return;
                        }

                        printf("Escreva o nome do seu aluno:\n");        

                        while(getchar() != '\n');          
                        
                        fgets(cofre[p].aluno, 50, stdin);  
                        cofre[p].aluno [strcspn (cofre[p].aluno, "\n") ] = '\0';
                        if(verificacao (cofre[p].aluno) == 0) return;                
                        alnTotais++;
                        p++;

                        return;
                        
                    }
                                        
                    void escAluno() {

                            printf("\nEscolha um aluno\n");                    
                            printf("1 - %s\n", cofre[0].aluno);
                            printf("2 - %s\n", cofre[1].aluno);
                            printf("3 - %s\n", cofre[2].aluno);
                            printf("4 - %s\n", cofre[3].aluno);
                            printf("5 - %s\n", cofre[4].aluno);
                            printf("9 - retornar ao menu\n");

                    }


                    void escdisc() {

                            printf("\nEscolha uma disciplina: \n");                    
                            printf("1 - %s\n", cofre1[0].disciplina);
                            printf("2 - %s\n", cofre1[1].disciplina);
                            printf("3 - %s\n", cofre1[2].disciplina);
                            printf("4 - %s\n", cofre1[3].disciplina);
                            printf("5 - %s\n", cofre1[4].disciplina);
                            printf("9 - retornar ao menu\n");
                    }
            
            
                    void cadastrarNotas(){
                        opAlunos = 0;
                        opdisc = 0;
                        if(alnTotais == 0){
                            
                            printf("Cadastre seus alunos\n");
                            printf("pressione enter para voltar\n");
                            getchar();
                            getchar();
                            return;
                        }
                        do{
                            system("cls");  
                            printf("\n=======================================\n");
                            escAluno();
                            printf("\n=======================================\n");
                            scanf("%d", &opAlunos);
                        
                        do{

                            system("cls");  
                            printf("\n=======================================\n");
                            escdisc();
                            printf("\n=======================================\n");
                            scanf("%d", &opdisc);
                        switch(opdisc){
                        
                        case 1:
                        
                            printf("\nNome do aluno: ");
                            printf("%s\n", cofre[opAlunos -1].aluno);                  
                            printf("cadastre as notas do aluno: \n");
                            for(int n = 0; n < Max_Notas; n++){
                                scanf("%lf", &cofre[opAlunos -1].disciplinas[opdisc -1].notas[n]);
                                ++ttnotas;                                                    
                        }
                                calcularmedias(opAlunos -1, opdisc -1);
                        break;

                        case 2:
                        
                            printf("\nNome do aluno: ");
                            printf("%s\n", cofre[opAlunos -1].aluno);                  
                            printf("cadastre as notas do aluno: \n");
                            for(int n = 0; n < Max_Notas; n++){
                                scanf("%lf", &cofre[opAlunos -1].disciplinas[opdisc -1].notas[n]);
                                ++ttnotas;
                            }
                                calcularmedias(opAlunos -1, opdisc -1);
                        break;
                        
                        case 3:
                        
                            printf("\nNome do aluno: ");
                            printf("%s\n", cofre[opAlunos -1].aluno);                  
                            printf("cadastre as notas do aluno: \n");
                            for(int n = 0; n < Max_Notas; n++){
                                scanf("%lf", &cofre[opAlunos -1].disciplinas[opdisc -1].notas[n]);
                                ++ttnotas;
                            }
                                calcularmedias(opAlunos -1, opdisc -1);
                        break;


                        case 4:
                        
                            printf("\nNome do aluno: ");
                            printf("%s\n", cofre[opAlunos - 1].aluno);                  
                            printf("cadastre as notas do aluno: \n");
                            for(int n = 0; n < Max_Notas; n++){
                                scanf("%lf", &cofre[opAlunos -1].disciplinas[opdisc -1].notas[n]);
                                ++ttnotas;  
                            }
                                calcularmedias(opAlunos -1, opdisc -1);
                        break;

                        case 5:
                        
                            printf("\nNome do aluno: ");
                            printf("%s\n", cofre[opAlunos - 1].aluno);                  
                            printf("cadastre as notas do aluno: \n");
                            for(int n = 0; n < Max_Notas; n++){
                                scanf("%lf", &cofre[opAlunos -1].disciplinas[opdisc -1].notas[n]);
                                ++ttnotas;
                            } 

                                calcularmedias(opAlunos -1, opdisc -1);
                        break;

                        case 9:
                        break;

                            default:
                                system("cls");
                                printf("\nescolha uma opcao valida\n");
                                printf("pressione enter para tentar novamente");
                                getchar();
                                getchar();
                                }                      
                            }while(opdisc != 9);
                        }while(opAlunos != 9);
                        }


                        void notas(){
                            if(alnTotais == 0){
                            
                            printf("Cadastre seus alunos\n");
                            printf("pressione enter para voltar\n");
                            getchar();
                            getchar();
                            return;
                        }
                        do{
                            system("cls");  
                            printf("\n=======================================\n");
                            printf("\nEscolha uma disciplina\n");
                            escdisc();
                            printf("\n=======================================\n");
                            scanf("%d", &opdisc);
                        

                        switch(opdisc){

                            case 1:
                            printf("alunos");
                        for(int u = 0; u < alnTotais; u++){
                            printf("Nome do aluno");
                            printf("%s\n", cofre[u].aluno);                  
                        for(int n = 0; n < Max_Notas; n++){
                            printf("Nota %d: %.2f\n", n+1, cofre[u].disciplinas[opdisc -1].notas[n]);
                            }
                        }
                            getchar();
                            
                        break;

                            case 2:
                            printf("alunos");
                        for(int u = 0; u < alnTotais; u++){
                            printf("Nome do aluno");
                            printf("%s\n", cofre[u].aluno);                  
                        for(int n = 0; n < Max_Notas; n++){
                            printf("Nota %d: %.2lf\n", n+1, cofre[u].disciplinas[opdisc -1].notas[n]);
                            }
                        }
                            getchar();
                            
                        break;

                            case 3:
                            printf("alunos");
                        for(int u = 0; u < alnTotais; u++){
                            printf("Nome do aluno");
                            printf("%s\n", cofre[u].aluno);                  
                        for(int n = 0; n < Max_Notas; n++){
                            printf("Nota %d: %.2lf\n", n+1, cofre[u].disciplinas[opdisc -1].notas[n]);
                            }
                        }
                            getchar();

                        break;

                            case 4:
                            printf("alunos");
                        for(int u = 0; u < alnTotais; u++){
                            printf("Nome do aluno");
                            printf("%s\n", cofre[u].aluno);                  
                        for(int n = 0; n < Max_Notas; n++){
                            printf("Nota %d: %.2lf\n", n+1, cofre[u].disciplinas[opdisc -1].notas[n]);
                            }
                        }
                            getchar();

                        break;
                            case 5:
                            printf("alunos");
                        for(int u = 0; u < alnTotais; u++){
                            printf("Nome do aluno");
                            printf("%s\n", cofre[u].aluno);                  
                        for(int n = 0; n < Max_Notas; n++){
                            printf("Nota %d: %.2lf\n", n+1, cofre[u].disciplinas[opdisc -1].notas[n]);
                            }
                        }
                            getchar();
                        break;

                        case 9:

                            printf("\nEncerrando a visualização de notas");
                            getchar();

                        break;


                        default:
                            
                            printf("\nSelecione uma opcao valida!");
                            printf("\npressione enter para tentar novamente");
                            getchar();
                            getchar();


                            }
                        
                        }                
                        while(opdisc != 9);
                        }


                        void menu (int i) {

                            printf("Nome da aluno: ");                    
                            printf("%s\n", cofre[i].aluno);
                            
                        }
                        void listar() {
                            if(alnTotais == 0) {

                            printf("Nao consta nenhum cadastro no sistema\n");
                            printf("pressione enter para voltar ao menu");
                            getchar();
                            getchar();

                        return;
                        }
                        for (int i = 0; i < alnTotais; i++){

                            printf("\n------------------------\n");
                            menu(i);
                            printf("\n------------------------\n");
                            getchar();
                        }
                        }
                        void listarNotas() {
                        if(alnTotais == 0) {

                            printf("Nao consta nenhum cadastro no sistema\n");
                            printf("pressione enter para voltar ao menu");
                            getchar();
                            getchar();

                        return;                        
                        }
                            printf("\n------------------------\n");
                            notas();
                            printf("\n------------------------\n");
                        }

                int main() {


                    SetConsoleOutputCP(CP_UTF8);

                    printf("Bem vindo");
                    printf("\n Cadastre seu nome de administrador: \n");
                    scanf("%s", &prof);
                    cadastroMateria();
                    do {

                    system("cls");
                    printf("Escolha uma opcao: \n");
                    printf("--Total de alunos: %d--", p);
                    printf("\n--Total de disciplinas: %d--", disciplinasTotais);
                    printf("\n------------------------\n");
                    printf("1 - Cadastrar um aluno: \n");
                    printf("2 - Liste as alunos cadastrados: \n");
                    printf("3 - Para cadastrar notas \n");
                    printf("4 - Para mostrar resultados de alunos\n");
                    printf("9 - Para sair do sistema\n");
                    scanf("%d", &opmain);
                        
                        switch(opmain) {
                        
                            case 1:

                                system("cls");
                                cadastrar ();
                                getchar();

                                break;

                            case 2:

                                system("cls");
                                listar();

                                break;

                            case 3:

                                system("cls");
                                cadastrarNotas();

                                break;

                            case 4:
                                
                                system("cls");
                                listarNotas();

                                break;

                            case 9:
                            
                                break;
                            
                            default:

                                system("cls");
                                printf("\nSelecione uma opcao valida\n");

                                break;
                        }
                }while(opmain != 9);
                
                system("cls");  
                printf("encerrando programa\n");
                printf("pressione entrer para sair\n");
                getchar();
                getchar();

                return 0;

                }