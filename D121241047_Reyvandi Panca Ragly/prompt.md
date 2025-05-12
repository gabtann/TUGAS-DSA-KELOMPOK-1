# AI Prompt dan Analisis

**Link Percakapan:** [https://chatgpt.com/share/681eb768-86c8-8009-bd66-1c43fdb4bbe4](https://chatgpt.com/share/6821db46-e560-8011-8e37-92eedd9c596f)

## Prompt (Sumber Soal)

## Penjelasan Soal

Kamu diberi sebuah graf tak berarah yang terdiri dari n simpul (vertices), diberi label dari 0 sampai n - 1.

📎 Detail yang diberikan:
1. Edges (Tepi):
- Sebuah daftar yang berisi pasangan edges[i] = [ui, vi], artinya ada jalur dua arah antara ui dan vi.
- Jalur ini tidak memiliki arah (bisa bolak-balik), jadi kalau bisa ke ui → vi, maka pasti bisa vi → ui.
- Tidak ada simpul yang mengarah ke dirinya sendiri (ui ≠ vi).
- Tidak ada edge ganda (dua simpul hanya dihubungkan maksimal satu kali).
2. n (jumlah simpul): Total jumlah simpul dalam graf.
3. source dan destination: Dua simpul khusus, kamu diminta mengecek apakah ada jalur apa pun dari source ke destination.

❓ Pertanyaan Soal:
Apakah ada jalur apa pun (tidak harus jalur terpendek atau tertentu) yang menghubungkan simpul source ke destination?

🧠 Tujuan:
- Jika ya, return True.
- Jika tidak ada cara untuk sampai ke destination, return False.

### Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2  
Output: true  
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2  
- 0 → 2  

### Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5  
Output: false  
Explanation: There is no path from vertex 0 to vertex 5.  

### Batasan (Constraints):
1. `1 <= n <= 2 * 10^5`
2. `0 <= edges.length <= 2 * 10^5`
3. `edges[i].length == 2`
4. `0 <= ui, vi <= n - 1`
5. `ui != vi`
6. `0 <= source, destination <= n - 1`
7. There are no duplicate edges.
8. There are no self edges.

## Analisis dan Pendekatan Solusi
