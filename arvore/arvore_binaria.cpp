#include <iostream>
using namespace std;
/*
Run
https://code.visualstudio.com/docs/cpp/config-clang-mac
*/

class No
{
    private:
        No *left, *right;
        int key;

    public:
        No(int key)
        {
            this->key =  key;
            left = NULL;
            right = NULL;
        }
        int getKey() 
        {
            return key;
        }
        No* getLeft()
        {
            return left;
        }
        No* getRight()
        {
            return right;
        }
        void setLeft(No* no)
        {
            left = no;
        }
        void setRight(No* no)
        {
            right = no;
        }
};

class Tree
{
    private:
        No* root;
    public:
        Tree()
        {
            root = NULL;
        }
        void insert(int key)
        {
            if (root == NULL)
            {
                root = new No(key);
            }
            else
            {
                insertBranch(root, key);
            } 
        }
        void insertBranch(No* no, int key)
        {
            if (key < no->getKey())
            {
                if (no->getLeft() == NULL)
                {
                    No* new_no = new No(key);
                    no->setLeft(new_no);
                }
                else
                {
                    insertBranch(no->getLeft(), key);
                }
                
            }
            if (key > no->getKey())
            {
                if (no->getRight() == NULL)
                {
                    No* new_no = new No(key);
                    no->setRight(new_no);
                }
                else
                {
                    insertBranch(no->getRight(), key);
                }
                
            }
        }
        No* getRoot()
        {
            return root;
        }
        void printInOrder(No* no)
        {
            if (no != NULL)
            {
                printInOrder(no->getLeft());
                cout << no->getKey() << " ";
                printInOrder(no->getRight());
            }
        }
};

int main(int argc, char const *argv[])
{
    Tree tree;
    tree.insert(8);
    tree.insert(10);
    tree.insert(14);
    tree.insert(13);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(4);
    tree.insert(7);

    tree.printInOrder(tree.getRoot());
    return 0;
}
