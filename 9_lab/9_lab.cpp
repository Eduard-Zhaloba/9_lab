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
struct WithinRange {
    int lower=20;
    int upper=50;
    bool operator()(int n) {
        return n >= lower && n <= upper;
	}
};
struct TaxApplier {
    double rate=0.2;
    void operator()(double& price){
        price += price * rate;
    }
};
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
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////
    std::array<std::string, 5> names = { "Oleksandr", "Ivan", "Anastasiia", "Petro", "Anna" };
	std::sort(names.begin(), names.end(), [](const std::string& a, const std::string& b) { return a.length() < b.length();});
    for (auto it = names.begin(); it != names.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////
	TaxApplier tax;
	std::deque<double> prices = { 10.0, 20.0, 30.0, 40.0, 50.0 };
    std::for_each(prices.begin(), prices.end(), tax);   
    std::cout << std::endl;
	std::cout << "prices with tax: ";
    for (auto it = prices.begin(); it != prices.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////
    WithinRange withinRange;
    std::set<int> numbers = { 12, 5, 18, 25, 30, 44, 50, 72 };
    int result = std::count_if(numbers.begin(), numbers.end(), withinRange);
    std::cout << "numbers within range: " << result << std::endl;
    std::cout << std::endl;
	/////////////////////////////////////////////////////////////////////////////////////////
    std::map<std::string, int> products = {
        {"Laptop", 150},
        {"Mouse", 45},
        {"Keyboard", 110},
        {"Monitor", 8},
        {"Charger", 300}
    };
 
    std::for_each(products.begin(), products.end(), [](std::pair<const std::string, int>& product) {
        if (product.second > 100) {
            std::cout << product.first << ": " << product.second << std::endl;
        }
		});
    std::cout << std::endl;
	//////////////////////////////////////////////////////////////////////////////////////////
	std::vector<int> vec1 = { 10, 2, -31, 45, 51, -7, -102, 88, 90, -70, 23 };
    std::for_each(vec1.begin(), vec1.end(), [](int &n) {
        if(n<0) {
            n = 0;
		}
    });
    for (auto it = vec1.begin(); it != vec1.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    double sum = 0;
    for (auto it = vec1.begin(); it != vec1.end(); ++it)
    {
        sum += *it;
    }
    double average = sum / vec1.size();
    std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << average << std::endl;
    std::cout << std::endl;
	//////////////////////////////////////////////////////////////////////////////////////////
    std::string s = "A samurai has no goal, only a path";
    std::string vowels = "aeiouyAEIOUY";
	int counter = std::count_if(s.begin(), s.end(), [&vowels](char c) {
		for (int i = 0; i < vowels.size(); ++i){
            if(c == vowels[i]) {
                return true;
            }
        }
		return false;
    });
    std::cout << s<< std::endl;
	std::cout << "Number of vowels: " << counter << std::endl;
	return 0;
}
