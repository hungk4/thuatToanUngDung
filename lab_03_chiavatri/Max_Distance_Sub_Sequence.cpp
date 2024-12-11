#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n, c; 
int a[maxn];
void input(){
  cin >> n >> c;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}
int check(int d){
  int cnt = 1;
  int last = a[1];
  for(int i = 2; i <= n; i++){
    if(a[i] - last >= d) {
      cnt++;
      last = a[i];
    }
    if(cnt >= c) return 1;
  }
  return 0;
}
void solution(){
  sort(a, a + n+1);
  int dmax = a[n] - a[1];
  int dmin = 0;
  int l = dmin, r = dmax;
  int res = 0;
  while(l <= r){
    int m = (l + r) / 2;
    if(check(m)){
      res = m;
      l = m + 1;
    } else{
      r = m - 1;
    }
  }
  cout << res << endl;
}
int main() {
  int t; cin >> t;
  while(t--){
    input();
    solution();
  }
  return 0;
}