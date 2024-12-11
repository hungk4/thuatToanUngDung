#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[1005];
int deg[1005];


void nhap(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    a[x].push_back(y);
    deg[y]++;
  }
}

void topoBfs(){
  queue<int> q;
  for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);

  vector<int> topo;
  while(!q.empty()){
    int u = q.front(); q.pop();
    topo.push_back(u);
    for(int v : a[u]){
      deg[v]--;
      if(deg[v] == 0) q.push(v);
    }
  }
  if(topo.size() < n) cout << "ton tai chu trinh";
  else {
    for(int x : topo){
      cout << x << ' ';
    }
  }
}
int main() {
  
  return 0;
}