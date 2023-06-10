import insertion_sort
import bubble_sort
import selection_sort
import quick_sort
import merge_sort
import time


arquivos = [r"instancias-num\num1000.txt", r"instancias-num\num_1000_3.txt",
            r"instancias-num\num_1000_4.txt", r"instancias-num\num_10000_3.txt",
            r"instancias-num\num_10000.txt", r"instancias-num\num_10000_1.txt",
            r"instancias-num\num_10000_3.txt", r"instancias-num\num_10000_4.txt",
            r"instancias-num\num_100000_1.txt", r"instancias-num\num_100000_2.txt",
            r"instancias-num\num_10000_3.txt"]

lista_de_arrays = []
for arquivo in arquivos:
    with open(arquivo, "r") as txt:
        linhas = [linha.strip() for linha in txt.readlines()]
    array = [int(linha) for linha in linhas]
    lista_de_arrays.append(array)


for array in lista_de_arrays:
    print(f"\n=> Testando com array de tamanho: {len(array)}")
    print(f"selection sort")
    hora_inicial = time.time()
    selection_sort.selection_sort(array.copy())
    hora_final = time.time()
    print(f"--Tempo gasto: {hora_final-hora_inicial}")

    print(f"bubble sort")
    hora_inicial = time.time()
    bubble_sort.bubble_sort(array.copy())
    hora_final = time.time()
    print(f"--Tempo gasto: {hora_final - hora_inicial}")

    print(f"insertion sort")
    hora_inicial = time.time()
    insertion_sort.insertion_sort(array.copy())
    hora_final = time.time()
    print(f"--Tempo gasto: {hora_final - hora_inicial}")

    print(f"merge sort")
    hora_inicial = time.time()
    merge_sort.merge_sort(array.copy(), 0, len(array.copy())-1)
    hora_final = time.time()
    print(f"--Tempo gasto: {hora_final - hora_inicial}")

    print(f"quick sort")
    hora_inicial = time.time()
    quick_sort.quick_sort(array.copy(), 0, len(array.copy())-1)
    hora_final = time.time()
    print(f"--Tempo gasto: {hora_final - hora_inicial}")
