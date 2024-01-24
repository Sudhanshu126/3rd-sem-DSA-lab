#include <iostream>
#define MAX 100
using namespace std;
class Stack{
    private:
    int arr[MAX], top, count;
    public:
    Stack(){
        top = -1;
        count = 0;
    }
    int Count(){
        return count;
    }
    void Push(int x){
        if(IsFull()){
            cout<<"Stack is overflow."<<endl;
            return;
        }
        arr[++top] = x;
        count++;
    }
    int Pop(){
        if(!IsEmpty()){
            count--;
            return arr[top--];
        }
        cout<<"Stack is underflow."<<endl;
    }
    bool IsFull(){
        if(top == MAX-1)
            return true;
        else
            return false;
    }
    bool IsEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    int Peek(){
        return arr[top];
    }
};
bool CheckPalindrome(Stack arr){
    Stack st1, st2=arr;
    int count = arr.Count();
    for(int i=0; i<count; i++)
        st1.Push(arr.Pop());
    for(int i=0; i<count; i++){
        if(st1.Pop() != st2.Pop())
            return false;
    }
    return true;
}
void ViewElements(Stack st){
    int count = st.Count();
    cout<<"The stack contains:"<<endl;
    for(int i=0; i<count; i++)
        cout<<st.Pop()<<endl;
}
int main(){
    Stack st;
    int choice, element;
    while(1){
        cout<<"---MENU---"<<endl<<"1. Push to stack"<<endl<<"2. Pop from stack"<<endl<<"3. Check palindrome"<<endl<<"4. View elements"<<endl<<"5. Exit"<<endl<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter element: ";
                cin>>element;
                st.Push(element);
                break;
            case 2: cout<<"Popped "<<st.Pop()<<endl;
                break;
            case 3:
                if(CheckPalindrome(st) == 1)
                    cout<<"Stack is palindrome"<<endl;
                else
                    cout<<"Stack is not palindrome."<<endl;
                break;
            case 4: ViewElements(st);
                break;
            case 5: cout<<"Exited successfully."<<endl;
                return 0;
            default: cout<<"Invalid choice entered."<<endl;
                break;
        }
    }
}