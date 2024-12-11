#include <bits/stdc++.h>
using namespace std;
int d[20];
const int x_max = 1e5+5;
int n, x;
int mem[20][x_max];
void input(){
  cin >> n >> x;
  for(int i = 1; i <= n; i++){
    cin >> d[i];
  }
  memset(mem, -1, sizeof(mem));

}
int minCoin(int i, int x){
  if(x < 0 || i == 0) return INT16_MAX;
  if(x == 0) {
    return mem[i][0] = 0;
  }

  if(mem[i][x] != -1) return mem[i][x];
  int res = INT16_MAX;
  res = min(res, 1 + minCoin(i, x-d[i]));
  res = min(res, minCoin(i-1, x));

  return mem[i][x] = res;

}

void Trace(int i, int x) {
  if(x <= 0 || i == 0) return;
  if(mem[i][x] == 1 + mem[i][x - d[i]]){
    cout << d[i] << ' ';
    Trace(i, x - d[i]);
  } else Trace(i-1, x);
}


int main() {
  input();
  cout << minCoin(n, x) << endl;
  Trace(n, x);
  return 0;
}