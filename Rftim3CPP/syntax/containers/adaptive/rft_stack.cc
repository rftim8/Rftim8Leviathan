#include "rft_stack.hh"

void printRftStackMain()
{
    std::stack<int> st = {};

    for (int i = 0; i < 10; i++)
    {
        st.push(i);
    }

    std::cout << st.top() << "\n";
    std::cout << st.size() << "\n";
}