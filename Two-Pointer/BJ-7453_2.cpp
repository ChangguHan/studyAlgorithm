/**
 BOJ 7453
 - 그냥 더하면 O(N^4) 시간초과
 
 - 두개씩 더해서 백트래킹
    - O(N^2 + N^2)
 
 - 궃체적 방법
    - 두개씩 더해줌
    - 정렬 N^2lgN^2
    - st, en 각 포인트 더하기
        - 만약 같은거 나오면, 중복해서 나올 수 있으니까
        - 각각 중복되는거 갯수 구해서 더해줌
 
 - INT 초과 안함
    - 정수값 최대 2^28 이므로, 2^30
    - 근데 카운트가 ll 가능
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
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    int idx=0;
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            AB[idx] = A[j] + B[i];
            CD[idx] = C[j] + D[i];
            idx++;
        }
    }
    
    sort(AB, AB+idx);
    sort(CD, CD+idx);
    
    int st=0,en = idx-1;
    ll rs=0;
    
    while(en >=0 && st <idx) {
        if(AB[st] + CD[en] ==0) {
            int origin = st;
            ll absame =0;
            ll cdsame = 0;
            while(AB[st] + CD[en] == 0) {
                absame++;
                st++;
                if(st==idx) break;
            }
            
            while(AB[origin] + CD[en] == 0) {
                cdsame++;
                en--;
                if(en<0) break;
            }
            rs += absame * cdsame;
            
        } else if(AB[st] + CD[en] < 0) {
            st++;
        } else if(AB[st] + CD[en] >0) {
            en--;
        }
         
    }
    
    cout << rs << '\n';
    return 0;
}
