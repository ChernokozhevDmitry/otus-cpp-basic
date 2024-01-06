#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <codecvt>

#include "myvector.hpp"
#include "mylist.hpp"


int main() {
    std::cout << "create myvector\n";
    MyVector<int> myvector;
    MyVector<int> myvector1;
    std::list<double> stl_list;

    std::cout << "2. add (0, 1 ... 9)\n";
    for(int i = 0; i < 10; ++i) {
        myvector.push_back(std::move(i));
    }

    for(int i = 0; i < 10; ++i) {
        myvector1.push_back(i);
    }

    std::cout << "3. print\n";
    std::cout << "expected output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
    std::cout << "myvector:\t" << myvector << '\n';
    std::cout << "myvector:\t";
    myvector.print_elem();
    std::cout << "myvector1:\t" << myvector1 << '\n';
    std::cout << "myvector1:\t";
    myvector1.print_elem();

    std::cout << "4. get size (expected output: 10)\n";
    std::cout << "myvector.size:\t" << myvector.size() << "\t myvector.capacity:\t" << myvector.capacity() <<'\n';

    std::cout << "5. delete 3, 5, 7 index\n";
    myvector.erase(6);
    myvector.erase(4);
    myvector.erase(2);

    std::cout << "6. print\n";
    std::cout << "expected output: 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();

    std::cout << "7. add 10 to begin\n";
    myvector.insert(0, 10);

    std::cout << "8. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();

    std::cout << "9. add 20 in the middle\n";
    myvector.insert(static_cast<int>(myvector.size()/2), 20);

    std::cout << "10. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9\n";
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();

    std::cout << "11. add 30 to end\n";
    myvector.push_back(30);

    std::cout << "12. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30\n";
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();

    std::cout << "13. for loop from begin to end by iterator *\n";
    std::cout << "myvector:\t";
    for (auto it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "14. for loop from begin to end by get() class function\n";
    std::cout << "myvector:\t";
    for (auto it = myvector.begin(); it != myvector.end(); ++it) {
        std::cout << it.get() << " ";
    }
    std::cout << "\n";

    MyVector<int> copyvector = myvector;
    std::cout << "15. ";
    std::cout << "copyvector:\t" << copyvector << '\n';
    // std::cout << "copyvector:\t";
    // copyvector.print_elem();
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();
    std::cout << "16. ";
    MyVector<int> movevector(std::move(myvector));
    std::cout << "movevector:\t" << movevector << '\n';
    std::cout << "movevector:\t";
    movevector.print_elem();
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();
    std::cout << "17. movevector.pop_back() three times: \n";
    movevector.pop_back();
    std::cout << "movevector:\t" << movevector << '\n';
    // std::cout << "movevector:\t";
    // movevector.print_elem();
    movevector.pop_back();
    std::cout << "movevector:\t" << movevector << '\n';
    // std::cout << "movevector:\t";
    // movevector.print_elem();
    movevector.pop_back();
    std::cout << "movevector:\t" << movevector << '\n';
    // std::cout << "movevector:\t";
    // movevector.print_elem();
    std::cout << "18. get value by index []: \n";
    std::cout << "movevector[0]:\t" << movevector[0] << '\n';
    std::cout << "movevector[4]:\t" << movevector[4] << '\n';


    return 0;
}



// https://stackoverflow.com/questions/16747591/how-to-get-an-element-at-specified-index-from-c-list

// std::vectorимеет итераторы произвольного доступа, поэтому вы можете выполнить эквивалентную операцию в O(1) через std::nextstd::advance , если у вас есть поддержка C++11, оператор или функция-член:[]at()

// std::vector<Student> v = ...; 
// std::cout << v[4] << '\n';    // UB if v has less than 4 elements
// std::cout << v.at(4) << '\n'; // throws if v has less than 4 elements


// //  std::list не имеет итератора произвольного доступа, поэтому придется сделать шаг 4 раза от переднего итератора.
// // сделать это вручную или с помощью std::advance не сработало std::next сработало   
//     stl_list.erase(std::next(stl_list.cbegin(), 6));
//     stl_list.erase(std::next(stl_list.cbegin(), 4));
//     stl_list.erase(std::next(stl_list.cbegin(), 2));

