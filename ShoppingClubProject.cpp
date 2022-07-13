#include<bits/stdc++.h>
using namespace std;
static int m=0;
class Node
{
    public :
    int id,quantity,price;
    string name;
    Node *next;
    void Add();
    void Administrator();
    void Display();
    void Modify();
    void Delete();
    void DisplayCustomer();
}*head=nullptr,*last=nullptr;
class Cust
{
public :
    string name;
    long long int phoneno;
    Cust *up,*down;
    void buy();
    void Customer();
}*top = nullptr,*current = nullptr;
void Cust::Customer()
{
    Node *p=head;
    Node ob;

    long long int number,choose,count=0,s,y,id,quantity,purchased=0;
    cout<<"Enter your name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter your phone number : ";
    cin>>number;
    Cust *temp;
    if(top==nullptr)
    {
        temp = new Cust;
        top = temp;
        temp->name = name;
        temp->phoneno = number;
        temp->up = nullptr;
        current =temp;
        temp->down = nullptr;
    }
    else
    {
        temp = new Cust;
        temp->down = top;
        temp->name = name;
        temp->phoneno = number;
        temp->up = nullptr;
        top = temp;
    }
    cout<<"Enter your choice :\n1.Inquiry about Products.\n2.Buy products "<<endl;
    cin>>choose;
    switch(choose)
    {
    case 1 :
        cout<<"Here are the products available at our store...."<<endl;
        ob.Display();
        break;
    case 2 :
        y :
        purchased++;
        ob.Display();
        cout<<"Enter the id of the product you wanna buy : ";
        cin>>id;
        while(p!=nullptr)
        {
            if(p->id==id)
            {
                s :
                cout<<"Enter the quantity of the product you wanna buy : ";
                cin>>quantity;
                if(p->quantity<quantity)
                {
                    cout<<"Sorry! We are not available with the desired quantity. Would you like to enter quantity again?\n1.Yes\n2.No";
                    cin>>choose;
                    if(choose == 1)
                        goto s;
                    else
                        break;
                }
                else
                {
                    p->quantity = p->quantity - quantity;
                    count+=(quantity*(p->price));
                }
                break;
            }
            p=p->next;
        }
        if(p==nullptr)
        {
            cout<<"Product not found."<<endl;
        }
        else
        {
            cout<<"Would you like to buy anything else?\n1.Yes\n2.No"<<endl;
            cin>>choose;
            if(choose==1)
            {
            p=head;
            goto y;
            }
        }
        break;
    }

    cout<<"Your Final receipt is as follows..."<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Phone number : "<<number<<endl;
    cout<<"Products purchased : "<<purchased<<endl;
    cout<<"Total Bill : Rs. "<<count<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"Thankyou for shopping!!"<<endl;
}

void Node::Add()         /* Use OF linked list data structure*/
{
    int Pid,Pq,Pprice;
    string Pname;
    Node *temp;
    cout<<"Enter id of the product : ";
    cin>>Pid;
    cout<<"Enter name of the product : ";
    cin.ignore();
    getline(cin,Pname);
    cout<<"Enter quantity available of this product : ";
    cin>>Pq;
    cout<<"Enter price of the product : ";
    cin>>Pprice;
    cout<<endl;
    if(head==nullptr)
    {
        temp = new Node;
        head = temp;
        temp->name = Pname;
        temp->quantity = Pq;
        temp->price = Pprice;
        temp->id = Pid;
        last = temp;
        last->next = nullptr;
    }
    else
    {
        temp = new Node;
        temp->name = Pname;
        temp->quantity = Pq;
        temp->price = Pprice;
        temp->id = Pid;
        last->next = temp;
        last = temp;
    }
    cout<<"Product Added Successfully!!"<<endl;
}

void Node::Display()
{
    int c=0;
    Node *p = head;
    if(head==nullptr)
    {
        cout<<"There is no existing product!!";
    }
    else
    {
    cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
		cout<<"|=================================================================|\n";
		while(p!=NULL)
		{
			cout<<p->id<<"\t\t"<<p->name<<"\t\t\t"<<p->price<<"\t\t\t"<<p->quantity<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1;
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
    }
}
void Node::Modify()
{
    int id,quantity,price;
    string name;
    Display();
    cout<<"Enter the id of the product you want to modify : ";
    cin>>id;
    Node *p = head;
    while(p!=nullptr)
    {
        if(p->id==id)
        {
            cout<<"Existing Details : "<<endl;
            cout<<"Product Name = "<<p->name<<endl;
            cout<<"Product id   = "<<p->id<<endl;
            cout<<"Product Quantity = "<<p->quantity<<endl;
            cout<<"Product Price = "<<p->price<<endl;
            cout<<endl;
            cout<<"Enter new id : ";
            cin>>id;
            p->id = id;
            cout<<"Enter product name : ";
            cin.ignore();
            getline(cin,name);
            p->name = name;
            cout<<"Enter product quantity : ";
            cin>>quantity;
            p->quantity = quantity;
            cout<<"Enter price : ";
            cin>>price;
            p->price = price;
            break;
        }
        p=p->next;
    }
    if(p==nullptr)
    {
        cout<<"Invalid id!!"<<endl;
        return;
    }
    cout<<"Item Modified Successfully..."<<endl;
}
void Node::Delete()
{
    int id;
    Display();
    cout<<"Enter the id of the node you want to delete : ";
    cin>>id;
    Node *p=head,*q=nullptr;
    while(p!=nullptr)
    {
        if(p->id==id&&p==head)
        {
            head = head->next;
            delete p;
            cout<<"Product Deleted successfully!"<<endl;
            break;
        }
        else if(p->id==id)
        {
            q->next = p->next;
            delete p;
            cout<<"Product Deleted successfully!"<<endl;
            break;
        }
        q=p;
        p = p->next;
    }
    if(p==nullptr)
        cout<<"Invalid input id!! Product cannot be deleted!"<<endl;
}
void Node::DisplayCustomer()
{
    Cust *p = top;
    cout<<"Customer list up to now is as follows : "<<endl;
    if(p==nullptr)
    {
        cout<<"There have been no customers up to now!!"<<endl;
    }
    else
    {
    while(p!=nullptr)
    {
        cout<<p->name<<" - "<<p->phoneno<<endl;
        p = p->down;
    }
    }
}
void Node::Administrator()
{
    int choose,s;
    s :
    cout<<"Choose from the following :\n1.Add Product.\n2.Display All Products\n3.Modify Existing Product\n4.Delete an Product\n5.Display Customers List"<<endl;
    cin>>choose;
    switch(choose)
    {
        case 1 : Add();
        break;
        case 2 : Display();
        break;
        case 3 : Modify();
        break;
        case 4 : Delete();
        break;
        case 5 : DisplayCustomer();
        break;
    }
    cout<<"Do you want to continue within administrator?\n1.Yes\n2.No"<<endl;
    cin>>choose;
    if(choose==1)
        goto s;
    else
        cout<<"Terminated..."<<endl;
}
int main()
{
    Node ob;
    Cust c;
   
    cout<<"********************SHOPPING CLUB PROJECT************************"<<endl;
   
    char choose;
    int choice,k;
    cout<<"Input any key to start shopping..."<<endl;
    cin>>choose;
    cout<<endl<<endl;
    do
    {
    cout<<"Please enter the choice from the options mentioned below :\n1.Administrator\n2.Customer\n3.Exit"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1 :  ob.Administrator();
        break;
        case 2 :  c.Customer();
        break;
        case 3 : return 0;
        break;
    }
    }while(choice!=3);
}