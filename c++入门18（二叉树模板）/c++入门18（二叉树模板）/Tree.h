#ifndef TREE_H
#define TREE_H 
#include <iostream>
#include<iomanip>
using namespace std;

template<typename T>
 struct Node            //树结点
{
  T data;
  Node<T> *left, *right;
  Node(const T& item);
 }; 

template<typename T>
 Node<T>::Node(const T& item)   //树结点初始化
{
  data = item;
  left = NULL;
  right = NULL;
 } 

template<typename T>          //队列结点
struct QNode
 {
  Node<T>* pdata;
  QNode<T>* next;
  QNode( Node<T>* &pd,  QNode* tp);
 }; 

template<typename T>           //队列结点初始化
QNode<T>::QNode( Node<T>* &pd,  QNode* tp)   
 {
  pdata = pd;
  next = tp;
 } 

template<typename T>            //放删除元素的队列结点
struct DQNode
 {
  T d_data;
  DQNode<T>* dnext;
  DQNode(const T& ditem, DQNode<T>* dp);
 }; 

template<typename T>                                 //放删除元素的队列结点初始化
DQNode<T>::DQNode(const T& ditem, DQNode<T>* dp)
 {
  d_data = ditem;
  dnext = dp;
 } 

template<typename T>           //二叉树类
class Tree
 {
 private:
  Node<T>* root;
  QNode<T>* head, *tail;
  DQNode<T>*dhead, *dtail;
  int size;//记录二叉树结点长度
 int qsize;//记录队列长度
 int dsize;//记录DQNode队列长度
public:
  Tree();
  ~Tree();
  void Operate();
 private:
  Node<T>* Creat(Node<T>* &rt);
  void Destory(Node<T>* t);
  void Del(Node<T>* t);
  void FiRoTra(Node<T>* rt ,int& ct);
  void MiRoTra(Node<T>* rt, int& ct);
  void LaRoTra(Node<T>* rt, int& ct);
  void LeveTra(Node<T>* rt, int& ct);
  void Addq( Node<T>* &pt);
  Node<T>* Outq();
  void AddDq(const T& tdata);
  void Delq();
  void Deld();
  void ShowAll(QNode<T>* header);
  void D_ShowAll(DQNode<T>* dheader);
  Node<T>* GetFather(Node<T>* t, Node<T>* p);
  void Search(Node<T>* t, const T& item, bool& sign);
 }; 

template<typename T>           //类构造函数
Tree<T>::Tree()
 {
  root = NULL;
  head = NULL;
  tail = NULL;
  dhead = NULL;
  dtail = NULL;
  size = 0;
  qsize = 0;
  dsize = 0;
 } 

template<typename T>          //类析构函数
Tree<T>::~Tree()
 {
  Destory(root);
 } 

template<typename T>          //入队一个元素
void Tree<T>::Addq( Node<T>* &pnode)
 {
  if (!head){ head = tail = new QNode<T>(pnode,NULL); qsize = 1; }
  else
  {
   tail->next = new QNode<T>(pnode, NULL);
   tail = tail->next;
   qsize++;
  }
 } 

template<typename T>          //出队一个元素
Node<T>* Tree<T>::Outq()
 {
  Node<T>* p;
  QNode<T>* item;
  p = head->pdata;
  item = head;
  head = head->next;
  delete item;
  qsize--;
  return p;
 } 

template<typename T>            //DQNode入队一个元素
void Tree<T>:: AddDq(const T& tdata)
 {
  if (!dhead){ dhead = dtail = new DQNode<T>(tdata, NULL); dsize = 1; }
  else
  {
   dtail->dnext = new DQNode<T>(tdata, NULL);
   dtail = dtail->dnext;
   dsize++;
  }
 } 

template<typename T>           //清空队列
void Tree<T>::Delq()
 {
   while (head)
  {
   QNode<T>* temp;
   temp = head; head = head->next; delete temp;
  }
 } 

template<typename T>           //清空DQNode队列
void Tree<T>::Deld()
 {
   while (dhead)
  {
   DQNode<T>* dtemp;
   dtemp = dhead; dhead = dhead->dnext; delete dtemp;
  }
 } 

template<typename T>               //输出队列内全部元素
void Tree<T>::ShowAll(QNode<T>* header)
 {
  QNode<T>* p = header;
  for (int i = 1; i <= qsize;i++)
  {
   cout << p->pdata << "  ";
   if (i % 5 == 0 )cout << endl;
   p = p->next;
  }
  cout << endl;
 } 

template<typename T>               //输出DQNode队列内全部元素
void Tree<T>::D_ShowAll(DQNode<T>* dheader)
 {
  DQNode<T>* dp = dheader;
  for (int i = 1; i <= dsize; i++)
  {
   cout << setiosflags(ios::left);
   cout<<setw(10) << dp->d_data;
   if (i % 5 == 0 )cout << endl;
   dp = dp->dnext;
  }
  cout << endl;
 } 

template<typename T>                         //得到某结点（以地址为关键值）的父结点的地址
Node<T>* Tree<T>::GetFather(Node<T>* t, Node<T>* p)
 {
  Node<T>* q;
  if (t == NULL)return NULL;
  if (t->left == p || t->right == p)return t;
  q = GetFather(t->left, p);
  if (q!= NULL)return q;
  else return GetFather(t->right, p);
 } 

template<typename T>             //在树中删除以某结点为根的树
void Tree<T>::Del(Node<T>* t)
 {
  if (t != NULL)
  {
   Del(t->left);
   Del(t->right);
   AddDq(t->data);
   delete t;
   size--;
  }
 } 

template<typename T>           //创建二叉树
Node<T>* Tree<T>::Creat(Node<T>* &rt)
 {
  int choice; bool flag;
  if (size > 0)
  {
   cout << "是否继续创建子树？是请按1，否请按0：" << endl;
    cin >> choice; 
    flag = true;
  }
  if (size == 0)
  {
   cout << "请输入根结点数据;" << endl;
   T data; cin >> data;
   rt = new Node<T>(data);
   if (!rt){ cout << "根结点创建失败！" << endl; return NULL; }
   size++;
      flag = false;
   cout << "根结点创建成功！" << endl;
   cout << "目前树中共有结点" << size << "个。" << endl;
  }
  if (flag)
  {
   if (choice == 0)return 0;
   else
   {
    cout << "请输入子结点数据;" << endl;
    T data; cin >> data;
    rt = new Node<T>(data);
    if (!rt){ cout << "子结点创建失败！" << endl; return NULL; }
    size++;
    cout << "子结点创建成功！" << endl;
    cout << "目前树中共有结点" << size << "个。" << endl;
   }
  }
  Creat(rt->left);
  Creat(rt->right);
  return root;
 } 

template<typename T>              //先根递归遍历 FiRoTra是first root traversal的缩写
void Tree<T>::FiRoTra(Node<T>* rt ,int& ct)
 {
  if (rt)
  {
   cout << setiosflags(ios::left);
   cout<<setw(10) << rt->data;
   ct++; 
   if (ct % 5 == 0)
    cout << endl;
   FiRoTra(rt->left,ct);
   FiRoTra(rt->right,ct);
  }
 } 

template<typename T>              //中根递归遍历 MiRoTra是middle root traversal的缩写
void Tree<T>::MiRoTra(Node<T>* rt, int& ct)
 {
  if (rt)
  {
   MiRoTra(rt->left, ct);
   cout << setiosflags(ios::left);
   cout <<setw(10)<< rt->data ;
   ct++;
   if (ct % 5 == 0)
    cout << endl;
   MiRoTra(rt->right, ct);
  }
 } 

template<typename T>              //后根递归遍历 LaRoTra是last root traversal的缩写
void Tree<T>::LaRoTra(Node<T>* rt, int& ct)
 {
  if (rt)
  {
   LaRoTra(rt->left, ct);
   LaRoTra(rt->right, ct);
   cout << setiosflags(ios::left);
   cout<<setw(10) << rt->data ;
   ct++;
   if (ct % 5 == 0)
    cout << endl; 
  }
 } 

template<typename T>              //层次遍历 LeveTra是level traversal的缩写
void Tree<T>::LeveTra(Node<T>* rt, int& ct)
 {
  Addq(rt);
  Node<T>* lt;
  while (qsize>0)
  {
   lt=Outq();
   ct++;
   cout << setiosflags(ios::left);
   cout <<setw(10)<< lt->data ;
   if (ct % 5 == 0)
    cout << endl;
   if (lt->left != NULL)Addq(lt->left);
   if (lt->right != NULL)Addq(lt->right);
  }
 } 

template<typename T>            //搜索数据域为某值的结点
void Tree<T>::Search(Node<T>* t, const T& item, bool& sign)
 {
  if (t)
  {
   Search(t->left, item, sign);
   Search(t->right, item, sign);
   if (t->data == item){sign = true; Addq(t);}
  }
 } 

template<typename T>           //销毁二叉树
void Tree<T>::Destory(Node<T>* t)
 {
   if (t!=NULL)
  {
   Destory(t->left);
   Destory(t->right);
   delete t;
   size--;
  }
 } 

//封装操作
template <typename T>
 void Tree<T>::Operate()
 {
  bool flager = true;
  while (flager)
  {
   cout << "请您选择操作（输入操作前的数字进行选择）：" << endl;
   cout << "1.创建二叉树并写入数据" << endl;
   cout << "2.先根遍历二叉树" << endl;
   cout << "3.中根遍历二叉树" << endl;
   cout << "4.后根遍历二叉树" << endl;
   cout << "5.层次遍历二叉树" << endl;
   cout << "6.搜索数据域为某值的结点" << endl;
   cout << "7.删除数据域为某值的结点及其子树" << endl;
   cout << "8.判断是否为完全二叉树" << endl;
   cout << "9.销毁二叉树" << endl;
   int choice;
   cin >> choice;
   switch (choice)
   {
   //由用户创建二叉树
  case 1:
   {
       if (root){ cout << "二叉树已经创建，无需再建！若想新建，请您先销毁旧树！" << endl; break; }
       Creat(root);
       cout << "二叉树创建完成！" << endl;
       cout << "此二叉树中共有结点" << size << "个！" << endl;
       break;
   }
   //先根遍历二叉树
  case 2:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行遍历操作，请您先创建二叉树！" << endl; break; }
       int counter2=0;
       FiRoTra(root,counter2);
       cout << endl;
       break;
   }
   //中根遍历二叉树 
   case 3:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行遍历操作，请您先创建二叉树！" << endl; break; }
       int counter3 = 0;
       MiRoTra(root, counter3);
       cout << endl;
       break;
   }
   //后根遍历二叉树
  case 4:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行遍历操作，请您先创建二叉树！" << endl; break; }
       int counter4 = 0;
       LaRoTra(root, counter4);
       cout << endl;
       break;
   }
   //层次遍历二叉树
  case 5:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行遍历操作，请您先创建二叉树！" << endl; break; }
       int counter5 = 0;
       LeveTra(root, counter5);
       cout << endl;
       head = tail = NULL;
       break;
   }
   //搜索数据域为某值的结点 
   case 6:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行搜索操作，请您先创建二叉树！" << endl; break; }
       cout << "请您输入数据域的值;" << endl;
       T indata;  cin >> indata;
       bool flag = false;
       Search(root, indata, flag);
       if (!flag){ cout << "该二叉树中没有数据域为" << indata << "的结点！" << endl; break; }
       else cout << "该二叉树中数据域为" << indata << "的结点共有"<<qsize<<"个。" << endl;
       cout << "是否输出这些结点的地址？是请按1，否则按0：" << endl;
       int choice6; cin >> choice6;
       if (choice6 == 1)    ShowAll(head);
       Delq(); head = tail = NULL; qsize = 0;
       break;
   }
   //删除数据域为某值的结点及其子树
  case 7:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法执行删除操作，请您先创建二叉树！" << endl; break; }
       T data7; bool flag7 = false; bool sign7 = true; int choice7;
       cout << "请您输入结点数据的值：" << endl;
       cin >> data7;
       Search(root, data7, flag7);
       if (!flag7){ cout << "目前二叉树中无数据域为" << data7 << "的结点！" << endl; Delq(); head = tail = NULL; qsize = 0; break; }
       while (sign7)
       {
        Node<T> *p7, *fp7;
        QNode<T> *item7;
        p7 = head->pdata;
        item7 = head; head = head->next; delete item7; qsize--;
        if (p7 == root)
        {
         cout << "数据域为"<<data7<<"的结点为根结点，若执行删除操作将会销毁整棵二叉树！" << endl;
         cout << "是否确定执行删除操作？确定请按1，取消请按0：" << endl;
         cin >> choice7;
         if (choice7 == 0){ Delq(); head = tail = NULL; qsize = 0; goto mark7; }
         else
         {
          Destory(p7); root = NULL; size = 0;
          root = NULL;
          cout << "删除成功！同时整棵二叉树也被销毁！" << endl;
          Delq(); head = tail = NULL; qsize = 0;         
          goto mark7;
         }
        }
        fp7 = GetFather(root, p7);
        if (fp7->left == p7)fp7->left = NULL;
        else fp7->right = NULL;
        Del(p7);
        cout << "删除成功！" << endl;
        if (qsize == 0){ cout << "此时树中已无数据域为" << data7 << "的结点及其子树！" << endl; sign7 = false; }
        if (qsize > 0){ cout << "但此时树中数据域为" << data7 << "的结点还有" <<qsize<<"个！"<< endl; }
        cout << "此次共删除结点" << dsize << "个，" << "目前树中还有结点" << size << "个。" << endl;
        cout << "是否显示被删除的各结点的值？是请按1，否则请按0：" << endl;
        cin >> choice7;
        if (choice7 == 1)D_ShowAll(dhead);
        Deld(); dhead = dtail = NULL; dsize = 0;
        if (qsize > 0)
        {
         cout << "是否继续删除数据域为" <<data7<<"的结点及其子树？是请按1，否则按0："<< endl;
         cin >> choice7;
         if (choice7 == 0)sign7 = false;
        }
       }
       Delq(); head = tail = NULL; qsize = 0;
      mark7:break;
   }
   //判断是否为完全二叉树
  case 8:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁，无法进行判断，请您先创建二叉树！" << endl; break; }
       bool branch=false;
       Addq(root);
       while (qsize>0)
       {
        Node<T>* pt;
        pt = Outq();
        if (!branch)
        {
         if (pt->left == NULL&&pt->right != NULL)
         {
          cout << "目前的二叉树不是完全二叉树！" << endl;
          Delq(); head = tail = NULL; qsize = 0;
          goto mark8;
         }
         if (pt->right==NULL)
         {
          branch = true;
         }
        }
        else
        {
         if (pt->left != NULL || pt->right != NULL)
         {
          cout << "目前的二叉树不是完全二叉树！" << endl;
          Delq(); head = tail = NULL; qsize = 0;
          goto mark8;
         }
        }
        if (pt->left != NULL)Addq(pt->left);
        if (pt->right != NULL)Addq(pt->right);
       }
       cout << "目前的二叉树是完全二叉树！" << endl;
       head = tail = NULL;
      mark8:break;
   }
   //销毁二叉树
  case 9:
   {
       if (!root){ cout << "二叉树还未创建或已被销毁！" << endl; break; }
       cout << "您确定销毁该二叉树吗？确定请按1，取消请按0：" << endl;
       int choice9; cin >> choice9;
       if (choice9 == 0)break;
       else Destory(root);
       root = NULL;
       size = 0;
       cout << "二叉树已销毁！" << endl;
       break;
   }
   //处理用户的错误输入 
   default:
   {
        cout << "您的输入有误，无法进行操作！" << endl;
        break;
   } 

  }//switch结束
  //控制循环
  cout << "是否继续？继续请按1，退出请按0：" << endl;
   int ifgoon;
   cin >> ifgoon;
   if (ifgoon == 0)flager = false;
  }//while结束
}
 #endif 
#pragma once
