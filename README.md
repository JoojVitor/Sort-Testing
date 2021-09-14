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

A tabela a seguir apresenta os resultados obtidos em nossos testes:

<table>
    <thead>
        <tr>
            <th>Método</th>
            <th>Caso</th>
            <th>10 elementos</th>
            <th>100 elementos</th>
            <th>1K elementos</th>
            <th>10K elementos</th>
            <th>100K elementos</th>
            <th>1Mi elementos</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=3>Insert Sort</td>
            <td>desc</td>
            <td>0.000004</td>
            <td>0.000019</td>
            <td>0.001620</td>
            <td>0.182767</td>
            <td>17.251184</td>
            <td>1611.838577</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000002</td>
            <td>0.000004</td>
            <td>0.000006</td>
            <td>0.000047</td>
            <td>0.000449</td>
            <td>0.004473</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000003</td>
            <td>0.000012</td>
            <td>0.00823</td>
            <td>0.079005</td>
            <td>7.943851</td>
            <td>799.206770</td>
        </tr>
        <tr>
            <td rowspan=3>Select Sort</td>
            <td>desc</td>
            <td>0.000003</td>
            <td>0.000019</td>
            <td>0.001410</td>
            <td>0.133461</td>
            <td>13.359896</td>
            <td>1343.629463</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000003</td>
            <td>0.0000015</td>
            <td>0.001354</td>
            <td>0.129305</td>
            <td>12.944675</td>
            <td>1306.872859</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000004</td>
            <td>0.000019</td>
            <td>0.001361</td>
            <td>0.134216</td>
            <td>12.956807</td>
            <td>1306.966180</td>
        </tr>
        <tr>
            <td rowspan=3>Bubble Sort</td>
            <td>desc</td>
            <td>0.000003</td>
            <td>0.000024</td>
            <td>0.002332</td>
            <td>0.241012</td>
            <td>23.713167</td>
            <td>2401.834658</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000003</td>
            <td>0.0000018</td>
            <td>0.001894</td>
            <td>0.154836</td>
            <td>15.277765</td>
            <td>1551.682540</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000004</td>
            <td>0.000032</td>
            <td>0.002354</td>
            <td>0.306766</td>
            <td>36.531915</td>
            <td>3758.580319</td>
        </tr>
        <tr>
            <td rowspan=3>Merge Sort</td>
            <td>desc</td>
            <td>0.000005</td>
            <td>0.000014</td>
            <td>0.000167</td>
            <td>0.001795</td>
            <td>0.019427</td>
            <td>--</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000010</td>
            <td>0.000009</td>
            <td>0.000098</td>
            <td>0.001441</td>
            <td>0.015994</td>
            <td>--</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000005</td>
            <td>0.000021</td>
            <td>0.000211</td>
            <td>0.002391</td>
            <td>0.027624</td>
            <td>--</td>
        </tr>
        <tr>
            <td rowspan=3>Quick Sort</td>
            <td>desc</td>
            <td>0.000003</td>
            <td>0.000029</td>
            <td>0.002901</td>
            <td>0.276623</td>
            <td>32.086353</td>
            <td>--</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000003</td>
            <td>0.000042</td>
            <td>0.004697</td>
            <td>0.394430</td>
            <td>46.614081</td>
            <td>--</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000003</td>
            <td>0.000014</td>
            <td>0.000163</td>
            <td>0.002214</td>
            <td>0.025998</td>
            <td>--</td>
        </tr>
        <tr>
            <td rowspan=3>Heap Sort</td>
            <td>desc</td>
            <td>0.000004</td>
            <td>0.000020</td>
            <td>0.000251</td>
            <td>0.003109</td>
            <td>0.038352</td>
            <td>0.482071</td>
        </tr>
        <tr>
            <td>asc</td>
            <td>0.000004</td>
            <td>0.000042</td>
            <td>0.000278</td>
            <td>0.003290</td>
            <td>0.041006</td>
            <td>0.498634</td>
        </tr>
        <tr>
            <td>random</td>
            <td>0.000005</td>
            <td>0.000023</td>
            <td>0.000325</td>
            <td>0.003789</td>
            <td>0.048847</td>
            <td>0.672122</td>
        </tr>
    </tbody>
</table>

    Obs.: O tempo das operações foram medidos em segundos.

## Especificação da maquina de testes
Neste projeto foi usada uma maquina virtual hospedada no serviço Google Cloud com as seguintes configurações:

    Processador: 4 vCPUs Intel(R) Xeon(R) CPU @ 2.20GHz
    Memória: 32GB
    SO: Ubuntu #56~18.04.1 x86_64, GNU/Linux
    Disco: 50GB
