#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000;
int n, m, cnt = 0;
long long a[maxN] , x[maxN], F[maxN];
long long f = 0;
void Try(int k){
  for(long long v = 1; v <= (m - f - (F[n] - F[k])) / a[k]; v++){
    x[k] = v;
    f = f + a[k] * x[k];
    if(k < n){
      Try(k+1);
    } else{
      if(f == m) cnt++;
    }
    f = f - a[k] * x[k];
  }
};
int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    F[i] = F[i-1] + a[i];
  }
  Try(1);
  cout << cnt;
  return 0;
}