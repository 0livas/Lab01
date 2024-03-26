#ifndef MATRIZ_HPP
#define MATRIZ_HPP

    int DescobrirTamanho();
    int** CriaMatriz (int linhascolunas);
    int** PreencheMatriz(int**JogodaVida, int Tamanho);
    int** ProximaGeracao(int** JogodaVida, int Tamanho, int GeracaoAtual);
    void DestrutorMatriz(int** JogodaVida, int Tamanho, int Exibirmensagem);
    void Limpar_geracoesmps();
    void Executar();

#endif