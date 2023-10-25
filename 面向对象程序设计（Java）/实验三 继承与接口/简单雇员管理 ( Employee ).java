import java.util.Vector;

public class Main {
    public static void main(String arg[]) {
        Employee e1 = new Employee("zhangsan", 20, "s101", "d01", 3);
        e1.print();
        System.out.println();

        Employee e2 = new Employee("lisi", 20, "s202", "d02", 4);
        e2.print();
        System.out.println();

        e2 = new Employee("maliu", 20, "s102", "d01", 5);

        Manager m1 = new Manager("wangwu", 30, "s100", "d01", 9);

        m1.getSubordinates().addElement(e1);
        m1.getSubordinates().addElement(e2);
        m1.print();
        System.out.println();
    }
}

class Person {
    String name;
    int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }


}

class Employee extends Person {
    String id;
    String depart;
    int rank;

    public Employee(String name, int age, String id, String depart, int rank) {
        super(name, age);
        this.id = id;
        this.depart = depart;
        this.rank = rank;
    }

    public void print() {
        System.out.printf("I am a Employee\n" +
                "My name is %s,I am %d years old.\n" +
                "I am a %d level Employee.My employeeNumber is %s.I am working in %s\n", name, age, rank, id, depart);
    }
}

class Manager extends Employee {
    Vector<Employee> subordinates;


    public Manager(String name, int age, String id, String depart, int rank) {
        super(name, age, id, depart, rank);
        subordinates = new Vector<Employee>();
    }

    public Vector<Employee> getSubordinates() {
        return subordinates;
    }

    @Override
    public void print() {
        System.out.printf("I am a Manager\n" +
                "My name is %s,I am %d years old.\n" +
                "I am a %d level Employee.My employeeNumber is %s.I am working in %s\n", name, age, rank, id, depart);
        System.out.println("My subordinate has:");
        for(int i = 0;i < subordinates.size();++i){
            System.out.printf("%s", subordinates.get(i).name);
            if(i != subordinates.size() - 1) System.out.print(",");
            else System.out.print(".\n");
        }
    }
}
