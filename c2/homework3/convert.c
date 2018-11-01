#include<stdio.h>
#include<string.h>
#include<malloc.h>

#define IS_NUM(x) ((x) >= '0' && (x) <= '9')        //判断x是否为整数，使用宏定义比较简洁
#define LENGTH 1024
#define N 50

char s[LENGTH], buffer[N][LENGTH];          //s存放原始字符串；buffer为二维数组，分别存储原始字符串切分出来的token
int size;

typedef struct node{                        //建立数的节点
    char token[LENGTH];                     //token：数字或运算符
    struct node *lchild, *rchild;
}Node;

Node* new_node(char *a, Node *l, Node *r)   //新建一个节点
{
    Node *root = (Node *)malloc(sizeof(Node));
    memset(root, '0', sizeof(Node));        //将malloc申请的空间初始化
    strcpy(root -> token, a);
    root -> lchild = l;
    root -> rchild = r;
    return root;
}

//free the node：程序的最后不要忘了free掉malloc申请的空间
//我懒，就不写free了=.=

Node* build()                               //建立一棵树
{
    int p = --size;                         //由于输入是后缀表达式，所以要倒着构建树，即最后一个字符其实是树的根节点
    if(IS_NUM(buffer[size][0])){            //数字是叶结点
        return new_node(buffer[p], NULL, NULL);
    }
    else{                                   //运算符是非叶结点
        return new_node(buffer[p], build(), build());
    }
}

int level(char *a)                          //为不同的token赋予不同的优先级
{
    switch(a[0]){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void mid_traverse(Node *root);              //中序遍历一棵树
void mid_traverse_with_bracket(Node *root, int flag)    //后缀转中缀，所以中序遍历的同时判断是否加括号
{
    if(flag){
        putchar('(');
    }
    mid_traverse(root);
    if(flag){
        putchar(')');
    }
}

void mid_traverse(Node *root)
{
    if(root -> lchild == NULL && root -> rchild == NULL){   //如果是叶结点，直接输出
        printf("%s", root->token);
    }else{                                                  //如果不是叶结点（即：是运算符），则对是否加括号进行判断
        /*判断是否加括号的条件：
         * 1.无论左右子树，只要子树操作符的优先级小于父节点运算符优先级，则子树要加括号；
         * 2.仅对左子树，如果左子树的优先级等于父节点运算符优先级，则肯定先算子树，所以无需加括号；
         * 3.仅对右子树，如果右子树的优先级等于父节点运算符优先级，则如果父节点的运算符是'-'或'/'，右子树需要加括号；
         * 4.无论左右子树，只要子树的优先级大于副节点的运算符的优先级，无需加括号。
         * 
         * 所以加括号的情况有1和3两种。
         */

        //判断左子树
        mid_traverse_with_bracket(root -> lchild, level(root->token) == 2 && level(root->lchild->token) == 1);  //情况1
        printf("%s", root->token);
        //判断右子树
        mid_traverse_with_bracket(root -> rchild,
                                  level(root->token) != 0 && level(root->rchild->token) != 0 &&
                                  (level(root->token) > level(root->rchild->token)              //情况1
                                   ||
                                   (level(root->token) == level(root->rchild->token)            //情况3
                                    && (root->token[0] == '-' || root->token[0] == '/'))) );
    }
}

void read()                                 //读取字符串，并使用sscanf切分进二维数组
{
    int offset;                             //相对于s其实位置的偏移量
    char *p = s;
    gets(s);                                //读取原始字符串

    while(sscanf(p, "%s%n", buffer[size], &offset) != EOF && buffer[size][0] != '\n'){
        size++;
        p += offset;
    }
}

int main()
{
    Node *root = NULL;
    read();
    root = build();
    mid_traverse(root);
    putchar('\n');
    return 0;
}

