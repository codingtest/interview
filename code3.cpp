#include <stdio.h>
#include <vector>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//大家肯定碰到过有关二叉搜索树的题（对了，什么是二叉搜索树？），这道题你可能没见过。
//给一个N个节点的二叉搜索树（BST/Binary Search Tree），给一个Key，返回与key最接近的m个节点（m<N）

// Definition for binary tree
typedef struct _TreeNode {
     int val;
     struct _TreeNode *left;
     struct _TreeNode *right;
 }TreeNode;


 vector<TreeNode*> findK(TreeNode* node, int key,  int k)
{
    if ( node == NULL || k == 0 )
        return  vector<TreeNode*>();
    //Stack contains the path to find the closest
    vector<TreeNode*> Stack;
    vector<TreeNode*> res;
    //temp contain the K closest node
    list<TreeNode*> temp;

    int cur = 0;
    int dis = -1;
    TreeNode* close = NULL;
    //find the close
    while(node)
    {
        Stack.push_back(node);
        int v = abs(node->val - key);
        if ( dis == -1 || v < dis)
        {
            dis = v;
            close = node;
        }
        if ( node->val < key )
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
   // res.push_back(close);
    temp.push_back(close);

    Stack.pop_back();

    while( !Stack.empty() )
    {
        TreeNode* cur = Stack.back();
        Stack.pop_back();
        if ( cur->val < key )
        {
           
            //add root
            {
                int insert_success = false;
                    for ( list<TreeNode*>::iterator it = temp.begin(); it!=  temp.end(); it++ )
                    {
                        if ( abs((*it)->val - key)> abs(cur->val - key) )
                        {
                             insert_success = true;
                            temp.insert(it, cur);
                             if (temp.size() > k)
                                  temp.pop_back();
                            break;
                        }
                    }
                    if ( insert_success == false)
                    {
                        if ( temp.size() < k )
                        {
                            temp.push_back(cur);
                        }
                        else
                            continue;
                    }
            }
           // stack.push_back(tree);
             //check the left
            TreeNode* root = cur->left;
            vector<TreeNode*> s;
            while(!s.empty() || root != NULL)
            {
                if ( root != NULL )
                {
                    s.push_back(root);
                    
                    root = root->right;
                }
                else
                {
                    root = s.back();
                    //add root
                    int insert_success = false;
                    for ( list<TreeNode*>::iterator it = temp.begin(); it!=  temp.end(); it++ )
                    {
                        if ( abs((*it)->val - key)> abs(root->val - key) )
                        {
                            insert_success = true;
                            temp.insert(it, cur);
                             if (temp.size() > k)
                                  temp.pop_back();
                            break;
                        }
                    }
                    if ( insert_success == false)
                    {
                        if ( temp.size() < k )
                        {
                            temp.push_back(root);
                        }
                        else
                            break;
                    }
                    s.pop_back();
                    root = root->left;
                }
            }
        }
        else
        {
             //check the right;
             //add root
            {
                int insert_success = false;
                    for ( list<TreeNode*>::iterator it = temp.begin(); it!=  temp.end(); it++ )
                    {
                        if ( abs((*it)->val - key)> abs(cur->val - key) )
                        {
                            insert_success = true;
                            temp.insert(it, cur);
                             if (temp.size() > k)
                                  temp.pop_back();
                            break;
                        }
                    }
                    if ( insert_success == false)
                    {
                        if ( temp.size() < k )
                        {
                            temp.push_back(cur);
                        }
                        else
                            continue;
                    }
            }
            TreeNode* root = cur->right;
            vector<TreeNode*> s;
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
                    //add root
                    int insert_success = false;
                    for ( list<TreeNode*>::iterator it = temp.begin(); it!=  temp.end(); it++ )
                    {
                        if ( abs((*it)->val - key)> abs(root->val - key) )
                        {
                             insert_success = true;
                            temp.insert(it, cur);
                             if (temp.size() > k)
                                  temp.pop_back();
                            break;
                        }
                    }
                    if ( insert_success == false)
                    {
                        if ( temp.size() < k )
                        {
                            temp.push_back(root);
                        }
                        else
                            break;
                    }
                        
                    s.pop_back();
                    root = root->right;
                }
            }
        }
    }

    for ( list<TreeNode*>::iterator it = temp.begin(); it!=  temp.end(); it++ )
    {
        res.push_back((*it));
    }
    return res;
}

int main()
{
    TreeNode* root = new TreeNode();
    if ( root == NULL )
        return -1;
    root->val = 50;
    
     TreeNode* n1 = new TreeNode();
    if ( n1 == NULL )
        return -1;
    n1->val = 17;
    root->left = n1;

    TreeNode* n2 = new TreeNode();
    if ( n2 == NULL )
        return -1;
    n2->val = 76;
    root->right = n2;

    TreeNode* n3 = new TreeNode();
    if ( n3 == NULL )
        return -1;
    n3->val = 23;
    n1->right = n3;
    n3->right = NULL;

    TreeNode* n4 = new TreeNode();
    if ( n4 == NULL )
        return -1;
    n4->val = 9;
    n1->left = n4;
    n4->left = NULL;

    TreeNode* n5 = new TreeNode();
    if ( n5 == NULL )
        return -1;
    n5->val = 14;
    n4->right = n5;
    n5->right = NULL;

    TreeNode* n6 = new TreeNode();
    if ( n6 == NULL )
        return -1;
    n6->val = 12;
    n5->left = n6;
    n6->right = NULL;
    n6->left = NULL;

    TreeNode* n7 = new TreeNode();
    if ( n7 == NULL )
        return -1;
    n7->val = 19;
    n3->left = n7;
    n7->right = NULL;
    n7->left = NULL;



     vector<TreeNode*> res = findK(root,20, 4);
    return 0;
}
