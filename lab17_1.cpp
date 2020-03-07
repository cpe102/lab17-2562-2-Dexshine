#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctype.h>
#include<stdio.h>
using namespace std;
string upper(string x){
    int i=0;
    while(x[i]){
        x[i] = toupper(x[i]);
        i++;
    }
    return x;
}

int main()
{
    ifstream namescore("name_score.txt");
    string data;
    int num1,num2,num3;
    char name[50];
    vector<string> vname;
    vector<int> vscore;
    vector<string> vgrade;
    while(getline(namescore,data)){
        sscanf(data.c_str(),"%[^:] : %d %d %d",name,&num1,&num2,&num3);
        vname.push_back(name);
        int tscore = num1+num2+num3;
        vscore.push_back(tscore);
        string grade;
        if(tscore>=80) grade = 'A';
        else if(tscore>=70) grade = 'B';
        else if(tscore>=60) grade = 'C';
        else if(tscore>=50) grade = 'D';
        else grade = 'F';
        vgrade.push_back(grade);
    }
    while(true){
        string text;
        int end = text.find_first_of(" ");
        string command1,search1;
        cout << "Please input your command: ";
        getline(cin,text);

        text = upper(text);

        command1 = text.substr(0,end);
        search1 = text.substr(end+1,text.size());
        if(command1 == "NAME"){
            for(int i=0;i<=vname.size();i++){
                if(upper(vname[i])==search1){
                    cout << vname[i] << " \'s grade = " << vgrade[i];
                }
                else if(i == vname.size() and vname[i]!= search1){
                    cout << "Cannot found" << "\n";
                }
            }
        }
        if(command1 == "GRADE"){
            for(int i=0;i<=vgrade.size();i++){
                if(upper(vgrade[i])==search1){
                    cout << vname[i] << "\n";
                }
                else if(i == vgrade.size() and vgrade[i] != search1){
                    cout << "Cannot found" << "\n";
                }
            }
        }
        if(command1 == "EXIT"){
            break;
        }
        if(command1 != "NAME" and command1 != "GRADE" and command1 != "EXIT"){
            cout << "Invalid command" << "\n";
        }
    }


}
