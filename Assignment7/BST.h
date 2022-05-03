#ifndef BST_H
#define BST_H
#include <string>
#include <stddef.h>
#include <iostream>




using namespace std;

template <typename E> class TreeNode{
    public:
        TreeNode();
        TreeNode(E k);
        ~TreeNode();

        E key;
        TreeNode<E> *left;
        TreeNode<E> *right;

        bool operator!=(TreeNode<E> node);
        bool operator==(TreeNode<E> node);
};

template <typename E> TreeNode<E>::TreeNode(){
    left =  NULL;
    right =  NULL;
}

template <typename E> TreeNode<E>::TreeNode(E k){
    left =  NULL;
    right =  NULL;
    key = k;
}

template <typename E> TreeNode<E>::~TreeNode(){
    // destructor
}


// BST 

template <typename E> class BST{
    private:
        TreeNode<E>* root; // root of tree
        int size; // number of elements in tree

    public:
        BST();
        ~BST();
        bool contains(E k);
        bool containsID(int k);
        bool printStudentInfo(E v);
        bool printFacultyInfo(E v);
        E find(E k);
        void insert(E v);
        bool remove(int k);
        TreeNode<E>* getSuccessor(TreeNode<E>* d);
        E getMin();
        E getMax();
        void inOrder(bool student, TreeNode<E> *node);
        void studentInOrder(TreeNode<E> *node);
        void facultyInOrder(TreeNode<E> *node);

        void printTree();
        TreeNode<E>* getRoot();
        int length();
        bool isEmpty();
};

//Constructor, sets root and size values.

template <typename E> BST<E>::BST(){
    root =  NULL;
}

//Destructor

template <typename E> BST<E>::~BST(){
// destructor
}

//Checks if tree contains node with key k.

template <typename E> bool BST<E>::contains(E k){
    E compare;
    if (root !=  NULL) {
            TreeNode<E> *current = root;
            // cout << "printing k: " << k << endl;
            while (current->key != k)
            {
                //compare =  current->key;
                if (compare >= k) {
                     current =  current->right;
                }
                else {
                     current =  current->left;
                }

                if (current ==  NULL) {
                    cout << "end of branch" << endl;
                    return false;
                }
            }
            return true;
        }
    else {
        cout << "empty root" << endl;
        return false;
    }
}

template <typename E> bool BST<E>::containsID(int k){
    E compare;
    if (root !=  NULL) {
            TreeNode<E> *current = root;
            // printing k
            while (current->key.getId() != k)
            {
                //compare =  current->key;
                if (current->key.getId() >= k) {
                     current =  current->left;
                }
                else {
                     current =  current->right;
                }

                if (current ==  NULL) {
                    // print end of branch
                    return false;
                }
            }
            return true;
        }
    else {
        // print tree is empty
        return false;
    }
}

template <typename E> bool BST<E>::printStudentInfo(E v) {
    E compare;
    if (root !=  NULL) {
            TreeNode<E> * current = root;

            while( current->key.getId() != v.getId()) {

                if (current->key.getId() >= v.getId()) {
                     current =  current->left;
                }
                else {
                     current =  current->right;
                }

                if (current ==  NULL) {
                    cout << "Could not find." << endl;
                    return false;
                }
            }
            cout << "Student name: " << current->key.getName() << endl;
            cout << "Student ID: " << current->key.getId() << endl;
            cout << "Student Major: " << current->key.getMajor() << endl;
            cout << "Student Level: " << current->key.getLevel() << endl;
            cout << "Student GPA: " << current->key.getGPA() << endl;
            cout << "Student Advisor ID: " << current->key.getAdvisor() << endl;
            return true;
        }
    else {
        cout << "Could not find." << endl;
        return false;
    }
}

template <typename E> bool BST<E>::printFacultyInfo(E v) {
    E compare;
    if (root !=  NULL) {
            TreeNode<E> * current = root;

            while( current->key.getId() != v.getId()) {
                compare =  current->key;
                if (current->key.getId() >= v.getId()) {
                     current =  current->left;
                }
                else {
                     current =  current->right;
                }

                if (current ==  NULL) {
                    // end of branch
                    cout << "Could not find." << endl;
                    return false;
                }
            }
            cout << "Faculty name: " << current->key.getName() << endl;
            cout << "Faculty ID: " << current->key.getId() << endl;
            cout << "Faculty level: " << current->key.getLevel() << endl;
            cout << "Faculty department: " << current->key.getDept() << endl;
            return true;
        }
    else {
        cout << "Could not find." << endl;
        return false;
    }
}

template <typename E> E BST<E>::find(E k){
    E compare;
    if (root !=  NULL) {
        TreeNode<E> * current = root;

        while( current->key != k) {
            compare =  current->key;
            if (compare > k) {
                    current =  current->right;
            }
            else {
                    current =  current->left;
            }

            if (compare ==  NULL) {
                // end of branch
                cout << "Could not find." << endl;
                return false;
            }
        }

        return true;
    }
    else {
        return false;
    }
}

//tree node to insert

template <typename E> void BST<E>::insert(E v){
    TreeNode<E> *node = new TreeNode<E>(v);
    if (root != NULL)
    { // not empty
        TreeNode<E> * current = root;
        TreeNode<E> *parent =  NULL;

        while(true){
            parent =  current;

            if (node->key >=  current->key) {
                // goes right
                 current =  current->right;
                if ( current !=  NULL) {
                    // continue
                }
                else {
                    parent->right = node;
                    break;
                }
            }
            else {
                // goes left
                 current =  current->left;
                if ( current !=  NULL) {
                    // continue
                }
                else {
                    parent->left = node;
                    break;
                }
            }
        }
    }
    else
    {
        root = node;
    }
}


//elete a node from tree

template <typename E> bool BST<E>::remove(int k){
    if (root ==  NULL){
        cout << "Nothing to delete." << endl;
        return false;
    }
    else {
        TreeNode<E> * current = root;
        TreeNode<E> *parent =  NULL;
        bool isLeftNode = true;
        bool isRightNode = false;

        while( current->key.getId() != k) {
            parent =  current;

            if (current !=  NULL) {
                 if (k >=  current->key.getId()) {
                isLeftNode = false;
                isRightNode = true;
                 current =  current->right;
            }
                else {
                    isLeftNode = true;
                    current = current->left;
                }
            }
            else {
                return false;
            }
        }



        if(current->right ==  NULL && current->left !=  NULL)
        {
            if(current != root)
            {
                if(!isLeftNode)
                {
                    parent->right = current->left;
                }
                else
                {
                    parent->left = current->left;
                }
            }
            else {
                root = current->left;
            }

        }

        else if(current->left ==  NULL && current->right !=  NULL)
        {
            if(current != root)
            {
                if(!isLeftNode)
                {
                    parent->right = current->right;
                }
                else
                {
                    parent->left = current->right;
                }
            }
            else {
                root = current->right;
            }
        }
        else if(current->left ==  NULL && current->right ==  NULL)
        {
            if(current != root)
            {
                if(!isLeftNode)
                {
                    parent->right =  NULL;
                }
                else
                {
                    parent->left =  NULL;

                }
            }
            else {
                root =  NULL;
            }

        }

        else {
            // node to delete has 2 children
            TreeNode<E> *successor = getSuccessor(current);
            if(current != root)
            {
                if(isLeftNode)
                {
                    parent->left = successor;
                }
                else
                {
                    parent->right = successor;
                }
            }
            else {
                root = successor;
            }

            successor->left = current->left;

        }
        return true;
    }
}

// get successor

template <typename E> TreeNode<E>* BST<E>::getSuccessor(TreeNode<E>* d){
    TreeNode<E> *sp = d;
    TreeNode<E> *current = d->right;
    TreeNode<E> *successor = d;

    while (current !=  NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }

    if (successor == d->right){
        //return successor;
    }
    else {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

//Find a trees smallest key node.

template <typename E> E BST<E>::getMin(){
    TreeNode<E> *current = root; //we start at the root

    if(root !=  NULL)
    {
        while(current->left !=  NULL)
        {
            current = current->left;
        }

        return current->key;
    }
    else {
        return  NULL;
    }
}


//find a trees largest key node
@return largest key node
*/
template <typename E> E BST<E>::getMax(){
    TreeNode<E> *current = root; //we start at the root

    if(root !=  NULL)
    {
        while(current->right !=  NULL)
        {
            current = current->right;
        }

        return current->key;
    }
    else {
        return  NULL;
    }
}

//node to begin traversal

template <typename E> void BST<E>::inOrder(bool student, TreeNode<E> *node){
    if (student) {
        if (node !=  NULL) {
            studentInOrder(node->left);
            studentInOrder(node->right);
        }
        else {
            return;
        }
    } else {
        if (node!=NULL){
            facultyInOrder(node->left);
            facultyInOrder(node->right);
        }
        else {
            return;
        }
    }

}
template <typename E> void BST<E>::studentInOrder(TreeNode<E> *node) {
    if (node != NULL) {
        studentInOrder(node->left);
        cout << "______________________________" << endl;
//cout << endl;
        cout << node->key.getName() << endl;
        cout << node->key.getId() << endl;
        cout << node->key.getMajor() << endl;
        cout << node->key.getAdvisor() << endl;
        cout << node->key.getLevel() << endl;
        cout << node->key.getGPA() << endl;
        studentInOrder(node->right);
    }
    else {
        return;
    }
}

template <typename E> void BST<E>::facultyInOrder(TreeNode<E> *node) {
    if (node != NULL) {
        facultyInOrder(node->left);
        cout << "______________________________" << endl;
        cout << endl;
        cout << node->key.getName() << endl;
        cout << node->key.getId() << endl;
        cout << node->key.getLevel() << endl;
        cout << node->key.getDept() << endl;
        facultyInOrder(node->right);

    }
    else {
        return;
    }
}

//print tree Caller for in order.

template <typename E> void BST<E>::printTree(){
}

// get root of tree.

template <typename E> TreeNode<E>* BST<E>::getRoot(){
    TreeNode<E> *node = this->root;
    return node;
}

//length size of tree.

template <typename E> int BST<E>::length(){
}

//is empty if size is 0 or not.

template <typename E> bool BST<E>::isEmpty(){
    if(root != NULL)
    {
        return false;
    }
    return true;
}

#endif
