//ABC 190 F - Shift and Inversions
//题目链接：https://atcoder.jp/contests/abc190/tasks/abc190_f
//重点：树状数组求逆序对，再观察k=i变化到k=i+1
//对逆序对数量会带来什么变化 

#include <iostream>
#include <vector>
#include <atcoder/fenwicktree>
using namespace std;

using ll = int64_t;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    
	for(ll& a : A) cin >> a;
    
    ll ans = 0;
    atcoder::fenwick_tree<ll> bit(N);
    
	for(ll a : A){
        ans += bit.sum(a, N);
        bit.add(a, 1);
    }
    
    for(ll a : A){
        cout << ans << '\n';
        ans += N - 1 - a * 2;
    }
} 
