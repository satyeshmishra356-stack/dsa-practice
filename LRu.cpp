#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int val,key;
        node *pre;
        node *next;

        node(int k,int v){
            key = k;
            val = v;
            pre = next = nullptr;
        }
};
node *head = nullptr,*last = nullptr;
void push(int val,int key){
    node *temp = head;
    node *store = NULL;
    int found = 0;
    if(last!=NULL && key==last->key){
        last->val = val;
        return;
    }
    while(temp->next!=NULL){
        if(temp->key==key){
            if(temp!=head) temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            found = 1;
            store = temp;
            break;
        }
    }
    if(found==1){
        temp->next = store;
        store->pre = temp;
        store->next = nullptr;
        store->val = val;
    }
    else{
        node *nw = new node(key,val);
        if(head==NULL){
            head = nw;
            last = nw;
            return;
        }
        temp->next = nw;
        nw->pre = temp;
    }
}
int main(){

}