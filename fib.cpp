#include <chrono>
using namespace std::chrono;
#include <iostream>
using namespace std;
#include <functional>

long *memo;

long fib(long i) {
    if (i < 2) return i;
    //if (memo[i]) return memo[i];
    long r = fib(i-1) + fib(i-2);
    //memo[i] = r;
    return r;
}

void bench(long i) {
    memo = new long[i]();
    auto start = high_resolution_clock ::now();
    auto r = fib(i);
    auto end = high_resolution_clock ::now();
    cout << r << " = fib(" << i << ")" << endl;
    auto duration = duration_cast<milliseconds>(end-start);
    cout << duration.count() << "ms" << endl;
}

int main() {
    bench(10);
    bench(20);
    bench(40);
    bench(42);
    bench(45);
    bench(50);
    return 0;
}
