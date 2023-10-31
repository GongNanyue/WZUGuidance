interface Auto {
    public abstract void move();

    public abstract void stop();

    public abstract void dudu();
}

interface Sprinkler {
    public abstract void watering();
}

public class Main {
    public static void main(String args[]) {
        Car car = new Car();
        car.move();
        car.dudu();
        car.stop();

        FireTruck firetruck = new FireTruck();
        firetruck.move();
        firetruck.dudu();
        firetruck.stop();
        firetruck.watering();
    }
}





class Car implements Auto {

    @Override
    public void move() {
        System.out.println("I am running very fast.");
    }

    @Override
    public void stop() {
        System.out.println("I am stopping.");
    }

    @Override
    public void dudu() {
        System.out.println("I am a car!Get out Every one!");
    }
}

class Truck implements Auto{

    @Override
    public void move() {
        System.out.println("I am running very smoothly.");
    }

    @Override
    public void stop() {
        System.out.println("I am slowly stopping.");
    }

    @Override
    public void dudu() {
        System.out.println("I am a big Auto!Get out Every one and small car!");
    }
}

class FireTruck extends Truck implements Sprinkler{

    @Override
    public void watering() {
        System.out.println("I am watering,No fire!");
    }
}