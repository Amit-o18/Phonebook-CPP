#include<iostream>
#include<vector>
#include<cctype>
#include<fstream>
using namespace std;

class Contact{
    unsigned long long int number;
    string name;
    public:
    Contact(string n, unsigned long long int num){
        name=n;
        number=num;
    }

    string get_name(){
        return name;
    }
    unsigned long long int get_number(){
        return number;
    }

    void set_number(unsigned long long int num){
        number=num;
    }

    void set_name(string n){
        name=n;
    }
};

class Phonebook{
    public:
    vector<Contact> contact;
    void add_contact();
    void display_contact();
    void search_contact();
    void update_contact();
    void delete_contact();
    void save_to_file();
    void load_file();
    string to_lower(string);
};

void Phonebook::add_contact(){
    string name;
    unsigned long long int number;
    cout<<"Enter Phone Number: ";
    cin>>number;
    if(number<1000000000 || number>9999999999){
        cout<<"Invalid Number!";
        return;
    }

    cin.ignore();
    cout<<"Enter name registered with number: ";
    getline(cin,name);

    Contact c(name,number);

    auto it=contact.begin();
    while(it != contact.end() && it->get_number() < number){
        it++;
    }
    contact.insert(it,c);
    cout<<"Contact added."<<endl;
}

void Phonebook::save_to_file(){
    ofstream fout("phone_book.txt");
    for(auto &c : contact){
        fout<<c.get_number()<<","<<c.get_name()<<endl;
    }
    fout.close();
}

void Phonebook::load_file(){
    ifstream fin("phone_book.txt");
    if(!fin){
        return;
    }

    string line, name;
    unsigned long long int num;

    while(getline(fin,line)){
        if(line.empty()){
            continue;
        }
        int pos=line.find(',');
        if(pos==string::npos){
            continue;
        }
        num=stoull(line.substr(0,pos));
        name=line.substr(pos+1);

        Contact c(name,num);
        auto it=contact.begin();
        while(it!=contact.end() && it->get_number()<num){
            it++;
        }
        contact.insert(it,c);
    }
    fin.close();
}

void Phonebook::display_contact(){
    if(contact.empty()){
        cout<<"No contact found!";
    } else{
        for(int i=0;i<contact.size();i++){
            cout<<"Name: "<<contact[i].get_name()<<endl;
            cout<<"Phone number: "<<contact[i].get_number()<<endl;
            cout<<"-----------------\n";
        }
    }
}

void Phonebook::search_contact(){
     if(contact.empty()){
        cout<<"Contact list is empty!";
    }else{
      cout<<"In which method u want to search:\n1.By Number\n2.By name.\nEnter your option: ";
      int ch;
      cin>>ch;

      bool found=false;
     

      if(ch==1){
       cout<<"Enter Number: ";
       unsigned long long int n;
       cin>>n;
       
         int lb=0,ub=contact.size()-1;
         while(lb<=ub){
           int mid=(lb+ub)/2;
              if(contact[mid].get_number()==n){
                cout<<"Contact Found!\n"<<"Name: "<<contact[mid].get_name()<<"\nPhone Number: "<<contact[mid].get_number()<<endl;
                found=true;
                break;
              } 
            if(n<contact[mid].get_number()){
                ub=mid-1;
            } else{
                lb=mid+1;
            }
        }
           if(!found){
                cout<<"Contact Not Found!"<<endl;
           }
      } else if(ch==2){
        cin.ignore();
        cout<<"Enter Name : ";
        string n;
        getline(cin,n);
        string srch_name=to_lower(n);
         for(int i=0;i<contact.size();i++){
            string stored=to_lower(contact[i].get_name());
            if(stored.find(srch_name)!=string::npos){
            cout<<"Contact Found...\n"<<"Name: "<<contact[i].get_name()<<"\nPhone Number: "<<contact[i].get_number()<<endl;
            found=true;
            
        }
       }
      } else{
        cout<<"Invalid Choice!";
        return;
      }
      if(found==false){
        cout<<"Contact not found!";
      }
    }
}

void Phonebook::update_contact(){
    if(contact.empty()){
        cout<<"Contact list is empty!";
    }
    int ch;
    cout<<"You Want to update\n1.Number\n2.Name\nEnter choice: ";
    cin>>ch;
    bool found =false;
    if(ch==1){
        unsigned long long int old_num , new_num;
       
        cout<<"Enter the number which you want to update: ";
        cin>>old_num;

        for(int i=0;i<contact.size();i++){
            if(old_num==contact[i].get_number()){
                unsigned long long int n,temp;
                cout<<"Enter new Number: ";
                cin>>new_num;
                if(new_num<1000000000 || new_num>9999999999){
                    cout<<"Invalid Number\n";
                    return;
                }
                contact[i].set_number(new_num);
               cout<<"Number Updated successfully..."<<endl;
               found=true;
               break;
            }
        }
    } else if(ch==2){
        string old_name,new_name;
        cin.ignore();
        cout<<"Enter name which u want to update: ";
        getline(cin,old_name);

        for(int i=0;i<contact.size();i++){
            if(old_name==contact[i].get_name()){
                cout<<"Enter new Name: ";
                getline(cin,new_name);
                contact[i].set_name(new_name);
                cout<<"Name updated successfully..."<<endl;
                found=true;
                break;
            }
        }
    } else{
        cout<<"Invalid choice!"<<endl;
        return;
    }
    if(found==false){
        cout<<"Contact Not found!";
        return;
    }
}

void Phonebook::delete_contact(){
      if(contact.empty()){
        cout<<"Contact list is empty!";
    }else{
        int ch;
        bool found =false;
        cout<<"You want to delete contact by Name or Number\n1.By Name\n2.By Number\nEnter: ";
        cin>>ch;
        if(ch==1){
            cin.ignore();
            string n;
            cout<<"Enter name : ";
            getline(cin,n);
            for(int i=0;i<contact.size();i++){
                if(n==contact[i].get_name()){
                    contact.erase(contact.begin()+i);
                    cout<<"Contact Deleted Successfully!";
                    found = true;
                    break;
                }
            }
        } else if(ch==2){
            unsigned long long int num;
            cout<<"Enter number: ";
            cin>>num;
            if(num<1000000000 || num>9999999999){
                cout<<"Invalid number!";
                return;
            }
            for(int i=0;i<contact.size();i++){
                if(num==contact[i].get_number()){
                    contact.erase(contact.begin()+i);
                    cout<<"Contact Deleted Successfully!";
                    found=true;
                    break;
                }
            }
        } else{
            cout<<"Invalid Choice!";
            return;
        }
        if(found == false){
            cout<<"Contact not found!";
            return;
        }
    }
}




string Phonebook::to_lower(string s){
    for(int i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
    return s;
}

int main(){
    Phonebook pb;
    pb.load_file();
    unsigned long long int choice;
    cout<<"Welcome to Phonebook\n";
    do{
        bool data_changed=false;
    cout<<"\nChoose your operation:\n1.Add Contact\n2.Display Contact\n3.Search Contact\n4.Update Contact\n5.Delete Contact\n6.Exit.\nEnter: ";
    cin>>choice;
        switch(choice){
            case 1:
            pb.add_contact();
            data_changed=true;
            break;

            case 2:
            pb.display_contact();
            break;

            case 3:
            pb.search_contact();
            break;

            case 4:
            pb.update_contact();
            data_changed=true;
            break;

            case 5:
            pb.delete_contact();
            data_changed=true;
            break;

            case 6:
            cout<<"Thank you for using Phonebook.\n";
            cout<<"Exiting...";

            default:
            cout<<"Invalid Choice! Please try again.";
            break;
        }

        if(data_changed){
            pb.save_to_file();
        }
    }while(choice!=6);
    return 0;
}