#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n;
void input(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
}

int maxSubArray() {
    int res = a[0];
    int total = 0;

    for (int n : a) {
      if (total < 0) {
          total = 0;
      }

      total += n;
      res = max(res, total);
    }

    return res;        
}

int main() {
  input();
  cout << maxSubArray();
  return 0;
}