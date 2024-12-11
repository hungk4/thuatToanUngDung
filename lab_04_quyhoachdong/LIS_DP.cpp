#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], mem[N], n;
void input(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++){
    mem[i] = -1;
  }
}

int maxLis(int i){
  if(i == 1){
    return mem[1] = 1;
  }
  if(mem[i] != -1) return mem[i];

  int res = 1;
  for(int j = 1; j < i; j++){
    if(a[i] > a[j]){
      res = max(res, 1 + maxLis(j));
    }
  }
  
  mem[i] = res;
  return res;
}
void Trace(int i){
  for(int j = i-1; j >= 1 ; j--){
    if(a[i] > a[j] && mem[i] == 1 + mem[j]){
      Trace(j);
      break;
    }
  }
  cout << a[i] << ' ';
}
void TraceVongLap(int i){
  stack<int> s;
  s.push(a[i]);
  int last = i;
  for(int j = i -1 ; j >= 1; j--){
    if(a[last] > a[j] && mem[last] == 1 + mem[j]){
      last = j;
      s.push(a[j]);
    }
  }
  while(!s.empty()){
    cout << s.top() << ' ';
    s.pop();
  }
}

void solution(){
  for(int i = 1; i <= n ; i++){
    maxLis(i);
  }
  int ans = 0, pos = 0;

  for(int i = 1; i <= n; i++){
    if(ans < mem[i]){
      ans = mem[i];
      pos = i;
    }
  }
  cout << ans << endl;
  // TraceVongLap(pos);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solution();
  return 0;
}