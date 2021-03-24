#include <iostream>
#include <string>
#include <array>
#include <memory>

// security2.cpp
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

const std::string convert_title_to_upper_case(std::shared_ptr<MediaPlayer> p, int index){
    auto songname = p->get_song_name(index);
    for(auto & c : songname){
        c = std::toupper(c);
    }
    return songname;
}

const std::string convert_title_to_lower_case(std::shared_ptr<MediaPlayer> p, int index){
    auto songname = p->get_song_name(index);
    for(auto & c : songname){
        c = std::tolower(c);
    }
    return songname;
}

void make_upper_0_lower_1(MediaPlayer &p){
    auto shared0 = std::shared_ptr<MediaPlayer>(&p);
    std::string s0_upper = convert_title_to_upper_case(shared0, 0);
    std::cout << s0_upper << "\n";

    auto shared1 = std::shared_ptr<MediaPlayer>(&p);
    std::string s1_lower = convert_title_to_lower_case(shared1, 1);
    std::cout << s1_lower << "\n";
}

#include <catch2/catch.hpp>

TEST_CASE("test_security2_0")
{
    MediaPlayer p;
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    make_upper_0_lower_1(p);
}
