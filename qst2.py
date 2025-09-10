n_filmes, n_atores = map(int, input().split(' '))
filmes: list[list[int]] = []

for i in range(n_filmes):
    filmes.append(list(map(int, input().split(' ')))[1:])

grafo: dict[int, set[int]] = {}

for i, filme in enumerate(filmes):
    for ator in filme:
        for outro in filme:
            if ator == outro:
                continue
            
            if ator not in grafo:
                grafo[ator] = set()
            
            if outro not in grafo:
                grafo[outro] = set()
            
            grafo[ator].add(outro)
            grafo[outro].add(ator)

def bfs(ini: int, fim: int):
    fila = [ini]
    closed = { ini }
    came = { ini: None }
    
    while fila:
        valor = fila.pop(0)
        
        if valor == fim:
            caminho = []
            atual = fim
            
            while atual in came:
                caminho.append(atual)
                atual = came[atual]
            
            return caminho[::-1]
        
        for vizinho in grafo[valor]:
            if vizinho in closed:
                continue
            
            fila.append(vizinho)
            closed.add(vizinho)
            came[vizinho] = valor
            
    return []
                
n_consultas = int(input())
consultas: list[tuple[int, int]] = []

for i in range(n_consultas):
    consultas.append(tuple(map(int, input().split(' '))))

for consulta in consultas:  
    res_atores = bfs(consulta[0], consulta[1])
    
    if len(res_atores) == 0:
        print('-1')
    else:
        print(len(res_atores))
        
        res: list[int] = []
        
        for i in range(1, len(res_atores)):
            for filme in range(n_filmes):
                if res_atores[i-1] in filmes[filme] and res_atores[i] in filmes[filme]:
                    res.extend([res_atores[i-1], filme + 1])
                    break
    
        res.append(res_atores[-1])
    
        print(' '.join(map(lambda x: str(x), res)))