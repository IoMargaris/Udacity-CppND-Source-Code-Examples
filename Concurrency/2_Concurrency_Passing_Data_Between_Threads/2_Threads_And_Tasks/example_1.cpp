/**
 * @author [Ioannis Margaris]

 * @create date 24 Aug. 2020 - 12:48:51

 * @desc [In the last section we have seen how data can be passed from a worker thread to the parent thread using promises and futures.
 * A disadvantage of the promise-future approach however is that it is very cumbersome (and involves a lot of boilerplate code) 
 * to pass the promise to the thread function using an rvalue reference and std::move.
 * For the straight-forward task of returning data or exceptions from a worker thread to the parent thread however,
 * there is a simpler and more convenient way using std::async() instead of std::thread(). 
 * Let us adapt the code example from the last section to use std::async:]
 
 */

#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0)
        throw std::runtime_error("Exception from thread: Division by zero!");

    return num / denom;
}


int main()
{
    // use async to start a task
    double num = 42.0, denom = 0.0;
    std::future<double> ftr = std::async(divideByNumber, num, denom);

    // retrieve result within try-catch-block
    try
    {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    }
    catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}