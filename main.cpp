#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <sstream>
#include <iomanip>
#include <direct.h>

#include "AVL_Tree.hpp"

// using namespace std;

// class User;
// class Social_Network;

std::vector<std::string> interests = {"UMT", "DSA", "Games", "Education", "Music", "Coding", "Jobs", "Entertainment"};

std::string take_input_string()
{
    std::string input;
    int i = 0;
    char in;

    // std::cout << "\n\n\n---------------------------------------------------------------------\n";
    std::cout << "Enter your input: ";
    while (true)
    {
        in = getch();

        if (in == 13) // if enter is pressed
        {
            // std::cout << "\n";
            break;
        }
        else if (in == 8) // if backspace is pressed
        {
            i--;
            std::cout << "\b \b";
        }
        // else if escape is presses
        else if (in == 27)
        {
            std::cout << "\n";
            input = 27;
            break;
        }
        else // if any other key is pressed
        {
            i++;
            std::cout << in;
            input += in;
        }
    }

    // for (int j = 0; j < i; j++)
    //     std::cout << "\b \b";
    std::cout << "\n";

    return input;
};

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int, int, int);
    // std::string get_time() const
    // {
    //     std::string t;
    //     t =
    // }
    void print() const;
};

Time ::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

void Time ::print() const
{
    if (hours < 10)
        std::cout << 0;
    std::cout << hours << ":";
    if (minutes < 10)
        std::cout << 0;
    std::cout << minutes << ":";
    if (seconds < 10)
        std::cout << 0;
    std::cout << seconds << '\n';
}

class chatMessage
{
private:
    std::string message_text;
    std::string sender;
    // Time sent_time;

public:
    chatMessage(std::string, std::string);

    std::string get_message_text() const;
    std::string get_sender() const;
    // Time get_sent_time() const;

    void set_message_text(std::string);
    void set_sender(std::string);
    // void set_sent_time(Time);
};

class User_Chat
{
private:
    static User_Chat *instance;

    User_Chat();

public:
    User_Chat(const User_Chat &) = delete;

    static User_Chat *getInstance();
};

User_Chat ::User_Chat()
{
    std::cout << "User_Chat created\n";
}
User_Chat *User_Chat ::instance = 0;
User_Chat *User_Chat ::getInstance()
{
    if (!instance)
        instance = new User_Chat;
    return instance;
}

class posts
{
private:
    std::string text;
    std::stack<User *> liked_by;
    // std::stack<std::unordered_map<std::string, std::string>> comments;

public:
    std::string get_text() const
    {
        return text;
    }
    std::stack<std::string> get_liked_by() const
    {
        return liked_by;
    }
    std::stack<std::unordered_map<std::string, std::string>> get_comments() const
    {
        return comments;
    }

    void set_text(std::string text)
    {
        this->text = text;
    }
    void set_liked_by(std::stack<std::string> liked_by)
    {
        this->liked_by = liked_by;
    }
    void set_comments(std::stack<std::unordered_map<std::string, std::string>> comments)
    {
        this->comments = comments;
    }

    void add_comment()
    {
    }
};

class User_Information
{
private:
    std::string username;
    std::string email;
    std::string name;
    char status;

    std::unordered_map<std::string, bool> user_interests;

public:
    User_Information(std::string, std::string, std::string, char, std::string);

    void set_username(std::string);
    void set_email(std::string);
    void set_name(std::string);
    void set_status(char);
    void process_interests_code(std::string);

    std::string get_username() const;
    std::string get_email() const;
    std::string get_name() const;
    char get_status() const;
};

User_Information ::User_Information(std::string username, std::string email, std::string name, char status, std::string interests_code = "")
{
    this->username = username;
    this->email = email;
    this->name = name;
    this->status = status;
    for (int i = 0; i < interests.size(); i++)
        user_interests[interests[i]] = false;

    process_interests_code(interests_code);
}

void User_Information ::set_username(std::string username)
{
    this->username = username;
}
void User_Information ::set_email(std::string email)
{
    this->email = email;
}
void User_Information ::set_name(std::string name)
{
    this->name = name;
}
void User_Information ::set_status(char status)
{
    this->status = status;
}

std::string User_Information ::get_username() const
{
    return username;
}
std::string User_Information ::get_email() const
{
    return email;
}
std::string User_Information ::get_name() const
{
    return name;
}
char User_Information ::get_status() const
{
    return status;
}

void User_Information ::process_interests_code(std::string interests_code)
{
    if (interests_code == "")
        return;

    for (int i = 0; i < interests_code.size(); i++)
    {
        if (interests_code[i] == '1')
            user_interests[interests[i]] = true;
    }
}

// void User_Information ::edit_user_interests()
// {
//     std::cout << "Allowed Interests:\n";
//     for (int i = 1; i <= interests.size(); i++)
//     {
//         std::cout << "  [" << i << "] " << interests[i - 1] << '\n';
//     }

//     std::cout << "\nCurrent Interests:\n";
//     for (auto i : user_interests)
//     {
//         if (i.second)
//             std::cout << "  " << i.first << '\n';
//     }

//     std::cout << "Enter to add or remove interests, or press escape to cancel\n";
//     while (true)
//     {
//         std::string input = take_input_string();
//         if (input[0] == 27)
//         {
//             std::cout << "Returned\n";
//             break;
//         }
//         else
//         {
//             int choice = stoi(input);
//             if (choice > 0 && choice <= interests.size())
//             {
//                 if (user_interests[interests[choice - 1]])
//                 {
//                     user_interests[interests[choice - 1]] = false;
//                 }
//                 else
//                 {
//                     user_interests[interests[choice - 1]] = true;
//                 }
//             }
//             else
//             {
//                 std::cout << "Invalid choice\n";
//             }
//         }
//     }

//     std::cout << "\nCurrent Interests:\n";
//     for (auto i : user_interests)
//     {
//         if (i.second)
//             std::cout << "  " << i.first << '\n';
//     }

//     // for (int i = 0; i < interests.size(); i++)
//     // pp.user_interests[interests[i]] = true;

//     // while(true)
//     // {

//     // }
// }

class User_Content
{
private:
    std::stack<posts> user_posts;

private:
};

class User : public User_Information
{
private:
    User_Content user_content;
    AVL_Tree<User *> friends;

public:
    User(std::string, std::string, std::string, char, std::string);
    ~User();

    bool operator<(const User &u) const
    {
        return get_username() < u.get_username();
    }
    bool operator>(const User &u) const
    {
        return get_username() > u.get_username();
    }
    bool operator==(const User &u) const
    {
        return get_username() == u.get_username();
    }

    bool operator<(const User *&u) const
    {
        return get_username() < u->get_username();
    }
    bool operator>(const User *&u) const
    {
        return get_username() > u->get_username();
    }
    bool operator==(const User *&u) const
    {
        return get_username() == u->get_username();
    }

    void print() const;

    AVL_Tree<User *> * get_friends();
};

User ::User(std::string username = "", std::string email = "", std::string name = "", char status = '\0', std::string interests_code = "") : User_Information(username, email, name, status) {}
User ::~User() {}
void User ::print() const
{
    std::cout << "\n\n\n---------------------------------------------------------------------\n";
    std::cout << "Username: " << get_username() << std::endl;
    std::cout << "Email: " << get_email() << std::endl;
    std::cout << "Name: " << get_name() << std::endl;
    std::cout << "Status: " << get_status() << std::endl;
}

AVL_Tree<User *> * User ::get_friends()
{
    return &friends;
}

class Primary_User : public User
{
private:
    static Primary_User *instance;

    User_Chat *user_chat;

    Primary_User();

public:
    static Primary_User *make_primary_user();

};

Primary_User ::Primary_User()
{
    user_chat = User_Chat::getInstance();
}
Primary_User *Primary_User ::instance = 0;
Primary_User *Primary_User ::make_primary_user()
{
    if (!instance)
        instance = new Primary_User;
    return instance;
}

class Social_Network
{
public:
    static Social_Network *instance;

    std::unordered_map<User *, AVL_Tree<User *> *> connections;
    AVL_Tree<User *> main_tree;

    Social_Network();

public:
    Social_Network(const Social_Network &) = delete;

    static Social_Network *getInstance();

    std::list<std::string> get_Mutals(const User &, const User &);
    void print_tree(AVL_Node<User> *&) const;
};

Social_Network ::Social_Network() {}
Social_Network *Social_Network ::instance = 0;
Social_Network *Social_Network ::getInstance()
{
    if (!instance)
        instance = new Social_Network;
    return instance;
}

std::list<std::string> Social_Network ::get_Mutals(const User &u1, const User &u2)
{
    std::list<std::string> frens1 = connections[u1.get_username()];
    std::list<std::string> frens2 = connections[u2.get_username()];

    std::list<std::string> mutual_friends;

    for (std::string i : frens1)
    {
        for (std::string j : frens2)
        {
            if (i == j)
            {
                mutual_friends.push_back(i);
            }
        }
    }

    std::cout << "\nMutuals are: ";
    for (std::string i : mutual_friends)
    {
        std::cout << i << ", ";
    }

    return mutual_friends;
}

void Social_Network ::print_tree(AVL_Node<User> *&cur) const
{

    // inorder print of tree
    if (cur == nullptr)
        return;
    print_tree(cur->get_left());
    cur->get_data().print();
    print_tree(cur->get_right());
}

class DataBase
{
private:
    static DataBase *instance;

    std::ifstream read;
    std::ofstream write;

    std::string directoryPath;
    std::string file_name;

    std::string data_write;
    std::string data_read;

    DataBase();

public:
    static DataBase *getInstance();
    DataBase(const DataBase &) = delete;

    int load_all_users(User **&);
    void load_friends(User &);
    void load_interests(User &);

    void load_chats(Primary_User *&);

    void make_main_tree(Social_Network *&, User **all_users, const int);

    void create_dir(std::string userName)
    {
        directoryPath = "D:/Semester III/Data Structures and Algorithms/Project/Social_Media_App/User_Data/" + userName;

        const char *path = directoryPath.c_str();

        if (_mkdir(path) == -1)
        {
            std::cerr << "Error creating directory" << std::endl;
            return;
        }

        std::cout << "Directory created successfully" << std::endl;
        // for (int i = 1; i <= 3; ++i)
        // {
        // string filename = directoryPath + "/file" + to_string(i) + ".txt";
        std::string filename = directoryPath + "/file" + "posts" + ".txt";
        std::ofstream outFile(filename);

        if (outFile.is_open())
        {
            outFile << "This is file "
                    << "posts" << std::endl;
            outFile.close();
            std::cout << "posts"
                      << " created successfully" << std::endl;
        }
        else
        {
            std::cerr << "Error creating file "
                      << "posts" << std::endl;
        }
    }
    // bool user_exists(std::string username);

    void set_file_path(std::string file_path);
    void set_file_name(std::string file_name);

    std::string get_file_path();
    std::string get_file_name();
};

DataBase *DataBase ::instance = 0;

DataBase ::DataBase()
{
    directoryPath = "";
    file_name = "";
}
DataBase *DataBase ::getInstance()
{
    if (!instance)
        instance = new DataBase;
    return instance;
}

void DataBase ::set_file_path(std::string file_path)
{
    directoryPath = file_path;
}
void DataBase ::set_file_name(std::string file_name)
{
    this->file_name = file_name;
}

std::string DataBase ::get_file_path()
{
    return directoryPath;
}

void DataBase ::load_friends(User &user)
{
    std::string username = user.get_username();

    std::cout << "finding friends\n\n";
    std::string r;

    // std::string friends_file = "Users_Data/" + username + "/friends.txt";
    std::ifstream read("Users_Data/" + username + "/friends.txt");

    if (!read.is_open())
    {
        std::cout << "Error opening file of: " << username << '\n';
        return;
    }
    else
    {

        while (read >> r)
        {
            std::cout << "Loading friends of: " << username << ": " << r << std::endl;
            user.get_friends().insert(user.get_friends().get_root(), r);
        }
        std::cout << std::endl;
    }
}

int DataBase ::load_all_users(User **&all_users)
{
    int total_users = 0;
    std::string username, email, name1, name2, interests_code;
    char status;

    read.open("users.txt");

    if (!read.is_open())
    {
        std::cout << "Error opening file\n";
        return -1;
    }
    else
    {
        read >> total_users;
        read.ignore();
        std::cout << "Total users: " << total_users << std::endl;
        all_users = new User *[total_users];

        std::cout << "Users created\n";

        for (int i = 0; getline(read, data_read, '\n') && i < total_users; i++)
        {
            std::stringstream ss(data_read);
            ss >> username >> name1 >> name2 >> email >> status >> interests_code;

            all_users[i] = new User(username, email, name1 + " " + name2, status, interests_code);
            std::cout << "user created: " << all_users[i]->get_username() << std::endl;
            load_friends(*all_users[i]);
            std::cout << "friends loaded: " << all_users[i]->get_username() << std::endl;
        }
        std::cout << "Users loaded\n";
        read.close();
    }
    return total_users;
}

void DataBase ::make_main_tree(Social_Network *&sn, User **all_users, const int total_users)
{
    for (int i = 0; i < total_users; i++)
    {
        sn->main_tree.insert(sn->main_tree.get_root(), &(*all_users[i]));
    }
}

int main()
{
    std::cout << "Helo jee" << std::endl;
    int total_users; //

    User **all_users = nullptr;

    Social_Network *sn = Social_Network::getInstance();
    DataBase *db = DataBase::getInstance();
    Primary_User *pu;

    return 0;
}