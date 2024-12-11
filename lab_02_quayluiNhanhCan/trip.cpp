#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int c[N][N];
int d[N], visited[N];
int n;
int res = INT_MAX;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> c[i][j];
    }
  }
}
void solution(){
  int f = 0;
  for(int i = 1; i < n; i++){
    f += c[d[i]][d[i+1]];
  }
  f += c[d[n]][d[0]];

  res = min(f, res);
}
void Try(int k){
  for(int u = 1; u <= n; u++){
    if(!visited[u]){
      visited[u] = 1;
      d[k] = u;

      if(k == n){
        solution();
      } else Try(k+1);

      visited[u] = 0;
    }
  }
}
int main() {
  input();
  Try(1);
  cout << res;
  return 0;
}