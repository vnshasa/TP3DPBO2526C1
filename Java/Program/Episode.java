import java.util.Locale;

/**
 * Satu episode dalam sebuah Drama.
 * Episode adalah "part of" Drama (Composition) -> disimpan sebagai bagian dari Drama.
 */
public class Episode {
    private int number;
    private String title;
    private int durationMinutes;
    private double viewerRating;  // rating penonton (%)

    public Episode(int number, String title, int durationMinutes, double viewerRating) {
        this.number = number;
        this.title = title;
        this.durationMinutes = durationMinutes;
        this.viewerRating = viewerRating;
    }

    public int getNumber() { return number; }
    public String getTitle() { return title; }
    public int getDurationMinutes() { return durationMinutes; }
    public double getViewerRating() { return viewerRating; }

    public void setNumber(int number) { this.number = number; }
    public void setTitle(String title) { this.title = title; }
    public void setDurationMinutes(int durationMinutes) { this.durationMinutes = durationMinutes; }
    public void setViewerRating(double viewerRating) { this.viewerRating = viewerRating; }

    public void display() {
        // Locale.US agar pemisah desimal selalu titik (bukan koma) di semua komputer
        System.out.println(String.format(Locale.US,
                "    %2d | %-50s | %3d menit | %5.1f%%",
                number, title, durationMinutes, viewerRating));
    }
}
