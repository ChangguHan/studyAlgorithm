// 시뮬레이션
#include <iostream>


#include <string>
#include <vector>

using namespace std;

int col[110][110];
int bo[110][110];
bool buildCol(int j, int i) {
    // 땅에 지을경우
    if(j==0) return 1;
    // 밑에 기둥있거나,
    if(col[j-1][i]==1) return 1;

    if(bo[j][i]==1) {
        // 보 있을경우(오른쪽에)
        return 1;
    }

    if(i>0) {
        // 왼쪽에 보 있을경우
        if(bo[j][i-1]==1) return 1;
    }
    
    return 0;

}
bool buildBo(int j, int i) {
    
    if(j>0) {
        // 양쪽에 하나라도 기둥있을경우
        if(col[j-1][i]==1 ||col[j-1][i+1]==1) {
            return 1;
        }else if (i>0) if(bo[j][i-1]==1 && bo[j][i+1]==1)  {
            // 양쪽에 쌍으로 보 있을경우
            // i==0 이면 안됨
            return 1;
        }
    }
    return 0;
}
// 이거 이렇게하면 조건문이 너무많아져서
// 각각 bool을 반환해줘야함
bool removeBo(int j, int i) {
    bo[j][i] = 0;

    // 양옆에 기둥있을 경우 체크
    if(col[j][i]) if(!buildCol(j,i)) {
        bo[j][i]=1;
        return 0;
    }

    if(col[j][i+1]) if(!buildCol(j,i+1)) {
        bo[j][i]=1;
        return 0;
    }
    // 양옆에 보가 있을때 체크
    if(bo[j][i+1]) if(!buildBo(j,i+1)){
        bo[j][i]=1;
        return 0;
    }

    // 양옆에 보가 있을때 체크
    if(i>0) if(bo[j][i-1]) if(!buildBo(j,i-1)){
        bo[j][i]=1;
        return 0;
    }
    return 1;
}

bool removeCol(int j, int i) {
    // 위에 기둥이 없고 다른 보와 연결되있지 않은 경우
    // 다른 보가 있는데. 그 보가 다른 보랑 연결되어있으면 상관없음
    //없애고 상황본다음에, 안되면 다시 return
    col[j][i] = 0;
    // 기둥 세울수 있으면 그대로 냅두고 안되면, return
    if(col[j+1][i]) {
        if(!buildCol(j+1,i)) {
            col[j][i] = 1;
            return 0;
        }
    }

    if(bo[j+1][i]) {
        if(!buildBo(j+1,i)) {
            col[j][i] = 1;
            return 0;
        }
    }

    if(i>0)  {
        // 양쪽 보를 검사
        if(bo[j+1][i-1]) {
            if(!buildBo(j+1,i-1)) {
                col[j][i] = 1;
                return 0;
            }
        }


    }

    return 1;

}




vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    fill(&col[0][0], &col[109][110], 0);
    fill(&bo[0][0], &bo[109][110], 0);
    for(auto x : build_frame) {
        int j = x[1];
        int i = x[0];
        // 설치
        if(x[3]==1) {
            // 기둥
            if(x[2] == 0) {
                if(buildCol(j,i)) col[j][i]=1;
            // 보
            }else if (x[2]==1) {
                if(buildBo(j,i)) bo[j][i]=1;
            }

        // 삭제
        } else if(x[3]==0) {
            // 기둥
            if(x[2] == 0) {
                // 위에 기둥이 없고 다른 보와 연결되있지 않은 경우
                // 다른 보가 있는데. 그 보가 다른 보랑 연결되어있으면 상관없음
                removeCol(j,i);
                
            // 보
            }else if (x[2]==1) {
                removeBo(j,i);
            }
        }




    }

    vector<vector<int>> answer;

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if(col[j][i]==1) {
                vector<int> ev;
                ev.push_back(i);
                ev.push_back(j);
                ev.push_back(0);
                answer.push_back(ev);
            }
            if(bo[j][i]==1) {
                vector<int> ev;
                ev.push_back(i);
                ev.push_back(j);
                ev.push_back(1);
                answer.push_back(ev);
            }

        }
    }


    
    return answer;
}

int main() {
    vector<vector<int> > build_frame;
    vector<int> row;
    
    // row.push_back(1);
    // row.push_back(0);
    // row.push_back(0);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(1);
    // row.push_back(1);
    // row.push_back(1);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(2);
    // row.push_back(1);
    // row.push_back(0);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(2);
    // row.push_back(2);
    // row.push_back(1);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();
    
    // row.push_back(5);
    // row.push_back(0);
    // row.push_back(0);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(5);
    // row.push_back(1);
    // row.push_back(0);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(4);
    // row.push_back(2);
    // row.push_back(1);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

    // row.push_back(3);
    // row.push_back(2);
    // row.push_back(1);
    // row.push_back(1);
    // build_frame.push_back(row);
    // row.clear();

// TC 2

    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(2);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(4);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(0);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();
    
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(2);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(3);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();

    row.push_back(2);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    build_frame.push_back(row);
    row.clear();

    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    row.push_back(0);
    build_frame.push_back(row);
    row.clear();

    row.push_back(2);
    row.push_back(2);
    row.push_back(0);
    row.push_back(1);
    build_frame.push_back(row);
    row.clear();


    

    vector<vector<int>> answer = solution(5,build_frame);
    for (auto y : answer) {
        for (int x : y) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}