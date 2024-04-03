//
// Created by mjk on 2024-04-02.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*Const*/
const int dy[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dx[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
/*Function*/
bool inRange(int &y, int &x){
    return ((0 <= y && y <= 4) && (0 <= x && x <= 4)); // 0~5로 해서 err
}
bool hasWord(const vector<string> &board, const string &word, int y, int x){
    if(!inRange(y, x)){
        return (false);
    }
    if(board[y][x] != word[0]){
        return (false);
    }
    if(word.size() == 1){
        return (true);
    }
    for (int dir = 0; dir < 8; ++dir) {
        int next_y = y + dy[dir];
        int next_x = x + dx[dir];
        if (hasWord(board, word.substr(1), next_y, next_x)){
            return (true);
        }
    }
    return (false);
}
/*Main*/
int main(){
    int c; cin >> c;
    while(c--){
        vector<string> board(5);
        for(auto &e : board){
            cin >> e;
        }
        int n; cin >> n;
        vector<string> words(n);
        for(auto &e : words){
            cin >> e;
        }
        for(auto &e : words){
            cout << e << " ";
            bool flag = false;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (hasWord(board, e, i, j)){
                        flag = true;
                    }
                }
            }
            cout << (flag?"YES":"NO") << '\n';
        }
    }
    return 0;
}