#include <bits/stdc++.h>
#include "CamadaFisica.hpp"

using namespace std;

void AplicacaoTransmissora() {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    getline(cin, mensagem);
    CamadaDeAplicacaoTransmissora(mensagem);
}


void CamadaDeAplicacaoTransmissora(string msg) {
    string mensagem_binaria;

    // Esse FOR serve para transformar as letras e/ou numeros em bytes.
    for (int i = 0; i < (int)msg.length(); i++) {
        char k = msg[i];
        int byte = (int) k;

        // Aqui é onde o byte se transforma em bit com divisoes.
        for (int n = 7; n >= 0; n--) {
            if ((int)byte / (int)pow(2, n) == 1) {
                byte = byte - (int)pow(2, n);
                mensagem_binaria += '1';
            } else {
                mensagem_binaria += '0';
            }
        }
    }
    CamadaFisicaTransmissora(mensagem_binaria);
}


void CamadaFisicaTransmissora(string binaria) {
    int tipoDeCodificacao = 2;
    string fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case 0:  // Binária;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(binaria);
            break;
        case 1:  // Manchester;
           fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(binaria);
           break;
        case 2:  // Bipolar;
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(binaria);
            break;
    }

    MeioDeComunicacao(fluxoBrutoDeBits);
}


void MeioDeComunicacao(string fluxo) {
    string fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;

    fluxoBrutoDeBitsPontoA = fluxo;

    while (fluxoBrutoDeBitsPontoB != fluxoBrutoDeBitsPontoA) {
        fluxoBrutoDeBitsPontoB += fluxoBrutoDeBitsPontoA;
    }

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora(string fluxoBrutoDeBitsPontoB) {
    int tipoDeDecodificacao = 2;  // Alterar junto com o tipo de Codificacao;
    string fluxoBrutoDeBits;

    switch (tipoDeDecodificacao) {
        case 0:  //decodificacao Binaria
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(fluxoBrutoDeBitsPontoB);
            break;
        case 1:  //decodificacao Manchester
           fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(fluxoBrutoDeBitsPontoB);
           break;
        case 2:  //decodificacao Bipolar;
            fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBipolar(fluxoBrutoDeBitsPontoB);
            break;
    }

    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

void CamadaDeAplicacaoReceptora(string fluxoBrutoDeBits) {
    string mensagem;

    for (int i = 0; i < (int)fluxoBrutoDeBits.length(); i=i+8) {
        int soma = 0;

        for (int k = 0; k < 8; k++) {
            soma += ((int)fluxoBrutoDeBits[i+k]-'0')*(int)pow(2, 7 - k);
        }
          mensagem.push_back((char)soma);
    }

    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora (string mensagem) {

    cout << "A mensagem recebida foi: " << mensagem << endl;
}


string CamadaFisicaTransmissoraCodificacaoBinaria(string mensagem) {

    cout << mensagem << endl;
    return mensagem;
}

string CamadaFisicaReceptoraDecodificacaoBinaria(string mensagem){

    return mensagem;
}

string CamadaFisicaTransmissoraCodificacaoBipolar(string mensagem) {

    string mensagem_bipolada;

    for (int i = 0; i < (int)mensagem.length(); i++) {

        if (mensagem[i] == '0') {

            mensagem_bipolada += '-';
            mensagem_bipolada += '1';
        } else {

            mensagem_bipolada += mensagem[i];
        }
    }
    cout<<mensagem_bipolada<<endl;

    return mensagem_bipolada;
}
string CamadaFisicaReceptoraDecodificacaoBipolar(string mensagem){

    string mensagem_bipolar_decodificada;

    for (int i = 0; i < (int)mensagem.length(); i++) {

        if (mensagem[i] == '-') {

            mensagem_bipolar_decodificada += '0';
            i++;

        } else {

            mensagem_bipolar_decodificada += '1';
        }
    }

    return mensagem_bipolar_decodificada;
}


string CamadaFisicaTransmissoraCodificacaoManchester(string mensagem){

    string mensagem_manchester;

    for (int i = 0; i < (int)mensagem.length(); i++) {

        if (mensagem[i]=='0') {
            mensagem_manchester += '1';
            mensagem_manchester += '0';

        } else {

            mensagem_manchester += '0';
            mensagem_manchester += '1';
        }
    }

    cout << mensagem_manchester << endl;

    return mensagem_manchester;
}

string CamadaFisicaReceptoraDecodificacaoManchester(string mensagem) {

    string mensagem_manchester_decodificada;

    for (int i = 0; i < (int)mensagem.length(); i=i+2) {

        if (mensagem[i] == '0') {

            mensagem_manchester_decodificada += '1';

        } else {

            mensagem_manchester_decodificada += '0';

        }
    }

    return mensagem_manchester_decodificada;

}
