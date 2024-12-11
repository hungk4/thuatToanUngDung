#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, K, Q;
int d[MAX], c[MAX][MAX];

int y[MAX]; // y[k] la diem giao dau tien cua xe thu k (y[k] thuoc {0, 1, 2, ..., N} voi k = 1, 2, .. K )
int x[MAX]; // x[i] la diem tiep theo cua diem giao i tren lo trinh( x[i] thuoc {0, 1, 2, ..., N})

bool visited[MAX]; // visted[v] = true , v da dc tham
int load[MAX]; // tong luong hang tren xe k
int f, f_best ;
int nbR ; // so xe thuc su duoc lap lo trinh
int segments; // so chang ( doan noi giua 2 diem lien tiep tren duong di)

// segment = N + nbR
int c_min = INT_MAX;
void input(){
  cin >> n >> K >> Q;
  for(int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 0; i <= n ; i++) {
    for (int j = 0; j <= n ; j++) {
      cin >> c[i][j];
      if(c[i][j] != 0 && c[i][j] < c_min){
        c_min = c[i][j];
      }
    }
  }
}

bool checkY(int v, int k){
  if(v == 0) return true;
  if(load[k] + d[v] > Q) return false;
  if(visited[v] == true) return false;
  return true;
}
bool checkX(int v, int k){
  if(v > 0 && visited[v] == true) return false;
  if(load[k] + d[v] > Q) return false;
  return true;
}
void Try_X(int s, int k){ // thu gia tri cho x[s]
  if(s == 0) {
    if(k < K) {
      Try_X(y[k+1], k+1);
    }
    return;
  }
  for(int v = 0; v <= n; v++){
    if(checkX(v, k)) {
      x[s] = v;
      visited[v] = true;
      f += c[s][v];
      load[k] = load[k] + d[v];
      segments = segments + 1;

      if(v > 0){
        // n + nbR - segments: so doan duong con lai
        if(f + (n + nbR - segments)*c_min < f_best )
          Try_X(v, k);
      } else {
        if(k == K) {
          if(segments == n + nbR) f_best = min(f_best, f);
        } else {
          if(f + (n + nbR - segments)*c_min < f_best) Try_X(y[k+1], k+1);
        }
      }

      visited[v] = false;
      f -= c[s][v];
      load[k] = load[k] - d[v];
      segments = segments - 1;
    }
  }
}
void Try_Y(int k){ // thu gia tri cho y[k]
  int s = 0;
  if(y[k-1] > 0) s = y[k-1] + 1;
  for(int v = s; v <= n; v++){
    if(checkY(v, k)){
      y[k] = v;

      if(v > 0) segments = segments + 1;
      visited[v] = true; 
      f += c[0][v]; 
      load[k] += d[v];

      if(k < K) Try_Y(k+1);
      else {
        nbR = segments;
        Try_X(y[1], 1);
      }

      load[k] -= d[v];
      visited[v] = false;
      f -= c[0][v];
      if(v > 0) segments = segments - 1;
      
    }
  }
}
void solve(){
  f = 0; f_best = INT_MAX;
  y[0] = 0;
  for(int v = 1; v <= n; v++){
    visited[v] = false;
  }
  Try_Y(1);
  cout << f_best;

}
int main() {
  input();
  Try_Y(1);
  solve();
  return 0;
}