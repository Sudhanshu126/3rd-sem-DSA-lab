#include <iostream>

#define MAX 10000
int a[MAX], choice, size;

using namespace std;

class DataArray
{
    private:
    bool IsIndexValid(int index)
    {
        if(index >= 0)
        {
            return true;
        }
        else
        {
        return false;
        }
    }

    public: 
    void Create()
    {
        if(size == 0)
        {
            cout<<"Empty arrray created."<<endl;
        }
        else if(IsIndexValid(size))
        {
            cout<<"Enter "<<size<<" elements: "<<endl;
            for(int i=0; i<size; i++)
            {
                cin>>a[i];
            }
        }
        else
        {
            cout<<"Invalid size entered. Empty array created."<<endl;
            size = 0;
        }
    }

    void Display()
    {
        if(size == 0)
        {
            cout<<"No elements to display."<<endl;
        }
        else
        {
            for(int i=0; i<size; i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }

    void Insert()
    {
        if(size == MAX)
        {
            cout<<"Maximum size reached."<<endl;
            return;
        }
        int index, element;
        cout<<"Enter index: ";
        cin>>index;
        if(index > size)
        {
            index = size;
        }
        if(IsIndexValid(index))
        {
            cout<<"Enter element: ";
            cin>>element;
            int temp;
            for(int i=index; i<=size; i++)
            {
                temp = a[i];
                a[i] = element;
                element = temp;
            }
            size++;
        }
        else
        {
            cout<<"Invalid index entered."<<endl;
            return;
        }
        Display();
    }

    void Delete()
    {
        if(size == 0)
        {
            cout<<"No elements to delete."<<endl;
            return;
        }
        int index;
        cout<<"Enter index: ";
        cin>>index;
        if(index > size-1)
        {
            cout<<"Index more than array size."<<endl;
            return;
        }
        for(int i=index; i<size-1; i++)
        {
            a[i] = a[i+1];
        }
        size--;
        Display();
    }
};

int main()
{
    DataArray d;
    cout<<"Enter the size of array: ";
    cin>>size;

    if(size > 10000)
    {
        cout<<"Size is too big"<<endl;
        size = 0;
    }

    d.Create();

    while(true)
    {
        cout<<"Choose one option:-"<<endl<<"1. Display array"<<endl<<"2. Insert element"<<endl<<"3. Delete element"<<endl<<"4. Exit"<<endl<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                d.Display();
                break;
            case 2:
                d.Insert();
                break;
            case 3:
                d.Delete();
                break;
            case 4:
                cout<<"Exited successfully."<<endl;
                return 0;
            default:
                cout<<"Invalid choice entered."<<endl;
                break;
        }
    }
}