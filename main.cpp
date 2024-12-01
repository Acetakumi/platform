#include "Socialmediaplatform.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Socialmediaplatform platform; // create a new object of the class Socialmediaplatform
    int userInput = 0;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Welcome to Husnain's social media platfrom" << endl;
    cout << "Created by Husnain Abbas for his class of COEN 243" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    while (true) {

        cout << "1. Register User" << endl;
        cout << "2. Create a Post" << endl;
        cout << "3. Like a Post" << endl;
        cout << "4. Comment on a Post" << endl;
        cout << "5. View User Profile" << endl;
        cout << "6. Remove a User" << endl;
        cout << "7. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> userInput;
        cout << endl;
        cout  << "-------------------------------------------------------------------------" << endl;


        switch (userInput) {


            case 1: {
                string username, bio;
                cout << "Enter username: ";
                cin >> username;

                cout << "Enter bio: ";
                cin.ignore(); // Clear the newline character left in the input buffer by the previous cin >> operation
                getline(cin, bio); // Read the entire line, including spaces

                platform.registerUser(username, bio);
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }

            case 2: {
                string username, content;
                cout << "Enter username: ";
                cin >> username;

                cout << "Enter post content: ";
                cin.ignore(); // Clear the newline character left in the input buffer by the previous cin >> operation
                getline(cin, content); // Read the entire line, including spaces
                cout << endl;

                // As parameter for this function I use the method findUserByUsername that returns a pointer and then a retreive the userID with get_userID();
                platform.createPostForUsername(platform.findUserByUsername(username)->get_userID(), content);
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }

            case 3: {
                string username;
                int postID;

                cout << "Enter username: ";
                cin >> username;

                cout << "Enter post ID to like: ";
                cin >> postID;

                // As parameter for this function I use the method findUserByUsername that returns a pointer and then a retreive the userID with get_userID();
                if (platform.likePost(postID,platform.findUserByUsername(username)->get_userID()) == true) {
                    cout << "Post ID " << postID << " liked " <<  endl;
                }

                cout  << "-------------------------------------------------------------------------"  << endl;

                break;
            }

            case 4: {
                string username, comment;
                int postID;

                cout << "Enter username: ";
                cin >> username;

                cout << "Enter post ID to comment on: ";
                cin >> postID;

                cout << "Enter your comment: ";
                cin.ignore(); // Clear the newline character left in the input buffer by the previous cin >> operation
                getline(cin, comment); // Read the entire line, including spaces
                cout << endl;

                platform.commentOnPost(postID, username, comment);
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }

            case 5: {
                string username;


                cout << "Enter username to view profile: ";
                cin >> username;
                cout << endl;
                // As parameter for this function I use the method findUserByUsername that returns a pointer and then a retreive the userID with get_userID();
                platform.viewUserProfile(platform.findUserByUsername(username)->get_userID());
                cout << endl;
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }

            case 6: {
                int userID;
                cout << "Enter the User ID to remove: ";
                cin >> userID;

                platform.removeUser(userID);
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }

            case 7: {

                cout << "Exiting program..." << endl;
                cout << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                cout << endl;
                cout  << "-------------------------------------------------------------------------"  << endl;
                break;
            }
        }

        cout << endl;


    }  return 0;
}
