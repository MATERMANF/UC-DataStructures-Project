#include <iostream>

// The nodes in the linked list
template <typename data_type>
struct Node{
    data_type data;
    Node* next;
    Node* prev;

    ~Node(){
        delete next;
        delete this;
    }
};

// The linked list
template <typename data_type>
class LinkedList {

    private:

    Node<data_type>* head;
    Node<data_type>* tail;
    int size;
    Node<data_type>* position;  // To save time, position is a pointer to a node rather than an integer


    public:

    /**
     * Constructor for the linked list
     */
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
        position = head;
    }
    /**
     * Adds the given item to the list
     */
    void AddItem(data_type* item){

    }
    /**
     * Searches the list for the given item. 
     * If found, it removes it from the list and returns it. 
     * If not found, it returns a null pointer.
     */
    data_type* GetItem(int index){
        
    }
    /**
     * Returns a bool indicating if the given item is in the list.
     */
    bool IsInList(data_type* item){

    }
    /**
     * Returns a bool indicating if the list is empty
     */
    bool IsEmpty(){
        return size == 0;
    }
    /**
     * Returns the size of the list
     */
    int Size(){
        return size;
    }
    /**
     *  Returns the next item without removing it from the list at a given location in the list. 
     *  When called twice, returns two items next to each other in the list.
     */
    data_type* SeeNext(){
        if(position == nullptr){
            position = head;
        }
        data_type* temp = position->data;
        position = position->next;
        return temp;
    }
    /**
     * Finds an item at a location in the list (int passed in from user), and
returns the item without removing it. If the location passed by the user is
past the end of the list, this will throw an error or display an error
message
     */
    data_type* SeeAt(int pos){

    }
    /**
     * Resets the position that SeeNext uses
     */
    void Reset(){
        position = 0;
    }
    /**
     * Destructor for the linked list
     * Should probably call every node's destructor. -Nathan
     */
    ~LinkedList(){
        delete head;
        delete this;
    }

};

int main(){
    
    LinkedList<int> list;

}