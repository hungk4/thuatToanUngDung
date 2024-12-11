#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
vector<int> a[MAX];
int n, m;
int num[MAX], low[MAX], cnt, bridge, articulation_point, cc;
int visited[MAX];
stack<int> st;
void input(){
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y; cin >> x >> y;
    a[x].push_back(y);
  }
}

void dfs(int u, int p){
  num[u] = low[u] = ++cnt;
  st.push(u);

  for(int v : a[u]){
    if(visited[v]) continue;
    if(num[v]) low[u] = min(low[u], num[v]);
    else {
      dfs(v, u);
      low[u] =  min(low[u], low[v]);
    }
  }

  if(num[u] == low[u]){
    cc++;
    cout << cc << ": ";
    while(true){
      int v = st.top();
      cout << v << ", ";
      visited[v] = 1;
      st.pop();
      if(v == u) break;
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  input();
  for(int i = 1; i <= n; i++) 
    if(!num[i]) dfs(i, 0);
  cout << cc << endl;

  for(int i = 1; i <= n; i++){
    cout << num[i] << ' ' << low[i] << endl;
  }
  return 0;
}