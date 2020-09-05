// 이거 다하고 문자열 정리하자

// 우선 단위별로 잘라서,줄여주기

// 시간복잡도
// N/2 * N, 1e6

#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    // N/2개까지 len 먼저
    int minv = 1000;
    for (int j=1; j<=s.length()/2; j++) {
        int rs = s.size();
        // 끝나는 인덱스
        int fin = s.length()-j-j;
        string old;
        // 0,1,2,3,4,5 >> 4 / 2 / 0
        int sw=0;
        for (int i=0; i<=fin; i++) {
            if(sw>0) {
                sw--;
                continue;
            }
            string fs = s.substr(i,j);
            string ss = s.substr(i+j,j);

            if(fs.compare(ss) ==0) {
                sw = j-1;
                if(old.compare(ss)==0) rs-=j;
                else rs = rs-(j-1);
                old = fs;
            } else old="";


        }
        minv = min(minv, rs);
    }
    return minv;

}

int main() {
    // string s = "aabbaccc";
    string s ="xababcdcdababcdcd";
    cout << solution(s) << '\n';


    return 0;
}