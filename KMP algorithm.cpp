#include <bits/stdc++.h>
using namespace std;

void computeLPS(string& pattern, vector<int>& lps){
    int m = pattern.length(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m){
        if (pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0){
                len = lps[len-1];   
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> kmp(string& pattern, string& str){
    int n = str.length(), m = pattern.length();
    int i = 0, j = 0;
    vector<int> matchingIndices, lps(m, 0);
    computeLPS(pattern, lps);
    
    while (i < n){
        if (pattern[j] == str[i]){
            i++, j++;
        }
        
        if (j == m){
            matchingIndices.push_back(i-m);
            j = lps[j-1];
        }
        else if (pattern[j] != str[i]){
            if (j != 0){
                j = lps[j-1];   
            }
            else {
                i++;
            }
        }
    }
    return matchingIndices;
}

int main(){
    string p = "me", str = "memes";
    vector<int> ans = kmp(p, str);
    for (int i: ans){
        cout << i << " ";
    }
    
    return 0;
}
