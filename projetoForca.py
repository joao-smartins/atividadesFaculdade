# Jogo da forca
import random

espelho = []
frutas = ['abacaxi', 'banana', 'caqui', 'damasco', 'embu', 'figo', 'goiaba']
nomes = ['ana', 'bernardo', 'caique', 'danilo', 'eustaquio', 'flavia', 'gerson']
times = ['ajax', 'borussia', 'chelsea', 'dynamo', 'everton', 'fulham', 'getafe']
print('\n****************************** Jogo da  Forca ******************************')
print('----------------------------------------------------------------------------')
print('Olá jogador!Selecione o tipo de de palavra a ser sorteada ou encerre o jogo:')
print('----------------------------------------------------------------------------')
op = int(input('''1. Frutas\n2. Nomes\n3. Times de futebol (europeus)\n0. Encerrar o jogo 
----------------------------------------------------------------------------\n'''))
while op > 0 and op < 4:
    if op == 1:
        i = random.randrange(0, len(frutas) - 1)
        var = frutas[i]
        # print(frutas[i])
    elif op == 2:
        i = random.randrange(0, len(nomes) - 1)
        var = nomes[i]
        # print(nomes[i])
    elif op == 3:
        i = random.randrange(0, len(times) - 1)
        var = times[i]
        # print(times[i])

    for i in range(0, len(var)):
        espelho.append('_')
    for i in range(0, len(var)):
        print(espelho[i], end=" ")

    des_forca = ['''
         +---+
         |   |
             |
             |
             |
             |    
        =========''', '''
         +---+
         |   |
         O   |
             |
             |
             |    
        =========''', '''
         +---+
         |   |
         O   |
         |   |
             |
             |    
        =========''', '''
         +---+
         |   |
         O   |
        /|   |
             |
             |    
        =========''', '''
         +---+
         |   |
         O   |
        /|\  |
             |
             |    
        =========''', '''
         +---+
         |   |
         O   |
        /|\  |
        /    |
             |    
        =========''', '''
         +---+
         |   |
         O   |
        /|\  |
        / \  |
             |    
        =========
        ''']

    print('\n*** Jogo da Forca ***')
    h = 0
    print(des_forca[h])
    cont = 0
    ganhou = 0
    rep = espelho.count('_')
    while h < 6 and rep != 0 and ganhou != 1:
        letra = input('\nDigite uma letra ou a palavra completa:\n').lower()
        procura = var.count(letra)
        if procura != 0 or letra == var:
            if procura != 0 and letra != var and len(letra) < 2:  # Letra por letra
                for i in range(0, len(var)):
                    if letra == var[i]:
                        espelho[i] = letra
                for i in range(0, len(var)):
                    print(espelho[i], end=" ")
            elif procura != 0 and letra == var:  # Palavra completa
                print('''\nVós sois um gênio!
ಠ_ರೃ''')
                ganhou = 1
            else:
                print('Letra não encontrada!')  # + de uma letra mas incompleto
                h = h + 1
                print(des_forca[h])


        else:
            print('Letra não encontrada!')
            h = h + 1
            print(des_forca[h])

        rep = espelho.count('_')
        if h == 6:
            print('''\nVocê perdeu!
¯\_(ツ)_/¯''')
        if rep == 0:
            print('''\n**************
*Você ganhou!*
**************
✌(-‿-)✌''')

    print(f'\nA resposta correta era: {var}\n')
    espelho.clear()
    print('---------------------------------------------------------------------------------------')
    print('Olá novamente, jogador!Selecione o tipo de de palavra a ser sorteada ou encerre o jogo:')
    print('---------------------------------------------------------------------------------------')
    op = int(input('''1. Frutas\n2. Nomes\n3. Times de futebol (europeus)\n0. Encerrar o jogo  
---------------------------------------------------------------------------------------\n'''))
if op == 7:
    print('''SHENLONG:Denovo esse tal de Kuririn?\n ''')