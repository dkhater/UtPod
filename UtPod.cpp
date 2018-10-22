#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

UtPod(){
    //allocate space as linked list node and set size to default 512 MB

}

UtPod(int size){
    //allocate space as linked list node and set size to parameter value

}

int addSong(Song const &s){

}

int removeSong(Song const &s){

}

void shuffle(){

}

void showSongList(){

}

void sortSongList(){

}

int getTotalMemory() {
    return memSize;
}

int getRemainingMemory(){

}

~UtPod();