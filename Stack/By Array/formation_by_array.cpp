#include<iostream>
using namespace std;
#define MAX_SIZE 5

class Stack{
    private:
        int top;
        int arr[MAX_SIZE];
    public:
        Stack(){
            top=-1; 
        }

        bool isEmpty(){
           return top==-1;
        }

        bool isFull(){
            return top == MAX_SIZE-1;
        }

        void push(int value){
            if(isFull()){
                cout<<"Stack is Full "<<value<<" cannot be entered"<<endl;
                return;
            }
            arr[++top] = value;
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack is Empty "<<endl;
                return -1;
            }
            return arr[top--];
        }

};
int main(){

    Stack obj1;
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    for(int i=0;i<3;i++){
        cout<<"Value "<<i+1<<" is: "<<obj1.pop()<<endl;
    }

    return 0;
}