//
// Created by Neha S on 10/18/18.
//
#include <cstdlib>
#include <iostream>


using namespace std;

#ifndef HW5_UTPOD_UTPOD_H
#define HW5_UTPOD_UTPOD_H

#endif //HW5_UTPOD_UTPOD_H

//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    UtPod();
    UtPod(int size);

    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();

    int getTotalMemory();
    int getRemainingMemory();
    int getNumSongsInUtPod();

    ~UtPod();

};



#endif
