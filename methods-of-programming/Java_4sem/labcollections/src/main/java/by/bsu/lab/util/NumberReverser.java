package by.bsu.lab.util;

import java.util.Stack;

public class NumberReverser {

    public int reverse(int number) {
        Stack<Character> stack = new Stack<Character>();
        char[] charArray = String.valueOf(number).toCharArray();
        String res = "";
        for (int i = 0; i < charArray.length; i++) {
            stack.push(charArray[i]);
        }
        for (int i = 0; i < charArray.length; i++) {
            res += stack.pop();
        }
        return Integer.parseInt(res);
    }
}
