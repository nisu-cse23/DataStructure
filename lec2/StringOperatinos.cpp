#include<iostream>
#include<string>

using namespace std;

int main(){
    string str,substr,newstr;
    int position,length;

    cout<< "Enter a string:";
    getline(cin,str);

    //Task1:Length of the string
    int lengthString=str.length();
    cout<<"The length of the string : "<< lengthString<<endl;

    //Task2:Substring
    cout<<"Enter the staring position:";
    cin >> position;
    cout << "Enter the length of substring:";
    cin>> length;

    string substring=str.substr(position,length);
    if(position>=0 && position< str.length()){
        cout<<"Substring:"<<substring<<endl;
    }
    else{
        cout<<"Invalid position"<<endl;
    }

    //Task3:Indexing
   cout << "Enter the position of the character to access: ";
   cin >> position;
   if (position >= 0 && position < str.length()) {
    char character = str[position]; 
    cout << "Character at position " << position << ": " << character << endl;
   } 
   else {
    cout << "Invalid position!" << endl;
}
   
    //Task4:Concatenation
    cout<<"Enter another string to concatenate: "<<endl;
    cin.ignore();//To clear the input buffer
    getline(cin,substr);
    string con=str+substr;
    cout<<"Concatenated String:"<<con<<endl;
    
  //Task5:Insertion
  cout<<"Enter the string to insert:";
  getline(cin,substr);

  cout<<"Enter the position to insert the string:";
  cin>>position;

  if(position>=0 && position<str.length()){
     newstr=str;
     newstr.insert(position,substr);

    cout<<"String after deletion:"<<newstr<<endl;
  }
  else{
    cout<<"Invalid position"<<endl;
  }

//Task6:Deletion
cout<<"Enter the starting position to delete:";
cin>>position;

cout<<"Enter the length of the portion to replace:";
cin>>length;
if(position>=0 && position<str.length()){
newstr=str;
newstr.erase(position,length);

    cout<<"String after deletion:"<<newstr<<endl;
}
else{
    cout<<"Invalid position"<<endl;
}

//Task7:Replacement
cout<<"Enter the starting position to replace:";
cin>>position;

cout<<"Enter the length of the portion to replace:";
cin>>length;

cout<<"Enter the new string to replace with:";
cin.ignore();
getline(cin,substr);

if(position>=0 && position+length<=str.length()){
newstr=str;
newstr.replace(position,length,substr);

    cout<<"String after replacement: "<<newstr<<endl;
}
else{
    cout<<"Invalid position or length!"<<endl;

}
return 0;
}