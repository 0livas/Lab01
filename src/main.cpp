#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main(){  
    Limpar_geracoesmps();
    cout << "Digite o número de gerações a ser avaliado: ";
    int NumerodeGeracoes, Cont_Geracoes = 0;
    cin >> NumerodeGeracoes;

    int Tam = DescobrirTamanho();
    char** Mapa = CriaMatriz(Tam);
    Mapa = PreencheMatriz(Mapa);
    
    do{
        Mapa = ProximaGeracao(Mapa, Tam, Cont_Geracoes);
        Cont_Geracoes = Cont_Geracoes + 1;
        cout << endl;
    }while(Cont_Geracoes!=NumerodeGeracoes); //*Perguntar o Michel depois.

    cout << "Finalizando o programa." << endl;
    DestrutorMatriz(Mapa, Tam, 1);
    return 0;
}