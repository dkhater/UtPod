//UTPod_driver

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"
#include "UtPod.h"

using namespace std;

enum cmd_code {
    Add,
    Remove,
    Shuffle,
    Show,
    Sort,
    Blank
};

cmd_code changeit (std::string const& inCmd){
    if (inCmd == "Add") return Add;
    else if (inCmd == "Remove") return Remove;
    else if (inCmd == "Shuffle") return Shuffle;
    else if (inCmd == "Show") return Show;
    else if (inCmd == "Sort") return Sort;
    else return Blank;
}
int main(int argc, char *argv[]) {
    UtPod t;
    string cmd;
    ifstream myfile;
    myfile.open(argv[1]);

    if (myfile.is_open()){

        while (getline (myfile,cmd)) {
            string artist, title, Size;
            int size;
            Song s;
            switch (changeit(cmd)) {
                case Add:
                    getline(myfile, artist);
                    getline(myfile, title);
                    getline(myfile, Size);
                    size = atoi(Size.c_str());
                    s = Song (artist, title, size);
                    t.addSong(s);
                    break;

                case Remove:
                    getline(myfile, artist);
                    getline(myfile, title);
                    getline(myfile, Size);
                    size = atoi(Size.c_str());
                    s = Song (artist, title, size);
                    t.removeSong(s);
                    break;

                case Shuffle:
                    t.shuffle();
                    break;

                case Show:
                    t.showSongList();
                    break;

                case Sort:
                    t.sortSongList();
                    break;
                default:
                    break;
            }
        }

    }
    else cout << "Unable to Open File";

    myfile.close();

    return 0;

}