/*Program implemented by: octavio Cea and Reinier Pamintuan.
  date;	October 01, 1016
  Course: CS 433 (Operatig systems)
  Brief description:	This program is a basic shell for unix which includes basic functions
  such as fork, cd (directory), history, ls (contents of directory), exit,
  and a few others.  

  A more complete description can be found in the written report for this program*/

#include <sys/types.h>
#include <iostream>
#include <string>
#include <list>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

list<string> Stack;

void dir()
{
        for(list<string>::iterator itr = Stack.begin(); itr != Stack.end(); itr++)
                cout << *itr << " ";
        cout << endl;
}

void push(char* tok, char* curDir)
{
        if(tok != NULL) 
	{
                string path = curDir;
                Stack.push_front(path);
                if(chdir(tok) != 0)
                        cout << "Error while changing to desired directory." << endl;
                else
                        dir();
        } 
	else 
	{
                cout << "No such directory." << endl;
        }
}
void pop()
{
        if(Stack.size() > 0) 
	{
                string curDir = Stack.front();
                Stack.pop_front();
                if(chdir(curDir.c_str()) != 0)
                        cout << "Error while changing to desired directory." << endl;
        } 
	else
                cout << "Empty directory stack." << endl;
}

//Checks the validity of the token directory and displays current directory
void cd(char* token)
{
        if(token != NULL) 
	{
                cout << "You are now in directory \"" << token << "\"" << endl;
                if(chdir(token) != 0)
                        cout << "Error while changing to desired directory." << endl;
        } 
	else
                cout << "Command not valid. Enter command as follows:" << endl
                        << "cd [name of directory]" << endl;
}
//This function forks a child everytime it is called
bool fork(char* token)
{
        pid_t pid = fork();
        if(pid < 0) 
	{
                cout << "Shell unable to execute command in a child process." << endl;
                return true;
        } 
	else if(pid == 0)
	{

                string prog = token;
                char* cmdArgs[1024];
                int i = 0;
                do 
		{
                        cmdArgs[i] = new char[strlen(token)+1];
                        memset(cmdArgs[i], 0, strlen(token)+1);
                        strcpy(cmdArgs[i], token);
                        i++;
                } while( (token = strtok(NULL, " ")) != NULL);

                int ret = execvp(prog.c_str(), cmdArgs);
                if(ret == -1)
			cout << "Not able to execute entered program." << endl;

                
                for(int y=0; y < i; y++)
                        delete cmdArgs[i];
                return false; 
                                       
        } 
	else 
	{ 
               	wait(NULL); 
               	return true; 
        }
}

// This function prints the history to the screen
void printHistory(int historyItems, string history[])
{
	for(int i = 0; i <= historyItems; i++)
	{
		cout << i+1 << ". " << history[i] << endl;
	}
}

//driver program, main perfoms the forking and it checks for the user
//input to execute a given program.
int main(int argc, char* argv[])
{
	cout << "Octavio Cea, Reinier Pamintuan" << endl;
        cout << "10/02/2016" << endl;
        cout << "CS433, Operating Systems" << endl;
        cout << "Assignment 2, UNIX Shell" << endl;

        string hist[1024];
	int i = 0;
	bool Continue = true;
        string inputStr;
        char Dir[1024] = { '\0' };
        do 
	{
                //Get the current directory
                if(getcwd(Dir, 1023) != NULL)
                        cout << "$" << Dir << " > " << flush;
		else
                        cout << " > " << flush;
                //Get input from user
                getline(cin, inputStr);
		hist[i] = inputStr;
                i++;
                char* cx = new char[inputStr.length() + 1];
                memset(cx, 0, inputStr.length()+1);
                strcpy(cx, inputStr.c_str());
                char* tok = strtok(cx, " ");
		if(tok != NULL) 
		{
			//If the first user input is exit the loop end and the program quits
                        if(strcmp(tok, "exit") == 0)
                                Continue = false;
                        else if (strcmp(tok, "pushd") == 0) 
			{
                                tok = strtok(NULL, " ");
				push(tok, Dir);
                        }
			else if (strcmp(tok, "history") == 0)
                        {
				printHistory(i-1, hist);
                        }
 			else if (strcmp(tok, "popd") == 0) 
			{
                                pop();
                        }
			else if (strcmp(tok, "dirs") == 0) 
			{
                                dir();
                        } 
			else if (strcmp(tok, "cd") == 0) 
			{
                                tok = strtok(NULL, " ");
                                cd(tok);
                        } 
			else 
			{
                                Continue = fork(tok);
                        }
		}
                delete cx;
        } while (Continue);

        return 0;
}
