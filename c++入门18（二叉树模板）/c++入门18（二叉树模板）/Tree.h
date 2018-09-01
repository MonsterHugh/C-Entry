#ifndef TREE_H
#define TREE_H 
#include <iostream>
#include<iomanip>
using namespace std;

template<typename T>
 struct Node            //�����
{
  T data;
  Node<T> *left, *right;
  Node(const T& item);
 }; 

template<typename T>
 Node<T>::Node(const T& item)   //������ʼ��
{
  data = item;
  left = NULL;
  right = NULL;
 } 

template<typename T>          //���н��
struct QNode
 {
  Node<T>* pdata;
  QNode<T>* next;
  QNode( Node<T>* &pd,  QNode* tp);
 }; 

template<typename T>           //���н���ʼ��
QNode<T>::QNode( Node<T>* &pd,  QNode* tp)   
 {
  pdata = pd;
  next = tp;
 } 

template<typename T>            //��ɾ��Ԫ�صĶ��н��
struct DQNode
 {
  T d_data;
  DQNode<T>* dnext;
  DQNode(const T& ditem, DQNode<T>* dp);
 }; 

template<typename T>                                 //��ɾ��Ԫ�صĶ��н���ʼ��
DQNode<T>::DQNode(const T& ditem, DQNode<T>* dp)
 {
  d_data = ditem;
  dnext = dp;
 } 

template<typename T>           //��������
class Tree
 {
 private:
  Node<T>* root;
  QNode<T>* head, *tail;
  DQNode<T>*dhead, *dtail;
  int size;//��¼��������㳤��
 int qsize;//��¼���г���
 int dsize;//��¼DQNode���г���
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

template<typename T>           //�๹�캯��
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

template<typename T>          //����������
Tree<T>::~Tree()
 {
  Destory(root);
 } 

template<typename T>          //���һ��Ԫ��
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

template<typename T>          //����һ��Ԫ��
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

template<typename T>            //DQNode���һ��Ԫ��
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

template<typename T>           //��ն���
void Tree<T>::Delq()
 {
   while (head)
  {
   QNode<T>* temp;
   temp = head; head = head->next; delete temp;
  }
 } 

template<typename T>           //���DQNode����
void Tree<T>::Deld()
 {
   while (dhead)
  {
   DQNode<T>* dtemp;
   dtemp = dhead; dhead = dhead->dnext; delete dtemp;
  }
 } 

template<typename T>               //���������ȫ��Ԫ��
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

template<typename T>               //���DQNode������ȫ��Ԫ��
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

template<typename T>                         //�õ�ĳ��㣨�Ե�ַΪ�ؼ�ֵ���ĸ����ĵ�ַ
Node<T>* Tree<T>::GetFather(Node<T>* t, Node<T>* p)
 {
  Node<T>* q;
  if (t == NULL)return NULL;
  if (t->left == p || t->right == p)return t;
  q = GetFather(t->left, p);
  if (q!= NULL)return q;
  else return GetFather(t->right, p);
 } 

template<typename T>             //������ɾ����ĳ���Ϊ������
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

template<typename T>           //����������
Node<T>* Tree<T>::Creat(Node<T>* &rt)
 {
  int choice; bool flag;
  if (size > 0)
  {
   cout << "�Ƿ�����������������밴1�����밴0��" << endl;
    cin >> choice; 
    flag = true;
  }
  if (size == 0)
  {
   cout << "��������������;" << endl;
   T data; cin >> data;
   rt = new Node<T>(data);
   if (!rt){ cout << "����㴴��ʧ�ܣ�" << endl; return NULL; }
   size++;
      flag = false;
   cout << "����㴴���ɹ���" << endl;
   cout << "Ŀǰ���й��н��" << size << "����" << endl;
  }
  if (flag)
  {
   if (choice == 0)return 0;
   else
   {
    cout << "�������ӽ������;" << endl;
    T data; cin >> data;
    rt = new Node<T>(data);
    if (!rt){ cout << "�ӽ�㴴��ʧ�ܣ�" << endl; return NULL; }
    size++;
    cout << "�ӽ�㴴���ɹ���" << endl;
    cout << "Ŀǰ���й��н��" << size << "����" << endl;
   }
  }
  Creat(rt->left);
  Creat(rt->right);
  return root;
 } 

template<typename T>              //�ȸ��ݹ���� FiRoTra��first root traversal����д
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

template<typename T>              //�и��ݹ���� MiRoTra��middle root traversal����д
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

template<typename T>              //����ݹ���� LaRoTra��last root traversal����д
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

template<typename T>              //��α��� LeveTra��level traversal����д
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

template<typename T>            //����������Ϊĳֵ�Ľ��
void Tree<T>::Search(Node<T>* t, const T& item, bool& sign)
 {
  if (t)
  {
   Search(t->left, item, sign);
   Search(t->right, item, sign);
   if (t->data == item){sign = true; Addq(t);}
  }
 } 

template<typename T>           //���ٶ�����
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

//��װ����
template <typename T>
 void Tree<T>::Operate()
 {
  bool flager = true;
  while (flager)
  {
   cout << "����ѡ��������������ǰ�����ֽ���ѡ�񣩣�" << endl;
   cout << "1.������������д������" << endl;
   cout << "2.�ȸ�����������" << endl;
   cout << "3.�и�����������" << endl;
   cout << "4.�������������" << endl;
   cout << "5.��α���������" << endl;
   cout << "6.����������Ϊĳֵ�Ľ��" << endl;
   cout << "7.ɾ��������Ϊĳֵ�Ľ�㼰������" << endl;
   cout << "8.�ж��Ƿ�Ϊ��ȫ������" << endl;
   cout << "9.���ٶ�����" << endl;
   int choice;
   cin >> choice;
   switch (choice)
   {
   //���û�����������
  case 1:
   {
       if (root){ cout << "�������Ѿ������������ٽ��������½������������پ�����" << endl; break; }
       Creat(root);
       cout << "������������ɣ�" << endl;
       cout << "�˶������й��н��" << size << "����" << endl;
       break;
   }
   //�ȸ�����������
  case 2:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ�б��������������ȴ�����������" << endl; break; }
       int counter2=0;
       FiRoTra(root,counter2);
       cout << endl;
       break;
   }
   //�и����������� 
   case 3:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ�б��������������ȴ�����������" << endl; break; }
       int counter3 = 0;
       MiRoTra(root, counter3);
       cout << endl;
       break;
   }
   //�������������
  case 4:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ�б��������������ȴ�����������" << endl; break; }
       int counter4 = 0;
       LaRoTra(root, counter4);
       cout << endl;
       break;
   }
   //��α���������
  case 5:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ�б��������������ȴ�����������" << endl; break; }
       int counter5 = 0;
       LeveTra(root, counter5);
       cout << endl;
       head = tail = NULL;
       break;
   }
   //����������Ϊĳֵ�Ľ�� 
   case 6:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ�����������������ȴ�����������" << endl; break; }
       cout << "���������������ֵ;" << endl;
       T indata;  cin >> indata;
       bool flag = false;
       Search(root, indata, flag);
       if (!flag){ cout << "�ö�������û��������Ϊ" << indata << "�Ľ�㣡" << endl; break; }
       else cout << "�ö�������������Ϊ" << indata << "�Ľ�㹲��"<<qsize<<"����" << endl;
       cout << "�Ƿ������Щ���ĵ�ַ�����밴1������0��" << endl;
       int choice6; cin >> choice6;
       if (choice6 == 1)    ShowAll(head);
       Delq(); head = tail = NULL; qsize = 0;
       break;
   }
   //ɾ��������Ϊĳֵ�Ľ�㼰������
  case 7:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷�ִ��ɾ�������������ȴ�����������" << endl; break; }
       T data7; bool flag7 = false; bool sign7 = true; int choice7;
       cout << "�������������ݵ�ֵ��" << endl;
       cin >> data7;
       Search(root, data7, flag7);
       if (!flag7){ cout << "Ŀǰ����������������Ϊ" << data7 << "�Ľ�㣡" << endl; Delq(); head = tail = NULL; qsize = 0; break; }
       while (sign7)
       {
        Node<T> *p7, *fp7;
        QNode<T> *item7;
        p7 = head->pdata;
        item7 = head; head = head->next; delete item7; qsize--;
        if (p7 == root)
        {
         cout << "������Ϊ"<<data7<<"�Ľ��Ϊ����㣬��ִ��ɾ�����������������ö�������" << endl;
         cout << "�Ƿ�ȷ��ִ��ɾ��������ȷ���밴1��ȡ���밴0��" << endl;
         cin >> choice7;
         if (choice7 == 0){ Delq(); head = tail = NULL; qsize = 0; goto mark7; }
         else
         {
          Destory(p7); root = NULL; size = 0;
          root = NULL;
          cout << "ɾ���ɹ���ͬʱ���ö�����Ҳ�����٣�" << endl;
          Delq(); head = tail = NULL; qsize = 0;         
          goto mark7;
         }
        }
        fp7 = GetFather(root, p7);
        if (fp7->left == p7)fp7->left = NULL;
        else fp7->right = NULL;
        Del(p7);
        cout << "ɾ���ɹ���" << endl;
        if (qsize == 0){ cout << "��ʱ��������������Ϊ" << data7 << "�Ľ�㼰��������" << endl; sign7 = false; }
        if (qsize > 0){ cout << "����ʱ����������Ϊ" << data7 << "�Ľ�㻹��" <<qsize<<"����"<< endl; }
        cout << "�˴ι�ɾ�����" << dsize << "����" << "Ŀǰ���л��н��" << size << "����" << endl;
        cout << "�Ƿ���ʾ��ɾ���ĸ�����ֵ�����밴1�������밴0��" << endl;
        cin >> choice7;
        if (choice7 == 1)D_ShowAll(dhead);
        Deld(); dhead = dtail = NULL; dsize = 0;
        if (qsize > 0)
        {
         cout << "�Ƿ����ɾ��������Ϊ" <<data7<<"�Ľ�㼰�����������밴1������0��"<< endl;
         cin >> choice7;
         if (choice7 == 0)sign7 = false;
        }
       }
       Delq(); head = tail = NULL; qsize = 0;
      mark7:break;
   }
   //�ж��Ƿ�Ϊ��ȫ������
  case 8:
   {
       if (!root){ cout << "��������δ�������ѱ����٣��޷������жϣ������ȴ�����������" << endl; break; }
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
          cout << "Ŀǰ�Ķ�����������ȫ��������" << endl;
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
          cout << "Ŀǰ�Ķ�����������ȫ��������" << endl;
          Delq(); head = tail = NULL; qsize = 0;
          goto mark8;
         }
        }
        if (pt->left != NULL)Addq(pt->left);
        if (pt->right != NULL)Addq(pt->right);
       }
       cout << "Ŀǰ�Ķ���������ȫ��������" << endl;
       head = tail = NULL;
      mark8:break;
   }
   //���ٶ�����
  case 9:
   {
       if (!root){ cout << "��������δ�������ѱ����٣�" << endl; break; }
       cout << "��ȷ�����ٸö�������ȷ���밴1��ȡ���밴0��" << endl;
       int choice9; cin >> choice9;
       if (choice9 == 0)break;
       else Destory(root);
       root = NULL;
       size = 0;
       cout << "�����������٣�" << endl;
       break;
   }
   //�����û��Ĵ������� 
   default:
   {
        cout << "�������������޷����в�����" << endl;
        break;
   } 

  }//switch����
  //����ѭ��
  cout << "�Ƿ�����������밴1���˳��밴0��" << endl;
   int ifgoon;
   cin >> ifgoon;
   if (ifgoon == 0)flager = false;
  }//while����
}
 #endif 
#pragma once
