from collections import defaultdict, deque
import sys

sys.setrecursionlimit(1000000)

class Graph:
    def __init__(self, V):
        self.V = V
        self.graph = defaultdict(list)
        self.can = True
        self.visited = set()
        self.recStack = set()
        self.ans = []

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, u):
        self.visited.add(u)
        self.recStack.add(u)
        for v in self.graph[u]:
            if v in self.recStack:
                self.can = False
            if v not in self.visited:
                self.dfs(v)
        self.recStack.remove(u)
        self.ans.append(u)

    def solve(self):
        for i in range(1, self.V + 1):
            if i not in self.visited:
                self.dfs(i)
        if self.can and len(self.ans) == self.V:
            return ' '.join(map(str, self.ans))
        return "IMPOSSIBLE"



n, m = map(int, input().split())
graph = Graph(n)
for i in range(m):
    u, v = map(int, input().split())
    graph.addEdge(v, u)
ans = graph.solve()
print(ans)
