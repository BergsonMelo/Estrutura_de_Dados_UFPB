def insertion_sort(array):
    tam = len(array)
    for pos_pivor in range(1, tam):
        valor_atual = array[pos_pivor]
        j = pos_pivor
        # pecorre o array da posicao atual para tras até a posicao zero
        # ou até encontrar alguem menor que o valor atual
        while j > 0 and array[j-1] > valor_atual:
            # dando um shift pra direita nos valores maiores que o valor atual
            array[j] = array[j-1]
            j -= 1
        # inserindo o valor atual na posição correta
        array[j] = valor_atual
    return array