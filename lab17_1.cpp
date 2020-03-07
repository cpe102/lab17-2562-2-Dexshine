#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctype.h>
#include<cstring>
#include<stdio.h>
using namespace std;
string upper(string x){
    string temp;
    int i=0;
    for(i=0;i<x.size();i++){
        if(x[i]>96){
            x[i] -= 32;
        }
    }
    return x;
}
void prtline(int n){
    for(int j=0;j<n;j++){ cout << "-";}
    cout << "\n";
}

int main()
{
    ifstream namescore("name_score.txt");
    string data,grade;
    int num1,num2,num3;
    bool check = 1;
    char name[50];
    vector<string> vname;
    vector<int> vscore;
    vector<string> vgrade;
    while(getline(namescore,data)){
        sscanf(data.c_str(),"%[^:] : %d %d %d",name,&num1,&num2,&num3);
        vname.push_back(name);
        int tscore = num1+num2+num3;
        vscore.push_back(tscore);
        if(tscore>=80) grade = "A";
        else if(tscore>=70) grade = "B";
        else if(tscore>=60) grade = "C";
        else if(tscore>=50) grade = "D";
        else grade = "F";
        vgrade.push_back(grade);
    }
    while(check){
        string text;
        string command,search;
        cout << "Please input your command:";
        getline(cin,text);
        string ntext = upper(text);
        int idx = text.find_first_of(" ");
        bool found = 0; 
        command = ntext.substr(0,idx);
        search = ntext.substr(idx+1,ntext.size());
        if(command == "NAME"){
            prtline(33);
            for(int i=0;i<vname.size();i++){
                if(upper(vname[i])==search){
                    cout << vname[i] << "\'s grade = " << vgrade[i] << "\n";
                    found = 1;
                }
                else if(found == 0  and i==vname.size()-1){
                    cout << "Cannot found." << "\n";
                }
            }
            prtline(33);
        }
        found = 0;
        if(command == "GRADE"){
            prtline(33);
            for(int i=0;i<vgrade.size();i++){
                if(upper(vgrade[i])==search){
                    cout << vname[i] << "\n";
                    found = 1;
                }
                else if(found == 0  and i==vgrade.size()-1){
                    cout << "Cannot found." << "\n";
                }
                
            }
            prtline(33);
        }
        if(command == "EXIT"){
            check = 0;;
        }
        if(command != "NAME" and command != "GRADE" and command != "EXIT"){
            cout << "Invalid command" << "\n";
        }
    }
    

}
