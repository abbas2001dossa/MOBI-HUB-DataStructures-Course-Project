#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h> // sleep

using namespace std ;
class NodeQ{
	public:
	int data;
	NodeQ* next;
	
	NodeQ(){
		data = 0;
		next = NULL;
	}
	NodeQ(int d){
		data = d;
		next = NULL;
	}
};


class QueueLL{
	NodeQ* front, *rear;
	
	public:
	QueueLL(){
		front = rear = NULL;
	}
	
	bool isEmpty(){
		return (rear == NULL);
	}
		
	void ADDMEMBER(int d){
		NodeQ* temp = new NodeQ(d);
		
	
		if (isEmpty()){
			front = rear = temp;
		}
		else{
			rear->next = temp;
			rear = temp;
		}
	}
	
	int peek(){
		if (isEmpty()){
			return INT_MIN;
		}
		return front->data;
	}
	
	int REMOVEMEMBER(){
		if (isEmpty()){
			return INT_MIN;
		}
		
		
		NodeQ * temp = front;
		front = front->next;
		
		
		if (front == NULL){
			rear = NULL;
		}
		
		delete temp;
	}
	
	
	void display(){
		if (isEmpty())
			return;
		
		cout << "\tdisplaying stack elements:" << endl;
		NodeQ* t = front;
		while(t != NULL){
			cout << t->data << endl;
			t = t->next;
		}
	}
};

class hashing{
	
	public:
		QueueLL obj;//Queue islye banai k records k incdexes store krsakein usko phr access thru file krengy(0-9 wali)
		string filename,str,word;
		string filenumber;
		int fLine,fNo,PriceCount=0,RatingCount=0 ,index,fileprice;
		
		hashing(){
			
		}
		void searchbyPricing(int price){//searching by price, parameter of this function is callled by you dossa.(organization) 
			ifstream file;
			
			file.open("pricing.txt");
			
			if(!file){
				
				cout<< "\nfile errror\n\n";
			}
			else{
				getline(file,str);
				for(int i=1 ; i<=1000 ; i++){
//					file>>str;
					getline(file,str);
					stringstream ss;
					ss<<str;
					ss>>fileprice;
//					cout<<fileprice<<endl;
//					cout<<str<<endl;
//					float fl=::atof(word.c_str());
					if(fileprice<=price){
//						cout<<i<<endl;
						obj.ADDMEMBER(i);
						PriceCount++;
					}
				}
				
			}
			
		}
		void displayOfPricing(){//dipslaying queue me jo indexes store hain unki files open krke unke records 
//			cout<<PriceCount<<endl;
			for(int i=0 ; i<PriceCount ; i++){
			index=obj.peek();
			obj.REMOVEMEMBER();
			fNo=getFileNo(index);
			fLine=getLineNo(index);
			stringstream ss;
			ss<<fNo;
			ss>>filename;
			
			filename+=".txt";
//			cout<<filename<<endl;
			ifstream file;
			file.open(filename);
			for(int i=0; i<=fLine ; i++){
			
			
				getline(file,str);
			}
			
			cout<<str<<endl;
		}
		}
		
		void searchbyRating(float rating){//rating search and adding indexes to queue
			ifstream file;
			file.open("ratings.txt");
			
			if(!file){
				
				cout<< "\nfile errror\n\n";
			}
			else{
				getline(file,str);
				for(int i=1 ; i<=1000 ; i++){
//					file>>str;
					getline(file,str);
					istringstream ss(str);
					ss>>word;
					
//					cout<<word<<endl;
					float fl=::atof(word.c_str());
					if(fl>=rating){
//						cout<<i<<endl;
						obj.ADDMEMBER(i);
						RatingCount++;
					}
				}
				
			}
		}
		
		int getLineNo(int data){//to get line of specific record in a file
			
			return data%100;
		}
		int getFileNo(int data){//to get the file number of record in which it is stored
			
			return data/100;
		}
		
		void displayOfRating(){//same as of pricing bus pricing ki jagah ratings wali files aur chezein agyin

			for(int i=0 ; i<RatingCount ; i++){
			index=obj.peek();
			obj.REMOVEMEMBER();
			fNo=getFileNo(index);
			fLine=getLineNo(index);
			stringstream ss;
			ss<<fNo;
			ss>>filename;
			
			filename+=".txt";
//			cout<<filename<<endl;
			ifstream file;
			file.open(filename);
			for(int i=0; i<=fLine ; i++){
			
			
				getline(file,str);
			}
			
			cout<<str<<endl;
		}
	}
};





int main ()
{
	
	system("Color 0A");
//	main_menu() ;
	
	hashing obj;
	obj.searchbyPricing(90000);
	obj.displayOfPricing();
	return 0 ;
}
