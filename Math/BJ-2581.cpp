/**
 BOJ 2581
 
 - 소수구할때 sqrt(N)까지만 하면, NlgN으로 구할수 있음
 - 에라토스테네스의 채 사용하면, NlglgN으로 줄일수 있음
 - 에라토스테네스의 채 해보자
 */

#include <iostream>

using namespace std;

bool chk[10010];
int main() {
    int N,M; cin >> M >> N;
    int sum=0;
    int sw=true;
    int fv=-1;
    for(int i=2; i<=N; i++) {
        if(chk[i]) continue;
        
        if(i>=M) {
            sum+=i;
            if(sw) {
                sw=0;
                fv = i;
            }
        }
        chk[i]=1;
        for(int j=i+i; j<=N; j+=i) {
            chk[j]=1;
        }
    }
    
    if(fv==-1) cout <<-1 << '\n';
    else {
        cout << sum << '\n' << fv << '\n';
    }
    return 0;
}
