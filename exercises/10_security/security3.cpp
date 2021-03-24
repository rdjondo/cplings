#include <iostream>
#include <string>
#include <array>

// security3.cpp
// Make me pass the test! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 


struct Song {
    std::string name_;
    Song() : name_("") {};
    Song(const std::string & name) : name_(name) {};
};
class MediaPlayer {
    static constexpr size_t max_num_songs = 4;
    std::array<Song, max_num_songs> song_ar;
public:
    MediaPlayer() {} 
    void set_song(std::string name, int index){
        song_ar[index] = Song(name);
    }
    std::string get_song_name(int index) const{
        return song_ar[index].name_;
    }
};


#include <catch2/catch.hpp>

TEST_CASE("test_security3_0") {
    MediaPlayer p;
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    p.set_song("We are in an orchestra", 2);
    p.set_song("Hotel California", 3);
    p.add_song("The pirates song", 4);
    REQUIRE(p.get_song_name(0) == "Old MacDonald had a farm");
}

TEST_CASE("test_security3_1") {
    MediaPlayer p;
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    REQUIRE(p.get_song_name(123123) == "");
}

