//
// Created by Neha S on 10/18/18.
//

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HW5_UTPOD_SONG_H
#define HW5_UTPOD_SONG_H

#endif //HW5_UTPOD_SONG_H

//DOCUMENT HERE

#ifndef SONG_H
#define SONG_H

//Song class declaration
class Song
{
    private:
        string artist;
        string title;
        int songSize;


    public:
        Song();
        Song(string, string, int);
        void setArtist(string);
        void setTitle(string);
        void setSize(int);
        string getArtist() const;
        string getTitle() const;
        int getSize() const;

};



#endif
