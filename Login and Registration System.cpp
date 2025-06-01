#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool userExists(const string& username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists! Please try a different one.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream userFile(username + ".txt");
    if (userFile) {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error in registration!\n";
    }
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;

    if (!userExists(username)) {
        cout << "User not found! Please register first.\n";
        return false;
    }

    cout << "Enter your password: ";
    cin >> password;

    ifstream userFile(username + ".txt");
    if (userFile) {
        getline(userFile, storedUsername);
        getline(userFile, storedPassword);
        userFile.close();

        if (username == storedUsername && password == storedPassword) {
            cout << "Login successful! Welcome, " << username << "!\n";
            return true;
        } else {
            cout << "Invalid username or password!\n";
        }
    } else {
        cout << "Error reading file!\n";
    }
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose an option: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
