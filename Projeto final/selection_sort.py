def selection_sort(array):
    for pos_inicio in range(len(array)):
        min_valor = pos_inicio
        for pos in range(pos_inicio+1, len(array)):
            if array[min_valor] > array[pos]:
                min_valor = pos
        aux = array[pos_inicio]
        array[pos_inicio] = array[min_valor]
        array[min_valor] = aux
    return array