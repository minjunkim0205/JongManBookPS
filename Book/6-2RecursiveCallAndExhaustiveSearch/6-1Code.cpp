//
// Created by mjk on 2024-04-02.
//
#include <iostream>

using namespace std;
/*Function*/
int sum(int n){
    int ret = 0;
    for (int i = 0; i <= n; ++i) {
        ret += i;
    }
    return (ret);
}
int recursiveSum(int n){
    if (n==1){
        return (1);
    }else{
        return (n + recursiveSum(n-1));
    }
}
/*Main*/
int main(){
    int x; cin >> x;
    cout << sum(x) << '\n';
    cout << recursiveSum(x) << '\n';
    return 0;
}