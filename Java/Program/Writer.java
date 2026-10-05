/** CHILD class #3 dari Person (Hierarchical Inheritance). */
public class Writer extends Person {
    private String penName;
    private String specialtyGenre;

    public Writer(String name, int age, int debutYear,
                  String penName, String specialtyGenre) {
        super(name, age, debutYear);
        this.penName = penName;
        this.specialtyGenre = specialtyGenre;
    }

    public String getPenName() { return penName; }
    public String getSpecialtyGenre() { return specialtyGenre; }

    public void setPenName(String penName) { this.penName = penName; }
    public void setSpecialtyGenre(String specialtyGenre) { this.specialtyGenre = specialtyGenre; }

    @Override
    public String getRole() { return "Writer"; }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("      Nama Pena    : " + penName);
        System.out.println("      Spesialisasi : " + specialtyGenre);
    }
}
