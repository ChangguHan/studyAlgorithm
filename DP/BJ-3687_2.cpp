/**
 BOJ 3687
 
 최대로 큰수를 구하는건 쉬워
 - 자리수가 제일 커야되며
    - 자리수가 크려면 성냥개비를 조금 써야함
    - 그래서 1(2개), 7(3개) 로만 사용하면 될듯
 - 이왕이면 더 큰 숫자가 나와야돼
    - 그래서 7을 먼저 하고, 그다음에 1을 추가
 
 최소가 문제인데
 - 자리수가 제일 작아야되고
    - 큰수를 앞에 두면서 하는건 의미가 없고
    - 성냥개비 몇개에 몇자리수가 가능한지를 확인해야함
        - 이때, 모든 성냥개비를 다해봐야하고,
        - 이걸 DP로 돌리면 되겠다, 어짜피 계속 쓰는거니까
 - 이왕이면 낮은 숫자가 앞으로 나와야함
    - 이건 낮은숫자부터 돌리면 됨,
    - 0을 먼저하면 좋지만 0은 첫자리면 안되니까, 먼저 체크한다음 낮은숫자순으로 ㄱ
 
 시간복잡도 구하자
 - 최대는 O(N/2)
 
 - 최소는 몇자리수인지 확인하는것 : 100자리까지, 100개씩 한다고 하면 O(N^2)
 - 낮은수부터 확인하는것도 역시 O(N^2)
 
 O(N^2*T) : 1e6
 */

#include <iostream>

using namespace std;

int need[10] = {6,2,5,5,4,5,6,3,7,6};
int dp[110][110];
string maxS, minS;

bool poss(int len, int cnt) {
    if(len==0) {
        if( cnt==0) return 1;
        else return 0;
    }
    
    if(cnt<=0) return 0;
    
    if(dp[len][cnt] != -1) return dp[len][cnt];
    
    dp[len][cnt] = 0;
    // 여기서 만약 0이10이거나 해서 유니크했다면
    // 처음과 끝을 다시 만들어야할듯
    for(int i=0; i<10; i++) {
        if(poss(len-1, cnt-need[i])) {
            dp[len][cnt] = 1;
            break;
        }
    }
    return dp[len][cnt];
}

void make(int len, int cnt, bool first) {
    if(len==0) return;
    
    if(!first && poss(len-1, cnt-need[0])) {
        minS += "0";
        make(len-1, cnt-need[0],0);
    } else {
        // 작은수부터
        for(int i=1; i<10; i++) {
            if(poss(len-1, cnt-need[i])) {
                minS += i+'0';
                make(len-1, cnt-need[i],0);
                break;
            }
        }
        
    }
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&dp[0][0], &dp[109][110],-1);
    int T; cin >> T;
    // 테스트케이스간에도 dp공유할수있음
    while(T--) {
        int N; cin >> N;
        maxS=""; minS="";
        int maxN = N;
        while(maxN !=0) {
            if(maxN%2 != 0) {
                maxS += "7";
                maxN-=3;
            } else {
                maxS += "1";
                maxN -= 2;
                
            }
        }
        
        // 최소거리먼저 구하자
        int minLen = 100;
        for(int i=1; i<=100; i++) {
            if(poss(i,N)) {
                minLen = i;
                break;
            }
        }
        // 함수 따로만들어주는 이유는, 재귀 써야하기 때문
        make(minLen, N,1);
        
        
        
        
        cout << minS << ' '<<maxS << '\n';
        
    }
    return 0;
}
