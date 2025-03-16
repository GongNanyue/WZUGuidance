#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    deque<int> handA, handB;
    int card;
    // 读入 A 的牌
    for (int i = 0; i < n; i++){
        cin >> card;
        handA.push_back(card);
    }
    // 读入 B 的牌
    for (int i = 0; i < n; i++){
        cin >> card;
        handB.push_back(card);
    }
    
    // 用 vector 表示桌面上的牌，index0 为最底部，back 为最顶部
    vector<int> table;
    
    // turnA = true 表示轮到 A，否则 B 出牌。
    bool turnA = true;
    
    while(true){
        // 当轮到某人出牌时先检查其是否还有牌
        if(turnA){
            if(handA.empty())
                break;
        } else {
            if(handB.empty())
                break;
        }
 
        // 当前玩家出牌：从手中第一个取出一张牌
        int curCard;
        if(turnA){
            curCard = handA.front();
            handA.pop_front();
        } else {
            curCard = handB.front();
            handB.pop_front();
        }
 
        // 将牌放到桌面上（放在最上面，即 vector 的末尾）
        table.push_back(curCard);
 
        // 检查桌面中（除新出的牌外）是否有与该牌面相同的牌
        // 从桌面顶端（新出牌的下面一张，即 table.size()-2）向下扫描
        int matchIndex = -1;
        if(table.size() > 1){
            for (int i = table.size() - 2; i >= 0; i--){
                if(table[i] == curCard){
                    matchIndex = i;
                    break;
                }
            }
        }
 
        // 如果找到匹配，则将 matchIndex 到桌面顶端的所有牌取走，
        // 并依次（从桌面最上面一张开始）加到当前玩家手牌的末尾
        if(matchIndex != -1){
            int size = table.size();
            if(turnA){
                for(int i = size - 1; i >= matchIndex; i--)
                    handA.push_back(table[i]);
            } else {
                for(int i = size - 1; i >= matchIndex; i--)
                    handB.push_back(table[i]);
            }
            table.resize(matchIndex); // 移除桌面上取走的牌
        }
 
        // 切换回合
        turnA = !turnA;
    }
 
    // 游戏结束：当轮到某人出牌却没有牌时，该玩家输，对手获胜。
    string winner;
    deque<int> winningHand;
    if(turnA){
        // 此时轮到 A，但 A 没有牌，故 B 获胜。
        winner = "B win";
        winningHand = handB;
    } else {
        winner = "A win";
        winningHand = handA;
    }
 
    // 输出结果
    cout << winner << "\n";
    // 输出获胜者手中所有牌：从第一张到最后一张，每个数后面有一个空格
    for (size_t i = 0; i < winningHand.size(); i++)
        cout << winningHand[i] << " ";
    cout << "\n";
 
    // 输出桌面上剩余的牌，从上至下：
    // 由于 vector 中 back 为最上面，则从 back 到 front输出
    for (int i = table.size() - 1; i >= 0; i--)
        cout << table[i] << " ";
    cout << "\n";
    
    return 0;
}
