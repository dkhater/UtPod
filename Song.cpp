#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(){       //what are we supposed to set here?
    setArtist("\0");
    setTitle("\0");
    setSize(NULL);
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

bool Song::operator >(Song const &rhs)
{
   // return (handicap < rhs.handicap); //May need to transform from current string to all lowercase or all upper
}
bool Song::operator <(Song const &rhs)
{
    //return (handicap < rhs.handicap);
}

bool Song::operator == (Song const &s1)
{
    return ( (this->artist == s1.artist) &&
            (this->title == s1.title) &&
            (this->songSize == s1.songSize)
             );
}


