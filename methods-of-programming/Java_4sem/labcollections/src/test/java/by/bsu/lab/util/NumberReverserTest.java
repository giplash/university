package by.bsu.lab.util;

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class NumberReverserTest {

    @Test
    public void shouldCorrectlyWorksWithSingleNumber() {
        NumberReverser reverser = new NumberReverser();
        assertEquals(5, reverser.reverse(5));
    }

    @Test
    public void shouldCorrectlyWorks() {
        NumberReverser reverser = new NumberReverser();
        assertEquals(54321, reverser.reverse(12345));
    }
}
