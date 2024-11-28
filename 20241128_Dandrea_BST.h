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
    
    bool searchI(int k){
        Node* current=this;
        do{
            if(current->value==k){
                cout<<"Trovato"<<endl;
                return true;
        
            }
            if(k<current->value){
                current=current->left;
            }else{
                current=current->right;
            }
        }while(current!=this);
        return false;
    }
    bool searchR(int k){
        if(this==NULL){
            cout<<"Non esistente"<<endl;
            return false;
        }
        if(this->value==k){
            cout<<"Trovato"<<endl;
            return true;
        }
        if(k<this->value){
            return left->searchR(k);
        }else{
            return right->searchR(k);
        }
    }
    Node* insertI(int k){
        Node* newNode=new Node(k);
        Node* current=this;
        Node* father=nullptr;
        do{
            father=current;
            if(k<current->value){
                current=current->left;
            }else{
                current=current->right;
            }
            if(k<father->value){
                father->left=newNode;
            }else{
                father->right=newNode;
            }

        }while(current!=nullptr);
        return this;
    }
};