/**
 * BASE CLASS pada Hierarchical Inheritance.
 * Actor, Director, dan Writer sama-sama mewarisi kelas ini.
 */
public class Person {
    private String name;
    private int age;
    private int debutYear;

    public Person(String name, int age, int debutYear) {
        this.name = name;
        this.age = age;
        this.debutYear = debutYear;
    }

    public String getName() { return name; }
    public int getAge() { return age; }
    public int getDebutYear() { return debutYear; }

    public void setName(String name) { this.name = name; }
    public void setAge(int age) { this.age = age; }
    public void setDebutYear(int debutYear) { this.debutYear = debutYear; }

    // Method biasa; child dapat melakukan override untuk menentukan peran.
    public String getRole() { return "Person"; }

    // Child boleh override, lalu memanggil super.displayInfo() untuk bagian yang sama.
    public void displayInfo() {
        System.out.println("  * [" + getRole() + "] " + name);
        System.out.println("      Umur / Debut : " + age + " tahun / debut " + debutYear);
    }
}
