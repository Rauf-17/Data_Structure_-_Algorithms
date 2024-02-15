
#include <iostream>
using namespace std;

class Stack{

private :

    int maxSize,top;
    char st[20];

public :

    Stack(int x, char *a){
        maxSize = x - 1;
        top = -1;
    }

    bool isFull(){

        if(top == maxSize){
            return true;
        }

        else{
            return false;
        }
    }

    bool isEmpty(){

        if(top == -1){
            return true;
        }

        else{
            return false;
        }
    }


    void push(char Element){

        if(isFull()){
            cout<<"Stack Is Full\n";
        }

        else{
            top = top + 1;
            st[top] = Element;
        }
    }

    char pop(){

        if(isEmpty()){

            cout<<"Stack Is Empty\n";

            return '\0';
        }

        else{
            char temp = st[top];

            st[top] = '\0';

            top = top - 1;

            return temp;
        }
    }
};

int main()
{
    int size = 0;

    char String[20];

    cout<<"Write A String To Reverse : ";

    cin.getline(String,20);

    for(int i = 0; i < 20; i++){

        if(String[i] != '\0'){

            size = size + 1;
        }

        else{

            size = size + 1;
            break;
        }
    }


    Stack Reverse(size,String);


    char y;

    for(int i = 0 ; i < size; i++){
        Reverse.push(String[i]);
    }

    for(int i = 0 ; i < size; i++){
        y = Reverse.pop();

        if(y == '\0'){

            String[size - 1] = y;
        }

        else{
            String[i - 1] = y;
        }
    }

    cout<<"The Reversed String Is : ";

    for(int i = 0; i<size; i++)
    {
        cout<<String[i];
    }

    return 0;
}
