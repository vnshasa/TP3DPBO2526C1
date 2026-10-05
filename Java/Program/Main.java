import java.util.ArrayList;

public class Main {

    static void printBanner(String text) {
        System.out.println("\n" + "=".repeat(64));
        System.out.println("  " + text);
        System.out.println("=".repeat(64) + "\n");
    }

    static Drama createReply1988(Director director, Writer writer,
                                 Actor actor1, Actor actor2, Actor actor3) {
        Drama drama = new Drama("Reply 1988", 2015, "Family, Romance, Drama", "tvN", director, writer);
        ArrayList<Actor> cast = new ArrayList<>();
        cast.add(actor1);
        cast.add(actor2);
        cast.add(actor3);
        drama.setCast(cast);

        ArrayList<Episode> episodes = new ArrayList<>();
        episodes.add(new Episode(1, "Hand in Hand", 84, 6.118));
        episodes.add(new Episode(2, "The One Thing You're Mistaken About Me", 85, 6.836));
        episodes.add(new Episode(3, "Not Guilty If You're Rich, Guilty If You're Poor", 81, 7.777));
        episodes.add(new Episode(4, "Can't Help~ ing", 71, 8.251));
        episodes.add(new Episode(5, "Ready for Winter", 86, 10.145));
        episodes.add(new Episode(6, "The First Snow Is Coming", 77, 9.263));
        episodes.add(new Episode(7, "To You", 88, 11.035));
        episodes.add(new Episode(8, "Warm Words", 86, 11.293));
        episodes.add(new Episode(9, "Crossing the Line", 92, 11.563));
        episodes.add(new Episode(10, "Memory", 79, 13.360));
        episodes.add(new Episode(11, "Three Prophecies", 99, 12.228));
        episodes.add(new Episode(12, "What It Means To Love Someone", 91, 13.060));
        episodes.add(new Episode(13, "Superman is Back", 95, 12.858));
        episodes.add(new Episode(14, "Don't Worry, My Dear", 93, 15.133));
        episodes.add(new Episode(15, "Between Love and Friendship", 94, 15.192));
        episodes.add(new Episode(16, "Life is an Irony - Part I", 92, 15.372));
        episodes.add(new Episode(17, "Life is an Irony - Part II", 105, 15.472));
        episodes.add(new Episode(18, "Goodbye, My First Love", 97, 17.191));
        episodes.add(new Episode(19, "You Did Your Best", 107, 17.597));
        drama.setEpisodes(episodes);
        return drama;
    }

    static Drama createCrashLandingOnYou(Director director, Writer writer,
                                         Actor actor1, Actor actor2, Actor actor3) {
        Drama drama = new Drama("Crash Landing on You", 2019, "Romance, Drama", "tvN", director, writer);
        ArrayList<Actor> cast = new ArrayList<>();
        cast.add(actor1);
        cast.add(actor2);
        cast.add(actor3);
        drama.setCast(cast);

        ArrayList<Episode> episodes = new ArrayList<>();
        episodes.add(new Episode(1, "Episode 1", 71, 6.074));
        episodes.add(new Episode(2, "Episode 2", 78, 6.845));
        episodes.add(new Episode(3, "Episode 3", 71, 7.414));
        episodes.add(new Episode(4, "Episode 4", 79, 8.499));
        episodes.add(new Episode(5, "Episode 5", 81, 8.730));
        episodes.add(new Episode(6, "Episode 6", 80, 9.223));
        episodes.add(new Episode(7, "Episode 7", 83, 9.394));
        episodes.add(new Episode(8, "Episode 8", 87, 11.349));
        episodes.add(new Episode(9, "Episode 9", 89, 11.516));
        episodes.add(new Episode(10, "Episode 10", 85, 14.633));
        episodes.add(new Episode(11, "Episode 11", 88, 14.238));
        episodes.add(new Episode(12, "Episode 12", 97, 15.933));
        episodes.add(new Episode(13, "Episode 13", 86, 14.097));
        episodes.add(new Episode(14, "Episode 14", 92, 17.705));
        episodes.add(new Episode(15, "Episode 15", 86, 17.066));
        episodes.add(new Episode(16, "Episode 16", 113, 21.683));
        drama.setEpisodes(episodes);
        return drama;
    }

    static Drama createHospitalPlaylist(Director director, Writer writer,
                                         Actor actor1, Actor actor2, Actor actor3) {
        Drama drama = new Drama("Hospital Playlist", 2020, "Medical, Comedy, Drama", "tvN", director, writer);
        ArrayList<Actor> cast = new ArrayList<>();
        cast.add(actor1);
        cast.add(actor2);
        cast.add(actor3);
        drama.setCast(cast);

        ArrayList<Episode> episodes = new ArrayList<>();
        episodes.add(new Episode(1, "Episode 1", 83, 6.325));
        episodes.add(new Episode(2, "Episode 2", 82, 7.750));
        episodes.add(new Episode(3, "Episode 3", 88, 8.556));
        episodes.add(new Episode(4, "Episode 4", 79, 9.754));
        episodes.add(new Episode(5, "Episode 5", 73, 11.321));
        episodes.add(new Episode(6, "Episode 6", 82, 11.682));
        episodes.add(new Episode(7, "Episode 7", 84, 12.077));
        episodes.add(new Episode(8, "Episode 8", 88, 12.008));
        episodes.add(new Episode(9, "Episode 9", 76, 12.134));
        episodes.add(new Episode(10, "Episode 10", 92, 12.701));
        episodes.add(new Episode(11, "Episode 11", 88, 13.125));
        episodes.add(new Episode(12, "Episode 12", 113, 14.142));
        drama.setEpisodes(episodes);
        return drama;
    }

    public static void main(String[] args) {
        // Objek agregat dibuat di luar Drama.
        Director replyDirector = new Director("Shin Won-ho", 50, 2007, "Family dan ensemble storytelling", 2);
        Writer replyWriter = new Writer("Lee Woo-jung", 50, 2001, "Lee Woo-jung", "Family, Coming-of-age, Romance");
        Actor replyActor1 = new Actor("Lee Hye-ri", 21, 2010, "DreamT Entertainment", "Sung Deok-sun", "Lead");
        Actor replyActor2 = new Actor("Park Bo-gum", 22, 2011, "Blossom Entertainment", "Choi Taek", "Lead");
        Actor replyActor3 = new Actor("Ryu Jun-yeol", 29, 2015, "C-JeS Entertainment", "Kim Jung-hwan", "Second Lead");

        Director crashDirector = new Director("Lee Jung-hyo", 48, 2008, "Romance dan human-centered drama", 0);
        Writer crashWriter = new Writer("Park Ji-eun", 50, 2000, "Park Ji-eun", "Romance, Comedy-Drama");
        Actor crashActor1 = new Actor("Hyun Bin", 43, 2003, "VAST Entertainment", "Ri Jeong-hyeok", "Lead");
        Actor crashActor2 = new Actor("Son Ye-jin", 44, 2000, "MSteam Entertainment", "Yoon Se-ri", "Lead");
        Actor crashActor3 = new Actor("Seo Ji-hye", 41, 2003, "Culture Depot", "Seo Dan", "Second Lead");

        Drama drama1 = createReply1988(replyDirector, replyWriter, replyActor1, replyActor2, replyActor3);
        Drama drama2 = createCrashLandingOnYou(crashDirector, crashWriter, crashActor1, crashActor2, crashActor3);

        DramaCatalog catalog = new DramaCatalog("K-Drama Hub");
        ArrayList<Drama> initialDramas = new ArrayList<>();
        initialDramas.add(drama1);
        initialDramas.add(drama2);
        catalog.setDramas(initialDramas);

        printBanner("DATA SEBELUM PENAMBAHAN");
        catalog.displayAll();

        printBanner("PROSES PENAMBAHAN DATA");

        Drama reply1988 = catalog.findDrama("Reply 1988");
        if (reply1988 != null) {
            ArrayList<Episode> episodes = new ArrayList<>(reply1988.getEpisodes());
            episodes.add(new Episode(20, "Goodbye, My Youth. Goodbye, Ssangmun-dong", 108, 18.803));
            reply1988.setEpisodes(episodes);
            System.out.println("[+] Episode 20 \"Goodbye, My Youth. Goodbye, Ssangmun-dong\" ditambahkan ke \"Reply 1988\"");
        }

        Actor newActor = new Actor("Kim Jung-hyun", 36, 2015, "Story J Company", "Goo Seung-jun", "Supporting");
        Drama crashLanding = catalog.findDrama("Crash Landing on You");
        if (crashLanding != null) {
            ArrayList<Actor> cast = new ArrayList<>(crashLanding.getCast());
            cast.add(newActor);
            crashLanding.setCast(cast);
            System.out.println("[+] Pemeran \"Kim Jung-hyun\" ditambahkan ke \"Crash Landing on You\"");
        }

        Actor hospitalActor1 = new Actor("Cho Jung-seok", 44, 2004, "JAM Entertainment", "Lee Ik-jun", "Lead");
        Actor hospitalActor2 = new Actor("Yoo Yeon-seok", 41, 2003, "King Kong by Starship", "Ahn Jeong-won", "Lead");
        Actor hospitalActor3 = new Actor("Jung Kyung-ho", 42, 2004, "Management Allum", "Kim Joon-wan", "Second Lead");
        Drama drama3 = createHospitalPlaylist(replyDirector, replyWriter, hospitalActor1, hospitalActor2, hospitalActor3);

        ArrayList<Drama> dramas = new ArrayList<>(catalog.getDramas());
        dramas.add(drama3);
        catalog.setDramas(dramas);
        System.out.println("[+] Drama baru \"Hospital Playlist\" ditambahkan ke katalog");

        printBanner("DATA SESUDAH PENAMBAHAN");
        catalog.displayAll();
    }
}
