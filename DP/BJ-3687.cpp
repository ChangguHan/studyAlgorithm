/**
 BJ 3687
 
 최대값은 greedy로 해결 가능
 최소값은 다음 조건
    - 자리수가 적어야하고
    - 적은 자리수 중에 작은 수가 앞에 와야함
 - 첫자리는 1부터 순서대로
    - 다음부턴 이왕이면 0이 오는게 제일낫고, 아닐경우 어짜피 자리수 같으니까, 앞에서부터 순서대로
 
 그럼, 자리수를 어떻게 정할까
    - 모든 경우를 따져보는수밖에 없지 않을까
    - 이걸 DP로 하면 좋지 않을까
 */

#include <iostream>

using namespace std;

string maxv="";
string minv="";

int dp[110][110];
int need[10] = {6,2,5,5,4,5,6,3,7,6};
bool poss(int len, int cnt) {
    
    if(len ==0 ) {
        if(cnt==0) return 1;
        else return 0;
        
    }
    if(cnt <0) return 0;
    
    
    if(dp[len][cnt] != -1) return dp[len][cnt];
    
    
    dp[len][cnt]=0;
    
    for(int i=0; i<10; i++) {
        
        if(poss(len-1, cnt-need[i])) {
            return dp[len][cnt]=1;
        }
    }
           
   return dp[len][cnt];
}
           
void track(int len, int cnt, bool first) {
    // 첫글자일경우, 0을 세울수 없으니까,
    // 자리수가 정해져있으니까, 0할수 있음 하면 좋음
    if(len ==0) return;
    
    if(!first && poss(len-1, cnt-need[0])) {
        minv += "0";
        track(len-1, cnt-need[0], 0);
    } else {
        for(int i=1; i<10; i++) {
            if( poss(len-1, cnt-need[i])) {
                minv +=i+'0';
                return track(len-1, cnt-need[i], 0);
                
            }
        }
    }
   return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Tc; cin >> Tc;
    fill(&dp[0][0], &dp[109][110], -1);
    while(Tc--) {
        maxv=""; minv="";
        int N; cin >> N;
        
        int maxN = N;
        while(maxN !=0) {
            if(maxN%2!=0) {
                maxv += '7';
                maxN -= 3;
            } else {
                maxv += '1';
                maxN -= 2;
            }
        }
        // min 구하자
        int minlen = 50;
        for(int i=1; i<=50; i++) {
            if(poss(i,N)){
                minlen = i;
                break;
            }
        }
        
        track(minlen,N,1);
        
        cout << minv << ' ' << maxv << '\n';
    }
    
    return 0;
}
