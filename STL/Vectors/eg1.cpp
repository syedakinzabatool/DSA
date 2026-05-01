#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    //assign() function to assign value to the vector
    v.assign(3,1);
    cout<<"The content: ";
    for(int i=0;i<v.size();i++){//it'll get size by itself
    cout<<v[i]<<" ";
    }
    cout<<endl;
    //using push_back()==>adds new element to the end
    v.push_back(3);//want to add 3 at the end
    int no=v.size();
    cout<<"Last element: "<<v[no-1]<<endl;
 //using push_back()==>adds new element to the end
    v.pop_back();//want to add 3 at the end
    cout<<"The contents after deleting elements are: ";
   for(int i=0;i<v.size();i++){//it'll get size by itself
    cout<<v[i]<<" ";
    }
    cout<<endl;
}