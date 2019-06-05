package by.bsu.lab.util;

import java.util.Stack;

public class NumberReverser {

    public int reverse(int number) {
        Stack<Character> stack = new Stack<Character>();
        char[] charArray = String.valueOf(Math.abs(number)).toCharArray();
        String res = number < 0 ? "-" : "";
        for (int i = 0; i < charArray.length; i++) {
            stack.push(charArray[i]);
        }
        for (int i = 0; i < charArray.length; i++) {
            res += stack.pop();
        }
        return Integer.parseInt(res);
    }
}
