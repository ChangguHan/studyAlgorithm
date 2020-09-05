// for 돌면서 하나씩 까주면 되겠다

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> bakery_schedule, string current_time, int K) {
    int rs=0;
    int curr_hour = stoi(current_time.substr(0,2));
    int curr_min = stoi(current_time.substr(3,2));
    for (string x : bakery_schedule) {
        int each_hour = stoi(x.substr(0,2));
        int each_min = stoi(x.substr(3,2));
        int each_bread = stoi(x.substr(6,x.size()-5));

        // 시간 이후인경우
        if(curr_hour<each_hour) {
            K -= each_bread;
            // rs += (each_hour - curr_hour) * 60;
            // rs += each_min - curr_min;

        } else if(curr_hour==each_hour && curr_min<=each_min) {
            // 시간 같은경우
            K -= each_bread;
            // rs += each_min - curr_min;

        }
        if(K<=0) {
            rs = (each_hour - curr_hour) * 60 + each_min - curr_min;
            return  rs;
        }

        
        

    }

    return -1;
}

int main() {
    vector<string> ip;
    // ip.push_back("09:05 10");
    // ip.push_back("12:20 5");
    // ip.push_back("13:25 6");
    // ip.push_back("14:24 5");
    // cout << solution(ip, "12:05", 10) << '\n';

    // ip.push_back("12:00 10");
    // cout << solution(ip, "12:00", 10) << '\n';

    ip.push_back("12:00 1000");
    cout << solution(ip, "13:00", 1) << '\n';



    return 0;
}