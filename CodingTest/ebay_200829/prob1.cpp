// 고객 개수로 배열에 하나씩 추가해줘서
// 돌면서 시간이상인거면 하나씩 추가해줌
// O(NMT), 1e4*600, 6e6
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> simulation_data) {
    int answer = 0;
    int time[6000010];
    fill(time, time+6000010,0);
    for(auto x : simulation_data) {
        while(time[x[0]]>=N) {
            answer++;
            x[0]++;
        }
        for(int i=0; i<x[1]; i++) {
            time[x[0]+i]++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int> > ip;
    // vector<int> eip;
    // eip.push_back(0);
    // eip.push_back(3);
    // ip.push_back(eip);

    // eip.clear();
    // eip.push_back(2);
    // eip.push_back(5);
    // ip.push_back(eip);

    // eip.clear();
    // eip.push_back(4);
    // eip.push_back(2);
    // ip.push_back(eip);

    // eip.clear();
    // eip.push_back(5);
    // eip.push_back(3);
    // ip.push_back(eip);

    vector<int> eip;
    eip.push_back(2);
    eip.push_back(3);
    ip.push_back(eip);

    eip.clear();
    eip.push_back(5);
    eip.push_back(4);
    ip.push_back(eip);

    eip.clear();
    eip.push_back(6);
    eip.push_back(3);
    ip.push_back(eip);

    eip.clear();
    eip.push_back(7);
    eip.push_back(4);
    ip.push_back(eip);

    cout << solution(1,ip) <<'\n' ;
    return 0;
}