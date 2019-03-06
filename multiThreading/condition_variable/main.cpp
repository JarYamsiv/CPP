#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
	std::cout<<"worker has started and is waiting for your input \n";
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});
 
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
 
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main()
{
	std::thread worker(worker_thread);
 
    std::cout<<"enter the data :";
    std::cin>>data;
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';
 
    worker.join();
	return 0;
}