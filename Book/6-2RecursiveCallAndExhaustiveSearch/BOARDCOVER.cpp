//
// Created by mjk on 2024-04-02.
//
#include <iostream>
#include <vector>

using namespace std;
/*Const*/
const int cover_type[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};
/*Function*/
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = true;
    for(int i = 0; i < 3; i++) {
        const int n_y = y + cover_type[type][i][0];
        const int n_x = x + cover_type[type][i][1];
        if (n_x < 0 || n_x >= board[0].size() || n_y < 0 || n_y >= board.size()) {
            ok = false;
        }else if((board[n_y][n_x] += delta) > 1){
            ok = false;
        }
    }
    return ok;
}
int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) {
            break;
        }
    }
    if(y == -1) {
        return 1;
    }
    int ret = 0;
    for(int type = 0; type < 4; type++) {
        if(set(board, y, x, type, 1)) {
            ret += cover(board);
        }
        set(board, y, x, type, -1);
    }
    return ret;
}
/*Main*/
int main() {
    int t; cin >> t;
    while(t--) {
        int h, w; cin >> h >> w;
        vector<vector<int>> board(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++) {
            string str; cin >> str;
            for(int j = 0; j < w; j++) {
                if(str[j] == '#') {
                    board[i][j] = 1;
                }
            }
        }
        cout << cover(board) << '\n';
    }
    return 0;
}