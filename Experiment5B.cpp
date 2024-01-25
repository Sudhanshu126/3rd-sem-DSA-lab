#include <iostream>
#include <cmath>
using namespace std;
void TOH(int n, char s, char h, char d){
    if(n==1){
        cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    TOH(n-1, s, d, h);
    cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(n-1, h, s, d);
}
int main(){
    int size;
    cout<<"Enter tower height: ";
    cin>>size;
    TOH(size, 'A', 'B', 'C');
    cout<<"Total number of moves are: "<<(pow(2, size)-1);
    return 0;
}