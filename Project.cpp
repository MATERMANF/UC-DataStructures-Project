#include <iostream>

// The nodes in the linked list
template <typename data_type>
struct Node{
    data_type data;
    Node* next;
    Node* prev;

    ~Node(){
        delete next;
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
        if (head==nullptr || newNode->data < head->data){ //if no head or new data less than current head:
            newNode->next = head;                //update new node's next to previous head
            if(head != nullptr){
                head->prev = newNode;               //previous head's "prev" changes from nullptr to newNode
            }
            head = newNode;                    //update list's head to new node
        }
        else{                           
            Node<data_type>* prev = nullptr;
            Node<data_type>* curr = head;
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
        data_type* result = &(curr->data);
        curr->next = nullptr;
        //delete curr;
        size--;
        return result;
    }
    /**
     * Returns a bool indicating if the given item is in the list.
     */
    bool IsInList(data_type* item){     // Same code as GetItem, just without removing the item
        Node<data_type>* curr = head;
        while (curr!=nullptr && curr->data != *item){    //checks to see if current is valid and is the item
            //std::cout<<"\nChecking: " << *item << " - " << curr->data;
            curr = curr->next;
        }
        if (curr==nullptr) return false;    //if item not found: return null pointer
        else return true;
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
        data_type* temp = &position->data;
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
        if (pos > size-1){
            std::cout<<"Error: Index out of range.";
            return nullptr;
        }
        Node<data_type>* curr = head;
        while(pos > 0) {
            curr = curr->next;
            pos--;
        }
        return &curr->data;
    }
    /**
     * Resets the position that SeeNext uses
     */
    void Reset(){
        position = head;
    }
    /**
     * Destructor for the linked list
     * Should probably call every node's destructor. -Nathan
     */
    ~LinkedList(){
        delete head;
        //delete this;
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

    
    Student(){
    }

    Student(std::string FirstName, std::string LastName, std::string MNum, float GPA, std::string Birthday){
        if(Birthday[5] != '/' || Birthday[2] != '/'){
            std::cout<<"Error: Birthday should be in the form DD/MM/YYYY.";
            std::cerr<<"Error: Birthday should be in the form DD/MM/YYYY.";
            std::terminate();
        }
        this->FirstName = FirstName;
        this->LastName = LastName;
        this->MNumber = MNum;
        this->GPA = GPA;
        this->Birthday = Birthday;
    }

    Student(std::string FirstName, std::string LastName, std::string MNum, std::string Birthday){
        if(Birthday[5] != '/' || Birthday[2] != '/'){
            std::cout<<"Error: Birthday should be in the form DD/MM/YYYY.";
            std::cerr<<"Error: Birthday should be in the form DD/MM/YYYY.";
            std::terminate();
        }
        this->FirstName = FirstName;
        this->LastName = LastName;
        this->MNumber = MNum;
        this->GPA = 0.0f;
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

    bool operator != (Student &other){
        return std::stoi(MNumber.substr(1)) != std::stoi(other.MNumber.substr(1));;
    }

    bool operator > (Student &other){
        return std::stoi(MNumber.substr(1)) > std::stoi(other.MNumber.substr(1));;
    }

    bool operator < (Student &other){
        return std::stoi(MNumber.substr(1)) < std::stoi(other.MNumber.substr(1));;
    }

    // Use when comparing M-Number: std::stoi(MNum.substr(1));

};

int testFunct(){
    std::cout<<"Hi";
};


void testMenu(){
    LinkedList<Student> list;
    bool running = true;
    while(running){
        std::cout<<"\n\nWelcome to the test program!\n\n";
        std::cout<<"Please select an option:\n";
        std::cout<<"[0] - Add Item to list\n";
        std::cout<<"[1] - Get Item from list\n";
        std::cout<<"[2] - Check if item is in list\n";
        std::cout<<"[3] - Check if list is empty\n";
        std::cout<<"[4] - Check the size of the list\n";
        std::cout<<"[5] - Get the next item in the list\n";
        std::cout<<"[6] - Get item at specific index\n";
        std::cout<<"[7] - Sets \"next item\" to be the first item\n";
        std::cout<<"[8] - Exit\n";

        int option;
        std::cin>>option;
        std::cout<<"option: "<<option;

        switch (option){
            case 0: //Add Item
            {
                std::cout<<"Add Item\n";
                std::string FirstName;  // Create variables for input
                std::string LastName;
                std::string MNum;
                std::string Birthday;
                float GPA;

                Student* student;        // Create blank Student pointer

                std::cout<<"Enter first name: ";        // Request inputs
                std::cin>>FirstName;
                std::cout<<"Enter last name: ";
                std::cin>>LastName;
                std::cout<<"Enter M number: ";
                std::cin>>MNum;
                std::cout<<"Enter birthday (DD/MM/YYYY): ";
                std::cin>>Birthday;
                std::cout<<"Enter GPA, or -1 to skip: ";
                std::cin>>GPA;

                if(GPA == -1){                              // Add new student to list
                    student = new Student(FirstName, LastName, MNum, Birthday);
                }
                else{
                    student = new Student(FirstName, LastName, MNum, GPA, Birthday);
                }
                list.AddItem(student);
                std::cout << "Student added.\n";
                break;
            }
            case 1: //Get Item
            {
                std::cout<<"Get Item\n";
                std::string MNum;
                std::cout<<"Enter M number: ";
                std::cin>>MNum;
                Student* temp_student = new Student("irrelevant","irrelevant",MNum,"00/00/0000");
                Student* found_student = list.GetItem(temp_student);
                if(found_student != nullptr){
                    std::cout<<"Student:\n\tName: " << found_student->GetName()<<"\n\tMNumber: "<<found_student->GetMNumber()<<"\n\tAge: "<<found_student->GetAge()<<"\n";
                    std::cout<<"Student found and successfully removed from the list.\n";
                }
                else{
                    std::cout<<"Student not found.\n";
                }
                delete found_student;
                break;
            }
            case 2: //Check if item is in list
            {
                std::cout<<"Check if item is in list\n";
                std::string MNum;
                std::cout<<"Enter M number: ";
                std::cin>>MNum;
                if(list.IsInList(new Student("irrelevant","irrelevant",MNum,"00/00/0000"))){
                    std::cout<<"Student found.\n";
                }
                else{
                    std::cout<<"Student not found.\n";
                }
                break;
            }


            case 3: //Check if list is empty
            {
                std::cout<<"Check if list is empty\n";
                if(list.IsEmpty()){
                    std::cout<<"List is empty.\n";
                }
                else{
                    std::cout<<"List is not empty.\n";
                }

                break;
            }
            case 4: //Check the size of the list
            {
                std::cout<<"Check the size of the list\n";
                std::cout<<"Size: "<<list.Size()<<"\n";

                break;
            }
            case 5: //Get the next item in the list
            {
                std::cout<<"Get the next item in the list\n";
                Student* temp_student = list.SeeNext();
                std::cout<<"Next Student:\n\tName: " << temp_student->GetName()<<"\n\tMNumber: "<<temp_student->GetMNumber()<<"\n\tAge: "<<temp_student->GetAge()<<"\n";
                break;
            }
            case 6: //Get item at specific index
            {
                int index;
                std::cout<<"Get Item at specific index\nIndex: ";
                std::cin>>index;
                Student* temp_student = list.SeeAt(index);
                if(temp_student != nullptr){
                    std::cout<<"Student:\n\tName: " << temp_student->GetName()<<"\n\tMNumber: "<<temp_student->GetMNumber()<<"\n\tAge: "<<temp_student->GetAge()<<"\n";
                }
                else{
                    std::cout<<"Student not found.\n";
                }

                break;
            }
            case 7: //Sets "next item" to be the first item. Maybe print it too?
            {
                std::cout<<"Sets \"next item\" to be the first item.\n";
                list.Reset();
                std::cout<<"Operation Successful.\n";
                break;
            }
            default:
                running = false;
                break;
        }
    }
}

int main(){

    //used to test AddItem function
    LinkedList<int> list;
    int* item1 = new int(3);
    int* item2 = new int(1);
    int* item3 = new int(2);
    list.AddItem(item1);
    list.AddItem(item2);
    list.AddItem(item3);

    std::cout<<"Checking if list contains 2: "<<list.IsInList(item2)<<std::endl;

    //used to test GetItem function
    int* foundItem = list.GetItem(item2);
    if (foundItem){
        std::cout << "Found item: " << *foundItem << std::endl;
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
    testMenu();
    return 0;

}

