#include <iostream>

#include <string>
#include <vector>

using namespace std;
// 반씩 자르고
// 한글자 예외처리
// 0이면 다음으로
vector<int> solution(int n) {
    vector<int> answer;
    if(n<10) {
        answer.push_back(0);
        answer.push_back(n);
        return answer;
    }
    int cnt=0;
    while(1) {
        if(n<10) {
            answer.push_back(cnt);
            answer.push_back(n);
            return answer;
        }
        cnt++;
        string ns = to_string(n);
        int mid = ns.size()/2;
        while(ns[mid] == '0' && mid!=ns.size()-1) {
            mid++;
        }

        string n1 = ns.substr(0,mid);
        string n2 = ns.substr(mid);
        // 여기서  비교해줘야되나
        // 자리수올라가면 안되니까 비교해줘야될듯
        if(n2.size() > n1.size() && n2[0] > n1[0]) {
            n1 = ns.substr(0,mid+1);
            n2 = ns.substr(mid+1);
        }

        n = stoi(n1) + stoi(n2);

    }
    


    return answer;
}
int main() {
    int n= 2373425;
    int b; cin >>b;
    for(int x : solution(n)) cout << x << '\n';
    return 0;
}
