#include "user.h"
#include "network.h"
#include "post.h"
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
void testAddFriend()
{
    cout << "testAddFriend...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    User userTwo(4, "Sami Shibli", 2000, 94087, vector<size_t>{0, 1, 2});
    userOne.addFriend(userTwo.getId());
    // cout << userOne;
    // algorithim to check if user two exist in user ones friends list
    assert((std::find(userOne.getFriendsList().begin(), userOne.getFriendsList().end(), userTwo.getId()) != userOne.getFriendsList().end()));
}
void testDeleteFriend()
{
    cout << "test Delete Friend...";
    User userOne(4, "Sami Shibli", 2000, 94087, vector<size_t>{0, 1, 2});
    // cout << userOne;
    // algorithim to check if user two exist in user ones friends list
    userOne.deleteFriend(2);
    // cout << userOne;
    bool found = false;
    for (auto v : userOne.getFriendsList())
    {
        if (v == 2)
            found = true;
    }

    // Check if userTwo's ID is no longer in userOne's friends list
    // cout << *(std::find(userOne.getFriendsList().begin(), userOne.getFriendsList().end(), 1)); // - userOne.getFriendsList().begin();
    // assert((std::find(userOne.getFriendsList().begin(), userOne.getFriendsList().end(), 1) == userOne.getFriendsList().end()));
    assert(found == false);
    // cout << userOne;
    cout << "Passed!" << endl;
}
void testUserGetId()
{
    cout << "test User GetId...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    assert(userOne.getId() == 3);
    // ...
    cout << "Passed!" << endl;
}
void testUserGetName()
{
    cout << "test User Get Name...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    assert(userOne.getName() == "Jason Chen");
    // ...
    cout << "Passed!" << endl;
}
void testUserGetBirthYear()
{
    cout << "test User Get BirthYear...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    assert(userOne.getBirthYear() == 2000);
    // ...
    cout << "Passed!" << endl;
}
void testUserGetZipCode()
{
    cout << "test User Get Zipcode...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    assert(userOne.getZipCode() == 94087);
    // ...
    cout << "Passed!" << endl;
}
void testUserGetFriendsList()
{
    cout << "test User Get Friends List...";
    User userOne(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    std::vector<size_t> expectedFriendsList = {0, 1, 2};

    assert(expectedFriendsList == userOne.getFriendsList());
    // ...
    cout << "Passed!" << endl;
}

void testConstructorGetter()
{
    cout << "testConstructorGetter...";
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    assert(u->getId() == 3);
    // ...
    cout << "Passed!" << endl;
}
// test add user functionality as well as numUsers. Assert would not pass if the add User does not work.
void testNumUsersAndAddUser()
{
    cout << "test numUsers function...";
    Network network;
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    User *x = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    network.addUser(u);
    network.addUser(x);
    assert(network.numUsers() == 2);
    cout << "Passed!" << endl;
}
void testGetUser()
{
    cout << "test getUser function...";
    Network network;
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    network.addUser(u);
    User *foundUser = network.getUser(3);
    assert(foundUser != nullptr);
    assert(foundUser->getId() == 3);

    cout << "Passed!" << endl;
}
void testGetId()
{
    cout << "test GetId function...";
    Network network;
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    network.addUser(u);
    size_t result = network.getId("Jason Chen");
    assert(result == 3);
    cout << "Passed!" << endl;
}
void testAddConnection()
{
    cout << "add connection test...";
    Network network;
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    User *x = new User(4, "Sami Shibli", 2000, 94087, vector<size_t>{0, 1, 2});
    User *y = new User(5, "Drew Smith", 2000, 94087, vector<size_t>{0, 1, 2});
    network.addUser(x);
    network.addUser(u);
    network.addUser(y);
    // Create User objects and add them to the network

    int result = network.addConnection("Sami Shibli", "Drew Smith");
    // Check if the result is 0 (indicating success)
    assert(result == 0);
    cout << "passed" << endl;
}
void testRemoveConnection()
{
    cout << "remove connection test...";
    Network network;
    User *u = new User(3, "Jason Chen", 2000, 94087, vector<size_t>{0, 1, 2});
    User *x = new User(4, "Sami Shibli", 2000, 94087, vector<size_t>{0, 1, 2, 5});
    User *y = new User(5, "Drew Smith", 2000, 94087, vector<size_t>{});
    network.addUser(x);
    network.addUser(u);
    network.addUser(y);
    // Create User objects and add them to the network
    int result = network.removeConnection("Sami Shibli", "Drew Smith");
    // Check if the result is 0 (indicating success)
    assert(result == 0);
    cout << "passed" << endl;
}
void testShortestPath()
{

    std::cout << "testShortestPath...";
    Network network;

    // Create users
    User *userOne = new User(1, "Alice", 1990, 12345, {});
    User *userTwo = new User(2, "Bob", 1985, 23456, {});
    User *userThree = new User(3, "Charlie", 1995, 34567, {});
    User *userFour = new User(4, "David", 1980, 45678, {});

    // Add users to the network
    network.addUser(userOne);
    network.addUser(userTwo);
    network.addUser(userThree);
    network.addUser(userFour);

    // Create connections
    network.addConnection("Alice", "Bob");
    network.addConnection("Bob", "Charlie");
    network.addConnection("Alice", "David");

    // Find shortest path between Alice and Charlie
    std::vector<std::size_t> shortestPath = network.shortestPath(1, 3);

    // Expected shortest path: Alice -> Bob -> Charlie
    std::vector<std::size_t> expectedPath = {1, 2, 3};

    // Compare the actual shortest path with the expected path
    assert(shortestPath == expectedPath);

    std::cout << "Passed!" << std::endl;
}
void testFriendSuggestions()
{

    std::cout << "testSuggestFriends...";
    Network network;

    // Create users
    User *userOne = new User(1, "Alice", 1990, 12345, {2, 3, 4, 5});
    User *userTwo = new User(2, "Bob", 1985, 23456, {1, 3, 6});
    User *userThree = new User(3, "Charlie", 1995, 34567, {1, 2, 4, 6});
    User *userFour = new User(4, "David", 1980, 45678, {1, 3, 5});
    User *userFive = new User(5, "Eva", 1982, 56789, {1, 4});
    User *userSix = new User(6, "Frank", 1988, 67890, {2, 3});

    // Add users to the network
    network.addUser(userOne);
    network.addUser(userTwo);
    network.addUser(userThree);
    network.addUser(userFour);
    network.addUser(userFive);
    network.addUser(userSix);

    // Calculate suggested friends for Alice (user ID: 1)
    size_t score = 0;
    std::vector<size_t> suggestedFriends = network.suggestFriends(1, score);

    std::vector<size_t> expectedSuggestedFriends = {};

    // Compare the actual suggested friends with the expected friends
    assert(suggestedFriends == expectedSuggestedFriends);
    assert(score == 2); // The maximum common friends count is 2

    std::cout << "Passed!" << std::endl;
}
void testGroups()
{
    std::cout << "testGroups...";
    Network network;

    // Creating users belonging to different groups
    User *user1 = new User(1, "Alice", 1990, 12345, std::vector<size_t>{2, 3});
    User *user2 = new User(2, "Bob", 1985, 54321, std::vector<size_t>{1, 3});
    User *user3 = new User(3, "Charlie", 1992, 67890, std::vector<size_t>{1, 2});
    User *user4 = new User(4, "David", 1988, 11111, std::vector<size_t>{5});
    User *user5 = new User(5, "Eva", 1987, 22222, std::vector<size_t>{4});

    network.addUser(user1);
    network.addUser(user2);
    network.addUser(user3);
    network.addUser(user4);
    network.addUser(user5);

    std::vector<std::vector<size_t>> groups = network.groups();

    // Assert the number of groups
    assert(groups.size() == 2);

    std::cout << "Passed!" << std::endl;
}
void testDistanceUser()
{
    cout << "DistanceUserTest...";
    Network network;
    User *userOne = new User(1, "Alice", 2000, 94087, {2, 3});
    User *userTwo = new User(2, "Bob", 2000, 94087, {1, 4});
    User *userThree = new User(3, "Charlie", 2000, 94087, {1});
    User *userFour = new User(4, "David", 2000, 94087, {2});

    network.addUser(userOne);
    network.addUser(userTwo);
    network.addUser(userThree);
    network.addUser(userFour);

    std::size_t to = 0;
    std::size_t id = userOne->getId();
    std::vector<std::size_t> path = network.distanceUser(id, to, 2);

    // The path from user 1 to user 4 with distance 2 is: 1 -> 2 -> 4
    std::size_t endUser = userFour->getId();
    assert(endUser == path[path.size() - 1]);

    // Test for invalid distance, expect empty path and toUser set to -1

    std::cout << "Passed!" << std::endl;
}
void testUserDisplayPost()
{
    cout << "Testing display Post...";
    User *userOne = new User(1, "Alice", 1990, 12345, {2, 3, 4, 5});
    userOne->addPost(new Post(1, "This is my first post!", 10));
    userOne->addPost(new IncomingPost(2, "Private message from Jane.", 15, false, "Jane"));
    userOne->addPost(new IncomingPost(3, "YO what up.", 20, true, "Alice"));

    std::cout << userOne->displayPosts(2, true); // Display 2 most recent public posts
    cout << "passed!" << endl;
}
void testAddPost()
{
    cout << "Testing add UserPost...";
    User *userOne = new User(1, "Alice", 1990, 12345, {2, 3, 4, 5});
    userOne->addPost(new Post(1, "This is my first post!", 10));
    userOne->addPost(new IncomingPost(2, "Private message from Jane.", 15, false, "Jane"));
    userOne->addPost(new IncomingPost(3, "YO what up.", 20, true, "Alice"));
    assert(userOne->getMessagesList().size() == 3);
    cout << "passed!" << endl;
}
void testNetworkAddPost()
{
    cout << "Testing add Network Post...";
    User *userOne = new User(1, "Alice", 2000, 94087, {2, 3});
    User *userTwo = new User(2, "Bob", 2000, 94087, {1, 4});
    User *userThree = new User(3, "Charlie", 2000, 94087, {1});
    User *userFour = new User(4, "David", 2000, 94087, {2});

    network.addUser(userOne);
    network.addUser(userTwo);
    network.addUser(userThree);
    network.addUser(userFour);
    network.addPost(userOne->getId(), "Hello World", 5, false, 0, false);
    Post *currentPost = userOne->getMessagesList();
    assert(currentPost->getMessage() == "Hello World");
    cout << "passed!" << endl;
}
void testNetworkDisplayPost()
{
    cout << "test network Display Post...";
    User *userOne = new User(1, "Alice", 1990, 12345, {2, 3, 4, 5});
    network.addPost(userOne->getId(), "Hello World", 5, false, 0, false);
    std::string username = userOne->getName();
    std::string result = network.displayPosts();
    result = network.displayPosts(username, 1, false);
    assert(result[0] == 'H');

    cout << "passed!" << endl;
}

int main()
{
    testConstructorGetter();
    testAddConnection();
    testRemoveConnection();
    testNumUsersAndAddUser();
    testGetUser();
    testGetId();
    testAddFriend();
    testDeleteFriend();
    testUserGetId();
    testUserGetName();
    testUserGetBirthYear();
    testUserGetFriendsList();
    testUserGetZipCode();
    testShortestPath();
    testDistanceUser();
    testFriendSuggestions();
    testGroups();
    testUserDisplayPost();
    testAddPost();
    testNetworkAddPost();
    testNetworkDisplayPost();

    return 0;
}