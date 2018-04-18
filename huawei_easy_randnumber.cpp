/*
 ÅÅĞòºÍÖØ×é
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int N;
    while(cin >> N){
        int res[N];
        int tmp;
        for (int i = 0; i < N; i++){
           cin >> tmp;
           res[i] = tmp;
        }

        sort(res, res+N);
        cout<< res[0]<<endl;
        for(int i = 1; i < N; i++){
           if (res[i]!= res[i-1]){
              cout << res[i] << endl;
           }
        }
    }
    return 0;
}

/* set ÈİÆ÷
#include<iostream>
#include<set>
using namespace std;
int main(){
    int N;
    while(cin >> N){
        int res[1000];
        for (int i =0; i < N; i++) cin >> res[i];
        set<int> num(res, res+N);
        for (set<int>::iterator it = num.begin(); it!= num.end(); it++){
            cout << *it <<endl;
        }
    }
    return 0;
}
*/

/*input
11
10
20
40
32
67
40
20
89
300
400
15
*/

/* output
10
15
20
32
40
67
89
300
400
*/
