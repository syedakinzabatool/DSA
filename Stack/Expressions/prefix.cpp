#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
//Jab opernd(value) aay to push krna h
//Jab symbol(operator) aay to 2 values ko variable main rakh k pop krna h
int prefix_Evaluation(string s){
    stack<int> st;
    for(int i=s.length()-1 ; i>=0 ; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;            
                }
        }
    }
    return st.top();
}

int main(){

    cout<<prefix_Evaluation("-+7*45+20")<<endl;

    return 0;
}