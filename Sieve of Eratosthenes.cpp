#include <bits/stdc++.h>
using namespace std;

class Sieve{
    public:
        vector<bool> isPrime;
        int n;
    
        Sieve(int _n){
            n = _n;
            isPrime.resize(n+1, true);
        }
    
        void markPrimes(){
            for (int num = 2; num*num <= n; num++) {
                if (isPrime[num] == true) {
                    for (int i = num*num; i <= n; i += num)
                        isPrime[i] = false;
                }
            }
        }
};

int main(){
    // TC - O(n*log(log(n)))
    // SC - O(n)
    Sieve s(45);
    s.markPrimes();
    cout << s.isPrime[29] << endl;
    
    return 0;
}
