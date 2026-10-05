/** CHILD class #2 dari Person (Hierarchical Inheritance). */
public class Director extends Person {
    private String signatureStyle;
    private int awardsWon;

    public Director(String name, int age, int debutYear,
                    String signatureStyle, int awardsWon) {
        super(name, age, debutYear);
        this.signatureStyle = signatureStyle;
        this.awardsWon = awardsWon;
    }

    public String getSignatureStyle() { return signatureStyle; }
    public int getAwardsWon() { return awardsWon; }

    public void setSignatureStyle(String signatureStyle) { this.signatureStyle = signatureStyle; }
    public void setAwardsWon(int awardsWon) { this.awardsWon = awardsWon; }

    @Override
    public String getRole() { return "Director"; }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("      Gaya Khas    : " + signatureStyle);
        System.out.println("      Penghargaan  : " + awardsWon + " piala");
    }
}
