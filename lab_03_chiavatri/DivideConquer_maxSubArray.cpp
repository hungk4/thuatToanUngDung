#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}

int maxLeft(int l, int m){
  int ans = INT_MIN;
  int f = 0;
  for(int k = m; k >= l; k--){
    f += a[k];
    ans = max(f, ans);
  }
  return ans;
}

int maxRight(int m, int r){
  int ans = INT_MIN;
  int f = 0;
  for(int k = m; k <= r; k++){
    f += a[k];
    ans = max(f, ans);
  }
  return ans;
}
int maxSubArray(int l, int r){
  if(l == r) return a[l];
  int m = (l + r) / 2;
  int wL = maxSubArray(l, m);
  int wR = maxSubArray(m+1, r);

  int wLM = maxLeft(l, m);
  int wRM = maxRight(m+1, r);
  int wM = wLM + wRM;

  return max(max(wL, wR), wM);
}
int main() {
  input();
  cout << maxSubArray(1, n);
  return 0;
}