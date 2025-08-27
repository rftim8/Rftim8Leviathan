#include "rft_queue.hh"

void printRftQueueMain()
{
    std::queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    std::cout << q.front() << "\n";
    std::cout << q.back() << "\n";
    std::cout << q.size() << "\n";
}
