#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6;
int n, m;
int c[maxN], d[maxN];
vector<int> a[maxN];
int visited[maxN];
void input(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> c[i] >> d[i];
  }
  for(int i = 1; i <= m; i++){
    int x, y; cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
}
void bfs(int u){
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while(!q.empty()){
    int x = q.front(); q.pop();
    cout << x << ' ';
    for(int y : a[x]){
      if(!visited[y]){
        q.push(y);
        visited[y] = true;
      }
    }
  }
}
int main() {
  input();
  return 0;
}