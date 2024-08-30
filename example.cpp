#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

#include "ThreadPool.h"

void operate(char letter) {
    double x = 12345.6789;
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            x = sqrt(x);
            x = x + 0.000000001;
            x = pow(x, 2);
        }
    }
}

int main()
{
    const int numThreads = 5;
    ThreadPool pool(numThreads);
    std::vector<char> letters = {'A', 'B', 'C', 'D', 'E'};

    for(int i = 0; i < letters.size(); ++i)
    {
        pool.enqueue([ letter = letters[i] ] {
            operate(letter);
        });
    }
    
    return 0;
}
