import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * Kelas Drama.
 * Aggregation : Director, Writer, dan Actor dibuat di luar Drama.
 * Composition : Drama menyimpan object Episode yang dibuat menjadi bagian internal Drama.
 */
public class Drama {
    private String title;
    private int year;
    private String genre;
    private String broadcaster;

    private Director director;
    private Writer writer;
    private ArrayList<Actor> cast = new ArrayList<>();
    private ArrayList<Episode> episodes = new ArrayList<>();

    public Drama(String title, int year, String genre, String broadcaster,
                 Director director, Writer writer) {
        this.title = title;
        this.year = year;
        this.genre = genre;
        this.broadcaster = broadcaster;
        this.director = director;
        this.writer = writer;
    }

    // ---------- Getter ----------
    public String getTitle() { return title; }
    public int getYear() { return year; }
    public String getGenre() { return genre; }
    public String getBroadcaster() { return broadcaster; }
    public Director getDirector() { return director; }
    public Writer getWriter() { return writer; }
    public ArrayList<Actor> getCast() { return cast; }
    public ArrayList<Episode> getEpisodes() {
        return new ArrayList<>(episodes);
    }
    public int getTotalEpisodes() { return episodes.size(); }

    // ---------- Setter ----------
    public void setTitle(String title) { this.title = title; }
    public void setYear(int year) { this.year = year; }
    public void setGenre(String genre) { this.genre = genre; }
    public void setBroadcaster(String broadcaster) { this.broadcaster = broadcaster; }
    public void setDirector(Director director) { this.director = director; }
    public void setWriter(Writer writer) { this.writer = writer; }
    public void setCast(ArrayList<Actor> cast) { this.cast = cast; }

    public void setEpisodes(ArrayList<Episode> episodes) {
        // Composition: buat object Episode baru yang menjadi milik Drama.
        this.episodes = new ArrayList<>();
        for (Episode ep : episodes) {
            this.episodes.add(new Episode(
                    ep.getNumber(),
                    ep.getTitle(),
                    ep.getDurationMinutes(),
                    ep.getViewerRating()));
        }
    }

    public int getTotalDuration() {
        int total = 0;
        for (Episode ep : episodes) total += ep.getDurationMinutes();
        return total;
    }

    public double getAverageRating() {
        if (episodes.isEmpty()) return 0.0;
        double sum = 0.0;
        for (Episode ep : episodes) sum += ep.getViewerRating();
        return sum / episodes.size();
    }

    public void display() {
        System.out.println("-".repeat(64));
        System.out.println("DRAMA: " + title);
        System.out.println("-".repeat(64));
        System.out.println("  Tahun / Genre : " + year + " / " + genre);
        System.out.println("  Penyiar       : " + broadcaster);
        System.out.println("  Episode       : " + episodes.size() + " episode, total " + getTotalDuration() + " menit");
        System.out.println(String.format(Locale.US, "  Rata2 Rating  : %.1f%%", getAverageRating()));

        List<Person> credits = new ArrayList<>();
        if (director != null) credits.add(director);
        if (writer != null) credits.add(writer);
        credits.addAll(cast);

        System.out.println("\n  >> KREDIT (Sutradara, Penulis, Pemeran) - " + credits.size() + " orang");
        for (Person person : credits) person.displayInfo();

        System.out.println("\n  >> DAFTAR EPISODE");
        System.out.println("    No | Judul                                              | Durasi    | Rating");
        System.out.println("    ---+----------------------------------------------------+-----------+-------");
        for (Episode ep : episodes) ep.display();
        System.out.println();
    }
}
