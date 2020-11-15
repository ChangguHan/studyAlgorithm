/**
 BOJ 3687
 - 큰수는 그리디하게 풀면됨
    - 자리수가 많아야하고
    - 같은 자리수라면 앞의 숫자가 더 커야함
    - 자리수를 많게 하기위해 성냥 작은걸 써서 최대한 늘리는수밖에없음
    - 1 : 2개, 7 : 3개로, 홀수일때 7 더하고 짝수일때 2 더해서 최대한 늘려줌
    - 성냥개비 1개인 케이스 없으니 문제 없음
 
 - 작은수가 문제
    - 조건
        - 자리수가 적어야하고
        - 같은 자리수면 앞자리가 작아야함
        - 맨 처음숫자는 0이면 안됨
    - 큰숫자로 처음에 하면 안되는것이, 다음 성냥개비 개수로 불가능할수가 있음
    - 그래서 dp로 성냥개비 몇개 남았을때 만들수 있는지 구해줘야함
        - dp 시간복잡도
            - 특정 성냥개비 개수에 (N) 가능한지 확인해줘야함
            - 모든 숫자 넣어봐서 확인하는 걸로, O(N*10), e3 가능

 - INT 초과 >> 성냥 초대 100개 이므로, e50, 위험할 수 있음
    - string 처리해주기
 
 - 구체적 방법
    - 큰수 : 그리디 가능
    - 작은수
        - dp 통해서 가장 작은 자리수 화인
        - 작은수부터 앞에 대입해 다음 숫자만들수 있는지확인
        - 맨 앞자리라면 0은 불가
 */

#include <iostream>
#include <string>

using namespace std;


string maxS, minS;
int dp[110][50];
int needs[10] = {6,2,5,5,4,5,6,3,7,6};

int get_dp(int num, int len) {
    
    if(num <0) return 0;
    
    if(len==0) {
        if(num ==0) return 1;
        else return 0;
    }
    
    if(dp[num][len] != -1) return dp[num][len];
    
    
    for(int i=0; i<10; i++) {
        int ec = needs[i];
        if(get_dp(num-ec, len-1)) return dp[num][len] = 1;
    }
    return dp[num][len] = 0;
}


void get_minString(int num, int len, bool first) {
    if(num==0) return;
    
    int st = 0;
    if(first) st=1;
    for(int i=st; i<10; i++) {
        int ec = needs[i];
        if(get_dp(num-ec, len-1)) {
            minS += '0' + i;
            return get_minString(num-ec, len-1, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    fill(&dp[0][0], &dp[109][50], -1);
    
    while(N--) {
        // 초기화
        maxS = "";
        minS = "";
        
        int num; cin >> num;
        int mnum = num;
        // 큰수부터
        while(num != 0) {
            if(num%2 !=0 ) {
                maxS += '7';
                num -= 3;
            } else {
                maxS += '1';
                num -= 2;
            }
        }
        
        // 작은수 구하기
        // 가장 작은 수부터구하기
        // 이떄 0을 따로 계산해줘야하나?, 0은 6개이므로 다른 숫자랑 중복해서 상관없음
        int minLen = 0;
        for(int len = 1; len<=50; len++) {
            if(get_dp(mnum, len)) {
                minLen = len;
                break;
            }
        }
       
        // 숫자구하기
        get_minString(mnum, minLen, 1);
               
        
        cout << minS << ' ' << maxS << '\n';
               
        
    }
    
    return 0;
}
