#include<bits/stdc++.h>
using namespace std;


int main()
{
//AVLTree obj ;
	int t=0;
	ifstream f;
	f.open("amazon bulk data.txt");
	
	
	char c;
	int k,l=0,m;
	string str,str2,str3 , str4 , str5 , str7;
	if(f){
//		while(getline(f,str2){
		getline(f,str2);
		for(int i=0; i<10 ; i++){
			getline(f,str);
			k=0;
			str2="";
			while(str[k]!='\t'){
				
				str2+=str[k];
				
				k++;
			}
			l=k++;
			
			while ( str[l] != '\t')
			{
				cout << str[l] ;
				str5=str5 + str[l] ;
				l++;
			}
			
			cout << str5 << endl ;
			
			
			
			


			
//			cout << str5 << endl 	;
			

//			while ( str[k] != '\t')
//			{
//				str7 = str7 + str[k] ;
//			}
			
			
//			obj.insert (str2, str5 , str7 );
//			cout << str2 << endl ;
		
		}
		}
}
