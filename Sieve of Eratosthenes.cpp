#include <bits/stdc++.h>
using namespace std;

class Sieve{
    public:
        vector<bool> prime;
        int n;
    
        Sieve(int _n){
            n = _n;
            prime.resize(n+1, true);
            for (int num = 2; num*num <= n; num++) {
                if (prime[num] == true) {
                    for (int i = num*num; i <= n; i += num)
                        prime[i] = false;
                }
            }
        }
    
        bool isPrime(int num){
            return prime[num];
        }
};

int main(){
    // TC - O(n*log(log(n)))
    // SC - O(n)
    Sieve s(45);
    cout << s.isPrime(43) << endl;
    
    return 0;
}
