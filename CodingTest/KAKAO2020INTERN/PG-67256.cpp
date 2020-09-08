// 시뮬레이션, 시간복잡도 생각할 필요있나
// 왼손, 오른손 위치 정보가지고있고
// 그래도 해보자
// N번, 올때마다
// 처음에 1,4,7인지 3,6,9인지 비교해본다음
// 안걸러지면 왼손 오른손 위치 비교해보면 될듯
//O(1)
// o(N)dd
#include <iostream>


#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lhy = 3;
    int lhx = 0;
    int rhy = 3;
    int rhx = 2;
    // 손을 몇번째 줄인지
    for(int x : numbers) {
        if(x == 1 || x==4 || x==7) {
            answer += "L";
            lhy = x/3;
            lhx = 0;
        } else if(x == 3 || x==6 || x==9) {
            answer += "R";
            rhy = x/3-1;
            rhx = 2;
        } else{
            // 중간값일떄 왼쪽 오른쪽도 신경 써줘야되는구나
            //반례 : 왼손 2, 오른손 9, 눌러야하는곳 5
            // 오른손잡이
            if(x==0) x = 11;
            int newy = x/3;
            int newx = 1;

            if(abs(newy - lhy) + abs(newx-lhx) > abs(newy - rhy) + abs(newx-rhx)) {
                // 오른손과의 차이가 더 적으면
                answer += "R";
                rhy = newy;
                rhx = newx;
            } else if(abs(newy - lhy) + abs(newx-lhx) < abs(newy - rhy) + abs(newx-rhx)) {
                answer += "L";
                lhy = newy;
                lhx = newx;
            } else {
                // 같은경우
                if(hand=="left") {
                    answer += "L";
                    lhy = newy;
                    lhx = newx;
                } else if(hand=="right") {
                    answer += "R";
                    rhy = newy;
                    rhx = newx;
                }
            }

        }
    }
    return answer;
}


int main() {
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(5);


    string hand = "right";

    cout << solution(numbers, hand);

    return 0;
}