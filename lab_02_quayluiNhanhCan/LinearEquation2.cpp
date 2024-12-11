#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n, m;
int a[MAX], x[MAX];
int cnt = 0, s = 0;
void input(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
}
void Try(int k){
  for(int v = 1; v <= ((m - s)/a[k]); v++){
    x[k] = v;
    if(k == n){
      if(s + a[k]*x[k] == m) cnt++;
    } else{
      if(m - s > 0){
        s += a[k] * x[k];
        Try(k+1);
      }
       

      s -= a[k] * x[k];
    }
  }
}
int main() {
  input();
  Try(1);
  cout << cnt;
  return 0;
}