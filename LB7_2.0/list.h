
#pragma warning(disable: 4996)
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
extern int length=0;
class Clist{
		struct list{
        int value;
        struct list *next;
    };
    struct list *head;
  //  int length;
public:
    Clist() {
	head=nullptr;
	length=0;
	};
    ~Clist() {ReleaseList();};
    void AddItem(int value);
    void DisplayList();
    void ReleaseList();
    bool DeleteFirstNotOdd();
    friend ostream& operator<<(ostream &out, Clist &obj);
	friend istream& operator>>(istream &in, Clist &obl);
	Clist& operator = (Clist &obj){
		list *temp = obj.head;
		while(temp != nullptr){
			AddItem(temp -> value);
			temp = temp -> next;
		}
	return *this;
	}
};

template<typename T>
class CList{
	typedef struct list{
        T value;
		list *next;
    };
    list *first, *head;
   
public:
    CList(){
	head=NULL;
	
	};
    ~CList(){
		ReleaseList();
	}
    void AddItem(T &value);
    void DisplayList();
    void ReleaseList();
    bool DeleteFirstNotOdd();
    template <typename T1>
    friend ostream& operator<<(ostream &out, CList<T1> &obj);
};

template<typename T>
void CList<T>::AddItem(T &item){
	struct list *new_item;
	new_item = new struct list;
	new_item->value=item;
	new_item->next=NULL;
	if(head==NULL){
		head=new_item;
	}
	else{
		struct list *current=head;
		while(current->next){
			current=current->next;
		}
		current->next=new_item;
	}
}


void CList<char*>::AddItem(char* &item){
	struct list *new_item;
	new_item = new struct list;
	new_item->value=item;
	new_item->next=NULL;
	if(head==NULL){
		head=new_item;
	}
	else{
		struct list *current=head;
		while(current->next){
			current=current->next;
		}
		current->next=new_item;
	}
}
	

void Clist::AddItem(int value){
    struct list *newItem = new struct list;
    newItem -> value = value;
    newItem -> next = head;
    head = newItem;
    length++;
}

template<typename T>
void CList<T>::DisplayList(){
    struct list *node = head;
    while (node != nullptr){
        std::cout << node -> value << " -> ";
        node = node -> next;
    }
    std::cout << "null\n";
}

void Clist::DisplayList(){
    struct list *node = head;
    while (node != nullptr){
        std::cout << node -> value << " -> ";
        node = node -> next;
    }
    std::cout << "null\n";
}

template<typename T>
void CList<T>::ReleaseList(){
    struct list *previous;
    while (head){
        previous = head;
        head = head -> next;
        delete previous;
    }
    length = 0;
}


void Clist::ReleaseList(){
    struct list *previous;
    while (head){
        previous = head;
        head = head -> next;
        delete previous;
    }
    length = 0;
}


template <>
void CList<char*>::ReleaseList(){
    struct list *previous;
    while (head){
        previous = head;
        head = head -> next;
        delete previous -> value, previous;
    }
    
}

template<typename T>
bool CList<T>::DeleteFirstNotOdd(){
	 struct list *current=head;
	 struct list *previous=NULL;
	 do{
		 if(fmod(current->value,2) == 0.0){
			 if (previous){
				 previous->next=current->next;
			 }
			 else{
				 head=current->next;
			 }
			delete(current);
			DisplayList();
			return true;
		 }
		 previous = current;
		 current=current->next;
	 }while(current->next);
	 return false;	 
}

template<>
bool CList<Clist>::DeleteFirstNotOdd(){
	 struct list *current=head;
	 struct list *previous=NULL;
	 do{
		 if(length%2==0){
			 if (previous){
				 previous->next=current->next;
			 }
			 else{
				 head=current->next;
			 }
			delete(current);
			DisplayList();
			return true;
		 }
		 previous = current;		 
		 current=current->next;
	 }while(current->next);
	 return false;
}

template <>
bool CList<char*>::DeleteFirstNotOdd(){
	 struct list *current=head;
	 struct list *previous=NULL;
	 do{
		 if(strlen(current->value)%2 == 0){
			 if (previous) {
				 previous->next=current->next;
			 }
			 else{
				 head=current->next;
			 }
			delete(current);
			DisplayList();
			return true;
		 }
		 previous = current;
		 current=current->next;
	 }while(current->next);
	 return false;
}

template<typename T1>
ostream& operator<< (ostream &out, CList<T1> &obj){
    obj.DisplayList();
    return out;
}

ostream& operator<< (ostream &out, Clist &obj){
    obj.DisplayList();
    return out;
}

istream& operator>> (istream &out, Clist &obj){	
	int i, key;
	do{
		cout<<"¬ведите число:"<<endl;
		cin>>i;
		obj.AddItem(i);
		key=_getch();
	}
	while(key!=27);	
	return out;
}