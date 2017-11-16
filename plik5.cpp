//An example of simple stack using linked lists, can be used for database management system.
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct DAT
{
    int id;
    char fname[20];
    char mname[20];
    char lname[20];
    char address[80];
    double salary;
    char tele_no[15];
};

struct NODE
{
  DAT data;
  Node *N;
  Node *P;
  Node(const int i , const char *f, const char *m, const char *l, const char *ad, const double s, const char *tel)
    {
       data.id = i;
       strcpy(data.fname,f);
       strcpy(data.mname,m);
       strcpy(data.lname,l);
       strcpy(data.address,ad);
       data.salary = s;
       strcpy(data.tele_no,tel);
       N = NULL;
       P = NULL;
  }

};

class StackLinkedList
{
  private:
  NODE *front;
  public:
  StackLinkedList(){front = NULL;}
  ~StackLinkedList(){destroyList();}
  void push(NODE *);
  NODE* pop();
  void destroyList();
};
void StackLinkedList::push(NODE *n)
{
    if(front == NULL)
    {
        front = n;
    }
    else
    {
        front->P = n;
        n->N = front;
        front = n;
    }
}

NODE* StackLinkedList::pop()
{
        NODE *temp;
    if( front == NULL )//no nodes
        return NULL;
    else if(front->N == NULL)//there is only one node
    {
        NODE * temp2 = front;
            temp = temp2;
            front = NULL;
            delete temp2;
            return temp;
    }
    else//there are more than one node
    {
       NODE * temp2 = front;
            temp = temp2;
            front = front->N;
            front->P = NULL;
            delete temp2;
            return temp;
    }
}

void StackLinkedList::destroyList()
{
   while(front != NULL)
   {
       NODE *temp = front;
       front = front->N;
       delete temp;
   }
}

void disp(NODE *N)
{
    if( N == NULL )
    {
        cout << "\nStack is Empty!!!" << endl;
    }
    else
    {
        cout << "\nId No.     : " << N->data.id <<" ";
        cout << "\nFull Name  : " << N->data.fname << " ";
        cout <<  N->data.mname << " ";
        cout <<  N->data.lname << endl;
        cout << "Address    : " << N->data.address << endl;
        cout << "Salary     : " << setprecision(15)  << N->data.salary << endl;
        cout << "Tele_no    : " << N->data.tele_no<< endl << endl;
    }
}

int main()
{
    StackLinkedList *Stack = new StackLinkedList();

    NODE No1(101,"Aaaaa","Nnnnnnn","Mmmmm","KRG Hawler Muhabad 120",7851243.9475,"07502334121");
    NODE No2(102,"Bbbbb","Ddddd","Ssssss","KRG DUhok 121",5681125.9457,"07507534127");
    NODE No3(103,"Ccccc","Gggggg","Kkkkkk","Iraq KRG-Erbil 123",2344003.48345,"075078654129");

    Stack->push(&No1);
    Stack->push(&No2);
    Stack->push(&No3);

    disp(Stack->pop());

    disp(Stack->pop());

    disp(Stack->pop());

    disp(Stack->pop());


    delete Stack;
    return 0;
}
/*Program's output
*********************
Id No.     : 103
Full Name  : Ccccc Gggggg Kkkkkk
Address    : Iraq KRG-Erbil 123
Salary     : 2344003.48345
Tele_no    : 075078654129


Id No.     : 102
Full Name  : Bbbbb Ddddd Ssssss
Address    : KRG DUhok 121
Salary     : 5681125.9457
Tele_no    : 07507534127


Id No.     : 101
Full Name  : Aaaaa Nnnnnnn Mmmmm
Address    : KRG Hawler Muhabad 120
Salary     : 7851243.9475
Tele_no    : 07502334121


Stack is Empty!!!

Process returned 0 (0x0)   execution time : 0.016 s
Press any key to continue.
*/
