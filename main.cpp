#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <time.h>
#include <iomanip>

using namespace std;

//---------------------------Funçoes auxiliares---------------------------
void SireVectorDesc(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        v[i] = n-i;
    }
}

void SireVectorAsc(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        v[i] = i;
    }
}

void SireVectorRoadom(int *v, int n){
    const int low = 0;
    const int high = n*100;

    for (int i=0; i < n; ++i) {

        v[i] = rand() % ( high - low + 1 ) + low;
    }
}

void WriteVetorFile(string file_name, int size, int *v){
    ofstream out(file_name);

    for(int i = 0; i < size; i++ )
    {
        out << v[i];
        out << ";";
    }

    out.close();
}

void WriteVetorFileResult(string file_name, string *info, int size){
    ofstream ate(file_name);
    for(int i = 0; i < size; i++)
    {
        ate << info[i]+"\n";
    }
    ate.close();
}

void readVectorFile(string nome, int size, int *v)
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

void PrintVector(int *v, int n){
    for(int i = 0; i < n; i++)
    {
        cout << v[i] << " - ";
    }
}
//---------------------------Funçoes auxiliares---------------------------

//---------------------------Funçoes de ordenação---------------------------
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Particion(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void QuickSort(int *Vet, int Pi, int Pf)
{
    if(Pi < Pf)
    {
        int q = Particion(Vet,Pi,Pf);
        QuickSort(Vet,Pi,(q-1));
        QuickSort(Vet,(q+1),Pf);
    }
}

void Heapify(int *Vet, int i, int N)
{
    int M;
    int l = 2*i;
    int r = (2*i)+1;
    if (l <=N && Vet[l] > Vet[i])
    {
        M = l;
    }
    else
    {
        M = i;
    }
    if(r <= N && Vet[r] > Vet[M])
    {
        M = r;
    }
    if(M != i)
    {
        swap(Vet[i],Vet[M]);
        Heapify(Vet,M,N);
    }
}
void Build_Heap(int *Vet, int N)
{
    for( int i = (N-1)/2; i > 0; i--)
    {
        Heapify(Vet, i, N);
    }
}
void HeapSort(int *Vet, int N)
{
    Build_Heap(Vet, N);
    for(int i = N-1; i > 0;)
    {
        swap(Vet[0],Vet[i]);
        i--;
        Heapify(Vet,0,i);
    }
}

void Merge(int *v, int Pi, int Pf, int M)
{
    int i,j,k;
    i = Pi;
    j = M+1;
    k = 0;
    int vet[Pf-Pi+1];
    while (i <= M && j <= Pf)
    {
        if(v[i] < v[j])
        {
            vet[k] = v[i];
            i++;
        }
        else
        {
            vet[k] = v[j];
            j++;
        }
        k++;
    }
    for(;i <= M; i++,k++)
    {
        vet[k] = v[i];
    }
    for(;j <= Pf; j++,k++)
    {
        vet[k] = v[j];
    }

    i = Pi;

    for( int o = 0; o < k; o++)
    {
        v[i] = vet[o];
        i++;
    }
}
void MergeSort(int *V, int Pi, int Pf)
{

    if(Pi<Pf)
    {
        int M=(Pi+Pf)/2;
        MergeSort(V,Pi,M);
        MergeSort(V,M+1,Pf);
        Merge(V,Pi,Pf,M);
    }
}

void BlublleSort(int *v, int n)
{
    int aux;
    for(int i=(n-1); i > 0; i--)
    {
        for(int j=0; j < i; j++)
        {
            if(v[j]>v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void InsertSort(int *v, int n){
    int aux,i,j;
    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i-1; j>=0 && aux < v[j]; j--)
        {
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}

void SelectSort(int *v, int n){
    int i, j, m, aux;
    for(i = 0; i < n-1; i++){
        m = i;
        for(j = i+1; j < n; j++){
            if(v[m] > v[j]){
                m = j;
            }
        }
        aux = v[i];
        v[i] = v[m];
        v[m] = aux;
    }
}


void CountingSort(int *A, int N, int K)
{
    int C[K], B[N];
    for(int i = 0; i <= K; i++)
    {
        C[i] = 0;
    }

    for(int i = 0; i < N; i++)
    {
        C[A[i]]++;
    }

    for(int i = 1; i <= K; i++)
    {
        C[i] += C[i-1];
    }

    for(int i = (N-1); i >= 0; i--)
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    for(int i = 0; i < N; i++)
    {
        A[i] = B[i];
    }
}
void CountingSort_start(int *vet, int N)
{
    int K = vet[0];
    for(int i = 1; i < N; i++)
    {
        if(K < vet[i])
        {
            K = vet[i];
        }
    }
    CountingSort(vet, N, K);
}

//---------------------------Funçoes de ordenação---------------------------

//---------------------------Geração de dados---------------------------
void GerarDados()
{

    cout << endl << "...........Gerando Banco para teste..........." << endl;

    cout << endl << "...........VALORES RANDO..........." << endl;

    // DECLARACAO DE VETORES PARA RANDON
    int *vet_rando_10 = new int [10];
    int *vet_rando_100 = new int [100];
    int *vet_rando_1000 = new int [1000];
    int *vet_rando_10000 = new int [10000];
    int *vet_rando_100000 = new int [100000];
    int *vet_rando_1000000 = new int [1000000];

    // GERACAO DE VALORES PARA OS VETORES
    SireVectorRoadom(vet_rando_10,10);
    SireVectorRoadom(vet_rando_100,100);
    SireVectorRoadom(vet_rando_1000,1000);
    SireVectorRoadom(vet_rando_10000,10000);
    SireVectorRoadom(vet_rando_100000,100000);
    SireVectorRoadom(vet_rando_1000000,1000000);

    // SALVA OS VETORES EM TXT PARA EFETUAR OS TESTE COM A MESMA BASE DE DADOS
    WriteVetorFile("vet_randon_10.txt",  10, vet_rando_10);
    WriteVetorFile("vet_randon_100.txt",  100, vet_rando_100);
    WriteVetorFile("vet_randon_1000.txt",  1000, vet_rando_1000);
    WriteVetorFile("vet_randon_10000.txt",  10000, vet_rando_10000);
    WriteVetorFile("vet_randon_100000.txt",  100000, vet_rando_100000);
    WriteVetorFile("vet_randon_1000000.txt",  1000000, vet_rando_1000000);


    delete [] vet_rando_10;
    delete [] vet_rando_100;
    delete [] vet_rando_1000;
    delete [] vet_rando_10000;
    delete [] vet_rando_100000;
    delete [] vet_rando_1000000;

    cout << endl << "...........VALORES DECRECENTE..........." << endl;

    // DECLARACAO DE VETORES PARA DECRECENTE
    int *vet_desc_10 = new int [10];
    int *vet_desc_100 = new int [100];
    int *vet_desc_1000 = new int [1000];
    int *vet_desc_10000 = new int [10000];
    int *vet_desc_100000 = new int [100000];
    int *vet_desc_1000000 = new int [1000000];


    // GERACAO DE VALORES PARA OS VETORES
    SireVectorDesc(vet_desc_10,10);
    SireVectorDesc(vet_desc_100,100);
    SireVectorDesc(vet_desc_1000,1000);
    SireVectorDesc(vet_desc_10000,10000);
    SireVectorDesc(vet_desc_100000,100000);
    SireVectorDesc(vet_desc_1000000,1000000);

    // SALVA OS VETORES EM TXT PARA EFETUAR OS TESTE COM A MESMA BASE DE DADOS
    WriteVetorFile("vet_desc_10.txt",  10, vet_desc_10);
    WriteVetorFile("vet_desc_100.txt",  100, vet_desc_100);
    WriteVetorFile("vet_desc_1000.txt",  1000, vet_desc_1000);
    WriteVetorFile("vet_desc_10000.txt",  10000, vet_desc_10000);
    WriteVetorFile("vet_desc_100000.txt",  100000, vet_desc_100000);
    WriteVetorFile("vet_desc_1000000.txt",  1000000, vet_desc_1000000);

    delete [] vet_desc_10;
    delete [] vet_desc_100;
    delete [] vet_desc_1000;
    delete [] vet_desc_10000;
    delete [] vet_desc_100000;
    delete [] vet_desc_1000000;


    cout << endl << "...........VALORES CRECENTE..........." << endl;

    // DECLARACAO DE VETORES PARA CRECENTE
    int *vet_asc_10 = new int [10];
    int *vet_asc_100 = new int [100];
    int *vet_asc_1000 = new int [1000];
    int *vet_asc_10000 = new int [10000];
    int *vet_asc_100000 = new int [100000];
    int *vet_asc_1000000 = new int [1000000];

    // GERACAO DE VALORES PARA OS VETORES
    SireVectorAsc(vet_asc_10,10);
    SireVectorAsc(vet_asc_100,100);
    SireVectorAsc(vet_asc_1000,1000);
    SireVectorAsc(vet_asc_10000,10000);
    SireVectorAsc(vet_asc_100000,100000);
    SireVectorAsc(vet_asc_1000000,1000000);

    // SALVA OS VETORES EM TXT PARA EFETUAR OS TESTE COM A MESMA BASE DE DADOS
    WriteVetorFile("vet_asc_10.txt",  10, vet_asc_10);
    WriteVetorFile("vet_asc_100.txt",  100, vet_asc_100);
    WriteVetorFile("vet_asc_1000.txt",  1000, vet_asc_1000);
    WriteVetorFile("vet_asc_10000.txt",  10000, vet_asc_10000);
    WriteVetorFile("vet_asc_100000.txt",  100000, vet_asc_100000);
    WriteVetorFile("vet_asc_1000000.txt",  1000000, vet_asc_1000000);

    delete [] vet_asc_10;
    delete [] vet_asc_100;
    delete [] vet_asc_1000;
    delete [] vet_asc_10000;
    delete [] vet_asc_100000;
    delete [] vet_asc_1000000;

//
    cout << endl << "...........FIM  Gerando Banco para teste..........." << endl;
}
//---------------------------Geração de dados---------------------------

//---------------------------Teste de tempo---------------------------

enum string_code {
    desc,
    asc,
    randon
};

enum string_code_func {
    insertSort,
    selectSort,
    blublleSort,
    mergeSort,
    quickSort,
    heapSort,
    countingSort_start
};

string_code hashit (string const& inString) {
    if (inString == "desc") return desc;
    if (inString == "asc") return asc;
    if (inString == "randon") return randon;
}

string_code_func hashit_func (string const& inString) {
    if (inString == "insertSort") return insertSort;
    if (inString == "selectSort") return selectSort;
    if (inString == "blublleSort") return blublleSort;
    if (inString == "mergeSort") return mergeSort;
    if (inString == "quickSort") return quickSort;
    if (inString == "heapSort") return heapSort;
    if (inString == "countingSort_start") return countingSort_start;
}

string TestTime(string name_function, string amostra)
{

    int vet_10[10];
    int vet_100[100];
    int vet_1000[1000];
    int vet_10000[10000];
    int vet_100000[100000];
    int vet_1000000[1000000];

    switch(hashit(amostra)) {
        case desc:

            readVectorFile("vet_desc_10.txt", 10, vet_10);
            readVectorFile("vet_desc_100.txt", 100, vet_100);
            readVectorFile("vet_desc_1000.txt", 1000, vet_1000);
            readVectorFile("vet_desc_10000.txt", 10000, vet_10000);
            readVectorFile("vet_desc_100000.txt", 100000, vet_100000);
            readVectorFile("vet_desc_1000000.txt", 1000000, vet_1000000);

            break;
        case asc:
            readVectorFile("vet_asc_10.txt", 10, vet_10);
            readVectorFile("vet_asc_100.txt", 100, vet_100);
            readVectorFile("vet_asc_1000.txt", 1000, vet_1000);
            readVectorFile("vet_asc_10000.txt", 10000, vet_10000);
            readVectorFile("vet_asc_100000.txt", 100000, vet_100000);
            readVectorFile("vet_asc_1000000.txt", 1000000, vet_1000000);
            break;
        case randon:
            readVectorFile("vet_randon_10.txt", 10, vet_10);
            readVectorFile("vet_randon_100.txt", 100, vet_100);
            readVectorFile("vet_randon_1000.txt", 1000, vet_1000);
            readVectorFile("vet_randon_10000.txt", 10000, vet_10000);
            readVectorFile("vet_randon_100000.txt", 100000, vet_100000);
            readVectorFile("vet_randon_1000000.txt", 1000000, vet_1000000);
            break;

    }

    string resultado = name_function + " - " + amostra + ";";
    clock_t start, end;
    double time_1 = 0.0 ;
    double time_2 = 0.0 ;
    double time_3 = 0.0 ;
    double time_4 = 0.0 ;
    double time_5 = 0.0 ;
    double time_6 = 0.0 ;

    switch(hashit_func(name_function)) {
        case insertSort:
            cout << "insertSort Testando para base 10........" << endl;
            start = clock();
            InsertSort(vet_10,10);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << " insertSortTestando para base 100........" << endl;
            start = clock();
            InsertSort(vet_100,100);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << " insertSort Testando para base 1000........" << endl;
            start = clock();
            InsertSort(vet_1000,1000);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << " insertSort Testando para base 10000........" << endl;
            start = clock();
            InsertSort(vet_10000,10000);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "insertSort Testando para base 100000........" << endl;
            start = clock();
            InsertSort(vet_100000,100000);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "insertSort Testando para base 1000000........" << endl;
            start = clock();
            InsertSort(vet_1000000,1000000);
            end = clock();
            time_6 = (end - start)/1000000.0;

//            feito
            break;
        case selectSort:
            cout << " selectSort Testando para base 10........" << endl;
            start = clock();
            SelectSort(vet_10,10);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "selectSort Testando para base 100........" << endl;
            start = clock();
            SelectSort(vet_100,100);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "selectSort Testando para base 1000........" << endl;
            start = clock();
            SelectSort(vet_1000,1000);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "selectSort Testando para base 10000........" << endl;
            start = clock();
            SelectSort(vet_10000,10000);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "selectSort Testando para base 100000........" << endl;
            start = clock();
            SelectSort(vet_100000,100000);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "selectSort Testando para base 1000000........" << endl;
            start = clock();
            SelectSort(vet_1000000,1000000);
            end = clock();
            time_6 = (end - start)/1000000.0;

            break;
        case blublleSort:
            cout << "blublleSort Testando para base 10........" << endl;
            start = clock();
            BlublleSort(vet_10,10);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "blublleSort Testando para base 100........" << endl;
            start = clock();
            BlublleSort(vet_100,100);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "blublleSort Testando para base 1000........" << endl;
            start = clock();
            BlublleSort(vet_1000,1000);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "blublleSort Testando para base 10000........" << endl;
            start = clock();
            BlublleSort(vet_10000,10000);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "blublleSort Testando para base 100000........" << endl;
            start = clock();
            BlublleSort(vet_100000,100000);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "blublleSort Testando para base 1000000........" << endl;
            start = clock();
            BlublleSort(vet_1000000,1000000);
            end = clock();
            time_6 = (end - start)/1000000.0;

//            feito
            break;
        case mergeSort:
            cout << "mergeSort Testando para base 10........" << endl;
            start = clock();
            MergeSort(vet_10,0,10-1);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "mergeSort Testando para base 100........" << endl;
            start = clock();
            MergeSort(vet_100,0,100-1);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "mergeSort Testando para base 1000........" << endl;
            start = clock();
            MergeSort(vet_1000,0,1000-1);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "mergeSort Testando para base 10000........" << endl;
            start = clock();
            MergeSort(vet_10000,0,10000-1);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "mergeSort Testando para base 100000........" << endl;
            start = clock();
            MergeSort(vet_100000,0,100000-1);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "mergeSort Testando para base 1000000........" << endl;
            start = clock();
            MergeSort(vet_1000000,0,1000000-1);
            end = clock();
            time_6 = (end - start)/1000000.0;

            //            feito
            break;
        case quickSort:
            cout << "quickSort Testando para base 10........" << endl;
            start = clock();
            QuickSort(vet_10,0,10-1);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "quickSort Testando para base 100........" << endl;
            start = clock();
            QuickSort(vet_100,0,100-1);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "quickSort Testando para base 1000........" << endl;
            start = clock();
            QuickSort(vet_1000,0,1000-1);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "quickSort Testando para base 10000........" << endl;
            start = clock();
            QuickSort(vet_10000,0,10000-1);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "quickSort Testando para base 100000........" << endl;
            start = clock();
            QuickSort(vet_100000,0,100000-1);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "quickSort Testando para base 1000000........" << endl;
            start = clock();
            QuickSort(vet_1000000,0,1000000-1);
            end = clock();
            time_6 = (end - start)/1000000.0;

//            feito

            break;
        case heapSort:
            cout << "heapSort Testando para base 10........" << endl;
            start = clock();
            HeapSort(vet_10,10);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "heapSort Testando para base 100........" << endl;
            start = clock();
            HeapSort(vet_100,100);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "heapSort Testando para base 1000........" << endl;
            start = clock();
            HeapSort(vet_1000,1000);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "heapSort Testando para base 10000........" << endl;
            start = clock();
            HeapSort(vet_10000,10000);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "heapSort Testando para base 100000........" << endl;
            start = clock();
            HeapSort(vet_100000,100000);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "heapSort Testando para base 1000000........" << endl;
            start = clock();
            HeapSort(vet_1000000,1000000);
            end = clock();
            time_6 = (end - start)/1000000.0;
            break;
        case countingSort_start:
            cout << "countingSort_start Testando para base 10........" << endl;
            start = clock();
            CountingSort_start(vet_10,10);
            end = clock();
            time_1 = (end - start)/1000000.0;

            cout << "countingSort_start Testando para base 100........" << endl;
            start = clock();
            CountingSort_start(vet_100,100);
            end = clock();
            time_2 = (end - start)/1000000.0;

            cout << "countingSort_start Testando para base 1000........" << endl;
            start = clock();
            CountingSort_start(vet_1000,1000);
            end = clock();
            time_3 = (end - start)/1000000.0;

            cout << "countingSort_start Testando para base 10000........" << endl;
            start = clock();
            CountingSort_start(vet_10000,10000);
            end = clock();
            time_4 = (end - start)/1000000.0;

            cout << "countingSort_start Testando para base 100000........" << endl;
            start = clock();
            CountingSort_start(vet_100000,100000);
            end = clock();
            time_5 = (end - start)/1000000.0;

            cout << "countingSort_start Testando para base 1000000........" << endl;
            start = clock();
            CountingSort_start(vet_1000000,1000000);
            end = clock();
            time_6 = (end - start)/1000000.0;

            break;

    }
    return resultado + to_string(time_1) + ";" + to_string(time_2) + ";" + to_string(time_3) + ";" + to_string(time_4) + ";" + to_string(time_5) + ";" + to_string(time_6) + ";";

}
//---------------------------Teste de tempo---------------------------


int main() {
    cout << endl << endl << "---------------------------Teste de Orenação---------------------------" << endl << endl;

    string result[28];
    result[0] = "Nome Funcao;T:10;T:100;T:1000;T:10000;T:100000;T:1000000";

    GerarDados();

    /*cout << endl << endl << "------------Testando insertSort para desc ------------" << endl << endl;
    result[1] = TestTime("insertSort", "desc");

    cout << endl << endl << "------------Testando insertSort para asc ------------" << endl << endl;
    result[2] = TestTime("insertSort", "asc");

    cout << endl << endl << "------------Testando insertSort para randon ------------" << endl << endl;
    result[3] = TestTime("insertSort", "randon");


    result[4] = "---------;---------;---------;---------;---------";

    cout << endl << endl << "------------Testando SelectSort para desc ------------" << endl << endl;
    result[5] = TestTime("selectSort", "desc");

    cout << endl << endl << "------------Testando SelectSort para asc ------------" << endl << endl;
    result[6] = TestTime("selectSort", "asc");

    cout << endl << endl << "------------Testando SelectSort para randon ------------" << endl << endl;
    result[7] = TestTime("selectSort", "randon");

result[8] = "---------;---------;---------;---------;---------";

    cout << endl << endl << "------------Testando blublleSort para desc ------------" << endl << endl;
    result[9] = TestTime("blublleSort", "desc");

    cout << endl << endl << "------------Testando blublleSort para asc ------------" << endl << endl;
    result[10] = TestTime("blublleSort", "asc");

    cout << endl << endl << "------------Testando blublleSort para randon ------------" << endl << endl;
    result[11] = TestTime("blublleSort", "randon");

result[12] = "---------;---------;---------;---------;---------";

    */cout << endl << endl << "------------Testando mergeSort para desc ------------" << endl << endl;
    result[13] = TestTime("mergeSort", "desc");
    cout << endl << endl << "------------Testando mergeSort para asc ------------" << endl << endl;
    result[14] = TestTime("mergeSort", "asc");
    cout << endl << endl << "------------Testando mergeSort para randon ------------" << endl << endl;
    result[15] = TestTime("mergeSort", "randon");

    result[16] = "---------;---------;---------;---------;---------";

    cout << endl << endl << "------------Testando quickSort para desc ------------" << endl << endl;
    result[17] = TestTime("quickSort", "desc");
    cout << endl << endl << "------------Testando quickSort para asc ------------" << endl << endl;
    result[18] = TestTime("quickSort", "asc");
    cout << endl << endl << "------------Testando quickSort para randon ------------" << endl << endl;
    result[19] = TestTime("quickSort", "randon");

    result[20] = "---------;---------;---------;---------;---------";

    cout << endl << endl << "------------Testando HeapSort para desc ------------" << endl << endl;
    result[21] = TestTime("heapSort", "desc");
    cout << endl << endl << "------------Testando HeapSort para asc ------------" << endl << endl;
    result[22] = TestTime("heapSort", "asc");
    cout << endl << endl << "------------Testando HeapSort para randon ------------" << endl << endl;
    result[23] = TestTime("heapSort", "randon");

    result[24] = "---------;---------;---------;---------;---------";

//    cout << endl << endl << "------------Testando countingSort_start para desc ------------" << endl << endl;
//    result[25] = TestTime("countingSort_start", "desc");
//    cout << endl << endl << "------------Testando countingSort_start para asc ------------" << endl << endl;
//    result[26] = TestTime("countingSort_start", "asc");
//    cout << endl << endl << "------------Testando countingSort_start para randon ------------" << endl << endl;
//    result[27] = TestTime("countingSort_start", "randon");
//    result[27] = "countingSort_start-randon;-------;-------;-------;-------";
//
    cout << endl << endl << "------------Salvando os Resultado no Arquivo------------" << endl << endl;
    WriteVetorFileResult("Resultado_teste.csv", result, 28);

    cout << endl << endl << "---------------------------Teste de Orenação---------------------------" << endl << endl;
    return 0;
}
