# Runtime testing on sorting algorithms

Members:
- João Vitor dos Santos Couto
- Norton Pereira Ricardo
- Gabriel de Castro Gonçalves
- Wellington Soares de Morais

This work aims to analyze the execution time of each sorting method, considering the best and worst case and a random case.

## Algoritmos
- InsertSort
- SelectSort
- BubbleSort
- MergeSort
- QuickSort
- HeapSort
- CountingSort

## Execution 
Initially, vectors of capacities 10, 100, 1000, 10000, 100000, 1000000 with random values are generated. Each ordering method contemplates the best case, the worst case and the random case, measuring the execution time in milliseconds.

    Ps.: Execution time is very long!

## Result
At the end of the execution, a .csv file is generated with the relation of the time of each sorting method, the case and the number of values.

The table below shows the results obtained in our tests:

<table>
    <thead>
        <tr>
            <th>Method</th>
            <th>Case</th>
            <th>10 elements</th>
            <th>100 elements</th>
            <th>1K elements</th>
            <th>10K elements</th>
            <th>100K elements</th>
            <th>1Mi elements</th>
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

    Ps.: The times of operations were measured in seconds.

## Test machine specification
In this project, a virtual machine hosted on the Google Cloud service was used with the following settings:

    Processor: 4 vCPUs Intel(R) Xeon(R) CPU @ 2.20GHz
    Memory: 32GB
    OS: Ubuntu #56~18.04.1 x86_64, GNU/Linux
    Hard disk: 50GB
