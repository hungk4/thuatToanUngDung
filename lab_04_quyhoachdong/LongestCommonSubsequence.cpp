#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n, m;
string x, y;
int mem[N][N];
void input(){
  cin >> x >> y;
  n = x.size();
  m = y.size();
  for(int i = n ; i >= 1; i--) {
    x[i] = x[i-1];
  }
  for(int i = m ; i >= 1; i--) {
    y[i] = y[i-1];
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      mem[i][j] = -1;
    }
  }


}
int maxLCB(int i, int j){
  if(i == 0 || j == 0) {
    return mem[i][j] = 0;
  }
  if(mem[i][j] != -1) return mem[i][j];

  int res = 0;
  res = max(res, maxLCB(i, j-1));
  res = max(res, maxLCB(i-1, j));
  if(x[i] == y[j]){
    res = max(res, 1 + maxLCB(i-1, j-1));
  }
  return mem[i][j] = res;;
}

void TraceDeQuy(int i, int j){
  if(i == 0 || j == 0) return;
  if(x[i] == y[j] && mem[i][j] == 1 + mem[i-1][j-1]){
    TraceDeQuy(i-1, j-1);
    cout << x[i] ;
    return;
  }
  if(mem[i][j] == mem[i][j-1]){
    TraceDeQuy(i, j-1);
    return;
  };
  if(mem[i][j] == mem[i-1][j]){
    TraceDeQuy(i-1, j);
    return;
  }
}
void solution(){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
       maxLCB(i, j);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      ans = max(ans, mem[i][j]);
    }
  }
  cout << ans << endl;
  TraceDeQuy(n, m);
}


int main() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solution();
  return 0;
}