#include <chrono>
using namespace std::chrono;
#include <iostream>
using namespace std;
#include <functional>
#include <time.h>

long *memo;

long fib(long i) {
    if (i < 2) return i;
    if (memo[i]) return memo[i];
    long r = fib(i-1) + fib(i-2);
    memo[i] = r;
    return r;
}

void bench(long i) {
    memo = new long[i]();
    auto start = time(NULL);
    auto r = fib(i);
    auto end = time(NULL);
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
    bench(80);
    return 0;
}
