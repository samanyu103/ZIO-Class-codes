#include <bits/stdc++.h>
using namespace std;

const int MOD = 1337;

// Fast exponentiation: (a^n) % mod
int power(int a, int n, int mod) {
    int result = 1;
    a %= mod;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % mod;
        }
        n /= 2;
        a = (a * a) % mod;
    }
    return result;
}

// b is represented as a vector of digits
int superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;

    int last_digit = b.back();
    b.pop_back();

    // a^b = (a^remaining)^10 * a^last_digit
    int part1 = power(superPow(a, b), 10, MOD);
    int part2 = power(a, last_digit, MOD);

    return (part1 * part2) % MOD;
}

int main() {
    int a = 2;
    vector<int> b = {1, 0}; // represents 10

    cout << superPow(a, b) << endl;
    return 0;
}