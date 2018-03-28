//
// Created by אריה גרוס on 27 מרץ 2018.
//

#include "Member.h"



int Member::numOfUsers = 0;
long Member::nextID = 0;

Member::Member(){
    folowing = new vector<Member>;
    folowers = new vector<Member>;
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
void Member::follow(Member member){
        this->folowing->push_back(member);
        //cout<<endl<<endl<<endl<<member.folowers->size()<<endl<<endl;
        member.folowers->push_back(*this);
       // cout<<endl<<endl<<member.folowers->size()<<endl<<endl;
    }


void Member::unfollow(Member member) {
    //from https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

    remove( member.folowers->begin(), member.folowers->end(), member );
    //member.folowers.erase(remove(member.folowers.begin(), member.folowers.end(), this),member.folowers.end());
    //this->folowing.erase(remove(this->folowing.begin(), this->folowing.end(), member),this->folowing.end());
}


int Member::count() {
    return  numOfUsers;
}





