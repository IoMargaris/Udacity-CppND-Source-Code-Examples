/**
 * @author [Ioannis Margaris]

 * @create date 24 Aug. 2020 - 12:55:14

 * @desc [The ids between the two threads differ from each other - they are running in parallel.
 * However, one of the major differences between std::thread and std::async is that with the latter,
 * the system decides wether the associated function should be run asynchronously or synchronously.
 * By adjusting the launch parameters of std::async manually, we can directly influence wether the associated 
 * thread function will be executed synchronously or asynchronously.]
 
 */



#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom)
{
    // print system id of worker thread
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0)
        throw std::runtime_error("Exception from thread#: Division by zero!");

    return num / denom;
}


int main()
{
    // print system id of worker thread
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    // use async to start a task
    double num = 42.0, denom = 2.0;
    
    // Launch keywords: "deferred" = synchonously, "async" = asynchronously 
    std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);

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