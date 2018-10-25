#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"

using namespace std;


UtPod::UtPod() {
    // set size to default value
    songs = NULL;
    memSize = MAX_MEMORY;

}

UtPod::UtPod(int size) {
    // set size to parameter value
    songs = NULL;
    if(size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else{
        memSize = size;
    }
}

int UtPod::addSong(Song const &s) {
    if(getRemainingMemory() >= s.getSize()){   // get remaining mem must be larger than the song size
        SongNode* temp;
        temp = new SongNode();                // like a malloc but declares the pointer
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
    if(getCurrentMemory() != MAX_MEMORY){       //This is just deleting the last song put in
        SongNode* temp;                         //I think we need to search and remove a specific one
        temp = songs;
        songs = temp->next;
        delete(temp);
        return SUCCESS;
    }
    else{
        return NOT_FOUND;
    }

}

void UtPod::shuffle() {
    //mix 500 times
    int shuffleTimes = 10;                  //Changing this number for testing purposes
    int ptr1position, ptr2position;
    Song temp;
    SongNode* ptr1 = songs;
    SongNode* ptr2 = songs;
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    while(shuffleTimes != 0){
        ptr1 = songs;
        ptr2 = songs;

        ptr1position = (rand() % getNumSongsInUtPod());
        ptr2position = (rand() % getNumSongsInUtPod());

        for(int i = 0; i < ptr1position; i++){
            ptr1 = ptr1->next;
        }

        for(int j = 0; j < ptr2position; j++){
            ptr2 = ptr2->next;
        }


        temp = ptr1->s;         //Swap two songs
        ptr1->s = ptr2->s;
        ptr2->s = temp;

        shuffleTimes--;
    }


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
    int currentMem = getCurrentMemory();
    return MAX_MEMORY-currentMem;

}

int UtPod::getCurrentMemory(){
     memSize = 0;
     SongNode* temp;
     temp = songs;
     while (temp != NULL){
         memSize = memSize + temp->s.getSize();
         temp = temp->next;
     }
     return memSize;
}

int UtPod::getNumSongsInUtPod(){
    int numSongs = 0;
    SongNode* temp;
    temp = songs;
    while (temp != NULL){
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}

UtPod::~UtPod(){
    if(songs != NULL){
        SongNode* temp;
        temp = songs;
        songs = temp->next;
        delete(temp);
    }
}
