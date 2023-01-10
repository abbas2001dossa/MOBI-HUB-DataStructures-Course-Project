#include <iostream>

using namespace std;

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
	
	Node *root ;
	
	
	AVLTree ()
	{
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
        inOrder(root);
//        cout << endl << "Printing in preorder" << endl;
//        preorder(root);
//        cout << endl << "Printing in postorder" << endl;
//        postOrder(root);
    }
	
	Node* search ( Node *root ,  string d)
	{
		
		
		if ( root ==  NULL)
		{
			return root;
		}
		else if ( d > root->data)
		{
			root->right = search ( root->right , d) ;
		}
		else if ( d  < root->data)
		{
			root->left = search ( root->left , d) ;
		}
		else if ( d == root->data)
		{
			cout << " searched " << endl ;
		}
		else{exit(1);
		}
		return root ;
		
	}
    
    
    
};



int main ()
{
	AVLTree obj;
    string array[15] = {"Moto G stylus | 2020 | Unlocked | Made for US by Motorola | 4/128GB | 48MP Camera | Indigo",
					   "Nokia 1.4 | Android 10 (Go Edition) | Unlocked Smartphone | 2-Day Battery | Dual SIM | US Version| 2/32GB | 6.51-Inch Screen | Charcoal",
					   "Moto G Power e 12  ~",
					   "Samsung Galaxy A12 (A125M) 64GB Dual SIM, GSM Unlocked, (CDMA Verizon/Sprint Not Supported) Smartphone Latin American Version No Warranty (Blue)",
					   "OnePlus 8 Glacial Green,​ 5G Unlocked Android Smartphone U.S Version, 8GB RAM+128GB Storage, 90Hz Fluid Display,Triple Camera, with Alexa Built-in",
					   "Moto G stylus | 2020 | Unlocked | Made for US by Motorola | 4/128GB | 48MP Camera | Indigo",
					   "LG Encore Prepaid GoPhone (AT&T)",
					   "Motorola MC659B-PD0BAA00100 HSDPA/CDMA/EVDO, 2D, Camera, Qwerty, GPS, WM6.5",
					   "Samsung Galaxy Note 3 N9005 32GB 4G LTE WHITE Unlocked International Version",
					   "Pixel 4 - Clearly White - 64GB - Unlocked with Amazon.com $200 Gift Card in a Greeting Card",
					   "Samsung Galaxy Express 3 Gophone Prepaid Carrier Locked - 4.5"" - White - J120AZWBATT",
					   "Samsung Ga laxy S6 Edge, Black Sapphire 32GB (Sprint)",
					   "Samsung Galaxy S6 Edge, White Pearl 128GB (AT&T)",
					   "Poco M3 PRO 5G + 4G Volte Global Unlocked GSM 6.5"" Octa Core 48mp Triple Camera (Not Verizon/Boost/CDMA) (Cool Blue, 128GB+6GB)",
					   "Nokia Lumia 930 International Version No Warranty Unlocked Black"
					   
					   
					   
					   };
    int size = sizeof(array) / sizeof(array[0]);
    int i;

    
    for (i = 0; i < 15; i++)
    {
        obj.insert(array[i]);
    }
	
//	obj.search(obj.root ,"Moto G Power e 12  ~" );
  	
    
      
    
    obj.display();
	
}
