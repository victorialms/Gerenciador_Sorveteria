<h1 align="center">Trabalho de Programação II - Gerenciador de Sorveteria 🍦</h1>

<p align="center">
  Projeto desenvolvido para a disciplina de Programação II, orientado pelo Prof. Lauro Víctor. Este software tem como objetivo gerenciar as operações de uma sorveteria, incluindo cadastro de vendas, consulta de informações e geração de relatórios detalhados.
</p>

---

## 📋 Enunciado do Problema

Uma sorveteria precisa controlar suas compras, entender seus clientes e realizar algumas consultas. Este projeto entrega a primeira versão de um sistema gerenciador que atende a essas necessidades.

---

## 📌 Funcionalidades Implementadas

1. **Menu Principal**
   - Cadastrar novas vendas.
   - Ver informações de uma venda específica, baseado no nome do cliente.
   - Ver informações de todas as vendas.
   - Encerrar o programa.

2. **Cadastro de Vendas**
   - O usuário define a quantidade de vendas a serem cadastradas.
   - Cada venda inclui informações como:
     - Nome, sexo e idade do cliente.
     - Número de itens.
     - Número de sabores.
     - Valor total da compra.
   - Validações realizadas:
     - Impede valores negativos.
     - Impede cadastro de sexo inválido (`m`, `f` ou `n`).
     - Impede nomes com menos de 3 letras.
   - Dados salvos no arquivo `registros.txt`.

3. **Pesquisa de Venda Específica**
   - Pesquisa vendas por nome do cliente.
   - Exibe:
     - Valor total de cada compra.
     - Número de sabores.
     - Quantidade de itens em cada compra.
     - Média de valor das compras.
   - Informa caso o cliente não seja encontrado.

4. **Relatórios de Vendas**
   - Quantidade de vendas abaixo de um valor específico.
   - Quantidade de vendas com apenas 1 item.
   - Quantidade de vendas com número par de sabores.
   - Estatísticas:
     - Compradores mulheres.
     - Valor total comprado por homens.
     - Total de itens vendidos.
     - Total de sabores vendidos.
     - Valor médio das compras.
   - Dados detalhados do cliente com o maior nome e do cliente mais novo.

5. **Persistência de Dados**
   - Dados carregados automaticamente do arquivo `registros.txt` ao iniciar o programa.
   - Novas vendas adicionadas ao arquivo sem sobrescrever informações existentes.

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem de Programação**: C.
- **Arquivos**: Gerenciamento de dados persistentes com `registros.txt`.

---

## 📝 Estrutura do Projeto

```plaintext
.
├── main.c
├── registros.txt
├── README.md
