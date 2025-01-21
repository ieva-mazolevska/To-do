// To-do list Manager
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    string task;
    string newTask;
    string cmd;
    int deleteLine;
    int lineCount = 0;
    int zero = 0;
    cout << "To-do List Manager\n";
    cout << "Your active tasks: \n";
    // Opening the file to read tasks
    ifstream ifile;
    //ofstream ofile;
    ifile.open("tasks.txt");
    if(!ifile) {cout << "File not found!"; return 1;}
    else{
        while (getline(ifile, task)){ //Reading and displaying tasks from file
            cout << task << endl;
        }
    }
    while (true){ //Loop until the user chooses to exit
        cout << "Choose 'enter', 'delete', or 'display' tasks. You can exit task manager by entering 'exit'.\n";
        getline(cin, cmd);
        if(cmd == "enter"){ // add a new task
            cout << "Enter a new task:\n";
            getline(cin, newTask);
            ofstream ofile ("tasks", ios::app);
            ofile << newTask << endl;
            ofile.close();
        };
        if (cmd == "delete") { // delete a specific task
            while(getline(ifile, task)){lineCount++;}
            cout << "enter the the line number you want to delete:\n";
            cin >> deleteLine;
            while(!deleteLine <= lineCount){
                cout << "Invalid number. Try again.";
            }
            deleteLine = deleteLine++;
            while(getline(ifile, task)){
                if(deleteLine == lineCount)
                {
                    ofile << zero;
                }
            }



        };
        if(cmd == "display"){ // display all tasks
            while (getline(ifile, task)){
                cout << task << endl;
            }
        }
        // Exit the loop
        if (cmd == "exit") { break; };
    }
    ifile.close();
    ofile.close();
    return 0;
}