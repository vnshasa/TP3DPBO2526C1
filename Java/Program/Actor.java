/** CHILD class #1 dari Person (Hierarchical Inheritance). */
public class Actor extends Person {
    private String agency;
    private String characterName;  // karakter yang diperankan di drama ini
    private String roleType;       // Lead / Second Lead / Supporting

    public Actor(String name, int age, int debutYear,
                 String agency, String characterName, String roleType) {
        super(name, age, debutYear);
        this.agency = agency;
        this.characterName = characterName;
        this.roleType = roleType;
    }

    public String getAgency() { return agency; }
    public String getCharacterName() { return characterName; }
    public String getRoleType() { return roleType; }

    public void setAgency(String agency) { this.agency = agency; }
    public void setCharacterName(String characterName) { this.characterName = characterName; }
    public void setRoleType(String roleType) { this.roleType = roleType; }

    @Override
    public String getRole() { return "Actor"; }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("      Karakter     : " + characterName + " (" + roleType + ")");
        System.out.println("      Agensi       : " + agency);
    }
}
