#include <iostream>
using namespace std;

template<typename T>
class MyDeck {
private:
    unsigned long len;
    long HEAD;
    long TAIL;
    T *arr;
public:
    MyDeck(unsigned long size);

    void push_front(T item);
    void push_back(T item);
    T pop_front();
    T pop_back();
    long size();

    template<typename U>
    friend ostream& operator<<(ostream &out, MyDeck<U> &dt);
};

template<typename T>
ostream &operator<<(ostream &out, MyDeck<T> &dt) {
    for (long i = dt.HEAD; i < dt.TAIL; i++)
        out << dt.arr[i] << " ";
    return out;
}

template<typename T>
MyDeck<T>::MyDeck(unsigned long size) : len(size), HEAD(size - 1), TAIL(size - 1), arr(new T[2 * size - 1]) {}

template<typename T>
long MyDeck<T>::size() {
    return abs(HEAD - TAIL);
}

template<typename T>
void MyDeck<T>::push_front(T item) {
    MyDeck<T>::arr[--HEAD] = item;
}

template<typename T>
void MyDeck<T>::push_back(T item) {
    MyDeck<T>::arr[TAIL++] = item;
}

template<typename T>
T MyDeck<T>::pop_back() {
    if (TAIL != HEAD)
        return MyDeck<T>::arr[--MyDeck<T>::TAIL];
    else {
        cerr << "Empty deque";
        return T();
    }
}

template<typename T>
T MyDeck<T>::pop_front() {
    if (TAIL != HEAD)
        return MyDeck<T>::arr[MyDeck<T>::HEAD++];
    else {
        cerr << "Empty deque";
        return T();
    }
}

int main() {
    MyDeck<int> Deque(5);
    Deque.push_back(3);
    Deque.push_back(13);
    Deque.push_front(1);
    Deque.pop_back();
    Deque.pop_front();
    cout << Deque.size() << endl;
    cout << Deque;
    return 0;
}
