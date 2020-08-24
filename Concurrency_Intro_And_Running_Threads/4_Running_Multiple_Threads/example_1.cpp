/**
 * @author [Ioannis Margaris]

 * @create date 21 Aug. 2020 - 13:46:28

 * @desc [In the following example, a number of threads is created and added to a vector using the Fork-Join Parallelism
 * The basic idea is to loop over the vector at the end of the main function and call join on all the thread objects inside the vector]
 
 */

#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread # " << std::this_thread::get_id() << std::endl;
}

int main()
{
    // create a vector of threads
    std::vector<std::thread> threads;
    
    for (size_t i = 0; i < 5; ++i)
    {
        // copying thread objects causes a compile error
        /*
        std::thread t(printHello);
        threads.push_back(t); 
        */

        // moving thread objects will work
        threads.emplace_back(std::thread(printHello));
    }

    // do something in main()
    std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    // call join on all thread objects using a range-based loop
    for (auto &t : threads)
        t.join();

    return 0;
}
