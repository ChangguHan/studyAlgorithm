#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// 보류한걸 어떻게 처리하냐가 문제인데
// 매번 명령 전에
// find 해서 하면 되지 않을까?

// void getPop(vector<int>& bor) {
//     for(int x : bor) {
//         int fro = 
//     }
// }
vector<int> solution(vector<int> ball, vector<int> order) {
    deque<int> deq(ball.begin(), ball.end());
    vector<int> bor;
    vector<int> answer;
    for(int e : order) {
        bor.push_back(e);
        while(1) {
            int fro = deq.front();
            int bac = deq.back();
            vector<int>::iterator it1 = find(bor.begin(), bor.end(),fro);
            if(it1!=bor.end()) {
                answer.push_back(fro);
                deq.pop_front();
                bor.erase(it1);

            }
            vector<int>::iterator it2 = find(bor.begin(), bor.end(),bac);
            if(it2!=bor.end()) {
                answer.push_back(bac);
                deq.pop_back();
                bor.erase(it2);
            }

            if(it1==bor.end() && it2 == bor.end()) {
                break;
            }

        }
        
    }
    
    
    return answer;
    
}
int main() {
    // vector<int> ball;
    // ball.push_back(1);
    // ball.push_back(2);
    // ball.push_back(3);
    // ball.push_back(4);
    // ball.push_back(5);
    // ball.push_back(6);


    // vector<int> order;
    // order.push_back(6);
    // order.push_back(2);
    // order.push_back(5);
    // order.push_back(1);
    // order.push_back(4);
    // order.push_back(3);


    vector<int> ball;
    ball.push_back(11);
    ball.push_back(2);
    ball.push_back(9);
    ball.push_back(13);
    ball.push_back(24);
    // ball.push_back(6);


    vector<int> order;
    order.push_back(9);
    order.push_back(2);
    order.push_back(13);
    order.push_back(24);
    order.push_back(11);
    // order.push_back(3);

    for(int x : solution(ball,order)) cout << x << ' ';
    return 0;
}
