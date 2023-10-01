import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String id = sc.next();
        String name = sc.next();
        String gender = sc.next();
        double C, M, E;
        C = sc.nextDouble();
        M = sc.nextDouble();
        E = sc.nextDouble();
        Student student = new Student(id, name, gender, C, M, E);
        System.out.printf("%s %s %s %.2f %.2f %.2f %.2f %.2f",
                student.id,student.name,student.gender,student.C,student.M,student.E,student.avg,student.sum);
    }
}

class Student {
    String id;
    String name;
    String gender;
    double C;
    double M;
    double E;
    double avg;
    double sum;


    public Student(String id, String name, String gender, double c, double m, double e) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        C = c;
        M = m;
        E = e;
        sum = (c + m + e);
        avg = sum / 3;
    }


}