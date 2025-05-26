#include<iostream>
#include<fstream>
// #include<bits/stdc++.h>

using namespace std; 

ifstream read_txt;  //read txt-file and encrypt........
ofstream write_txt; //create encrypted file......

class Txt_Encoder {
    private:
        char txt;
        int encryption_key;
        string filename;
    public:
        void encrypt();
        void decrypt();
        void About(){
             system("cls");
             system("color 2");
                cout<<"\n\n-------------- Usage ------------------------\n \n";
                cout<<"If you Select Encryption \nNext enter you want to encrypt text file name; Eg:- example.txt\n";
                cout<<"\t###-Next Enter Encryption key\n\t###-Don\'t forget encryption key\n\t###-Without encryption key you can\'t decrypt that encrypted file\n";
                cout<<"After doing this your text file is sucessfully encrypted\n\n";
                cout<<"If you select Decryption \n\t***-Next enter encrypted text file name; Eg:-Encrypted-example.txt\n";
                cout<<"\t***-Enter your encryption key and sucessfully decrypted..... \n\n";
                cout<<"\n==============================================\n";
                cout<<"------------------------------------------------ Prepared by t.me/Bahir_21\n";

        }

};

void Txt_Encoder::encrypt(){
        
        cout<<"\n\nPlease enter file name with text format \n--> ";
        cin.ignore();
        getline(cin,filename);
        cout<<"Please enter encryption key number \n--> ";  
        cin>>encryption_key;

        read_txt.open(filename);
        write_txt.open("Encrypted-"+filename);


        while(read_txt >> noskipws >> txt){ 
            int encode = (txt + encryption_key);
            write_txt<<(char)encode;
        }
    cout<<"\n"<<filename<<" To Encrypted-"<<filename<<"  Sucessfully completed"<<endl;


    read_txt.close();
    write_txt.close();
}

void Txt_Encoder::decrypt(){

        cout<<"\n\nPlease enter file name with text format \n--> ";
        cin.ignore();
        getline(cin,filename);
        cout<<"Please enter your encryption key number \n--> ";  
        cin>>encryption_key;

        read_txt.open(filename);
        write_txt.open("decrypted-"+filename);


        while(read_txt >> noskipws >> txt){ 
            int encode = (txt - encryption_key);
            write_txt<<(char)encode;
        }

    cout<<"\n-------------\n---------------\n"
	<<filename<<" To Decrypted-"<<filename<<" Sucessfully completed"<<endl;

    read_txt.close();
    write_txt.close();

}

int main(){
    Txt_Encoder encoding;
    char choice;

        again:
        again1:
        again2:
         system("color 4");
        cout<<"######################################################################\n";
        cout<<"#--------------------------------------------------------------------#\n";
        cout<<"#-----              Text Encryption and Decryption              -----#\n";
        cout<<"#--------------------------------------------------------------------#\n";
        cout<<"######################################################################\n";
        
        do{
            cout<<"\n\tSelect one     \n";
            cout<<"\t[1]  Encryption  \n";
            cout<<"\t[2]  Decryption \n";
            cout<<"\t[3]  About      \n";
            cout<<"\t[4]  Exit       \n\n";
            cout<<"[-] Select an option : "; cin>>choice;
            
        } while(choice <'1' || choice >'4');
		system("cls ");
		system("color 2");
        switch(choice){
            case '1':
                encoding.encrypt();
                cin.get();
                if(cin.get()=='\n'){
	                 system("cls");
	                goto again;
	            }
                break;
            case '2':
                encoding.decrypt();
                cin.get();
                if(cin.get()=='\n'){
	                system("cls");
	                goto again1;
            	}
                break;
            case '3':
                encoding.About();
                cin.get();
                if(cin.get()=='\n'){
	                system("cls");
	                goto again2;
            	}
                break;
            case '4':
                break;
        
        }

    return 0;
}
