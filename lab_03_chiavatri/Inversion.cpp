#include<bits/stdc++.h>
using namespace std;
int cnt = 0, mod = 1e9+7;
// tu tuong : tron cac phan tu chi so l -> m va m + 1 -> r thanh 1 mang tang dan
void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1 , n2 = r - m;
    int x[n1], y[n2];
    // luu cac phan tu tu l -> m thanh 1 mang 
    for(int i = 0; i < n1; i++){
        x[i] = a[l+i];
    }
    // luu cac phan tu tu m + 1-> r thanh 1 mang 
    for(int i = 0; i < n2; i++){
        y[i] = a[m+1+i];
    }
    // tron 2 mang x,y gan lai vao mang a[l,r]
    int i = 0, j = 0, index = l;
    while(i < n1 && j < n2){
        if(x[i] <= y[j]){
            a[index++] = x[i++];
        }
        else{
            cnt += (n1 - 1 - i + 1);
            cnt %= mod;
            a[index++] = y[j++];
        }
    }
    while(i < n1){
        a[index++] = x[i++];
    }
    while(j < n2){
        a[index++] = y[j++];
    }
}
void mergesort(int a[], int l , int r){
    if(l < r){
        // chia mang thanh cac mang con 
        int m = (l + r) / 2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n; cin >> n;
    int a[n]; 
    for(int &x : a) cin >> x;
    mergesort(a,0,n-1);
    cout << cnt;
    return 0;
}