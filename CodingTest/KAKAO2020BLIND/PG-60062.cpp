// 숫자들간의 최소거리로 포함할수 있는 거리 구하는 문제

// 가장 차이 weak 끼리, 큰 dist 할수도 없는거고

// 어떤 범위 내에 가장 많은걸 찾아야하는데 이것도 어려워
// 숫자가 작긴한데 백트래킹으로?
// n의 0부터 11까지, 각각 dist를 세우는 방법
// O(8 * 8-1 * ...)
// dist의 위치를 우선 이렇게 정해
// 그래서 안되면 넘기고
// 그래서 최소값을 구하면 되지
// O(1e8 이하)


#include <iostream>


#include <string>
#include <vector>

using namespace std;

vector<int> per;
vector<int> distg;
vector<int> weakg;
int ng;

int answer;
bool map[201];

// 순열, 순서가 중요해
void dfs(int size) {
    if(per.size() == size) {
        vector<int> distper;
        for(int x : per) distper.push_back(distg[x]);

        bool sw = false;
        for(int i=0; i<n; i++) {
            int idx=0;
            // weak이 있는부분만
            if(map[i]) {
                i += distper[idx];
                idx++;
            }

            // 모두 썻는데도, 안되면 끄기
            if(idx == dist.size()) {
                for(int j= i+1; i<n; j++) {

                    if(map[j]==1) {
                        sw = true;
                        break;
                    }
                }
            }
        }
        if(!sw)answer = min(answer, idx);
        return;
    }

    for(int i=0; i<size; i++) {
        vector<int>::iterator x = find(i,per.begin(), per.end());
        if(x!=per.end()) continue;

        per.push_back(i);
        dfs(size);
        per.pop_back();
    }


}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer  = dist.size()+1;
    fill(map, map+201, false);
    for(int x : weak) map[x] = 1;
    distg = dist;
    dfs(-1, dist.size());
    weakg = weak;
    ng = n;

    if(answer == dist.size()+1) return -1
    
    return answer;
}


int main() {
    vector<int> weak;
    weak.push_back(1);
    weak.push_back(5);
    weak.push_back(6);
    weak.push_back(10);

    vector<int> dist;
    weak.push_back(1);
    weak.push_back(2);
    weak.push_back(3);
    weak.push_back(4);


    cout << solution(12, weak, dist) << '\n'
    return 0;
}