/*
 * test.cpp
 *
 *  Created on: Jun 17, 2024
 *      Author: ffan
 *
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

void test1()
{
    int myints[] = {16,2,77,29};
    std::vector<int> v (myints, myints+4);
    int i = 0;
    for(std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it) {
        std::cout << "v[" <<  i << "] = " << *it << std::endl;
        ++i;
    }
}

int main()
{
    test1();
    return 0;
}


