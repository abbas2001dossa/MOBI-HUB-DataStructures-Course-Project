#include<bits/stdc++.h>

using namespace std;

int main(){
	
	ifstream f;
	f.open("amazon bulk data.txt");
	
	char c;
	int k,l=0,m=0;
	string str,str2,str3,str4;
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
			cout<<str2;
			l= k+1;
//			cout<<endl;
			str3="";
			while(str[l]!='\t'){
			
//				cout<<" ";
				str3+=str[l];
				l++;
			}
			cout<<'\t'<< str3 ;
//			cout<<endl;
			str4="";
			 m=l+1;
			while(str[m]!='\0'){
				str4+=str[m];
				m++;
			}
			cout<<'\t'<<str4<<endl;
		}
		}
	else{
		cout<<"file couldnt be opened!";
	}
	
	
}
