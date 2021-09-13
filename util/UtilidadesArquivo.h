//
// Created by demo on 9/13/21.
//

#ifndef MAIN_CPP_UTILIDADESARQUIVO_H
#define MAIN_CPP_UTILIDADESARQUIVO_H

class UtilidadesArquivo {
public:
    void readVectorFile(std::string nome, int size, int *v);
    void SireVectorDesc(int *v, int n);
    void SireVectorAsc(int *v, int n);
    void SireVectorRoadom(int *v, int n);
    void WriteVetorFile(std::string file_name, int size, int *v);
    void WriteVetorFileResult(std::string file_name, std::string *info, int size);
    void PrintVector(int *v, int n);
};


#endif //MAIN_CPP_UTILIDADESARQUIVO_H
