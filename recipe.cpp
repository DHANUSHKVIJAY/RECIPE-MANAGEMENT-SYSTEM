#include <iostream>
#include "recipe.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {
system("color 03");
    
int outerChoice = 0;
while(outerChoice!=9){
    system("cls");
    cout<<"\n Recipe Management System\n\n";
    cout<<"\n================================\n\n";
	cout<<"\n    WELCOME TO REAL TASTE\n\n";
	cout<<"\n--------------------------------\n\n";
    cout<<"\n1. Admin";
    cout<<"\n2. User";
    cout<<"\n9. Exit";
    cout<<"\n\n--------------------------------";
    cout<<"\n\nEnter your choice : ";
    cin>>outerChoice;
    
    if( outerChoice == 1 )
    {
    char adminUser[10];
    char adminPassword[10];
    
    system("cls");
    cout<<"\n================================\n";
    cout<<"\n ------- ADMIN LOGIN -------\n";
    cout<<"\n================================\n\n";
    cout<<"\n\n Enter username: ";
    cin>>adminUser;
    cout<<"\n Enter password:";
    cin>>adminPassword;
    if( (strcmp(adminUser, ADMINUSER) == 0) && 
        ( strcmp(adminPassword, ADMINPASSWORD) == 0)){
        
    getchar(); getchar();
    system("cls");
    int innerChoice = 0;
    while(innerChoice != 9){
    cout<<"\n     Logged In as Admin !!";  
    cout<<"\n================================\n";
    cout<<"\n ------------ MENU ------------ \n";
    cout<<"\n================================\n\n";
    cout<<"\n1. Add Recipe";
    cout<<"\n2. Update Recipe ";
    cout<<"\n3. Delete Recipe ";
    cout<<"\n4. Display Recipe ";
    cout<<"\n5. Search Recipe By ID";
    cout<<"\n6. Search Recipe By Name";
    cout<<"\n9. Exit";
    cout<<"\n\n Enter your choice : ";
    cin>>innerChoice;
        switch(innerChoice){
        case 1: addRecipe(); break;
        case 2: updateRecipe(); break;
        case 3: deleteRecipe(); break;
        case 4: displayRecipe(); break;
        case 5: searchRecipe(); break;
        case 6: searchRecipeName(); break;
        default: cout<<"\n\n Invalid Choice. Press any key to continue..";
                 getchar();
    }
    system("cls");
    }
                    
    }
    else
    {
    cout<<"\n\n Error : Invalid Credentials. Press any key to conitnue";
    getchar();getchar();
    }
                    
    }
    else if(outerChoice ==2) {              
        char User[10];
        char Password[10];
            
        system("cls");
        cout<<"\n================================\n";
        cout<<"\n --------- USER LOGIN ---------\n";
        cout<<"\n================================\n\n";
        cout<<"\n\n Enter username: ";
        cin>>User;
        cout<<"\n Enter password:";
        cin>>Password;
            
        if( (strcmp(User, USER) ==0)  && 
            (strcmp(Password, USERPASSWORD) == 0)){
        int innerChoice = 0;
        while(innerChoice != 9){
        system("cls");
        	cout<<"\n     Logged In as User!!!";
			cout<<"\n================================\n";
			cout<<"\n ------------ MENU ------------ \n";
			cout<<"\n================================\n\n";
            cout<<"\n1. Display Recipe";
            cout<<"\n2. Search Recipe By ID";
            cout<<"\n3. Search Recipe By Name";
            cout<<"\n4. Open Recipe";
            cout<<"\n9. Exit";  
        cout<<"\n\n Enter your choice : ";
        cin>>innerChoice;   
        
        switch(innerChoice){
        case 1: displayRecipe();break;
        case 2: searchRecipe();break;
        case 3: searchRecipeName();break;
        case 4: open_recipe();break;
        case 9: break;
        default: cout<<"\n\n Error: Invalid Choice. Press any key to continue..";
        getchar();getchar();
            
        }
                
        }
        system("cls");
        }
        else
        {
        cout<<"\n\n Error : Invalid Credentials. Press any key to conitnue";
        getchar();getchar();
            
        }
    }
    else if(outerChoice!=9){
        cout<<"\n\n Invalid choice. Press any key to continue..";
        getchar();getchar();
    }
    else
    {
        cout<<"\n\n Thank you for using REAL TASTE !! Press any key to exit";
        getchar();getchar();
    }


}
return 0;
}

int addRecipe()
{
    system("cls");
    fstream file;
    int recipeid;
    string recipename;
    string category;
 
    cout << "\n\n\t\t\t\tADD RECIPE";
    cout << "\n\n Recipe ID : ";
    cin >> recipeid;
    cout << "\nRecipe Name : ";
    cin >> recipename;
    cout << "\nCategory : ";
    cin >> category;

  
    file.open("D:// recipe.txt",
              ios::out | ios::app);
    file << " " << recipeid << " "
         <<recipename << " " << category << "\n";
 
    file.close();
    return 0;
}

int deleteRecipe(){


    system("cls");
    fstream file, file1;
    int count = 0;
    int recipeid,recipeidd;
    string recipename;
    string category;
    cout << "\n\n\t\t\t\tDelete a Recipe";
  
    file1.open("D:// recipe1.txt",
               ios::app | ios::out);
    file.open("D:// recipe.txt",
              ios::in);
  
    if (!file)
        cout << "\n\nFile Opening Error...";
    else {
  
        cout << "\n\nRecipe ID : ";
        cin >> recipeid;
        file >> recipeidd >> recipename;
        file >> category; 
        while (!file.eof()) {
  
            if (recipeid == recipeidd) {
  
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Delete a Recipe";
                cout << "\n\n Recipe is Deleted "
                        "Successfully...\n\n";
                count++;
            }
            else
                file1 << " " << recipeidd
                      << " " << recipename
                      << " " << category
                      << "\n\n";
            file >> recipeidd >> recipename;
            file >> category;
        }
        if (count == 0)
            cout << "\n\n Recipe ID "
                 << "Not Found...";
    }
    system("pause");
  
   
    file.close();
    file1.close();
    remove("D:// recipe.txt");
    rename("D:// recipe1.txt",
           "D:// recipe.txt");

  return 0; 
    
}

int updateRecipe()

{
    system("cls");
    fstream file, file1;
    int count = 0;
    int recipeid,recipeidd;
    string recipename,rname;
    string category,rcategory;
    
    cout << "\n\n\t\t\t\tUpdate Recipe Record";
    file1.open("D:// recipe1.txt",
               ios::app | ios::out);
    file.open("D:// recipe.txt", ios::in);
  
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
  
        cout << "\n\nRecipe ID : ";
        cin >> recipeid;
        file >> recipeidd >> recipename;
        file >> category; 
  
        while (!file.eof()) {
            if (recipeid == recipeidd) {
                system("cls");
                cout << "\t\t\t\t"
                     << "Update Recipe Record";
                cout << "\n\nNew Recipe Name : ";
                cin >> rname;
                cout << "\nCategory : ";
                cin >> rcategory;
                
                file1 << " " << recipeid << " "
                      << rname << " "
                      << rcategory 
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << recipeidd
                      << " " << recipename
                      << " " << category
                      << "\n\n";
            file >> recipeidd >> recipename;
            file >> category;
        }
        if (count == 0)
            cout << "\n\nRecipe ID"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");
  
    file.close();
    file1.close();
    remove("D:// recipe.txt");
    rename("D:// recipe1.txt",
           "D:// recipe.txt");
    return 0;
}   
    


int displayRecipe(){

{
    system("cls");
    fstream file;
    int recipeid;
    string recipename;
    string category;
    cout << "\n\n\t\t\t\t\tAll  Recipes";
    file.open("D:// recipe.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
  
        cout << "\n\n\nRecipe ID\t\tRecipe Name"
             << "\t\tCategory"
                "\n\n";
        file >> recipeid >> recipename;
        file >> category; 
  
        while (!file.eof()) {
  
            cout << "  " << recipeid
                 << "\t\t\t" << recipename
                 << "\t\t\t" << category
                 << "\n\n";
            file >> recipeid >> recipename;
            file >> category; 
        }
  
        system("pause");
  
        file.close();
    }
}
    
   return 0;    
}

int searchRecipe()
{
    {
    system("cls");
    fstream file;
    int  count = 0;
    int recipeid ,recipeidd;
    string recipename;
    string category;
    cout << "\n\n\t\t\t\tCheck "
         << "Particular Recipe";
  
    // Open the file in input mode
    file.open("D:// recipe.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
  
        cout << "\n\nRecipe ID : ";
        cin >> recipeidd;
        file >> recipeid >> recipename;
        file >> category;
  
        while (!file.eof()) {
  
            if (recipeidd == recipeid) {
  
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Recipe";
                cout << "\n\nRecipe ID : "
                     << recipeid;
                cout << "\n Recipe Name : "
                     << recipename;
                cout << "\nCategory: "
                     << category;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> recipeid >> recipename;
            file >> category;
        }
        
        if (count == 0)
            cout << "\n\nRecipe ID Not"
                 << " Found...";
    }
    system("pause");
    file.close();
}
 
    return 0;
}


int searchRecipeName()
{
    {
    system("cls");
    fstream file;
    int  count = 0;
    int recipeid ,recipeidd;
    string recipename,rname;
    string category;
    cout << "\n\n\t\t\t\tCheck "
         << "Particular Recipe";
  
    // Open the file in input mode
    file.open("D:// recipe.txt", ios::in);
    if (!file)
        cout << "\n\nFile Opening Error!";
    else {
  
        cout << "\n\nRecipe Name : ";
        cin >> rname;
        file >> recipeid >> recipename;
        file >> category;
  
        while (!file.eof()) {
  
            if (rname == recipename) {
  
                system("cls");
                cout << "\n\n\t\t\t\t"
                     << "Check Particular Recipe";
                cout << "\n\nRecipe ID : "
                     << recipeid;
                cout << "\n Recipe Name : "
                     << recipename;
                cout << "\nCategory : "
                     << category;
                cout << endl
                     << endl;
                count++;
                break;
            }
            file >> recipeid >> recipename;
            file >> category;
        }
        
        if (count == 0)
            cout << "\n\nRecipe Name Not"
                 << " Found...";
    }
    system("pause");
    file.close();
}
  
   return 0;    
}


int open_recipe()
{ 
	ifstream in;
	char filename[20];
	cout<<"Enter the recipe you want to learn: ";
	cin>>filename;
 
	in.open(filename);
	if(!in) 
	{
   	 cout << "Cannot Open Recipe. Or Recipe Not Found\n";
   	 return 1;
	}

	char str[1000];
	cout<<"\n======================================================================================================================================================================\n\n";
  
	while(in) 
	{
   	 in.getline(str, 1000);
   	 if(in) 
	 cout << str << endl;
	}

	cout<<"\n\n=====================================================================================================================================================================\n";
   system("pause");
   in.close();

  return 0;
}


int adminLogin(){
    
    return 0;
    
}

int userLogin(){

 return 0;
}
