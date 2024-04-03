//
// Created by mjk on 2024-04-02.
//
#include <iostream>
#include <vector>

using namespace std;
/*Function*/
void coutVector(vector<int> &data){
    for(auto element : data){
        cout << element << " ";
    }
    cout << '\n';
}
void pick(int n, vector<int> &picked, int to_pick){ // n개의 원소, picked 조합을 위해 있는 백터, 고를 원소의 갯수
    if (to_pick == 0){
        coutVector(picked);
        return;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        pick(n ,picked, to_pick - 1);
        picked.pop_back();
    }
}
/*Main*/
int main(){
    int x, y; cin >> x >> y;
    vector<int> picked;
    pick(x, picked, y);
    return 0;
}