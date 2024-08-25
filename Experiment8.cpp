#include<iostream>
using namespace std;
#define MAX 100
struct Employee{
    string ssn, name, dept, designation, phNo;
    int salary;
    struct Employee* previous, * next;
};
typedef struct Employee Employee;
Employee* CreateNode(){
    Employee* newNode = new Employee;
    cout<<"Enter SSN, name, department, designation, salary and phone number: ";
    cin>>newNode->ssn>>newNode->name>>newNode->dept>>newNode->designation>>newNode->salary>>newNode->phNo;
    newNode->previous = newNode->next = nullptr;
    return newNode;
}
int CountNodes(Employee* head){
    Employee* node = head;
    int count = 0;
    while(node != nullptr){
        node = node->next;
        count++;
    }
    return count;
}
void Display(Employee* head){
    Employee* node = head;
    if(node ==nullptr){
        cout<<"No nodes to display.\n";
        return;
    }
    while(node != nullptr){
        cout<<"\n---Employee data---\n";
        cout<<"SSN: "<<node->ssn<<endl;
        cout<<"Name: "<<node->name<<endl;
        cout<<"Department: "<<node->dept<<endl;
        cout<<"Designation: "<<node->designation<<endl;
        cout<<"Salary: "<<node->salary<<endl;
        cout<<"Phone number: "<<node->phNo<<endl;
        node = node->next;
    }
}
void InsertAtFront(Employee* &head){
    if(CountNodes(head) == MAX){
        cout<<"Nodes overflow.\n";
        return;
    }
    Employee* newNode = CreateNode();
    newNode->next = head;
    newNode->previous = nullptr;
    head = newNode;
}
void InsertAtEnd(Employee* &head){
    if(CountNodes(head) == MAX){
        cout<<"Nodes overflow.\n";
        return;
    }
    Employee* node = head;
    if(node == nullptr){
        node = CreateNode();
        head = node;
    }else{
        while(node->next != nullptr){
            node = node->next;
        }
        Employee* newNode = CreateNode();
        node->next = newNode;
        newNode->previous = node;
    }
}
void DeleteAtFront(Employee* &head){
    if(head == nullptr){
        cout<<"Nodes underflow.\n";
        return;
    }
    Employee* headNode = head;
    head = headNode->next;
    head->previous = nullptr;
    delete(headNode);
}
void DeleteAtEnd(Employee* &head){
    if(head == nullptr){
        cout<<"Nodes underflow.\n";
        return;
    }
    Employee* node, * previousNode;
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
void DEQueue(Employee* head){
    int choice;
    do{
        cout<<"\n----- DLL as a Double Ended Queue -----\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                InsertAtFront(head);
                break;
            case 2:
                InsertAtEnd(head);
                break;
            case 3:
                DeleteAtFront(head);
                break;
            case 4:
                DeleteAtEnd(head);
                break;
        }
    }while(choice!=5);
    Display(head);
}
int main(){
    Employee* head = nullptr;
    int choice;
    do{
        cout<<"1. Create list\n2. Display list\n3. Insert at rear\n4. Insert at front\n5. Delete from front\n6. Delete from rear\n7. Double ended Queue\n8. Exit\nEnter choice: ";
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
                DEQueue(head);
                break;
            case 8:
                cout<<"Exited successfully\n";
                return 0;
                break;
            default:
                cout<<"Invalid choice.\n";
                break;
        }
    }while(choice != 8);
    return 0;
}