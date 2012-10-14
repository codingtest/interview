#include <vector>
#include <deque>

using namespace std;

typedef struct _node
{
	int value;
	struct _node* left;
	struct _node* right;
	
}Node;

Node* BuildTree(int* array, int num)
{
    if ( array == NULL || num == 0 )
         return NULL;

	deque<Node*> temp;
	Node* new_node = new Node();
	memset(new_node, 0 , sizeof(Node));
	new_node->value = array[0];
	Node* tree = new_node;
	temp.push_back(new_node);
	for ( int i = 1; i < num;)
	{
		Node* parent = temp.front();
		temp.pop_front();

		Node* left_node = new Node();
		memset(left_node, 0 , sizeof(Node));
		left_node->value = array[i++];

		parent->left = left_node;
        temp.push_back(left_node);

		if ( i >= num )
			break;

		Node* right_node = new Node();
		memset( right_node, 0 , sizeof(Node));
		right_node->value = array[i++];

		parent->right = right_node;
        temp.push_back(right_node);
	}
	return tree;
}

void Print(vector<int> buffer, int start, int end)
{
	for ( int i =start; i <= end; i++)
	{
		printf("%d ", buffer[i]);
	}
	printf("\n");
}

void findSum(Node* node, int sum, int level, vector<int> buffer)
{
	if ( node == NULL )
		return;
	int data = node->value;
	buffer.push_back(data);
	int ret = 0;
	for (int i = level ; i >= 0 ;i--)
	{
		ret += buffer[i];
		if ( ret == sum )
		{
			Print(buffer, i, level );
			break;
		}
	}
	
	vector<int> temp = buffer;
	findSum(node->left, sum, level+1, temp);
	findSum(node->right, sum, level+1, temp);
	
}


int depth1;
int depth2;
int depth = 0;

int lcs(Node* node, int a , int b , Node** result, Node* parent, int depth)
{
	int right = 0, left = 0;
	if ( node->left ) left = lcs(node->left, a, b, result, node, depth+1);
	if ( node->right ) right = lcs(node->right, a, b, result, node, depth+1);

	int mid = 0;
	if ( node->value == a ){
		mid = 1;
        depth1 = depth;
    } else if ( node->value == b )
    {
        mid = 1;
        depth2 = depth;
    }
	if ( (*result) == NULL && (left + right + mid ) == 2 )
	{
		if ( mid == 1) 
			(*result) = parent;
		else
			*result = node;
	}
	if ( left + right + mid > 0 )
		return 1;
	else
		return 0;
}
Node* find(Node* node, int a , int b )
{
	if ( node == NULL )
		return NULL;
	Node* result = NULL;
	lcs(node, a, b, &result,NULL,1);
	return result;
}

//count the tree's depth
int CountDepth(Node* node)
{
    int max_depth = 0;
    int min_depth = 0;
	if ( node == NULL )
		return 0;
	deque<Node*> a1;
	deque<Node*> a2;
	a1.push_back(node);
	int depth = 0;

	deque<Node*>* cur;
	deque<Node*>* next;
	while( a1.size() != 0 || a2.size() != 0 )
	{
		depth++;
		if( a1.size() != 0 )
		{
			cur = &a1;
			next = &a2;
		} else 
		{
			cur = &a2;
			next = &a1;
		}

		while((*cur).size() != 0 )
		{
			Node* par = (*cur).front();
			(*cur).pop_front();

            if ( par->left == NULL && par->right == NULL )
                 min_depth = min_depth == 0 ? depth: min_depth;
			
			if ( par->left != NULL)
				(*next).push_back(par->left);
			if ( par->right != NULL)
				(*next).push_back(par->right);
		}
	}
    max_depth = depth;
	return depth;
}

//find the max path between two node
int max(int a, int b)
{
	return a>b?a:b;
}

int findMax(Node* tree)
{
	int path = 0;
	while ( tree->left == NULL || tree->right == NULL )
	{
		path++;
		if( tree->left == NULL && tree->right == NULL )
			return path;
		if (tree->left != NULL )
			tree = tree->left;
		if ( tree->right != NULL )
			tree = tree->right;
	}
	int left_depth = CountDepth(tree->left);
	int right_depth = CountDepth(tree->right);

	int max_depth;
	max_depth = max(left_depth + path - 1, left_depth + right_depth);
	max_depth = max(right_depth + path - 1, max_depth);
	return max_depth;
}

Node* buildBST(int* array, int num)
{
	if ( num == 0 )
        return NULL;

	if ( num == 1 )
	{
		Node* node = new Node();
		memset(node, 0 ,sizeof(Node));
		node->value = array[0];
		return node;
	}
	
	int mid = num / 2;
	Node* node = new Node();
	memset(node, 0 ,sizeof(Node));
	node->value = array[mid - 1];
	node->left = buildBST(array, mid - 1);
	node->right = buildBST(array + mid, num - mid );

    return node;

}

/****************************************************************************
题目要求 ：一棵排序二叉树，令 f=(最大值+最小值)/2，设计一个算法，找出距离f值最近、大于f值的结点。 
复杂度如果是O(n2)则不得分。 

用C描述的算法，注释略
****************************************************************************/

Node* FindClose(Node* tree, int N)
{
	Node* temp = tree;
	while (temp)
	{
		if ( temp->value > N )
		{
            if ( temp->left == NULL)
                break;
			if ( temp->left->value <= N && temp->left->right == NULL)
				break;
			temp = temp->left;
		}
		else
		{
            if ( NULL == (temp = temp->right) || temp->value > N )
                    break;
		/*	if (  && temp->right->left == NULL){
                temp = temp->right;
				break;
            }*/
			temp = temp->right;
		}
	}
	return temp;
}


bool Same(int* a, int* b, int start, int M)
{
	int temp[10];
	memset(temp,0,sizeof(temp));
	for ( int i = 0 ; i < M ;i++)
	{
		temp[b[i]]++;
	}
	for ( int i = start ; i < start + M ;i++)
	{
		temp[a[i]]--;
	}
	for ( int i = 0 ; i < M ;i++)
	{
		if ( temp[i] != 0 )
			return false;
	}
	return true;
}

int FindSame(int* a, int N, int* b , int M)
{
	int sum1 = 0;
	int sum2 = 0;
	for ( int i = 0 ; i < M ;i++)
	{
		sum1 += b[i];
		sum2 += a[i];
	}

	for ( int i = M ; i < N; i++)
	{
		if ( sum1 == sum2 && Same(a, b, i - M, M) )
			return i - M;
		sum2 = sum2 - a[i - M] + a[i];
	}
	return 0;
}

//输入一颗二元查找树，将该树转换为它的镜像，即在转换后的二元查找树中，
//左子树的结点都大于右子树的结点。用递归和循环两种方法完成树的镜像转换。
void Mirror(Node* node)
{
	if (node == NULL )
		return;
	
	Node* temp = node->left;
	node->left = node->right;
	node->right = temp;

	if ( node->left )
		Mirror(node->left);
	if ( node->right)
		Mirror(node->right);
    return;
}

void Mirror2(Node* node)
{
	if (node == NULL )
		return;

	vector<Node*> stack;
	stack.push_back(node);
	while(stack.size() != 0 )
	{
		Node* n = stack.back();
		stack.pop_back();
		Node* temp = n->left;
		n->left = n->right;
		n->right = temp;
		
		if ( n->left )
			stack.push_back(n->left);
		if ( n->right)
			stack.push_back(n->right);
	}
	return;
}

//Node* change(Node* node)
//{
//        
//}

//输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。如果是返回true，否则返回false。
bool verifyBST(int* a, int length)
{
	if ( a == NULL || length <= 0 )
		return false;
	
	int root = a[length-1];
	
	int i;
	for ( i = 0; i < length; i++)
	{
		if ( a[i] >= root)
			break;
	}

	for(int j = i; j< length;j++)
	{
		if ( a[j] < root )
			return false;
	}
	bool left = true;
	if ( i >  0 )
		left = verifyBST(a, i);
	bool right = true;
	if ( i < length - 1)
		right = verifyBST(a + i, length - i - 1);

	return left && right;
	
}

void DeleteNode(Node** tree, int value)
{
        if ( tree == NULL )
                return ;

        //find node
        Node* parent = NULL;
         Node* node = *tree;
        while ( node != NULL )
        {
            if  ( node->value == value )
                break;
            parent = node;
            if ( node->value > value )
                node = node->left;
            else
                node  = node->right;
            
        }

        if ( node == NULL )
            return;
        
        if ( node->left != NULL && node->right != NULL )
        {
            Node* temp = node->right;
            while ( temp->left )
            {
                temp = temp->left;
            }
            if( temp->left == NULL )
                temp->left = node->left;
            else {
                temp->left->left = node->left;
                temp->left->right = node->right;
                temp->left = NULL;
            }
        }else
        {
              if ( parent == NULL){
                  if (node->left )
                    *tree = node->left;
                  else if ( node->right)
                  *tree - node->right;
                  else
                      *tree = NULL;
              } else {
                   if ( node->left ){
                       node->value = node->left->value;
                    //   node->value = node->left->
                   }
                   else
                       node = node->right;
              }
        }


}

//	joshf环
int LastRemain(int n , int m)
{
	if ( n <= 0 || m <= 0 )
		return -1;

	int last = 0;
	for ( int i = 2; i <= n; i++ )
		last = (last + m) % i;

	return last;
}

//Given a string s and an array of smaller strings T, design a method to search s for each small string in T.
typedef struct _Mtree
{
	char ch;
	vector<struct _Mtree*> childnode;
}Mtree;

Mtree* buildTree(char* str)
{
	if ( str == NULL )
		return NULL;

	char* temp = str;
	Mtree* root = new Mtree();
	if ( root == NULL )
		return NULL;
	root->ch = '\0';
	Mtree* cur = NULL;
	while( *temp != '\0')
	{
		cur = root;
		for ( int index = 0 ; index  < strlen(temp); index ++ )
		{
			
			int i = 0;
			int find = false;
			for ( ; i < cur->childnode.size(); i++ )
			{
				if ( cur->childnode[i]->ch == temp[index] )
				{
					find = true;
					break;
				}
			}
			if ( find )
				cur = cur->childnode[i];
			else {
				Mtree* node = new Mtree();
				if ( node == NULL )
					return NULL;
				node->ch = temp[index];
                cur->childnode.push_back(node);
                cur = node;
			}
		}
        temp++;
	}
	return root;
}

bool check(char* input, Mtree* root)
{
        if ( input == NULL || root == NULL )
        {

            return false;
        }

        char* temp = input;
        Mtree* cur = root;
         while (*temp != '\0')
         {
            int find = false;
             for ( int i =0 ; i< cur->childnode.size(); i++ )
             {
                 if ( cur->childnode[i]->ch == temp[0] ){
                     find = true;
                     cur = cur->childnode[i];
                     break;
                 }
             }
             if ( find == false )
                   return false;
              temp++;
         }
         return true;
}

//print all  摆列
void swap(char *str1,char *str2)
{
    char temp;
    temp=*str1;
    *str1=*str2;
    *str2=temp;
}

void permStr(char *str,int i)
{
    //printf("%d",i);
    if(i==strlen(str)-1)
        printf("%s\n",str);    
    else        
    {        
        for(int j=i;j<strlen(str);j++)            
        {
            //printf("i %d,j %d",i,j);
            swap(&str[i],&str[j]);
            permStr(str,i+1);
            swap(&str[i],&str[j]);
        }
    }
}

//str1, str2里连续公共子串
char* findSame(char* str1, char* str2)
{
	if ( str1 == NULL || str2 == NULL )
		return NULL;

	int maxlength = 0;
	char* start = NULL;


	for ( int i = 0; i < strlen(str2) ; i++ )
	{
		char* start1 = str1;
		char* start2 = str2 + strlen(str2) - i - 1;
		int length = 0;
		char* temp = NULL;
		while( *start1 != '\0' && *start2 != '\0')
		{
			if ( *start1 == *start2 )
			{
				if ( temp == NULL )
					temp = start1;
				length++;
			
			}
			else 
			{
				if ( maxlength < length )
				{
					maxlength = length;
					start = temp;
				}
				temp = NULL;
                 length = 0;
			}
            if ( maxlength < length )
				{
					maxlength = length;
					start = temp;
				}
            start1++;
             start2++;
		}	

	}

	for ( int i = 1; i < strlen(str1) ; i++ )
	{
		char* start1 = str1 + i;
		char* start2 = str2;
		int length = 0;
		char* temp = NULL;
		while( *start1 != '\0' && *start2 != '\0')
		{
			if ( *start1 == *start2 )
			{
				if ( temp == NULL )
					temp = start1;
				length++;
			
			}
			else 
			{
				if ( maxlength < length )
				{
					maxlength = length;
					start = temp;
				}
				temp = NULL;
                length = 0;
			}
            start1++;
             start2++;
		}	
        if ( maxlength < length )
				{
					maxlength = length;
					start = temp;
				}

	}
	char*  result = new char[maxlength + 1];
	if ( result == NULL )
		return NULL;
	memcpy(result, start, maxlength);
	result[maxlength] = '\0';
	return result;
}

//typedef struct _node
//{
//	//struct _node *next;
//	//struct _node *head;
//    struct _node *right;
//    struct _node* left;
//}Node;

void conver(Node* tree, Node** lastNode)
{
	Node* result = NULL;
	if ( tree == NULL )
		return ;
	if ( tree->left != NULL )
		conver(tree->left, lastNode);

    if ( *lastNode != NULL )
    {
        (*lastNode)->right = tree;
        tree->left = (*lastNode);
    }
    else
    {
        tree->left = NULL;
    }
        
	*lastNode = tree;
	if ( tree->right )
		conver(tree->right, lastNode);
}

Node * tranfer(Node* tree)
{
	if ( tree== NULL )
		return NULL;
	Node* lastNode = NULL;
	  conver(tree, &lastNode);

      while( lastNode->left != NULL )
          lastNode = lastNode->left;

      return lastNode;;
}

class CElement
{
public:
	virtual ~CElement() {};
	virtual char* A(){ return "CELEMENT";}
};

class COptionElement sealed: public CElement
{
public:
	virtual ~COptionElement() {};
	virtual char* A(){ return "COPTIONELEMENT";}
};

int main()
{
         COptionElement* ce = new COptionElement();
    char* result = ce->A();
  //  return 0;

     int input[10] = {1,2,4,5,6,7,9,10};

     int* a = new int[10];
     int length = sizeof(input);

      Node* tree = buildBST(input, 8);
      Node* link  = tranfer(tree);
     //   char* result = findSame("abcdefg", "abdefg");

    //char str[]={"abcde"};

    //permStr(str,0);

    //int result = LastRemain(10,4);
    //Mtree* result = buildTree("bibs");
    //bool ret = check("ibc", result );
    /*int input1[13] = {4, 1, 6, 2, 8, 9, 5, 3, 2, 9, 8, 4, 6};
    int input2[5] = {5, 6, 2, 9, 8};*/
    //int result = FindSame(input1, 13, input2, 5);
   /* int input[10] = {1,2,4,5,6,7,9,10};
    Node* tree = buildBST(input, 8);
    DeleteNode(&tree,2);*/
    //Node* close = FindClose(tree, 6);
    //findSum(tree, 11,0,vector<int>());
    //Node* parent = find(tree, 8,7);
  // int max_depth = CountDepth(tree);
    return 0;
}