class Solution {
public:
    long long const Mod = 1e9 + 7;

    long long power(long long x, long long n) {

        if (n == 0) return 1;
        if (n == 1) return x % Mod;

        long long half = power(x, n / 2);
        long long result = (half * half) % Mod;

        if (n % 2 == 0)
            return result;
        return (x * result) % Mod;
    }
    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % Mod;
    }
};