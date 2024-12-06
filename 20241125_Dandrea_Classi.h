#include <iostream>
using namespace std;

class Node{
    private:
    int value;
    Node* left;
    Node* right;

    public:
    Node(int v){
        value=v;
        left=nullptr;
        right=nullptr;
    }
    Node* InsertR(int k){
        if(k>value){
            if(right==NULL){
                right=new Node(k);
            }else{
                right->InsertR(k);
            }

        }else{
            if(left==NULL){
                left=new Node(k);
            }else{
                left->InsertR(k);
            }
        }
        return this;
    }

    void InOrder(){
        if(left!=NULL){
            left->InOrder();
        }
        cout<<value<<endl;
        if(right!=NULL){
            right->InOrder();
        }
    }
};