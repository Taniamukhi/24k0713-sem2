#include <iostream>
#include <string>
using namespace std;

class mediafile {
protected:
    string filepath;
    int filesize;

public:
    mediafile(string path, int size) : filepath(path), filesize(size) {
        cout<< "Mediafile constructor" << endl;
    }

    virtual void play() {
        cout<< "Playing media: " << filepath << endl;
    }

    virtual void stop() {
        cout<< "Media stopped. " << filepath << endl;
    }

    virtual ~mediafile() {
        cout<< "Mediafile destructor" << endl;
    }
};

class visualmedia : virtual public mediafile {
protected:
    string resolution;

public:
    visualmedia(const string &path, int size, string reso) : mediafile(path, size), resolution(reso) {
        cout<< "VisualMedia Constructor" << endl;
    }

    void show() {
        cout<< "Displaying visual media: " << resolution << endl;
    }

    ~visualmedia() {
        cout<< "VisualMedia destructor" << endl;
    }
};

class audiomedia : virtual public mediafile {
protected:
    int rate;
public:
    audiomedia(const string &path, int size, int r) : mediafile(path, size), rate(r) {
        cout<< "AudioMedia Constructor" << endl;
    }

    void play() {
        cout<< "Playing audio media at " << rate << " Hz" << endl;
    }

    ~audiomedia() {
        cout<< "AudioMedia destructor" << endl;
    }
};

class imagefile : public visualmedia {
public:
    imagefile(const string &path, int size, const string &reso) : mediafile(path, size), visualmedia(path, size, reso) {
        cout<< "ImageFile Constructor" << endl;
    }

    void play() override {
        cout<< "Cannot play image, but showing it." << endl;
        show();
    }

    ~imagefile() {
        cout<< "ImageFile destructor" << endl;
    }
};

class audiofile : public audiomedia {
public:
    audiofile(const string &path, int size, int r) : mediafile(path, size), audiomedia(path, size, r) {
        cout<< "AudioFile Constructor" << endl;
    }

    void play() override {
        audiomedia::play();
    }

    ~audiofile() {
        cout<< "AudioFile destructor" << endl;
    }
};

class videofile : public visualmedia, public audiomedia {
public:
    videofile(const string &path, int size, const string &reso, int r)
        : mediafile(path, size), visualmedia(path, size, reso), audiomedia(path, size, r) {
        cout<< "VideoFile Constructor" << endl;
    }

    void play() override {
        cout<< "Playing video with resolution " << resolution << " and audio at " << rate << " Hz" << endl;
    }

    ~videofile() {
        cout<< "VideoFile destructor" << endl;
    }
};

int main() {
    mediafile *media[] = {
        new imagefile("photo.img", 200, "120x324"),
        new audiofile("song.mp3", 100, 120),
        new videofile("film.mp4", 800, "1920x1080", 44100),
    };
    for (mediafile *med : media) {
        med->play();
        cout << "....\n";
    }
    for (mediafile *med : media) {
        delete med;
    }
    return 0;
}
