#include <iostream>
using namespace std;
int Priority(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'||c=='%'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    string infix, postfix;
    char stack[100], top=0;
    cout<<"Enter valid infix expression: ";
    cin>>infix;
    for(char c: infix){
        if(c>='A' && c<='Z' || c>='a' && c<='z'){
            postfix+=c;
        }
        else if(c=='('){
            stack[top++] = c;
        }
        else if(c==')'){
            while(stack[top-1]!='('){
                postfix+=stack[--top];
            }
            top--;
        }
        else{
            if(Priority(c) == 0){
                cout<<"Invalid character found."<<endl;
                return 1;
            }
            if(top==0){
                stack[top++] = c;
            }
            else{
                while(Priority(stack[top-1])>Priority(c) && top!=0){
                    postfix+=stack[--top];
                }
                if(stack[top-1] == '^'){
                    stack[top++]=c;
                }
                else if(Priority(stack[top-1])==Priority(c)){
                    postfix+=stack[--top];
                }
                stack[top++] = c;
            }
        }
    }
    if(top>0){
        while(top>0){
            postfix+=stack[--top];
        }
    }
    cout<<"The infix is: "<<infix<<endl;
    cout<<"The postfix is: "<<postfix<<endl;
    return 0;
}