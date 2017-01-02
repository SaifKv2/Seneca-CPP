// OOP345 Workshop 4 - Templates
// File	KVL.h
// Date	2016/02/15
// Author Ben Mantle (064-329-147)

#ifndef _KVLIST_H
#define _KVLIST_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>

template <typename K, typename V, int N>

class KVList {
private:
    K* keys;
    V* values;
    int count;

public:
    KVList();
    size_t size() const;
    const K& key(int i) const { return keys[i]; };
    const V& value(int i) const { return values[i]; };
    KVList& add(const K& key, const V& value);
    int find(const K& k) const;
    KVList& replace(int i, const K& k, const V& v);
};

template <typename K, typename V, int N>

KVList<K, V, N>::KVList() {

    keys = new K[N];
    values = new V[N];
    count = 0;
};

template <typename K, typename V, int N>

size_t KVList<K, V, N>::size() const {
    return count;
};

template <typename K, typename V, int N>

KVList<K, V, N>& KVList<K, V, N>::add(const K& key, const V& value) {

    if (count < N) {

	    keys[count] = key;
	    values[count] = value;
	    count++;
    }

    else {
	    std::cout << "The array is full.\n";
    }

    return *this;
};

template <typename K, typename V, int N>

int KVList<K, V, N>::find(const K& k) const {

    int res = -1;

    for ( int i = 0; i < N; i++ ) {

	  if (keys[i] == k) {
	    res = i;
	  }
    }

    return res;
};

template <typename K, typename V, int N>

KVList<K, V, N>& KVList<K, V, N>::replace(int i, const K& k, const V& v) {

    keys[i] = k;
    values[i] = v;
    return *this;
}

#endif // _KVLIST_H
