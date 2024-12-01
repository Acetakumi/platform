//
// Created by aceta on 2024-11-26.
//

#include "Socialmediaplatform.h"

Socialmediaplatform::Socialmediaplatform() {
    _users = vector<User>();
}

void Socialmediaplatform::registerUser( string username, string bio) {

    // Here i use static int for the userID because we want it to dynamically change as we keep assign it to new users.
    static int userID = 1;
    // Here i am create a new object of class User and im initializing it with the values specific to the new user and im adding it into the vector of _users.
    User temp(userID++, username, bio);
    _users.push_back(temp);
    cout << endl;

    cout << "Thank you " << username <<  " for registering on Husnain's Social media platform :) " << endl;
    cout << "Your ID: " << userID - 1 << endl;
}


bool Socialmediaplatform::removeUser(int userID) {
    for (int i = 0; i < _users.size(); i++) {
        // We go through each element  of the vector _users till we find the one that matches the parameter.
        if (_users[i].get_userID() == userID) {
            // I then erase or delete the element.
            _users.erase(_users.begin() + i);
            cout << "This user has been removed from our platform " << endl;
        } return true;
    } cout << " The user you are trying to remove does not exist in our Data Base. Please try again..." << endl;
    cout  << "-------------------------------------------------------------------------"  << endl;
    return false;
}


User * Socialmediaplatform::findUserByUsername(string username) {
    for (int i = 0; i < _users.size(); i++) {
        // We go through each element  of the vector _users till we find the one that matches the parameter.
        if (_users[i].get_username() == username) {
            return &_users[i];
        }
    } cout << "We could not find this user in our data base. Please try again..." << endl;
    cout  << "-------------------------------------------------------------------------"  << endl;
    return nullptr ;
}

bool Socialmediaplatform::createPostForUsername(int userID, string content) {
    for (int i = 0; i < _users.size(); i++) {
        // // We go through each element  of the vector _users till we find the one that matches the parameter.
        if (_users[i].get_userID() == userID) {
            _users[i].createPost(content); // Here we call the method createPost to add a post at that specific element of the vector _users.
            cout << "Post added successfully for " << _users[i].get_username() << endl;
            vector<Post> temp = _users[i].get_posts(); // Here I create a new vector of the class Post to extract the postID
            cout << "The Post ID is : " << temp.back().get_postID() << endl;
            return true;

        }
    }
    return false;

}



bool Socialmediaplatform::likePost(int postID, int userID) {
    for (int i = 0; i < _users.size(); ++i) {
        // We go through each element  of the vector _users till we find the one that matches the parameter.
        if (_users[i].get_userID() == userID) {
            vector<Post>& temp = _users[i].get_posts(); // Here I create a variable that is declared by reference so that I can change the value stored in the
            // original _users vectors.

            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j].get_postID() == postID) {
                    temp[j].addLike();
                    cout << endl;
                    return true;
                }
            }

        }
    }
    return false;

}


bool Socialmediaplatform::commentOnPost(int postID,string username,string comment) {
    for (int i = 0; i < _users.size(); ++i) {
        // We go through each element  of the vector _users till we find the one that matches the parameter.
        vector<Post>& temp = _users[i].get_posts();// Here I create a variable that is declared by reference so that I can change the value stored in the
        // original _users vectors.


        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j].get_postID() == postID) {
                temp[j].addComment(username, comment);
                cout  << "Your comment has been succesfully added to the post " << postID <<  endl;
                return true;
            }
        }

    } cout << " We have been unable to find the Post you are trying to comment on. Please Try again..." << endl;
    cout  << "-------------------------------------------------------------------------"  << endl;

    return false;
}


bool Socialmediaplatform::viewUserProfile(int userID) {
    for (int i = 0; i < _users.size(); ++i) {
        if (_users[i].get_userID() == userID) {
            cout << "User ID : " << _users[i].get_userID() << endl;
            cout << "Username: " << _users[i].get_username() << endl;
            cout << "bio: " << _users[i].get_bio() << endl;
            _users[i].listPosts();
            return true;
        }

    }
    return false;
}
