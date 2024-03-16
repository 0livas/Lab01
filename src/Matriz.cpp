#include <iostream>
#include <fstream>
#include <sstream>
#include "Matriz.hpp"
using namespace std;

int DescobrirTamanho(){ //Lê a primeira linha do txt e pega o tamanho.
    int Tamanho = 0;
    string Aux_de_linha;
    ifstream inFile;

    inFile.open("datasets/input.mps", ios::in);
    if(!inFile){
        cout << "O arquivo especificado (input.mps) não pôde ser aberto!" << endl;
        return 1;
    }

    std::getline(inFile, Aux_de_linha);
    inFile.close();
    std::istringstream iss (Aux_de_linha);
    iss >> Tamanho;

    return Tamanho;
};


char** CriaMatriz(int linhascolunas){ //Aloca a matriz dinâmicamente e cerca a cidade com um caracter à minha escolha.
    char** JogodaVida = new char*[linhascolunas+2];
    for(int i = 0; i < linhascolunas+2; i++){
        JogodaVida[i] = new char[linhascolunas+2];
    } 

    for(int i = 0; i<linhascolunas+2; i++){
        for(int j = 0; j<linhascolunas+2; j++){
            if(i == 0 || j == 0 || i == linhascolunas+1 || j == linhascolunas+1){
                JogodaVida[i][j] = '*';
            }
        }
    }

    return JogodaVida;
};


char** PreencheMatriz(char**JogodaVida, int Tamanho){ // Recebe a matriz já alocada e preenche seu interior baseado no arquivo txt.
    ifstream inFile;
    inFile.open("datasets/input.mps", ios::in);
    if(!inFile){
        cout << "O arquivo especificado (input.mps) não pôde ser aberto!" << endl;
        abort();
    }
    
    Tamanho = Tamanho+1;

    for(int i=1; i<Tamanho; i++){
        for(int j=1; j<Tamanho; j++){
            inFile >> JogodaVida[i][j];
        }
    }

    inFile.close();
    return JogodaVida;
};


char** ProximaGeracao(char** JogodaVida, int Tamanho, int GeracaoAtual){ //Preenche uma matriz auxiliar da pŕoxima geração do jogo e escreve a geração anterior no .mps de saída
    char** MatrizAux = CriaMatriz(Tamanho);
    
    for(int i=0; i<Tamanho+2; i++){
        for(int j=0; j<Tamanho+2; j++){
            cout << JogodaVida[i][j];
        }
        cout << endl;
    }

    int vizinhos = 0;
    for(int i = 1; i<Tamanho+1; i++){
        for(int j = 1; j<Tamanho+1; j++){
            vizinhos = 0;
            if(JogodaVida[i-1][j-1] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i-1][j] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i-1][j+1] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i][j-1] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i][j+1] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i+1][j-1] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i+1][j] == '1'){
                vizinhos++;
            }
            if(JogodaVida[i+1][j+1] == '1'){
                vizinhos++;
            }
            
            if(JogodaVida[i][j] == '1' && vizinhos < 2){
                MatrizAux[i][j] = '0';
            }

            if(JogodaVida[i][j] == '1' && vizinhos > 3){
                MatrizAux[i][j] = '0';
            }

            if(JogodaVida[i][j] == '1' && vizinhos == 2){
                MatrizAux[i][j] = '1';
            }

            if(JogodaVida[i][j] == '1' && vizinhos == 3){
                MatrizAux[i][j] = '1';
            }

            if(JogodaVida[i][j] == '0' && vizinhos == 3){
                MatrizAux[i][j] = '1';
            }

            if(JogodaVida[i][j] == '0' && vizinhos < 3){
                MatrizAux[i][j] = '0';
            }

            if(JogodaVida[i][j] == '0' && vizinhos > 3){
                MatrizAux[i][j] = '0';
            }
        }
    }

    ofstream outFIle;
    outFIle.open("datasets/Geracoes.mps", ios::app);
    if(!outFIle){
        cout << "O arquivo especificado (Geracoes.mps) não pôde ser aberto!" << endl;
        abort();
    }
    
    outFIle << "-> Geração " << GeracaoAtual << "." << endl << endl;

    for(int i = 1; i<Tamanho+1; i++){
        for(int j = 1; j<Tamanho+1; j++){
            outFIle << JogodaVida[i][j];
        }
        outFIle << endl;
    }
    outFIle << endl;

    outFIle.close();
    DestrutorMatriz(JogodaVida, Tamanho, 0);
    return MatrizAux;

};


void DestrutorMatriz(char** JogodaVida, int Tamanho, int Exibirmensagem){ // Destrói a matriz alocada anteriormente.
    Tamanho = Tamanho + 2;
    for(int i = 0; i<Tamanho; i++){
        delete JogodaVida[i];
    }
    delete JogodaVida;
    if(Exibirmensagem == 1){
        cout << "O espaço alocado para a matriz foi limpo com sucesso!" << endl;
    }
    return;
};


void Limpar_geracoesmps(){ //Apenas limpa o txt Geracoes.mps para executar a função ProximaGeracao sem erros.
    ofstream outFIle;
    outFIle.open("datasets/Geracoes.mps", ios::out);
    if(!outFIle){
        cout << "O arquivo especificado (Geracoes.mps) não pôde ser aberto!" << endl;
        abort();
    }
    return;
};

void Executar(){
    Limpar_geracoesmps();
    cout << "\nDigite o número de gerações a ser avaliado: ";
    int NumerodeGeracoes, Cont_Geracoes = 0;
    cin >> NumerodeGeracoes;

    int Tam = DescobrirTamanho();
    char** Mapa = CriaMatriz(Tam);
    Mapa = PreencheMatriz(Mapa, Tam);
    
    do{
        Mapa = ProximaGeracao(Mapa, Tam, Cont_Geracoes);
        Cont_Geracoes = Cont_Geracoes + 1;
        cout << endl;
    }while(Cont_Geracoes!=NumerodeGeracoes+1);

    DestrutorMatriz(Mapa, Tam, 1);
    cout << "Finalizando o programa." << endl;
    return;
}
