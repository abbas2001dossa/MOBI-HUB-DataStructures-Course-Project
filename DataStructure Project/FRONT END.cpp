#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h> // sleep

using namespace std ;




class Node
{
public:
    string data;
    Node *left;
    Node *right;
    int height;

    Node()
    {
        data = "";
        left = right = NULL;
        height = 1;
    }

    Node( string d)
    {
        data = d;
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
    
    Node *insert(Node *leaf, string d)
    {
        if (leaf == NULL)
        {
            leaf = new Node(d);
            return leaf;
        }

        if (d < leaf->data)
        {
            leaf->left = insert(leaf->left, d);
        }

        else if (d > leaf->data)
        {
            leaf->right = insert(leaf->right, d);
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
    
    
 	void preorder(Node *leaf)
    {
        if (leaf != NULL)
        {
            cout << leaf->data << " ";
            preorder(leaf->left);
            preorder(leaf->right);
        }
    }

    void postOrder(Node *leaf)
    {
        if(leaf != NULL)
        {
            postOrder(leaf->left);
            postOrder(leaf->right);
            cout << leaf->data << " ";
        }
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

    Node *inorderSuccessor(Node *leaf)
    {
        Node *current = leaf;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *leaf, string d)
    {
        if (leaf == NULL)
        {
            return leaf;
        }

        if (d < leaf->data)
        {
            leaf->left = deleteNode(leaf->left, d);
        }

        else if (d > leaf->data)
        {
            leaf->right = deleteNode(leaf->right, d);
        }

        else
        {
            if (leaf->left == NULL && leaf->right == NULL)
            {
                delete leaf;
                return NULL;
            }

            else if (leaf->left == NULL)
            {
                Node *temp = leaf->right;
                delete leaf;
                return temp;
            }

            else if (leaf->right == NULL)
            {
                Node *temp = leaf->left;
                delete leaf;
                return temp;
            }

            else
            {
                Node *temp = inorderSuccessor(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
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

    void insert(string data)
    {
        root = insert(root, data);
    }

    void display()
    {
        cout << endl << "Printing in inorder" << endl;
        fflush(stdin);
        inOrder(root);
   
    }

    
    void search (Node *leaf , string d )
    {
        if(leaf != NULL)
        {
            search(leaf->left , d);
            if (checkword ( leaf->data, d ))
            {
            	cout << count+1 << " : " <<  leaf->data << endl   ;count++;
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
			
		searchProductName();
		
		
		
		
		 
	}
		
		
	void searchProductName ()  //AVL
	{
		system ("cls");
		fflush(stdin);
		
		cout << "Enter product name :   "  ;
		getline ( cin , productName) ;
		
		AVLTree obj ;
		int t=0;
		
		ifstream f;
		f.open("amazon bulk data.txt");
	
		char c;
		int k;
		string str,str2;
		if(f){
			getline(f,str2);
			for(int i=0; i<1000 ; i++){
				getline(f,str);
				k=0;
				str2="";
				while(str[k]!='\t'){
				
					str2+=str[k];
				
					k++;
				}
			
				obj.insert (str2);t++;
				fflush(stdin);
//			cout << str2 << endl ;
		
			}
		}
		else{
			cout<<"file couldnt be opened!";
		}
		fflush (stdin) ;
	
		obj.search(obj.root ,  productName);
		
	}
	
	void searchProductReview ()
	{
		system ("cls");
		cout << "    ::   SEARCH PRODUCT BY REVIEW   ::      " << "\n\n\n" ;
		
	}
	
	void searchProductRatings ()
	{
		//
	}
	
		
	void popularProduct ()
	{
		system("cls");
		cout << "          ::    POPULAR PRODUCT   ::                  " << "\n\n\n\n" ;
		
//		cin >> popProduct ;
		
	}
	
	
	void ourRecommendations()
	{
		system("cls");
		cout << "          ::    RECOMMENDTION PRODUCT   ::                  " << "\n\n\n\n" ;
		
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
	main_menu() ;
	
	
	
	return 0 ;
}
