//main
#include <iostream>
#include <chrono>
#include <random>
#include "stack.h"
#include "queue.h"

using namespace std;
using namespace std::chrono;

void measure_time(Stack& stack, Queue& queue, int num_elements) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    // Measure insert time for stack
    auto start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        stack.insert(dis(gen));
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Stack Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure insert time for queue
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        queue.insert(dis(gen));
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Queue Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure remove time for stack
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        stack.remove();
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Stack Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;

    // Measure remove time for queue
    start = high_resolution_clock::now();
    for (int i = 0; i < num_elements; ++i) {
        queue.remove();
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    cout << "Queue Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;
}

int main() {
    Stack stack;
    Queue queue;

    // Insert elements
    for (int i = 0; i < 10; ++i) {
        stack.insert(i);
        queue.insert(i);
    }

    // Print elements
    cout << "Stack contents:" << endl;
    stack.print();
    cout << "Queue contents:" << endl;
    queue.print();

    // Remove elements
    stack.remove();
    queue.remove();

    // Print elements again
    cout << "Stack contents after one removal:" << endl;
    stack.print();
    cout << "Queue contents after one removal:" << endl;
    queue.print();

    // Performance testing
    measure_time(stack, queue, 100);
    measure_time(stack, queue, 1000);
    measure_time(stack, queue, 10000);

    return 0;
}