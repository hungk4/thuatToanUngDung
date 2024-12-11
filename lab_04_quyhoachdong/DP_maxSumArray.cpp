#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n;
int marked[maxn];
int mem[maxn];

void TraceDeQuy(int i);
void TraceVongLap();

void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
}


int maxSum(int i){
  if (i == 1) {
    mem[i] = a[i];
    return a[i];
  }
  int res = max(a[i], a[i] + maxSum(i-1));
  marked[i] = 1;
  mem[i] = res;
  return res; 
}



void solution(){
  int ans = INT_MIN;
  for(int i = 1; i <= n; i++){
    maxSum(i);
  }
  int pos = 0;
  for(int i = 1; i <= n; i++){
    if(mem[i] > ans){
      ans = mem[i];
      pos = i;
    }
    ans = max(ans, mem[i]);
  }
  cout << ans << endl;
  // TraceDeQuy(pos);
  TraceVongLap();

}
int main() {
  input();
  solution();
  return 0;
}

// ------Ham Truy Vet-------
void TraceDeQuy(int i){
  if(i != 1 && mem[i] == a[i] + mem[i-1]){
      TraceDeQuy(i-1);
  }
  cout << a[i] << ' ';
}

void TraceVongLap(){
  int ans = 0, pos = -1;
  for(int i = 1; i <= n; i++){
    if(ans < mem[i]){
      ans = mem[i];
      pos = i;
    }
  }
  int left = pos, right = pos, sum = a[left];
  while(sum != ans){
    left--;
    sum += a[left];
  }
  cout << left << ' ' << right << endl;
}