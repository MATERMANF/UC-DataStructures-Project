#include <iostream>

class LinkedList {

    private:



    public:

    LinkedList(){

    }
    /**
     * Adds the given item to the list
     */
    void AddItem(){

    }
    /**
     * Searches the list for the given item. 
     * If found, it removes it from the list and returns it. 
     * If not found, it returns a null pointer.
     */
    void GetItem(){
        
    }
    /**
     * Returns a bool indicating if the given item is in the list.
     */
    void IsInList(){

    }
    /**
     * Returns a bool indicating if the list is empty
     */
    void IsEmpty(){

    }
    /**
     * Returns the size of the list
     */
    void Size(){

    }
    /**
     *  Returns the next item without removing it from the list at a given location in the list. 
     *  When called twice, returns two items next to each other in the list.
     */
    void SeeNext(){

    }
    /**
     * Finds an item at a location in the list (int passed in from user), and
returns the item without removing it. If the location passed by the user is
past the end of the list, this will throw an error or display an error
message
     */
    void SeeAt(int pos){

    }
    /**
     * Resets the position that SeeNext uses
     */
    void Reset(){

    }
    /**
     * Destructor for the linked list
     * Should probably call every node's destructor. -Nathan
     */
    ~LinkedList(){

    }

};

int main(){
    int temp = 5;
    std::cout << "Hello World!" << std::endl;

}