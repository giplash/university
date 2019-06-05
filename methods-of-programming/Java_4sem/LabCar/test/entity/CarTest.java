package entity;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CarTest {

    @Test
    void ride() {
        Wheel wheel1 = new Wheel(false,"BMW");
        Wheel wheel2 = new Wheel(false,"BMW");
        Wheel wheel3 = new Wheel(false,"BMW");
        Wheel wheel4 = new Wheel(false,"BMW");
        List<Wheel> wheels = Arrays.asList(wheel1,wheel2,wheel3,wheel4);
        Engine engine = new Engine(false,320,"RTR Motors");
        Car car = new Car(wheels,engine,"BMW");
        car.ride();
        assertTrue((engine.isWorking()&&wheels.get(0).isSpinning()));
    }

    @Test
    void fuelUp() {
        Wheel wheel1 = new Wheel(true,"BMW");
        Wheel wheel2 = new Wheel(true,"BMW");
        Wheel wheel3 = new Wheel(true,"BMW");
        Wheel wheel4 = new Wheel(true,"BMW");
        List<Wheel> wheels = Arrays.asList(wheel1,wheel2,wheel3,wheel4);
        Engine engine = new Engine(true,320,"RTR Motors");
        Car car = new Car(wheels,engine,"BMW");
        car.fuelUp();
        assertTrue(!(engine.isWorking()&&wheels.get(0).isSpinning()));
    }

    @Test
    void changeWheel() {
        Wheel wheel1 = new Wheel(true,"BMW");
        Wheel wheel2 = new Wheel(true,"BMW");
        Wheel wheel3 = new Wheel(true,"BMW");
        Wheel wheel4 = new Wheel(true,"BMW");
        List<Wheel> wheels = Arrays.asList(wheel1,wheel2,wheel3,wheel4);
        Engine engine = new Engine(true,320,"RTR Motors");
        Car car = new Car(wheels,engine,"BMW");
        car.changeWheel(new Wheel(false,"Mercedes"),0);
        assertTrue(!(engine.isWorking()
                &&wheels.get(0).isSpinning()
                &&wheels.get(0).getFacturerName().equalsIgnoreCase("Mercedes")));
    }
}
