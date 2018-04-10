//
// Created by amgross .
//

#include "Member.h"



int Member::numOfUsers = 0;
long Member::nextID = 0;

Member::Member(){
    isOrigin = true;
    folowing = new vector<Member>;
    folowers = new vector<Member>;
    numOfUsers++;
    ID = nextID;
    nextID++;
}
Member::~Member(){
    if(isOrigin) {

        numOfUsers--;
        // delete from other followers and following
        for(Member member : *folowing){//https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop/12702744
            this->unfollow(member);
        }
        for(Member member : *folowers){//https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop/12702744
            member.unfollow(*this);
        }
        delete this->folowing;
        delete this->folowers;
    }

}
int Member::numFollowers(){
    return this->folowers->size();
}
int Member::numFollowing(){
    return this->folowing->size();
}
void Member::follow(Member member) {
    member.isOrigin = false; //it is just copy!!!
    if ((!(*this==member))&&find(this->folowing->begin(), this->folowing->end(), member) == this->folowing->end()) {
        this->folowing->push_back(member);
        this->isOrigin = false; //sending copy of 'this' to the vector
        member.folowers->push_back(*this);
        this->isOrigin = true; //canging back the original

    }
}

void Member::unfollow(Member member) {
    member.isOrigin = false;
    //from https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    member.folowers->erase(remove(member.folowers->begin(), member.folowers->end(), *this),member.folowers->end());//remove 'this' from the followers of the member
    this->folowing->erase(remove(this->folowing->begin(), this->folowing->end(), member),this->folowing->end());//remove 'member' from the list that 'this' following

}


int Member::count() {
    return  numOfUsers;
}





