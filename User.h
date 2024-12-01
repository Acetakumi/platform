



#ifndef USER_H
#define USER_H

#include<string>
#include<vector>
#include "Post.h"
#include<iostream>
using namespace std;


class User {
    private:
    /**
     * @note These are my private variables.
     */
    int _userID;
        string _username;
        string _bio;
        vector<Post> _posts;

    public:
    /**
    *
    * @param userID this is the unique userID that I assign myself to the user
    * @param username This is the username the user has chosen
    * @param bio this is the bio the user wishes to have
    */
    User(int userID,string username,string bio);

    /**
     *
     * @return this method returns the value stored in the private instance of _userID
     */
    int get_userID();
    /**
     *
     * @return this method returns the value stored in the private instance of _username
     */
    string get_username();
    /**
     *
     * @return this method returns the value stored in the private instance _bio
     */
    string get_bio();
    /**
     *
     * @return this is a method that is a vector of the class Post and it returns by reference the value
     * stored inside this vector
     */
    vector<Post>& get_posts();

    /**
     *
     * @param content this is the content of the post you are trying to create
     * @note im creating a static int variable for the postID because I want it to increment at each new post i create and change dynamically
     * as i keep adding posts. I also create a new object of the class Post and then i initiliaze it using the constructor i created earlier and i added to my vector of Post
     *
     */
    void createPost(string content);

    /**
     * @notes in here i use the get_PostID to retreive the postID for a sepcific user than I call my viewpost function to get the rest of the data
     * needed to complete the listPost function
     */
    void listPosts();
};



#endif //USER_H
