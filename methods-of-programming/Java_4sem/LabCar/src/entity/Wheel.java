package entity;

import java.util.Objects;
import java.util.StringJoiner;

public class Wheel {
    private boolean isSpinning;
    private String facturerName;

    public Wheel(boolean isSpinning, String facturerName) {
        this.isSpinning = isSpinning;
        this.facturerName = facturerName;
    }

    public boolean isSpinning() {
        return isSpinning;
    }

    public void setSpinning(boolean spinning) {
        isSpinning = spinning;
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
        Wheel wheel = (Wheel) o;
        return isSpinning == wheel.isSpinning &&
                facturerName.equals(wheel.facturerName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(isSpinning, facturerName);
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", Wheel.class.getSimpleName() + "[", "]")
                .add("isSpinning=" + isSpinning)
                .add("facturerName='" + facturerName + "'")
                .toString();
    }
}
