#include <iostream>
#include <string>
#include <vector>

using namespace std;
int caltime(string& s) {
    int rs=0;
    
    rs+=stoi(s.substr(0,2))*3600;
    rs+=stoi(s.substr(3,2))*60;
    rs+=stoi(s.substr(6,2));
    return rs;
}

string timetoString(int t) {
    int tl = t%3600;
    string rs= to_string(t/3600);
    if(rs.size()==1) rs = "0" + rs;
    rs += ":";
    string es = to_string(tl/60);
    if(es.size()==1) es = "0" + es;
    rs += es;
    tl = tl%60;
    rs += ":";
    es = to_string(tl);
    if(es.size()==1) es = "0" + es;
    rs += es;
    return rs;
}
// 시간이 기니까 twopointer로 하면 되지않을까
string solution(string play_time, string adv_time, vector<string> logs) {
    int time[360010];
    fill(time, time+360010,0);
    for(string x : logs) {
        string start = x.substr(0,8);
        string end = x.substr(9);

        int sttime = caltime(start);

        int endtime =caltime(end);
        
        for(int t = sttime; t<endtime; t++) time[t]++;
    }

    int adtime =caltime(adv_time);
    int runtime =caltime(play_time);
    int st=runtime-adtime;
    int sc=0;
    for(int i=st; i<runtime; i++) {
        sc += time[i];
    }
    int maxv = sc;
    
    for(int i=runtime-adtime-1; i>=0; i--) {
        // 최대값으로 해줘야함
        
        sc += time[i]-time[i+adtime];
        if(sc >= maxv) {
            maxv = sc;
            st = i;
        }
    }

    // cout << sc  << '\n';
    
    return timetoString(st);
}

int main() {

    
    // string play_time = "99:59:59";
    // string adv_time = "25:00:00";
    // vector<string> logs;
    // logs.push_back("69:59:59-89:59:59");
    // logs.push_back("01:00:00-21:00:00");
    // logs.push_back("79:59:59-99:59:59");
    // logs.push_back("11:00:00-31:00:00");
    
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs;
    logs.push_back("01:20:15-01:45:14");
    logs.push_back("00:40:31-01:00:00");
    logs.push_back("00:25:50-00:48:29");
    logs.push_back("01:30:59-01:53:29");
    logs.push_back("01:37:44-02:02:30");

    cout << solution(play_time, adv_time, logs) << '\n';

    return 0;
}