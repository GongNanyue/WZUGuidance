import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> ss = new ArrayList<Student>();

        while (true) {
            String op = sc.next();
            if (op.equals("QUIT")) {
                System.out.println("Good bye!");
                break;
            } else if (op.equals("INSERT")) {
                String id = sc.next(), name = sc.next(), sex = sc.next();
                double chi = sc.nextDouble(), mat = sc.nextDouble(), eng = sc.nextDouble();
                ss.add(new Student(id, name, sex, chi, mat, eng));
                System.out.println(ss.get(ss.size() - 1));
            } else if (op.equals("LIST")) {
                Collections.sort(ss);
                for (Student o : ss) {
                    System.out.println(o);
                }
            }
        }
    }
}

class Student implements Comparable<Student> {
    String id, name, sex;
    double chi, mat, eng;
    double avg, sum;

    public Student(String id, String name, String sex, double chi, double mat, double eng) {
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.chi = chi;
        this.mat = mat;
        this.eng = eng;
        sum = (chi + mat + eng);
        avg = sum / 3;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.2f %.2f %.2f %.2f %.2f", id, name, sex, chi, mat, eng, avg, sum);
    }

    @Override
    public int compareTo(Student o) {
        return this.id.compareTo(o.id);
    }
}
