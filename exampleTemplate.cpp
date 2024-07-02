#include <iostream>


template <typename T>
struct Node{
    T data;
    Node* next;
    Node* prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr){}
};
template <typename T>
class OrderedLinkedList {
private:

    Node<T>* head;
    Node<T>* current;

public:

};

int main(){
    OrderedLinkedList<int> list;
}
