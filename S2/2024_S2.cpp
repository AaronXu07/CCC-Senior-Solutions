#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int T, N;

    cin >> T >> N;

    for(int i = 0; i < T; i++){
        
        string word;
        set<char> heavy;
        int letters[26];
        memset(letters, 0, 26*sizeof(int));

        cin >> word;

        for(int j = 0; j < N; j++){
            letters[word[j] - 'a'] +=1;
            if(letters[word[j] - 'a'] == 2){
                heavy.insert(word[j]);
            }
        }

        int isprevheavy = 0;

        if(heavy.find(word[0]) != heavy.end()){
            isprevheavy = 1;
        }
        else{
            isprevheavy = 0;
        }

        int sum = 1;

        for(int j = 1; j < N; j++){
            if(isprevheavy == 1){
                if(heavy.find(word[j]) != heavy.end()){
                    break;
                }
                else{
                    isprevheavy = 0;
                    sum++;
                }
            }
            else{
                if(heavy.find(word[j]) != heavy.end()){
                    isprevheavy = 1;
                    sum++;
                }
                else{
                    break;
                }
            }
        }
        
        if(sum == N){
            cout << "T" << endl;
        }
        else{
            cout << "F" << endl;
        }
    }
    return 0;
}