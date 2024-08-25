#include<iostream>
using namespace std;
#define MAX 100
int choice, front = 0, rear = -1, count = 0;
char queue[MAX], value;

void Display(){
    if(count == 0){
        cout<<"Queue is empty.\n";
    }else{
        for(int i = front; i <= rear; i++){
            cout<<queue[i]<<", ";
        }
        cout<<endl;
    }
}

void Insert(){
    if(count == MAX){
        cout<<"Queue overflow.\n";
    }else{
        rear = (rear+1)%MAX;
        queue[rear] = value;
        count++;
    }
}

void Delete(){
    if(count == 0){
        cout<<"Queue underflow.\n";
    }else{
        value = queue[front];
        cout<<"Deleted "<<value<<" from queue\n";
        front = (front+1)%MAX;
        count--;
    }
}

int main(){
    while(true){
        cout<<"1. Insert in queue\n2. Delete from queue\n3. View queue\n4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element: ";
                cin>>value;
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                cout<<"Exited successfully\n";
                return 0;
                break;
            default:
                cout<<"Invalid choice.\n";
                break;
        }
    }
}
