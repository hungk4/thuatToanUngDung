#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
vector<int> a[MAX];
int n, m;
int num[MAX], low[MAX], cnt, bridge, articulation_point;

void input(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y; cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
}

void dfs(int u, int p){
  num[u] = low[u] = ++cnt;
  int node = (p != 0); // p != 0 nghia la dinh u da noi voi 1 dinh ca phia tren
  for(int v : a[u]){
    if(v == p) continue; // dinh v khac dinh cha cua u
    if(num[v]) low[u] = min(low[u], num[v]);
    else {
      dfs(v, u);
      low[u] =  min(low[u], low[v]);

      if(low[v] == num[v]) bridge++; 
      // dinh v khong the tham cac dinh cha o tren
      // u - v la cau

      if(low[v] >= num[u]) node++; 
      // dinh nho nhat ma v co the tham la cha u 
      // node la luong thanh phan lien thong
    }
  }
  if(node >= 2) articulation_point++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  for(int i = 1; i <= n; i++) 
    if(!num[i]) dfs(i, 0);
  cout << articulation_point<< ' ' << bridge;
  return 0;
}