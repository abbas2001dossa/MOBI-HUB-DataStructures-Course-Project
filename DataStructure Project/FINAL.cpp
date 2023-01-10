#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h> // sleep
void main_menu ();


using namespace std ;





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
	int count , jump;
	
	Node *root ;
	
	
	AVLTree ()
	{
		count =jump=0;
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
    
    void search ( Node *root , string d , int count  )
    {
    	
        if(root != NULL)
        {
            search(root->left , d , count );
            if (checkword ( root->data, d  ))
            {
			
				if ( count == jump )  // first 3 numbers to be printed only .
    			{
    				
				}
            	else
				{
					jump++;
					cout << "   ~    " << " DESCRIPTION : "  <<endl<<endl<<  root->data  << "\n\n" << " RATING : " << root->ratings << "\n\n" << "PRICE : " << root->price << "\n\n\n\n"    ;
    			}
				        	
			}
    
            search(root->right , d , count );
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
	
	void insertInAVL ()    // iinsert in AVLTREE through filiing
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
			insert(str2 , str3 , str4);
		}
		
		
		
		}
	else{
		cout<<"file couldnt be opened!";
	}
	
	
	
	}
    
};





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

//queue class ! 
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


//hashing vlass !
class hashing{
	int oio=0;
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
			for(int i=1; i<=fLine ; i++){
			
			
				getline(file,str);
			}
			
			jhandodisplay(str);
		}
		}
		
		
		void jhandodisplay(string str){
		int k=0 , l=0 , m =0;
		string str2,str3, str4;
		while(str[k]!='\t'){
				
				str2+=str[k];
				
				k++;
			}
//			cout<<str2;
			l= k+1;
//			cout<<endl;
			str3="";
			while(str[l]!='\t'){
			
//				cout<<" ";
				str3+=str[l];
				l++;
			}
//			cout<<'\t'<< str3 ;
//			cout<<endl;
			str4="";
			 m=l+1;
			while(str[m]!='\0'){
				str4+=str[m];
				m++;
			}
//			cout<<"  "<<str4<<endl;
			cout<<"\n\n------------------------------------------------------------------------\n";
			
			cout<<"	NAME AND DESCRIPTION :			"<<endl<<str2;
			cout<<" \n\n RATINGS :			"<<endl<<str3;
			cout<<"\n\n PRICE :          "<<endl<<str4<<endl;
			cout<<"\n------------------------------------------------------------------------\n";

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
			system("cls");
			cout << "    ::       DISPLAY OF RATING        ::     " << "\n\n\n\n" ;
			
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
			for(int i=1; i<=fLine ; i++){
			
			
				getline(file,str);
			}
			
			jhandodisplay(str);
//			cout<<oio+1 << "  :-    " << str<<"\n\n\n";oio++;
		}
	}
};








class systemmm 
{
	string productName ;
	
	
	public :
	
	systemmm ()
	{
		productName ="" ;
	}
	
	void searchProduct ()
	{	
		
		system("cls");
		cout << "          ::    SEARCH PRODUCT   ::                  " << "\n\n\n\n" ;
		cout << " 1 - SEARCH PRODUCT BY NAME " << "\n\n" ;
		cout << " 2 - SEARCH PRODUCT BY PRICE " << "\n\n" ;
		cout << " 3 - SEARCH PRODUCT BY RATINGS " << "\n\n" ;
		cout << " 4 - GO BACK " << "\n\n" ;
		char ch = getch () ;
		if ( ch == 49 )
		{
			
			searchProductName();
			
		}
		else if ( ch == 50)
		{
			//
			searchProductPrice () ;
		}
		else if ( ch == 51)
		{
			//
			searchProductRatings ();
		}
		else if ( ch == 52 )
		{
			main_menu();
		}
	
			
		
		// by name 
		// by rating 
		// by pricing 
		 
	}
		
		
	void searchProductName ()  //AVL
	{
		system ("cls");
		cout << "         ::  SEARCH PRODUCT NAME ::           " << "\n\n\n\n";
		
		 // object made
		AVLTree  obj ;
		obj.insertInAVL();
		
		string temp ;
		cout << "Enter which Product do you want to search ? " << endl ;
		getline ( cin , temp ) ; 
		obj.search(obj.root , temp  , 5);
		
		
		getch();
		searchProduct ();
		
	}
	
	
	//
	void searchProductPrice ()
	{
		system("cls");
		int min , max ;
		cout << "   ::  SEARCH PRODUCT BY PRICE  ::  " << "\n\n\n\n" ;
		cout << " CHOOSE YOUR BUDGET : " << "\n\n\n" ;
		cout << "ENTER THE MOST MINIMUM VALUE OF PHONE YOU CAN AFFORD : " ;
		cin >> min ;
		cout << "ENTER THE MOST MAXIMUM VALUE OF PHONE YOU CAN AFFORD TO BUY :" ;
		cin >> max ;
		
		hashing obj
		;
		obj.searchbyPricing(max);
		obj.displayOfPricing();
		
		getch();
		searchProduct ();
		
	}
	//
	
	void searchProductRatings ()
	{
		hashing obj;
		
		system("cls");
		cout << "   ::  SEARCH PRODUCT BY RATINGS ::        " << "\n\n\n\n\n" ;
		cout  << " CHOOSE ANY ONE OF THE FOLLOWING RATINGS : " << "\n\n";
		cout << " 1 - 5.0 ratings " <<"\n"<< endl  ;
		cout << " 2 - 4.5 above rating " << "\n"<<endl ;
		cout << " 3 - 4.0 above rating " <<"\n"<< endl ;
		cout << " 4 - 3.5 above rating " <<"\n"<< endl ;
		cout << " 5 - 3 above rating " << "\n"<<endl ;
		cout << " 6 - 2.5 above rating " <<"\n" <<endl ;
		cout << " 7 - GO BACK  " << "\n\n" ;
		char ch = getch() ;
		if ( ch == 49 )
		{
			obj.searchbyRating(5.0);
			obj.displayOfRating();
			getch();
			searchProductRatings ();
		}
		else if ( ch == 50)
		{
			obj.searchbyRating(4.5);obj.displayOfRating();
			
			getch();
			searchProductRatings ();obj.displayOfRating();
		}
		else if ( ch == 51)
		{
			obj.searchbyRating(4.0);obj.displayOfRating();
			getch();
			searchProductRatings ();
		}
		else if ( ch == 52)
		{
			obj.searchbyRating(3.5);obj.displayOfRating();
			getch();
			searchProductRatings ();
		}
		else if ( ch == 53)
		{
			obj.searchbyRating(3.0);obj.displayOfRating();
			getch();
			searchProductRatings ();
		}
		else if ( ch == 54)
		{
			obj.searchbyRating(2.5);obj.displayOfRating();
			getch();
			searchProductRatings ();
		}
		else if ( ch == 55)
		{
			searchProduct() ;
		}
		
		
		
	}

	
		
	void popularProduct ( )
	{
		system("cls");
		cout << "          ::    POPULAR PRODUCTS   ::                  " << "\n\n\n\n" ;
		AVLTree obj ;
		obj.insertInAVL(); // works fine !
		
		cout << "Enter the product company you want to choose : " << endl ;
		cout << "1 - APPLE " << "\n" << endl  ; 
		cout << "2 - SAMSUNG " << "\n"<<endl ; 
		cout << "3 - NOKIA "<<"\n" << endl ;
		cout << "4 - LG " <<"\n"<< endl ;
		cout << "5 - MOTOROLA " <<"\n"<< endl ;
		cout << "6 - ONE PLUS " <<"\n"<< endl ;
		cout << "7 - XIAOMI " <<"\n"<< endl ;
		cout << "8 - EXIT " <<"\n"<<  endl ;
		
		// file opened ! 
	
		char ch = getch ();
		if ( ch == 49)
		{
			// first 3 popular apple products .
			system("cls");
			obj.search(obj.root , "Apple" , 3);
			getch();
			popularProduct(); 
			
		}
		else if ( ch == 50 )
		{
			system("cls");
			obj.search(obj.root , "Samsung Galaxy" , 3);getch();
			popularProduct();
		}
		else if ( ch == 51)
		{
			system("cls");
			obj.search(obj.root , "Nokia" , 3);getch();
			popularProduct();
		}
		else if (ch == 52)
		{
			system("cls");
			obj.search(obj.root , "LG" , 3);getch();
			popularProduct();
		}
		else if ( ch == 53)
		{
			system("cls");
			obj.search(obj.root , "Motorola" , 3);getch();
			popularProduct();
		}
		else if ( ch == 54 )
		{
			system("cls");
			obj.search(obj.root , "OnePlus" , 3);getch();
			popularProduct();
		}
		else if ( ch == 55)
		{
			system("cls");
			obj.search(obj.root , "Xiaomi" , 3);getch();
			getch();
			popularProduct();
		}
		else if (ch == 56 )
		{
			main_menu () ;//exit 
			
		}
			
		
		
		
	}
	
	//only 5 stars
	void ourRecommendations(  )
	{
		system("cls");
		cout << "          ::    RECOMMENDATION PRODUCTS   ::                  " << "\n\n\n\n" ;
		
		hashing obj;
		obj.searchbyRating(5.0);
		obj.displayOfRating();
		
		getch();
		main_menu();
		
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
	
	
	
void main_menu ()
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
			
			obj.searchProduct () ;
			
			break;
		}
		else if ( ch == 50)
		{
		
			obj.popularProduct () ; 
			
			break;
		}
		else if ( ch == 51)
		{
			obj.ourRecommendations () ;
			
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
	  // one object made now this would be manipulated everywhere !
	main_menu() ;
	
	
	hashing obj;
//	obj.searchbyHash(4.5);
//	obj.display();
	
	return 0 ;
}
