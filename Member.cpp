//
// Created by אריה גרוס on 27 מרץ 2018.
//

#include "Member.h"



int Member::numOfUsers = 0;
long Member::nextID = 0;

Member::Member(){
    folowing = new vector<long>;
    folowers = new vector<long>;

    numOfUsers++;
    ID = nextID;
    nextID++;

    }
Member::~Member(){
        numOfUsers--;

    //delete folowing;
    //delete folowers;

    }
int Member::numFollowers(){
        return this->folowers->size();
    }
int Member::numFollowing(){
        return this->folowing->size();
    }
void Member::follow(Member member) {
    if (find(this->folowing->begin(), this->folowing->end(), member.ID) == this->folowing->end()) {


        this->folowing->push_back(member.ID);
        //cout<<endl<<endl<<endl<<member.folowers->size()<<endl<<endl;
        member.folowers->push_back(this->ID);
        // cout<<endl<<endl<<member.folowers->size()<<endl<<endl;

    }
    numOfUsers++;
}

void Member::unfollow(Member member) {
    //from https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    numOfUsers++;
    member.folowers->erase(std::remove(member.folowers->begin(), member.folowers->end(), this->ID), member.folowers->end());
    this->folowing->erase(std::remove(this->folowing->begin(),this->folowing->end(), member.ID), this->folowing->end());
    //vector::erase( member.folowers->begin(), member.folowers->end(), member.ID );
    //member.folowers.erase(remove(member.folowers.begin(), member.folowers.end(), this),member.folowers.end());
    //this->folowing.erase(remove(this->folowing.begin(), this->folowing.end(), member),this->folowing.end());
}


int Member::count() {
    return  numOfUsers;
}





