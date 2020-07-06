#include <cassert>
#include "int_list_t.h"

int main() {
    int_list_t list(3, 6);
    assert(list.size() == 3);
    assert(!list.empty());
    std::cout << "list(3, 6)\n";
    std::cout << "list = " << list << '\n';

    std::cout << "list = ";
    std::cout.flush();
    std::cin >> list;
    std::cout << "list = " << list << '\n';

    const int_list_t a(list);
    std::cout << "a(list)\n";
    std::cout << "a = " << a << '\n';
    std::cout << "list = " << list << '\n';

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    int_list_t b;
    assert(b.empty());
    std::cout << "b\n";

    b.swap(list);
    assert(list.empty());
    std::cout << "b.swap(list)\n";
    std::cout << "b = " << b << '\n';
    std::cout << "list = " << list << '\n';

    list.merge(b);
    assert(b.empty());
    std::cout << "list.merge(b)\n";
    std::cout << "list = " << list << '\n';
    std::cout << "b = " << b << '\n';

    list.reverse();
    std::cout << "list.reverse()\n";
    std::cout << "list = " << list << '\n';

    b = list;
    std::cout << "b = list\n";
    std::cout << "b = " << b << '\n';
    std::cout << "list = " << list << '\n';

    int_list_t c(5, 9);
    std::cout << "c(5, 9)\n";

    for (size_t i = 0; i < c.size(); ++i) {
        c[i] += i;
        assert(c[i] == 9 + i);
        std::cout << "c[" << i << "] += " << i << '\n';
    }
    std::cout << "c = " << c << '\n';
    std::cout << "c.front() = " << c.front() << '\n';
    std::cout << "c.back() = " << c.back() << '\n';

    int_list_t d = c.splice(1, 3);
    assert(c.size() == 2);
    assert(d.size() == 3);
    std::cout << "d = c.splice(1, 3)\n";
    std::cout << "c = " << c << '\n';
    std::cout << "d = " << d << '\n';

    d.pop_front();
    assert(d.size() == 2);
    std::cout << "d.pop_front()\n";
    std::cout << "d = " << d << '\n';

    d.pop_back();
    assert(d.size() == 1);
    std::cout << "d.pop_back()\n";
    std::cout << "d = " << d << '\n';

    c.swap(d);
    assert(c.size() == 1);
    assert(d.size() == 2);
    std::cout << "c.swap(d)\n";
    std::cout << "c = " << c << '\n';
    std::cout << "d = " << d << '\n';

    c.push_front(1);
    assert(c.size() == 2);
    assert(c.front() == 1);
    assert(c[0] == c.front());
    std::cout << "c.push_front(1)\n";
    std::cout << "c = " << c << '\n';

    c.push_back(5);
    assert(c.size() == 3);
    assert(c.back() == 5);
    assert(c[2] == c.back());
    std::cout << "c.push_back(5)\n";
    std::cout << "c = " << c << '\n';

    ++d.front();
    --d.back();
    std::cout << "++d.front()\n";
    std::cout << "--d.back()\n";
    std::cout << "d = " << d << '\n';

    return 0;
}

