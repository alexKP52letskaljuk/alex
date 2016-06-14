package lab2;


class Student{
    String name;
    String surname;
    boolean male;
    double znoRaiting;

    public Student(String name, String surname, boolean male, double znoRaiting) {
        this.name = name;
        this.surname = surname;
        this.male = male;
        this.znoRaiting = znoRaiting;
    }

    int compare(Student other){

        if(this.znoRaiting < other.znoRaiting) return -1;
        else if(this.znoRaiting > other.znoRaiting) return 1;
        return this.surname.compareTo(other.surname);
    }

    @Override public String toString(){
        String gender;
        if(male) gender ="male";
        else gender = "female";
        return znoRaiting + "\t" +  name + " " + surname + " " + gender;
    }
}