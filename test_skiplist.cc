
#include "skiplist.h"

#include <cassert>
#include <iostream>

int main(void) {
    base::SkipList<int, int> list;
    list.Insert(10, 20);
    list.Insert(20, 30);
    list.Insert(30, 40);
    list.Insert(40, 50);

    int result;

    assert(list.LookUp(10, &result));
    assert(result == 20);

    // 遍历
    base::SkipList<int, int>::Iterator iter(&list);
    assert(!iter.Vaild());
    iter.SeekToFirst();
    while (iter.Vaild()) {
        std::cout << "key = " << iter.key() << "  ,  value = " << iter.value() << std::endl;
        iter.Next();
    }

    iter.SeekToLast();
    assert(iter.key() == 40);
    assert(iter.value() == 50);

    iter.Seek(30);
    iter.value() = 30;
    assert(iter.value() == 30);
    return 0;
}