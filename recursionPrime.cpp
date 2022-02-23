#include <iostream>
#include <vector>

using namespace std; 

void innerLoop(int & j, int & i, int & nMax, vector <bool> & sieve) {

    if(j < nMax) {
        sieve[j] = 0;
        j += i;
        innerLoop(j, i, nMax, sieve);
    }

}

void outerLoop(int & i, int & nMax, vector <bool> & sieve) {
    if(i*i < nMax) {
        i++;
        int j = i * i;
        innerLoop(j, i, nMax, sieve);
        outerLoop(i, nMax, sieve);
    }
}

void recursivePrime(int & nMax, vector <bool> & sieve) {
    int i = 1;
    outerLoop(i, nMax, sieve);
}

int main() {
    int nmaxMain = 100;
    vector <bool> sieve(nmaxMain, 1);
    recursivePrime(nmaxMain, sieve);
    for(int i = 0; i < sieve.size(); i++) {
        if(sieve[i] == true) {
            cout << i << endl;
        }
    }
}
