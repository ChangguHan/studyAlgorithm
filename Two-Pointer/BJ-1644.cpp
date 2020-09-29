/**
 BOJ 1644
 - 소수먼저 구하기
 O(N * sqrt(N)), O(N^(3/2)), 4e6, 8e9
 이걸 에라토스테네스의 채 써서 NlglgN으로 끝냄
 - 수 처음부터 더하는 방식
 O(N * sqrt(N))
 
 - 연속된 수니까, twopointer로 가능
 O(2*sqrt(N))
 
 - 소수먼저 구하는게 시간초과날것같긴 한데,
- 그래도 한번 해보자
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool chk[4000010];

int main() {
    int N; cin >> N;
    vector<int> sq;
    // 에라토스테네스의 채
    for(int i=2; i<=N; i++) {
        if(chk[i]) continue;
        sq.push_back(i);
        for(int j=i+i; j<=N; j+=i) {
            chk[j]=1;
        }
    }
    
    int st=0, en=0, cnt=0, sum=0;
    
    while(1) {
        if(sum>=N) sum -= sq[st++];
        else if(en==sq.size()) break;
        else sum += sq[en++];
        
        if(sum==N) cnt++;
    }
    cout << cnt << '\n';
    
    return 0;
}
