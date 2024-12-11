#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int prime[N], f[N];
void sang(){
	for(int i = 0; i <= N; i++){
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= sqrt(N); i++){
		if(prime[i]){
			for(int j = i * i; j <= N; j += i){
				prime[j] = 0;
			}
		}
	}
}
int main() {
  sang();
  for(int i = 1; i <= N; i++){
    if(prime[i]){
      f[i] = 1 + f[i-1];
    } else{
      f[i] = f[i-1];
    }
  }
  cout << f[3]; // so luon so nguyen to tu 1 den 3
  return 0;
}