#include <iostream>
#include <string>
using namespace std;

class Remove
{
public:
    string s;
    string part;
    Remove()
    {
      s="daabcbaabcbc";
      part="abc";
    }
    string removeOccurence(){
        while (s.length()>0 && s.find(part)<s.length()){   // stringname.find(part) ==>it saem the same portion of part in the string and return it's first index
            s.erase(s.find(part),part.length());     //stringname.erase(0,4)==>it'll erase the element from 1st index to the 4th index e.g;Kinzah ==> //h
        }
        return s;
    }
};
int main()
{
    Remove obj;
    cout<<obj.removeOccurence();

}