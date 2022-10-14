//i forgot which headers are essential, so i guess they all are

#include <iostream>
#include <unistd.h> 
#include <fstream>
#include <ctime>

//also cant remember whats important
std::string login;
std::string user;
std::string accNum;
std::string aaccNum;
std::string accBal;
std::string lname;
std::string llname;
std::string fname;
int comm;
std::string n;
std::string fn = "First Name: ";
std::string ln = "Last Name: ";
std::string ab = "Account Balance ($): ";
std::string an = "Account Number: ";
std::string sc = (lname + accBal + ".txt");
std::string notimportant;
std::string usn;

//generates new account record
void newAcc()
{
  //since this is an admin function, it requires admin credentials
  std::cout << "ENTER UID: ";
  std::cin >> usn;
  if (usn == "0000")
  {
  //this block checks for the existence of a record with the same name
  std::cout << "\x1B[2J\x1B[H";
  std::cout << "++COLLISION CHECK. INPUT ACCOUNT DATA++"<<std::endl;
  std::cout<<"Enter last name of account holder: ";
  std::cin>>lname;
  std::cout<<"Enter account number: ";
  std::cin>>accNum;
  
  std::ifstream inf{ lname + accNum + ".txt"};
  if (inf)//<uses fstream's input function to check for file names and prevent name collisions
  {
    std::cout << "\x1B[2J\x1B[H";
    std::cout<<"--ERROR - ACCOUNT IDENTIFIER ALREADY EXISTS--"<<std::endl;
  }
  if (!inf){
  // gets current time and date
   time_t now = time(0);
   
   // converts time and date to string
   char* dt = ctime(&now);



   // writes date and time to record
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
  std::cout << "\x1B[2J\x1B[H";
  std::cout<<"--DOMAIN AVAILABLE--"<<std::endl;
  n = "\n";
  //writes record
  std::cout<<"Set new account's legal first name: ";
  std::cin>>fname;
  std::cout<<"Set new account's legal last name: ";
  std::cin>>lname;
  std::cout<<"Set account number: ";
  std::cin>>accNum;
  std::cout<<"Set initial account balance ($): ";
  std::cin>>accBal;
  std::ofstream outf{ lname + accNum + ".txt", std::ios::app };
  if (!outf)
  {
    std::cerr<<"File could not be opened.";
  }
  //I added some nice borders so each record entry is more readable
  outf<<" " + n;
  outf<<"+----------------------------------------------+  ";
  outf<<dt + n;
  //this annotates the record with the current user and time
  outf<<"CREATED BY: " + user + n;
  outf<<" " + n;
  outf<<fn + fname + n;
  outf<<ln + lname + n;
  outf<<an + accNum + n;
  outf<<ab + accBal + n;
  outf<<"+-----------------------------------------------+";
  }
  }else{
    std::cout<<"--INVALID UID--";
  }
}

void vAcc()
{
  //input to find record
  std::cout<<"Enter last name of account holder: ";
  std::cin>>lname;
  std::cout<<"Enter account number: ";
  std::cin>>accNum;
  
  std::ifstream inf{ lname + accNum + ".txt"};
  if(!inf)
  {
    std::cerr<<"--ERROR. FILE NOT FOUND--" << std::endl;
  }
  while (inf)
  {
  std::string strInput;
  std::getline(inf, strInput);
  std::cout<<strInput<<'\n';
  }
}

void mAcc()
{
  // another time and date thing
   time_t now = time(0);
   
   // 
   char* dt = ctime(&now);



   // 
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
  int uid;
  std::cout<<"Admin UID required: "<<std::endl;
  std::cin>>uid;
    if (uid == 0000)
  {
  std::cout << "\x1B[2J\x1B[H";//<this clears the console
  std::cout<<"Enter last name of account holder: ";
  std::cin>>llname;
  std::cout<<"Enter account number: ";
  std::cin>>aaccNum;
  
  std::ifstream inf{ llname + aaccNum + ".txt" };
  if(!inf)//<uses fstream's input function to verify the record exists
  {
    std::cerr<<"Error. File could not be opened.";
  }if (inf){
  
    n = "\n";
  std::cout<<"Enter acount holder's legal first name: ";
  std::cin>>fname;
  std::cout<<"Enter account holder's legal last name: ";
  std::cin>>lname;
  std::cout<<"Enter account number: ";
  std::cin>>accNum;
  std::cout<<"Update account balance ($): ";
  std::cin>>accBal;
  std::ofstream outf{ llname + aaccNum + ".txt", std::ios::app };
  if (!outf)
  {
    std::cerr<<"File could not be opened.";
  }
  //all write functions are in append mode, so there is a chronological record
  outf<<" " + n;
  //same appending function headers, but a little different
  outf<<"+----------------------------------------------+  ";
  outf<<dt + n;
  outf<<" " + n;
  outf<<"MODIFIED BY: " + user<< std::endl;
  outf<<" " + n;
  outf<<fn + fname + n;
  outf<<ln + lname + n;
  outf<<an + accNum + n;
  outf<<ab + accBal + n;
  outf<<"+----------------------------------------------+";
  }
  }if (uid != 0000)
  {
    std::cout<<"Invalid UID";
  }
}



int main()
{
  //primary login, since this is an admin console
  std::cout<<"ENTER UID: "<< std::endl;
  std::cin>>login;
  std::cout<<"ENTER USERNAME: "<<std::endl;
  std::cin>>user;
  while (login == "113113" && user == "admin")
  //a cool banner for the menu
  {
    std::cout << "\x1B[2J\x1B[H";
    std::cout <<"▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" <<        std::endl;
    std::cout <<"██ ▄▄▀█ ▄▄▀██ ▀██ ██ █▀▄████ ▄▄▄ ██ ▄▄▄████ ▀██ █ ▄▄▀█▄▄ ▄▄██ ▄▄▄"<<         std::endl;
    std::cout <<"██ ▄▄▀█ ▀▀ ██ █ █ ██ ▄▀█████ ███ ██ ▄▄█████ █ █ █ ▀▀ ███ ████ ▄▄▄"<<         std::endl;
    std::cout <<"██ ▀▀ █ ██ ██ ██▄ ██ ██ ████ ▀▀▀ ██ ███████ ██▄ █ ██ ███ ████ ▀▀▀"<<         std::endl;
    std::cout <<"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"<<         std::endl;
    std::cout <<"--BANK OF NATE ADMIN CONSOLE - PLEASE SELECT FUNCTION--"  << std::endl;
    std::cout<<"+------------------------------------------------------------+"               <<std::endl;
    std::cout<<"|                 +++Management Console++                    |"              <<std::endl;
    std::cout<<"|  1. New Account                                            |"              <<std::endl;
    std::cout<<"|  2. View Record                                            |"              <<std::endl;
    std::cout<<"|  3. Modify Account                                         |"              <<std::endl;
    std::cout<<"|                                                            |"              <<std::endl;
    std::cout<<"+------------------------------------------------------------+"              <<std::endl;
    std::cout<<"Enter command: ";
    std::cin>>comm;
    
    if (comm == 1)
      {
        newAcc();
      }
    if (comm == 2)
      {
        vAcc();
      }
    if (comm == 3)
      {
        mAcc();
      }
  
    std::cout<<"INPUT 'R' FOR MAIN MENU"<<std::endl;
    std::cin>>notimportant;
    if (notimportant == "r")
    {
    user = "admin";
    std::cout << "\x1B[2J\x1B[H";
    }
    if (login != "113113")
    {
    std::cout<<"INVALID UID";
    }
  }
}
