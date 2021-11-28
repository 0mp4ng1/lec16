#include <iostream>
#include <string>
using namespace std;
int arr[256][26];

int getNextState(string pattern, int state, int x){
    if (state < pattern.length() and x == (int)pattern[state] - 97)
        return state + 1;
    int idx = 0;
    for(int i = state; i>0; i--){
        if((int)pattern[i-1] - 97 == x){
            while(idx<i-1){
                if(pattern[idx] != pattern[state-i+1+idx])
                    break;
                idx++;
            }
            if(idx == i-1)
                return i;
        }
    }
    return 0;

}


void makeTable(string pattern){

    for(int state = 0; state < pattern.length();state++){
        for(int x = 0;x < 26;x++){
            arr[state][x] = getNextState(pattern, state, x);
        }
    }

}

void search(string str, string pattern){
    int state = 0;
    bool isFind = false;
    for(int i=0;i<str.length();i++){
        state = arr[state][(int)str[i] - 97];
        if(state == pattern.length()){
            isFind = true;
            printf("Found Pattern!!!!\n");
        }
    }
    if(!isFind) printf("No Pattern\n");
}

int main(){
    string str;
    cout << "Input string" << endl;
    cin >> str;

    string pattern;
    cout << "Input pattern" << endl;
    cin >> pattern;

    makeTable(pattern);
    search(str, pattern);

}