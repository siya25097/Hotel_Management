#include <iostream>
using namespace std;
class Hotel
{
private:
    struct Node
    {
        int id, date;
        string name, roomtype;
        Node *next;
    };

public:
    Node *head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
    void list();
};
void Hotel::menu()
{
p:
    int choice;
    cout << "\n";
    cout << "\t welcome to Hotel Management System Application\n"<< "\n";
    cout << "\n\t_____Hotel Management System_____";
    cout << "\n\nS.No     Functions                     Description" << "\n";
    cout << "\n1\tAllocate Room\t\t\tInsert New Room";
    cout << "\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout << "\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout << "\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout << "\n5\tShow Room Records\t\tShow Room Records that(we added)";
    cout << "\n6\tExit" << "\n";

    cout << "Enter your choice" << "\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert();
        menu();
        
    case 2:
        search();
        menu();
        
    case 3:
        update();
        menu();
        
    case 4:
        del();
        menu();
       
    case 5:
        sort();
        show();
        menu();
       
    case 6:
         exit(0);
         default:cout<<"Invalid";
    }
}
void Hotel::insert(){
    cout << "\n\t_____Hotel Management System_____";
    Node* new_node=new Node;
    cout<<"\nEnter Room ID "<<"\n";
    cin>>new_node->id;
    cout<<"\nEnter Customer Name "<<"\n";
    cin>>new_node->name;
    cout<<"\nEnter Allocated Date "<<"\n";
    cin>>new_node->date;
    cout<<"\nEnter Room Type(single/double/twin) "<<"\n";
    cin>>new_node->roomtype;


    if(head==NULL){
        head=new_node;
    }
    else{
        Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
    cout<<"\n\n\t\t New Room Inserted";
}
void Hotel::search(){
    cout << "\n\t_____Hotel Management System_____";
    int t_id;
    if(head==NULL){
        cout<<"\n\nLinked List is Empty";
    }
    else{
        cout<<"\n\nRoom ID";
        cin>>t_id;
        Node* ptr=head;
        while(ptr!=NULL){
            if(t_id==ptr->id){
                cout<<"\n\nRoom ID"<<ptr->id;
                cout<<"\n\nCustomer Name"<<ptr->name;
                cout<<"\n\nRoom Allocated Date"<<ptr->date;
                cout<<"\n\nRoom Type"<<ptr->roomtype;

            }
            ptr=ptr->next;
        }
    }
  
}

void Hotel::update(){
    cout << "\n\t_____Hotel Management System_____";
    int t_id;
    if(head==NULL){
        cout<<"\n\nLinked List is Empty";
    }
    else{
        cout<<"\n\nRoom ID";
        cin>>t_id;
        Node* ptr=head;
        while(ptr!=NULL){
            if(t_id==ptr->id){
                cout<<"\n\nRoom ID";
                cin>>ptr->id;

                cout<<"\n\nCustomer Name";
                cin>>ptr->name;

                cout<<"\n\nAllocated Date";
                cout<<ptr->date;

                cout<<"\n\nRoom Type";
                cout<<ptr->roomtype;

                cout<<"\n\n\t\t Update Record Successfully";
            }
            ptr=ptr->next;
        }
    }
}
void Hotel::del(){
    cout << "\n\t_____Hotel Management System_____";
    int t_id;
    if(head==NULL){
        cout<<"\n\nLinked List is Empty";
    }
    else{
        cout<<"\n\nRoom ID";
        cin>>t_id;
        if(t_id==head->id){
          Node* ptr=head;
          head=head->next;
          delete ptr;
          cout<<"Deleted Room Record Successfully";
        }
        else{
            Node* pre=head;
            Node* ptr=head;
            while(ptr!=NULL){
                if(t_id==ptr->id){
                    pre->next=ptr->next;
                    delete ptr;
                    cout<<"Deleted Room Record Successfully";
                    break;
                }
                pre=ptr;
                ptr=ptr->next;
            }
        }
    }
}
void Hotel::show(){
    Node* ptr=head;
    while(ptr!=NULL){
        cout<<"\n\nRoom ID"<<ptr->id;
        cout<<"\n\nCustomer Name"<<ptr->name;
        cout<<"\n\nAllocated Date"<<ptr->date;
        cout<<"\n\nRoom Type"<<ptr->roomtype;
        ptr=ptr->next;
    }
}
void Hotel::sort(){
    if(head==NULL){
        cout<<"\n\nLinked List is Empty";
        menu();
    }
    int count=0, t_id,t_date;
    string t_name,t_roomtype;
    Node* ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    for(int i=1;i<=count;i++){
        Node* ptr=head;
        for(int j=1;j<count;j++){
            if(ptr->id>ptr->next->id){
                t_id=ptr->id;
                t_name=ptr->name;
                t_date=ptr->date;
                t_roomtype=ptr->roomtype;

                ptr->id=ptr->next->id;
                ptr->name=ptr->next->name;
                ptr->date=ptr->next->date;
                ptr->roomtype=ptr->next->roomtype;
            }
            ptr=ptr->next;
        }
    }
}
int main(){
    Hotel h;
    h.menu();
}