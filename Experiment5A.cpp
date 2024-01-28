#include <iostream>
#include <cmath>
using namespace std;
int main(){
    string postfix;
    float stack[100];
    int top=0;
    cout<<"Enter valid postfix expression: ";
    cin>>postfix;
    for(char c: postfix){
        if(c>='0' && c<='9'){
            stack[top++] = c-'0';
        }
        else{
            int op1 = stack[--top];
            int op2 = stack[--top];
            float result;
            switch(c){
                case '+':
                    result = op2+op1;
                    break;
                case '-':
                    result = op2-op1;
                    break;
                case '*':
                    result = op2*op1;
                    break;
                case '/':
                    result = op2/op1;
                    break;
                case '%':
                    result = op2%op1;
                    break;
                case '^':
                    result = pow(op2,op1);
                    break;
                default:
                    cout<<"Invalid expression."<<endl;
                    return 1;
            }
            stack[top++] = result;
        }
    }
    cout<<"Postfix expression: "<<postfix<<endl;
    cout<<"The result is: "<<stack[top-1]<<endl;
    return 0;
}