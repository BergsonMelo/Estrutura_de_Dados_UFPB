def merge_sort(lista, inicio, fim):
    if (inicio < fim - 1):
        meio = (inicio + fim)//2
        merge_sort(lista, inicio, meio)
        merge_sort(lista, meio, fim)
        merge(lista, inicio, meio, fim)
    return lista


def merge(lista, inicio, meio, fim):
    lista_vazia = []
    i = inicio
    j = meio

    while i < meio and j < fim:
        if lista[i] <= lista[j]:
            lista_vazia.append(lista[i])
            i += 1
        else:
            lista_vazia.append(lista[j])
            j += 1

    while i < meio:
        lista_vazia.append(lista[i])
        i += 1

    while j < fim:
        lista_vazia.append(lista[j])
        j += 1

    for k in range(inicio, fim):
        lista[k] = lista_vazia[k - inicio]

    return lista