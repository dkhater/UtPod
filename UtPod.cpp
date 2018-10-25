#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;


UtPod::UtPod() {
    //allocate space as linked list node and set size to default 512 MB

    songs = NULL;
    memSize = MAX_MEMORY;

}

UtPod::UtPod(int size) {
    //allocate space as linked list node and set size to parameter value
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else{
        memSize = size;
    }


}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() > s.getSize()){   //get remaining mem must be larger than the song size
        SongNode* temp;
        temp = new SongNode(); // like a malloc but declares the pointer
        temp->s.setSize(s.getSize());
        temp->s.setTitle(s.getTitle());
        temp->s.setArtist(s.getArtist());
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }
    else{
        return NO_MEMORY;
    }


}

int UtPod::removeSong(Song const &s) {
    if(memSize != MAX_MEMORY){
        SongNode* temp;
        temp = songs;
        songs = temp->next;
        memSize = memSize + s.getSize();
        delete(temp);
        return SUCCESS;
    }
    else{
        return NOT_FOUND;
    }

}

void UtPod::shuffle() {
    //mix 500 times
}

void UtPod::showSongList() {
    if(songs == NULL)
        return;
    else{
        SongNode* ptr = songs;
        while(ptr != NULL){
            cout << ptr->s.getArtist()<< ", " << ptr->s.getTitle() << endl;
            ptr = ptr->next;
        }

    }

}

void UtPod::sortSongList() {

}

int UtPod::getRemainingMemory() {
    int currentmem = 0;
    SongNode* temp = songs;

    while (songs != NULL){
        currentmem = currentmem + temp->s.getSize();
        temp->next;
    }
    return 512-currentmem;

}

UtPod::~UtPod(){

}
