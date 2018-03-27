//
// Created by אריה גרוס on 27 מרץ 2018.
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
    vector<Member> folowing;
    vector<Member> folowers;

public:
    Member();

    ~Member();

    int numFollowers();

    int numFollowing();

    void follow(Member member);
    void unfollow(Member member);
    static int count();
};





#endif //PROJECT_MEMBER_H
