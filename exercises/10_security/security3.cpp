#include <iostream>
#include <string>
#include <array>

// security3.cpp
// Make me pass the tests!
// Fix 1: add_song writes to song_ar[index] without checking bounds.
//        Add bounds checking so it silently ignores out-of-range indices.
// Fix 2: get_song_name accesses song_ar[index] without checking bounds.
//        Add bounds checking to return "" for out-of-range indices.
// This exercise demonstrates buffer overflow and its mitigation.


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
    void add_song(std::string name, size_t index) {
        // Fix: writing to song_ar[index] without bounds checking is a buffer overflow.
        // Add a bounds check so that out-of-range writes are silently ignored.
        song_ar[index] = Song(name); // unsafe: index 4 is out of bounds for a 4-element array!
    }
    std::string get_song_name(int index) const{
        // Fix: accessing song_ar[index] without bounds checking is undefined behaviour.
        // Return "" for any index outside [0, max_num_songs).
        return song_ar[index].name_;
    }
};


#include <catch2/catch_test_macros.hpp>

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

