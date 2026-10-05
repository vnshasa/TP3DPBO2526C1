#ifndef DRAMACATALOG_H
#define DRAMACATALOG_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Drama.h"

// ============================================================
// DramaCatalog : agregat yang menyimpan referensi ke Drama.
// Objek Drama dibuat di luar DramaCatalog, sehingga Drama tetap
// dapat hidup walaupun DramaCatalog dihapus.
// ============================================================
class DramaCatalog {
private:
    std::string name;
    std::vector<Drama*> dramas;

public:
    explicit DramaCatalog(const std::string& name) : name(name) {}

    // ---------- Getter ----------
    const std::string& getName() const { return name; }
    std::vector<Drama*> getDramas() const { return dramas; }

    // ---------- Setter ----------
    void setName(const std::string& name) { this->name = name; }
    void setDramas(const std::vector<Drama*>& dramas) { this->dramas = dramas; }

    Drama* findDrama(const std::string& title) {
        for (Drama* drama : dramas) {
            if (drama != nullptr && drama->getTitle() == title) return drama;
        }
        return nullptr;
    }

    int getTotalDramas() const { return static_cast<int>(dramas.size()); }

    int getTotalEpisodes() const {
        int total = 0;
        for (const Drama* drama : dramas) {
            if (drama != nullptr) total += drama->getTotalEpisodes();
        }
        return total;
    }

    void displaySummary() const {
        std::cout << "No | Judul                        | Tahun | Genre                        | Eps | Avg Rating\n";
        std::cout << "---+------------------------------+-------+------------------------------+-----+-----------\n";
        for (size_t i = 0; i < dramas.size(); ++i) {
            const Drama* d = dramas[i];
            if (d == nullptr) continue;
            std::cout << std::right << std::setw(2) << (i + 1) << " | "
                      << std::left << std::setw(28) << d->getTitle() << " | "
                      << std::right << std::setw(5) << d->getYear() << " | "
                      << std::left << std::setw(28) << d->getGenre() << " | "
                      << std::right << std::setw(3) << d->getTotalEpisodes() << " | "
                      << std::fixed << std::setprecision(1)
                      << std::setw(9) << d->getAverageRating() << "%\n";
        }
        std::cout << "\n";
    }

    void displayAll() const {
        std::cout << "KATALOG       : " << name << "\n";
        std::cout << "Total Drama   : " << getTotalDramas() << "\n";
        std::cout << "Total Episode : " << getTotalEpisodes() << "\n\n";

        displaySummary();
        for (const Drama* drama : dramas) {
            if (drama != nullptr) drama->display();
        }
    }
};

#endif
