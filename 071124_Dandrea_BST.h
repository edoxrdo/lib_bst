#include <iostream>
using namespace std;

//Creazione Struttura
struct Node{
    int value;
    Node* right;
    Node* left;
    Node(int v){
        value=v;
        right=nullptr;
        left=nullptr;
    }
};


//Inserimento Ricorsivo
Node* Insert_R(Node* root, int k){
    if(root==NULL){
        return new Node(k);
    }
    if(root->value==k){
        return root;
    }
    if(k<root->value){
        root->left=Insert_R(root->left, k);
    }else{
        root->right=Insert_R(root->right, k);
    }
    return root;
};


//Inserimento Iterativo
Node* Insert_I(Node* root, int k){
    bool check{true};
    Node* current{root};
    Node* father{root};
    do{
        if(current==NULL){
            if(k<father->value){
                father->left=new Node(k);
                check=false;
                return root;

            }else{
                father->right=new Node(k);
                check=false;
                return root;
            
            }
        }
        if(current->value==k){
            check=false;
            return root;

        }
        if(k<current->value){
            father=current;
            current=current->left;

        }else{
            father=current;
            current=current->right;
        }
    }while(check);
    return root;
};

//Ricerca Ricorsiva
Node* Search_R(Node* root, int k){
    if(root==NULL){
        cout<<"Non trovato"<<endl;
        return root;
    }
    if(root->value==k){
        cout<<"Trovato"<<endl;
        return root;
    }
    if(k<root->value){
        root->left=Search_R(root->left, k);
    }else{
        root->right=Search_R(root->right, k);
    }
    return root;
};

//Ricerca Iterativa
Node* Search_I(Node* root, int k){
    bool check{true};
    Node* current{root};
    Node* father{root};
    do{
        if(current==NULL){
            cout<<"Non è questo"<<endl;
            check=false;
            return root;

        }
        if(current->value==k){
            cout<<"Trovato"<<endl;
            check=false;
            return root;
        }
        if(k<current->value){
            father=current;
            current=current->left;
        }else{
            father=current;
            current=current->right;
        }

    }while(check);
    return root;
}

//Cancellazione Ricorsiva
Node* Cancel_R(Node* root, int k){
    if(root==NULL){
        cout<<"Non è presente"<<endl;
        return root;
    }
    if(root->value==k){
        if(root->right==NULL && root->left==NULL){
            delete [] root;
            root->value=0;
            root=nullptr;
            return root;

        }
        if(root->right!=NULL && root->left==NULL){
            root->value=root->right->value;
            delete [] root->right;
            root->right=nullptr;
            return 0;


        }
        if(root->right==NULL && root->left!=NULL){
            root->value=root->left->value;
            delete [] root;
            root->left=nullptr;
            return 0;
        }

    }
    if(k<root->value){
        root->left= Cancel_R(root->left,k);
    }else{
        root->right= Cancel_R(root->right,k);
    }
    return root;
}

//Cancellazione Iterativa
Node *Cancel_I(Node *root, int k){
    bool check=false;
    Node* current{root};
    do
    {
        if(current==NULL){
            cout<<"Non trovato"<<endl;
            return root;
        }
        if(current->value==k){
            if(current->left==nullptr && current->right==nullptr){
                delete [] current;
                current->value=0;
                current->left->value=0;
                current->left=nullptr;
                current->right->value=0;
                current->right=nullptr;
                return root;
            }
            if(current->left!=nullptr && current->right==nullptr){
                current->value=current->left->value;
                delete [] current->left;
                current->left->value=0;
                current->left=nullptr;
                return root;
            }
            if(current->left==nullptr && current->right!=nullptr){
                current->value=current->right->value;
                delete [] current->right;
                current->right->value=0;
                current->right=nullptr;
                return root;
            }
        }
        if(k<current->value){
            current=current->left;
        }else{
            current=current->right;
        }
    }while(check);
    return root;
}

//Calcolo dell'Altezza
int Maximum(int l,int r){
    if(l>r){
        return l;
    }
    return r;
}
int Height(Node *root){
    if(root==NULL){
        return 0;
    }
    int l=Height(root->left);
    int r=Height(root->right);
    return Maximum(l,r)+1;
}

//Verifica BST
bool Bst(Node* root, Node* Minimum=nullptr, Node* Maximum=nullptr) {
    if(root==nullptr){
        return true;
    }
    if(Minimum!=nullptr && root->value<=Minimum->value){
        return false;
    }
    if(Maximum!=nullptr && root->value>=Maximum->value){
        return false;
    }
    return Bst(root->left,Minimum,root) && Bst(root->right, root, Maximum);
}

//Attraversamento InOrder
Node* InOrder (Node*root){
    if(root==NULL){
        cout<<"L'albero è vuoto"<<endl;
    }else{
        if(root->left!=NULL){
            InOrder(root->left );
        }
        cout<<root->value<<" ";
        if(root->right!=NULL){
            InOrder(root->right );
        }
    }
    return root;
}

//Attraversamento PreOrder
Node* PreOrder(Node* root){
    if(root==NULL){
        return root;
    } 
    cout<<root->value<<" ";
    if(root->left!=NULL){
       PreOrder(root->left); 
    }else{
        PreOrder(root->right);
    }
    return root;
}

//Attraversamento PostOrder
Node* PostOrder(Node* root) {
    if (root==NULL){
        return root;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->value<<" ";
    return root;
}











