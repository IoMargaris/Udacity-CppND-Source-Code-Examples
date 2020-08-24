/**
 * @author [Ioannis Margaris]

 * @create date 24 Aug. 2020 - 12:06:42

 * @desc [In the following example, we want to declare a promise which allows for transmitting a string between two threads
 * and modifying it in the process.]
 
 */

#include <iostream>
#include <thread>
#include <future>

void ModifyMessage(std::promise<std::string> && prms, std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // simulate work
    std::string ModifiedMessage = message + "...has been modified!";
    prms.set_value(ModifiedMessage);
    
}

int main()
{
    
    // Define a message
    std::string messageToThread = "My Message";

    // Create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // Start a thread passing the promise as an argument
    std::thread t(ModifyMessage, std::move(prms), messageToThread);

    // Print out the original message
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    // Get modified message via future from worker thread and print it 
    std::string messageFromThread = ftr.get();
    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    // Thread barrier
    t.join();

    return 0;
}
