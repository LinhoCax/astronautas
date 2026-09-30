# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 1.18.33
- Modelo usado: Gemini (por uma questão se segurança de dados, já que o próprio OpenCode avisa que podem fazer coleta de dados do usuario para o treinamento dos modelos gratuitos. Além disso tenho a versão de estudantes do Gemini que possibilita seu uso dentro do OpenCode).

## Parte 1: antes de programar

- O que cada classe guarda: Todas as classes possuem modificadores de acesso publicos e privados. 
        Astronauta: Guarda os dados de uma pessoa (CPF, nome, idade) e o seu status atual (se está vivo e se está disponível).
        Voo: Guarda os dados da missão (código e estado) e uma lista contendo apenas os CPFs dos astronautas que estão a bordo.
        Agencia: É a coordenadora geral que guarda duas listas: uma com todos os objetos *Astronauta* e outra com todos os objetos *Voo* do sistema.

- O que acontece em `LANCAR_VOO`, em palavras: 

  Primeiro, a Agencia busca o voo pelo código e verifica se ele está no estado "planejado" e se possui algum astronauta a bordo. Em seguida, ela passa por cada astronauta do voo          verificando se todos estão vivos e disponíveis. Se estiver tudo certo, a Agencia manda cada astronauta embarcar (o que os deixa indisponíveis) e muda o estado do voo para "em curso", imprimindo a mensagem de sucesso no final.

- Uma dúvida que eu tinha antes de começar:

Como a classe Agencia consegue coordenar as outras duas, sendo a única responsável por buscar as informações cruzadas entre voos e astronautas?

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): 
- O que aprendi:

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
1- Uso de const em métodos de leitura (Getters): Métodos como getCpf() apenas retornam valores. Adicionar o const no final da assinatura garante ao compilador que esse método não vai alterar o estado do objeto.
2- Passagem de string por referência constante: Nos construtores e métodos (como adicionarAstronauta(string cpf)). Usar uma referência constante (const string&) evita essa cópia e deixa o programa mais rápido.
3- Lista de inicialização nos construtores: No C++, é mais eficiente e idiomático inicializar os atributos diretamente na declaração do construtor, em vez de atribuir valores usando this-> dentro do bloco de código.

- A que escolhi e por quê:

A passagem de string por referência constante (const string&). Ao analisar o consumo de memória e a velocidade de execução em estruturas de dados, notei o impacto profundo deste tipo de otimização: em vez de alocar memória para criar uma cópia completa de um texto (como um nome ou CPF) sempre que um método é chamado, o C++ passa apenas uma referência de leitura muito leve e segura, otimizando imediatamente o desempenho do programa.

- O que mudou no código, e se os seis testes continuaram passando:

Apenas alterações nas assinaturas de alguns metodos das classes. Os seis testes passaram depois das mudanças.

- O que entendi que não sabia antes:

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
