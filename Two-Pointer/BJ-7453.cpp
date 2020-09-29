/*
 BOJ 7453
 각 배열 4번 for 돌리면 4000^4로 시간초과
 
 두배열의 합을 각각 구해줘서
 양쪽에서 오는 two pointer로 해주면 되겠다
 */

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int A[4010];
int B[4010];
int C[4010];
int D[4010];
int AB[16000010];
int CD[16000010];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        cin >> D[i];
    }
    int idx=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            AB[idx] = A[i] + B[j];
            CD[idx] = C[i] + D[j];
            idx++;
        }
    }
    sort(AB, AB+idx);
    sort(CD, CD+idx);
    
    int st=0, en=idx-1;
    ll cnt=0;
    while(st<idx && en>=0) {
        if(AB[st] + CD[en] == 0) {
            ll same_ab=0, same_cd=0;
            int origin = st;
            while(AB[st] + CD[en]==0) {
                same_ab++;
                st++;
                if(st==idx) break;
            }
            while(AB[origin] + CD[en]==0) {
                same_cd++;
                en--;
                if(en<0) break;
            }
            cnt += same_ab * same_cd;
        }else if(AB[st] + CD[en] >0) en--;
        else st++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
