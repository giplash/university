package entity;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.StringJoiner;

public class Car {
    private static final Logger LOGGER = LogManager.getLogger(Car.class);
    private List<Wheel> wheels;
    private Engine engine;
    private String carName;

    public Car(List<Wheel> wheels, Engine engine, String carName) {
        this.wheels = wheels;
        this.engine = engine;
        this.carName = carName;
    }

    public List<Wheel> getWheels() {
        return wheels;
    }

    public void setWheels(ArrayList<Wheel> wheels) {
        this.wheels = wheels;
    }

    public Engine getEngine() {
        return engine;
    }

    public void setEngine(Engine engine) {
        this.engine = engine;
    }

    public String getCarName() {
        return carName;
    }

    public void setCarName(String carName) {
        this.carName = carName;
    }

    public void ride() {
        this.engine.setWorking(true);
        for (Wheel wheel:wheels) {
            wheel.setSpinning(true);
        }
        LOGGER.info("Car is riding");
    }

    public void fuelUp(){
        this.engine.setWorking(false);
        for (Wheel wheel:wheels) {
            wheel.setSpinning(false);
        }
        LOGGER.info("Fuel is being replenished");
    }

    public void changeWheel(Wheel newWheel, int a) {
        this.engine.setWorking(false);
        for (Wheel wheel:wheels) {
            wheel.setSpinning(false);
        }
        wheels.set(a,newWheel);
        LOGGER.info("Wheel is being changed");
    }



    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Car car = (Car) o;
        return wheels.equals(car.wheels) &&
                engine.equals(car.engine) &&
                carName.equals(car.carName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(wheels, engine, carName);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", Car.class.getSimpleName() + "[", "]")
                .add("wheels=" + wheels)
                .add("engine=" + engine)
                .add("carName='" + carName + "'")
                .toString();
    }
}
