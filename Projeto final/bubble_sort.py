def bubble_sort(array):
    trocou = True
    while trocou:
        trocou = False
        elementos_ordenados = 0
        for pos_inicial in range(0, len(array) - elementos_ordenados - 1):
            if array[pos_inicial] > array[pos_inicial+1]:
                aux = array[pos_inicial]
                array[pos_inicial] = array[pos_inicial+1]
                array[pos_inicial+1] = aux
                trocou = True
        elementos_ordenados += 1
    return array