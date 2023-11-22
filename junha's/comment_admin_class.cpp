#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "comment_admin_class.hpp"
using namespace std;

CommentAdmin::CommentAdmin() {
    chats = new string[NUM_CHATS];
}
    
CommentAdmin::~CommentAdmin() {
    delete chats;
}

int CommentAdmin::getChatCount() {
    int i;
    for(i = 0; i < NUM_CHATS; ++i)
    {
        string s = chats[i];
        if(s.empty() == true) break;
    }
    return i;
}

void CommentAdmin::printChat()
{
    int count = getChatCount();
    for(int i = 0; i < count; ++i)
    {
        cout << i << " " << chats[i] << endl;
    }
}

// Add _chat into chats
// If it fails, return false; otherwise, return true
bool CommentAdmin::addChat(string& _chat) {
    /* TODO */
    for (int i = 0; i < NUM_CHATS; ++i) {
        if (chats[i].empty()) {
            chats[i] = _chat;
            return true;
        }
    }
    return false;
    // returns true when adding chat is succeeded
}

// Remove the chat at _index from chats
// if _index does not exists, return false; otherwise, return true
bool CommentAdmin::removeChat(int _index) {
    if (_index >= NUM_CHATS)
        return false;
    // returns true when removing chat is succeeded
    /* TODO */
    for (int i = _index; i < NUM_CHATS-1; ++i) {
        chats[i] = chats[i + 1];
    }
    return true;
}

// Remove the comments at indices form _indices[0] to _indices[_count-1] 
// (inclusive)
// Return true if at least one is removed; false otherwise
// Do nothing if an index does not exist
bool CommentAdmin::removeChat(int* _indices, int _count) {
    bool isRemoved = false;
    /* TODO */
    for (int i = 0; i < _count; ++i) {
        int x = _indices[i];
        chats[x] = "";
        isRemoved = true;
    }
    for (int i = 0; i < NUM_CHATS; i++)
    {
        if (chats[i].empty())
        {
            for (int j = i + 1; j < NUM_CHATS; j++)
            {
                if (!chats[j].empty())
                {
                    chats[i] = chats[j];
                    chats[j] = "";
                    break;
                }
            }
        }
    }
    return isRemoved;
}

// Remove the comments at indices from _start to _end in chats
// Return true if at least one is removed.
// If _strat is a negative number or _end >= NUM_CHATS,
// remove only the chats at valid indices.
bool CommentAdmin::removeChat(int _start, int _end) {
    bool isRemoved = false;
    /* TODO */
    if (0 <= _start and _end <= NUM_CHATS) {
        int cnt = _end - _start + 1;
        cout << cnt << endl;
        for (int i = _start; i < _end + 1; ++i) {
            chats[i] = "";
            if (i + cnt < NUM_CHATS) {
                chats[i] = chats[i + cnt];
                isRemoved = true;
            }
            chats[i + cnt] = "";
        }
    }
    return isRemoved;
}

