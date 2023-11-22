#ifndef COMMENT_ADMIN_CLASS_H
#define COMMENT_ADMIN_CLASS_H
#include <string>
using namespace std;
const int NUM_CHATS = 200;

class CommentAdmin {
private:
    string* chats;
public:
    CommentAdmin();
    ~CommentAdmin();
    int getChatCount();
    void printChat();
    bool addChat(string&);
    bool removeChat(int);
    bool removeChat(int*, int);
    bool removeChat(int, int);
};
#endif
