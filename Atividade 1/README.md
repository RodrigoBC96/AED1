# Atividade 1

-  Nome: Rodrigo Barbosa Carvalho
-  Matrícula: 16104702
-  GitHub: https://github.com/RodrigoBC96/AED1
-  Link dos vídeos:
  
 -- Exercícios --

1) Faça uma gravação curta de você criando um projeto "Olá Mundo" em C no Visual Code e usando o debug com um breakpoint no printf.

2) Faça um programa que armazena nomes.
• O programa deve armazenar todos os nomes na mesma string
• O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos
• Não pode ter desperdício de memória.
• Faça o seguinte menu:
 - 1. Adicionar nome
 - 2. Remover nome
 - 3. Listar
 - 4. Sair

3) Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
- Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
- Cada pessoa tem nome[10], idade e telefone.
- O trabalho que vale nota será uma continuação deste.

 -- Execução --
 
  Devido à lógica utilizada, existem excessões de caso no exercício 2, visto que nomes que podem estar contidos dentro de outros e nomes compostos não foram cogitados para esta aplicação. Nos demais, apenas é pedido que os parâmetros do enunciado sejam seguidos.

 -- Comentário --
 
  Ao tentar processar os códigos com o Dr. Memory, foram encontrados diversos problemas durante os testes, porém, nenhum deles se mostrou relacionado com o código à princípio. Pois se tratavam de quebras internas ou acesso fora da área do heap.
