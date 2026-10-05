#ifndef EPISODE_H
#define EPISODE_H

#include <iomanip>
#include <iostream>
#include <string>

// ============================================================
// Episode : satu episode dalam sebuah Drama.
// Episode adalah "part of" Drama (Composition) -> disimpan sebagai bagian dari Drama.
// ============================================================
class Episode {
private:
    int number;
    std::string title;
    int durationMinutes;
    double viewerRating;  // rating penonton (%)

public:
    Episode(int number, const std::string& title, int durationMinutes, double viewerRating)
        : number(number), title(title),
          durationMinutes(durationMinutes), viewerRating(viewerRating) {}

    int getNumber() const { return number; }
    const std::string& getTitle() const { return title; }
    int getDurationMinutes() const { return durationMinutes; }
    double getViewerRating() const { return viewerRating; }

    void setNumber(int number) { this->number = number; }
    void setTitle(const std::string& title) { this->title = title; }
    void setDurationMinutes(int durationMinutes) { this->durationMinutes = durationMinutes; }
    void setViewerRating(double viewerRating) { this->viewerRating = viewerRating; }

    void display() const {
        std::cout << "    " << std::right << std::setw(2) << number << " | "
                  << std::left << std::setw(50) << title << " | "
                  << std::right << std::setw(3) << durationMinutes << " menit | "
                  << std::fixed << std::setprecision(1) << std::setw(5) << viewerRating << "%\n";
    }
};

#endif
