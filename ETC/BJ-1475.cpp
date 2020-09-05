// 6이랑 9는 합해서 반으로 나눈다음 최대 큰수구하면 됨

#include <iostream>
#include <string>

using namespace std;

int num[11];
int main() {
    string st;
    cin >> st;

    for (int i=0;i<st.size(); i++) {
        num[st[i]-'0']++;
    }
    num[10] = (num[6]+num[9]);
    int maxv=0;

    for (int i=0; i<10; i++) {
        if(i==6 || i==9) continue;
        maxv = max(maxv, num[i]);

    }
    if(num[10]!=0) maxv = max(maxv, (num[10]-1)/2+1);

    cout << maxv << '\n';


    return 0;
}