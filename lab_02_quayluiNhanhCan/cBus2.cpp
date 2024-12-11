#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n, cap;
int c[MAX+1][MAX], ok[MAX+1], x[MAX];
int f_best = INT_MAX;
int f, load, c_min = INT_MAX;
int x_best[MAX];


void input(){
  cin >> n >> cap;
  for (int i = 0; i <= 2*n; i++) {
    for (int j = 0; j <= 2*n ; j++) {
        cin >> c[i][j];
        if(c[i][j] != 0){
          c_min = min(c_min, c[i][j]);
        }
    }
  }
}

int check(int v){
  if(ok[v] == 1) return 0;
  if(v <= n){
    if(load + 1 > cap) return 0;
  } else{
    if(ok[v-n] == 0) return 0;
  }
  return 1;
}

void solution(){
  if(f + c[x[2*n]][0] < f_best){
    f_best = f + c[x[2*n]][0];
  }
  for(int i = 0; i <= 2*n; i++) x_best[i] = x[i]; // x_1, x2, . . ., x2n là chuỗi 2n điểm (hoán vị của 1, 2, . . ., 2n) đón – trả của hành khách trong hành trình xe bus. ​
}

void Try(int k){
  for(int v = 1; v <= 2*n; v++){
    if(check(v)){
      x[k] = v;

      ok[v] = 1;
      f += c[x[k-1]][x[k]];
      if(v <= n) load += 1;
      else load -= 1;

      if(k == 2*n) solution();
      else {
        if(f + (2*n + 1 - k) * c_min < f_best) Try(k+1);
      }

      ok[v] = 0;
      f -= c[x[k-1]][x[k]];
      if(v <= n) load -= 1;
      else load += 1;

    }
  }
}

void solve(){
  Try(1);
  cout << f_best << endl;
  // for(int i = 0; i <= 2*n; i++){
  //   cout << x_best[i] << ' ';
  // }
}
int main() {
  input();
  solve();
  return 0;
}