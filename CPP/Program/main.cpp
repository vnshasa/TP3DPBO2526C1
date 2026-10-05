#include <iostream>
#include <string>
#include <vector>

#include "Actor.h"
#include "Director.h"
#include "Drama.h"
#include "DramaCatalog.h"
#include "Episode.h"
#include "Writer.h"

// ---------- Helper tampilan ----------
void printBanner(const std::string& text) {
    std::cout << "\n" << std::string(64, '=') << "\n";
    std::cout << "  " << text << "\n";
    std::cout << std::string(64, '=') << "\n\n";
}

// ---------- Pembuat data ----------
// Director, Writer, dan Actor dibuat di main (di luar Drama),
// lalu Drama hanya menyimpan referensinya -> Aggregation.
Drama createReply1988(Director& director, Writer& writer,
                      Actor& actor1, Actor& actor2, Actor& actor3) {
    Drama drama("Reply 1988", 2015, "Family, Romance, Drama", "tvN", &director, &writer);
    drama.setCast(std::vector<Actor*>{&actor1, &actor2, &actor3});

    std::vector<Episode> episodes;
    episodes.push_back(Episode(1, "Hand in Hand", 84, 6.118));
    episodes.push_back(Episode(2, "The One Thing You're Mistaken About Me", 85, 6.836));
    episodes.push_back(Episode(3, "Not Guilty If You're Rich, Guilty If You're Poor", 81, 7.777));
    episodes.push_back(Episode(4, "Can't Help~ ing", 71, 8.251));
    episodes.push_back(Episode(5, "Ready for Winter", 86, 10.145));
    episodes.push_back(Episode(6, "The First Snow Is Coming", 77, 9.263));
    episodes.push_back(Episode(7, "To You", 88, 11.035));
    episodes.push_back(Episode(8, "Warm Words", 86, 11.293));
    episodes.push_back(Episode(9, "Crossing the Line", 92, 11.563));
    episodes.push_back(Episode(10, "Memory", 79, 13.360));
    episodes.push_back(Episode(11, "Three Prophecies", 99, 12.228));
    episodes.push_back(Episode(12, "What It Means To Love Someone", 91, 13.060));
    episodes.push_back(Episode(13, "Superman is Back", 95, 12.858));
    episodes.push_back(Episode(14, "Don't Worry, My Dear", 93, 15.133));
    episodes.push_back(Episode(15, "Between Love and Friendship", 94, 15.192));
    episodes.push_back(Episode(16, "Life is an Irony - Part I", 92, 15.372));
    episodes.push_back(Episode(17, "Life is an Irony - Part II", 105, 15.472));
    episodes.push_back(Episode(18, "Goodbye, My First Love", 97, 17.191));
    episodes.push_back(Episode(19, "You Did Your Best", 107, 17.597));
    drama.setEpisodes(episodes);
    return drama;
}

Drama createCrashLandingOnYou(Director& director, Writer& writer,
                              Actor& actor1, Actor& actor2, Actor& actor3) {
    Drama drama("Crash Landing on You", 2019, "Romance, Drama", "tvN", &director, &writer);
    drama.setCast(std::vector<Actor*>{&actor1, &actor2, &actor3});

    std::vector<Episode> episodes;
    episodes.push_back(Episode(1, "Episode 1", 71, 6.074));
    episodes.push_back(Episode(2, "Episode 2", 78, 6.845));
    episodes.push_back(Episode(3, "Episode 3", 71, 7.414));
    episodes.push_back(Episode(4, "Episode 4", 79, 8.499));
    episodes.push_back(Episode(5, "Episode 5", 81, 8.730));
    episodes.push_back(Episode(6, "Episode 6", 80, 9.223));
    episodes.push_back(Episode(7, "Episode 7", 83, 9.394));
    episodes.push_back(Episode(8, "Episode 8", 87, 11.349));
    episodes.push_back(Episode(9, "Episode 9", 89, 11.516));
    episodes.push_back(Episode(10, "Episode 10", 85, 14.633));
    episodes.push_back(Episode(11, "Episode 11", 88, 14.238));
    episodes.push_back(Episode(12, "Episode 12", 97, 15.933));
    episodes.push_back(Episode(13, "Episode 13", 86, 14.097));
    episodes.push_back(Episode(14, "Episode 14", 92, 17.705));
    episodes.push_back(Episode(15, "Episode 15", 86, 17.066));
    episodes.push_back(Episode(16, "Episode 16", 113, 21.683));
    drama.setEpisodes(episodes);
    return drama;
}

Drama createHospitalPlaylist(Director& director, Writer& writer,
                              Actor& actor1, Actor& actor2, Actor& actor3) {
    Drama drama("Hospital Playlist", 2020, "Medical, Comedy, Drama", "tvN", &director, &writer);
    drama.setCast(std::vector<Actor*>{&actor1, &actor2, &actor3});

    std::vector<Episode> episodes;
    episodes.push_back(Episode(1, "Episode 1", 83, 6.325));
    episodes.push_back(Episode(2, "Episode 2", 82, 7.750));
    episodes.push_back(Episode(3, "Episode 3", 88, 8.556));
    episodes.push_back(Episode(4, "Episode 4", 79, 9.754));
    episodes.push_back(Episode(5, "Episode 5", 73, 11.321));
    episodes.push_back(Episode(6, "Episode 6", 82, 11.682));
    episodes.push_back(Episode(7, "Episode 7", 84, 12.077));
    episodes.push_back(Episode(8, "Episode 8", 88, 12.008));
    episodes.push_back(Episode(9, "Episode 9", 76, 12.134));
    episodes.push_back(Episode(10, "Episode 10", 92, 12.701));
    episodes.push_back(Episode(11, "Episode 11", 88, 13.125));
    episodes.push_back(Episode(12, "Episode 12", 113, 14.142));
    drama.setEpisodes(episodes);
    return drama;
}

int main() {
    // Objek agregat dibuat di luar Drama.
    Director replyDirector("Shin Won-ho", 50, 2007, "Family dan ensemble storytelling", 2);
    Writer replyWriter("Lee Woo-jung", 50, 2001, "Lee Woo-jung", "Family, Coming-of-age, Romance");
    Actor replyActor1("Lee Hye-ri", 21, 2010, "DreamT Entertainment", "Sung Deok-sun", "Lead");
    Actor replyActor2("Park Bo-gum", 22, 2011, "Blossom Entertainment", "Choi Taek", "Lead");
    Actor replyActor3("Ryu Jun-yeol", 29, 2015, "C-JeS Entertainment", "Kim Jung-hwan", "Second Lead");

    Director crashDirector("Lee Jung-hyo", 48, 2008, "Romance dan human-centered drama", 0);
    Writer crashWriter("Park Ji-eun", 50, 2000, "Park Ji-eun", "Romance, Comedy-Drama");
    Actor crashActor1("Hyun Bin", 43, 2003, "VAST Entertainment", "Ri Jeong-hyeok", "Lead");
    Actor crashActor2("Son Ye-jin", 44, 2000, "MSteam Entertainment", "Yoon Se-ri", "Lead");
    Actor crashActor3("Seo Ji-hye", 41, 2003, "Culture Depot", "Seo Dan", "Second Lead");

    Drama drama1 = createReply1988(replyDirector, replyWriter, replyActor1, replyActor2, replyActor3);
    Drama drama2 = createCrashLandingOnYou(crashDirector, crashWriter, crashActor1, crashActor2, crashActor3);

    DramaCatalog catalog("K-Drama Hub");
    catalog.setDramas(std::vector<Drama*>{&drama1, &drama2});

    printBanner("DATA SEBELUM PENAMBAHAN");
    catalog.displayAll();

    printBanner("PROSES PENAMBAHAN DATA");

    Drama* reply1988 = catalog.findDrama("Reply 1988");
    if (reply1988 != nullptr) {
        std::vector<Episode> episodes = reply1988->getEpisodes();
        episodes.push_back(Episode(20, "Goodbye, My Youth. Goodbye, Ssangmun-dong", 108, 18.803));
        reply1988->setEpisodes(episodes);
        std::cout << "[+] Episode 20 \"Goodbye, My Youth. Goodbye, Ssangmun-dong\" ditambahkan ke \"Reply 1988\"\n";
    }

    Actor newActor("Kim Jung-hyun", 36, 2015, "Story J Company", "Goo Seung-jun", "Supporting");
    Drama* crashLanding = catalog.findDrama("Crash Landing on You");
    if (crashLanding != nullptr) {
        std::vector<Actor*> cast = crashLanding->getCast();
        cast.push_back(&newActor);
        crashLanding->setCast(cast);
        std::cout << "[+] Pemeran \"Kim Jung-hyun\" ditambahkan ke \"Crash Landing on You\"\n";
    }

    Actor hospitalActor1("Cho Jung-seok", 44, 2004, "JAM Entertainment", "Lee Ik-jun", "Lead");
    Actor hospitalActor2("Yoo Yeon-seok", 41, 2003, "King Kong by Starship", "Ahn Jeong-won", "Lead");
    Actor hospitalActor3("Jung Kyung-ho", 42, 2004, "Management Allum", "Kim Joon-wan", "Second Lead");
    Drama drama3 = createHospitalPlaylist(replyDirector, replyWriter, hospitalActor1, hospitalActor2, hospitalActor3);

    std::vector<Drama*> dramas = catalog.getDramas();
    dramas.push_back(&drama3);
    catalog.setDramas(dramas);
    std::cout << "[+] Drama baru \"Hospital Playlist\" ditambahkan ke katalog\n";

    printBanner("DATA SESUDAH PENAMBAHAN");
    catalog.displayAll();

    return 0;
}
