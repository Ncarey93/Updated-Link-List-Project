//// performance_test.cpp
//#include <iostream>
//#include <chrono>
//#include <random>
//#include "stack.h"
//#include "queue.h"
//
////NOTE: This code "preformance_test.cpp" was implimented using online refrences.//
//using namespace std;
//using namespace std::chrono;
//
//void measure_time(Stack & stack, Queue& queue, int num_elements) {
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> dis(1, 10000);
//
//    // Measure insert time for stack
//    auto start = high_resolution_clock::now();
//    for (int i = 0; i < num_elements; ++i) {
//        stack.insert(dis(gen));
//    }
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<milliseconds>(end - start).count();
//    cout << "Stack Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;
//
//    // Measure insert time for queue
//    start = high_resolution_clock::now();
//    for (int i = 0; i < num_elements; ++i) {
//        queue.insert(dis(gen));
//    }
//    end = high_resolution_clock::now();
//    duration = duration_cast<milliseconds>(end - start).count();
//    cout << "Queue Insert Time for " << num_elements << " elements: " << duration << " ms" << endl;
//
//    // Measure remove time for stack
//    start = high_resolution_clock::now();
//    for (int i = 0; i < num_elements; ++i) {
//        stack.remove();
//    }
//    end = high_resolution_clock::now();
//    duration = duration_cast<milliseconds>(end - start).count();
//    cout << "Stack Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;
//
//    // Measure remove time for queue
//    start = high_resolution_clock::now();
//    for (int i = 0; i < num_elements; ++i) {
//        queue.remove();
//    }
//    end = high_resolution_clock::now();
//    duration = duration_cast<milliseconds>(end - start).count();
//    cout << "Queue Remove Time for " << num_elements << " elements: " << duration << " ms" << endl;
//}
