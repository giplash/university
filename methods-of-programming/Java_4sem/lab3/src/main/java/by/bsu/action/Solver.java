package by.bsu.action;

import java.util.*;

public class Solver {

    public static int[] sort(int[] arr) {
        return Arrays.stream(arr)
                .boxed()
                .sorted((a, b) -> Integer.toString(a).length() - Integer.toString(b).length())
                .mapToInt(i -> i)
                .toArray();
    }
}
