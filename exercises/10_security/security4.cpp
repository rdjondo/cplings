#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <unordered_map>

// security4.cpp
// Make me pass the test! Go to the folder hint if you want a hint :)

// We sometimes encourage you to keep trying things on a given exercise,
// even after you already figured it out. 


struct Song;

struct Song {
    std::string name_;
    Song() : name_("") {
        //std::cout << "Creating empty song\n";
    };
    Song(const std::string & name): name_(name) {};
    Song(const std::string && name) : name_(name) {
        std::cout << "Move song name "<< name_ <<"\n";
    }
    // Song(const Song & song) : name_(song.name_) {
    //     std::cout << "Copy song "<< name_ <<"\n";
    // }
    Song& operator=(const Song&) = delete;
    Song& operator=(const Song&& song) {
        name_ = std::move(song.name_);
        std::cout << "Assign-Move song "<< name_ <<"\n";
        return *this;
    }   
    Song(const Song && song) : name_(std::move(song.name_)) {
        std::cout << "Move song "<< name_ <<"\n";
    }
    static std::unordered_map<size_t, ptrdiff_t> alloc_tracker;

    static void * operator new[](const size_t num_songs) noexcept{
        Song * s = nullptr;
        try {
            s = ::new Song[num_songs];
            size_t song_address_code = reinterpret_cast<size_t>(s);
            alloc_tracker[song_address_code] = num_songs*sizeof(Song);
            std::cout << "Allocated "<< std::dec << alloc_tracker[song_address_code] <<"B at " << std::hex << song_address_code<<"\n";
        }
        catch(std::bad_alloc){
            std::cout<<"Program is probably running out of memory ..."<<"\n";
        } 
        return s;
    }
    static void operator delete[](void * song_ptr) noexcept{
        Song * s = static_cast<Song *>(song_ptr);
        size_t song_address_code = reinterpret_cast<size_t>(s);
        std::cout << "De-allocated "<< std::dec << alloc_tracker[song_address_code] <<"B at " << std::hex << song_address_code<<"\n";
        alloc_tracker.erase(song_address_code);
        ::delete[](s);
    }
};

std::unordered_map<size_t, ptrdiff_t> Song::alloc_tracker;

class MediaPlayer {
    static constexpr size_t default_max_num_songs = 4;
    Song* song_ar;
    MediaPlayer() = delete;
public:
    MediaPlayer(const size_t max_num_songs) {
        song_ar = static_cast<Song*>(Song::operator new[](max_num_songs));
        std::cout<<"Created MediaPlayer song array at " << std::hex << song_ar <<"\n";
    }
    ~MediaPlayer(){
        std::cout<<"Deleting MediaPlayer song array at " << std::hex << song_ar <<"\n";
        Song::operator delete[](song_ar);
    }
    void set_song(std::string name, const unsigned short  index){
        song_ar[index] = std::move(Song(std::move(name)));
    }
    std::string get_song_name(const unsigned char index) const{
        return song_ar[index].name_;
    }
};


#include <catch2/catch.hpp>

TEST_CASE("test_security4_0") {
    MediaPlayer p(300);
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    p.set_song("We are in an orchestra", 256);
    std::cout << "TESTING : " << p.get_song_name(0) << "\n";
    std::cout << "TESTING : " << p.get_song_name(256) << "\n";
    p.set_song("The pirates song", 4);
    REQUIRE(p.get_song_name(0) == "Old MacDonald had a farm");
}

TEST_CASE("test_security4_1") {
    MediaPlayer p(80'000);
    p.set_song("Old MacDonald had a farm", 0);
    p.set_song("When the circus comes to town", 1);
    p.set_song("We are in an orchestra", -1);
    REQUIRE(p.get_song_name(1) == "When the circus comes to town");
}

