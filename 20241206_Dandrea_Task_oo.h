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

    friend istream& operator>>(istream&in,Node &node){
        in>>node.value;
        return in;
    }

    friend ostream& operator<<(ostream&out,const Node &node){
        out<<node.value<<endl;
        return out;
    }
    
    istream& operator>>(istream& in, const Node* Node){
        cout<<"Inserisci un valore"<<endl;
        in>>Node->value;
        return in;
    }

    ostream& operator<<(ostream& out, const Node* Node){
        cout<<"Centrale"<<endl;
        out<<Node->value
        if(Node->left!=NULL){
            cout<<"Sinistro:"<<endl;
            out<<Node->left->value;
        }
        if(Node->right!=NULL){
            cout<<"Destro;"<<endl;
            out<<Node->right->value;
        }
        return out;
    }

    Node* insertR(int k){
        if(k>value){
            if(right==NULL){
                right=new Node(k);
            }else{
                right->insertR(k);
            }

        }else{
            if(left==NULL){
                left=new Node(k);
            }else{
                left->insertR(k);
            }
        }
        return this;
    }

    void inOrder(){
        if(left!=NULL){
            left->inOrder();
        }
        cout<<value<<endl;
        if(right!=NULL){
            right->inOrder();
        }
    }

    void preOrder(){
        cout<<value<<endl;
        if(left!=NULL){
            left->inOrder();
        }
        if(right!=NULL){
            right->inOrder();
        }
    }

    void postOrder(){
        if(left!=NULL){
            left->inOrder();
        }
        if(right!=NULL){
            right->inOrder();
        }
        cout<<value<<endl;
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

    Node* deleteNode(int k){
        if()
    }
    bool isBst(){

    }
};