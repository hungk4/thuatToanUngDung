#include <bits/stdc++.h>
using namespace std;
int n, cap;
int c[100][100], visited[100], x[100];
int load = 0 ,f = 0, f_best = INT_MAX, cmin = INT_MAX;

int check(int v){
  if(visited[v] == 1) return 0;
  if(v > n){
    if(!visited[v-n]) return 0;
  } else{
    if(load + 1 > cap) return 0;
  }
  return 1;
}

void Try(int k){
  for(int v = 1; v <= 2*n ; v++){
    if(check(v)){
      x[k] = v;
      if(v <= n){
        load += 1;
      } else{
        load -= 1;
      };
      visited[v] = 1;
      f += c[x[k-1]][x[k]];

      if(k == 2*n){
        f_best = min(f_best, f + c[x[k]][0]);
      } else{
        if(f + (2 * n  + 1 - k) * cmin < f_best)
          Try(k+1);
      }

      if(v <= n) load -= 1; else load += 1;
      visited[v] = 0;      
      f -= c[x[k-1]][x[k]];
    }
  }
}
int main() {
  cin >> n >> cap;
  for (int i = 0; i <= 2*n ; i++) {
    for (int j = 0; j <= 2*n ; j++) {
      cin >> c[i][j] ;
      if(c[i][j] >= 1)
        cmin = min(cmin, c[i][j]);
    }
  }
  Try(1);
  cout << f_best;
  return 0;
}