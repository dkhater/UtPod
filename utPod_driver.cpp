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
    //myfile.open(argv[1]);
    myfile.open("Input.txt");

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

/*
int main(){
    UtPod u;

    Song s1("ABBA", "Dancing Queen", 4);
    int result = u.addSong(s1);
    cout << "result = " << result << endl;
    u.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = u.addSong(s2);
    cout << "result = " << result << endl;
    u.showSongList();

    Song s4("Coldplay", "Paradise", 10);        //Lowercase is worth more than upper case
    result = u.addSong(s4);
    cout << "result = " << result << endl;
    u.showSongList();

    Song s5("COLDPLAY", "PARADISE", 2);         //This was to test case sensitivity - it does make a difference
    result = u.addSong(s5);
    cout << "result = " << result << endl;
    u.showSongList();

    Song s3("Drake", "Hotline Bling", 7);
    result = u.addSong(s3);
    cout << "result = " << result << endl;
    u.showSongList();

    Song s6("DRAKE", "Hotline Bling", 7);
    result = u.addSong(s6);
    cout << "result = " << result << endl;
    u.showSongList();

    u.shuffle();
    u.showSongList();

    bool answer;
    answer = s1 == s1;
    cout << "answer = " << answer << endl;

    answer = s3 > s4;
    cout << "answer = " << answer << endl;

    answer = s5 > s4;
    cout << "answer = " << answer << endl;

    answer = s1 < s3;
    cout << "answer = " << answer << endl;

    answer = s6 == s3;
    cout << "answer = " << answer << endl;

    u.sortSongList();
    u.showSongList();

    return 0;
}
*/
