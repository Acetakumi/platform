

#include "Post.h"

Post::Post(int postID, string content, int likes) {

    _postID = postID;
    _content = content;
    _likes = likes;
    _comment = vector<string>();
}



int Post::get_postID() {
    return _postID;
}


string Post::get_content() {
    return _content;
}


int Post::get_likes() {
    return _likes;
}



void Post::addLike() {
        _likes++;
}


void Post::addComment(string username,string comment) {
    string final_comment = "      " + username + " : " + comment;
    _comment.push_back(final_comment);
}


void Post::viewPosts() {

    cout << "[Post Content] : " << _content << endl;
    cout << "[Likes] : " << _likes << endl;

    if (_comment.empty()) {
        cout << "No comments yet." << endl;
    } else {
        cout << "[Comments] :" << endl;
        for (int i = 0; i < _comment.size(); i++) {
            cout << _comment[i] << endl;
        }
    }

}

