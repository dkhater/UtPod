#include <cstdlib>
#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(){        //Default song settings: set blank strings and null size.
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

bool Song::operator >(Song const &rhs)  //May need to transform from current string to all lowercase or all upper
{
    if(this->artist > rhs.artist){
        return true;
    }
    else if(this->artist < rhs.artist){
        return false;
    }
    else if(this->artist == rhs.artist){
        if(this->title > rhs.title){
            return true;
        }
        else if(this->title < rhs.title){
            return false;
        }
        else if(this->title == rhs.title){
            if(this->songSize > rhs.songSize){
                return true;
            }
            else if(this->songSize < rhs.songSize){
                return false;
            }
            else
                cout << "Equal" << endl;                // For debugging purposes
        }

    }

}
bool Song::operator <(Song const &rhs) //May need to transform from current string to all lowercase or all upper
{
    if(this->artist < rhs.artist){
        return true;
    }
    else if(this->artist > rhs.artist){
        return false;
    }
    else if(this->artist == rhs.artist){
        if(this->title < rhs.title){
            return true;
        }
        else if(this->title > rhs.title){
            return false;
        }
        else if(this->title == rhs.title){
            if(this->songSize < rhs.songSize){
                return true;
            }
            else if(this->songSize > rhs.songSize){
                return false;
            }
            else
                cout << "Equal" << endl;                // For debugging purposes
        }

    }

}

bool Song::operator == (Song const &s1)
{
    return ( (this->artist == s1.artist) &&
            (this->title == s1.title) &&
            (this->songSize == s1.songSize)
             );
}


