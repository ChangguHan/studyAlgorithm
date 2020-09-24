#include <iostream>

#include <string>
#include <vector>

using namespace std;
// 시뮬레이션
int getcard(int num) {
    if(num>10) num = 10;
    return num;
}
int solution(vector<int> cards) {
    int N = cards.size();
    int dealer=0;
    int player=0;
    int i=0;
    int score=0;
    int c=0;
    int vis=0;
    int Acount_player=0;
    int Acount_dealer=0;
    while(1) {
        dealer=0;
        player=0;
        Acount_player=0;
        Acount_dealer=0;


        // 플레이어 카드 뽑음
        if(i==N) return score;
        c = getcard(cards[i++]);
        if(c==1) {
            c=11;
            Acount_player++;
        }
        player += c;

        // 딜러 카드 뽑음
        if(i==N) return score;
        c = getcard(cards[i++]);
        if(c==1) {
            c=11;
            Acount_dealer++;
        }
        dealer += c;

        // 플레잉어 카드2 뽑음
        if(i==N) return score;
        c = getcard(cards[i++]);
        if(c==1 && player+11<=21) {
            c=11;
            Acount_player++;
        }
        player += c;


        // 딜러 카드2 뽑음
        if(i==N) return score;
        c = getcard(cards[i++]);
        vis = c;
        if(c==1 && dealer+11<=21) {
            c=11;
            Acount_dealer++;
        }
        dealer += c;

        if(player==21) {
            if(dealer==21) continue;
            else {
                score += 3;
                continue;
            }
        }else if(player<21) {
            if(vis==1 || vis >=7){
                while(player<17) {
                    // 플레잉어 카드2 뽑음
                    if(i==N) return score;
                    c = getcard(cards[i++]);
                    if(c==1 && player+11<=21) {
                        c=11;
                        Acount_player++;

                    }
                    player += c;

                    if(player>21) {
                        if(Acount_player>0) {
                            Acount_player--;
                            player-=10;
                        }
                    }
                }
                
            } else if(vis==2 ||vis==3) {
                while(player<12) {
                    // 플레잉어 카드2 뽑음
                    if(i==N) return score;
                    c = getcard(cards[i++]);
                    if(c==1 && player+11<=21) {
                        c=11;
                        Acount_player++;
                    }
                    player += c;
                    if(player>21) {
                        if(Acount_player>0) {
                            Acount_player--;
                            player-=10;
                        }
                    }
                }
            }
            if(player>21) {
                    score-=2;
                    continue;
                }
                // 여기 예외케이스 없나?

        }
        

        // 딜러 카드 받기
        while(dealer<17) {
            
            if(i==N) return score;
            c = getcard(cards[i++]);
            if(c==1 && dealer+11<=21) {
                c=11;
                Acount_dealer++;
            }
            dealer += c;
            if(dealer>21) {
                if(Acount_dealer>0) {
                    Acount_dealer--;
                    dealer-=10;
                }
            }
        }
        if(dealer>21) {
            score +=2;
            continue;

        }

        if(player>dealer) score+=2;
        else if(player==dealer) continue;
        else score-=2;


    }

    
    return score;
}
int main() {

    vector<int> cards;
    cards.push_back(12);
    cards.push_back(7);
    cards.push_back(11);
    cards.push_back(6);
    cards.push_back(2);
    cards.push_back(12);


    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // cards.push_back(1);
    // [10, 13, 10, 1, 2, 3, 4, 5, 6, 2]



    cout << solution(cards) << '\n';
    return 0;
}
