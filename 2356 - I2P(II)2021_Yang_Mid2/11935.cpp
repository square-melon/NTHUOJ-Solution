#include <iostream>
#include "11935_function.cpp"
using namespace std;
int main(){
    _stack stk;
    _queue que;
    string inst;
    string cont;
    int data;
    _node* ptr;
    while(cin>>cont){
        if(cont=="stack"){
            //stack
            cin>>inst;
            if(inst=="push"){
                cin>>data;
                stk.push(data);
            }
            else if(inst=="pop"){
                stk.pop();
            }
            else if(inst=="top"){
                ptr = stk.get_data();
                if(ptr!=NULL)
                    cout<<stk.get_data()->data<<"\n";
            }
        }
        else if(cont=="queue"){
            //stack
            cin>>inst;
            if(inst=="push"){
                cin>>data;
                que.push(data);
            }
            else if(inst=="pop"){
                que.pop();
            }
            else if(inst=="front"){
                ptr = que.get_data();
                if(ptr!=NULL)
                    cout<<que.get_data()->data<<"\n";
            }
        }
        else{
            break;
        }
    }

}
