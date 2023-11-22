#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>
#include "comment_admin_class.hpp"
#include "comment_admin_class.cpp"
using namespace std;

int main(void)
{
    CommentAdmin* admin = new CommentAdmin();
    string s;
    s = "Hello, Comment Administrator!";
    admin->addChat(s);
    s = "How have you been?";
    admin->addChat(s);
    s = "I am an undergraduate.";
    admin->addChat(s);
    s = "I am taking Creative Software Design.";
    admin->addChat(s);
    s = "This class is awesome.";
    admin->addChat(s);
    while(true)
    {
        string command;
        getline(cin, command);
        if (command == "#quit") break;
        else if (command.substr(0, 7) == "#remove")
        {
            /* remove chat */
            int numcommas;
            int numchats = admin->getChatCount();
            string substr = command.substr(8);
            stringstream ss(substr);
            bool hascomma =  command.find(',') != string::npos;
            bool hashyphen = command.find('-') != string::npos;
            bool succeed = false;
            if (hascomma && hashyphen) {
                cerr<<"invalid input: combination of different commands."<<endl;
                exit(1);
            }
            else if (hascomma) {
                numcommas = count(substr.begin(), substr.end(), ',');
                int* indices = new int[numcommas];
                int cnt = 0;
                for (int i; ss >> i && cnt <= numcommas; ) {
                    indices[cnt++] = i;
                    if (ss.peek() == ',')
                        ss.ignore();
                }
                /* remove chats using member function of commentadmin if comment has comma  */
                if (admin->removeChat(indices, cnt)) succeed = true;
            }
            else if (hashyphen) {
                int start, end;
                if (! (ss >> start)) 
                    continue;
                ss.ignore();
                if (! (ss >> end)) 
                    continue;
                /* remove chats using member function of commentadmin if comment has hyphen  */
                if (admin->removeChat(start, end)) succeed = true;
            }
            else {
                int ind;
                if (! (ss >> ind))
                    continue;
                /* remove just one comment*/
                if (admin->removeChat(ind)) succeed = true;
            }
            if (succeed) {
                /* print chats*/
                admin->printChat();
            }
        }
	else if (command[0] == '#') continue;
        else if (admin->addChat(command)) 
            admin->printChat();
    }
    return 0;
}

