#include <iostream>
#define MAX 10000
int a[MAX], choice, size=0;
using namespace std;
void Create(){
    if(size == 0)
        cout<<"Empty arrray created."<<endl;
    else if(size > 0){
        cout<<"Enter "<<size<<" elements: "<<endl;
        for(int i=0; i<size; i++)
            cin>>a[i];
    }
    else{
        cout<<"Invalid size entered. Empty array created."<<endl;
        size = 0;
    }
}
void Display(){
    if(size == 0)
        cout<<"No elements to display."<<endl;
    else{
        for(int i=0; i<size; i++)
            cout<<a[i]<<" ";
        
        cout<<endl;
    }
}
void Insert(){
    if(size == MAX){
        cout<<"Maximum size reached."<<endl;
        return;
    }
    int index, element;
    cout<<"Enter index: ";
    cin>>index;
    if(index > size)
        index = size;
    if(index >= 0){
        cout<<"Enter element: ";
        cin>>element;
        int temp;
        for(int i=index; i<=size; i++){
            temp = a[i];
            a[i] = element;
            element = temp;
        }
        size++;
    }
    else{
        cout<<"Invalid index entered."<<endl;
        return;
    }
    Display();
}
void Delete(){
    if(size == 0){
        cout<<"No elements to delete."<<endl;
        return;
    }
    int index;
    cout<<"Enter index: ";
    cin>>index;
    if(index > size-1){
        cout<<"Index more than array size."<<endl;
        return;
    }
    for(int i=index; i<size-1; i++)
        a[i] = a[i+1];
    size--;
    Display();
}
int main(){
    while(true){
        cout<<"Choose one option:-"<<endl<<"1. Create array"<<endl<<"2. Display array"<<endl<<"3. Insert element"<<endl<<"4. Delete element"<<endl<<"5. Exit"<<endl<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the size of array: ";
                cin>>size;
                Create();
                break;
            case 2: Display();
                break;
            case 3: Insert();
                break;
            case 4: Delete();
                break;
            case 5: cout<<"Exited successfully."<<endl;
                return 0;
            default: cout<<"Invalid choice entered."<<endl;
                break;
        }
    }
}