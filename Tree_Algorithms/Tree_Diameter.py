from collections import defaultdict, deque
import sys

sys.setrecursionlimit(200010)

class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = defaultdict(list)
        self.visited = set()
        self.maxx = -1
        self.X = None

    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def bfs(self, u):
        q = deque()
        q.append((u, 0))
        while q:
            u, dist = q.popleft()
            if self.maxx < dist:
                self.maxx = dist
                self.X = u
            self.visited.add(u)
            for v in self.graph[u]:
                if v not in self.visited:
                    q.append((v, dist + 1))

    def solve(self):
        self.bfs(1)
        self.visited = set()
        self.bfs(self.X)
        return self.maxx


n = int(input())
graph = Graph(n)
for i in range(n - 1):
    u, v = map(int, input().split())
    graph.addEdge(u, v)
print(graph.solve())

