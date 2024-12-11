#include <bits/stdc++.h>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
}

int main() {
  int n; cin >> n;
  vector<pair<int, int>> p ;
  while(n--){
    int ai, bi; cin >> ai >> bi;
    p.push_back({ai, bi});
  }
  sort(p.begin(), p.end(), cmp );
  int last = -1, cnt = 0;
  for(auto it = p.begin(); it != p.end(); it++){
    if(it->first > last){
      cnt++;
      last = it->second;
    }
  }
  cout << cnt;
  return 0;
}