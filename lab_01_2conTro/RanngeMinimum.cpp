#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 5, lg = 20; // 2^lg < maxn
int a[maxN], n;
int m[maxN][lg];// m[i][j] is minimum among a[i..i+2^j-1]

void processing(){
  for(int i = 0; i < n; i++){
    m[i][0] = a[i];
  }
  int LOG = log2(n);
  for(int k = 1; k <= LOG; k++){
    for(int i = 0; i + (1 << k) - 1 < n; i++){
      m[i][k] = min( m[i][k-1], m[i + (1 << (k-1))][k-1]);
    }
  }
}
int queryMin(int l , int r) {
  int len = r - l + 1;
  int k = 0;
  while( (1 << (k + 1)) <= len ){
    k++;
  };
  return min( m[l][k] , m[r - (1 << k) + 1][k]);
}
int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  processing();
  long long sum = 0;
  int m; cin >> m;
  while(m--){
    int l, r; cin >> l >> r;
    sum += queryMin(l, r);
  }
  cout << sum;

  return 0;
}