#include<iostream>
using namespace std;
#define MAX 100
struct Student{
    string userName, name, branch, phoneNo;
    int semester; 
    struct Student* next;
};
typedef struct Student Student;
Student* CreateNode(){
    Student* newNode = new Student;
    cout<<"Enter username, name, branch, semester and phone number: ";
    cin>>newNode->userName>>newNode->name>>newNode->branch>>newNode->semester>>newNode->phoneNo;
    newNode->next = nullptr;
    return newNode;
}
int CountNodes(Student* head){
    Student* node = head;
    int count = 0;
    while(node != nullptr){
        node = node->next;
        count++;
    }
    return count;
}
void Display(Student* head){
    Student* node = head;
    if(node ==nullptr){
        cout<<"No nodes to display.\n";
        return;
    }
    cout<<"Displaying "<<CountNodes(head)<<" data.\n";
    while(node != nullptr){
        cout<<"\n---Student data---\n";
        cout<<"Username: "<<node->userName<<endl;
        cout<<"Name: "<<node->name<<endl;
        cout<<"Branch: "<<node->branch<<endl;
        cout<<"Semester: "<<node->semester<<endl;
        cout<<"Phone number: "<<node->phoneNo<<endl;
        node = node->next;
    }
}
void InsertAtFront(Student* &head){
    if(CountNodes(head) == MAX){
        cout<<"Nodes overflow.\n";
        return;
    }
    Student* newNode = CreateNode();
    newNode->next = head;
    head = newNode;
}
void InsertAtEnd(Student* &head){
    if(CountNodes(head) == MAX){
        cout<<"Nodes overflow";
        return;
    }
    Student* node = head;
    if(node == nullptr){
        node = CreateNode();
        head = node;
    }else{
        while(node->next != nullptr){
            node = node->next;
        }
        Student* newNode = CreateNode();
        node->next = newNode;
    }
}
void DeleteAtFront(Student* &head){
    if(head == nullptr){
        cout<<"Nodes underflow.\n";
        return;
    }
    Student* headNode = head;
    head = head->next;
    delete(headNode);
}
void DeleteAtEnd(Student* &head){
    if(head == nullptr){
        cout<<"Nodes underflow.\n";
        return;
    }
    Student* node, * previousNode;
    node = previousNode = head;
    while(node->next != nullptr){
        previousNode = node;
        node = node->next;
    }
    previousNode->next = nullptr;
    if(node != head){
        delete(node);
    }else{
        delete(head);
        head = nullptr;
    }
}
void Stack(Student* head){
    int choice;
    do{
        cout<<"\n----- SLL as a Stack -----\n1. Insert at Top(PUSH)\n2. Delete from Top(POP))\n3. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                InsertAtFront(head);
                break;
            case 2:
                DeleteAtFront(head);
                break;
            case 3:
                break;
        }
        Display(head);
    }while(choice!=3);
}
void Queue(Student* head){
    int choice;
    do{
        cout<<"\n----- SLL as a Queue -----\n1. Insert at Rear(ENQUEUE)\n2. Delete from Front(DEQUEUE)\n3. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                InsertAtEnd(head);
                break;
            case 2:
                DeleteAtFront(head);
                break;
            case 3:
                break;
        }
        Display(head);
    }while(choice!=3);
}
int main(){
    Student* head = nullptr;
    int choice;
    do{
        cout<<"1. Create list\n2. Display list\n3. Insert at rear\n4. Insert at front\n5. Delete from front\n6. Delete from rear\n7. Stack\n8. Queue\n9. Exit\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                head = CreateNode();
                break;
            case 2:
                Display(head);
                break;
            case 3:
                InsertAtEnd(head);
                break;
            case 4:
                InsertAtFront(head);
                break;
            case 5:
                DeleteAtFront(head);
                break;
            case 6:
                DeleteAtEnd(head);
                break;
            case 7:
                Stack(head);
                break;
            case 8:
                Queue(head);
                break;
            case 9:
                cout<<"Exited successfully\n";
                return 0;
                break;
            default:
                cout<<"Invalid choice.\n";
                break;
        }
    }while(choice != 9);
    return 0;
}