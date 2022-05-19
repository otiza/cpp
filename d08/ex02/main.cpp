#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(78999);

    MutantStack<int>::iter it = mstack.begin();
    MutantStack<int>::iter ite = mstack.end();

    std::cout << "----"<< std::endl;
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "----" << std::endl;
    std::stack<int> s(mstack);
    return 0;
}