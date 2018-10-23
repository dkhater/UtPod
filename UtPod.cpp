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
    if(memSize > 0){
        SongNode* temp;
        temp = (SongNode*)malloc(sizeof(SongNode));
        temp->s = s;
        temp->next = songs;
        songs = temp;
        memSize = memSize - s.getSize();
        cout << memSize<< endl;
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
        memSize = memSize + s.getSize();                     // Increase memSize
        free(temp);
        return SUCCESS;
    }
    else{
        return NOT_FOUND;
    }

}

void UtPod::shuffle() {

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
    return memSize;                 // We changed this

}

UtPod::~UtPod(){

}
