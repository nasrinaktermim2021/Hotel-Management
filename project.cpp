#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define exit();
class About;
class Customer;
class Room;

template<class T>
void bswap(T &b,T &c)
{
     T temp=b;
     b=c;
     c=temp;
}
template<class T>
void bsort(T a[],T b[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
    {
        if(b[i]>b[j])
        {
            bswap(b[i],b[j]);
            bswap(a[i],a[j]);
        }
    }
}

template<class T>
void display(T a[],T b[],int n)
{
    cout<<"\n"<<setw(30)<<"Room No"<<"        "<<"cost"<<endl;
    for(int i=0;i<n;i++)
        cout<<"\n"<<setw(30)<<a[i]<<"          "<<b[i];
    cout<<endl;
}
    template<class T>
    void writeData(T obj,char *fname)
    {
        fstream inoutfile;
        obj.getData();
        inoutfile.open(fname,ios::app);
        inoutfile.write((char *)&obj,sizeof(obj));
        inoutfile.close();
    }
    template<class T>
    void readData(T obj,char *fname)
    {
        int size =0;
        int tobj=0;
        int i=0;
        fstream inoutfile;
        inoutfile.open(fname,ios::app);
        inoutfile.seekg(0,ios::end);
        size=inoutfile.tellg();
        tobj=size/sizeof(obj);
        inoutfile.seekg(0);
        for(i=0;i<tobj;i++)
        {

        inoutfile.read((char *)&obj,sizeof(obj));
        obj.display();
        }
        inoutfile.close();
    }

class Hotel
{
    public:
        virtual void menu()=0;

};

class Customer :  virtual public Hotel
{
     public:
    Customer();
        virtual ~Customer();
        void menu();
        void check_in();
        void check_out();
        void customersearch();
        void all_view();
protected:
    int roomId,dat1,dat2,dat3;
    int static totalCustomer;
	char name[30];
	char address[50];
	char phone[12];
	int counter;
    char type[15];
    int cost;
        int getRoomId()
        {
            return roomId;
        }

    public:
          friend class About;
    void getData()
       {

           int g;
           totalCustomer++;
      cout <<"\n\nRoom No  : ";
    cin>>roomId;
    cout<<"Date:";
    do
{
    int g=0;
try
{
    cin>>dat1;
    cin>>dat2;
    cin>>dat3;
        if(dat1>32&&dat2>13&&dat3<2018)
            throw "Invalid date input.Date value maximum 30,Month value 12,year grater than 2018 ";
        g++;
        break;
}
catch( const char *m)
{
    cout<<m<<endl;
}

}while(g);

    cout<<" Name: ";
    do
    {int g=0;
        try
        {
             cin>>name;
           if(strlen(name)>30)
            throw "out of input range.Maximum character 30";
           g++;
           break;
        }
        catch( const char *m)
{
    cout<<m<<endl;
}

    }while(g);

    cin.ignore();
    cout<<" Address: ";
    do
    { int g=0;
        try
        {
             cin>>address;
           if(strlen(address)>30)
            throw "out of input range.Maximum character 30";
           g++;
           break;
        }
        catch( const char *m)
{
    cout<<m<<endl;
}

    }while(g);
    cin.ignore();
    cout<<" Phone No: ";
    do
    {int g=0;

     try
     {
         cin>>phone;
     if( strlen(phone)<11||strlen(phone)>12)
        throw "Invalid phone number.Phone must be contain 11 digit ";
        g++;
        break;
     }
     catch(const char *m)
     {
         cout<<m<<endl;
     }

    }while(g);

    cin.ignore();
       }
    void display()const
       {
cout<<setw(15) << roomId << setw(20)<< name << setw(20) << address << setw(20) << phone <<setw(20)<<dat1<<"."<<dat2<<"."<<dat3<< endl;

       }
       void display(int)
       {
            cout<<"\n\t\t\tList Of Rooms Allotted"<<endl;
        cout<<setw(20)<<"\t-----------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(20)<<"Room No ";
        cout<<setw(20)<<"Name    ";
        cout<<setw(20)<<"Address  ";
        cout<<setw(20)<<"Phone number  ";
        cout<<setw(20)<<"Check in Date  ";
        cout<<endl;
        cout<<setw(20)<<"\t---------------------------------------------------------------------------------------------"<<endl;

       }

};
int Customer::totalCustomer;

Customer::Customer()
{
   roomId=0;

   //ctor
}

Customer::~Customer()
{
    //dtor
}

void Customer::menu()
{
    Customer c;
    int choice;
    while(choice!=6)
    {
        cout<<"\n\t\t\t*************************************************************";
        cout<<"\n\t\t\t***          Customer MANAGEMENT ****** *********************";
        cout<<"\n\t\t\t*************************************************************";

        cout<<"\n\n\n\t\t\t1.check in";
        cout<<"\n\t\t\t2.check out";
        cout<<"\n\t\t\t3.Update";
        cout<<"\n\t\t\t4.All View";
        cout<<"\n\t\t\t5.search";
        cout<<"\n\t\t\t6.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            check_in();
            break;
        case 2:
            check_out();
            break;
        case 4:
            all_view();
            break;
        case 5:
            customersearch();
            break;
        case 6:
            exit();
            break;
        default:
        {
            cout<<"\n\n\t\t\tWrong choice!!!";
            cout<<"\n\t\t\tPress any key to continue!!";

        }
        break;


        }
    }
}

void Customer::check_in()
{
   Customer co;
    cout<<"\n Enter Customer Details";
    cout<<"\n **********************"<<endl;
   getData();
   fstream inoutfile;
   inoutfile.open("customerRecord.text",ios::app);
   inoutfile.write((char*)this,sizeof(*this));
   inoutfile.close();
     // writeData(co,"customerRecord.text");
     //readData(co,"customerRecord.text");
    cout<<"\n Room is booked!!!";


}

void Customer::check_out()
{
    int room;
    cout<<"\n\n\t\tEnter the room no: ";
    cin>>room;
    ifstream inoutfile;
    ofstream tempfile;
    inoutfile.open("customerRecord.text",ios::app);
    tempfile.open("temp.text",ios::app);
    inoutfile.read((char*)this,sizeof(*this));
    while(!inoutfile.eof())
    {
        if(room!=roomId)
            tempfile.write((char*)this,sizeof(*this));
        inoutfile.read((char*)this,sizeof(*this));
    }
    inoutfile.close();
        tempfile.close();
        remove("customerRecord.text");
        rename("temp.text","customerRecord.text");
        cout<<"Check out successfully"<<endl;
}

void Customer::customersearch()
{

int roomNo ,flag=0;
    cout<<"\n\tEnter the room no:";
    cin>>roomNo;
    cin.ignore();
    display(flag);
    fstream inoutfile;
    inoutfile.open("customerRecord.text",ios::app);
    inoutfile.seekg(0);
    inoutfile.read((char*)this,sizeof(*this));
    while(!inoutfile.eof())
    {
        if(roomNo==roomId)
        {
            display();
            flag++;
            break;
        }
         inoutfile.read((char*)this,sizeof(*this));
    }
if(flag==0)
    {
        cout<<"\nRoom is not found..................."<<endl;
    }

    inoutfile.close();


}

void Customer::all_view()
{
         int a=0;
         display(a);
         fstream inoutfile;
         inoutfile.open("customerRecord.text",ios::in);
        inoutfile.seekg(0,ios::beg);
    inoutfile.read((char *)this,sizeof(*this));
        while(!inoutfile.eof())
        {
         display();
        inoutfile.read((char *)this,sizeof(*this));
        }

   inoutfile.close();

}
class Room : virtual public Hotel,public Customer
{
public:
    Room();

    void menu();
    void add();
    void delet();

    void getData()


    {    cout<<"\n\t\tRoom No :  ";
    cin>>roomId;
    cout<<"\n\t\ttype    :  ";
    cin >> type;
     cin.ignore();
    cout<<"\n\t\tCost :  ";
    cin.ignore();
    cin>>cost;
    cout<<endl;

       }
  void display()const
       {
         cout<<setw(15) << roomId << setw(20)<< type << setw(20)<<cost<<  endl;

       }
void alldisplay();

};
Room::Room()
{ roomId=0;
  strcpy(type,"no tital");
  cost=0;
    //ctor
}
void Room::menu()
{
    cout<<setw(20)<<"\t\t\t*****************************************************"<<endl;
    cout<<setw(20)<<"\t\t\t*****************************************************"<<endl;
    cout<<setw(20)<<setw(20)<<"\n\t\t\t\t\tManage Room\t\t\n\n\n";
    cout<<setw(20)<<"\t\t\t*****************************************************"<<endl;
    cout<<setw(20)<<"\t\t\t*****************************************************"<<endl;
    cout<<setw(20)<<"\t\tpress any key...........................\n\n";
    cout<<setw(20)<<"\n\t\t1.Add\n";
    cout<<setw(20)<<"\n\t\t2.Delete\n";
    cout<<setw(20)<<"\n\t\t3.Display\n";
    cout<<setw(20)<<"\n\t\t4.Exit\n";

}
void Room::add()
{
cout<<"\n\tCreated Room Information..........................\n\n";
      return;
}
   void Room::alldisplay()
   {
      cout<<"\n\t\t*************CONTENT OF ROOM*******************\t\t\n";
     cout<<setw(20)<<"\t---------------------------------------------------------------"<<endl;
        cout<<setw(20)<<"Room No ";
        cout<<setw(20)<<"type    ";
        cout<<setw(20)<<"Cost  ";
        cout<<endl;
        cout<<setw(20)<<"\t------------------------------------------------------------------"<<endl;


   }

void Room::delet()
{
    int deleteId;
    cout<<"\n\n\t\tEnter Room ID that you want delete......."<<endl;
    cout<<"\n\t\tRoom ID: ";
    cin>>deleteId;
    return;

}
class About{
    public:
        int room[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,16,17,18,19,20};
        int cost[20]={750,750,750,725,725,725,920,920,920,920,1000,5000,5000,5000,200,200,300,300,4000,4000};
void getData()
{
    bsort(room,cost,20);
    cout<<setw(10)<<"\nDisplay lowest cost room"<<endl;
    display(room,cost,20);

}

    int totalCustomer;
 void tolatCustomer(Customer &obj)
 {
    totalCustomer=obj.totalCustomer;
    cout<<"Total Number of customer: "<<totalCustomer<<endl;
 }
 void menu()
 {
     cout<<"\n\t\t***********************************************************************";
    cout<<"\n\t\t************ HOTEL MANAGEMENT PROJECT **********************************";
    cout<<"\n\t\t************************************************************************";
    cout<<setw(40)<<"\n\n**** Lab Project***" <<endl;
    cout<<setw(30)<<"Project completed in Group"<<endl;
     cout<<setw(30)<<" Group Name : 3STAR"<<endl;
     cout<<setw(30)<<"Batch       :37/A"<<endl;
     cout<<setw(30)<<"Department  :CSE"<<endl;
    cout<<setw(30)<<"\n\n*******Author Information*********"<<endl;
    cout<<setw(30)<<"Nasrin Akter"<<setw(30)<<endl;
     cout<<setw(30)<<"Roll: 1973"<<setw(30)<<endl;

 }
};
int main()
{
    Hotel *h;

    cout<<"\n\t\t\t\t\t\t****************************";
    cout<<"\n\t\t\t\t\t\t* HOTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t\t\t\t****************************";
    cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!!!!!!!!!!!!"<<"\n\n"<<endl;
    int x;
    while(x!=5)
    {

        cout<<"\n\t\t\t\t************************************************************************************";
        cout<<"\n\t\t\t\t********************************** MAIN MENU ****************************************";
        cout<<"\n\t\t\t\t*************************************************************************************";
        cout<<"\n\n\n\t\t\t1.Room";
        cout<<"\n\t\t\t2.Customer";
         cout<<"\n\t\t\t3.About";
        cout<<"\n\t\t\t4.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                 while(1)
                 {
                      int choice1;
                Room r;
                h=&r;
                h->menu();
                   cout<<"\n\n\t\t\tEnter Your Choice: ";
            cin>>choice1;
        switch(choice1)
        {
        case 1:
             writeData(r,"roomRecord.dat");
             r.add();
            break;
        case 2:
            r.delet();
            break;
  case 3:
            r.alldisplay();
             readData(r,"roomRecord.dat");
            break;
        case 4:
            exit();
            goto level;
            break;
        default:
        {
            cout<<"\n\n\t\t\tWrong choice!!!";
            cout<<"\n\t\t\tPress any key to continue!!";

        }
        break;

        }
                 }
    level:
    cout << "exit called" << endl;
            }
            break;
            case 2:
            {
               Customer c;
               h=&c;
                h->menu();
            }
            break;
            case 3:
            {   Customer c;
                About a;
                a.tolatCustomer(c);
                a.getData();
               a.menu();
            }
            break;
            case 4:
                exit();
                goto level2;
                break;
            default:
            {
                cout<<"\n\n\t\t\tWrong choice!!!";
                cout<<"\n\t\t\tPress any key to continue!!";
            }
        }
    } level2:
    return 0;
}


