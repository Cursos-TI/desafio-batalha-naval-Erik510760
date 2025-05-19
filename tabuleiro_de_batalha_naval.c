import random
TAMANHO = 10

AGUA = "~"
NAVIO = "N"
ACERTO = "X"
ERRO = "O"

def criar_tabuleiro():
    return [[AGUA for _ in range(TAMANHO)] for _ in range(TAMANHO)]

def imprimir_tabuleiro(tabuleiro, ocultar_navios=False):
    print("  " + " ".join(str(i) for i in range(TAMANHO)))
    for i, linha in enumerate(tabuleiro):
        visivel = [
            AGUA if (ocultar_navios and cel == NAVIO) else cel for cel in linha
        ]
        print(f"{i} " + " ".join(visivel))

def posicionar_navio(tabuleiro, tamanho_navio):
    orientacao = random.choice(['H', 'V'])
    if orientacao == 'H':
        linha = random.randint(0, TAMANHO - 1)
        coluna = random.randint(0, TAMANHO - tamanho_navio)
        if all(tabuleiro[linha][coluna + i] == AGUA for i in range(tamanho_navio)):
            for i in range(tamanho_navio):
                tabuleiro[linha][coluna + i] = NAVIO
            return True
    else:
        linha = random.randint(0, TAMANHO - tamanho_navio)
        coluna = random.randint(0, TAMANHO - 1)
        if all(tabuleiro[linha + i][coluna] == AGUA for i in range(tamanho_navio)):
            for i in range(tamanho_navio):
                tabuleiro[linha + i][coluna] = NAVIO
            return True
    return False

def atacar(tabuleiro, linha, coluna):
    if tabuleiro[linha][coluna] == NAVIO:
        tabuleiro[linha][coluna] = ACERTO
        return "Acertou!"
    elif tabuleiro[linha][coluna] == AGUA:
        tabuleiro[linha][coluna] = ERRO
        return "Errou!"
    else:
        return "Já atacou aqui!"

def contar_navios(tabuleiro):
    return sum(row.count(NAVIO) for row in tabuleiro)

# Jogo principal
def jogar():
    tabuleiro_jogador = criar_tabuleiro()
    tabuleiro_inimigo = criar_tabuleiro()

    # Posicionar navios (ex: 1 de tamanho 4, 2 de tamanho 3, etc.)
    navios = [4, 3, 3, 2, 2]
    for tamanho in navios:
        while not posicionar_navio(tabuleiro_inimigo, tamanho):
            continue

    print("Bem-vindo à Batalha Naval!")
    while contar_navios(tabuleiro_inimigo) > 0:
        imprimir_tabuleiro(tabuleiro_inimigo, ocultar_navios=True)
        try:
            linha = int(input("Linha do ataque (0-9): "))
            coluna = int(input("Coluna do ataque (0-9): "))
            resultado = atacar(tabuleiro_inimigo, linha, coluna)
            print(resultado)
        except (ValueError, IndexError):
            print("Entrada inválida. Tente novamente.")

    print("Parabéns! Você venceu.")
    imprimir_tabuleiro(tabuleiro_inimigo, ocultar_navios=False)

if __name__ == "__main__":
    jogar()
