class Car implements Auto {

    public void move() {

        System.out.println("I am running very fast.");

    }



    public void stop() {

        System.out.println("I am stopping.");

    }



    public void dudu() {

        System.out.println("I am a car!Get out Every one!");

    }

}



class Truck implements Auto {

    public void move() {

        System.out.println("I am running very smoothly.");

    }



    public void stop() {

        System.out.println("I am slowly stopping.");

    }



    public void dudu() {

        System.out.println("I am a big Auto!Get out Every one and small car!");

    }

}



class FireTruck extends Truck implements Sprinkler {

    public void watering() {

        System.out.println("I am watering,No fire!");

    }

}