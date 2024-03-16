<h1 align='center'>Jogo da Vida</h1>

<div align = "center" >

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

> Status: Finalizado ✅

## Introdução
<p align="justify">
Este programa faz referência a disciplina Algorítmo e Estrutura de Dados I, desenvolvido na linguagem C++ na IDE Visual Studio Code, usando uma makefile disponibilizada pelo docente. O Jogo da Vida é um problema que visa instruir os estudantes a trabalhar com uma matriz bidimensional constituída de apenas elementos 0 e 1, numa proporção de 2:1. Conforme o programa é executado, a matriz evoluirá mediante as regras propostas pelo problema.
</p>

## Objetivos

<p align='justify'>
O objetivo deste trabalho é usar a matriz de entrada fornecida pelo usuário em um arquivo de texto para chegar rapidamente à formatação final da matriz, após um determinado número de gerações. Essas gerações representam o número de interações que o programa analisará a matriz e mudará seu conteúdo conforme as regras estipuladas pelo problema.
</p>

## Arquivos
### datasets
- ``` input.mps ``` Esse arquivo de texto fornece em sua primeira linha o Tamanho (linhas e colunas) da Matriz, além, também, de seu conteúdo inicial. Ambos serão lidos pelo programa;
- ``` Geracoes.ps ``` Esse arquivo de texto é o local onde o programa imprimirá os resultados de cada geração.

## src
- ``` main.cpp ```: Arquivo principal;
- ``` Matriz.hpp ```: Assinatura das funções relacionadas às matrizes;
- ``` Matriz.cpp ```: Implementação das funções relacionadas às matrizes;

## Resolução do Problema
<p aligh='justify'>
O primeiro passo para a resolução do problema é identificar o tamanho da matriz de maneira correta. Nas instruções do problema, sabe-se que a matriz sempre será quadrática, e seu tamanho corresponderá ao número na primeira linha do arquivo de texto input.mps. Feito isso, o programa alocará espaço para a matriz NxN. É importante dizer que, na implementação, a fim de evitar problemas futuros, a matriz criada tem tamanho N+2xN+2. Isso foi feito para que a matriz pudesse ser cercada com um caractér escolhido e, dessa forma, quando analisando cada posição P(ij) da matriz, não fosse acessada uma posição de memória não alocada anteriormente. Após criada a matriz, o programa abrirá novamente o arquivo de entrada input.txt e copiará a matriz pré-existente nela para a matriz criada pelo programa. Esse também será o último acesso ào arquivo de texto input.mps.
</p>

<p align='justify'> 
Feito isso, agora serão executadas sequências lógicas que seguem as regras estipuladas pelo exercício. Essa lógica determinara como será o proximo estado da matriz, que será armazenada em uma matriz igual a anterior, denominada aux ( auxiliar ). Após isso, a matriz original será escrita no arquivo de texto Geracoes.mps, e a matriz original passará a ser a matriz auxiliar, e a original será destruída para evitar vazamento de memória. O programa executará esse mesmo processo X vezes, onde X representa o número de interações pedidas pelo usuário. Depois de todas as interações serem feitas, o programa então destruirá a matriz final e exibirá uma mensagem indicando o término de suas operações.
</p>

## Resultados
- Arquivo de Entrada ``input.mps``
