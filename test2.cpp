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

int trap(int* a, int n)
{
    if ( a == NULL || n == 0 )
        return 0;
    int* left = new int[n];
    if ( left == NULL )
           return 0;
     int* right = new int[n];
    if ( right == NULL )
           return 0;

    int maxL = 0;
    for ( int i = 0 ; i < n-1; i++ )
    {
        left[i] = maxL;
        maxL = max(maxL, a[i]);
    }

    int maxR = 0;
    for ( int i = n-1; i >= 0; i-- )
    {
        right[i] = maxR;
        maxR = max(maxR, a[i]);
    }

    int res = 0;
    for ( int i = 0 ; i < n-1 ;i++)
    {
        int v = min(left[i], right[i]) - a[i];
        if ( v > 0 )
            res += v;
    }
    delete[] left;
    delete[] right;
    return res;
}

//// Definition for binary tree
//typedef struct _TreeNode {
//     int val;
//     struct _TreeNode *left;
//     struct _TreeNode *right;
// }TreeNode;
//
//bool same(TreeNode* p , TreeNode* q)
//{
//    if (p== NULL && q == NULL )
//        return true;
//    if ( p == NULL || q == NULL )
//        return false;
//            
//    if ( p->val != q->val)
//        return false;
//    if ( same(p->left, q->left) == false )
//        return false;
//    if ( same(p->right, q->right) == false )
//        return false;
//    return true;
//}
//bool isSameTree(TreeNode *p, TreeNode *q) {
//    // Start typing your C/C++ solution below
//    // DO NOT write int main() function
//    if ( p == NULL && q == NULL )
//        return true;
//            
//    if ( p == NULL || q == NULL )
//        return false;
//    return same(p, q);
//}
//
//int sum(int a, int  b )
//{
//    if (  b == 0 )
//        return a;
//
//    int c = a ^ b;
//    int d = (a&b) << 1;
//    return sum(c,d);
//}

// Definition for binary tree
typedef struct _TreeNode {
     int val;
     struct _TreeNode *left;
     struct _TreeNode *right;
 }TreeNode;


 vector<TreeNode*> findK(TreeNode* node, int key,  int k)
{
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

int count(int n )
{
    if ( n <= 0 )
        return 0;
    if ( n == 1 )
        return 1;
    if ( n == 2 ) 
        return 2;

	int* temp = new int[n];
	if ( temp == NULL )
		return 0;
	
	temp[0] = 1;
	temp[1] = 2;
	for ( int i = 2; i < n ; i++)
	{
		temp[i] = 0;
		for ( int j = 0; j <= i; j++)
		{
			if ( j == 0 || j == i)
				temp[i] += temp[i-1];
			else
				temp[i] += temp[j-1] * temp[i-j - 1];
		}
	}


	int res = temp[n-1];
	delete[] temp;
	return res;
}

TreeNode* copyTree(TreeNode* src)
{
    if ( src == NULL )
        return NULL;
    TreeNode* node = new TreeNode();
        if ( node == NULL )
            return NULL;

        node->val = src->val;
        node->left = copyTree(src->left);
        node->right = copyTree(src->right);
        return node;

}

list<TreeNode*> res;
int g_n;
TreeNode* buildBSThelp(int n, int start, int end, TreeNode* root, vector<TreeNode*> &s)
{
   
    if ( n == 0)
    {
        if ( start >= g_n) 
        {
             for ( int i = 0 ; i < s.size()-1; i++)
            {
                s[i]->right = s[i+1];
            }
            s[s.size()-1]->right = NULL;
            res.push_back(copyTree(root));
            return NULL;
        }
        else
            return NULL;
    }

     TreeNode* node = new TreeNode();
        if ( node == NULL )
            return NULL;

    if ( n == 1 )
    {
        node->left = NULL;
        node->right = NULL;
        node->val =  start;
        if ( start == g_n )
        {
            for ( int i = 0 ; i < s.size()-1; i++)
            {
                s[i]->right = s[i+1];
            }
            s[s.size()-1]->right = node;
            res.push_back(copyTree(root));
            //return node;
        }

        return node;
    }

     

    for  ( int i = start; i <= end; i++ )
    {

        node->val = i;
        node->right = NULL;
        node->left = buildBSThelp( i-start, start, i-1, root,s);
                s.push_back(node);
        node->right = buildBSThelp(end-i, i+1, end,root,s);
        s.pop_back();
    /*    if ( f == 1)
            res.push_back(copyTree(root));*/
    }
    return node;
}
list<TreeNode*> buildBST(int n )
{
    
    if ( n <= 0 )
        return res;

    g_n = n;
    //buildBSThelp(n,1, n,0);
    TreeNode* node = new TreeNode();
        if ( node == NULL )
            return res;
    
    vector<TreeNode*> s;
    for ( int i = 1; i <=n ;i++)
    {
          if ( i == n)
            g_n = n-1;
        node->val = i;
        node->right = NULL;
        node->left = buildBSThelp(i-1,1, i-1, node,s);
          s.push_back(node);
        node->right  = buildBSThelp(n-i,i+1,n, node, s);
        s.pop_back();
        //if ( f == 1)
        //    res.push_back(copyTree(node));
        //res.push_back(node);
    }
    return res;
}
int main()
{

    list<TreeNode*> res22 = buildBST(3);
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

