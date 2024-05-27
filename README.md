# Jogo - Pong

## Descrição

Este é um jogo de Pong implementado em C para ser jogado na linha de comando. O jogo inclui animações e movimento dos elementos na tela, bem como tratamento de colisão. O projeto faz uso de estruturas, ponteiros, alocação dinâmica de memória e manipulação de arquivos para armazenar as pontuações mais altas.
O jogo é um projeto para a disciplina de Programação Imperativa e Funcional - 2024.1.


## Funcionalidades

- Jogo de Pong com movimento suave da bola e das raquetes.
- Animações básicas para os elementos do jogo.
- Tratamento de colisão entre a bola, raquetes, paredes e obstáculos.
- Armazenamento e leitura das pontuações mais altas em um arquivo.
- Uso de estruturas (structs) para os elementos do jogo.
- Uso de ponteiros e alocação dinâmica de memória.
- Implementação de uma lista encadeada para armazenar as maiores pontuações.

## Requisitos

- GCC (ou qualquer outro compilador C)
- Sistema operacional Unix-like recomendado (Linux, macOS)
- Biblioteca `ncurses` para manipulação da tela de comando (opcional, mas recomendado para animações).

Após certificar-se de ter um compilador C instalado, clone este repositório para sua máquina local e navegue até o diretório do projeto.
Então, compile o código e execute o jogo.

## Como Jogar

Bem-vindo ao jogo Pong! A estrutura do jogo é bem intuitiva: você controla uma raquete que pode se mover verticalmente ao longo de uma linha no lado esquerdo da tela. A bola se move de um lado para o outro e você deve usar a raquete para rebater a bola e evitar que ela passe pela sua raquete. Você ganha pontos toda vez que a bola passa pela raquete do adversário controlado pelo computador.
O jogo termina quando o tempo definido se esgota ou quando um dos jogadores atinge 5 pontos. O jogador com a maior pontuação no final do jogo é o vencedor. Nas categorias Intermediário, Avançado e Expert, o jogo apresenta desafios adicionais: a bola se move mais rapidamente, as raquetes são menores, exigindo reflexos mais rápidos dos jogadores, ou são introduzidos obstáculos na tela, que variam de acordo com o nível escolhido.

### Menu Inicial

Ao iniciar o jogo, você será solicitado a informar o número de jogadores. Selecione `1` para o modo single player, contra um bot, ou `2` para 2 jogadores.
Você também poderá selecionar um nível de dificuldade. As opções são: Iniciante, Intermediário, Avançado e Expert. Escolha o nível que mais se adequa à sua habilidade. 

### Objetivos

- Rebata a bola de modo que o adversário (que pode ser controlado pelo computador) não consiga devolvê-la. 
- Você ganha um ponto toda vez que o adversário falha em rebater a bola.
- O jogo termina quando o tempo definido se esgota ou quando um dos jogadores atinge 5 pontos. 
- O jogador com a maior pontuação no final do jogo é o vencedor.

### Níveis de Dificuldade

- Iniciante: A bola se move lentamente e as raquetes são grandes. 
- Intermediário: A bola se move mais rapidamente e as raquetes são menores. 
- Avançado: A bola se move ainda mais rapidamente, as raquetes são menores e há obstáculos na tela. 
- Expert: A bola se move muito rapidamente, as raquetes são bem pequenas e há vários obstáculos na tela.

### Controles do Jogo

Jogador do Lado Esquerdo:
- tecla `w` para mover a raquete para cima.
- tecla `s` para mover a raquete para baixo.

Jogador do Lado Direito:
- tecla `o` para mover a raquete para cima.
- tecla `l` para mover a raquete para baixo.

- `Enter` - Seleciona a opção do menu ou confirma uma ação
- `Esc` - Sai do jogo

## Contato

Equipe - Lisa Matubara, Luziane Santos, Thaís Aguiar
