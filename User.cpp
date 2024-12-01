
#include "user.h"

using namespace std;


User::User(int userID, string username, string bio) {
    _userID = userID;
    _username = username;
    _bio = bio;
    _posts = vector<Post>();

}


int User::get_userID() {
    return _userID;
}

string User::get_username() {
    return _username;
}

string User::get_bio() {
    return _bio;
}

vector<Post>&  User::get_posts() {
    return _posts;
}

void User::createPost( string content) {
        static int postID = 1;
        Post temp(postID++, content, 0);
        _posts.push_back(temp);
}


void User::listPosts() {

    for (size_t i = 0; i < _posts.size(); ++i) {
        cout << "-----------------------" << endl;
        cout << "[Post ID]: " << _posts[i].get_postID() << endl;

        _posts[i].viewPosts();

    }
}











