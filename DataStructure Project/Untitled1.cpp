#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h> // sleep
void main_menu ();


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
		QueueLL obj;
		string filename,str,word;
		string filenumber;
		int fLine,fNo,k,index;
		
		hashing(){
			
		}
	
		void searchbyHash(float rating){//rating search and adding indexes to queue
			ifstream file;
			file.open("ratings.txt");
			
			if(!file){
				
				cout<< "\nfile errror\n\n";
			}
			else{
				getline(file,str);
				for(int i=1 ; i<=10 ; i++){
//					file>>str;
					getline(file,str);
					istringstream ss(str);
					ss>>word;
					
					cout<<word<<endl;
					float fl=::atof(str.c_str());
					if(fl>=rating){
//						cout<<i<<endl;
						obj.ADDMEMBER(i);
						k++;
					}
				}
				
			}
		}
		
//		float convertStringToFLoat ( string str )
//		{
//			float temp = ::atof(str.c_str());
//			return temp;
//		}
		
		int getLineNo(int data){
			
			return data%100;
		}
		int getFileNo(int data){
			
			return data/100;
		}
		void display(){
			for(int i=0 ; i<k ; i++){
			index=obj.peek();
			obj.REMOVEMEMBER();
			fNo=getFileNo(index);
			fLine=getLineNo(index);
			stringstream ss;
			ss<<fNo;
			ss>>filename;
			
			filename+=".txt";
			
			ifstream file;
			file.open(filename);
			for(int i=0; i<=fLine ; i++){
			
			
				getline(file,str);
			}
			
			cout<<str<<endl;
		}
}
};




// AVL TREE ! 
class Node
{
public:
    string data;
    string price ;
    string ratings ;
    
    
    Node *left;
    Node *right;
    int height;

    Node()
    {
        data= ratings = price  = "";
        left = right = NULL;
        height = 1;
    }

    Node( string d , string ratings , string price )
    {
        data = d;
        this->ratings=ratings ;
        this->price=price ;
        
        left = right = NULL;
        height = 1;
    }
};


class AVLTree
{
	
public :
	int count ;
	
	Node *root ;
	
	
	AVLTree ()
	{
		count =0;
		root=NULL ;
    }   
    
    Node *insert(Node *leaf, string d , string ratin , string price)
    {
        if (leaf == NULL)
        {
            leaf = new Node(d , ratin , price );
            return leaf;
        }

        if (d < leaf->data)
        {
            leaf->left = insert(leaf->left, d , ratin , price);
        }

        else if (d > leaf->data)
        {
            leaf->right = insert(leaf->right, d , ratin , price );
        }

        else
        {
            return leaf;
        }

        leaf->height = heightCalculator(leaf);

        int balanceFactor = balanceFactorCalculator(leaf);

        if (balanceFactor > 1 && d < leaf->left->data)
            return rightRotation(leaf);

        if (balanceFactor < -1 && d > leaf->right->data)
            return leftRotation(leaf);

        if (balanceFactor < -1 && d < leaf->right->data)
        {
            leaf->right = rightRotation(leaf->right);
            return leftRotation(leaf);
        }

        if (balanceFactor > 1 && d > leaf->left->data)
        {
            leaf->left = leftRotation(leaf->left);
            return rightRotation(leaf);
        }

        return leaf;
    }
    

	int heightCalculator(Node *leaf)
    {
        int leftHeight, rightHeight;
        if (leaf == NULL)
        {
            return -1;
        }

        else
        {
            leftHeight = heightCalculator(leaf->left);
            rightHeight = heightCalculator(leaf->right);

            if (leftHeight > rightHeight)
            {
                return leftHeight + 1;
            }
            return rightHeight + 1;
        }
    }

    int balanceFactorCalculator(Node *leaf)
    {
        if (leaf == NULL)
        {
            return -1;
        }

        return heightCalculator(leaf->left) - heightCalculator(leaf->right);
    }

    Node *leftRotation(Node *leaf)
    {
        Node *temp1 = leaf->right;
        Node *temp2 = temp1->left;

        temp1->left = leaf;
        leaf->right = temp2;

        temp1->height = heightCalculator(temp1);

        return temp1;
    }

    Node *rightRotation(Node *leaf)
    {
        Node *temp1 = leaf->left;
        Node *temp2 = temp1->right;

        temp1->right = leaf;
        leaf->left = temp2;

        temp1->height = heightCalculator(temp1);

        return temp1;
    }

    void insert(string data , string ratin , string price)
    {
        root = insert(root, data , ratin , price);
    }

    void display()
    {
        cout << endl << "Printing in inorder" << endl;
        fflush(stdin);
        inOrder(root);
   
    }

    void inOrder(Node *leaf)
    {
        if(leaf != NULL)
        {
            inOrder(leaf->left);
            cout << leaf->data << endl;
            inOrder(leaf->right);
        }
    }
    
    void search (Node *leaf , string d )
    {
        if(leaf != NULL)
        {
            search(leaf->left , d);
            if (checkword ( leaf->data, d ))
            {
            	cout << count+1 << " : " << " DESCRIPTION : "  <<  leaf->data  << endl << " RATING : " << leaf->ratings << endl << "PRICE : " << leaf->price << endl    ;count++;
    			return ;        	
			}
    
            search(leaf->right , d);
        }
    }
    
    
    bool checkword ( string description  , string word)
    {
    	int k = description.find(word) ;
    	if ( k > -1)
    	{
    		return true ;
		}
		
		
		return false ;
	}
    
};

AVLTree insertInAVL ( AVLTree  obj)
{
	 // putting in AVL tree !
	int t=0;
	ifstream f;
	f.open("amazon bulk data.txt");
	
	char c;
	int k,l=0,m=0;
	string str,str2,str3,str4;
	if(f){
		getline(f,str2);
		for(int i=0; i<1000; i++){
			getline(f,str);
			k=0;
			str2="";
			while(str[k]!='\t'){
				
				str2+=str[k];
				
				k++;
			}
//			cout<<str2;
			l= k+1;
			str3="";
			while(str[l]!='\t'){
			
				str3+=str[l];
				l++;
			}
//			cout<<'\t'<< str3 ;
			str4="";
			 m=l+1;
			while(str[m]!='\0'){
				str4+=str[m];
				m++;
			}
//			cout<<'\t'<<str4<<endl;
			obj.insert(str2 , str3 , str4);
		}
		
		
		
		}
	else{
		cout<<"file couldnt be opened!";
	}
	
	
	return obj;
}

class systemmm 
{
	string productName ;
	
	
	public :
	
	systemmm ()
	{
		productName ="" ;
	}
	
	void searchProduct (AVLTree obj )
	{	
		
		system("cls");
		cout << "          ::    SEARCH PRODUCT   ::                  " << "\n\n\n\n" ;
			
		searchProductName(obj);
		// by name 
		// by rating 
		// by pricing 
		
		
		
		
		 
	}
		
		
	void searchProductName ( AVLTree obj)  //AVL
	{
		system ("cls");
		cout << "         ::  SEARCH PRODUCT NAME ::           " << "\n\n\n\n";
		
		 // object made
		
		string temp ;
		cout << "Enter which Product do you want to search ? " << endl ;
		getline ( cin , temp ) ; 
		obj.search(obj.root , temp );
		
	}
	
	void searchProductReview ()
	{
		system("cls");
		
	}
	
	void searchProductRatings ()
	{
		system("cls");
		
	}

	
		
	void popularProduct ( AVLTree obj )
	{
		system("cls");
		cout << "          ::    POPULAR PRODUCTS   ::                  " << "\n\n\n\n" ;
		
		cout << "Enter the product company you want to choose : " << endl ;
		cout << "1 - APPLE " << "\n" << endl  ; 
		cout << "2 - SAMSUNG " << "\n"<<endl ; 
		cout << "3 - NOKIA "<<"\n" << endl ;
		cout << "4 - LG " <<"\n"<< endl ;
		cout << "5 - MOTOROLA " <<"\n"<< endl ;
		cout << "6 - ONE PLUS " <<"\n"<< endl ;
		cout << "7 - POCO " <<"\n"<< endl ;
		cout << "8 - EXIT " <<"\n"<<  endl ;
		
		// file opened ! 
		
		
		
		
		
		char ch = getch ();
		if ( ch == 49)
		{
			// first 3 popular apple products .
			 
			
		}
		else if ( ch == 50 )
		{
			
		}
		else if ( ch == 51)
		{
			
		}
		else if (ch == 52)
		{
			
		}
		else if ( ch == 53)
		{
			
		}
		else if ( ch == 54 )
		{
			
		}
		else if ( ch == 55)
		{
			
		}
		else if (ch == 56 )
		{
			main_menu () ;//exit 
			
		}
		
		
		
		
//			cout << str2 << endl ;
		
			
		
		
		
	}
	
	
	void ourRecommendations( AVLTree obj )
	{
		system("cls");
		cout << "          ::    RECOMMENDATION PRODUCTS   ::                  " << "\n\n\n\n" ;
		
//		cin >> recProduct ;
		
	}
	
	
};


void us ()
	{
		system ("cls");
		int count ;
		for(count = 0;count<1;count++)
		{
			Sleep(50);
			cout << "\n\n\n\n" ;
			Sleep(50);
			cout << "|-----------------------------------------------------------------|" << endl ;
			Sleep(50);
			cout << "|                		MOBI-HUB			                       |" << endl ;
			Sleep(50);
			cout << "|                                                                 |" << endl ;
			Sleep(50);
			cout << "|                ABBAS DOSSA 20K-1660         	                   |" << endl ;
			Sleep(50);
			cout << "|                UMER FAROOQ 20K-1625 		                       |" << endl ;
			Sleep(50);
			cout << "|                LAIBA ZUBAIR 20K-0258                            |" << endl ;
			Sleep(50);
			cout << "|-----------------------------------------------------------------|" << endl ;
			Sleep(50);
			cout << "\n\n\n\n" ;
		}
	}
	
	
	
void main_menu (AVLTree obj2)
{
	
	us();
	getch();
	system("cls");
	cout << "\t" <<  " :: MAIN MENU :: " << "\t" ;
	cout << "\n\n" ;
		cout <<" 1. Search Product :  "  << endl ;
		cout << "\n\n" ;
		cout <<" 2. Popular products : " << endl ;
		cout << "\n\n" ;
		cout << " 3. Our Recommendations : " << endl ;
		cout << "\n\n" ;
		cout << " 4. EXIT " << endl;
		char ch;
		systemmm obj;
		while (1)
		{
			
		ch= getch();
		if ( ch == 49) 
		{
			
			obj.searchProduct (obj2) ;
			
			break;
		}
		else if ( ch == 50)
		{
		
			obj.popularProduct (obj2) ; 
			
			break;
		}
		else if ( ch == 51)
		{
			obj.ourRecommendations (obj2) ;
			
			break ;
		}
		else if ( ch == 52)
		{
			exit(1);
		}
		
		}
	
	
}

int main ()
{
	
	system("Color 0A");
	
	
	AVLTree oj;
	insertInAVL (oj) ;  // one object made now this would be manipulated everywhere !
	main_menu(oj) ;
	
	
	hashing obj;
//	obj.searchbyHash(4.5);
//	obj.display();
	
	return 0 ;
}
