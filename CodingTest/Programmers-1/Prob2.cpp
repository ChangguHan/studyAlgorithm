#include <iostream>
// 3시간, 4문제
using namespace std;
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    // for로 풀수 있는 방법이 있을까
    // 우선 몇개야, n * (n+1)/2
    
    // 우선 삼각형 내부에 삼각형이 몇개들어가지
    // 1 : 1, 2 : 1, 3 :1
    // 4 : 2, 5 : 2, 6 :2
    // 7 : 3, 
    // n+2/3
    vector<int> answer(n*(n+1)/2);
    // 1,2
    int num=0;
    int totalbase=0;
    for(int k=n; k>0; k = k- 3) {
        
        // if(k==1) {

        // }
        for(int j=1; j<=(3*k-3); j++) {
            num++;
            if(j<=k) answer[totalbase + j*(j-1)/2] = num;
            else if(j<=2*k-1) {
                int base = k*(k-1)/2;
                answer[totalbase+base+j-k] = num;
            }
            else {
                int base = k*(k+1)/2;
                int nn = j-2*k+1; // 이제 1,2,3으로 바꿈
                int a = k-nn; // 3,2,1



                answer[totalbase+a*(a+1)/2-1] = num;
            }

        }
        int b = (n-k-1)/3*2 + 2;
        totalbase += b*(b+1)/2+1;
    }
    return answer;
}

int main() {
    for(int x : solution(5)) cout << x << ' ';
    return 0;
}