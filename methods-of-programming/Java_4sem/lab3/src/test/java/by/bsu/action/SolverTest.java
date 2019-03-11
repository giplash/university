package by.bsu.action;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class SolverTest {

    @Test
    void baseTest1() {
        int[] initial = { 100, 10, 1 };
        int[] sorted = { 1, 10, 100 };        ;
        assertArrayEquals(sorted, Solver.sort(initial));
    }

    @Test
    void baseTest2() {
        int[] initial = { 1, 102, 101, 100 };
        int[] sorted = { 1, 102, 101, 100 };
        assertArrayEquals(sorted, Solver.sort(initial));
    }

    @Test
    void testWithOneValue() {
        int[] initial = { 1 };
        int[] sorted = { 1 };
        assertArrayEquals(sorted, Solver.sort(initial));
    }

    @Test
    void testWithEmptyArray() {
        int[] initial = {  };
        int[] sorted = {  };
        assertArrayEquals(sorted, Solver.sort(initial));
    }

}
