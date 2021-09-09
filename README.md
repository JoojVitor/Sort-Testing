# Teste de tempo de execução em algoritmos de ordenação
Este trabalho visa analisar o tempo de execução de cada método de ordenação, considerando o melhor e pior caso e um caso aleatório.

## Algoritmos
- InsertSort
- SelectSort
- BubbleSort
- MergeSort
- QuickSort
- HeapSort
- CountingSort

## Execução 
Inicialmente são gerados vetores de capacidades 10, 100, 1000, 10000, 100000, 1000000 com valores aleatórios. Cada método de ordenação contempla o melhor caso, o pior caso e o caso aleatório, medindo o tempo de execução em milissegundo.

    Obs.: O tempo para execução é bastante demorado!

## Resultado
No final da execução é gerado um arquivo .csv com a relação do tempo de cada método de ordenação, o caso e a quantidade de valores.

## Especificação da maquina de testes
Neste projeto foi usada uma maquina virtual hospedada no serviço Google Cloud com as seguintes configurações:

    Processador: 4 vCPUs Intel(R) Xeon(R) CPU @ 2.20GHz
    Memória: 32GB
    SO: Ubuntu #56~18.04.1 x86_64, GNU/Linux
    Disco: 50GB
