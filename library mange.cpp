#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Book{
private: string Title,Author,Isbn,Genre;
int Publicationyear;
public:
Book(string title,string author,string id,string genre,int year):Author(author){
 setTitle(title);
 setAuthor(author);
 setIsbn(id);
 setGenre(genre);
 setPublicationyear(year);
}; 
//setters
void setTitle(string title){Title=title;}
void setAuthor(string author){ 
    while(author==" "){
        cout<<"Please Enter Author name:"<<endl;
        cin>>author;
    }
    Author=author;}
void setIsbn(string id){Isbn=id ;}
void setGenre(string genre){ Genre=genre;}
void setPublicationyear(int year){
    while(year>2025 || year<=0){
        cout<<"Enter year correctly"<<endl;
        cin>>year;
    }
    Publicationyear=year;
}

//getters
string getTitle(){return Title;}
string getAuthor(){return Author;}
string getIsbn(){return Isbn;}
string getGenre(){return Genre;}
int getPublicationyear(){return Publicationyear;}
//Other Methods
void getdetails(){
cout<<"Title:"<<getTitle()<<endl;
cout<<"Author:"<<getAuthor()<<endl;
cout<<"Isbn:"<<getIsbn()<<endl;
cout<<"Genre:"<<getGenre()<<endl;
cout<<"Publciation year:"<<getPublicationyear()<<endl;
}
};
class Author{
    private: string Name;
            int Birthday,Birthmonth,Birthyear;
   public: Author(string name,int Birthday,int Birthmonth,int Birthyear){
    setName(name);
    setBirthdate(Birthday,Birthmonth,Birthyear);
   }
   //setters
   void setName(string name){Name=name;}
   void setBirthdate(int dd,int mm,int yyyy){
    bool okday=false;
    bool okmonth=false;
    bool okyear=false;
    while(okday==false || okmonth==false || okyear==false){
        if(dd>30 ||dd<=0){
            cout<<"day must be between 1 and 30"<<endl;
            cin>>dd;
        }else{
            okday=true;
            Birthday=dd;
        }
        if(mm>12 ||mm<=0){
            cout<<"month must be between 1 and 12"<<endl;
        }else{okmonth=true;
            Birthmonth=mm;
        }
        if(yyyy>2025 ||yyyy<=0){
            cout<<"year must be between 1 and 2025"<<endl;
        }else{okyear=true;
            Birthyear=yyyy;
        }
    }
   }
    // getters
    string getName(){return Name;}
    int getbirthday(){return Birthday;}
    int getbirthmonth(){return Birthmonth;}
    int getbirthyear(){return Birthyear;}     
};
class FictionBook:public Book{};
class Non_FictionBook:public Book{};
class Library:public Book,public Author{};
vector<Book> Library={
        Book("1984", "George Orwell", "9780451524935", "Dystopian", 1949),
    Book("To Kill a Mockingbird", "Harper Lee", "9780060935467", "Fiction", 1960),
    Book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", "Classic", 1925)
};
void addbook(string title,string author,string id,string genre,int year){
    Book Newbook(title,author,id,genre,year);
    Library.push_back(Newbook);
    cout<<"Book added successfully"<<endl;
}
int main(){
    cout<<"Welcome library Management System"<<endl;
    bool exit=false;
    do{
    cout<<"1.add book"<<endl;
    cout<<"2.Display Book Details"<<endl;
    cout<<"3.Search Books By Author"<<endl;        
    cout<<"4.Exit"<<endl;
    int choice;
    cin>>choice;
    while(choice>4||choice<0){
        cout<<"Enter a number between 1 and 4"<<endl;
        cin>>choice;
    }
    if(choice==1){
        string title,author,Id,genre;
        int year;
        cout<<"Title: ";
        cin>>title;
        cout<<endl;
        cout<<"Author: ";
        cin>>author;
        cout<<endl;
        cout<<"Isbn: ";
        cin>>Id;
        cout<<endl;
        cout<<"Genre: ";
        cin>>genre;
        cout<<endl;
        cout<<"Year: ";
        cin>>year;
        cout<<endl;
        addbook(title,author,Id,genre,year);
    }
    if(choice==2){
        bool found=false;
        cout<<"Enter book title you want"<<endl;
        string search;
        cin.ignore();
        getline(cin,search);
        transform(search.begin(),search.end(),search.begin(),::tolower);
        for(int i=0;i<Library.size();i++){
            string Q=Library[i].getTitle();
            transform(Q.begin(),Q.end(),Q.begin(),::tolower);
            if(Q==search){
            Library[i].getbookdetails();
                cout<<"<----------->"<<endl;
                found=true;
                break;
            }
        }
        if(!found){cout<<"book not found"<<endl;}
}
    if(choice==3){
           bool found=false;
        cout<<"Enter book author you want"<<endl;
        string search;
        cin.ignore();
        getline(cin,search);
        transform(search.begin(),search.end(),search.begin(),::tolower);
        for(int i=0;i<Library.size();i++){
            string Q=Library[i].getAuthor();
            transform(Q.begin(),Q.end(),Q.begin(),::tolower);
            if(Q==search){
            cout<<Library[i].getTitle()<<endl;
                cout<<"<----------->"<<endl;
                found=true;
            }
        }
        if(!found){cout<<"author not found"<<endl;}
    }
    if(choice==4){exit=true;}
}while(exit==false);
    return 0;
    }
   // cout << "Library size: " << Library.size() << endl;
    //Library[0].getTitle();
    /*for(Book librarys:Library){
        librarys.getbookdetails();
        cout<<"<------------>"<<endl;
    }*/



    
