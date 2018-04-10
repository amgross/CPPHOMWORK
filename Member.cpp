//
// Created by אריה גרוס on 27 מרץ 2018.
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
    member.isOrigin = false;
    if (find(this->folowing->begin(), this->folowing->end(), member) == this->folowing->end()) {
        this->folowing->push_back(member);
        //cout<<endl<<endl<<endl<<member.folowers->size()<<endl<<endl;
        this->isOrigin = false;
        member.folowers->push_back(*this);
        this->isOrigin = true;
        // cout<<endl<<endl<<member.folowers->size()<<endl<<endl;

    }
}

void Member::unfollow(Member member) {
    member.isOrigin = false;
    //from https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

    //remove( member.folowers->begin(), member.folowers->end(), member );
    member.folowers->erase(remove(member.folowers->begin(), member.folowers->end(), *this),member.folowers->end());
    this->folowing->erase(remove(this->folowing->begin(), this->folowing->end(), member),this->folowing->end());

}


int Member::count() {
    return  numOfUsers;
}





