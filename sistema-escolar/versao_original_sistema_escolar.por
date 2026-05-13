programa
{
    funcao real lerNota(cadeia mensagem)
    {
        real nota
        // Le a nota informada pelo usuario.
        escreva(mensagem)
        leia(nota)

        // Valida a entrada para aceitar apenas notas entre 0 e 10.
        enquanto (nota < 0 ou nota > 10)
        {
            escreva("Nota invalida. Nem inventando, a nota tem que ser entre 0 e 10: ")
            leia(nota)
        }

        retorne nota
    }

    funcao cadeia lerNome(cadeia mensagem)
    {
        cadeia nome
        // Le o nome informado pelo usuario.
        escreva(mensagem)
        leia(nome)

        // Valida a entrada para impedir nomes vazios.
        enquanto (nome == "")
        {
            escreva("Nome invalido. Vamos fingir seriedade e digitar direito: ")
            leia(nome)
        }

        retorne nome
    }

    // Essa funcao existe pra eu nao ter que repetir a mesma comparacao mil vezes, apesar de a vida claramente querer isso.
    funcao cadeia situacaoMateria(real mediaFinal)
    {
        se (mediaFinal >= 7)
        {
            retorne "Aprovado"
        }
        senao
        {
            retorne "Reprovado"
        }
    }

    funcao confirmarVoltaMenu()
    {
        inteiro confirmar

        escreva("\nDigite 0 para voltar ao menu principal: ")
        leia(confirmar)

        enquanto (confirmar != 0)
        {
            escreva("Valor invalido. Digite 0 para voltar ao menu principal: ")
            leia(confirmar)
        }
    }

    funcao inicio()
    {

        // CADASTRO DOS ALUNOS
        // Porque o sistema infelizmente nao le mentes.

        cadeia aluno1, aluno2, aluno3, aluno4, aluno5
        // Cinco alunos porque sofrer com poucos dados seria facil demais
        // DECLARACAO DAS VARIAVEIS DE NOTAS E MEDIAS
        // Sim, e um monte de variavel A vida nao quis ser minimalista
        // a corresponde a aluno, a segunda letra é a inicial da materia e os numeros correspondem se e o primeiro aluno ou nota da materia
        // Assim como usando a1pm é media a1pf é a nota final
        // Aluno 1
        real a1p1, a1p2, a1p3, a1pm, a1pr, a1pf
        real a1m1, a1m2, a1m3, a1mm, a1mr, a1mf
        real a1c1, a1c2, a1c3, a1cm, a1cr, a1cf
        real a1h1, a1h2, a1h3, a1hm, a1hr, a1hf
        real a1e1, a1e2, a1e3, a1em, a1er, a1ef

        // Aluno 2
        real a2p1, a2p2, a2p3, a2pm, a2pr, a2pf
        real a2m1, a2m2, a2m3, a2mm, a2mr, a2mf
        real a2c1, a2c2, a2c3, a2cm, a2cr, a2cf
        real a2h1, a2h2, a2h3, a2hm, a2hr, a2hf
        real a2e1, a2e2, a2e3, a2em, a2er, a2ef

        // Aluno 3
        real a3p1, a3p2, a3p3, a3pm, a3pr, a3pf
        real a3m1, a3m2, a3m3, a3mm, a3mr, a3mf
        real a3c1, a3c2, a3c3, a3cm, a3cr, a3cf
        real a3h1, a3h2, a3h3, a3hm, a3hr, a3hf
        real a3e1, a3e2, a3e3, a3em, a3er, a3ef

        // Aluno 4
        real a4p1, a4p2, a4p3, a4pm, a4pr, a4pf
        real a4m1, a4m2, a4m3, a4mm, a4mr, a4mf
        real a4c1, a4c2, a4c3, a4cm, a4cr, a4cf
        real a4h1, a4h2, a4h3, a4hm, a4hr, a4hf
        real a4e1, a4e2, a4e3, a4em, a4er, a4ef

        // Aluno 5
        real a5p1, a5p2, a5p3, a5pm, a5pr, a5pf
        real a5m1, a5m2, a5m3, a5mm, a5mr, a5mf
        real a5c1, a5c2, a5c3, a5cm, a5cr, a5cf
        real a5h1, a5h2, a5h3, a5hm, a5hr, a5hf
        real a5e1, a5e2, a5e3, a5em, a5er, a5ef

        // Aqui eu guardo as situacoes, porque nao basta calcular nota, ainda tem que organizar a tragedia
        cadeia s1p, s1m, s1c, s1h, s1e, s1ano
        cadeia s2p, s2m, s2c, s2h, s2e, s2ano
        cadeia s3p, s3m, s3c, s3h, s3e, s3ano
        cadeia s4p, s4m, s4c, s4h, s4e, s4ano
        cadeia s5p, s5m, s5c, s5h, s5e, s5ano

        real mediaGeral1, mediaGeral2, mediaGeral3, mediaGeral4, mediaGeral5
        real mediaTurmaPortugues, mediaTurmaMatematica, mediaTurmaCiencias, mediaTurmaHistoria, mediaTurmaEdFisica
        real mediaGeralTurma, maiorMediaGeral, menorMediaGeral
        inteiro totalAprovadosAno, totalReprovadosAno
        cadeia melhorAluno, piorAluno
        cadeia nomeConsulta

        inteiro opcao
        // Variavel do menu, tambem conhecida como ponto onde tudo pode dar errado dependendo do dedo da pessoa
        logico alunosCadastrados, notasLancadas // Regitrar aqui professor a minha insatisfação de não ter conseguido usar vetor pra isso que tipo assim deve ter papo de 200 variaveis aqui eu nao aguento mais
        inteiro opcaoMateria, opcaoAluno 
        logico a1pOk, a1mOk, a1cOk, a1hOk, a1eOk
        logico a2pOk, a2mOk, a2cOk, a2hOk, a2eOk
        logico a3pOk, a3mOk, a3cOk, a3hOk, a3eOk
        logico a4pOk, a4mOk, a4cOk, a4hOk, a4eOk
        logico a5pOk, a5mOk, a5cOk, a5hOk, a5eOk


        opcao = -1
        alunosCadastrados = falso
        notasLancadas = falso
        opcaoMateria = -1
        opcaoAluno = -1
      // ex: a1p0k só serve pra validar se foi alunos e notas foram cadastrados!
        a1pOk = falso
        a1mOk = falso
        a1cOk = falso
        a1hOk = falso
        a1eOk = falso

        a2pOk = falso
        a2mOk = falso
        a2cOk = falso
        a2hOk = falso
        a2eOk = falso

        a3pOk = falso
        a3mOk = falso
        a3cOk = falso
        a3hOk = falso
        a3eOk = falso

        a4pOk = falso
        a4mOk = falso
        a4cOk = falso
        a4hOk = falso
        a4eOk = falso

        a5pOk = falso
        a5mOk = falso
        a5cOk = falso
        a5hOk = falso
        a5eOk = falso


        enquanto (opcao != 0)
        {
            escreva("ESCOLA DOS ETERNOS PROTAGONISTAS\n")
            escreva("1 - Cadastrar alunos\n")
            escreva("2 - Lancar notas por materia e aluno\n")
            escreva("3 - Consultar notas de um aluno\n")
            escreva("4 - Mostrar relatorio final\n")
            escreva("5 - Mostrar desempenho por materia\n")
            escreva("6 - Mostrar estatisticas gerais\n")
            escreva("0 - Sair\n")
            escreva("Digite uma opcao: ")
            leia(opcao)

            escolha (opcao)
            {
                caso 1:
                    escreva("\nCADASTRO DOS ALUNOS\n")
                    aluno1 = lerNome("Digite o nome do 1o aluno: ")
                    aluno2 = lerNome("Digite o nome do 2o aluno: ")
                    aluno3 = lerNome("Digite o nome do 3o aluno: ")
                    aluno4 = lerNome("Digite o nome do 4o aluno: ")
                    aluno5 = lerNome("Digite o nome do 5o aluno: ")

                    alunosCadastrados = verdadeiro
                    notasLancadas = falso

                    a1pOk = falso
                    a1mOk = falso
                    a1cOk = falso
                    a1hOk = falso
                    a1eOk = falso

                    a2pOk = falso
                    a2mOk = falso
                    a2cOk = falso
                    a2hOk = falso
                    a2eOk = falso

                    a3pOk = falso
                    a3mOk = falso
                    a3cOk = falso
                    a3hOk = falso
                    a3eOk = falso

                    a4pOk = falso
                    a4mOk = falso
                    a4cOk = falso
                    a4hOk = falso
                    a4eOk = falso

                    a5pOk = falso
                    a5mOk = falso
                    a5cOk = falso
                    a5hOk = falso
                    a5eOk = falso

                    escreva("\nAlunos cadastrados com sucesso!\n")
                    pare

                caso 2:
                    se (alunosCadastrados == falso)
                    {
                        escreva("\nPrimeiro use a opcao 1 para cadastrar os alunos.\n")
                    }
                    senao
                    {
                        opcaoMateria = -1

                        enquanto (opcaoMateria != 0)
                        {
                            escreva("\nCADASTRO DE NOTAS\n")
                            escreva("1 - Portugues\n")
                            escreva("2 - Matematica\n")
                            escreva("3 - Ciencias\n")
                            escreva("4 - Historia\n")
                            escreva("5 - Educacao Fisica\n")
                            escreva("0 - Voltar ao menu principal\n")
                            escreva("Escolha a materia: ")
                            leia(opcaoMateria)

                            se (opcaoMateria != 0)
                            {
                                escreva("\nEscolha o aluno:\n")
                                escreva("1 - ", aluno1, "\n")
                                escreva("2 - ", aluno2, "\n")
                                escreva("3 - ", aluno3, "\n")
                                escreva("4 - ", aluno4, "\n")
                                escreva("5 - ", aluno5, "\n")
                                escreva("Digite o numero do aluno: ")
                                leia(opcaoAluno)

                                escolha (opcaoMateria)
                                {
                                caso 1:
                                    escolha (opcaoAluno)
                                    {
                                    caso 1:
                                        escreva("\nLANCANDO PORTUGUES PARA ", aluno1, "\n")
                                        a1p1 = lerNota("Portugues - 1a nota: ")
                                        a1p2 = lerNota("Portugues - 2a nota: ")
                                        a1p3 = lerNota("Portugues - 3a nota: ")
                                        a1pm = (a1p1 * 2 + a1p2 * 3 + a1p3 * 5) / 10
                                        se (a1pm < 7)
                                        {
                                            a1pr = lerNota("Recuperacao de Portugues: ")
                                            se (a1pr >= 6)
                                            {
                                                a1pf = 7
                                            }
                                            senao
                                            {
                                                a1pf = a1pm
                                            }
                                        }
                                        senao
                                        {
                                            a1pf = a1pm
                                        }
                                        a1pOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno1, " em Portugues.\n")
                                        pare
                                    caso 2:
                                        escreva("\nLANCANDO PORTUGUES PARA ", aluno2, "\n")
                                        a2p1 = lerNota("Portugues - 1a nota: ")
                                        a2p2 = lerNota("Portugues - 2a nota: ")
                                        a2p3 = lerNota("Portugues - 3a nota: ")
                                        a2pm = (a2p1 * 2 + a2p2 * 3 + a2p3 * 5) / 10
                                        se (a2pm < 7)
                                        {
                                            a2pr = lerNota("Recuperacao de Portugues: ")
                                            se (a2pr >= 6)
                                            {
                                                a2pf = 7
                                            }
                                            senao
                                            {
                                                a2pf = a2pm
                                            }
                                        }
                                        senao
                                        {
                                            a2pf = a2pm
                                        }
                                        a2pOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno2, " em Portugues.\n")
                                        pare
                                    caso 3:
                                        escreva("\nLANCANDO PORTUGUES PARA ", aluno3, "\n")
                                        a3p1 = lerNota("Portugues - 1a nota: ")
                                        a3p2 = lerNota("Portugues - 2a nota: ")
                                        a3p3 = lerNota("Portugues - 3a nota: ")
                                        a3pm = (a3p1 * 2 + a3p2 * 3 + a3p3 * 5) / 10
                                        se (a3pm < 7)
                                        {
                                            a3pr = lerNota("Recuperacao de Portugues: ")
                                            se (a3pr >= 6)
                                            {
                                                a3pf = 7
                                            }
                                            senao
                                            {
                                                a3pf = a3pm
                                            }
                                        }
                                        senao
                                        {
                                            a3pf = a3pm
                                        }
                                        a3pOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno3, " em Portugues.\n")
                                        pare
                                    caso 4:
                                        escreva("\nLANCANDO PORTUGUES PARA ", aluno4, "\n")
                                        a4p1 = lerNota("Portugues - 1a nota: ")
                                        a4p2 = lerNota("Portugues - 2a nota: ")
                                        a4p3 = lerNota("Portugues - 3a nota: ")
                                        a4pm = (a4p1 * 2 + a4p2 * 3 + a4p3 * 5) / 10
                                        se (a4pm < 7)
                                        {
                                            a4pr = lerNota("Recuperacao de Portugues: ")
                                            se (a4pr >= 6)
                                            {
                                                a4pf = 7
                                            }
                                            senao
                                            {
                                                a4pf = a4pm
                                            }
                                        }
                                        senao
                                        {
                                            a4pf = a4pm
                                        }
                                        a4pOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno4, " em Portugues.\n")
                                        pare
                                    caso 5:
                                        escreva("\nLANCANDO PORTUGUES PARA ", aluno5, "\n")
                                        a5p1 = lerNota("Portugues - 1a nota: ")
                                        a5p2 = lerNota("Portugues - 2a nota: ")
                                        a5p3 = lerNota("Portugues - 3a nota: ")
                                        a5pm = (a5p1 * 2 + a5p2 * 3 + a5p3 * 5) / 10
                                        se (a5pm < 7)
                                        {
                                            a5pr = lerNota("Recuperacao de Portugues: ")
                                            se (a5pr >= 6)
                                            {
                                                a5pf = 7
                                            }
                                            senao
                                            {
                                                a5pf = a5pm
                                            }
                                        }
                                        senao
                                        {
                                            a5pf = a5pm
                                        }
                                        a5pOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno5, " em Portugues.\n")
                                        pare
                                    caso contrario:
                                        escreva("\nAluno invalido.\n")
                                        pare
                                    }
                                    pare
                                caso 2:
                                    escolha (opcaoAluno)
                                    {
                                    caso 1:
                                        escreva("\nLANCANDO MATEMATICA PARA ", aluno1, "\n")
                                        a1m1 = lerNota("Matematica - 1a nota: ")
                                        a1m2 = lerNota("Matematica - 2a nota: ")
                                        a1m3 = lerNota("Matematica - 3a nota: ")
                                        a1mm = (a1m1 * 2 + a1m2 * 3 + a1m3 * 5) / 10
                                        se (a1mm < 7)
                                        {
                                            a1mr = lerNota("Recuperacao de Matematica: ")
                                            se (a1mr >= 6)
                                            {
                                                a1mf = 7
                                            }
                                            senao
                                            {
                                                a1mf = a1mm
                                            }
                                        }
                                        senao
                                        {
                                            a1mf = a1mm
                                        }
                                        a1mOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno1, " em Matematica.\n")
                                        pare
                                    caso 2:
                                        escreva("\nLANCANDO MATEMATICA PARA ", aluno2, "\n")
                                        a2m1 = lerNota("Matematica - 1a nota: ")
                                        a2m2 = lerNota("Matematica - 2a nota: ")
                                        a2m3 = lerNota("Matematica - 3a nota: ")
                                        a2mm = (a2m1 * 2 + a2m2 * 3 + a2m3 * 5) / 10
                                        se (a2mm < 7)
                                        {
                                            a2mr = lerNota("Recuperacao de Matematica: ")
                                            se (a2mr >= 6)
                                            {
                                                a2mf = 7
                                            }
                                            senao
                                            {
                                                a2mf = a2mm
                                            }
                                        }
                                        senao
                                        {
                                            a2mf = a2mm
                                        }
                                        a2mOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno2, " em Matematica.\n")
                                        pare
                                    caso 3:
                                        escreva("\nLANCANDO MATEMATICA PARA ", aluno3, "\n")
                                        a3m1 = lerNota("Matematica - 1a nota: ")
                                        a3m2 = lerNota("Matematica - 2a nota: ")
                                        a3m3 = lerNota("Matematica - 3a nota: ")
                                        a3mm = (a3m1 * 2 + a3m2 * 3 + a3m3 * 5) / 10
                                        se (a3mm < 7)
                                        {
                                            a3mr = lerNota("Recuperacao de Matematica: ")
                                            se (a3mr >= 6)
                                            {
                                                a3mf = 7
                                            }
                                            senao
                                            {
                                                a3mf = a3mm
                                            }
                                        }
                                        senao
                                        {
                                            a3mf = a3mm
                                        }
                                        a3mOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno3, " em Matematica.\n")
                                        pare
                                    caso 4:
                                        escreva("\nLANCANDO MATEMATICA PARA ", aluno4, "\n")
                                        a4m1 = lerNota("Matematica - 1a nota: ")
                                        a4m2 = lerNota("Matematica - 2a nota: ")
                                        a4m3 = lerNota("Matematica - 3a nota: ")
                                        a4mm = (a4m1 * 2 + a4m2 * 3 + a4m3 * 5) / 10
                                        se (a4mm < 7)
                                        {
                                            a4mr = lerNota("Recuperacao de Matematica: ")
                                            se (a4mr >= 6)
                                            {
                                                a4mf = 7
                                            }
                                            senao
                                            {
                                                a4mf = a4mm
                                            }
                                        }
                                        senao
                                        {
                                            a4mf = a4mm
                                        }
                                        a4mOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno4, " em Matematica.\n")
                                        pare
                                    caso 5:
                                        escreva("\nLANCANDO MATEMATICA PARA ", aluno5, "\n")
                                        a5m1 = lerNota("Matematica - 1a nota: ")
                                        a5m2 = lerNota("Matematica - 2a nota: ")
                                        a5m3 = lerNota("Matematica - 3a nota: ")
                                        a5mm = (a5m1 * 2 + a5m2 * 3 + a5m3 * 5) / 10
                                        se (a5mm < 7)
                                        {
                                            a5mr = lerNota("Recuperacao de Matematica: ")
                                            se (a5mr >= 6)
                                            {
                                                a5mf = 7
                                            }
                                            senao
                                            {
                                                a5mf = a5mm
                                            }
                                        }
                                        senao
                                        {
                                            a5mf = a5mm
                                        }
                                        a5mOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno5, " em Matematica.\n")
                                        pare
                                    caso contrario:
                                        escreva("\nAluno invalido.\n")
                                        pare
                                    }
                                    pare
                                caso 3:
                                    escolha (opcaoAluno)
                                    {
                                    caso 1:
                                        escreva("\nLANCANDO CIENCIAS PARA ", aluno1, "\n")
                                        a1c1 = lerNota("Ciencias - 1a nota: ")
                                        a1c2 = lerNota("Ciencias - 2a nota: ")
                                        a1c3 = lerNota("Ciencias - 3a nota: ")
                                        a1cm = (a1c1 * 2 + a1c2 * 3 + a1c3 * 5) / 10
                                        se (a1cm < 7)
                                        {
                                            a1cr = lerNota("Recuperacao de Ciencias: ")
                                            se (a1cr >= 6)
                                            {
                                                a1cf = 7
                                            }
                                            senao
                                            {
                                                a1cf = a1cm
                                            }
                                        }
                                        senao
                                        {
                                            a1cf = a1cm
                                        }
                                        a1cOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno1, " em Ciencias.\n")
                                        pare
                                    caso 2:
                                        escreva("\nLANCANDO CIENCIAS PARA ", aluno2, "\n")
                                        a2c1 = lerNota("Ciencias - 1a nota: ")
                                        a2c2 = lerNota("Ciencias - 2a nota: ")
                                        a2c3 = lerNota("Ciencias - 3a nota: ")
                                        a2cm = (a2c1 * 2 + a2c2 * 3 + a2c3 * 5) / 10
                                        se (a2cm < 7)
                                        {
                                            a2cr = lerNota("Recuperacao de Ciencias: ")
                                            se (a2cr >= 6)
                                            {
                                                a2cf = 7
                                            }
                                            senao
                                            {
                                                a2cf = a2cm
                                            }// To com dores no braco de tanto digitar
                                        }
                                        senao
                                        {
                                            a2cf = a2cm
                                        }
                                        a2cOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno2, " em Ciencias.\n")
                                        pare
                                    caso 3:
                                        escreva("\nLANCANDO CIENCIAS PARA ", aluno3, "\n")
                                        a3c1 = lerNota("Ciencias - 1a nota: ")
                                        a3c2 = lerNota("Ciencias - 2a nota: ")
                                        a3c3 = lerNota("Ciencias - 3a nota: ")
                                        a3cm = (a3c1 * 2 + a3c2 * 3 + a3c3 * 5) / 10
                                        se (a3cm < 7)
                                        {
                                            a3cr = lerNota("Recuperacao de Ciencias: ")
                                            se (a3cr >= 6)
                                            {
                                                a3cf = 7
                                            }
                                            senao
                                            {
                                                a3cf = a3cm
                                            }
                                        }
                                        senao
                                        {
                                            a3cf = a3cm
                                        }
                                        a3cOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno3, " em Ciencias.\n")
                                        pare
                                    caso 4:
                                        escreva("\nLANCANDO CIENCIAS PARA ", aluno4, "\n")
                                        a4c1 = lerNota("Ciencias - 1a nota: ")
                                        a4c2 = lerNota("Ciencias - 2a nota: ")
                                        a4c3 = lerNota("Ciencias - 3a nota: ")
                                        a4cm = (a4c1 * 2 + a4c2 * 3 + a4c3 * 5) / 10
                                        se (a4cm < 7)
                                        {
                                            a4cr = lerNota("Recuperacao de Ciencias: ")
                                            se (a4cr >= 6)
                                            {
                                                a4cf = 7
                                            }
                                            senao
                                            {
                                                a4cf = a4cm
                                            }
                                        }
                                        senao
                                        {
                                            a4cf = a4cm
                                        }
                                        a4cOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno4, " em Ciencias.\n")
                                        pare
                                    caso 5:
                                        escreva("\nLANCANDO CIENCIAS PARA ", aluno5, "\n")
                                        a5c1 = lerNota("Ciencias - 1a nota: ")
                                        a5c2 = lerNota("Ciencias - 2a nota: ")
                                        a5c3 = lerNota("Ciencias - 3a nota: ")
                                        a5cm = (a5c1 * 2 + a5c2 * 3 + a5c3 * 5) / 10
                                        se (a5cm < 7)
                                        {
                                            a5cr = lerNota("Recuperacao de Ciencias: ")
                                            se (a5cr >= 6)
                                            {
                                                a5cf = 7
                                            }
                                            senao
                                            {
                                                a5cf = a5cm
                                            }
                                        }
                                        senao
                                        {
                                            a5cf = a5cm
                                        }
                                        a5cOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno5, " em Ciencias.\n")
                                        pare
                                    caso contrario:
                                        escreva("\nAluno invalido.\n")
                                        pare
                                    }
                                    pare
                                caso 4:
                                    escolha (opcaoAluno)
                                    {
                                    caso 1:
                                        escreva("\nLANCANDO HISTORIA PARA ", aluno1, "\n")
                                        a1h1 = lerNota("Historia - 1a nota: ")
                                        a1h2 = lerNota("Historia - 2a nota: ")
                                        a1h3 = lerNota("Historia - 3a nota: ")
                                        a1hm = (a1h1 * 2 + a1h2 * 3 + a1h3 * 5) / 10
                                        se (a1hm < 7)
                                        {
                                            a1hr = lerNota("Recuperacao de Historia: ")
                                            se (a1hr >= 6)
                                            {
                                                a1hf = 7
                                            }
                                            senao
                                            {
                                                a1hf = a1hm
                                            }
                                        }
                                        senao
                                        {
                                            a1hf = a1hm
                                        }
                                        a1hOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno1, " em Historia.\n")
                                        pare
                                    caso 2:
                                        escreva("\nLANCANDO HISTORIA PARA ", aluno2, "\n")
                                        a2h1 = lerNota("Historia - 1a nota: ")
                                        a2h2 = lerNota("Historia - 2a nota: ")
                                        a2h3 = lerNota("Historia - 3a nota: ")
                                        a2hm = (a2h1 * 2 + a2h2 * 3 + a2h3 * 5) / 10
                                        se (a2hm < 7)
                                        {
                                            a2hr = lerNota("Recuperacao de Historia: ")
                                            se (a2hr >= 6)
                                            {
                                                a2hf = 7
                                            }
                                            senao
                                            {
                                                a2hf = a2hm
                                            }
                                        }
                                        senao
                                        {
                                            a2hf = a2hm
                                        }
                                        a2hOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno2, " em Historia.\n")
                                        pare
                                    caso 3:
                                        escreva("\nLANCANDO HISTORIA PARA ", aluno3, "\n")
                                        a3h1 = lerNota("Historia - 1a nota: ")
                                        a3h2 = lerNota("Historia - 2a nota: ")
                                        a3h3 = lerNota("Historia - 3a nota: ")
                                        a3hm = (a3h1 * 2 + a3h2 * 3 + a3h3 * 5) / 10
                                        se (a3hm < 7)
                                        {
                                            a3hr = lerNota("Recuperacao de Historia: ")
                                            se (a3hr >= 6)
                                            {
                                                a3hf = 7
                                            }
                                            senao
                                            {
                                                a3hf = a3hm
                                            }
                                        }
                                        senao
                                        {
                                            a3hf = a3hm
                                        }
                                        a3hOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno3, " em Historia.\n")
                                        pare
                                    caso 4:
                                        escreva("\nLANCANDO HISTORIA PARA ", aluno4, "\n")
                                        a4h1 = lerNota("Historia - 1a nota: ")
                                        a4h2 = lerNota("Historia - 2a nota: ")
                                        a4h3 = lerNota("Historia - 3a nota: ")
                                        a4hm = (a4h1 * 2 + a4h2 * 3 + a4h3 * 5) / 10
                                        se (a4hm < 7)
                                        {
                                            a4hr = lerNota("Recuperacao de Historia: ")
                                            se (a4hr >= 6)
                                            {
                                                a4hf = 7
                                            }
                                            senao
                                            {
                                                a4hf = a4hm
                                            }
                                        }
                                        senao
                                        {
                                            a4hf = a4hm
                                        }
                                        a4hOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno4, " em Historia.\n")
                                        pare
                                    caso 5:
                                        escreva("\nLANCANDO HISTORIA PARA ", aluno5, "\n")
                                        a5h1 = lerNota("Historia - 1a nota: ")
                                        a5h2 = lerNota("Historia - 2a nota: ")
                                        a5h3 = lerNota("Historia - 3a nota: ")
                                        a5hm = (a5h1 * 2 + a5h2 * 3 + a5h3 * 5) / 10
                                        se (a5hm < 7)
                                        {
                                            a5hr = lerNota("Recuperacao de Historia: ")
                                            se (a5hr >= 6)
                                            {
                                                a5hf = 7
                                            }
                                            senao
                                            {
                                                a5hf = a5hm
                                            }
                                        }
                                        senao
                                        {
                                            a5hf = a5hm
                                        }
                                        a5hOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno5, " em Historia.\n")
                                        pare
                                    caso contrario:
                                        escreva("\nAluno invalido.\n")
                                        pare
                                    }
                                    pare
                                caso 5:
                                    escolha (opcaoAluno)
                                    {
                                    caso 1:
                                        escreva("\nLANCANDO EDUCACAO FISICA PARA ", aluno1, "\n")
                                        a1e1 = lerNota("Educacao Fisica - 1a nota: ")
                                        a1e2 = lerNota("Educacao Fisica - 2a nota: ")
                                        a1e3 = lerNota("Educacao Fisica - 3a nota: ")
                                        a1em = (a1e1 * 2 + a1e2 * 3 + a1e3 * 5) / 10
                                        se (a1em < 7)
                                        {
                                            a1er = lerNota("Recuperacao de Educacao Fisica: ")
                                            se (a1er >= 6)
                                            {
                                                a1ef = 7
                                            }
                                            senao
                                            {
                                                a1ef = a1em
                                            }
                                        }
                                        senao
                                        {
                                            a1ef = a1em
                                        }
                                        a1eOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno1, " em Educacao Fisica.\n")
                                        pare
                                    caso 2:
                                        escreva("\nLANCANDO EDUCACAO FISICA PARA ", aluno2, "\n")
                                        a2e1 = lerNota("Educacao Fisica - 1a nota: ")
                                        a2e2 = lerNota("Educacao Fisica - 2a nota: ")
                                        a2e3 = lerNota("Educacao Fisica - 3a nota: ")
                                        a2em = (a2e1 * 2 + a2e2 * 3 + a2e3 * 5) / 10
                                        se (a2em < 7)
                                        {
                                            a2er = lerNota("Recuperacao de Educacao Fisica: ")
                                            se (a2er >= 6)
                                            {
                                                a2ef = 7
                                            }
                                            senao
                                            {
                                                a2ef = a2em
                                            }
                                        }
                                        senao
                                        {
                                            a2ef = a2em
                                        }
                                        a2eOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno2, " em Educacao Fisica.\n")
                                        pare
                                    caso 3:
                                        escreva("\nLANCANDO EDUCACAO FISICA PARA ", aluno3, "\n")
                                        a3e1 = lerNota("Educacao Fisica - 1a nota: ")
                                        a3e2 = lerNota("Educacao Fisica - 2a nota: ")
                                        a3e3 = lerNota("Educacao Fisica - 3a nota: ")
                                        a3em = (a3e1 * 2 + a3e2 * 3 + a3e3 * 5) / 10
                                        se (a3em < 7)
                                        {
                                            a3er = lerNota("Recuperacao de Educacao Fisica: ")
                                            se (a3er >= 6)
                                            {
                                                a3ef = 7
                                            }
                                            senao
                                            {
                                                a3ef = a3em
                                            }
                                        }
                                        senao
                                        {
                                            a3ef = a3em
                                        }
                                        a3eOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno3, " em Educacao Fisica.\n")
                                        pare
                                    caso 4:
                                        escreva("\nLANCANDO EDUCACAO FISICA PARA ", aluno4, "\n")
                                        a4e1 = lerNota("Educacao Fisica - 1a nota: ")
                                        a4e2 = lerNota("Educacao Fisica - 2a nota: ")
                                        a4e3 = lerNota("Educacao Fisica - 3a nota: ")
                                        a4em = (a4e1 * 2 + a4e2 * 3 + a4e3 * 5) / 10
                                        se (a4em < 7)
                                        {
                                            a4er = lerNota("Recuperacao de Educacao Fisica: ")
                                            se (a4er >= 6)
                                            {
                                                a4ef = 7
                                            }
                                            senao
                                            {
                                                a4ef = a4em
                                            }
                                        }
                                        senao
                                        {
                                            a4ef = a4em
                                        }
                                        a4eOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno4, " em Educacao Fisica.\n")
                                        pare
                                    caso 5:
                                        escreva("\nLANCANDO EDUCACAO FISICA PARA ", aluno5, "\n")
                                        a5e1 = lerNota("Educacao Fisica - 1a nota: ")
                                        a5e2 = lerNota("Educacao Fisica - 2a nota: ")
                                        a5e3 = lerNota("Educacao Fisica - 3a nota: ")
                                        a5em = (a5e1 * 2 + a5e2 * 3 + a5e3 * 5) / 10
                                        se (a5em < 7)
                                        {
                                            a5er = lerNota("Recuperacao de Educacao Fisica: ")
                                            se (a5er >= 6)
                                            {
                                                a5ef = 7
                                            }
                                            senao
                                            {
                                                a5ef = a5em
                                            }
                                        }
                                        senao
                                        {
                                            a5ef = a5em
                                        }
                                        a5eOk = verdadeiro
                                        escreva("\nNotas salvas com sucesso para ", aluno5, " em Educacao Fisica.\n")
                                        pare
                                    caso contrario:
                                        escreva("\nAluno invalido.\n")
                                        pare
                                    }
                                    pare
                                caso contrario:
                                    escreva("\nMateria invalida.\n")
                                    pare
                                }
                            }
                        }


                        se (a1pOk e a1mOk e a1cOk e a1hOk e a1eOk e
                            a2pOk e a2mOk e a2cOk e a2hOk e a2eOk e
                            a3pOk e a3mOk e a3cOk e a3hOk e a3eOk e
                            a4pOk e a4mOk e a4cOk e a4hOk e a4eOk e
                            a5pOk e a5mOk e a5cOk e a5hOk e a5eOk)
                        {
                            notasLancadas = verdadeiro

        // SITUACAO EM CADA MATERIA
        

        // Agora eu transformo numero em situacao, pra ficar com cara de sistema serio
        s1p = situacaoMateria(a1pf)
        s1m = situacaoMateria(a1mf)
        s1c = situacaoMateria(a1cf)
        s1h = situacaoMateria(a1hf)
        s1e = situacaoMateria(a1ef)

        s2p = situacaoMateria(a2pf)
        s2m = situacaoMateria(a2mf)
        s2c = situacaoMateria(a2cf)
        s2h = situacaoMateria(a2hf)
        s2e = situacaoMateria(a2ef)

        s3p = situacaoMateria(a3pf)
        s3m = situacaoMateria(a3mf)
        s3c = situacaoMateria(a3cf)
        s3h = situacaoMateria(a3hf)
        s3e = situacaoMateria(a3ef)

        s4p = situacaoMateria(a4pf)
        s4m = situacaoMateria(a4mf)
        s4c = situacaoMateria(a4cf)
        s4h = situacaoMateria(a4hf)
        s4e = situacaoMateria(a4ef)

        s5p = situacaoMateria(a5pf)
        s5m = situacaoMateria(a5mf)
        s5c = situacaoMateria(a5cf)
        s5h = situacaoMateria(a5hf)
        s5e = situacaoMateria(a5ef)

        
        // SITUACAO ANUAL
        

        // Verificando se o aluno passou em tudo porque uma materia ja basta pra estragar a felicidade
        se (a1pf >= 7 e a1mf >= 7 e a1cf >= 7 e a1hf >= 7 e a1ef >= 7)
        {
            s1ano = "Passou de ano"
        }
        senao
        {
            s1ano = "Reprovou no ano"
        }

        se (a2pf >= 7 e a2mf >= 7 e a2cf >= 7 e a2hf >= 7 e a2ef >= 7)
        {
            s2ano = "Passou de ano"
        }
        senao
        {
            s2ano = "Reprovou no ano"
        }

        se (a3pf >= 7 e a3mf >= 7 e a3cf >= 7 e a3hf >= 7 e a3ef >= 7)
        {
            s3ano = "Passou de ano"
        }
        senao
        {
            s3ano = "Reprovou no ano"
        }

        se (a4pf >= 7 e a4mf >= 7 e a4cf >= 7 e a4hf >= 7 e a4ef >= 7)
        {
            s4ano = "Passou de ano"
        }
        senao
        {
            s4ano = "Reprovou no ano"
        }

        se (a5pf >= 7 e a5mf >= 7 e a5cf >= 7 e a5hf >= 7 e a5ef >= 7)
        {
            s5ano = "Passou de ano"
        }
        senao
        {
            s5ano = "Reprovou no ano"
        }

        
        // MEDIA GERAL POR ALUNO
        

        // Media geral de cada aluno pra resumir o caos em um numero so 
        mediaGeral1 = (a1pf + a1mf + a1cf + a1hf + a1ef) / 5
        mediaGeral2 = (a2pf + a2mf + a2cf + a2hf + a2ef) / 5
        mediaGeral3 = (a3pf + a3mf + a3cf + a3hf + a3ef) / 5
        mediaGeral4 = (a4pf + a4mf + a4cf + a4hf + a4ef) / 5
        mediaGeral5 = (a5pf + a5mf + a5cf + a5hf + a5ef) / 5

        
        // MEDIA DA TURMA POR MATERIA
        

        // Media da turma por materia ou seja o ranking coletivo do sofrimento sempre estive em ultimo lugar
        mediaTurmaPortugues = (a1pf + a2pf + a3pf + a4pf + a5pf) / 5
        mediaTurmaMatematica = (a1mf + a2mf + a3mf + a4mf + a5mf) / 5
        mediaTurmaCiencias = (a1cf + a2cf + a3cf + a4cf + a5cf) / 5
        mediaTurmaHistoria = (a1hf + a2hf + a3hf + a4hf + a5hf) / 5
        mediaTurmaEdFisica = (a1ef + a2ef + a3ef + a4ef + a5ef) / 5
        // Filosofia eu to achando bem interesante...
        // ESTATISTICAS GERAIS
        totalAprovadosAno = 0
        totalReprovadosAno = 0

        se (s1ano == "Passou de ano")
        {
            totalAprovadosAno = totalAprovadosAno + 1
        }
        senao
        {
            totalReprovadosAno = totalReprovadosAno + 1
        }

        se (s2ano == "Passou de ano")
        {
            totalAprovadosAno = totalAprovadosAno + 1
        }
        senao
        {
            totalReprovadosAno = totalReprovadosAno + 1
        }

        se (s3ano == "Passou de ano")
        {
            totalAprovadosAno = totalAprovadosAno + 1
        }
        senao
        {
            totalReprovadosAno = totalReprovadosAno + 1
        }

        se (s4ano == "Passou de ano")
        {
            totalAprovadosAno = totalAprovadosAno + 1
        }
        senao
        {
            totalReprovadosAno = totalReprovadosAno + 1
        }

        se (s5ano == "Passou de ano")
        {
            totalAprovadosAno = totalAprovadosAno + 1
        }
        senao
        {
            totalReprovadosAno = totalReprovadosAno + 1
        }

        mediaGeralTurma = (mediaGeral1 + mediaGeral2 + mediaGeral3 + mediaGeral4 + mediaGeral5) / 5

        maiorMediaGeral = mediaGeral1
        menorMediaGeral = mediaGeral1
        melhorAluno = aluno1
        piorAluno = aluno1

        se (mediaGeral2 > maiorMediaGeral)
        {
            maiorMediaGeral = mediaGeral2
            melhorAluno = aluno2
        }
        se (mediaGeral3 > maiorMediaGeral)
        {
            maiorMediaGeral = mediaGeral3
            melhorAluno = aluno3
        }
        se (mediaGeral4 > maiorMediaGeral)
        {
            maiorMediaGeral = mediaGeral4
            melhorAluno = aluno4
        }
        se (mediaGeral5 > maiorMediaGeral)
        {
            maiorMediaGeral = mediaGeral5
            melhorAluno = aluno5
        }

        se (mediaGeral2 < menorMediaGeral)
        {
            menorMediaGeral = mediaGeral2
            piorAluno = aluno2
        }
        se (mediaGeral3 < menorMediaGeral)
        {
            menorMediaGeral = mediaGeral3
            piorAluno = aluno3
        }
        se (mediaGeral4 < menorMediaGeral)
        {
            menorMediaGeral = mediaGeral4
            piorAluno = aluno4
        }
        se (mediaGeral5 < menorMediaGeral)
        {
            menorMediaGeral = mediaGeral5
            piorAluno = aluno5
        }

                            escreva("\nTodas as notas foram lancadas com sucesso!\n")
                        }
                        senao
                        {
                            notasLancadas = falso
                            escreva("\nAlgumas notas ja foram lancadas, mas ainda faltam materias/alunos para completar tudo.\n")
                        }
                    }
                    pare

                caso 3:
                    se (alunosCadastrados == falso)
                    {
                        escreva("\nPrimeiro use a opcao 1 para cadastrar os alunos.\n")
                    }
                    senao
                    {
                        se (notasLancadas == falso)
                        {
                            escreva("\nPrimeiro complete o lancamento de todas as notas na opcao 2.\n")
                        }
                        senao
                        {
                            escreva("\nCONSULTA INDIVIDUAL DE ALUNO\n")
                            escreva("1 - ", aluno1, "\n")
                            escreva("2 - ", aluno2, "\n")
                            escreva("3 - ", aluno3, "\n")
                            escreva("4 - ", aluno4, "\n")
                            escreva("5 - ", aluno5, "\n")
                            escreva("Digite o numero do aluno: ")
                            leia(opcaoAluno)

                            escolha (opcaoAluno)
                            {
                                caso 1:
                                    nomeConsulta = aluno1
                                    escreva("\nAluno: ", nomeConsulta, "\n")
                                    escreva("Portugues: ", a1pf, " - ", s1p, "\n")
                                    escreva("Matematica: ", a1mf, " - ", s1m, "\n")
                                    escreva("Ciencias: ", a1cf, " - ", s1c, "\n")
                                    escreva("Historia: ", a1hf, " - ", s1h, "\n")
                                    escreva("Educacao Fisica: ", a1ef, " - ", s1e, "\n")
                                    escreva("Media geral: ", mediaGeral1, "\n")
                                    escreva("Situacao anual: ", s1ano, "\n")
                                    pare
                                caso 2:
                                    nomeConsulta = aluno2
                                    escreva("\nAluno: ", nomeConsulta, "\n")
                                    escreva("Portugues: ", a2pf, " - ", s2p, "\n")
                                    escreva("Matematica: ", a2mf, " - ", s2m, "\n")
                                    escreva("Ciencias: ", a2cf, " - ", s2c, "\n")
                                    escreva("Historia: ", a2hf, " - ", s2h, "\n")
                                    escreva("Educacao Fisica: ", a2ef, " - ", s2e, "\n")
                                    escreva("Media geral: ", mediaGeral2, "\n")
                                    escreva("Situacao anual: ", s2ano, "\n")
                                    pare
                                caso 3:
                                    nomeConsulta = aluno3
                                    escreva("\nAluno: ", nomeConsulta, "\n")
                                    escreva("Portugues: ", a3pf, " - ", s3p, "\n")
                                    escreva("Matematica: ", a3mf, " - ", s3m, "\n")
                                    escreva("Ciencias: ", a3cf, " - ", s3c, "\n")
                                    escreva("Historia: ", a3hf, " - ", s3h, "\n")
                                    escreva("Educacao Fisica: ", a3ef, " - ", s3e, "\n")
                                    escreva("Media geral: ", mediaGeral3, "\n")
                                    escreva("Situacao anual: ", s3ano, "\n")
                                    pare
                                caso 4:
                                    nomeConsulta = aluno4
                                    escreva("\nAluno: ", nomeConsulta, "\n")
                                    escreva("Portugues: ", a4pf, " - ", s4p, "\n")
                                    escreva("Matematica: ", a4mf, " - ", s4m, "\n")
                                    escreva("Ciencias: ", a4cf, " - ", s4c, "\n")
                                    escreva("Historia: ", a4hf, " - ", s4h, "\n")
                                    escreva("Educacao Fisica: ", a4ef, " - ", s4e, "\n")
                                    escreva("Media geral: ", mediaGeral4, "\n")
                                    escreva("Situacao anual: ", s4ano, "\n")
                                    pare
                                caso 5:
                                    nomeConsulta = aluno5
                                    escreva("\nAluno: ", nomeConsulta, "\n")
                                    escreva("Portugues: ", a5pf, " - ", s5p, "\n")
                                    escreva("Matematica: ", a5mf, " - ", s5m, "\n")
                                    escreva("Ciencias: ", a5cf, " - ", s5c, "\n")
                                    escreva("Historia: ", a5hf, " - ", s5h, "\n")
                                    escreva("Educacao Fisica: ", a5ef, " - ", s5e, "\n")
                                    escreva("Media geral: ", mediaGeral5, "\n")
                                    escreva("Situacao anual: ", s5ano, "\n")
                                    pare
                                caso contrario:
                                    escreva("\nAluno invalido.\n")
                                    pare
                            }
                        }
                        confirmarVoltaMenu()
                    }
                    pare

                caso 4:
                    se (alunosCadastrados == falso)
                    {
                        escreva("\nPrimeiro use a opcao 1 para cadastrar os alunos.\n")
                    }
                    senao
                    {
                        se (notasLancadas == falso)
                        {
                            escreva("\nPrimeiro complete o lancamento de todas as notas na opcao 2.\n")
                        }
                        senao
                        {
                            escreva("RELATORIO FINAL DOS ALUNOS\n")

                            escreva("\nAluno: ", aluno1, "\n")
                            escreva("Portugues: ", a1pf, " - ", s1p, "\n")
                            escreva("Matematica: ", a1mf, " - ", s1m, "\n")
                            escreva("Ciencias: ", a1cf, " - ", s1c, "\n")
                            escreva("Historia: ", a1hf, " - ", s1h, "\n")
                            escreva("Educacao Fisica: ", a1ef, " - ", s1e, "\n")
                            escreva("Media geral: ", mediaGeral1, "\n")
                            escreva("Situacao anual: ", s1ano, "\n")

                            escreva("\nAluno: ", aluno2, "\n")
                            escreva("Portugues: ", a2pf, " - ", s2p, "\n")
                            escreva("Matematica: ", a2mf, " - ", s2m, "\n")
                            escreva("Ciencias: ", a2cf, " - ", s2c, "\n")
                            escreva("Historia: ", a2hf, " - ", s2h, "\n")
                            escreva("Educacao Fisica: ", a2ef, " - ", s2e, "\n")
                            escreva("Media geral: ", mediaGeral2, "\n")
                            escreva("Situacao anual: ", s2ano, "\n")

                            escreva("\nAluno: ", aluno3, "\n")
                            escreva("Portugues: ", a3pf, " - ", s3p, "\n")
                            escreva("Matematica: ", a3mf, " - ", s3m, "\n")
                            escreva("Ciencias: ", a3cf, " - ", s3c, "\n")
                            escreva("Historia: ", a3hf, " - ", s3h, "\n")
                            escreva("Educacao Fisica: ", a3ef, " - ", s3e, "\n")
                            escreva("Media geral: ", mediaGeral3, "\n")
                            escreva("Situacao anual: ", s3ano, "\n")

                            escreva("\nAluno: ", aluno4, "\n")
                            escreva("Portugues: ", a4pf, " - ", s4p, "\n")
                            escreva("Matematica: ", a4mf, " - ", s4m, "\n")
                            escreva("Ciencias: ", a4cf, " - ", s4c, "\n")
                            escreva("Historia: ", a4hf, " - ", s4h, "\n")
                            escreva("Educacao Fisica: ", a4ef, " - ", s4e, "\n")
                            escreva("Media geral: ", mediaGeral4, "\n")
                            escreva("Situacao anual: ", s4ano, "\n")

                            escreva("\nAluno: ", aluno5, "\n")
                            escreva("Portugues: ", a5pf, " - ", s5p, "\n")
                            escreva("Matematica: ", a5mf, " - ", s5m, "\n")
                            escreva("Ciencias: ", a5cf, " - ", s5c, "\n")
                            escreva("Historia: ", a5hf, " - ", s5h, "\n")
                            escreva("Educacao Fisica: ", a5ef, " - ", s5e, "\n")
                            escreva("Media geral: ", mediaGeral5, "\n")
                            escreva("Situacao anual: ", s5ano, "\n")
                        }
                        confirmarVoltaMenu()
                    }
                    pare

                caso 5:
                    se (alunosCadastrados == falso)
                    {
                        escreva("\nPrimeiro use a opcao 1 para cadastrar os alunos.\n")
                    }
                    senao
                    {
                        se (notasLancadas == falso)
                        {
                            escreva("\nPrimeiro complete o lancamento de todas as notas na opcao 2.\n")
                        }
                        senao
                        {
                            escreva("DESEMPENHO POR MATERIA\n")
                            escreva("Portugues: ", mediaTurmaPortugues, "\n")
                            escreva("Matematica: ", mediaTurmaMatematica, "\n")
                            escreva("Ciencias: ", mediaTurmaCiencias, "\n")
                            escreva("Historia: ", mediaTurmaHistoria, "\n")
                            escreva("Educacao Fisica: ", mediaTurmaEdFisica, "\n")
                        }
                        confirmarVoltaMenu()
                    }
                    pare

                caso 6:
                    se (alunosCadastrados == falso)
                    {
                        escreva("\nPrimeiro use a opcao 1 para cadastrar os alunos.\n")
                    }
                    senao
                    {
                        se (notasLancadas == falso)
                        {
                            escreva("\nPrimeiro complete o lancamento de todas as notas na opcao 2.\n")
                        }
                        senao
                        {
                            escreva("\nESTATISTICAS GERAIS DA TURMA\n")
                            escreva("Total de aprovados no ano: ", totalAprovadosAno, "\n")
                            escreva("Total de reprovados no ano: ", totalReprovadosAno, "\n")
                            escreva("Media geral da turma: ", mediaGeralTurma, "\n")
                            escreva("Maior media geral: ", maiorMediaGeral, " - ", melhorAluno, "\n")
                            escreva("Menor media geral: ", menorMediaGeral, " - ", piorAluno, "\n")
                        }
                        confirmarVoltaMenu()
                    }
                    pare

                caso 0:
                    escreva("\nSistema encerrado.\n")
                    pare

                caso contrario:
                    escreva("\nOpcao invalida.\n")
                    pare
            }
        }
    }
}
