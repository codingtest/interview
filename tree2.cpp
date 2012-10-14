#include <vector> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <queue> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <string> 
#include <cassert> 

using namespace std; 

typedef struct _node
{
    struct _node* left;
     struct _node* right;
     int value;

}Node;

Node* BuildBST(int* input, int num)
{
    if ( num == 0 ) 
        return NULL;
     Node* root = new Node();
    if ( root == NULL )
        return NULL;
    memset(root, 0, sizeof(Node));
    if ( num == 1 )
    {
        root->value = input[0];
        return root;
    }

    int rootVal = input[num/2 - 1];
    int mid = num/2;
    root->value = rootVal;
    root->left = BuildBST(input, mid - 1);
    root->right = BuildBST(input + mid, num - mid );
    return root;
}

void midorder(Node* tree)
{
    if ( tree == NULL )
        return ;

    if ( tree->left != NULL )
        midorder(tree->left);
    printf("%d", tree->value);
    if ( tree->right != NULL)
        midorder(tree->right);
}

void midorder2(Node* tree)
{
    if ( tree == NULL )
        return ;
    
    Node* root = tree;
    vector<Node*> s;
   // stack.push_back(tree);
    while(!s.empty() || root != NULL)
    {
        if ( root != NULL )
        {
            s.push_back(root);
            root = root->left;
        }
        else
        {
            root = s.back();
            printf("%d", root->value);
            s.pop_back();
            root = root->right;
        }
    }
}

void postorder(Node* tree)
{
    if ( tree == NULL )
        return ;

    if ( tree->left != NULL )
        postorder(tree->left);
    
    if ( tree->right != NULL)
        postorder(tree->right);
    printf("%d", tree->value);
}

void postorder2(Node* tree)
{
    if ( tree == NULL )
        return ;

    stack<Node*> s;
    Node* pre = NULL;
    Node* top = NULL;
    Node* root = tree;
    while ((NULL != root) || !s.empty()) 
    {
        if (NULL != root) 
        { 
            s.push(root); 
            root = root->left; 
        } 
        else
        {
            top = s.top();
            if ( top->right != pre )
            {
                //right is not visit
                root = top->right;
                pre = NULL;
            }
            else
            {
                printf("%d", top->value);
                pre = top;
                s.pop();
            }
        }
    }
}

void preorder(Node* tree)
{
    if ( tree == NULL )
        return ;
    printf("%d", tree->value);

    if ( tree->left != NULL )
        preorder(tree->left);
    
    if ( tree->right != NULL)
        preorder(tree->right);
    
}

void preorder2(Node* tree)
{
    if ( tree == NULL )
        return ;

    vector<Node*> s;
    Node* root = tree;

    while( !s.empty()  || root != NULL)
    {
        if ( root != NULL )
        {
            printf("%d", root->value);
            s.push_back(root);
            root =  root->left;
        }
        else
        {
            root = s.back();
            s.pop_back();
            root = root->right;
        }
    }
}
//
//int depth(Node* tree)
//{
//}

//int main()
//{
//    int input1[13] = {4, 1, 6, 2, 8, 9, 5, 3, 2, 9, 8, 4, 6};
//    sort(input1, input1 + 13, less<int>());
//    Node* root = BuildBST(input1, 13);
//    preorder(root);
//    printf("\n");
//    preorder2(root);
//    return 0;
//}