import java.util.ArrayList;

/**
 * Kelas DramaCatalog.
 * Aggregation : catalog menyimpan referensi Drama yang dibuat di luar catalog.
 */
public class DramaCatalog {
    private String name;
    private ArrayList<Drama> dramas = new ArrayList<>();

    public DramaCatalog(String name) {
        this.name = name;
    }

    // ---------- Getter ----------
    public String getName() { return name; }
    public ArrayList<Drama> getDramas() { return dramas; }

    // ---------- Setter ----------
    public void setName(String name) { this.name = name; }
    public void setDramas(ArrayList<Drama> dramas) { this.dramas = dramas; }

    public Drama findDrama(String title) {
        for (Drama drama : dramas) {
            if (drama.getTitle().equals(title)) return drama;
        }
        return null;
    }

    public int getTotalDramas() { return dramas.size(); }

    public int getTotalEpisodes() {
        int total = 0;
        for (Drama drama : dramas) total += drama.getTotalEpisodes();
        return total;
    }

    public void displaySummary() {
        System.out.println("No | Judul                        | Tahun | Genre                        | Eps | Avg Rating");
        System.out.println("---+------------------------------+-------+------------------------------+-----+-----------");
        for (int i = 0; i < dramas.size(); i++) {
            Drama d = dramas.get(i);
            System.out.printf(java.util.Locale.US,
                    "%2d | %-28s | %5d | %-28s | %3d | %9.1f%%%n",
                    i + 1, d.getTitle(), d.getYear(), d.getGenre(),
                    d.getTotalEpisodes(), d.getAverageRating());
        }
        System.out.println();
    }

    public void displayAll() {
        System.out.println("KATALOG       : " + name);
        System.out.println("Total Drama   : " + getTotalDramas());
        System.out.println("Total Episode : " + getTotalEpisodes() + "\n");

        displaySummary();
        for (Drama drama : dramas) drama.display();
    }
}
