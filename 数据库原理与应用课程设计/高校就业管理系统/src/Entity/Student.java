package Entity;

public class Student {
    public int ID;
    public String name;
    public String sex;
    public String dept;
    public String major;
    public int jobID;
    public boolean isWork;

    public Student(int ID, String name, String sex, String dept, String major, int jobID, boolean isWork) {
        this.ID = ID;
        this.name = name;
        this.sex = sex;
        this.dept = dept;
        this.major = major;
        this.jobID = jobID;
        this.isWork = isWork;
    }
}
