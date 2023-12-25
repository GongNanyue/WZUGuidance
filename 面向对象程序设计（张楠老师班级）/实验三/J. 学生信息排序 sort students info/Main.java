import java.util.*;

class Student implements Comparable<Student> {
    String id;
    String name;
    String gender;
    double s1, s2, s3;

    Student(String id, String name, String gender, double s1, double s2, double s3) {
        this.id = id;
        this.name = name;
        this.gender = gender;
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }

    @Override
    public int compareTo(Student other) {
        return this.id.compareTo(other.id);
    }
}

public class Main {
    public static void main(String args[]) {
        var in = new Scanner(System.in);
        var students = new ArrayList<Student>();
        var command = in.next();
        while (!command.equals("QUIT")) {
            if (command.equals("INSERT")) {
                var student = new Student(in.next(), in.next(), in.next(), in.nextDouble(), in.nextDouble(), in.nextDouble());
                students.add(student);
                System.out.printf("%s %s %s %.2f %.2f %.2f %.2f %.2f\n", student.id, student.name, student.gender, student.s1, student.s2, student.s3, (student.s1 + student.s2 + student.s3) / 3, student.s1 + student.s2 + student.s3);
            } else if (command.equals("LIST")) {
                Collections.sort(students);
                for (var student : students) {
                    System.out.printf("%s %s %s %.2f %.2f %.2f %.2f %.2f\n", student.id, student.name, student.gender, student.s1, student.s2, student.s3, (student.s1 + student.s2 + student.s3) / 3, student.s1 + student.s2 + student.s3);
                }
            }
            command = in.next();
        }
        System.out.println("Good bye!");
    }
}
