def quick_sort(lista, inicio, fim):
  if(inicio < fim):
    indice_pivo = partition(lista, inicio, fim)
    quick_sort(lista, inicio, indice_pivo-1)
    quick_sort(lista, indice_pivo + 1, fim)
 
  return lista
 
def partition(lista, inicio, fim):
  pivo = lista[inicio]
  a = inicio
  b = fim
  while(a<= b):
    while(lista[b] >= pivo):
      b -= 1
      if(b == inicio):
            break
    while(lista[a] <= pivo):
      a += 1
      if(a == fim):
            break
    if(a>=b):
      break
    lista[a],lista[b] = lista[b],lista[a]
  lista[inicio], lista[b] = lista[b], lista[inicio]
  return b