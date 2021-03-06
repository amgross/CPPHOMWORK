//
// Created by amgross .
//
#pragma once
#ifndef PROJECT_MEMBER_H
#define PROJECT_MEMBER_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Member {
private:
    bool isOrigin;//flag for the destructor that it is not copy of member
    static int numOfUsers;
    static long nextID;
    long  ID;
    vector<Member> *folowing;
    vector<Member> *folowers;

public:
    Member();

    ~Member();

    int numFollowers();

    int numFollowing();

    void follow(Member member);
    void unfollow(Member member);
    static int count();
    bool operator==(const Member &rhs) const {
        return rhs.ID == ID;
    }
};




#endif //PROJECT_MEMBER_H
