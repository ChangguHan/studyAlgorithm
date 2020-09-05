//최대이득부터 빼는 양식
// min(일일판매 *2, 재고) * 개당가격
// 이게 높은 순서대로 날짜마다 for 돌리면됨
// O(n * products) : 1e10
#include <iostream>


#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<vector<int>> products) {
    long long answer = 0;

    while(n--) {
        // 행사 정하기
        vector<long long> maxvec;
        long long maxv = 0;
        int idx = -1;
        int maxcnt = 0;
        
        for(int i=0; i<products.size(); i++) {
            // 남은기간동안 어짜피 모두 팔수 있는건 제외하자
            if(products[i][0] <= products[i][2]*(n+1)) continue;
            


            int cnt = min(products[i][0], products[i][2]*2);
            long long e = cnt*products[i][1];
            maxvec.push_back(e);
            if(maxv < e ) {
                maxv = e;
                idx = i;
                maxcnt = cnt;
            }
        }
        
        for(int i=0; i<products.size(); i++) {
            if(idx==i) {
                answer += maxv;
                products[i][0] -= maxcnt;
                continue;
            }
            int productscnt = min(products[i][0], products[i][2]);
            products[i][0] -= productscnt;
            answer += productscnt*products[i][1];
        }

    }
    return answer;
}

int main() {
    vector<vector<int> > ip;
    vector<int> ei;

    // ei.clear();
    // ei.push_back(10);
    // ei.push_back(3);
    // ei.push_back(2);
    // ip.push_back(ei);

    // ei.clear();
    // ei.push_back(15);
    // ei.push_back(2);
    // ei.push_back(5);
    // ip.push_back(ei);

    // ei.clear();
    // ei.push_back(6);
    // ei.push_back(5);
    // ei.push_back(1);
    // ip.push_back(ei);

    // ei.clear();
    // ei.push_back(11);
    // ei.push_back(3);
    // ei.push_back(2);
    // ip.push_back(ei);

    // ei.clear();
    // ei.push_back(7);
    // ei.push_back(10);
    // ei.push_back(3);
    // ip.push_back(ei);

     ei.clear();
    ei.push_back(3);
    ei.push_back(10);
    ei.push_back(2);
    ip.push_back(ei);

    ei.clear();
    ei.push_back(10);
    ei.push_back(1);
    ei.push_back(1);
    ip.push_back(ei);

    // ei.clear();
    // ei.push_back(7);
    // ei.push_back(10);
    // ei.push_back(3);
    // ip.push_back(ei);


    cout << solution(1,ip) << '\n';
    return 0;

}