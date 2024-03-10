#ifndef MATRIZ_HPP
#define MATRIZ_HPP

    int DescobrirTamanho();
    char** CriaMatriz (int linhascolunas);
    char** PreencheMatriz(char**JogodaVida);
    char** ProximaGeracao(char** JogodaVida, int Tamanho, int GeracaoAtual);
    void DestrutorMatriz(char** JogodaVida, int Tamanho, int Exibirmensagem);
    void Limpar_geracoesmps();

#endif