class Solution:
    def validPath(self, n, edges, source, destination):
        
        if source == destination:
            return True
        
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = set()
        visited.add(source)

        def dfs(i):
            if i == destination:
                return True
            
            for nei_node in graph[i]:
                if nei_node not in visited:
                    visited.add(nei_node)
                    if dfs(nei_node):
                        return True

            return False

        return dfs(source)
