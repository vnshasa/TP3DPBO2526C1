#ifndef DRAMA_H
#define DRAMA_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Actor.h"
#include "Director.h"
#include "Episode.h"
#include "Writer.h"

// ============================================================
// Drama : kelas utama yang memiliki data drama.
// Aggregation : Director, Writer, dan Actor tetap dapat hidup
//               di luar objek Drama.
// Composition : Episode menjadi bagian dari Drama.
// ============================================================
class Drama {
private:
    std::string title;
    int year;
    std::string genre;
    std::string broadcaster;

    // Aggregation: objek Director dan Writer dibuat di luar Drama.
    Director* director;
    Writer* writer;

    // Aggregation + Array of Object: Drama menyimpan referensi Actor
    // yang dibuat di luar Drama.
    std::vector<Actor*> cast;

    // Composition + Array of Object: Episode disimpan sebagai objek
    // milik Drama.
    std::vector<Episode> episodes;

public:
    Drama(const std::string& title, int year, const std::string& genre,
          const std::string& broadcaster,
          Director* director, Writer* writer)
        : title(title), year(year), genre(genre), broadcaster(broadcaster),
          director(director), writer(writer) {}

    // ---------- Getter ----------
    const std::string& getTitle() const { return title; }
    int getYear() const { return year; }
    const std::string& getGenre() const { return genre; }
    const std::string& getBroadcaster() const { return broadcaster; }
    Director* getDirector() const { return director; }
    Writer* getWriter() const { return writer; }
    std::vector<Actor*> getCast() const { return cast; }
    std::vector<Episode> getEpisodes() const { return episodes; }
    int getTotalEpisodes() const { return static_cast<int>(episodes.size()); }

    // ---------- Setter ----------
    void setTitle(const std::string& title) { this->title = title; }
    void setYear(int year) { this->year = year; }
    void setGenre(const std::string& genre) { this->genre = genre; }
    void setBroadcaster(const std::string& broadcaster) { this->broadcaster = broadcaster; }
    void setDirector(Director* director) { this->director = director; }
    void setWriter(Writer* writer) { this->writer = writer; }
    void setCast(const std::vector<Actor*>& cast) { this->cast = cast; }
    void setEpisodes(const std::vector<Episode>& episodes) { this->episodes = episodes; }

    // ---------- Perhitungan ----------
    int getTotalDuration() const {
        int total = 0;
        for (const Episode& ep : episodes) total += ep.getDurationMinutes();
        return total;
    }

    double getAverageRating() const {
        if (episodes.empty()) return 0.0;
        double sum = 0.0;
        for (const Episode& ep : episodes) sum += ep.getViewerRating();
        return sum / episodes.size();
    }

    // ---------- Tampilan ----------
    void display() const {
        std::cout << std::string(64, '-') << "\n";
        std::cout << "DRAMA: " << title << "\n";
        std::cout << std::string(64, '-') << "\n";
        std::cout << "  Tahun / Genre : " << year << " / " << genre << "\n";
        std::cout << "  Penyiar       : " << broadcaster << "\n";
        std::cout << "  Episode       : " << episodes.size() << " episode, total "
                  << getTotalDuration() << " menit\n";
        std::cout << "  Rata2 Rating  : " << std::fixed << std::setprecision(1)
                  << getAverageRating() << "%\n";

        std::vector<const Person*> credits;
        if (director != nullptr) credits.push_back(director);
        if (writer != nullptr) credits.push_back(writer);
        for (const Actor* actor : cast) {
            if (actor != nullptr) credits.push_back(actor);
        }

        std::cout << "\n  >> KREDIT (Sutradara, Penulis, Pemeran) - " << credits.size() << " orang\n";
        for (const Person* person : credits) person->displayInfo();

        std::cout << "\n  >> DAFTAR EPISODE\n";
        std::cout << "    No | Judul                                              | Durasi    | Rating\n";
        std::cout << "    ---+----------------------------------------------------+-----------+-------\n";
        for (const Episode& ep : episodes) ep.display();
        std::cout << "\n";
    }
};

#endif
