#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 각각 떨어지는거 계산해줌녀 도리듯
int solution(vector<string> drum) {
    int rs = 0;
    char map[1010][1010];
    for(int j=0; j<drum.size(); j++) {
        for (int i=0; i<drum[0].size(); i++) {
            map[j][i] = drum[j][i];
        }
    }
    for (int i=0; i<drum[0].size(); i++) {
        int ey = 0;
        int ex = i;
        bool sw = false;
        int cnt=0;
        while(1) {
            if(map[ey][ex] == '#') ey++;
            else if(map[ey][ex] == '>')ex++;
            else if(map[ey][ex] == '<')ex--;
            else if(map[ey][ex] == '*') {
                if(cnt==0) {
                    cnt++;
                    ey++;
                }
                else break;
            }
            if(ey == drum.size()-1) {
                sw = true;
                break;
            }

        }
        if(sw) rs++;

    }

    return rs;

}

int main() {
    vector<string> ip;
    ip.push_back("######");
    ip.push_back(">#*###");
    ip.push_back("####*#");
    ip.push_back("#<#>>#");
    ip.push_back(">#*#*<");
    ip.push_back("######");

    cout << solution(ip) <<'\n';

    return 0;
}