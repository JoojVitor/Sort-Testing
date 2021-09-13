//
// Created by demo on 9/13/21.
//
#include <fstream>
#include <iostream>
#include <string>
#include "UtilidadesArquivo.h"

using namespace std;

void UtilidadesArquivo::readVectorFile(string nome, int size, int *v)
{
    ifstream arquivo;
    string line;
    arquivo.open(nome);
    int i = 0;
    if(arquivo.is_open())
    {
        while(arquivo.good())
        {
            getline(arquivo,line,';');
            if (i < size){
                v[i] = stoi(line);
                i++;
            }
        }
    }
}

void UtilidadesArquivo::SireVectorDesc(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        v[i] = n-i;
    }
}

void UtilidadesArquivo::SireVectorAsc(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        v[i] = i;
    }
}

void UtilidadesArquivo::SireVectorRoadom(int *v, int n){
    const int low = 0;
    const int high = n*100;

    for (int i=0; i < n; ++i) {

        v[i] = rand() % ( high - low + 1 ) + low;
    }
}

void UtilidadesArquivo::WriteVetorFile(string file_name, int size, int *v){
    ofstream out(file_name);

    for(int i = 0; i < size; i++ )
    {
        out << v[i];
        out << ";";
    }

    out.close();
}

void UtilidadesArquivo::WriteVetorFileResult(string file_name, string *info, int size){
    ofstream ate(file_name);
    for(int i = 0; i < size; i++)
    {
        ate << info[i]+"\n";
    }
    ate.close();
}

void UtilidadesArquivo::PrintVector(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " - ";
    }
}