// 뒤에서부터 조건에따라 나눠줌

#include <iostream>
#include <string>

using namespace std;

int num[7];
int rs[7];

int main() {
    string ip;
    cin >> ip;
    int len = ip.length();
    for (int i=0; i<len; i++) {
        num[i] = ip[i] - '0';
    }

    for (int i=len-1; i>=0; i--) {
        if(num[i]<0) {
            num[i-1]--;
            num[i] +=10;
        }
        if(num[i] >= 7) rs[i] = 7;
        else if(num[i] >=4) rs[i] = 4;
        else if(i>0) {
            num[i-1]--;
            rs[i] = 7;
        }
    }
    string rss;
    int st=0;
    if(num[0] == 0) st++;
    for (int i=st; i<len; i++) {
        
        rss += to_string(rs[i]);
    }
    
    cout << stoi(rss) << '\n';
    

    return 0;
}

