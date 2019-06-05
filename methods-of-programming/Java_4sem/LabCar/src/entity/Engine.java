package entity;

import java.util.Objects;
import java.util.StringJoiner;

public class Engine {
    private boolean isWorking;
    private int power;
    private String facturerName;

    public Engine(boolean isWorking, int power,String facturerName) {
        this.isWorking = isWorking;
        this.power = power;
        this.facturerName = facturerName;
    }

    public boolean isWorking() {
        return isWorking;
    }

    public void setWorking(boolean working) {
        isWorking = working;
    }

    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }
    public String getFacturerName() {
        return facturerName;
    }

    public void setFacturerName(String facturerName) {
        this.facturerName = facturerName;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Engine engine = (Engine) o;
        return isWorking == engine.isWorking &&
                power == engine.power &&
                facturerName.equals(engine.facturerName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(isWorking, power, facturerName);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", Engine.class.getSimpleName() + "[", "]")
                .add("isWorking=" + isWorking)
                .add("power=" + power)
                .add("facturerName='" + facturerName + "'")
                .toString();
    }
}
