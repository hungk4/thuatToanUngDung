/*
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
*/
#include <bits/stdc++.h>
using namespace std;

int checksdt(string x){
  if(x.length() > 10){
    return 0;
  }
  for(int i = 0; i < x.length(); i++){
    if(!(x[i] == '0' || x[i] == '1' || x[i] == '2' || x[i] == '3' || x[i] == '4' || x[i] == '5' || x[i] == '6' || x[i] == '7' || x[i] == '7' || x[i] == '8' || x[i] == '9')){
      return 0;
    } 
  }
  return 1;
}


int main() {
  map<string, pair<int, int>> sdt;
  string x;
  int check = 1;
  int call_cnt = 0;
  while(cin >> x && x != "#"){
    string fr_num, to_num, date, fr_time, to_time;
    cin >> fr_num >> to_num >> date >> fr_time >> to_time;
    if(checksdt(fr_num) == 0 || checksdt(to_num) == 0){
      check = 0;
    } 
    
    call_cnt += 1;
    sdt[fr_num].first +=  1;

    int fr_time_h = (fr_time[0] - '0') * 10 + (fr_time[1] - '0');
    int fr_time_m = (fr_time[3] - '0') * 10 + (fr_time[4] - '0');
    int fr_time_s = (fr_time[6] - '0') * 10 + (fr_time[7] - '0');

    int to_time_h = (to_time[0] - '0') * 10 + (to_time[1] - '0');
    int to_time_m = (to_time[3] - '0') * 10 + (to_time[4] - '0');
    int to_time_s = (to_time[6] - '0') * 10 + (to_time[7] - '0');

    sdt[fr_num].second += (to_time_h - fr_time_h) * 3600 + (to_time_m - fr_time_m) * 60 + (to_time_s - fr_time_s);
  }

  while(cin >> x && x != "#"){
    if(x == "?check_phone_number"){
      if(check == 1){
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if( x == "?number_calls_from" ){
      string y; cin >> y;
      cout << sdt[y].first << endl;
    } else if( x == "?number_total_calls"){
      cout << call_cnt << endl;
    } else if (x  == "?count_time_calls_from"){
      string y; cin >> y;
      cout << sdt[y].second << endl;
    }
  }
  return 0;
}