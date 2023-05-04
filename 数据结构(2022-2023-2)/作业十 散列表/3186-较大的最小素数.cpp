int nextPrime(int n) {
    vector<int> primes;
    vector<bool> out(2 * n + 1);
    for (int i = 2; i <= 2 * n; ++i) {
        if (!out[i])primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; ++j) {
            out[primes[j] * i] = true;
            if (i % primes[j] == 0)break;
        }
    }
    return *lower_bound(primes.begin(), primes.end(), n);
}
