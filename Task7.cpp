#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

// Shared resources
std::queue<int> buffer;         // Shared buffer (queue)
std::mutex mtx;                 // Mutex to protect shared buffer
std::condition_variable cv;     // Condition variable for synchronization

                                // Producer function
void producer() {
    for (int i = 1; i <= 5; ++i) {
        // Lock the mutex to access the shared resource (buffer)
        std::lock_guard<std::mutex> lock(mtx);

        // Produce a number and add it to the buffer
        buffer.push(i);
        std::cout << "Produced " << i << std::endl;

        // Notify the consumer that new data is available
        cv.notify_all();

        // Simulate some work with sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// Consumer function
void consumer() {
    for (int i = 1; i <= 5; ++i) {
        // Lock the mutex before accessing the shared buffer
        std::unique_lock<std::mutex> lock(mtx);

        // Wait until the buffer has data
        cv.wait(lock, [](){ return !buffer.empty(); });

        // Consume the data from the buffer
        int consumed = buffer.front();
        buffer.pop();
        std::cout << "Consumed " << consumed << std::endl;

        // Simulate some work with sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    // Create producer and consumer threads
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    // Wait for both threads to finish
    producerThread.join();
    consumerThread.join();

    return 0;
}
