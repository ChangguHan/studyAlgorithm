// 모든 원소가 한번씩 포함하는
// 최단거리를 구하기

// for 2번 돌면 안돼
// dp로 풀어야되나
// 각각 인덱스에서 몇개있는지 확인하면
// 결국 빼줘야하는 곳에서 O(N^2)

// two pointer로 st, en 정해서
// map, set 이용해서 풀어보자
#include <iostream>


#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    
    int st=0, en=0, lrs=0, rrs=gems.size();
    set<string> gemset(gems.begin(), gems.end());
    map<string,int> map;

    while(1) {
        if(map.size() == gemset.size())  {
            // 이때 빼줘야지
            string s = gems[st++];
            map[s]--;
            if(map[s]==0) map.erase(s);
        } else if(en==gems.size())  break;
        else {
            string s = gems[en++];
            if(map.find(s) == map.end()) map.insert(make_pair(s,1));
            else map[s]++;
        }

        if(map.size() == gemset.size()) {
            // 길이 다르다면
            if(en-st < rrs-lrs) {
                rrs = en;
                lrs = st;
            }
        }


    }

    vector<int> answer;
    answer.push_back(lrs+1);
    answer.push_back(rrs);
    
    return answer;
}


int main() {
    vector<string> gems;
    gems.push_back("DIA");
    gems.push_back("RUBY");
    gems.push_back("RUBY");
    gems.push_back("DIA");
    gems.push_back("DIA");
    gems.push_back("EMERALD");
    gems.push_back("SAPPHIRE");
    gems.push_back("DIA");


    // gems.push_back("AA");
    // gems.push_back("AB");
    // gems.push_back("AC");
    // gems.push_back("AA");
    // gems.push_back("AC");


    for(int x : solution(gems)) cout << x <<' ';

    return 0;
}