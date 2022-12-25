#include "all.hpp"
#include <iostream>

void    test_pair()
{
    ft::pair<int, int> a(1, 2);
    ft::pair<int, int> b(1, 1);
    ft::pair<int, int> c(1, 3);
    ft::pair<int, int> d(0, 1);
    ft::pair<int, int> e(0, 2);
    ft::pair<int, int> f(0, 3);
    ft::pair<int, int> g(2, 3);
    ft::pair<int, int> h(2, 2);
    ft::pair<int, int> i(2, 1);

    std::cout << "\n------TESTING LESS------\n\n";
    std::cout << "A is " << (a<b ? "less": "not less") << " than b" << std::endl;
    std::cout << "A is " << (a<c ? "less": "not less") << " than c" << std::endl;
    std::cout << "B is " << (b<c ?  "less": "not less") << " than c" << std::endl;
    std::cout << "A is " << (a<d ?  "less": "not less") << " than D" << std::endl;
    std::cout << "A is " << (a<e ?  "less": "not less") << " than E" << std::endl;
    std::cout << "A is " << (a<f ?  "less": "not less") << " than F" << std::endl;
    std::cout << "A is " << (a<g ?  "less": "not less") << " than G" << std::endl;
    std::cout << "A is " << (a<h ?  "less": "not less") << " than H" << std::endl;
    std::cout << "A is " << (a<i ?  "less": "not less") << " than I" << std::endl;

    std::cout << "\n------TESTING LESS EQUAL------\n\n";
    std::cout << "A is " << (a<=b ? "less equal": "not less equal") << " than b" << std::endl;
    std::cout << "A is " << (a<=c ? "less equal": "not less equal") << " than c" << std::endl;
    std::cout << "B is " << (b<=c ?  "less equal": "not less equal") << " than c" << std::endl;
    std::cout << "A is " << (a<=d ?  "less equal": "not less equal") << " than D" << std::endl;
    std::cout << "A is " << (a<=e ?  "less equal": "not less equal") << " than E" << std::endl;
    std::cout << "A is " << (a<=f ?  "less equal": "not less equal") << " than F" << std::endl;
    std::cout << "A is " << (a<=g ?  "less equal": "not less equal") << " than G" << std::endl;
    std::cout << "A is " << (a<=h ?  "less equal": "not less equal") << " than H" << std::endl;
    std::cout << "A is " << (a<=i ?  "less equal": "not less equal") << " than I" << std::endl;

    std::cout << "\n------TESTING GREATER------\n\n";
    std::cout << "A is " << (a>b ? "greater": "not greater") << " than b" << std::endl;
    std::cout << "A is " << (a>c ? "greater": "not greater") << " than c" << std::endl;
    std::cout << "B is " << (b>c ?  "greater": "not greater") << " than c" << std::endl;
    std::cout << "A is " << (a>d ?  "greater": "not greater") << " than D" << std::endl;
    std::cout << "A is " << (a>e ?  "greater": "not greater") << " than E" << std::endl;
    std::cout << "A is " << (a>f ?  "greater": "not greater") << " than F" << std::endl;
    std::cout << "A is " << (a>g ?  "greater": "not greater") << " than G" << std::endl;
    std::cout << "A is " << (a>h ?  "greater": "not greater") << " than H" << std::endl;
    std::cout << "A is " << (a>i ?  "greater": "not greater") << " than I" << std::endl;

    std::cout << "\n------TESTING GREATER EQUAL------\n\n";
    std::cout << "A is " << (a>=b ? "greater equal": "not greater equal") << " than b" << std::endl;
    std::cout << "A is " << (a>=c ? "greater equal": "not greater equal") << " than c" << std::endl;
    std::cout << "B is " << (b>=c ?  "greater equal": "not greater equal") << " than c" << std::endl;
    std::cout << "A is " << (a>=d ?  "greater equal": "not greater equal") << " than D" << std::endl;
    std::cout << "A is " << (a>=e ?  "greater equal": "not greater equal") << " than E" << std::endl;
    std::cout << "A is " << (a>=f ?  "greater equal": "not greater equal") << " than F" << std::endl;
    std::cout << "A is " << (a>=g ?  "greater equal": "not greater equal") << " than G" << std::endl;
    std::cout << "A is " << (a>=h ?  "greater equal": "not greater equal") << " than H" << std::endl;
    std::cout << "A is " << (a>=i ?  "greater equal": "not greater equal") << " than I" << std::endl;

    std::cout << "\n------TESTING EQUAL------\n\n";
    std::cout << "A is " << (a==a ? "equal": "not equal") << " than A" << std::endl;
    std::cout << "A is " << (a==b ? "equal": "not equal") << " than b" << std::endl;
    std::cout << "A is " << (a==c ? "equal": "not equal") << " than c" << std::endl;
    std::cout << "B is " << (b==c ?  "equal": "not equal") << " than c" << std::endl;
    std::cout << "A is " << (a==d ?  "equal": "not equal") << " than D" << std::endl;
    std::cout << "A is " << (a==e ?  "equal": "not equal") << " than E" << std::endl;
    std::cout << "A is " << (a==f ?  "equal": "not equal") << " than F" << std::endl;
    std::cout << "A is " << (a==g ?  "equal": "not equal") << " than G" << std::endl;
    std::cout << "A is " << (a==h ?  "equal": "not equal") << " than H" << std::endl;
    std::cout << "A is " << (a==i ?  "equal": "not equal") << " than I" << std::endl;

    std::cout << "\n------TESTING DIFFERENT------\n\n";
    std::cout << "A is " << (a!=a ? "different": "not different") << " than A" << std::endl;
    std::cout << "A is " << (a!=b ? "different": "not different") << " than b" << std::endl;
    std::cout << "A is " << (a!=c ? "different": "not different") << " than c" << std::endl;
    std::cout << "B is " << (b!=c ?  "different": "not different") << " than c" << std::endl;
    std::cout << "A is " << (a!=d ?  "different": "not different") << " than D" << std::endl;
    std::cout << "A is " << (a!=e ?  "different": "not different") << " than E" << std::endl;
    std::cout << "A is " << (a!=f ?  "different": "not different") << " than F" << std::endl;
    std::cout << "A is " << (a!=g ?  "different": "not different") << " than G" << std::endl;
    std::cout << "A is " << (a!=h ?  "different": "not different") << " than H" << std::endl;
    std::cout << "A is " << (a!=i ?  "different": "not different") << " than I" << std::endl;

}