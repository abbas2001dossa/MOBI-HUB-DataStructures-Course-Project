#include<bits/stdc++.h>
using namespace std;


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




int main(){
	
	AVLTree obj ; // putting in AVL tree !
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
			cout<<str2;
			l= k+1;
			str3="";
			while(str[l]!='\t'){
			
				str3+=str[l];
				l++;
			}
			cout<<'\t'<< str3 ;
			str4="";
			 m=l+1;
			while(str[m]!='\0'){
				str4+=str[m];
				m++;
			}
			cout<<'\t'<<str4<<endl;
			obj.insert(str2 , str3 , str4);
		}
		
		
		
		}
	else{
		cout<<"file couldnt be opened!";
	}


	string te ;
	cout << "Enter product : " << endl ;
	getline ( cin , te) ;
	
	obj.search(obj.root ,  te);
	
	

	
	
}
