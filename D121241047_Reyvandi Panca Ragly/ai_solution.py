class Solution:
    def validPath(self, n, edges, source, destination):
        # Jika source dan destination sama, jalur sepele ada
        if source == destination:
            return True
        
        # Buat daftar adjasi
        adj_list = [[] for _ in range(n)]
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        
        # Set untuk melacak simpul yang sudah dikunjungi
        visited = set()
        
        def dfs(node):
            # Jika mencapai destination, jalur ditemukan
            if node == destination:
                return True
            
            # Tandai node sebagai dikunjungi
            visited.add(node)
            
            # Kunjungi semua tetangga yang belum dikunjungi
            for neighbor in adj_list[node]:
                if neighbor not in visited:
                    if dfs(neighbor):
                        return True
            
            return False
        
        # Mulai DFS dari source
        return dfs(source)
