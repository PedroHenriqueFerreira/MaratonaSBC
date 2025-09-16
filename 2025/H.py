n, k = map(int, input().split())
alunos = []

for i in range(n):
    alunos.append(int(input(), 2))

m = int(input())

objetivos = []

for i in range(m): 
    objetivos.append(int(input(), 2))

for objetivo in objetivos:
    validos: list[int] = []
    
    for aluno in alunos:
        if ~(~aluno | objetivo) != 0:
            continue
            
        validos.append(aluno)
    
    print(validos)
    