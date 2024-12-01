

#ifndef SOCIALMEDIAPLATFORM_H
#define SOCIALMEDIAPLATFORM_H
#include "user.h"



class Socialmediaplatform {

    private:

        vector<User> _users;

    public:
        /**
         * @note this is my constructor that initiliazes my vector of class User.
         */
        Socialmediaplatform();

        /**
         * 
         * @param username this is the username of the user we are trying to register
         * @param bio this is the bio of the said user.
         */
        void registerUser(string username, string bio);

        /**
         * 
         * @param userID This is the specific userID that belongs to the user.
         * @return This function returns true if the user we are trying to delete has been removed succesfully and
         * it returns false if the user cannot be removed.
         */
        bool removeUser(int userID);

        /**
         * 
         * @param username This is the username of the user we are trying to find
         * @return this returns the memory adress of the element at which this users information is stored.
         */
        User* findUserByUsername(string username);

        /**
         * 
         * @param userID This is the userID of the user for which we are trying to create a post
         * @param content this is the content of the post
         * @return this returns true we were able to find the user and create a post and it returns false in case we couldn't find the user and create a post.
         */
        bool createPostForUsername(int userID,string content);

        /**
         * 
         * @param postID This is the postID of the  post we are trying to like
         * @param userID This is the userID of the user we are trying to like the post of
         * @return true if we succesfully liked the post and returns false we couldn't like the post.
         */
        bool likePost(int postID,int userID);

        /**
         *
         * @param postID this is the postID of the post we are trying to comment on
         * @param username this is the username of the person that is posting the comment
         * @param comment this is the comment that the user is trying to leave on the post.
         * @return true if a comment was successfully left on the post and false if it did not work
         */
        bool commentOnPost(int postID,string username,string comment);

        /**
         * 
         * @param userID this is the userID of the user we are trying to view the profile of
         * @return this returns true we were able to extract the information of the user and display it and false if we couldn't
         */
        bool  viewUserProfile(int userID);



};



#endif //SOCIALMEDIAPLATFORM_H
