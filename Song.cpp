#include <cstdlib>
#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(){       //what are we supposed to set here?

}

Song::Song(string artistName, string songName, int sizeSong){
    setArtist(artistName);
    setTitle(songName);
    setSize(sizeSong);

}
void Song::setArtist(string artistName){
    artist = artistName;

}
void Song::setTitle(string titleName){
    title = titleName;

}
void Song::setSize(int siz){
    songSize = siz;

}
string Song::getArtist() const{
    return artist;

}
string Song::getTitle() const{
    return title;

}
int Song::getSize() const{
    return songSize;
}

