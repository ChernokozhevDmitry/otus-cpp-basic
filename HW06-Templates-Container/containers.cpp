#include <iostream>
#include <vector>
#include <list>
#include <iterator>


#include "myvector.hpp"
#include "mysinglylinkedlist.hpp"
#include "mydoublylinkedlist.hpp"

int main() {
    std::cout << "-------------- vector implementation --------------\n"; 
    std::cout << "create myvector\n";
    MyVector<int> myvector;
    MyVector<int> myvector1;

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
    std::cout << "15. Copy Ctor\n";
    std::cout << "copyvector:\t" << copyvector << '\n';
    // std::cout << "copyvector:\t";
    // copyvector.print_elem();
    std::cout << "myvector:\t" << myvector << '\n';
    // std::cout << "myvector:\t";
    // myvector.print_elem();
    std::cout << "16. Move Ctor\n";
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
    std::cout << "-------------- end vector implementation \n \n"; 





    std::cout << "-------------- singly linked list implementation --------------\n"; 

    std::cout << "create mysinglylinkedlist\n";
    MySinglyLinkedList<int> mysinglylinkedlist;
    MySinglyLinkedList<int> mysinglylinkedlist_push_front;
 
    std::cout << "2. add (0, 1 ... 9)\n";
    for(int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            mysinglylinkedlist.push_back(i);
        } else {
            mysinglylinkedlist.push_back(std::move(i));
        }     
    }
    for(int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            mysinglylinkedlist_push_front.push_front(i);
        } else {
            mysinglylinkedlist_push_front.push_front(std::move(i));
        }     
    }
    std::cout << "3. print\n";
    std::cout << "expected output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
    std::cout << "mysinglylinkedlist (push_back() copy and move):\t" << mysinglylinkedlist << '\n';
    std::cout << "mysinglylinkedlist (push_front() copy and move) /reverse/:\t" << mysinglylinkedlist_push_front << '\n';

    std::cout << "4. get size (expected output: 10)\n";
    std::cout << "mysinglylinkedlist.size:\t" << mysinglylinkedlist.size() << '\n';

    std::cout << "5. delete 3, 5, 7 index\n";

    mysinglylinkedlist.erase(7);
    mysinglylinkedlist.erase(5);
    mysinglylinkedlist.erase(3);

    std::cout << "6. print\n";
    std::cout << "expected output: 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';

    std::cout << "7. add 10 to begin\n";
    mysinglylinkedlist.push_front(10);

    std::cout << "8. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';

    std::cout << "9. add 20 in the middle\n";
    mysinglylinkedlist.insert(static_cast<int>(mysinglylinkedlist.size()/2), 20);

    std::cout << "10. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9\n";
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';

    std::cout << "11. add 30 to end\n";
    mysinglylinkedlist.push_back(30);

    std::cout << "12. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30\n";
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';

    std::cout << "13. for loop from begin to end by iterator *\n";
    std::cout << "mysinglylinkedlist:\t";
    for (auto it = mysinglylinkedlist.begin(); it != mysinglylinkedlist.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
    std::cout << "14. for loop from begin to end by get() class function\n";
    std::cout << "mysinglylinkedlist:\t";
    for (auto it = mysinglylinkedlist.begin(); it != mysinglylinkedlist.end(); ++it) {
        std::cout << it.get() << " ";
    }
    std::cout << "\n";

    std::cout << "15. Copy Ctor\n";
    MySinglyLinkedList<int> copysinglylinkedlist = mysinglylinkedlist;
    std::cout << "copysinglylinkedlist:\t" << copysinglylinkedlist << '\n';
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';
    std::cout << "16. Move Ctor\n";
    MySinglyLinkedList<int> movesinglylinkedlist(std::move(mysinglylinkedlist));
    std::cout << "movesinglylinkedlist:\t" << movesinglylinkedlist << '\n';
    std::cout << "mysinglylinkedlist:\t" << mysinglylinkedlist << '\n';
    
    std::cout << "17. movesinglylinkedlist.pop_back() three times: \n";
    for (int i = 0; i < 3; ++i) {
        movesinglylinkedlist.pop_back();
        std::cout << "movesinglylinkedlist:\t" << movesinglylinkedlist << '\n';
    }
    std::cout << "18. movesinglylinkedlist.pop_front() three times: \n";
    for (int i = 0; i < 3; ++i) {
        movesinglylinkedlist.pop_front();
        std::cout << "movesinglylinkedlist:\t" << movesinglylinkedlist << '\n';
    }
    std::cout << "-------------- end singly linked list implementation \n \n";





std::cout << "-------------- doubly linked list implementation --------------\n"; 

    std::cout << "create mydoublylinkedlist\n";
    MyDoublyLinkedList<int> mydoublylinkedlist;
    MyDoublyLinkedList<int> mydoublylinkedlist_push_front;
 
    std::cout << "2. add (0, 1 ... 9)\n";
    for(int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            mydoublylinkedlist.push_back(i);
        } else {
            mydoublylinkedlist.push_back(std::move(i));
        }     
    }
    for(int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            mydoublylinkedlist_push_front.push_front(i);
        } else {
            mydoublylinkedlist_push_front.push_front(std::move(i));
        }     
    }
    std::cout << "3. print\n";
    std::cout << "expected output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n";
    std::cout << "mydoublylinkedlist (push_back() copy and move):\t" << mydoublylinkedlist << '\n';
    std::cout << "mydoublylinkedlist (push_front() copy and move) /reverse/:\t" << mydoublylinkedlist_push_front << '\n';

    std::cout << "4. get size (expected output: 10)\n";
    std::cout << "mydoublylinkedlist.size:\t" << mydoublylinkedlist.size() << '\n';

    std::cout << "5. delete 3, 5, 7 index\n";

    mydoublylinkedlist.erase(7);
    mydoublylinkedlist.erase(5);
    mydoublylinkedlist.erase(3);

    std::cout << "6. print\n";
    std::cout << "expected output: 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';

    std::cout << "7. add 10 to begin\n";
    mydoublylinkedlist.push_front(10);

    std::cout << "8. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 5, 7, 8, 9\n";
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';

    std::cout << "9. add 20 in the middle\n";
    mydoublylinkedlist.insert(static_cast<int>(mydoublylinkedlist.size()/2), 20);

    std::cout << "10. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9\n";
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';

    std::cout << "11. add 30 to end\n";
    mydoublylinkedlist.push_back(30);

    std::cout << "12. print\n";
    std::cout << "expected output: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30\n";
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';

    std::cout << "13. for loop from begin to end by iterator *\n";
    std::cout << "mydoublylinkedlist:\t";
    for (auto it = mydoublylinkedlist.begin(); it != mydoublylinkedlist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "13.1. for loop from END to BEGIN by iterator *\n";
    std::cout << "mydoublylinkedlist:\t";
    for (auto it = mydoublylinkedlist.rbegin(); it != mydoublylinkedlist.rend(); --it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "14. for loop from begin to end by get() class function\n";
    std::cout << "mydoublylinkedlist:\t";
    for (auto it = mydoublylinkedlist.begin(); it != mydoublylinkedlist.end(); ++it) {
        std::cout << it.get() << " ";
    }
    std::cout << "\n";

    std::cout << "14.1. for loop from END to BEGIN by get() class function\n";
    std::cout << "mydoublylinkedlist:\t";
    for (auto it = mydoublylinkedlist.rbegin(); it != mydoublylinkedlist.rend(); --it) {
        std::cout << it.get() << " ";
    }
    std::cout << "\n";

    std::cout << "15. Copy Ctor\n";
    MyDoublyLinkedList<int> copydoublylinkedlist = mydoublylinkedlist;
    std::cout << "copydoublylinkedlist:\t" << copydoublylinkedlist << '\n';
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';
    std::cout << "16. Move Ctor\n";
    MyDoublyLinkedList<int> movedoublylinkedlist(std::move(mydoublylinkedlist));
    std::cout << "movedoublylinkedlist:\t" << movedoublylinkedlist << '\n';
    std::cout << "mydoublylinkedlist:\t" << mydoublylinkedlist << '\n';
    
    std::cout << "17. movedoublylinkedlist.pop_back() three times: \n";
    for (int i = 0; i < 3; ++i) {
        movedoublylinkedlist.pop_back();
        std::cout << "movedoublylinkedlist:\t" << movedoublylinkedlist << '\n';
    }
    std::cout << "18. movedoublylinkedlist.pop_front() three times: \n";
    for (int i = 0; i < 3; ++i) {
        movedoublylinkedlist.pop_front();
        std::cout << "movedoublylinkedlist:\t" << movedoublylinkedlist << '\n';
    }
    std::cout << "-------------- end doubly linked list implementation \n \n";
    
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

