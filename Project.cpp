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
        Node<data_type>* newNode = new Node<data_type>;    //creates new node
        newNode->data = *item;                            //adds new item to new node's data
        //    !!!!This line breaks compiler: trying without pointers?
        //if (head==nullptr || *(newNode->data) < *(head->data)){    //if no head or new data less than current head:
        if (head==nullptr || newNode->data < head->data){ //if no head or new data less than current head:
            newNode->next = head;                //update new node's next to previous head
            head->prev = newNode;               //previous head's "prev" changes from nullptr to newNode
            head = newNode;                    //update list's head to new node
            head->prev = nullptr;            //changes the head's previous back to nullptr
        }
        else{                           
            Node<data_type>* prev = nullptr;
            Node<data_type>* curr = head;
            //while (curr && *(curr->data) < *(newNode->data)){    //!!! breaks compiler?
            while (curr && curr->data < newNode->data){
                prev = curr;
                curr = curr->next;
            }
            newNode->next = curr;
            prev->next = newNode;
        }
        size++;
    }
    /**
     * Searches the list for the given item. 
     * If found, it removes it from the list and returns it. 
     * If not found, it returns a null pointer.
     */
    data_type* GetItem(data_type* item){
        Node<data_type>* prev = nullptr;
        Node<data_type>* curr = head;
        //while (curr!=nullptr && *(curr->data)!=*item){    //breaks compiler
        while (curr!=nullptr && curr->data!=*item){    //checks to see if current is valid and is the item
            prev = curr;
            curr = curr->next;
        }
        if (curr==nullptr) return nullptr;    //if item not found: return null pointer
        if (prev==nullptr){        //if item found at beginning:
            head = curr->next;        //update head to next item, since node is to be deleted later
        }
        else{
            prev->next = curr->next;    //update item's previous "next" to the current node's "next" for deletion
        }
        data_type* result = curr->data;    //!!!error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
        delete curr;
        size--;
        return result;
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
        return size==0;
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

class Student {
    private:

    std::string FirstName;
    std::string LastName;
    std::string MNumber;
    float GPA;
    std::string Birthday;   // Format: YYYY/MM/DD


    public:

    Student(std::string FirstName, std::string LastName, std::string MNum, float GPA, std::string Birthday){
        this->FirstName = FirstName;
        this->LastName = LastName;
        this->MNumber = MNum;
        this->GPA = GPA;
        this->Birthday = Birthday;
    }

    std::string GetName(){
        return FirstName + " " + LastName;
    }

    std::string GetMNumber(){
        return MNumber;
        //std::string temp = "M" + std::to_string(MNumber);
        //return temp;
    }

    int GetAge(){
        return 2024 - std::stoi(Birthday.substr(6));
    }

    // Overide of operators

    bool operator == (Student &other){
        return std::stoi(MNumber.substr(1)) == std::stoi(other.MNumber.substr(1));;
    }

    bool operator > (Student &other){
        return std::stoi(MNumber.substr(1)) > std::stoi(other.MNumber.substr(1));;
    }

    bool operator < (Student &other){
        return std::stoi(MNumber.substr(1)) < std::stoi(other.MNumber.substr(1));;
    }

    // Use when comparing M-Number: std::stoi(MNum.substr(1));

};

int main(){

    //used to test AddItem function
    LinkedList<int> list;
    int* item1 = new int(3);
    int* item2 = new int(1);
    int* item3 = new int(2);
    list.AddItem(item1);
    list.AddItem(item2);
    list.AddItem(item3);

    //used to test GetItem function
    int* foundItem = list.GetItem(item2);
    if (foundItem){
        std::cout << "Found item: " << *foundItem << std::endl;
        delete foundItem;
    } else{
        std::cout << "Item not found." << std::endl;
    }
        

    
    Student myStudent = Student("Nathan", "Fullerton", "M14923244", 3.5, "05/24/2004");
    Student notMyStudent = Student("Sterling", "Hofmann", "M14923294", 3.5, "05/24/2004");
    std::cout<<myStudent.GetName()<<std::endl;
    std::cout<<myStudent.GetMNumber()<<std::endl;
    std::cout<<myStudent.GetAge()<<std::endl;

    if(myStudent < notMyStudent){
        std::cout<<"Pass!";
    }
    else{
        std::cout<<"Fail!";
    }

    return 0;

}

