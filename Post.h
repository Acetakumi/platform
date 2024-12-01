


#ifndef POST_H
#define POST_H

#include<string>
#include<vector>
#include<iostream>
using namespace std;



class Post {

    private:

        int _postID;
        string _content;
        int _likes;
        vector<string> _comment;

    public:
        /**
        * @note This is my constructor for the class Post
        * @param postID this is the post ID assigned to each post made by a user
        * @param content this is the content inside the post
        * @param likes number of likes the post has gotten
        * @note _comment is initiliazed as just a vector of strings
        */
        Post(int postID, string content,int likes);
        /**
        *
        * @return This is a get function that returns the value stored in the private instance _postID
        */
        int get_postID();
        /**
        *
        * @return This is a get function that returns the value stored in the private instance _content
        */
        string get_content();
        /**
         *
         * @return This is a get function that returns the value stored in the private instance _likes
         */
        int get_likes();
        /**
         * @note this is a void function that increments the number _likes
         */
        void addLike();
        /**
         *
         * @param username this is the username of the person who comments on the post
         * @param comment this is the comment that the user leaves on the post
         * @note this void function adds a string combination that shows the username and the comments and adds it to the vector of strings _comment
         */
        void addComment(string username,string comment);
         /**
         * this void function prints the variables _content, _likes, and goes through the vector _comment  for this object and prints all the comments made.
         */
        void viewPosts();
};



#endif //POST_H
