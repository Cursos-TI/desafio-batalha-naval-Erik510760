# Tamanho do tabuleiro
TAMANHO = 10

# Criação do tabuleiro com todos os valores iniciando em 0 (água)
tabuleiro = [[0 for _ in range(TAMANHO)] for _ in range(TAMANHO)]

# Tamanho fixo dos navios
TAMANHO_NAVIO = 3

# Vetores que representam os navios
navio_horizontal = [3] * TAMANHO_NAVIO
navio_vertical = [3] * TAMANHO_NAVIO

# Coordenadas iniciais dos navios
linha_h = 2
coluna_h = 4

linha_v = 5
coluna_v = 1

# Verificação se estão dentro dos limites
def dentro_dos_limites(l, c, orientacao):
    if orientacao == 'H':
        return c + TAMANHO_NAVIO <= TAMANHO
    elif orientacao == 'V':
        return l + TAMANHO_NAVIO <= TAMANHO
    return False

# Verificação de sobreposição
def sem_sobreposicao(tabuleiro, l, c, orientacao):
    for i in range(TAMANHO_NAVIO):
        if orientacao == 'H':
            if tabuleiro[l][c + i] != 0:
                return False
        else:  # V
            if tabuleiro[l + i][c] != 0:
                return False
    return True

# Posicionamento do navio horizontal
if dentro_dos_limites(linha_h, coluna_h, 'H') and sem_sobreposicao(tabuleiro, linha_h, coluna_h, 'H'):
    for i in range(TAMANHO_NAVIO):
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i]
else:
    print("Erro ao posicionar navio horizontal.")

# Posicionamento do navio vertical
if dentro_dos_limites(linha_v, coluna_v, 'V') and sem_sobreposicao(tabuleiro, linha_v, coluna_v, 'V'):
    for i in range(TAMANHO_NAVIO):
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i]
else:
    print("Erro ao posicionar navio vertical.")

# Impressão do tabuleiro
print("Tabuleiro após posicionar os navios (3 representa navio):")
for linha in tabuleiro:
    print(" ".join(str(cel) for cel in linha))
