#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <random>

bool isOdd(int n) {

    if (n % 2 != 0) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    srand(time(NULL));
    int r;
    std::list<int> list1;
	for (int i = 0; i < 20; ++i)
    {
		r = rand() % 100 + 1;
        list1.push_back(r);
    }
	std::cout << "basic list: ";
	for (auto it = list1.begin(); it != list1.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	std::cout << "new list:   ";
    auto it = std::remove_if(list1.begin(), list1.end(), isOdd);
    list1.erase(it, list1.end());
    for (auto it = list1.begin(); it != list1.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////
    std::array<std::string, 5> names = { "Oleksandr", "Ivan", "Anastasiia", "Petro", "Anna" };
	std::sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) { return a.length() < b.length();});
    for (auto it = names.begin(); it != names.end(); ++it)
    {
        std::cout << *it << " ";
    }
	////////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;
}
