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