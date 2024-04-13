//
// Created by mjk on 2024-04-01.
//
#include <iostream>
#include <vector>

using namespace std;
/*Function*/
int countPairings(vector<vector<bool>> &are_friends, const int &n, bool taken[10]) {
    int first_free = -1;
    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            first_free = i;
            break;
        }
    }
    if(first_free == -1) {
        return 1;
    }
    int ret = 0;
    for(int pair_with = first_free + 1; pair_with < n; pair_with++) {
        if(!taken[pair_with] && are_friends[first_free][pair_with]) {
            taken[first_free] = taken[pair_with] = true;
            ret += countPairings(are_friends, n, taken);
            taken[first_free] = taken[pair_with] = false;
        }
    }
    return ret;
}
/*Main*/
int main(){
    int c; cin >> c;
    while(c--) {
        vector<vector<bool>> are_friends(10, vector<bool>(10, false));
        int n, m; cin >> n >> m;
        for(int i = 0; i<m; i++) {
            int a, b; cin >> a >> b;
            are_friends[a][b] = true;
            are_friends[b][a] = true;
        }
        bool arr[10] = {false, };
        cout << countPairings(are_friends, n, arr) << '\n';
    }
    return 0;
}