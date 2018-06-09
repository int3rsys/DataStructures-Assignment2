//
// Created by Omer on 09/06/2018.
//

#include "HashTable.h"
#include "testMacros.h"

bool testCreate() {
    int size = 10;
    int **array = new int *[size];
    int *keys = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = new int(i);
        keys[i] = i;
    }

    HashTable<int> table(size, array, keys);

    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;
    delete[] keys;
    return true;
}

bool testInsert() {
    int size = 10;
    int **array = new int *[size];
    int *keys = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = new int(i);
        keys[i] = i;
    }

    HashTable<int> table(size, array, keys);
    int x;

    x = 9;
    ASSERT_FALSE(table.insert(&x, x));

    x = 120;
    ASSERT_TRUE(table.insert(&x, x));
    ASSERT_FALSE(table.insert(&x, x));

    x = 90;
    ASSERT_TRUE(table.insert(&x, x));
    ASSERT_FALSE(table.insert(&x, x));

    x = 120;
    ASSERT_FALSE(table.insert(&x, x));

    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;
    delete[] keys;
    return true;
}

bool testSearch() {
    int size = 10;
    int **array = new int *[size];
    int *keys = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = new int(i);
        keys[i] = i;
    }

    HashTable<int> table(size, array, keys);
    int x;

    x = 10;
    ASSERT_EXCEPTION(table.search(x), HashElementNotFound);

    x = 8;
    ASSERT_TRUE(table.search(x) == 8);

    for (int i = 0; i < size; i++) {
        delete array[i];
    }
    delete[] array;
    delete[] keys;
    return true;
}

int main() {
    RUN_TEST(testCreate);
    RUN_TEST(testInsert);
    RUN_TEST(testSearch);
}
