// 순열로 풀수 있나?
// O(10)
// 각각 더해줘야하니까
// 최대, 50개의 연산을 해줘야함
// O(10*50)

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
typedef long long ll;

char yeon[] = {'*','+','-'};
vector<int> numvec;
bool chk[3] = {false,};
ll maxv=0;


void cal(string& expression) {
    // split을 어떻게 해줄까
    // 숫자 다 쪼개고
    // 연산자 배열로 가지고 와서, 

    // 이걸 배열로해?,
    // 아니지 순서를 맞추는게 중요하지
    // 할때마다 하나씩 땡겨와야되는데
    // 그럼 O(50) 이 추가되잖아
    // O(25000) 괜찮네

    // 우선 각 위치를 먼저 찾자
    vector<int> multi;
    vector<int> plus;
    vector<int> subs;
    int cnt=0;
    for(int i=0; i<expression.size(); i++) {
        
        if(expression[i]== '*') {
            multi.push_back(cnt);
            cnt++;
        }
        else if(expression[i]== '+') {
            plus.push_back(cnt);
            cnt++;
        }
        else if(expression[i]== '-') {
            subs.push_back(cnt);
            cnt++;
        }
        
    }

    // 잘라주자
    vector<ll> nums;
    int idx=0;
    for(int i=0; i<expression.size(); i++) {
        if(expression[i]=='*' || expression[i]=='+' || expression[i]=='-') {
            nums.push_back(stoi(expression.substr(idx,i-idx)));
            idx = i+1;
        }

        if(i==expression.size()-1) {
            nums.push_back(stoi(expression.substr(idx,i-idx+1)));
        }
    }


    // multi = 1, plus = 3, subs = 0,2

    for(int x : numvec) {
        vector<int> *yeons;
        if(x==0) yeons = &multi;
        else if(x==1) yeons = &plus;
        else if(x==2) yeons = &subs;

        // 연산자로 계산을 해보자
        for(int y : *yeons) {
            // 연산해서 그자리 넣고
            // 그 뒤에 있는 건 빼주기
            // 해당 인덱스와 뒤에 있는 인덱스를 계산해주고
            // 그 뒤에 있는 연산자들 하나씩 숫자 줄어들기
            ll eachRes=0;
            if(x==0) eachRes = nums[y] * nums[y+1];
            else if(x==1) eachRes = nums[y] + nums[y+1];
            else if(x==2) eachRes = nums[y] - nums[y+1];

            // 해당것 삭제해주기
            nums[y] = eachRes;
            nums.erase(nums.begin()+y+1);

            
            for(int i=0; i<multi.size(); i++) {

                if(multi[i] > y) multi[i]--;
                
            }
            for(int i=0; i<plus.size(); i++) {

                if(plus[i] > y) plus[i]--;
                
            }

            for(int i=0; i<subs.size(); i++) {

                if(subs[i] > y) subs[i]--;
                
            }


        }

    }

    maxv = max(maxv, abs(nums[0]));
    


}

void dfs(int dep, string& expression) {
    if(dep==3) {
        cal(expression);
        return;
    }

    for(int i=0; i<3; i++) {
        if(chk[i]) continue;
        numvec.push_back(i);
        chk[i]=1;
        dfs(dep+1, expression);
        numvec.pop_back();
        chk[i]=0;
    }    
    
}

long long solution(string& expression) {

    dfs(0, expression);
    return maxv;
}


int main() {
    string exp = "50*6-3*2"	;
    cout << solution(exp) << '\n';
    


    return 0;
}