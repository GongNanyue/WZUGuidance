class Circle extends Shape {

    double radius;



    Circle(double radius) {

        this.radius = radius;

    }



    @Override

    public double calArea() {

        return radius * radius * 3.14;

    }

}



class Rectangle extends Shape {

    double length, width;



    Rectangle(double length, double width) {

        this.length = length;

        this.width = width;

    }



    @Override

    public double calArea() {

        return length * width;

    }

}
