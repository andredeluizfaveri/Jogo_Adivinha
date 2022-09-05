#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
    int  chutesmax = 5;
    int chute, tentativas = 5, numero_secreto;
    bool acertou = 0, errou =0;
    double pontos = 10.0;
    char dificuldade;
void cabecario (){
    cout << endl << endl;
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhação! *" << endl;
    cout << "***************************************" << endl<< endl<< endl;
}
void escolhendodificuldade(){
    bool identificador = 0;
    while (identificador == false){
    cout << "ESCOLHA O NÍVEL DE DIFICULDADE:" << "  Fácil (f) | Médio (m) | Difícil (d)"<< endl;
    cin >> dificuldade;
    if (dificuldade == 'f'){
        chutesmax = 8;
        tentativas = chutesmax;
        break;
    }else if (dificuldade == 'm'){
        chutesmax = 6;
        tentativas = chutesmax;
        break;
    }else if (dificuldade == 'd') {
        chutesmax = 3;
        tentativas = chutesmax;
        break;
    }else {
        cout << "Você digitou a opção errada, tente novamente." << endl;
        identificador = 0;
    }
    }
    cout << "Você tem " << chutesmax << " chutes" << endl;
}
void aleatrorio (){
    unsigned seed = time(0);
    srand(seed);
    numero_secreto = rand()%10;
}
void verificapontos(){
   if (dificuldade == 'f'){
    double pontos_perdidos = abs(chute - numero_secreto)/2.0;
    pontos = pontos - pontos_perdidos;
   }else if (dificuldade == 'm'){
    double pontos_perdidos = abs(chute - numero_secreto)/4.0;
    pontos = pontos - pontos_perdidos; 
   }else {
    double pontos_perdidos = abs(chute - numero_secreto)/6.0;
    pontos = pontos - pontos_perdidos;
   }
}
void verificachute (){
        while (acertou == 0)
    {
        verificapontos();
        cout << "Digite seu chute: ";
        cin >> chute;
        if (chute == numero_secreto)
        {
            acertou = 1;
        } else if (chute > numero_secreto)
        {
            tentativas --;
            cout << "Seu chute foi maior que o número secreto!" << endl;
            cout << "Você tem " << tentativas << " chutes." << endl;

        } else if (chute < numero_secreto)
        {
            tentativas --;
            cout << "Seu chute foi menor que o número secreto!" << endl;
            cout << "Você tem " << tentativas << " chutes." << endl;
        }
        if(tentativas == 0)
        {
            errou = true;
            break;
        }
        
    } 
}
void fimdejogo(){
    system ("clear");
    if (acertou)
    {
        cout << "Parabéns! Você acertou sobrando " << tentativas << " tentativas!!" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontos << " pontos" << endl;
    } else {
        cout << "Infelizmente você PERDEU, ficaremos felizes se tentar novamente!" << endl << endl;
    }  
    cout << "O JOGO ACABOU!";
}

int main (){

    cabecario();
    escolhendodificuldade();
    aleatrorio();
    verificachute();
    fimdejogo();
return 0;
}
